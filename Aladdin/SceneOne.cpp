#include "SceneOne.h"
#include "Ground.h"
#include "Pilar.h"
#include "Exit.h"
#include "Fance.h"
#include "../Framework/debug.h"

SceneOne::SceneOne()
{
	this->aladdin = Aladdin::GetInstance();
	this->aladdin->SetPosition(100, 1052);
	//this->aladdin->SetPosition(2170, 63);
	//this->aladdin->SetPosition(432, 580);

	CSprites* sprites = CSprites::GetInstance();
	//mapWidth = 2144.0f;
	//mapHeight = 1024.0f;

	mapWidth = 2272.0f;
	mapHeight = 1152.0f;
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

	aladinObjects = new AladdinObjects();
	aladinObjects->Load(fileResoucre, &objects);

	leftMap = new MapCollision();
	leftMap->SetPosition(-32 - DEVIATION_X, 0);
	leftMap->SetWidth(32);
	leftMap->SetHeight(1139);
	leftMap->SetId(objects.size() + 1);
	objects.push_back(leftMap);

	rightMap = new MapCollision();
	rightMap->SetPosition(2272 - DEVIATION_X, 1);
	rightMap->SetWidth(32);
	rightMap->SetHeight(1139);
	rightMap->SetId(objects.size() + 1);
	objects.push_back(rightMap);

	Pilar* pilar = new Pilar();
	pilar->SetState(PILAR_STATE_1);
	pilar->SetPosition(161, 773);
	pilars.push_back(pilar);

	pilar = new Pilar();
	pilar->SetState(PILAR_STATE_2);
	pilar->SetPosition(481, 957);
	pilars.push_back(pilar);

	pilar = new Pilar();
	pilar->SetState(PILAR_STATE_3);
	pilar->SetPosition(801, 373);
	pilars.push_back(pilar);

	pilar = new Pilar();
	pilar->SetState(PILAR_STATE_4);
	pilar->SetPosition(1153, 925);
	pilars.push_back(pilar);

	pilar = new Pilar();
	pilar->SetState(PILAR_STATE_5);
	pilar->SetPosition(1490, 405);
	pilar->SetWidth(PILAR_BBOX_WIDTH_5);
	pilar->SetHeight(PILAR_BBOX_HEIGHT_5);
	pilar->SetId(objects.size() + 1);
	objects.push_back(pilar);

	exit = new Exit();
	exit->SetState(EXIT_STATE);
	exit->SetPosition(2177, 69);
	exit->SetWidth(EXIT_BBOX_WIDTH);
	exit->SetHeight(EXIT_BBOX_HEIGHT);
	exit->SetId(objects.size() + 1);

	Fance* fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(10, 881);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(10, 625);

	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(10, 396);

	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(10, 140);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(10, 1);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(522, 881);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(522, 625);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(522, 396);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(522, 140);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(522, 1);
	fances.push_back(fance);


	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(1034, 881);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(1034, 625);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(1034, 396);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(1034, 140);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(1034, 1);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(1546, 881);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(1546, 625);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(1546, 396);

	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(1546, 140);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(1546, 1);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(2058, 881);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(2058, 625);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(2058, 396);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(2058, 140);
	fances.push_back(fance);

	fance = new Fance();
	fance->SetState(FANCE_STATE);
	fance->SetPosition(2058, 1);
	fances.push_back(fance);

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
	exit->Render();
	//for (int i = 1; i < objects.size(); i++)
	//{
	//	objects[i]->Render();
	//}
	/*for (int i = 0; i < exit.size(); i++)
	{
		exit[i]->Render();
	}*/
	
	for (int i = 0; i < pilars.size(); i++)
	{
		pilars[i]->Render();
	}



	for (int i = 0; i < fances.size(); i++)
	{
		fances[i]->Render();
	}

	scoreboard->Render();
}

void SceneOne::Update(DWORD dt)
{
	if (aladdin->x > 2212 - DEVIATION_X && aladdin->y - ALADDIN_BBOX_HEIGHT < 244)
	{
		CSceneManager::GetInstance()->ChangeScene(new SceneBoss());
		return;
	}
	grid->GetListOfObjects(&coObjects, screenWidth, screenHeight);

	aladdin->Update(dt, &coObjects);

	for (int i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Update(dt, &coObjects);
	}

	//aladdin->Update(dt, &coObjects);
	//for (int i = 1; i < coObjects.size(); i++)
	//{
	//	coObjects[i]->Update(dt, &coObjects);
	//}

	time += dt;
	scoreboard->Update(0, 500 - time * 0.001, 3, 2);
	//DebugOut(L"[INFO] aladdin hp: %d\n", aladdin->GetHP());
}

void SceneOne::DestroyAll()
{
}
