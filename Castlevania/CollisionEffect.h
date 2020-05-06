#pragma once
#include "../Framework/Effect.h"
class CollisionEffect : public Effect
{
public:
	void SetPosition(float x, float y);
	void Render();
	void Update(DWORD dt);
	CollisionEffect();
	~CollisionEffect();
};

