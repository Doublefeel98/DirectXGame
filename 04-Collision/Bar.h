#pragma once
#include "GameObject.h"
#define BAR_WIDTH  50
#define BAR_HEIGHT 200
#define BAR_STATE_DOWN -1
#define BAR_STATE_UP 1
#define BAR_STATE_IDLE 0
#define BAR_WALKING_SPEED 50

class Bar : public CGameObject
{
	int state;
public:
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void SetState(int state);
	void Update(DWORD dt);
};

