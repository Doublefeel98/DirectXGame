#pragma once
#include "../Framework/Enemy.h"
#include "CollisionEffect.h"
#include "DeadEffect.h"
class Enemy : public CEnemy
{
protected:
	CollisionEffect* collisionEffect;
	DeadEffect* deadEffect;
	bool isGrounded;

public:
	static void StartTimeStop() { timestop_start = GetTickCount(); }
	static DWORD timestop_start;
	static bool IsStop;
	Enemy();
	CollisionEffect* GetCollisionEffect() { return collisionEffect; }
	DeadEffect* GetDeadEffect() { return deadEffect; }
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};

