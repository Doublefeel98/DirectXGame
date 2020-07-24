#include "FireBomb.h"
#include "../Framework/Ground.h"
#include "../Framework/BoundingMap.h"

void FireBomb::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	Weapon::Update(dt, coObjects);
	if (IsFiring == true)
	{
		vy = 0;
		vx = 0;
	}
	if (isEnable == true)
		vy += 0.0007 * dt;

	if (IsFiring == true)
	{
		timefiring += dt;
		if (timefiring > 1000)
		{
			IsFiring = false;
			isEnable = false;
			vy = -0.2;
			timefiring = 0;
		}
	}
	if (isEnable == false)
		IsFiring = false;
}

void FireBomb::Render()
{

	if (IsFiring == true) {
		animation_set->at(2)->Render(x, y - 5);
	}
	else {
		Weapon::Render();
	}

}

void FireBomb::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + 8;
	bottom = y + 8;
}

FireBomb::FireBomb()
{
	useHeart = 1;
	damage = 2;
	vy = -0.2;
	SetAnimationSet(6);
}

FireBomb::~FireBomb()
{
}
