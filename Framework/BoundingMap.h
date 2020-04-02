#pragma once
#include "GameObject.h"

class BoundingMap : public CGameObject
{
	CSprite* sprite;
public:
	BoundingMap();
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	BoundingMap(int width, int height);
	~BoundingMap();
};

