#pragma once
#include "../Framework/GameObject.h"

#define BAT_INTRO_SPEED 0.025f
#define BAT_INTRO_STATE_FLY_UP 100
#define BAT_INTRO_STATE_FLY_STRAIGHT 200

class BatIntro : public CGameObject
{
public:
	BatIntro();
	~BatIntro();
	void Update(DWORD dt);
	void Render();
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void SetState(int state);
};

