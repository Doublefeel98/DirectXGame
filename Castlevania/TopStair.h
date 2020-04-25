#pragma once
#include "../Framework/GameObject.h"
class TopStair : public CGameObject
{
public:
	TopStair(int _nx);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	~TopStair();
};

