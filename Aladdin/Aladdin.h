#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

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
public:
	Aladdin();
	bool IsSit;
	bool IsLookingUp;
	bool IsJump;
	bool IsGround;
	bool IsSlash;
	bool IsStand;
	bool IsMoveCameraWhenLookingUp();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	void ResetAnimationsSlash();
	void ResetAnimationsSitDown();
	void ResetAnimationIdle();
	void ResetAllAnimation();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	~Aladdin();
};
