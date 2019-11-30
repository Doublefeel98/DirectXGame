#include "SceneOne.h"
#include "Ground.h"
SceneOne::SceneOne(Aladdin* aladdin)
{
	this->aladdin = aladdin;
	this->aladdin->SetPosition(0, 900);

	objects.push_back(this->aladdin);

	CSprites* sprites = CSprites::GetInstance();
	mapWidth = 2144.0f;
	mapHeight = 1024.0f;
	spriteMap = sprites->Get(ID_SPRITE_MAP_ONE);
	//fileResoucre = "resoucres\\object\\objects_lv1.txt";
	fileResource = "resources\\object\\objects_1.txt";
	fileMap = "resources\\mapread\\lv1\\Mapstate.txt";
	tileWidth = 16.0f;
	tileHeight = 16.0f;
	screenWidth = SCREEN_WIDTH;
	screenHeight = SCREEN_HEIGHT;

	aladinObjects = new AladdinObjects();

	tilemap = new TileMap(mapWidth, mapHeight, spriteMap, 16.0f, 16.0f);
	tilemap->LoadListTileFromFile(fileMap);

	//aladinObjects->Load(fileResoucre, &objects);
	aladinObjects->LoadListObject(fileResource, &objects);

	for (int i = 0; i < 67; i++)
	{
		Ground* ground = new Ground();
		ground->SetPosition(0 + i * 32.0f, 995);
		objects.push_back(ground);
	}

	for (int i = 1; i < objects.size(); i++)
		coObjects.push_back(objects[i]);

	grid = new Grid((int)mapWidth, (int)mapHeight, screenWidth, screenHeight);
	grid->Add(&coObjects);

	scoreboard = new ScoreBoard(aladdin, 0);
}

void SceneOne::Render()
{
	tilemap->Render(screenWidth, screenHeight);
	for (int i = 0; i < objects.size(); i++)
		objects[i]->Render();
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
