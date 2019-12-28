#include "SceneBoss.h"
#include "../Framework/debug.h"
#include "SceneEnd.h"
#include "Sound.h"
SceneBoss::SceneBoss()
{
	if (sound == false) {
		Sound::getInstance()->playRep(BOSS_MUSIC, "boss");
		sound = true;
	}
	IsEnableSpitFire = false;
	isCheck = false;

	this->aladdin = Aladdin::GetInstance();
	this->aladdin->SetPosition(140, 290);
	this->aladdin->checkPointX = 140;
	this->aladdin->checkPointY = 290;

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

	leftMap = new MapCollision();
	leftMap->SetPosition(96 - DEVIATION_X, 1);
	leftMap->SetWidth(36);
	leftMap->SetHeight(415);
	objects.push_back(leftMap);

	rightMap = new MapCollision();
	rightMap->SetPosition(835 - DEVIATION_X, 1);
	rightMap->SetWidth(36);
	rightMap->SetHeight(415);
	objects.push_back(rightMap);

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
	if (aladdin->GetHP() <= 0)
	{
		aladdin->ResetCheckpoint();
	}

	if (jafar->GetHP() <= 0)
	{
		Sound::getInstance()->stop("boss");

		CSceneManager::GetInstance()->ChangeScene(new SceneEnd());
		return;
	}
	if (aladdin->GetCountApple() == 0)
	{
		if (isCheck == false)
		{
			isCheck = true;
			int position = Helper::random(1, 4);
			switch (position)
			{
			case 1:
			{
				Apple* apple = new Apple();
				apple->SetPosition(165 - DEVIATION_X, 296);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(178 - DEVIATION_X, 288);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(190 - DEVIATION_X, 297);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(179 - DEVIATION_X, 302);
				objects.push_back(apple);
			}
			break;
			case 2:
			{
				Apple* apple = new Apple();
				apple->SetPosition(367 - DEVIATION_X, 289);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(381 - DEVIATION_X, 278);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(393 - DEVIATION_X, 290);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(382 - DEVIATION_X, 300);
				objects.push_back(apple);
			}
			break;
			case 3:
			{
				Apple* apple = new Apple();
				apple->SetPosition(560 - DEVIATION_X, 292);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(576 - DEVIATION_X, 281);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(590 - DEVIATION_X, 291);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(577 - DEVIATION_X, 301);
				objects.push_back(apple);
			}
			break;
			case 4:
			{
				Apple* apple = new Apple();
				apple->SetPosition(760, 292);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(774, 284);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(787, 294);
				objects.push_back(apple);
				apple = new Apple();
				apple->SetPosition(776, 301);
				objects.push_back(apple);
			}
			break;
			default:
				break;
			}
		}
	}
	else {
		isCheck = false;
	}

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

	coObjects.clear();
	for (int i = 0; i < objects.size(); i++)
	{
		coObjects.push_back(objects.at(i));
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
