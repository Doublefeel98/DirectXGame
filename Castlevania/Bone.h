#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"
#include "Simon.h"
#include "Enemy.h"
class Bone : public Enemy
{
private:
	int damage;
	int isBreak;
	Simon* simon;
	vector<LPGAMEOBJECT> objects;
public:
	Bone();
	~Bone();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void SetState(int state);
};
