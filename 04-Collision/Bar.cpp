#include "Bar.h"

void Bar::Render()
{
	RenderBoundingBox();
}

void Bar::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + BAR_WIDTH;
	b = y + BAR_HEIGHT;
}

void Bar::Update(DWORD dt)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);
	y += dy;
	if (vx > 0 && x > 500 - BAR_HEIGHT) x = 500 - BAR_HEIGHT;
	if (vy < 0 && y < 0) y = 0;
}

void Bar::SetState(int state)
{
	switch (state)
	{
	case BAR_STATE_UP:
		vx = BAR_WALKING_SPEED;
		break;
	case BAR_STATE_DOWN:
		vx = -BAR_WALKING_SPEED;
		break;
	case BAR_STATE_IDLE:
		vx = 0;
		break;
	}
}

