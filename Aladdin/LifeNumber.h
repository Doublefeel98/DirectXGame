#pragma once
#include "../Framework/GameObject.h"

class LifeNumber : public CGameObject
{
	wstring lifeNumber;
public:
	void Render();
	void Update(wstring lifeNumber);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	LifeNumber();
};