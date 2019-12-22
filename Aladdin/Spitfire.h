#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"
#include "Aladdin.h"
#include "Fire.h"
class Spitfire : public CGameObject
{
	Aladdin* aladdin;
	Fire* fires[3];
public:
	bool isEnableFire;
	Spitfire();
	~Spitfire();
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects);
};

