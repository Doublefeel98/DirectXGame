#pragma once
#include "../Framework/GameObject.h"

class PennyCount : public CGameObject
{
	int pennyCount;
public:
	void Render();
	void Update(int hp);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	PennyCount(int pennyCount);
};

