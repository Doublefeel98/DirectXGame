#pragma once
#include "../Framework/GameObject.h"
#include "Item.h"
#include "Enemy.h"
class Weapon : public CGameObject
{
protected:
	int useHeart;
	int damage;
	int count;
	void _handleLogicCollisionEnemy(Enemy* enemy);
	virtual void _checkAABB(vector<LPGAMEOBJECT>* coObjects);
	virtual void _checkSweptAABB(vector<LPGAMEOBJECT>* coObjects);
public:
	Weapon();
	~Weapon();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void ResetAnimation();
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	int GetUseHeart() { return useHeart; }
	int GetDamage() { return damage; }
	void SetDamage(int damage) { this->damage = damage; }
};
