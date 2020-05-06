#include "CollisionEffect.h"

void CollisionEffect::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void CollisionEffect::Render()
{
	if (isEnable)
		animations[0]->Render(x, y);
}

void CollisionEffect::Update(DWORD dt)
{
	if (isEnable)
	{
		timeDelay += dt;
		if (timeDelay > 450)
		{
			timeDelay = 0.0f;
			isEnable = false;
		}
	}
}

CollisionEffect::CollisionEffect()
{
	AddAnimation(501);
	timeDelay = 0.0f;
	isEnable = false;
}

CollisionEffect::~CollisionEffect()
{
}
