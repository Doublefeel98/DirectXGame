#pragma once
#include "../Framework/GameObject.h"
class MovingPlatform : public CGameObject
{
	float startX, startY;
public:
	MovingPlatform();
	virtual void FromVector(vector<string> tokens);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	~MovingPlatform();
};

