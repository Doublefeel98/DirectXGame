#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"
#include "Aladdin.h"
class Bone : public CGameObject
{
private:
	int damage;
	int isBreak;
	DWORD timeStartFly;
	float velocityRamdomX;
	float velocityRamdomY;
	Aladdin* aladdin;
	vector<LPGAMEOBJECT> objects;
public:
	Bone();
	~Bone();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void SetState(int state);
};

