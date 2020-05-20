#pragma once
#include "../Framework/Effect.h"
class MoneyEffect : public Effect
{
	int moneyType;
public:
	void Render();
	void Update(DWORD dt);
	void Enable();
	MoneyEffect(int _moneyType);
	~MoneyEffect();
};
