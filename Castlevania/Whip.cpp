#include "Whip.h"
#include "Define.h"
#include "Torch.h"
#include "Candle.h"
#include "Item.h"
#include "../Framework/Game.h"
#include "../Framework/Utils.h"
#include "Enemy.h"


void Whip::Render()
{
}

void Whip::Render(bool IsRight)
{
	if (isEnable == true)
	{
		float posX = x, posY = y;
		if (level == WHIP_LEVEL_1)
		{
			if (IsRight)
			{
				if (state == WHIP_STATE_PREPARE)
				{
					indexAni = WHIP_LEVEL_1_ANI_PREPARE_RIGHT;
				}
				else {
					indexAni = WHIP_LEVEL_1_ANI_RIGHT;
				}
			}
			else
			{
				if (state == WHIP_STATE_PREPARE)
				{
					indexAni = WHIP_LEVEL_1_ANI_PREPARE_LEFT;
				}
				else {
					indexAni = WHIP_LEVEL_1_ANI_LEFT;
				}
			}
		}
		else if (level == WHIP_LEVEL_2)
		{
			if (IsRight)
			{
				if (state == WHIP_STATE_PREPARE)
				{
					indexAni = WHIP_LEVEL_2_ANI_PREPARE_RIGHT;
				}
				else {
					indexAni = WHIP_LEVEL_2_ANI_RIGHT;
				}
			}
			else
			{
				if (state == WHIP_STATE_PREPARE)
				{
					indexAni = WHIP_LEVEL_2_ANI_PREPARE_LEFT;
				}
				else {
					indexAni = WHIP_LEVEL_2_ANI_LEFT;
				}
			}
		}
		else if (level == WHIP_LEVEL_3)
		{
			if (IsRight)
			{
				if (state == WHIP_STATE_PREPARE)
				{
					indexAni = WHIP_LEVEL_3_ANI_PREPARE_RIGHT;
				}
				else {
					indexAni = WHIP_LEVEL_3_ANI_RIGHT;
				}
			}
			else
			{
				if (state == WHIP_STATE_PREPARE)
				{
					indexAni = WHIP_LEVEL_3_ANI_PREPARE_LEFT;
				}
				else {
					indexAni = WHIP_LEVEL_3_ANI_LEFT;
				}
			}
		}

		if (state != WHIP_STATE_PREPARE)
		{
			if (IsRight)
			{
				posX = x + SIMON_BBOX_WIDTH + WHIP_DELTA_X_RIGHT;
			}
			else {
				if (level == WHIP_LEVEL_1)
				{
					posX = x - WHIP_DELTA_X_LEFT - WHIP_LEVEL_1_BBOX_WIDTH;
				}
				else if (level == WHIP_LEVEL_2)
				{
					posX = x - WHIP_DELTA_X_LEFT - WHIP_LEVEL_2_BBOX_WIDTH;
				}
				else {
					posX = x - WHIP_DELTA_X_LEFT - WHIP_LEVEL_3_BBOX_WIDTH;
				}

			}
			if (level == WHIP_LEVEL_1)
			{
				posY = y + WHIP_DELTA_POSITION_BOX_HEIGHT - 2;
			}
			else if (level == WHIP_LEVEL_2)
			{
				posY = y + WHIP_DELTA_POSITION_BOX_HEIGHT - 1;
			}
			else {
				posY = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
			}

		}
		else {
			if (IsRight)
			{
				posX = x - SIMON_BBOX_WIDTH;
			}
			else {
				posX = x + SIMON_BBOX_WIDTH;
			}
		}

		animation_set->at(indexAni)->Render(posX, posY);
		if (state == WHIP_STATE_HIT)
		{
			RenderBoundingBox();
		}
	}
}

void Whip::SetPosition(float x, float y, bool Issit)
{
	if (Issit)
	{
		y += WHIP_DELTA_POSITION_Y;
	}
	CGameObject::SetPosition(x, y);
}

void Whip::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (state == WHIP_STATE_HIT && isEnable)
	{
		CGameObject::Update(dt);

		for (UINT i = 0; i < coObjects->size(); i++)
		{
			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			coObjects->at(i)->GetBoundingBox(l2, t2, r2, b2);

			if (CGame::IsColliding(l1, t1, r1, b1, l2, t2, r2, b2))
			{
				if (dynamic_cast<Enemy*>(coObjects->at(i))) {

					Enemy* enemy = dynamic_cast<Enemy*>(coObjects->at(i));

					if ((coObjects->at(i))->nx != 0)
					{
						if (enemy->isEnable != false) {
							enemy->GetCollisionEffect()->SetEnable(true);
							enemy->SetHP(enemy->GetHP() - this->damage);
							this->isEnable = false;
							ResetAnimation();
						}
					}

				}
				else if (dynamic_cast<Torch*>(coObjects->at(i))) {
					Torch* torch = dynamic_cast<Torch*>(coObjects->at(i));

					if (torch->isEnable) {
						torch->GetCollisionEffect()->SetEnable(true);
						torch->GetDeadEffect()->SetEnable(true);
						torch->isEnable = false;
						torch->isDead = true;
					}
				}
				else if (dynamic_cast<Candle*>(coObjects->at(i))) {
					Candle* candle = dynamic_cast<Candle*>(coObjects->at(i));

					if (candle->isEnable) {
						candle->GetCollisionEffect()->SetEnable(true);
						candle->GetDeadEffect()->SetEnable(true);
						candle->isEnable = false;
						candle->isDead = true;
					}
				}
			}
		}
	}
}

void Whip::ResetAnimation()
{
	ResetAni(0);
	ResetAni(1);
	ResetAni(2);
	ResetAni(3);
	ResetAni(4);
	ResetAni(5);
	ResetAni(6);
	ResetAni(7);
	ResetAni(8);
	ResetAni(9);
	ResetAni(10);
	ResetAni(11);
}

int Whip::GetCurrentFrame()
{
	ani = animation_set->at(indexAni);
	return ani->GetCurrentFrame();
}

void Whip::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	switch (indexAni)
	{
	case WHIP_LEVEL_1_ANI_LEFT:
		left = x - WHIP_DELTA_X_LEFT - WHIP_LEVEL_1_BBOX_WIDTH;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_1_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_1_BBOX_HEIGHT;
		break;
	case WHIP_LEVEL_1_ANI_RIGHT:
		left = x + SIMON_BBOX_WIDTH + WHIP_DELTA_X_RIGHT;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_1_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_1_BBOX_HEIGHT;
		break;
	case WHIP_LEVEL_2_ANI_LEFT:
		left = x - WHIP_DELTA_X_LEFT - WHIP_LEVEL_2_BBOX_WIDTH;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_2_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_2_BBOX_HEIGHT;
		break;
	case WHIP_LEVEL_2_ANI_RIGHT:
		left = x + SIMON_BBOX_WIDTH + WHIP_DELTA_X_RIGHT;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_2_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_2_BBOX_HEIGHT;
		break;
	case WHIP_LEVEL_3_ANI_LEFT:
		left = x - WHIP_DELTA_X_LEFT - WHIP_LEVEL_3_BBOX_WIDTH;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_3_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_3_BBOX_HEIGHT;
		break;
	case WHIP_LEVEL_3_ANI_RIGHT:
		left = x + SIMON_BBOX_WIDTH + WHIP_DELTA_X_RIGHT;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_3_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_3_BBOX_HEIGHT;
		break;
	default:
		break;
	}
}

void Whip::SetLevel(int level)
{
	this->level = level;
	switch (level)
	{
	case WHIP_LEVEL_1:
		damage = WHIP_DAMAGE;
		break;
	case WHIP_LEVEL_2:
	case WHIP_LEVEL_3:
		damage = WHIP_DAMAGE * 1.5;
		break;
	default:
		break;
	}
}

Whip::Whip()
{
	damage = WHIP_DAMAGE;
	level = WHIP_LEVEL_1;
	indexAni = 0;
}

Whip::~Whip()
{
}
