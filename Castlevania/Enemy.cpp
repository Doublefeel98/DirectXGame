#include "Enemy.h"
#include "Simon.h"

Enemy::Enemy()
{
	collisionEffect = new CollisionEffect();
	deadEffect = new DeadEffect();
	isEnable = true;
	isDead = false;
}

void Enemy::Render()
{
	collisionEffect->Render();
	deadEffect->Render();
}

void Enemy::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!IsStop)
		CGameObject::Update(dt, coObjects);
	if (!isDead)
	{
		if (isEnable)
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
				Simon::GetInstance()->AddScore(point);
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
			collisionEffect->SetPosition(x, y + 10);
			deadEffect->SetPosition(x + 3, y - 3);
		}

	}
	if (!isEnable)
		respawnTime += dt;

	collisionEffect->Update(dt);
	deadEffect->Update(dt);
}

void Enemy::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}
