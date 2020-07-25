#include "Enemy.h"
#include "Simon.h"

DWORD Enemy::timestop_start = 0;
bool Enemy::IsStop = false;

Enemy::Enemy()
{
	collisionEffect = new CollisionEffect();
	deadEffect = new DeadEffect();
	isEnable = true;
	isDead = false;
	is_boss = false;
}

void Enemy::Hurted(int damage)
{
	SetHP(this->hp - damage);
	if (isDead) {
		Simon::GetInstance()->AddScore(this->point);
	}
}

void Enemy::Render()
{
	collisionEffect->Render();
	deadEffect->Render();
}

void Enemy::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (IsStop)
	{
		dx = 0;
		dy = 0;
	}
	else {
		CGameObject::Update(dt, coObjects);
	}
	if (!isDead)
	{
		if (isEnable)
		{
			if (hp <= 0)
			{
				isDead = true;
				isEnable = false;
				GetDeadEffect()->SetEnable(true);
				Simon::GetInstance()->AddScore(point);
				return;
			}

			collisionEffect->SetPosition(x, y + 10);
			deadEffect->SetPosition(x + 3, y - 3);
		}
	}

	collisionEffect->Update(dt);
	deadEffect->Update(dt);
}

void Enemy::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}
