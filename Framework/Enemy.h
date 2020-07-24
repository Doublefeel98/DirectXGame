#pragma once
#include "GameObject.h"

#define E_INVINCIBLE_TIME 0.4
class CEnemy;
typedef CEnemy* LPENEMY;
class CEnemy :public CGameObject
{
protected:
	int hp;
	int damage;
	int point;
public:
	CEnemy();
	CEnemy(int hp);
	~CEnemy();
	virtual void Render() = 0;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	int GetHP() { return this->hp; }
	void SetHP(int hp) { this->hp = hp; }
	int GetDamage() { return this->damage; }
	void SetDamage(int damage) { this->damage = damage; }
	int GetPoint() { return point; }
};
