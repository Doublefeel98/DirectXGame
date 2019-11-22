#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

class Aladdin : public CGameObject
{
	int level;
	int untouchable;
	DWORD untouchable_start;
	DWORD timeAttackStart;
public:
	Aladdin();
	bool IsSit;
	bool IsJump;
	bool IsGround;
	bool IsSlash;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	void ResetAnimation();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	~Aladdin();
};
