#pragma once
#include "../Framework/GameObject.h"
#define TORCH_BBOX_WIDTH  32
#define TORCH_BBOX_HEIGHT 64

class Torch :public CGameObject
{
public:
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	Torch();
	~Torch();
};


