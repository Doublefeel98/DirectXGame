#pragma once
#include "../Framework/GameObject.h"
#include <string>
class Score : public CGameObject
{
	wstring score;
public:
	virtual void Render();
	void Update(wstring score);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	Score();
};

