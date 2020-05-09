#include "MovingPlatform.h"


MovingPlatform::MovingPlatform(float startX, float startY)
{
	vx = 0.025f;

	this->startX = startX;
	this->startY = startY;

	vx = 0.02;
	nx = 1;
}

void MovingPlatform::Render()
{
	animation_set->at(0)->Render(x, y);
	RenderBoundingBox();
}

void MovingPlatform::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt);
	x += dx;
	if (vx > 0 && abs(x - startX) > 32) {
		x = startX + 32;
		vx = -vx;
		nx = -1;
	}

	if (vx < 0 && x <= startX) {
		x = startX;
		vx = -vx;
		nx = 1;
	}
}

void MovingPlatform::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = l + 32;
	b = t + 8;
}

MovingPlatform::~MovingPlatform()
{
}
