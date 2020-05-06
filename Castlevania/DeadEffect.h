#pragma once
#include "../Framework/Effect.h"

class DeadEffect : public Effect
{
public:
	void SetPosition(float x, float y);
	void Render();
	void Render(float posX, float posY);
	void Update(DWORD dt);
	DeadEffect();
	~DeadEffect();
};

