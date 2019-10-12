#pragma once
#include "GameObject.h"

#define BRICK_BBOX_WIDTH  500
#define BRICK_BBOX_HEIGHT 1

class CBrick : public CGameObject
{
public:
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};