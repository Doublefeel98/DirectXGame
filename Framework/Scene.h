#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include "TileMap.h"
#include "Resoucres.h"
#include "MapCollision.h"
#include "Grid.h"
class CScene
{
protected:
	DWORD time;
	int state;
	TileMap* tilemap;
	D3DXVECTOR3 cameraCheckpoint;
	MapCollision* leftMap;
	MapCollision* rightMap;
	char* fileResoucre;
	char* fileGrid;
	char* fileMap;
	CCamera* camera;
	vector<LPGAMEOBJECT> objects;
	vector<LPGAMEOBJECT> coObjects;
	float mapWidth, mapHeight;
	Grid* grid;
	LPSPRITE spriteMap;
	int screenWidth, screenHeight;
	float tileWidth, tileHeight;
public:
	bool isChangeScene;
	CScene();
	float GetMapWidth() { return mapWidth; }
	float GetMapHeight() { return mapHeight; }
	virtual void LoadResources();
	virtual void Render() = 0;
	virtual void Update(DWORD dt);
	virtual void DestroyAll() = 0;
	//virtual bool GetChangingScene() { return changeScene; }
	//virtual void SetChangingScene(bool status) { changeScene = status; }
};

