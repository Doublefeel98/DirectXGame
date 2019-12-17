#pragma once
#include "../Framework/GameObject.h"

class PennyNumber : public CGameObject
{
	wstring pennyNumber;
public:
	void Render();
	void Update(wstring pennyNumber);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	PennyNumber();
};

