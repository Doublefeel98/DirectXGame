#pragma once
#include "Whip.h"
#include "../Framework/Player.h"

class Simon : public CPlayer
{
	static Simon* __instance;
	int level;
	int hp;
	int score;
	int life;
	int heart;
	DWORD untouchable_start;
	DWORD timeAttackStart;
	float oldVy;

	float checkPointX, checkPointY;
	Whip* whip;
	float posXStair, posYStair;

	int hurtable;
	DWORD hurtable_start;

	int typeWeaponCollect;
	int typeShotCollect;

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
	bool IsHurt;

	bool IsRun;
	bool IsGround;

	bool IsOnStair;
	bool IsUpStair;
	bool IsDownStair;
	bool canClimbUpStair;
	bool canClimbDownStair;
	int directionStair;

	bool IsFreeze;
	DWORD timeFreezeStart;

	void Reset();

	int untouchable;
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	int GetHP() { return this->hp; }
	void SetHP(int hp) { this->hp = hp; }
	int GetLife() { return life; }
	int GetScore() { return score; }
	int GetHeart() { return this->heart; }
	int GetLevelWhip();
	void SetEnergy(int energy) { this->heart = energy; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	void StartHurting() { IsHurt = true; hurtable = 1; hurtable_start = GetTickCount(); }
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void ResetCheckpoint();
	void ResetAnimationFighting();
	void ResetAnimationHurt();

	void Load(LPCWSTR simonFile);
	void SetPosition(float x, float y);
	int GetTypeWeaponCollect() { return typeWeaponCollect; }
	int GetTypeShotCollect() { return typeShotCollect; }
};

