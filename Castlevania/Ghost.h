﻿#pragma once
#include "Enemy.h"
class Ghost : public Enemy
{
	float startX, startY;
	int ny;
	float x_back;
	DWORD time_waiting;
	int old_nx;
public:
	Ghost();
	virtual void FromVector(vector<string> tokens);
	~Ghost();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};
