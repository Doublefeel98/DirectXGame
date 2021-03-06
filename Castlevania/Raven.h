﻿#pragma once
#include "Enemy.h"
class Raven : public Enemy
{
	float startX, startY;
	int ny;
	DWORD time_wait;
public:
	Raven();
	virtual void FromVector(vector<string> tokens);
	~Raven();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};
