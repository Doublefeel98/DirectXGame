#pragma once
#include "../Framework/GameObject.h"
#define BRICK_BBOX_WIDTH  32
#define BRICK_BBOX_HEIGHT 32
class Brick : public CGameObject
{
	CSprite* sprite;
public:
	void Render( );
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	Brick();
};

