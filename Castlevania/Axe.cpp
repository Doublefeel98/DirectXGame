#include "Axe.h"
#include "../Framework/Ground.h"
#include "../Framework/BoundingMap.h"
#include "Enemy.h"

void Axe::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	Weapon::Update(dt, coObjects);
	if (isEnable)
		vy += 0.0007 * dt;
}

void Axe::Render()
{
	Weapon::Render();
}

void Axe::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + 15;
	bottom = y + 14;
}

Axe::Axe()
{
	SetAnimationSet(5);
	useHeart = 1;
	damage = 2;
	vy = -0.25;
}

Axe::~Axe()
{
}
