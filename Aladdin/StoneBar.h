#pragma once
#include "../Framework/GameObject.h"
class StoneBar : public CGameObject
{
public:
	StoneBar();
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt);
};

