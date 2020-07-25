#include "BatIntro.h"

BatIntro::BatIntro()
{
}

BatIntro::~BatIntro()
{
}

void BatIntro::Update(DWORD dt)
{
	CGameObject::Update(dt);
	x += dx;
	y -= dy;
}

void BatIntro::Render()
{
	animation_set->at(0)->RenderWithoutCamera(x, y);
}

void BatIntro::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = top = right = bottom = 0;
}

void BatIntro::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BAT_INTRO_STATE_FLY_UP:
		vx = BAT_INTRO_SPEED;
		vy = BAT_INTRO_SPEED;
		break;
	case BAT_INTRO_STATE_FLY_STRAIGHT:
		vx = -BAT_INTRO_SPEED;
		vy = BAT_INTRO_SPEED * 0.2;
		break;
	}
}
