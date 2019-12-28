#include "Jafar.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "Define.h"
#include "Aladdin.h"


void Jafar::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	if (!isDead) {
		DWORD now = GetTickCount();
		CEnemy::Update(dt, coObject);
		D3DXVECTOR3 alaPosition = Aladdin::GetInstance()->GetPosition();

		nx = this->x >= alaPosition.x ? -1 : 1;

		for (int i = 0; i < snakeFires.size(); i++)
		{
			snakeFires.at(i)->Update(dt, coObject);
		}

		for (int i = 0; i < stars.size(); i++)
		{
			stars.at(i)->Update(dt, coObject);
		}

		if (this->hp > JAFAR_HP - 10)
		{
			SetState(JAFAR_STATE_ATTACK);
		}
		else {
			if (!isExplosion)
			{
				isExplosion = true;
			}
			SetState(JAFAR_STATE_SNAKE);
		}

		if (state == JAFAR_STATE_ATTACK)
		{
			if ((animations[2]->currentFrame > 3 && animations[2]->currentFrame < 6) || (animations[3]->currentFrame > 3 && animations[3]->currentFrame < 6))
			{
				if (now - timeAtack >= 150)
				{
					Star* star = new Star();

					if (nx > 0)
					{
						star->SetState(FIRE_SNAKE_STATE_RIGHT);
						star->SetPosition(x + JAFAR_BBOX_WIDTH / 2, y + JAFAR_BBOX_HEIGHT - JAFAR_SNAKE_BBOX_HEIGHT);
					}
					else
					{
						star->SetState(FIRE_SNAKE_STATE_LEFT);
						star->SetPosition(x - JAFAR_SNAKE_BBOX_WIDTH, y + JAFAR_BBOX_HEIGHT - JAFAR_SNAKE_BBOX_HEIGHT);
					}
					stars.push_back(star);

					timeAtack = now;
				}
			}
			else {
				Aladdin::GetInstance()->vx = 0;
				timeAtack = now;
				canAbleAtackStar = true;
			}
		}
		else if (state == JAFAR_STATE_SNAKE)
		{
			if (animations[4]->currentFrame >= 9 || animations[5]->currentFrame >= 9)
			{
				if (canAbleAtackFire)
				{
					SnakeFire* snakeFire = new SnakeFire();

					if (nx > 0)
					{
						snakeFire->SetState(FIRE_SNAKE_STATE_RIGHT);
						snakeFire->SetPosition(x, y + JAFAR_SNAKE_BBOX_HEIGHT - FIRE_SNAKE_BBOX_HEIGHT);

					}
					else
					{
						snakeFire->SetState(FIRE_SNAKE_STATE_LEFT);
						snakeFire->SetPosition(x, y + JAFAR_SNAKE_BBOX_HEIGHT - FIRE_SNAKE_BBOX_HEIGHT);

					}
					snakeFires.push_back(snakeFire);


					canAbleAtackFire = false;
				}

			}
			else {
				canAbleAtackFire = true;
			}
		}
	}
}

void Jafar::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = left + JAFAR_BBOX_WIDTH;
	bottom = top + JAFAR_BBOX_HEIGHT;
}

void Jafar::SetState(int stateNew)
{
	if (state != stateNew)
	{
		ResetAllAnimation();
		timeAtack = GetTickCount();
	}
	CEnemy::SetState(stateNew);
	switch (stateNew)
	{
	case JAFAR_STATE_IDLE:
		vx = 0;
		vy = 0;
		break;
	case JAFAR_STATE_ATTACK:
		vx = 0;
		vy = 0;
		if (nx > 0)
		{
			vx = GUARD_WALKING_SPEED;
		}
		else {
			vx = -GUARD_WALKING_SPEED;
		}
		break;
	case JAFAR_STATE_SNAKE:
		vx = 0;
		vy = 0;
		break;
	default:
		break;
	}
}

void Jafar::Render()
{
	if (isEnable && !isDead)
	{
		int ani = 0;
		int posX = x, posY = y;
		switch (state)
		{
		case JAFAR_STATE_IDLE:
			if (nx > 0)
			{
				ani = JAFAR_ANI_IDLE_RIGHT;
			}
			else {
				ani = JAFAR_ANI_IDLE_LEFT;
			}
			break;
		case JAFAR_STATE_ATTACK:
			posX = x + 15;
			if (nx > 0)
			{
				ani = JAFAR_ANI_ATTACK_RIGHT;
			}
			else {
				ani = JAFAR_ANI_ATTACK_LEFT;
			}
			break;
		case JAFAR_STATE_SNAKE:
			posX = x + 15;
			if (nx > 0)
			{
				ani = JAFAR_ANI_SNAKE_RIGHT;
			}
			else {
				ani = JAFAR_ANI_SNAKE_LEFT;
			}
			break;
		default:
			break;
		}

		if (state == JAFAR_STATE_SNAKE)
		{
			animations[animations.size() - 2]->Render(x, y + JAFAR_SNAKE_BBOX_HEIGHT - FIRE_BBOX_HEIGHT);
			animations[animations.size() - 2]->Render(x + 20, y + JAFAR_SNAKE_BBOX_HEIGHT - FIRE_BBOX_HEIGHT);
			animations[animations.size() - 2]->Render(x + 20 * 2, y + JAFAR_SNAKE_BBOX_HEIGHT - FIRE_BBOX_HEIGHT);
		}

		animations[ani]->Render(posX, posY);
		RenderBoundingBox();

		for (int i = 0; i < snakeFires.size(); i++)
		{
			snakeFires.at(i)->Render();
		}

		for (int i = 0; i < stars.size(); i++)
		{
			stars.at(i)->Render();
		}

		if (isExplosion && !animations[animations.size() - 1]->IsLastFrame)
		{
			animations[animations.size() - 1]->Render(x + JAFAR_BBOX_WIDTH / 2, y + JAFAR_BBOX_HEIGHT / 2);
		}
	}
}

Jafar::Jafar() : CEnemy()
{
	width = JAFAR_BBOX_WIDTH;
	height = JAFAR_BBOX_HEIGHT;

	timeAtack = 0;

	hp = JAFAR_HP;

	canAbleAtackFire = true;
	canAbleAtackStar = true;
	isExplosion = false;

	AddAnimation(700);		// idle right
	AddAnimation(701);		// idle left

	AddAnimation(702);		// attack right
	AddAnimation(703);		// attack left

	AddAnimation(800);		// snake right
	AddAnimation(801);		// snake left

	AddAnimation(900);

	AddAnimation(5001);

	animations[animations.size() - 2]->IsLoop = true;
}

Jafar::~Jafar()
{

}