#pragma once
#include "../Framework/GameObject.h"
class Wood : public CGameObject
{
public:
	Wood();
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt);
};

