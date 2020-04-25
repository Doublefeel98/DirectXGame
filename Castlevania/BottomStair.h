#pragma once
#include "../Framework/GameObject.h"
class BottomStair : public CGameObject
{
public:
	BottomStair(int _nx);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	~BottomStair();
};

