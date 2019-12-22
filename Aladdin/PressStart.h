#pragma once
#include "../Framework/GameObject.h"

class PressStart : public CGameObject
{
	wstring pressStart;
public:
	void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	PressStart();
};