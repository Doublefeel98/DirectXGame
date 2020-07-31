#pragma once
#include "Enemy.h"
#include "BossDeadEffect.h"
class PhantomBat : public Enemy
{
	float startX, startY;
	BossDeadEffect* bossDeadEffect;

	D3DXVECTOR2 random;
	D3DXVECTOR2 simonPos;
	D3DXVECTOR2 batPos;
	float ny;
	float nx;
	float distance;
	bool isFlyToRandomPos;
	bool isFlyToSimonPos;
	float waitTime;
	float hurtTime;
	DWORD delayTime;
	int previousHP;
	float introTime;
	DWORD chaseTime;
	bool isHurted;

	float getPt(float n1, float n2, float perc);
public:
	PhantomBat();
	virtual void FromVector(vector<string> tokens);
	~PhantomBat();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);

	void CalculateSimonPos(DWORD dt);
	void Fly(DWORD dt);
	void RandomPos();
	void CheckHPChange();
	void CheckHurtTime(DWORD dt);
	void FlyToRandomPos(DWORD dt);
};
