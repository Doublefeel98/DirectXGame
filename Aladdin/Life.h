#pragma once
#include "../Framework/GameObject.h"

class Life : public CGameObject
{
	int life;
public:
	void Render();
	void Update(int hp);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	Life(int life);
};