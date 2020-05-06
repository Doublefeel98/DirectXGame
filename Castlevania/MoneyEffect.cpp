#include "MoneyEffect.h"

void MoneyEffect::Render()
{
	if (isEnable)
		animations[moneyType]->Render(x, y);
}

void MoneyEffect::Update(DWORD dt)
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

MoneyEffect::MoneyEffect(int _moneyType)
{
	moneyType = _moneyType;

	AddAnimation(500);
	timeDelay = 0.0f;
	isEnable = false;
}

MoneyEffect::~MoneyEffect()
{

}
