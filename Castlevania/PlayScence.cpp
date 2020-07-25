#include <iostream>
#include <fstream>

#include "PlayScence.h"
#include "../Framework/Utils.h"
#include "../Framework/Textures.h"
#include "../Framework/Sprites.h"
#include "../Framework/Portal.h"
#include "../Framework/BoundingMap.h"
#include "../Framework/Ground.h"
#include "BottomStair.h"
#include "TopStair.h"

#include "Brick.h"
#include "Torch.h"
#include "Candle.h"
#include "Item.h"
#include "Define.h"
#include "BlackKnight.h"
#include "VampireBat.h"
#include "Gate.h"
#include "MovingPlatform.h"
#include "Enemy.h"
#include "Ghost.h"
#include "Fleamen.h"
#include "Skeleton.h"
#include "Raven.h"
#include "Zombie.h"
#include "PhantomBat.h"

#include "../Framework/SceneManager.h"

using namespace std;


CPlayScene::CPlayScene(int id, LPCWSTR filePath) :
	CScene(id, filePath)
{
	key_handler = new CPlayScenceKeyHandler(this);
	camera = CCamera::GetInstance();
	mapHeight = 0.0f;
	mapWidth = 0.0f;

	position = -1;
}

/*
	Load scene resources from scene file (textures, sprites, animations and objects)
	See scene1.txt, scene2.txt for detail format specification
*/


void CPlayScene::_ParseSection_SETTINGS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 2) return;

	if (tokens[0] == "stage")
		stage = atoi(tokens[1].c_str());
	else if (tokens[0] == "time") {
		int timeDefault = atoi(tokens[1].c_str());
		if (timeDefault > 0) {
			defaultTimeGame = timeDefault;
		}
		remainTime = atoi(tokens[1].c_str());
	}
	else if (tokens[0] == "map_width")
		mapWidth = atoi(tokens[1].c_str());
	else if (tokens[0] == "map_height")
		mapHeight = atoi(tokens[1].c_str());
	else if (tokens[0] == "objects") {
		string pathFile = tokens[1];

		fstream pFile;
		pFile.open(pathFile, fstream::in);
		string temp;

		while (pFile.good())
		{
			getline(pFile, temp);

			if (temp[0] == '/' && temp[1] == '/') continue;	// skip comment lines
			if (temp[0] == '#') continue;	// skip comment lines

			_ParseSection_OBJECTS(temp);
		}

		pFile.close();
	}
	else if (tokens[0] == "tile_map") {
		string pathFile = tokens[1];

		int spriteId = atoi(tokens[2].c_str());

		LPSPRITE spriteMap = CSprites::GetInstance()->Get(spriteId);

		tileMap = new TileMap(mapWidth, mapHeight, spriteMap, pathFile);
	}
	else if (tokens[0] == "grid") {
		string pathFile = tokens[1];

		int cellSize = atoi(tokens[2].c_str());

		grid = new Grid(pathFile, &objects);
	}
	else
		DebugOut(L"[ERROR] Unknown scene setting %s\n", ToWSTR(tokens[0]).c_str());
}


/*
	Parse a line in section [OBJECTS]
*/
void CPlayScene::_ParseSection_OBJECTS(string line)
{
	vector<string> tokens = split(line);

	//DebugOut(L"--> %s\n",ToWSTR(line).c_str());

	if (tokens.size() < 9) return; // skip invalid lines - an object set must have at least id, x, y

	int id = atoi(tokens[0].c_str());
	int object_type = atoi(tokens[1].c_str());
	//skip name object
	float x = atof(tokens[3].c_str());
	float y = atof(tokens[4].c_str());

	//
	int width = atoi(tokens[5].c_str());
	int height = atoi(tokens[6].c_str());
	int ani_set_id = atoi(tokens[7].c_str());
	int itemType = atoi(tokens[8].c_str());

	CGameObject* obj = NULL;

	switch (object_type)
	{
	case OBJECT_TYPE_SIMON:
	{
		player = Simon::GetInstance();

		position++;

		if (player->Position != position) {
			return;
		}

		player->FromVector(tokens);

		objects.insert(objects.begin(), player);
		return;
	}
	break;
	case OBJECT_TYPE_TORCH: obj = new Torch(); break;
	case OBJECT_TYPE_CANDLE: obj = new Candle(); break;
	case OBJECT_TYPE_GATE: obj = new Gate(); break;
	case OBJECT_TYPE_MOVING_FLATFORM: obj = new MovingPlatform(); break;
	case OBJECT_TYPE_VAMPIRE_BAT: obj = new VampireBat(); break;
	case OBJECT_TYPE_BLACK_KNGHT: obj = new BlackKnight(); break;
	case OBJECT_TYPE_GHOST: obj = new Ghost(); break;
	case OBJECT_TYPE_FLEAMEN: obj = new Fleamen(); break;
	case OBJECT_TYPE_SKELETON: obj = new Skeleton(); break;
	case OBJECT_TYPE_RAVEN: obj = new Raven(); break;
	case OBJECT_TYPE_PHANTOM_BAT: obj = new PhantomBat(); break;
	case OBJECT_TYPE_ZOOMBIE: obj = new Zombie(); break;
	case OBJECT_TYPE_PORTAL:obj = new CPortal(); break;
	case OBJECT_TYPE_BOUNGDING_MAP: obj = new BoundingMap(); break;
	case OBJECT_TYPE_GROUND: obj = new Ground(); break;
	case OBJECT_TYPE_BOTTOM_STAIR: obj = new  BottomStair(); break;
	case OBJECT_TYPE_TOP_STAIR:obj = new  TopStair(); break;
	default:
		DebugOut(L"[ERR] Invalid object type: %d\n", object_type);
		return;
	}

	obj->FromVector(tokens);

	if (dynamic_cast<Enemy*>(obj)) {
		Enemy* enemy = dynamic_cast<Enemy*>(obj);
		if (enemy->IsBoss()) {
			boss = enemy;
		}
	}

	objects.push_back(obj);
}

bool CPlayScene::_checkInBoundMap()
{
	float l1 = 0, t1 = 0, r1 = mapWidth, b1 = mapHeight, l2, t2, r2, b2;
	player->GetBoundingBox(l2, t2, r2, b2);
	return CGame::IsColliding(l1, t1, r1, b1, l2, t2, r2, b2) && t2 < b1;
}

void CPlayScene::Load()
{
	DebugOut(L"[INFO] Start loading scene resources from : %s \n", sceneFilePath);

	ifstream f;
	f.open(sceneFilePath);

	// current resource section flag
	int section = SCENE_SECTION_UNKNOWN;

	char str[MAX_SCENE_LINE];
	while (f.getline(str, MAX_SCENE_LINE))
	{
		string line(str);

		if (line[0] == '#') continue;	// skip comment lines
		if (line[0] == '/' && line[1] == '/') continue;	// skip comment lines

		if (line == "[SETTINGS]") {
			section = SCENE_SECTION_SETTINGS; continue;
		}
		if (line == "[TEXTURES]") { section = SCENE_SECTION_TEXTURES; continue; }
		if (line == "[SPRITES]") {
			section = SCENE_SECTION_SPRITES; continue;
		}
		if (line == "[ANIMATIONS]") {
			section = SCENE_SECTION_ANIMATIONS; continue;
		}
		if (line == "[ANIMATION_SETS]") {
			section = SCENE_SECTION_ANIMATION_SETS; continue;
		}
		if (line[0] == '[') { section = SCENE_SECTION_UNKNOWN; continue; }

		//
		// data section
		//
		switch (section)
		{
		case SCENE_SECTION_SETTINGS: _ParseSection_SETTINGS(line); break;
		case SCENE_SECTION_TEXTURES: _ParseSection_TEXTURES(line); break;
		case SCENE_SECTION_SPRITES: _ParseSection_SPRITES(line); break;
		case SCENE_SECTION_ANIMATIONS: _ParseSection_ANIMATIONS(line); break;
		case SCENE_SECTION_ANIMATION_SETS: _ParseSection_ANIMATION_SETS(line); break;
		}
	}

	f.close();

	//CTextures::GetInstance()->Add(ID_TEX_BBOX, L"resources\\textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));

	scoreBoard = new ScoreBoard(player, 16);

	time = 0;

	DebugOut(L"[INFO] Done loading scene resources %s\n", sceneFilePath);
}

void CPlayScene::Update(DWORD dt)
{
	// We know that Mario is the first object in the list hence we won't add him into the colliable object list
	// TO-DO: This is a "dirty" way, need a more organized way

	grid->GetListOfObjects(&coObjects, CAMERA_WIDTH, CAMERA_HEIGHT);

	//for (size_t i = 0; i < coObjects.size(); i++)
	//{
	//	if (dynamic_cast<Enemy*>(coObjects.at(i))) {
	//		if (coObjects.at(i)->IsEnable() && !coObjects.at(i)->IsDead()) {
	//			bool isContain = false;
	//			for (int j = 0; j < listEnemies.size(); j++)
	//			{
	//				if (coObjects.at(i)->GetID() == listEnemies.at(j)->GetID()) {
	//					isContain = true;
	//					break;
	//				}
	//			}
	//			if (!isContain) {
	//				listEnemies.push_back(dynamic_cast<Enemy*>(coObjects.at(i)));
	//			}
	//		}
	//	}
	//}

	//for (size_t i = 0; i < listEnemies.size(); i++)
	//{
	//	if (listEnemies.at(i)->IsEnable() && !listEnemies.at(i)->IsDead()) {
	//		bool isContain = false;
	//		for (size_t j = 0; j < coObjects.size(); j++)
	//		{
	//			if (listEnemies.at(i)->GetID() == coObjects.at(j)->GetID()) {
	//				isContain = true;
	//				break;
	//			}
	//		}
	//		if (!isContain) {
	//			coObjects.push_back(listEnemies.at(i));
	//		}
	//	}
	//}

	for (size_t i = 0; i < listItems.size(); i++)
	{
		coObjects.push_back(listItems.at(i));
	}



	player->Update(dt, &coObjects);

	// skip the rest if scene was already unloaded (Mario::Update might trigger PlayScene::Unload)
	if (player == NULL) return;

	for (size_t i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Update(dt, &coObjects);

		if (coObjects[i]->IsDead()
			&& !dynamic_cast<Item*>(coObjects[i]))
		{
			coObjects[i]->SetDead(false);
			int typeItem = coObjects[i]->GetTypeItem();
			if (typeItem >= -1) {
				Item* item;
				if (typeItem == -1) {
					item = new Item();
				}
				else {
					item = new Item(typeItem);
				}
				item->Enable();
				item->SetPosition(coObjects[i]->x, coObjects[i]->y - 3);
				listItems.push_back(item);
			}
			coObjects[i]->SetEnable(false);
		}
	}

	if (player->IsKillAllEnemies())
	{
		for (int i = 0; i < coObjects.size(); i++)
		{
			if (dynamic_cast<Enemy*>(coObjects[i])) {
				Enemy* enemy = dynamic_cast<Enemy*>(coObjects[i]);
				if (!enemy->IsBoss()) {
					enemy->SetHP(0);
					enemy->SetTypeItem(-2);
				}
			}
		}
		timeKillAll += dt;
		if (timeKillAll < 400)
		{
			if ((int)(timeKillAll) % 2 == 0)
				CGame::GetInstance()->SetBackgroundColor(CROSS_COLOR_BACKGROUND);
			else
				CGame::GetInstance()->SetBackgroundColor(BACKGROUND_COLOR);
		}
		else
		{
			CGame::GetInstance()->SetBackgroundColor(BACKGROUND_COLOR);
			player->SetKillAllEnemies(false);
			timeKillAll = 0;
		}
	}

	//update scoreBoard
	time += dt;
	remainTime = defaultTimeGame - time * 0.001;
	int hp_boss = boss ? boss->GetHP() : 16;
	scoreBoard->Update(hp_boss, remainTime, stage);

	// Update camera to follow player
	camera->HandleUpdateFollowPlayer(mapWidth, mapHeight);

	if (!_checkInBoundMap()) {
		player->Reset();
		position = -1;
		this->Unload();
		this->Load();
	}

	if (Enemy::IsStop == true) {

		if (GetTickCount() - Enemy::timestop_start > 5000)
		{
			Enemy::IsStop = false;
			Enemy::timestop_start = 0;
		}
	}
}

void CPlayScene::Render()
{
	tileMap->Render(CAMERA_WIDTH, CAMERA_HEIGHT);

	grid->GetListOfObjects(&coObjects, CAMERA_WIDTH, CAMERA_HEIGHT);

	//for (size_t i = 0; i < coObjects.size(); i++)
	//{
	//	if (dynamic_cast<Enemy*>(coObjects.at(i))) {
	//		if (coObjects.at(i)->IsEnable() && !coObjects.at(i)->IsDead()) {
	//			bool isContain = false;
	//			for (int j = 0; j < listEnemies.size(); j++)
	//			{
	//				if (coObjects.at(i)->GetID() == listEnemies.at(j)->GetID()) {
	//					isContain = true;
	//					break;
	//				}
	//			}
	//			if (!isContain) {
	//				listEnemies.push_back(dynamic_cast<Enemy*>(coObjects.at(i)));
	//			}
	//		}
	//	}
	//}

	//for (size_t i = 0; i < listEnemies.size(); i++)
	//{
	//	if (listEnemies.at(i)->IsEnable() && !listEnemies.at(i)->IsDead()) {
	//		bool isContain = false;
	//		for (size_t j = 0; j < coObjects.size(); j++)
	//		{
	//			if (listEnemies.at(i)->GetID() == coObjects.at(j)->GetID()) {
	//				isContain = true;
	//				break;
	//			}
	//		}
	//		if (!isContain) {
	//			coObjects.push_back(listEnemies.at(i));
	//		}
	//	}
	//}

	for (size_t i = 0; i < listItems.size(); i++)
	{
		listItems.at(i)->Render();
	}

	for (int i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Render();
	}

	player->Render();

	scoreBoard->Render();
}

/*
	Unload current scene
*/
void CPlayScene::Unload()
{
	for (int i = 1; i < objects.size(); i++)
		delete objects[i];

	objects.clear();
	coObjects.clear();
	player = nullptr;

	if (tileMap) {
		tileMap->Unload();
		SAFE_DELETE(grid);
	}
	if (grid) {
		grid->Unload();
		SAFE_DELETE(grid);
	}
	CScene::Unload();
	//delete tileMap;
	//delete grid;
}

void CPlayScenceKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);

	Simon* simon = ((CPlayScene*)scence)->GetPlayer();
	if (simon->IsFreeze) return;
	switch (KeyCode)
	{
	case DIK_1:
		Simon::GetInstance()->Position = 0;
		CSceneManager::GetInstance()->BeforeSwitchScene(1);
		break;
	case DIK_2:
		Simon::GetInstance()->Position = 0;
		CSceneManager::GetInstance()->BeforeSwitchScene(2);
		break;
	case DIK_3:
		Simon::GetInstance()->Position = 0;
		CSceneManager::GetInstance()->BeforeSwitchScene(3);
		break;
	case DIK_4:
		Simon::GetInstance()->Position = 0;
		CSceneManager::GetInstance()->BeforeSwitchScene(4);
		break;
	case DIK_5:
		Simon::GetInstance()->Position = 0;
		CSceneManager::GetInstance()->BeforeSwitchScene(5);
		break;
	case DIK_6:
		Simon::GetInstance()->Position = 0;
		CSceneManager::GetInstance()->BeforeSwitchScene(6);
		break;
	case DIK_Z:
		if (!simon->IsFighting)
		{
			simon->SetState(SIMON_STATE_FIGHTING);
		}
		break;
	case DIK_X:
		if (!simon->IsJump && !simon->IsFighting && !simon->IsSit && !simon->IsOnStair)
		{
			simon->SetState(SIMON_STATE_JUMP);
		}
		break;
	case DIK_RIGHT:
		simon->nx = 1;
		break;
	case DIK_LEFT:
		simon->nx = -1;
		break;
	}
}

void CPlayScenceKeyHandler::OnKeyUp(int KeyCode)
{
	Simon* simon = ((CPlayScene*)scence)->GetPlayer();
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	if (simon->IsFreeze) return;
	switch (KeyCode)
	{
	case DIK_LEFT:
		simon->vx = 0;
		simon->IsRun = false;
		if (simon->IsOnStair) {
			simon->vx = 0;
			simon->vy = 0;
		}
		break;
	case DIK_RIGHT:
		simon->vx = 0;
		simon->IsRun = false;
		if (simon->IsOnStair) {
			simon->vx = 0;
			simon->vy = 0;
		}
		break;
	case DIK_DOWN:
		if (simon->IsSit) {
			simon->IsSit = false;
			simon->y -= 8;
		}
		if (simon->IsOnStair) {
			simon->vx = 0;
			simon->vy = 0;
		}
		break;
	case DIK_UP:
		if (simon->IsOnStair) {
			simon->vx = 0;
			simon->vy = 0;
		}
		simon->IsKeyState_DIK_UP = false;
		break;
	}
}

void CPlayScenceKeyHandler::KeyState(BYTE* states)
{
	CGame* game = CGame::GetInstance();
	Simon* simon = ((CPlayScene*)scence)->GetPlayer();

	// disable control key when Mario die 
	if (simon->IsFreeze) return;
	if (simon->GetState() == SIMON_STATE_DIE) return;
	if (game->IsKeyDown(DIK_DOWN))
	{
		if (simon->canClimbDownStair)
		{
			simon->SetState(SIMON_STATE_CLIMB_STAIR_DESCEND);
		}
		else if (simon->IsOnStair) {
			simon->SetState(SIMON_STATE_CLIMB_STAIR_DESCEND);
		}
		else {
			simon->SetState(SIMON_STATE_SIT_DOWN);
		}
	}
	else if (game->IsKeyDown(DIK_UP)) {
		if (simon->canClimbUpStair)
		{
			simon->SetState(SIMON_STATE_CLIMB_STAIR_ASCEND);
		}
		else if (simon->IsOnStair) {
			simon->SetState(SIMON_STATE_CLIMB_STAIR_ASCEND);
		}

		simon->IsKeyState_DIK_UP = true;
	}
	else if (game->IsKeyDown(DIK_RIGHT))
	{
		if (simon->IsOnStair && (!simon->canClimbDownStair || !simon->canClimbUpStair)) {
			if (simon->directionStair == 1)
			{
				simon->SetState(SIMON_STATE_CLIMB_STAIR_ASCEND);
			}
			else if (simon->directionStair == -1) {
				simon->SetState(SIMON_STATE_CLIMB_STAIR_DESCEND);
			}
		}
		else if (!simon->IsFighting)
		{
			simon->SetState(SIMON_STATE_WALK_RIGHT);
		}
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		if (simon->IsOnStair && (!simon->canClimbDownStair || !simon->canClimbUpStair)) {
			if (simon->directionStair == 1)
			{
				simon->SetState(SIMON_STATE_CLIMB_STAIR_DESCEND);
			}
			else if (simon->directionStair == -1) {
				simon->SetState(SIMON_STATE_CLIMB_STAIR_ASCEND);
			}
		}
		else if (!simon->IsFighting)
		{
			simon->SetState(SIMON_STATE_WALK_LEFT);
		}
	}

	else
		simon->SetState(SIMON_STATE_IDLE);

	/*CCamera* camera = CCamera::GetInstance();
	if (game->IsKeyDown(DIK_RIGHT))
		camera->SetCameraPosition(camera->GetCameraPosition().x + 10, camera->GetCameraPosition().y);
	else if (game->IsKeyDown(DIK_LEFT))
		camera->SetCameraPosition(camera->GetCameraPosition().x - 10, camera->GetCameraPosition().y);
	else if (game->IsKeyDown(DIK_UP))
		camera->SetCameraPosition(camera->GetCameraPosition().x, camera->GetCameraPosition().y - 10);
	else if (game->IsKeyDown(DIK_DOWN))
		camera->SetCameraPosition(camera->GetCameraPosition().x, camera->GetCameraPosition().y + 10);*/
}
