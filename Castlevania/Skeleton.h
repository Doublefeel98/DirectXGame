#pragma once
#include "Enemy.h"
#include "Bone.h"
#include <vector>
class Skeleton : public Enemy
{
	float startX, startY;
	DWORD timeAttack;
	vector<Bone*> bones;
public:
	Skeleton();
	virtual void FromVector(vector<string> tokens);
	~Skeleton();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};
