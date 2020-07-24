#include "Simon.h"
#include "Define.h"
#include "Torch.h"
#include "../Framework/SceneManager.h"
#include "Candle.h"
#include "../Framework/Utils.h"
#include "../Framework/Portal.h"
#include "../Framework/BoundingMap.h"
#include "../Framework/Ground.h"
#include "BottomStair.h"
#include "TopStair.h"
#include "VampireBat.h"
#include "MovingPlatform.h"

#include <iostream>
#include <fstream>

Simon* Simon::__instance = NULL;

using namespace std;

#pragma region public methods

void Simon::SetTypeOfWeapon(int item)
{
	for (int i = 0; i < 3; i++)
	{
		switch (item)
		{

		case ITEM_HOLY_WATER:
			typeWeaponCollect = item;
			break;
		case ITEM_AXE:
			typeWeaponCollect = item;
			break;
		case ITEM_DAGGER:
			typeWeaponCollect = item;
			break;
		case ITEM_BOOMERANG:
			typeWeaponCollect = item;
			break;
		case ITEM_STOP_WATCH:
			typeWeaponCollect = item;
			break;
		default:
			break;
		}
	}
}

Simon* Simon::GetInstance()
{
	if (__instance == NULL) __instance = new Simon();
	return __instance;
}

void Simon::Reset()
{
	/*SetState(SIMON_STATE_IDLE);
	SetPosition(checkPointX, checkPointY);
	SetSpeed(0, 0);*/

	level = 0;
	hp = SIMON_HP;
	heart = 5;
	score = 0;
	life = life - 1;

	untouchable = 0;
	untouchable_start = 0;

	IsFighting = false;
	IsJump = false;
	IsSit = false;
	IsRun = false;

	timeAttackStart = 0;

	IsFreeze = false;
	timeFreezeStart = 0;

	state = SIMON_STATE_IDLE;

	DoCaoDiDuoc = 0;
	_IsFirstOnStair = false;

	IsUseSubWeapons = false;

	numberSubWeaponAble = 1;

	isKillAllEnemies = false;

	Position = 0;
}

void Simon::SetState(int state)
{
	CGameObject::SetState(state);
	DWORD currentTime = GetTickCount();
	switch (state)
	{
	case SIMON_STATE_WALK_RIGHT:
	{
		vx = SIMON_WALKING_SPEED;
		nx = 1;
		IsRun = true;
	}
	break;
	case SIMON_STATE_WALK_LEFT:
	{
		vx = -SIMON_WALKING_SPEED;
		nx = -1;
		IsRun = true;
	}
	break;
	case SIMON_STATE_JUMP:
		IsJump = true;
		IsGround = false;
		vy = -SIMON_JUMP_SPEED_Y;
	case SIMON_STATE_IDLE:
		IsSit = false;
		IsRun = false;
		//vx = 0;
		break;
	case SIMON_STATE_DIE:
		vy = -SIMON_DIE_DEFLECT_SPEED;
		break;
	case SIMON_STATE_SIT_DOWN:
		vx = 0;
		IsSit = true;
		break;
	case SIMON_STATE_CLIMB_STAIR_ASCEND:
		if (!IsOnStair) {
			if (directionStair > 0) {
				x = posXStair - 6;
			}
			else {
				x = posXStair + 5;
				//y = posYStair + 7 - SIMON_BBOX_HEIGHT;
			}
			IsOnStair = true;
			IsUpStair = true;
			IsDownStair = false;
			_IsFirstOnStair = true;
		}
		else {
			_IsFirstOnStair = false;
			if (canClimbDownStair) {
				IsOnStair = false;
				IsUpStair = false;
				IsDownStair = false;
				y -= 2;
				x = posXStair;
				vx = 0;
			}
			else {
				if (directionStair > 0) {
					vx = SIMON_JUMP_SPEED_STAIR;
				}
				else {
					vx = -SIMON_JUMP_SPEED_STAIR;
				}
				vy = -SIMON_JUMP_SPEED_STAIR;
				IsOnStair = true;
				IsUpStair = true;
				IsDownStair = false;
			}
		}
		break;
	case SIMON_STATE_CLIMB_STAIR_DESCEND:
		if (!IsOnStair) {
			if (directionStair > 0) {
				x = posXStair;
				y = posYStair + 8;
			}
			else {
				x = posXStair + 6;
				y = posYStair + 8;
			}

			IsOnStair = true;
			IsUpStair = false;
			IsDownStair = true;
			_IsFirstOnStair = true;
		}
		else {
			if (directionStair > 0) {
				vx = -SIMON_JUMP_SPEED_STAIR;
			}
			else {
				vx = SIMON_JUMP_SPEED_STAIR;
			}
			vy = SIMON_JUMP_SPEED_STAIR;
			IsOnStair = true;
			IsUpStair = false;
			IsDownStair = true;
			_IsFirstOnStair = false;
		}
		break;
	case SIMON_STATE_FIGHTING:
		if (IsJump) {
			y -= 4;
		}
		vx = 0;
		IsFighting = true;
		timeAttackStart = currentTime;
		if (IsKeyState_DIK_UP && typeWeaponCollect >= ITEM_DAGGER && typeWeaponCollect <= ITEM_STOP_WATCH && heart > 0 && !IsUseSubWeapons) {
			for (int i = 0; i < numberSubWeaponAble; i++)
			{
				if (heart <= 0) {
					break;
				}

				Weapon* weapon = nullptr;
				switch (typeWeaponCollect)
				{

				case ITEM_HOLY_WATER:
					weapon = new FireBomb();
					break;
				case ITEM_AXE:
					weapon = new Axe();
					break;
				case ITEM_DAGGER:
					weapon = new Dagger();
					break;
				case ITEM_BOOMERANG:
					weapon = new Boomerang(x);
					break;
				case ITEM_STOP_WATCH:
					weapon = new Stopwatch();
					break;
				default:
					break;
				}
				if (weapon != nullptr) {
					if (heart - weapon->GetUseHeart() >= 0)
					{
						IsUseSubWeapons = true;
						heart -= weapon->GetUseHeart();
						weapon->SetEnable(true);
						weapon->SetPosition(this->x, this->y);
						if (this->nx == -1)
							weapon->nx = -1;
						else
							weapon->nx = 1;
						weapons.push_back(weapon);
					}
				}

			}
		}
		if (!IsUseSubWeapons) {
			whip->SetEnable(true);
			whip->SetState(WHIP_STATE_PREPARE);
		}
		break;
	case SIMON_STATE_HURT:
		IsGround = false;
		if (IsOnStair) {
			vy = 0;
			vx = 0;
		}
		else
		{
			if (nx > 0)
			{
				vx = -0.03;
			}
			if (nx < 0)
			{
				vx = 0.03;
			}
			if (dy <= 0 || vy >= 0 || dy > 0)
				vy = -0.2;

		}
		break;
	}
}

void Simon::AddScore(int point)
{
	score += point;
}

int Simon::GetLevelWhip()
{
	return this->whip->GetLevel();
}

void Simon::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDead)
	{
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else
	{
		int boxWidth = SIMON_BBOX_WIDTH;
		int boxHeight = SIMON_BBOX_HEIGHT;
		if (IsJump && !IsFighting) {
			boxHeight -= 8;
		}

		left = x;
		top = y;

		if (IsSit) {
			boxHeight -= 8;
			top = y + 8;
		}
		right = left + boxWidth;
		bottom = top + boxHeight;
	}
}

void Simon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	DWORD now = GetTickCount();
	CGameObject::Update(dt);

	// Simple fall down
	if (!IsOnStair) {
		vy += SIMON_GRAVITY * dt;
	}
	else {
		vy = 0;
		if (IsUpStair) {
			nx = directionStair;
		}
		else {
			nx = -directionStair;
		}

		DoCaoDiDuoc = DoCaoDiDuoc + abs(vy) * 16.0f;

		if (DoCaoDiDuoc > SIMON_FIXED_LENGTH_STAIR)
		{
			/* fix lỗi mỗi lần đi vượt quá 8px */
			if (nx > 0 && IsUpStair) // đi lên bên phải
			{
				x -= (DoCaoDiDuoc - SIMON_FIXED_LENGTH_STAIR);
				y += (DoCaoDiDuoc - SIMON_FIXED_LENGTH_STAIR);
			}
			if (nx < 0 && IsUpStair) // đi lên bên trái
			{
				x += (DoCaoDiDuoc - SIMON_FIXED_LENGTH_STAIR);
				y += (DoCaoDiDuoc - SIMON_FIXED_LENGTH_STAIR);
			}
			if (nx < 0 && IsDownStair) // đi xuống bên phải
			{
				x -= (DoCaoDiDuoc - SIMON_FIXED_LENGTH_STAIR);
				y -= (DoCaoDiDuoc - SIMON_FIXED_LENGTH_STAIR);
			}
			if (nx > 0 && IsDownStair) // đi xuống bên trái
			{
				x += (DoCaoDiDuoc - SIMON_FIXED_LENGTH_STAIR);
				y -= (DoCaoDiDuoc - SIMON_FIXED_LENGTH_STAIR);
			}
			DebugOut(L"DoCaoDiDuoc = %f . dy = %f . y = %f\n", DoCaoDiDuoc, dy, y);
			DoCaoDiDuoc = 0;
		}
		else {
			DebugOut(L"DoCaoDiDuoc = %f . dy = %f . y = %f\n", DoCaoDiDuoc, dy, y);
		}

	}

	if (IsFighting)
	{
		if (!IsUseSubWeapons) {
			whip->SetPosition(this->x, this->y, IsSit);
			whip->Update(dt, coObjects);

			if (now - timeAttackStart > (SIMON_ATTACK_TIME - 150))
			{
				whip->SetState(WHIP_STATE_HIT);
			}
		}

		if (now - timeAttackStart > SIMON_ATTACK_TIME)
		{
			timeAttackStart = 0;
			IsFighting = false;
			whip->ResetAnimation();
			whip->SetEnable(false);
			ResetAnimationFighting();
			IsUseSubWeapons = false;
		}
	}


	_updateSubWeapon(dt, coObjects);


	if (IsFreeze) {
		if (now - timeFreezeStart > TIME_FREEZE_MAX)
		{
			timeFreezeStart = 0;
			IsFreeze = false;
		}
		else {
			IsRun = false;
			vx = 0;
			vy = 0;
		}
	}

	if (canClimbUpStair) {
		canClimbUpStair = false;
	}
	if (canClimbDownStair) {
		canClimbDownStair = false;
	}

	// reset untouchable timer if untouchable time has passed
	if (GetTickCount() - untouchable_start > SIMON_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	if (IsHurt) {
		if (GetTickCount() - hurtable_start > 1000)
		{
			hurtable_start = 0;
			hurtable = 0;
			IsHurt = false;
			ResetAnimationHurt();
		}
	}

	if (this->GetState() != SIMON_STATE_SIT_DOWN)
		IsSit = false;

	_checkAABB(coObjects);
	_checkSweptAABB(coObjects);
}

void Simon::Render()
{
	int ani = 0;
	float posX = x, posY = y;
	if (state == SIMON_STATE_DIE)
	{
		if (nx > 0) ani = SIMON_ANI_DEATH_RIGHT;
		else ani = SIMON_ANI_DEATH_LEFT;
	}
	else
	{
		if (IsHurt) {
			if (nx > 0) {
				ani = SIMON_ANI_HURT_RIGHT;
			}
			else {
				ani = SIMON_ANI_HURT_LEFT;
			}
		}
		else if (IsSit) {
			if (IsFighting)
			{
				if (nx > 0) ani = SIMON_ANI_FIGHTING_SIT_RIGHT;
				else ani = SIMON_ANI_FIGHTING_SIT_LEFT;
			}
			else if (nx != 0)
			{
				if (nx > 0) ani = SIMON_ANI_SIT_DOWN_RIGHT;
				else ani = SIMON_ANI_SIT_DOWN_LEFT;
			}
			posY = y + 8;
		}
		else if (IsJump) {
			if (IsFighting)
			{
				if (nx > 0) ani = SIMON_ANI_FIGHTING_RIGHT;
				else ani = SIMON_ANI_FIGHTING_LEFT;
			}
			else if (nx != 0)
			{
				if (nx > 0) ani = SIMON_ANI_SIT_DOWN_RIGHT;
				else ani = SIMON_ANI_SIT_DOWN_LEFT;
			}
		}
		else if (IsUpStair) {
			if (IsFighting)
			{
				if (nx > 0) ani = SIMON_ANI_FIGHTING_ASCEND_STAIR_RIGHT;
				else ani = SIMON_ANI_FIGHTING_ASCEND_STAIR_LEFT;
			}
			else {
				if (vx == 0)
				{
					if (nx > 0) ani = SIMON_ANI_IDLE_STAIR_ASCEND_RIGHT;
					else ani = SIMON_ANI_IDLE_STAIR_ASCEND_LEFT;
				}
				else
				{
					if (vx > 0)
						ani = SIMON_ANI_CIMB_STAIR_ASCEND_RIGHT;
					else ani = SIMON_ANI_CIMB_STAIR_ASCEND_LEFT;
				}
			}
		}
		else if (IsDownStair) {
			if (IsFighting)
			{
				if (nx > 0) ani = SIMON_ANI_FIGHTING_DESCEND_STAIR_RIGHT;
				else ani = SIMON_ANI_FIGHTING_DESCEND_STAIR_LEFT;
			}
			else {
				if (vx == 0)
				{
					if (nx > 0) ani = SIMON_ANI_IDLE_STAIR_DESCEND_RIGHT;
					else ani = SIMON_ANI_IDLE_STAIR_DESCEND_LEFT;
				}
				else
				{
					if (vx > 0)
						ani = SIMON_ANI_CIMB_STAIR_DESCEND_RIGHT;
					else ani = SIMON_ANI_CIMB_STAIR_DESCEND_LEFT;
				}
			}
		}
		else {
			if (IsFighting)
			{
				if (nx > 0) ani = SIMON_ANI_FIGHTING_RIGHT;
				else ani = SIMON_ANI_FIGHTING_LEFT;
			}
			else {
				if (!IsRun)
				{
					if (nx > 0) ani = SIMON_ANI_IDLE_RIGHT;
					else ani = SIMON_ANI_IDLE_LEFT;
				}
				else
				{
					if (nx > 0) {
						ani = SIMON_ANI_WALKING_RIGHT;
					}
					else {
						ani = SIMON_ANI_WALKING_LEFT;
					}
				}
			}
		}

	}

	if (IsFighting)
	{
		whip->SetPosition(this->x, this->y, IsSit);
		whip->Render(nx > 0);
	}

	if (typeWeaponCollect >= ITEM_DAGGER && typeWeaponCollect <= ITEM_STOP_WATCH) {
		for (int i = 0; i < weapons.size(); i++)
		{
			if (weapons[i]->IsEnable())
				weapons[i]->Render();
		}
	}

	int alpha = 255;
	if (untouchable) alpha = 128;
	if (IsFreeze)
	{
		animation_set->at(ani)->Render(posX, posY, alpha, rand() % 256, rand() % 256, rand() % 256);
	}
	else {
		animation_set->at(ani)->Render(posX, posY, alpha);
	}


	RenderBoundingBox();
}

void Simon::ResetCheckpoint()
{
	this->x = checkPointX;
	this->y = checkPointY;
	this->hp = SIMON_MAX_HP;
}

void Simon::ResetAnimationFighting()
{
	ResetAni(SIMON_ANI_FIGHTING_RIGHT);
	ResetAni(SIMON_ANI_FIGHTING_LEFT);

	ResetAni(SIMON_ANI_FIGHTING_SIT_RIGHT);
	ResetAni(SIMON_ANI_FIGHTING_SIT_LEFT);

	ResetAni(SIMON_ANI_FIGHTING_ASCEND_STAIR_RIGHT);
	ResetAni(SIMON_ANI_FIGHTING_ASCEND_STAIR_LEFT);


	ResetAni(SIMON_ANI_FIGHTING_DESCEND_STAIR_RIGHT);
	ResetAni(SIMON_ANI_FIGHTING_DESCEND_STAIR_LEFT);
}

void Simon::ResetAnimationHurt()
{
	ResetAni(SIMON_ANI_HURT_LEFT);
	ResetAni(SIMON_ANI_HURT_RIGHT);
}

void Simon::Load(LPCWSTR simonFile)
{
	DebugOut(L"[INFO] Start loading simon resources from : %s \n", simonFile);

	ifstream f;
	f.open(simonFile);

	// current resource section flag
	int section = SCENE_SECTION_UNKNOWN;

	char str[MAX_SCENE_LINE];
	while (f.getline(str, MAX_SCENE_LINE))
	{
		string line(str);

		if (line[0] == '#') continue;	// skip comment lines
		if (line[0] == '/' && line[1] == '/') continue;	// skip comment lines

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
		if (line == "[SETTINGS]") {
			section = SCENE_SECTION_SETTINGS; continue;
		}
		if (line[0] == '[') { section = SCENE_SECTION_UNKNOWN; continue; }

		//
		// data section
		//
		switch (section)
		{
		case SCENE_SECTION_TEXTURES: _ParseSection_TEXTURES(line); break;
		case SCENE_SECTION_SPRITES: _ParseSection_SPRITES(line); break;
		case SCENE_SECTION_ANIMATIONS: _ParseSection_ANIMATIONS(line); break;
		case SCENE_SECTION_ANIMATION_SETS: _ParseSection_ANIMATION_SETS(line); break;
		case SCENE_SECTION_SETTINGS: _ParseSection_SETTINGS(line); break;
		}
	}

	f.close();

	CTextures::GetInstance()->Add(ID_TEX_BBOX, L"resources\\textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));

	DebugOut(L"[INFO] Done loading simon resources %s\n", simonFile);
}

void Simon::SetPosition(float x, float y)
{
	checkPointX = x;
	checkPointY = y;
	this->x = x;
	this->y = y;
}

void Simon::Hurted(int damage)
{
	if (hp > 0)
	{
		hp -= damage;
		StartUntouchable();
		SetState(SIMON_STATE_HURT);
		StartHurting();
	}
	else
		SetState(SIMON_STATE_DIE);
}
void Simon::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	checkPointX = x;
	checkPointY = y;
	if (tokens.size() > 10) {
		this->nx = atoi(tokens[9].c_str());
		int state = atoi(tokens[10].c_str());

		if (state == 0) {
			this->IsOnStair = false;
			this->IsOnStair = false;
			this->IsUpStair = false;

			this->SetState(SIMON_STATE_IDLE);
		}
		else {
			this->IsOnStair = true;
			if (state == 1) {
				this->IsUpStair = true;
				this->IsDownStair = false;
			}
			else {
				this->IsUpStair = false;
				this->IsDownStair = true;
			}
			this->directionStair = this->nx;
			this->vx = 0;
			this->vy = 0;
		}
	}
}
#pragma endregion

#pragma region private methods
Simon::Simon()
{
	level = 0;
	hp = SIMON_HP;
	heart = 5;
	score = 0;
	life = 3;

	untouchable = 0;
	untouchable_start = 0;

	IsFighting = false;
	IsJump = false;
	IsSit = false;
	IsRun = false;

	timeAttackStart = 0;

	IsFreeze = false;
	timeFreezeStart = 0;

	whip = new Whip();

	state = SIMON_STATE_IDLE;

	DoCaoDiDuoc = 0;
	_IsFirstOnStair = false;

	IsUseSubWeapons = false;

	numberSubWeaponAble = 1;

	isKillAllEnemies = false;

	Position = 0;
}

#pragma region load data

void Simon::_ParseSection_TEXTURES(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 5) return; // skip invalid lines

	int texID = atoi(tokens[0].c_str());
	wstring path = ToWSTR(tokens[1]);
	int R = atoi(tokens[2].c_str());
	int G = atoi(tokens[3].c_str());
	int B = atoi(tokens[4].c_str());

	CTextures::GetInstance()->Add(texID, path.c_str(), D3DCOLOR_XRGB(R, G, B));
}

void Simon::_ParseSection_SPRITES(string line)
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
}

void Simon::_ParseSection_ANIMATIONS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 3) return; // skip invalid lines - an animation must at least has 1 frame and 1 frame time

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
}

void Simon::_ParseSection_ANIMATION_SETS(string line)
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
}

void Simon::_ParseSection_SETTINGS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 2) return;

	if (tokens[0] == "animation_set")
	{
		int ani_set_id = atoi(tokens[1].c_str());
		SetAnimationSet(ani_set_id);
	}
	else if (tokens[0] == "animation_set_whip")
	{
		int ani_set_whip_id = atoi(tokens[1].c_str());
		whip->SetAnimationSet(ani_set_whip_id);
	}
	else
		DebugOut(L"[ERROR] Unknown scene setting %s\n", ToWSTR(tokens[0]).c_str());
}

#pragma endregion

void Simon::_checkAABB(vector<LPGAMEOBJECT>* coObjects)
{
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Enemy*>(coObjects->at(i)))
		{
			Enemy* enemy = dynamic_cast<Enemy*>(coObjects->at(i));
			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			enemy->GetBoundingBox(l2, t2, r2, b2);
			if ((CGame::IsColliding(l1, t1, r1, b1, l2, t2, r2, b2))) {
				_handleLogicCollisionEnemy(enemy);
			}
		}
		else if (dynamic_cast<BottomStair*>(coObjects->at(i))) {
			if (!IsJump) {
				BottomStair* bottomStair = dynamic_cast<BottomStair*>(coObjects->at(i));

				float l1, t1, r1, b1, l2, t2, r2, b2;
				GetBoundingBox(l1, t1, r1, b1);
				bottomStair->GetBoundingBox(l2, t2, r2, b2);

				if (CGame::IsColliding(l1, t1, r1, b1, l2, t2, r2, b2))
				{
					if (b2 > b1) {
						canClimbUpStair = true;
						posXStair = bottomStair->x;
						posYStair = bottomStair->y;
						directionStair = bottomStair->nx;
					}
				}
			}
		}
		else if (dynamic_cast<TopStair*>(coObjects->at(i))) {
			if (!IsJump) {
				TopStair* topStair = dynamic_cast<TopStair*>(coObjects->at(i));

				float l1, t1, r1, b1, l2, t2, r2, b2;
				GetBoundingBox(l1, t1, r1, b1);
				topStair->GetBoundingBox(l2, t2, r2, b2);

				if (CGame::IsColliding(l1, t1, r1, b1, l2, t2, r2, b2))
				{
					canClimbDownStair = true;
					posXStair = topStair->x;
					posYStair = topStair->y;
					directionStair = topStair->nx;
				}
			}

		}
		else if (dynamic_cast<Item*>(coObjects->at(i))) {
			Item* item = dynamic_cast<Item*>(coObjects->at(i));

			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			item->GetBoundingBox(l2, t2, r2, b2);

			if (CGame::IsColliding(l1, t1, r1, b1, l2, t2, r2, b2))
			{
				_handleLogicCollisionItem(item);
			}
		}
	}
}

void Simon::_checkSweptAABB(vector<LPGAMEOBJECT>* coObjects)
{
	DWORD now = GetTickCount();

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	if (state != SIMON_STATE_DIE)
		CalcPotentialCollisions(coObjects, coEvents);

	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT e = coEvents[i];
		if (dynamic_cast<Torch*>(e->obj) || dynamic_cast<Candle*>(e->obj))
		{
			coEvents.erase(coEvents.begin() + i);
		}
	}

	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		if (!_IsFirstOnStair) {
			x += dx;
			y += dy;
		}
		else {
			_IsFirstOnStair = false;
		}

	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		float rdx = 0;
		float rdy = 0;

		// TODO: This is a very ugly designed function!!!!
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny, rdx, rdy);


		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];

			if (dynamic_cast<Item*>(e->obj))
			{
				Item* item = dynamic_cast<Item*>(e->obj);
				_handleLogicCollisionItem(item);
			}
			if ((dynamic_cast<Enemy*>(e->obj))) {
				Enemy* enemy = dynamic_cast<Enemy*>(e->obj);
				_handleLogicCollisionEnemy(enemy);
			}

			if (dynamic_cast<Ground*>(e->obj))
			{
				if (IsOnStair) {
					bool isHandleLogic = false;
					if (IsDownStair) {
						
						if (e->ny < 0)
						{
							if (canClimbUpStair) {
								IsOnStair = false;
								IsUpStair = false;
								IsDownStair = false;
								vx = 0;
								y -= 2;
								if (directionStair > 0) {
									x = posXStair - 8;
								}
								else {
									x = posXStair;
								}
								isHandleLogic = true;
							}
						}
					}
					if (!isHandleLogic) {
						x += dx;
						y += dy;
					}
				}
				else {
					Ground* ground = dynamic_cast<Ground*>(e->obj);
					// block 

					x += min_tx * dx + nx * 0.4f;
					y += min_ty * dy + ny * 0.4f;

					if (nx != 0) vx = 0;
					if (ny != 0) vy = 0;

					if (IsJump)
					{
						if (e->ny < 0) {
							y -= 10;
							IsJump = false;
						}

					}
					if (IsHurt) {
						hurtable_start = 0;
						hurtable = 0;
						IsHurt = false;
						vx = 0;
						ResetAnimationHurt();
					}
					/*if (e->ny < 0 || e->nx != 0)
					{
						x += min_tx * dx + nx * 0.4f;
						y += min_ty * dy + ny * 0.4f;

						if (nx != 0) vx = 0;
						if (ny != 0) vy = 0;

						if (IsJump)
						{
							y -= 8;
							IsJump = false;
						}
						if (IsHurt) {
							hurtable_start = 0;
							hurtable = 0;
							IsHurt = false;
							vx = 0;
							ResetAnimationHurt();
						}
					}
					else {
						x += dx;
						y += dy;
					}*/
				}
			}
			else if (dynamic_cast<BoundingMap*>(e->obj)) {
				x += min_tx * dx + nx * 0.4f;
				y += min_ty * dy + ny * 0.4f;

				if (nx != 0) vx = 0;
				if (ny != 0) vy = 0;
			}
			else if (dynamic_cast<MovingPlatform*>(e->obj)) {
				if (e->ny < 0)
				{
					x += min_tx * dx + nx * 0.4f;
					y += min_ty * dy + ny * 0.4f;

					if (ny != 0) vy = 0;
					vx = e->obj->vx;
				}
				if (IsJump)
				{
					y -= 8;
					IsJump = false;
				}
			}
			else if (dynamic_cast<BottomStair*>(e->obj))
			{
				x += dx;
				if (e->ny < 0)
				{
					y += dy + ny * -0.7f;
				}
				else if (e->nx != 0)
				{
					if (ny < 0)
						y += dy + ny * 0.7f;
					else if (ny > 0)
						y += dy + ny * -0.7f;
				}
				else {
					y += dy;
				}
			}
			else if (dynamic_cast<CPortal*>(e->obj))
			{
				CPortal* p = dynamic_cast<CPortal*>(e->obj);
				this->Position = p->GetPosistionSimon();
				CSceneManager::GetInstance()->BeforeSwitchScene(p->GetSceneId());
				return;
			}
			else {
				x += dx;
				if (ny < 0)
					y += dy + ny * 0.7f;
				else if (ny > 0)
					y += dy + ny * -0.7f;

			}
		}
	}

	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void Simon::_handleLogicCollisionItem(Item* item)
{
	DWORD now = GetTickCount();
	if (!item->IsDead() && item->IsEnable())
	{
		switch (item->GetTypeItem())
		{
		case ITEM_MORNING_STAIR:
			if (whip->GetLevel() < WHIP_LEVEL_3)
			{
				whip->SetLevel(whip->GetLevel() + 1);
				IsFreeze = true;
				timeFreezeStart = now;
			}
			break;
		case ITEM_SMALL_HEART:
			heart += 1;
			break;
		case ITEM_LARGE_HEART:
			heart += 5;
			break;
		case ITEM_MONEY_BAG_RED:
			score += 100;
			item->GetMoneyEffect()->Enable();
			break;
		case ITEM_MONEY_BAG_PURPLE:
			score += 400;
			item->GetMoneyEffect()->Enable();
			break;
		case ITEM_MONEY_BAG_WHITE:
			score += 700;
			item->GetMoneyEffect()->Enable();
			break;
		case ITEM_DAGGER:
			SetTypeOfWeapon(ITEM_DAGGER);
			break;
		case ITEM_AXE:
			SetTypeOfWeapon(ITEM_AXE);
			break;
		case ITEM_HOLY_WATER:
			SetTypeOfWeapon(ITEM_HOLY_WATER);
			break;
		case ITEM_BOOMERANG:
			SetTypeOfWeapon(ITEM_BOOMERANG);
			break;
		case ITEM_STOP_WATCH:
			SetTypeOfWeapon(ITEM_STOP_WATCH);
			break;
		case ITEM_BONUSES:
			score += 1000;
			item->GetMoneyEffect()->Enable();
			break;
		case ITEM_CROWN:
		case ITEM_CHEST:
			score += 2000;
			item->GetMoneyEffect()->Enable();
			break;
		case ITEM_DOUBLE_SHOT:
			typeShotCollect = ITEM_DOUBLE_SHOT;
			numberSubWeaponAble = 2;
			break;
		case ITEM_TRIPLE_SHOT:
			typeShotCollect = ITEM_TRIPLE_SHOT;
			numberSubWeaponAble = 3;
			break;
		case ITEM_CROSS:
			SetKillAllEnemies(true);
			break;
		case ITEM_INVISIBILITY_POTION:
			StartUntouchable();
			break;
		}
		item->SetDead(true);
		item->SetEnable(false);
	}
}

void Simon::_handleLogicCollisionEnemy(Enemy* enemy)
{
	if (enemy->vx != 0)
	{
		if (untouchable == 0)
		{
			if (enemy->isEnable != false)
			{
				if (hp > 0)
				{
					hp -= enemy->GetDamage();
					StartUntouchable();
					SetState(SIMON_STATE_HURT);
					StartHurting();
					if (dynamic_cast<VampireBat*>(enemy))
					{
						enemy->SetEnable(false);
						enemy->GetCollisionEffect()->SetEnable(true);
					}
				}
				else
					SetState(SIMON_STATE_DIE);
			}
		}
	}
}

void Simon::_updateSubWeapon(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (typeWeaponCollect >= ITEM_DAGGER && typeWeaponCollect <= ITEM_STOP_WATCH) {
		for (int i = 0; i < weapons.size(); i++)
		{
			if (weapons[i]->IsEnable())
				weapons[i]->Update(dt, coObjects);
		}
	}

	for (int i = 0; i < weapons.size(); i++) {
		if (weapons[i]->IsEnable()) {
			if (dynamic_cast<Boomerang*>(weapons[i])) {

				Boomerang* weapon = dynamic_cast<Boomerang*>(weapons[i]);

				if (weapon->countReturn == 0) {
					continue;
				}

				float l1, t1, r1, b1, l2, t2, r2, b2;
				GetBoundingBox(l1, t1, r1, b1);
				weapons[i]->GetBoundingBox(l2, t2, r2, b2);

				if (CGame::IsColliding(l1, t1, r1, b1, l2, t2, r2, b2))
				{
					weapons[i]->SetEnable(false);
					heart++;
				}
			}
		}
	}
}

#pragma endregion
