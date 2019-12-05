#include "ThrowApples.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

ThrowApples::ThrowApples() :CGameObject() {
	x = -5;
	y = -5;
	width =	APPLE_BBOX_WIDTH;
	height = APPLE_BBOX_HEIGHT;

	AddAnimation(2200);		// throw apple
	
	AddAnimation(2201);		// throw apple break
	AddAnimation(2202);
	AddAnimation(2203);
	AddAnimation(2204);
	isEnable = false;
}
ThrowApples::~ThrowApples() {

}
void ThrowApples::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isEnable) {
		left = x;
		top = y;
		right = left + APPLE_BBOX_WIDTH;
		bottom = top + APPLE_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void ThrowApples::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case THROW_APPLE_STATE_RIGHT:
		vx = THROW_APPLE_SPEED;
		nx = 1;
		break;
	case THROW_APPLE_STATE_LEFT:
		vx = -THROW_APPLE_SPEED;
		nx = -1;
		break;
	}
}
void ThrowApples::Render() {
	if (isEnable) {
		animations[0]->Render(x, y);
		RenderBoundingBox();
	}
}
void ThrowApples::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	
	if (isEnable) {
		CGameObject::Update(dt);

		// Simple fall down
		vy += THROW_APPLE_GRAVITY * (dt/2);

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		CalcPotentialCollisions(coObjects, coEvents);

		// No collision occured, proceed normally
		if (coEvents.size() == 0)
		{
			x += dx;
			y += dy;
		}
		else {
			isEnable = false;
		}
	}
	else {
		x = -5;
		y = -5;
		vy = 0;
	}
}