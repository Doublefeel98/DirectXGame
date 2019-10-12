#pragma once
#include "GameObject.h"
#define BALL_WIDTH 10
#define BALL_HEIGHT 10
#define BALL_UNTOUCHABLE_TIME 5000

class Ball : public CGameObject
{
	int level;
	int untouchable;
	DWORD untouchable_start;
public:
	void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	void Render();
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};

