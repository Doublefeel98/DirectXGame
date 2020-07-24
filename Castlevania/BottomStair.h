#pragma once
#include "../Framework/GameObject.h"
class BottomStair : public CGameObject
{
public:
	BottomStair();
	virtual void FromVector(vector<string> tokens);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	~BottomStair();
};
