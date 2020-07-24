#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
	float startX, startY;
	int direction;
public:
	Zombie();
	virtual void FromVector(vector<string> tokens);
	~Zombie();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};
