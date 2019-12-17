#pragma once
#include "../Framework/GameObject.h"

class AppleCount : public CGameObject
{
	int appleCount;
public:
	void Render();
	void Update(int hp);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	AppleCount(int appleCount);
};

