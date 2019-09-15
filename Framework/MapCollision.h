#pragma once
#include "GameObject.h"

#define ID_TEX_TRANSPARENT	-200
class MapCollision : public CGameObject
{
	CSprite *sprite;
public:
	MapCollision();
	void Render(Camera* camera);
	void GetBoundingBox(float &l, float &t, float &r, float &b);
	MapCollision(int width, int height);
	~MapCollision();
};

