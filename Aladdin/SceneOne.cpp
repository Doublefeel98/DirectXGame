#include "SceneOne.h"
#include "Ground.h"
#include "Pilar.h"

SceneOne::SceneOne(Aladdin* aladdin)
{
	this->aladdin = aladdin;
	this->aladdin->SetPosition(0, 900);

	objects.push_back(this->aladdin);

	CSprites* sprites = CSprites::GetInstance();
	mapWidth = 2144.0f;
	mapHeight = 1024.0f;
	spriteMap = sprites->Get(ID_SPRITE_MAP_ONE);
	fileResoucre = "resources\\map\\lv1\\new_obj.txt";
	fileGrid = "resources\\map\\lv1\\new_grid.txt";
	fileMap = "resources\\map\\lv1\\titlemaplv1_bg.txt";
	tileWidth = 16.0f;
	tileHeight = 16.0f;
	screenWidth = SCREEN_WIDTH;
	screenHeight = SCREEN_HEIGHT;

	aladinObjects = new AladdinObjects();

	tilemap = new TileMap(mapWidth, mapHeight, spriteMap, 16.0f, 16.0f);
	tilemap->LoadListTileFromFile(fileMap);

	aladinObjects->Load(fileResoucre, &objects);

	//for (int i = 0; i < 67; i++)
	//{
	//	Ground* ground = new Ground();
	//	ground->SetPosition(0 + i * 32.0f, 995);
	//	objects.push_back(ground);
	//}

	Pilar* pilar = new Pilar();
	pilar->SetState(PILAR_STATE_1);
	pilar->SetPosition(159, 690);
	pilars.push_back(pilar);

	pilar = new Pilar();
	pilar->SetState(PILAR_STATE_2);
	pilar->SetPosition(463, 863);
	pilars.push_back(pilar);

	pilar = new Pilar();
	pilar->SetState(PILAR_STATE_3);
	pilar->SetPosition(766, 335);
	pilars.push_back(pilar);

	pilar = new Pilar();
	pilar->SetState(PILAR_STATE_4);
	pilar->SetPosition(1098, 834);
	pilars.push_back(pilar);

	pilar = new Pilar();
	pilar->SetState(PILAR_STATE_5);
	pilar->SetPosition(1402, 363);
	objects.push_back(pilar);

	for (int i = 1; i < objects.size(); i++)
		coObjects.push_back(objects[i]);

	grid = new Grid((int)mapWidth, (int)mapHeight, 160);
	grid->Add(&coObjects);

	scoreboard = new ScoreBoard(aladdin, 0);
}

void SceneOne::Render()
{
	tilemap->Render(screenWidth, screenHeight);
	for (int i = 1; i < objects.size(); i++)
		objects[i]->Render();

	aladdin->Render();

	for (int i = 0; i < pilars.size(); i++)
	{
		pilars[i]->Render();
	}
	scoreboard->Render();
}

void SceneOne::Update(DWORD dt)
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt, &coObjects);
	}

	time += dt;
	scoreboard->Update(0, 500 - time * 0.001, 3, 2);
}

void SceneOne::DestroyAll()
{
}
