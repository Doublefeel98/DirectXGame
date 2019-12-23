#include "Scene.h"
#include "Game.h"

CScene::CScene()
{
	isChangeScene = false;
	camera = CCamera::GetInstance();
}
void CScene::Update(DWORD dt)
{
}
void CScene::LoadResources()
{
	//tilemap = new TileMap(widthMap, heightMap, spriteMap, 16.0f, 16.0f);
	//tilemap->LoadListTileFromFile(fileMap);

	//resoucres->Load(fileResoucre, &listObject);
	//for (int i = 0; i < listObject.size(); i++)
	//	coObjects.push_back(listObject[i]);

}