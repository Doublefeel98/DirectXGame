#pragma once
#include "../Framework/Effect.h"
class HP : public Effect
{
	int type;
	CSprite* sprite;
public:
	void Render();
	HP(int type);
	~HP();
};

