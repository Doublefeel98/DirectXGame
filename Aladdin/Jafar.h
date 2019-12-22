#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"
#include "../Framework/Enemy.h"
#include "SnakeFire.h"
#include "Star.h"
class Jafar : public CEnemy
{
private:
	vector <SnakeFire*> snakeFires;
	vector <Star*> stars;
	DWORD timeAtack;
	bool canAbleAtackFire;
	bool canAbleAtackStar;
	bool isExplosion;
public:
	Jafar();
	~Jafar();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};
