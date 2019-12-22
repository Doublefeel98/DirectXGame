#pragma once
#include "../Framework/GameObject.h"

class Exit : public CGameObject
{
public:
	Exit();
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

