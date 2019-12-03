#pragma once
#include "../Framework/GameObject.h"
class Pilar : public CGameObject
{
public:
	Pilar();
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

