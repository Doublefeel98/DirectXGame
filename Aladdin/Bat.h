#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

class Bat : public CGameObject
{
private:
	bool wait, fly, rotate, die;	// indicate which state a bat object is currently in
	int HP;
public:
	Bat();
	~Bat();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};