#pragma once
#include "../Framework/Enemy.h"
#include "Define.h"

class Bat : public CEnemy
{
private:
	bool wait, fly, rotate, die;	// indicate which state a bat object is currently in
public:
	Bat();
	~Bat();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	
};