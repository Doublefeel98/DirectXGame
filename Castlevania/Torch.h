#pragma once
#include "../Framework/GameObject.h"
#include "CollisionEffect.h"
#include "DeadEffect.h"
class Torch : public CGameObject
{
	CollisionEffect* collisionEffect;
	DeadEffect* deadEffect;
public:
	Torch();
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	CollisionEffect* GetCollisionEffect() { return collisionEffect; }
	DeadEffect* GetDeadEffect() { return deadEffect; }
};

