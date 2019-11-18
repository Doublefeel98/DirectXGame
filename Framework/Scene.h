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
	int state;
	static bool changeScene;
	TileMap* tilemap;
	D3DXVECTOR3 cameraCheckpoint;
	MapCollision* leftmap;
	MapCollision* rightmap;
	string fileResoucre;
	char* fileMap;
	CCamera* camera;
	//CResoucres *resoucres;
	vector<LPGAMEOBJECT> listObject;
	vector<LPGAMEOBJECT> coObjects;
	float mapWidth, mapHeight;
	Grid* grid;
	LPSPRITE spriteMap;
	int screenWidth, screenHeight;
	float tileWidth, tileHeight;
public:
	CScene();
	virtual void LoadResources();
	virtual void Render() = 0;
	virtual void Update(DWORD dt);
	virtual void DestroyAll() = 0;
	//virtual bool GetChangingScene() { return changeScene; };
	//virtual void SetChangingScene(bool status) { changeScene = status; }
};

