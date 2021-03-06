#pragma once
#include "Enemy.h"
class VampireBat : public Enemy
{
	float startX, startY;
	int distanceX;
public:
	VampireBat();
	virtual void FromVector(vector<string> tokens);
	~VampireBat();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};

