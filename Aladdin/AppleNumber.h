#pragma once
#include "../Framework/GameObject.h"

class AppleNumber : public CGameObject
{
	wstring appleNumber;
public:
	void Render();
	void Update(wstring appleNumber);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	AppleNumber();
};

