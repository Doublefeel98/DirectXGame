#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"
#include "../Framework/Enemy.h"

class Jafar : public CEnemy
{
private:

public:
	Jafar();
	~Jafar();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};
