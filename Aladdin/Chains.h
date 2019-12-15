#pragma once
#include "../Framework/GameObject.h"

class Chains : public CGameObject 
{
public:
	Chains();
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt);
};

