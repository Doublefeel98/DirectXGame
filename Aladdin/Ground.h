#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

class Ground : public CGameObject
{
public:
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
};

