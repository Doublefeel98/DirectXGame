#include "ColliderEffect.h"



void ColliderEffect::Render()
{
	if (isEnable)
		animation[0]->Render(x, y);
}

void ColliderEffect::Update(DWORD dt)
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

ColliderEffect::ColliderEffect()
{

	animation.push_back(CAnimations::GetInstance()->Get(26001));
	timeDelay = 0.0f;
	isEnable = false;
}


ColliderEffect::~ColliderEffect()
{
}
