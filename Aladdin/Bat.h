#pragma once
#include "../Framework/Enemy.h"
#include "Define.h"
#include"Aladdin.h"
#define LEFT false
#define RIGHT true
class Bat : public CEnemy
{
private:
	bool wait, fly, swing, die;	// indicate which state a bat object is currently in
	int x_start, y_start; bool reverse = false, init = true;
	int lastActive;
	int direction;
	bool finalAni;
public:
	Bat();
	~Bat();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};