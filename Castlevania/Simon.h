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
	float oldVy;

	float checkPointX, checkPointY;
	Whip* whip;
	float posXStair, posYStair;

	void _ParseSection_TEXTURES(string line);
	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);
	void _ParseSection_ANIMATION_SETS(string line);
	void _ParseSection_SETTINGS(string line);

	Simon();
public:

	static Simon* GetInstance();
	bool IsFighting;
	bool IsSit;
	bool IsJump;

	bool IsRun;
	bool IsGround;

	bool IsOnStair;
	bool IsUpStair;
	bool IsDownStair;
	bool canClimbUpStair;
	bool canClimbDownStair;
	int directionStair;

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

	void Load(LPCWSTR simonFile);
	void SetPosition(float x, float y);
};

