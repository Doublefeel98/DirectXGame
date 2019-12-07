#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"
#include "ThrowApples.h"
#include "Sword.h"

class Aladdin : public CGameObject
{
	int level;
	int untouchable;
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
	ThrowApples* throwApple;
	Sword* sword;
public:
	Aladdin();
	bool IsSit;
	bool IsLookingUp;
	bool IsJump;
	bool IsGround;
	bool IsSlash;
	bool IsStand;
	bool IsThrow;
	bool IsMoveCameraWhenLookingUp();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	void ResetAnimationsSlash();
	void ResetAnimationsSitDown();
	void ResetAnimationIdle();
	void ResetAnimationsThrow();
	void ResetAnimationsJump();
	void ResetAnimationsLookUp();
	void ResetAllAnimation();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	~Aladdin();
};
