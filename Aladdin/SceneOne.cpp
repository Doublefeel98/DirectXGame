#include "SceneOne.h"
SceneOne::SceneOne()
{
	CSprites* sprites = CSprites::GetInstance();
	mapWidth = 2144.0f;
	mapHeight = 1024.0f;
	spriteMap = sprites->Get(ID_SPRITE_MAP_ONE);
	fileResoucre = "resoucres\\object\\objects_lv1.txt";
	fileMap = "resources\\mapread\\lv1\\Mapstate.txt";
	tileWidth = 16.0f;
	tileHeight = 16.0f;
	screenWidth = SCREEN_WIDTH;
	screenHeight = SCREEN_HEIGHT;

	resoucres = new AladdinResources();

	tilemap = new TileMap(mapWidth, mapHeight, spriteMap, 16.0f, 16.0f);
	tilemap->LoadListTileFromFile(fileMap);

	resoucres->Load(fileResoucre, &listObject);
	for (int i = 0; i < listObject.size(); i++)
		coObjects.push_back(listObject[i]);

	grid = new Grid((int)mapWidth, (int)mapHeight, screenWidth, screenHeight);
	grid->Add(&coObjects);

	camera->SetCameraPosition(0, mapHeight - screenHeight + 22);
}

void SceneOne::Render()
{
	tilemap->Render(screenWidth, screenHeight);
}

void SceneOne::Update(DWORD dt)
{

}

void SceneOne::DestroyAll()
{
}
