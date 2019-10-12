#include "DeadEffect.h"



void DeadEffect::Render()
{
	if (isEnable)
		animation[0]->Render(x, y);
}

void DeadEffect::Render(D3DXVECTOR3 &pos)
{
	if (isEnable)
		animation[0]->Render(pos.x,pos.y);
}

void DeadEffect::Update(DWORD dt)
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

DeadEffect::DeadEffect()
{
	animation.push_back(CAnimations::GetInstance()->Get(28001));
	timeDelay = 0.0f;
	isEnable = false;
}


DeadEffect::~DeadEffect()
{
}
