#pragma once
#include "../Framework/GameObject.h"
#define CANDLE_BBOX_WIDTH  16
#define CANDLE_BBOX_HEIGHT 32
class Candle :public CGameObject
{
public:
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	Candle();
	~Candle();
};