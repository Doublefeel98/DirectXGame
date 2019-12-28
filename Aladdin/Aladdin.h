#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"
#include "ThrowApples.h"
#include "Sword.h"
#include "Chains.h"

class Aladdin : public CGameObject
{
	static Aladdin* __instance;
	int level;
	DWORD untouchable_start;
	DWORD timeAttackStart;
	DWORD timeSittingSlashStart;
	DWORD timeStandStart;
	DWORD timeIdleStart;
	DWORD timeSitStart;
	DWORD timeLookUpStart;
	DWORD timeThrowStart;
	DWORD timeRunJumpStart;
	DWORD timeJumpSlashStart;
	DWORD timeJumpThrowStart;
	DWORD timeEnemyHurt;
	int hurtable;
	DWORD timeHurtableStart;
	vector<ThrowApples*> throwApples;
	Sword* sword;
	int hp;
	int indexApple;
	int countPenny;
	int countLife;
	int countPoint;
	Aladdin();	
	Chains* chainsCanAble;
public:
	int checkPointX, checkPointY;
	int untouchable;
	bool IsRun;
	bool IsSit;
	bool IsLookingUp;
	bool IsJump;
	bool IsGround;
	bool IsSlash;
	bool IsStand;
	bool IsThrow;
	bool IsHurt;
	bool IsClimb;
	bool canAbleClimb;
	bool canAbleClimbUp;
	bool canAbleClimbDown;
	bool IsClimbing;
	bool IsEnemyHurt;
	bool fallingAfterClimbing;
	bool IsMoveCameraWhenLookingUp();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	int GetHP() { return this->hp; }
	void SetHP(int hp) { this->hp = hp; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	void StartHurting(int damage);
	void ResetAnimationsSlash();
	void ResetAnimationsSitDown();
	void ResetAnimationIdle();
	void ResetAnimationsThrow();
	void ResetAnimationsJump();
	void ResetAnimationsLookUp();
	void ResetAllAnimation();
	void EnemyHurted(int damage);
	int GetCountApple() { return this->throwApples.size() - indexApple; }
	void addApple(int count);
	bool CanAbleThrow() { return this->throwApples.size() != indexApple; }
	int GetCountPenny() { return countPenny; }
	void addPenny(int count) { countPenny += count; }
	int GetCountLife() { return countLife; }
	int GetCountPoint() { return countPoint; }
	void addPoint(int count) { countPoint += count; }
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	~Aladdin();
	static Aladdin* GetInstance();
	void SetPosition(float x, float y);
	void ResetCheckpoint();
};
