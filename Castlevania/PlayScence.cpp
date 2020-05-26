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

using namespace std;

#define CROSS_COLOR_BACKGROUND D3DCOLOR_XRGB(188, 188, 188) // Màu xám 188, 188, 188
#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)

CPlayScene::CPlayScene(int id, LPCWSTR filePath) :
	CScene(id, filePath)
{
	key_handler = new CPlayScenceKeyHandler(this);
	camera = CCamera::GetInstance();
	mapHeight = 0.0f;
	mapWidth = 0.0f;
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

void CPlayScene::_ParseSection_TEXTURES(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 5) return; // skip invalid lines

	int texID = atoi(tokens[0].c_str());
	wstring path = ToWSTR(tokens[1]);
	int R = atoi(tokens[2].c_str());
	int G = atoi(tokens[3].c_str());
	int B = atoi(tokens[4].c_str());

	CTextures::GetInstance()->Add(texID, path.c_str(), D3DCOLOR_XRGB(R, G, B));
	listIdTextures.push_back(texID);
}

void CPlayScene::_ParseSection_SPRITES(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 6) return; // skip invalid lines

	int ID = atoi(tokens[0].c_str());
	int l = atoi(tokens[1].c_str());
	int t = atoi(tokens[2].c_str());
	int width = atoi(tokens[3].c_str());
	int height = atoi(tokens[4].c_str());
	int texID = atoi(tokens[5].c_str());
	int dx = atoi(tokens[6].c_str());
	int dy = atoi(tokens[7].c_str());

	LPDIRECT3DTEXTURE9 tex = CTextures::GetInstance()->Get(texID);
	if (tex == NULL)
	{
		DebugOut(L"[ERROR] Texture ID %d not found!\n", texID);
		return;
	}

	CSprites::GetInstance()->AddByWidthHeight(ID, l, t, width, height, tex, dx, dy);
	listIdSprites.push_back(ID);
}

void CPlayScene::_ParseSection_ANIMATIONS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 4) return; // skip invalid lines - an animation must at least has 1 frame and 1 frame time

	//DebugOut(L"--> %s\n",ToWSTR(line).c_str());

	int isLoop = atoi(tokens[1].c_str());

	LPANIMATION ani = new CAnimation(100, isLoop);

	int ani_id = atoi(tokens[0].c_str());
	for (int i = 2; i < tokens.size(); i += 2)	// why i+=2 ?  sprite_id | frame_time  
	{
		int sprite_id = atoi(tokens[i].c_str());
		int frame_time = atoi(tokens[i + 1].c_str());
		ani->Add(sprite_id, frame_time);
	}

	CAnimations::GetInstance()->Add(ani_id, ani);
	listIdAnimations.push_back(ani_id);
}

void CPlayScene::_ParseSection_ANIMATION_SETS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 2) return; // skip invalid lines - an animation set must at least id and one animation id

	int ani_set_id = atoi(tokens[0].c_str());

	LPANIMATION_SET s = new CAnimationSet();

	CAnimations* animations = CAnimations::GetInstance();

	for (int i = 1; i < tokens.size(); i++)
	{
		int ani_id = atoi(tokens[i].c_str());

		LPANIMATION ani = animations->Get(ani_id);
		s->push_back(ani);
	}

	CAnimationSets::GetInstance()->Add(ani_set_id, s);
	listIdAnimationSets.push_back(ani_set_id);
}

/*
	Parse a line in section [OBJECTS]
*/
void CPlayScene::_ParseSection_OBJECTS(string line)
{
	vector<string> tokens = split(line);

	//DebugOut(L"--> %s\n",ToWSTR(line).c_str());

	if (tokens.size() < 5) return; // skip invalid lines - an object set must have at least id, x, y

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
		if (player != NULL)
		{
			DebugOut(L"[ERROR] MARIO object was created before! ");
			return;
		}
		player = Simon::GetInstance();
		player->SetPosition(x, y);
		objects.push_back(obj);
		return;
	}
	break;
	case OBJECT_TYPE_TORCH: obj = new Torch(); break;
	case OBJECT_TYPE_CANDLE: obj = new Candle(); break;
	case OBJECT_TYPE_GATE: obj = new Gate(); break;
	case OBJECT_TYPE_MOVING_FLATFORM: obj = new MovingPlatform(x, y); break;
	case OBJECT_TYPE_ITEM_HEART: obj = new Item(ITEM_LARGE_HEART); break;
	case OBJECT_TYPE_ITEM_SMALL_HEART: obj = new Item(ITEM_SMALL_HEART); break;
	case OBJECT_TYPE_ITEM_KNIFE: obj = new Item(ITEM_DAGGER); break;
	case OBJECT_TYPE_ITEM_AXE: obj = new Item(ITEM_AXE); break;
	case OBJECT_TYPE_ITEM_BOOMERANG: obj = new Item(ITEM_BOOMERANG); break;
	case OBJECT_TYPE_ITEM_WHIP: obj = new Item(ITEM_MORNING_STAIR); break;
	case OBJECT_TYPE_VAMPIRE_BAT: obj = new VampireBat(x, y); break;
	case OBJECT_TYPE_BLACK_KNGHT: obj = new BlackKnight(x, y); break;
	case OBJECT_TYPE_GHOST: obj = new Ghost(x, y); break;
	case OBJECT_TYPE_FLEAMEN: obj = new Fleamen(x, y); break;
	case OBJECT_TYPE_SKELETON: obj = new Skeleton(x, y); break;
	case OBJECT_TYPE_RAVEN: obj = new Raven(x, y); break;
	case OBJECT_TYPE_PHANTOM_BAT: obj = new PhantomBat(x, y); break;
	case OBJECT_TYPE_ZOOMBIE: obj = new Zombie(x, y); break;
	case OBJECT_TYPE_PORTAL:
	{
		int scene_id = atoi(tokens[7].c_str());
		obj = new CPortal(x, y, width, height, scene_id);
		obj->SetID(id);
		obj->SetTypeItem(-2);
		objects.push_back(obj);
		return;
	}
	break;
	case OBJECT_TYPE_BOUNGDING_MAP: obj = new BoundingMap(); break;
		break;
	case OBJECT_TYPE_GROUND: obj = new Ground(); break;
		break;
	case OBJECT_TYPE_BOTTOM_STAIR: {
		obj = new BottomStair(ani_set_id);
		obj->SetID(id);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		obj->SetType(object_type);
		obj->SetTypeItem(-2);
		objects.push_back(obj);
		return;
	}
	case OBJECT_TYPE_TOP_STAIR:
	{
		obj = new TopStair(ani_set_id);
		obj->SetID(id);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		obj->SetType(object_type);
		obj->SetTypeItem(-2);
		objects.push_back(obj);
		return;
	}
	default:
		DebugOut(L"[ERR] Invalid object type: %d\n", object_type);
		return;
	}

	// General object setup
	obj->SetID(id);
	obj->SetPosition(x, y);
	obj->SetWidth(width);
	obj->SetHeight(height);
	obj->SetType(object_type);
	obj->SetTypeItem(itemType);

	if (ani_set_id > 0) {
		obj->SetAnimationSet(ani_set_id);
	}


	objects.push_back(obj);
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

	grid->GetListOfObjects(&coObjects, SCREEN_WIDTH, SCREEN_HEIGHT);

	for (size_t i = 0; i < listItems.size(); i++)
	{
		coObjects.push_back(listItems.at(i));
	}

	player->Update(dt, &coObjects);
	for (size_t i = 0; i < coObjects.size(); i++)
	{
		coObjects[i]->Update(dt, &coObjects);

		if (coObjects[i]->IsDead()
			&& !dynamic_cast<Item*>(coObjects[i]))
		{
			coObjects[i]->SetDead(false);
			int typeItem = coObjects[i]->GetTypeItem();
			if (typeItem == -1) {
				Item* item = new Item();
				item->SetEnable(true);
				item->SetPosition(coObjects[i]->x, coObjects[i]->y - 3);
				listItems.push_back(item);
			}
			else if (typeItem > -1) {
				Item* item = new Item(typeItem);
				item->SetEnable(true);
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
				enemy->SetHP(0);
				enemy->SetTypeItem(-2);
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

	// skip the rest if scene was already unloaded (Mario::Update might trigger PlayScene::Unload)
	if (player == NULL) return;

	//update scoreBoard
	time += dt;
	remainTime = defaultTimeGame - time * 0.001;
	scoreBoard->Update(16, remainTime, stage);

	// Update camera to follow player
	D3DXVECTOR3 pos = camera->GetCameraPosition();
	float cx, cy, boundHeight;

	player->GetPosition(cx, cy);

	if (mapWidth > SCREEN_WIDTH - 15) {
		if (cx < (SCREEN_WIDTH - 15) / 2) {
			cx = 0;
		}
		else if (cx + (SCREEN_WIDTH - 15) / 2 > mapWidth) {
			cx = mapWidth - (SCREEN_WIDTH - 15);
		}
		else {
			cx = cx + (SCREEN_WIDTH - 15) / 2 - (SCREEN_WIDTH - 15);
		}
	}
	else {
		cx = 0;
	}

	if (mapHeight > SCREEN_HEIGHT)
	{
		if (cy + player->GetHeight() / 2 < mapHeight - SCREEN_HEIGHT / 2) {
			cy = cy + player->GetHeight() / 2 - SCREEN_HEIGHT / 2;
		}
		else {
			cy = mapHeight - SCREEN_HEIGHT;
		}
	}
	else {
		cy = mapHeight > SCREEN_HEIGHT;
	}


	camera->SetCameraPosition((int)cx, (int)cy);
}

void CPlayScene::Render()
{
	tileMap->Render(SCREEN_WIDTH, SCREEN_HEIGHT);

	grid->GetListOfObjects(&coObjects, SCREEN_WIDTH, SCREEN_HEIGHT);

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
	for (int i = 0; i < objects.size(); i++)
		delete objects[i];

	objects.clear();
	coObjects.clear();
	player = NULL;

	if (tileMap) {
		tileMap->Unload();
		delete tileMap;
		tileMap = NULL;
	}
	if (grid) {
		grid->Unload();
		delete grid;
		grid = NULL;
	}
	//delete tileMap;
	//delete grid;

	CTextures::GetInstance()->Clear(listIdTextures);
	CSprites::GetInstance()->Clear(listIdSprites);
	CAnimations::GetInstance()->Clear(listIdAnimations);
	CAnimationSets::GetInstance()->Clear(listIdAnimationSets);

	listIdTextures.clear();
	listIdSprites.clear();
	listIdAnimations.clear();
	listIdAnimationSets.clear();
}

void CPlayScenceKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);

	Simon* simon = ((CPlayScene*)scence)->GetPlayer();
	if (simon->IsFreeze) return;
	switch (KeyCode)
	{
	case DIK_Z:
		if (!simon->IsFighting)
		{
			simon->SetState(SIMON_STATE_FIGHTING);
		}
		break;
	case DIK_X:
		if (!simon->IsJump && !simon->IsFighting && !simon->IsSit)
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
