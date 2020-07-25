#include "Boomerang.h"
#include "Enemy.h"
#include "Define.h"

#define DELTA_X 10

void Boomerang::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	Weapon::Update(dt, coObjects);

	if (vx > 0 && abs(x - startX) >= CAMERA_WIDTH / 2 - DELTA_X) {
		x = startX + CAMERA_WIDTH / 2 - DELTA_X;
		vx = -vx;
		nx = -1;
		countReturn++;
	}

	if (vx < 0 && x <= startX - CAMERA_WIDTH / 2 + DELTA_X) {
		x = startX - CAMERA_WIDTH / 2 + DELTA_X;
		vx = -vx;
		nx = 1;
		countReturn++;
	}

	if (countReturn > 1) {
		isEnable = false;
		return;
	}
}

void Boomerang::Render()
{
	Weapon::Render();
	if (this->isEnable == false)
		count = 0;
}

void Boomerang::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + 15;
	bottom = y + 14;
}

Boomerang::Boomerang(float _startX)
{
	SetAnimationSet(4);
	useHeart = 1;
	damage = 2;
	this->startX = _startX;

	countReturn = 0;
}

Boomerang::~Boomerang()
{
}
