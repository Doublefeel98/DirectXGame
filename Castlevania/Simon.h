#pragma once
#include "Whip.h"
#include "../Framework/GameObject.h"

class Simon : public CGameObject
{
	static Simon* __instance;
	int level;
	int hp;
	int score;
	int life;
	int energy;
	DWORD untouchable_start;
	DWORD timeAttackStart;

	float checkPointX, checkPointY;
	Whip* whip;
public:
	Simon(float x, float y);
	static Simon* GetInstance();
	bool IsFighting;
	bool IsSit;
	bool IsJump;
	bool IsAscendStair;
	bool IsDescendStair;

	bool IsRun;
	bool IsGround;

	void Reset();

	int untouchable;
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	int GetHP() { return this->hp; }
	void SetHP(int hp) { this->hp = hp; }
	int GetLife() { return life; }
	int GetScore() { return score; }
	int GetEnergy() { return this->energy; }
	int GetLevelWhip();
	void SetEnergy(int energy) { this->energy = energy; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void ResetCheckpoint();
	void ResetAnimationFighting();
	void SetAnimationSetWhip(LPANIMATION_SET ani_set);
};

