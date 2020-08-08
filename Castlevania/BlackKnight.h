#pragma once
#include "Enemy.h"
class BlackKnight : public Enemy
{
	float startX, startY;
	int distanceX;
	int prev_hp;
	DWORD time_hurt;
public:
	void Hurted(int damage);
	BlackKnight();
	virtual void FromVector(vector<string> tokens);
	~BlackKnight();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};
