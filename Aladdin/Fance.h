#pragma once
#include "../Framework/GameObject.h"

class Fance : public CGameObject
{
public:
	Fance();
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

