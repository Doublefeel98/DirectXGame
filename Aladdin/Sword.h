#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"
class Sword : public CGameObject
{
private:
	int damage;
	bool isFighting;
public:
	Sword();
	~Sword();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void SetFighting(bool isFighting) { this->isFighting = isFighting; }
	bool IsFighting() { return this->isFighting; }
	void SetState(int state);
};

