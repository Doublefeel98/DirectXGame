#include "Enemy.h"


CEnemy::CEnemy() : CGameObject()
{
	isEnable = true;
	isDead = false;
}

CEnemy::CEnemy(int hp) : CGameObject()
{
	this->hp = hp;
	isEnable = true;
	isDead = false;
}

CEnemy::~CEnemy()
{
}

void CEnemy::SetHP(int _hp) {
	this->hp = _hp;
	if (hp <= 0)
	{
		isDead = true;
		isEnable = false;
	}
}

void CEnemy::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	;
	if (!isDead)
	{
		if (isEnable == true)
		{
			if (hp <= 0)
			{
				isDead = true;
				isEnable = false;
				return;
			}
		}

	}
}

void CEnemy::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}
