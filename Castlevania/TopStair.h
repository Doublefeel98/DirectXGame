#pragma once
#include "../Framework/GameObject.h"
class TopStair : public CGameObject
{
public:
	TopStair();
	virtual void FromVector(vector<string> tokens);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	~TopStair();
};
