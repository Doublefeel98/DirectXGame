#pragma once
#include "GameObject.h"

class MapCollision : public CGameObject
{
	CSprite* sprite;
public:
	MapCollision();
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	MapCollision(int width, int height);
	~MapCollision();
};

