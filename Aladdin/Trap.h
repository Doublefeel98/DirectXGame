#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

class Trap :public CGameObject {
private:
	int damage;
public:
	Trap();
	~Trap();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	void SetDamage(int damage) { this->damage = damage; }
	int GetDamage() { return damage; }
};