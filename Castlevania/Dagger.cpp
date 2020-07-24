#include "Dagger.h"
#include "../Framework/Ground.h"
#include "../Framework/BoundingMap.h"
#include "Enemy.h"

void Dagger::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	Weapon::Update(dt, coObjects);
}

void Dagger::Render()
{
	Weapon::Render();
}

void Dagger::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (nx > 0)
	{
		left = x;
		top = y;
		right = x + 16;
		bottom = y + 9;
	}
	else
	{
		left = x - 16;
		top = y;
		right = left + 16;
		bottom = y + 9;
	}
}

Dagger::Dagger()
{
	SetAnimationSet(3);
	useHeart = 1;
	damage = 1;
}

Dagger::~Dagger()
{
}
