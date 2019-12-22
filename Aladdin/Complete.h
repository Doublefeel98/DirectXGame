#pragma once
#include "../Framework/GameObject.h"

class Complete : public CGameObject
{
	int complete;
public:
	void Render();
	void Update(int hp);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	Complete();
};
