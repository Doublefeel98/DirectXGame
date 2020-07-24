#pragma once
#include "Enemy.h"
class Fleamen : public Enemy
{
	float startX, startY;
	DWORD timeJump;
public:
	Fleamen();
	virtual void FromVector(vector<string> tokens);
	~Fleamen();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};

