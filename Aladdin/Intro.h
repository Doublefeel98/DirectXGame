#pragma once
#include "../Framework/GameObject.h"

class Intro : public CGameObject
{
	int intro;
public:
	void Render();
	void Update(int hp);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	Intro();
};