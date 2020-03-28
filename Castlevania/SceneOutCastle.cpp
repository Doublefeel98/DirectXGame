#include "SceneOutCastle.h"
#include "Define.h"

SceneOutCastle::SceneOutCastle()
{
	this->simon = Simon::GetInstance();
	this->simon->SetPosition(0, 0);

	CSprites* sprites = CSprites::GetInstance();
	mapWidth = 1536.0f;
	mapHeight = 384.0f;
	spriteMap = sprites->Get(ID_SPRITE_MAP_OUT_CASTLE);

	//fileMap = "resources\\maps\\outcastle\\lv1_bg.txt";
	//fileMap = "resources\\maps\\\outcastle\\stateoutcastle.txt";
	fileMap = "resources\\maps\\outcastle\\test.txt";
	fileResoucre = "resources\\maps\\outcastle\\outcastle_obj.txt";
	fileGrid = "resources\\maps\\outcastle\\outcastle_grid.txt";

	tileWidth = 32.0f;
	tileHeight = 32.0f;
	screenWidth = SCREEN_WIDTH;
	screenHeight = SCREEN_HEIGHT;

	tilemap = new TileMap(mapWidth, mapHeight, spriteMap, tileWidth, tileHeight);
	tilemap->LoadListTileFromFile(fileMap);

	castlevaniaObjects = new CastlevaniaObjects();
	castlevaniaObjects->Load(fileResoucre, &objects);

	Item* item = new Item(ITEM_HEART);
	item->SetPosition(160, 261);
	listItems.push_back(item);

	item = new Item(ITEM_WHIP);
	item->SetPosition(443, 261);
	listItems.push_back(item);

	item = new Item(ITEM_HEART);
	item->SetPosition(673, 261);
	listItems.push_back(item);

	item = new Item(ITEM_WHIP);
	item->SetPosition(943, 261);
	listItems.push_back(item);

	item = new Item(ITEM_HEART);
	item->SetPosition(1201, 261);
	listItems.push_back(item);

	for (int i = 0; i < objects.size(); i++)
		coObjects.push_back(objects[i]);

	grid = new Grid(fileGrid, (int)mapWidth, (int)mapHeight, 260, &coObjects);

	scoreboard = new ScoreBoard(simon, 16);
}

void SceneOutCastle::Render()
{
	tilemap->Render(screenWidth, screenHeight);

	grid->GetListOfObjects(&coObjects, screenWidth, screenHeight);

	for (int i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Render();
	}

	for (int i = 0; i < listItems.size(); i++)
	{
		listItems[i]->Render();
	}

	simon->Render();

	scoreboard->Render();
}

void SceneOutCastle::Update(DWORD dt)
{
	grid->GetListOfObjects(&coObjects, screenWidth, screenHeight);

	for (int i = 0; i < listItems.size(); i++)
	{
		coObjects.push_back(listItems[i]);
	}

	simon->Update(dt, &coObjects);

	for (int i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Update(dt, &objects);
	}

	time += dt;
	scoreboard->Update(16, 300 - time * 0.001, 3, 1);
}

void SceneOutCastle::DestroyAll()
{
}
