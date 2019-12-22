#include "SceneEnd.h"
#include "../Framework/debug.h"

SceneEnd::SceneEnd()
{
	CSprites* sprites = CSprites::GetInstance();
	//mapWidth = 2144.0f;
	//mapHeight = 1024.0f;

	mapWidth = 320;
	mapHeight = 256;
	spriteMap = sprites->Get(ID_SPRITE_MAP_ONE);
	//fileResoucre = "resources\\map\\lv1\\new_obj.txt";
	//fileGrid = "resources\\map\\lv1\\new_grid.txt";
	//fileMap = "resources\\map\\lv1\\titlemaplv1_bg.txt";
	//fileMap = "resources\\map\\lv1\\mapgamelv1_bg.txt";

	fileMap = "resources\\map\\lv1\\tilemapgamelv1.txt";
	fileResoucre = "resources\\map\\lv1\\text_obj.txt";
	fileGrid = "resources\\map\\lv1\\text_grid.txt";

	tileWidth = 16.0f;
	tileHeight = 16.0f;
	screenWidth = SCREEN_WIDTH;
	screenHeight = SCREEN_HEIGHT;


	tilemap = new TileMap(mapWidth, mapHeight, spriteMap, 16.0f, 16.0f);
	tilemap->LoadListTileFromFile(fileMap);

	//for (int i = 0; i < 67; i++)
	//{
	//	Ground* ground = new Ground();
	//	ground->SetPosition(0 + i * 32.0f, 995);
	//	objects.push_back(ground);
	//}

	for (int i = 1; i < objects.size(); i++)
		coObjects.push_back(objects[i]);

	grid = new Grid((int)mapWidth, (int)mapHeight, 160);
	grid->Add(&coObjects);

	sceneEndBoard = new SceneEndBoard();
}

void SceneEnd::Render()
{
	tilemap->Render(screenWidth, screenHeight);

	grid->GetListOfObjects(&coObjects, screenWidth, screenHeight);

	for (int i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Render();
	}

	sceneEndBoard->Render();
}

void SceneEnd::Update(DWORD dt)
{
	grid->GetListOfObjects(&coObjects, screenWidth, screenHeight);


	for (int i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Update(dt, &coObjects);
	}
}

void SceneEnd::DestroyAll()
{
}
