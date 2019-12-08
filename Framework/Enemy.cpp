#include "Enemy.h"

int CEnemy::score = 0;
float CEnemy::stopTime = 0;
int CEnemy::timestop = 0;
DWORD CEnemy::timestop_start = 0;
bool CEnemy::IsStop = false;
void CEnemy::AddScore()
{
	CEnemy::score += point;
}

int CEnemy::GetScore()
{
	return score;
}


CEnemy::CEnemy() : CGameObject()
{
	isEnable = true;
	isDead = false;
}
CEnemy::CEnemy(int hp) : CGameObject()
{
	this->hp = hp;
	this->respawnTime = 1000;
	hpC = hp;
	e_prevHP = hp;
	isEnable = true;
	isDead = false;
}

CEnemy::~CEnemy()
{
}


void CEnemy::Render()
{
	CGameObject::Render();
}

void CEnemy::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!IsStop)
		CGameObject::Update(dt, coObjects);
	if (!isDead)
	{
		if (isEnable == true)
		{
			respawnTime = 0;
			if (hp < e_prevHP) {
				e_prevHP = hp;
			}

			if (hp <= 0)
			{
				isDead = true;
				isEnable = false;
				GetDeadEffect()->SetEnable(true);
				AddScore();
				return;
			}
			if (IsStop == true) {

				if (GetTickCount() - timestop_start > 5000)
				{
					IsStop = false;
					timestop = 0;
					timestop_start = 0;
				}
			}
		}

	}
	if (!isEnable)
		respawnTime += dt;
}

void CEnemy::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}


void CEnemy::Reload()
{
	isEnable = false;
	isDead = true;
	hp = hpC;
	e_prevHP = hp;
}

void CEnemy::Respawn()
{
	isEnable = true;
	isDead = false;
	hp = hpC;
	e_prevHP = hp;
}

void CEnemy::SetScore(int score)
{
	CEnemy::score += score;
}



