#include "SceneOne.h"
#include "Ground.h"
#include "Pilar.h"
#include "../Framework/debug.h"

SceneOne::SceneOne(Aladdin* aladdin)
{
	this->aladdin = aladdin;
	this->aladdin->SetPosition(1030, 750);
	//this->aladdin->SetPosition(432, 580);

	CSprites* sprites = CSprites::GetInstance();
	//mapWidth = 2144.0f;
	//mapHeight = 1024.0f;

	mapWidth = 2272.0f;
	mapHeight = 1152.0f;
	spriteMap = sprites->Get(ID_SPRITE_MAP_ONE);
	fileResoucre = "resources\\map\\lv1\\new_obj.txt";
	fileGrid = "resources\\map\\lv1\\new_grid.txt";
	//fileMap = "resources\\map\\lv1\\titlemaplv1_bg.txt";
	//fileMap = "resources\\map\\lv1\\mapgamelv1_bg.txt";
	fileMap = "resources\\map\\lv1\\tilemapgamelv1.txt";
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
	pilar->SetWidth(PILAR_BBOX_WIDTH_5);
	pilar->SetHeight(PILAR_BBOX_HEIGHT_5);
	pilar->SetId(objects.size() + 1);
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

	grid->GetListOfObjects(&coObjects, screenWidth, screenHeight);

	for (int i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Render();
	}

	aladdin->Render();

	for (int i = 0; i < pilars.size(); i++)
	{
		pilars[i]->Render();
	}
	scoreboard->Render();
}

void SceneOne::Update(DWORD dt)
{
	grid->GetListOfObjects(&coObjects, screenWidth, screenHeight);

	aladdin->Update(dt, &coObjects);

	for (int i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Update(dt, &coObjects);
	}

	time += dt;
	scoreboard->Update(0, 500 - time * 0.001, 3, 2);
	//DebugOut(L"[INFO] aladdin hp: %d\n", aladdin->GetHP());
}

void SceneOne::DestroyAll()
{
}
