#include "SceneBoss.h"
#include "../Framework/debug.h"

SceneBoss::SceneBoss(Aladdin* aladdin)
{
	IsEnableSpitFire = false;

	this->aladdin = aladdin;
	this->aladdin->SetPosition(140, 290);

	CSprites* sprites = CSprites::GetInstance();

	mapWidth = 960.0f;
	mapHeight = 416.0f;
	spriteMap = sprites->Get(ID_SPRITE_MAP_BOSS);

	fileMap = "resources\\map\\lv_boss\\tilemap.txt";
	fileResoucre = "resources\\map\\lv_boss\\boss_obj.txt";
	//fileGrid = "resources\\map\\lv_boss\\text_grid.txt";

	tileWidth = 16.0f;
	tileHeight = 16.0f;
	screenWidth = SCREEN_WIDTH;
	screenHeight = SCREEN_HEIGHT;

	tilemap = new TileMap(mapWidth, mapHeight, spriteMap, tileWidth, tileHeight);
	tilemap->LoadListTileFromFile(fileMap);

	aladinObjects = new AladdinObjects();
	aladinObjects->Load(fileResoucre, &objects);

	MapCollision* mapCollision = new MapCollision();
	mapCollision->SetPosition(96 - DEVIATION_X, 1);
	mapCollision->SetWidth(36);
	mapCollision->SetHeight(415);
	objects.push_back(mapCollision);

	mapCollision = new MapCollision();
	mapCollision->SetPosition(835 - DEVIATION_X, 1);
	mapCollision->SetWidth(36);
	mapCollision->SetHeight(415);
	objects.push_back(mapCollision);

	Spitfire* spitfire = new Spitfire();
	spitfire->SetPosition(141 - DEVIATION_X, 311);
	spitfire->SetWidth(97);
	spitfire->SetHeight(36);
	objects.push_back(spitfire);
	spitFires.push_back(spitfire);

	spitfire = new Spitfire();
	spitfire->SetPosition(337 - DEVIATION_X, 311);
	spitfire->SetWidth(97);
	spitfire->SetHeight(36);
	objects.push_back(spitfire);
	spitFires.push_back(spitfire);

	spitfire = new Spitfire();
	spitfire->SetPosition(533 - DEVIATION_X, 311);
	spitfire->SetWidth(97);
	spitfire->SetHeight(36);
	objects.push_back(spitfire);
	spitFires.push_back(spitfire);

	spitfire = new Spitfire();
	spitfire->SetPosition(729 - DEVIATION_X, 311);
	spitfire->SetWidth(97);
	spitfire->SetHeight(36);
	objects.push_back(spitfire);
	spitFires.push_back(spitfire);

	jafar = new Jafar();
	jafar->SetPosition(mapWidth / 2 - JAFAR_BBOX_WIDTH / 2, 348 - JAFAR_BBOX_HEIGHT);
	objects.push_back(jafar);

	for (int i = 0; i < objects.size(); i++)
		coObjects.push_back(objects[i]);

	scoreboard = new ScoreBoard(aladdin, 0);
}

void SceneBoss::Render()
{
	tilemap->Render(screenWidth, screenHeight);

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Render();
	}

	aladdin->Render();
	scoreboard->Render();
}

void SceneBoss::Update(DWORD dt)
{
	if (!IsEnableSpitFire)
	{
		if (jafar->state == JAFAR_STATE_SNAKE)
		{
			for (int i = 0; i < spitFires.size(); i++)
			{
				spitFires.at(i)->isEnableFire = true;
			}
			IsEnableSpitFire = true;
		}
	}

	aladdin->Update(dt, &coObjects);
	for (int i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Update(dt, &coObjects);
	}

	if (aladdin->x < 133 - DEVIATION_X)
	{
		aladdin->x = 133 - DEVIATION_X;
	}
	else if (aladdin->x > 834 - DEVIATION_X)
	{
		aladdin->x = 834 - DEVIATION_X;
	}


	if (abs(aladdin->vx) > ALADDIN_MAX_SPEED)
	{
		aladdin->vx = ALADDIN_MAX_SPEED;
	}

	DebugOut(L"[INFO] aladdin->vx: %d\n", aladdin->vx);

	time += dt;
	scoreboard->Update(0, 500 - time * 0.001, 3, 2);
}

void SceneBoss::DestroyAll()
{

}
