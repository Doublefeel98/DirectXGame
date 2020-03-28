#include "Whip.h"
#include "Define.h"
#include "Torch.h"
#include "Item.h"
#include "../Framework/Game.h"
#include "../Framework/debug.h"

void Whip::Render(bool IsRight, bool IsJump)
{
	if (isEnable == true)
	{
		if (level == WHIP_LEVEL_1)
		{
			if (IsRight)
			{
				indexAni = WHIP_LEVEL_1_ANI_RIGHT;
			}
			else
			{
				indexAni = WHIP_LEVEL_1_ANI_LEFT;
			}
		}
		else if (level == WHIP_LEVEL_2)
		{
			if (IsRight)
			{
				indexAni = WHIP_LEVEL_2_ANI_RIGHT;
			}
			else
			{
				indexAni = WHIP_LEVEL_2_ANI_LEFT;
			}
		}
		else if (level == WHIP_LEVEL_3)
		{
			if (IsRight)
			{
				indexAni = WHIP_LEVEL_3_ANI_RIGHT;
			}
			else
			{
				indexAni = WHIP_LEVEL_3_ANI_LEFT;
			}
		}

		animations[indexAni]->Render(x, y);
		//RenderBoundingBox();
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
	CGameObject::Update(dt);

	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Item*>(coObjects->at(i))) {
			Item* item = dynamic_cast<Item*>(coObjects->at(i));

			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			item->GetBoundingBox(l2, t2, r2, b2);

			if (CGame::isColliding(l1, t1, r1, b1, l2, t2, r2, b2))
			{
				if (!item->IsDead() && !item->IsEnable()) {
					item->SetEnable(true);
				}
			}
		}

		if (dynamic_cast<Torch*>(coObjects->at(i))) {
			Torch* torch = dynamic_cast<Torch*>(coObjects->at(i));

			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			torch->GetBoundingBox(l2, t2, r2, b2);

			if (CGame::isColliding(l1, t1, r1, b1, l2, t2, r2, b2))
			{
				if (torch->isEnable) {
					torch->GetCollisionEffect()->SetEnable(true);
					torch->GetDeadEffect()->SetEnable(true);
					torch->isEnable = false;
					torch->isDead = true;
				}
			}
		}
	}
}

void Whip::ResetAnimation()
{
	resetAni(0);
	resetAni(1);
	resetAni(2);
	resetAni(3);
	resetAni(4);
	resetAni(5);
}

int Whip::GetCurrentFrame()
{
	ani = animations[indexAni];
	return ani->getCurrentFrame();
}

void Whip::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	switch (indexAni)
	{
	case WHIP_LEVEL_1_ANI_LEFT:
		left = x - 12 - WHIP_LEVEL_1_BBOX_WIDTH;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_1_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_1_BBOX_HEIGHT;
		break;
	case WHIP_LEVEL_1_ANI_RIGHT:
		left = x + SIMON_BBOX_WIDTH + 11;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_1_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_1_BBOX_HEIGHT;
		break;
	case WHIP_LEVEL_2_ANI_LEFT:
		left = x - 12 - WHIP_LEVEL_2_BBOX_WIDTH;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_2_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_2_BBOX_HEIGHT;
		break;
	case WHIP_LEVEL_2_ANI_RIGHT:
		left = x + SIMON_BBOX_WIDTH + 11;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_2_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_2_BBOX_HEIGHT;
		break;
	case WHIP_LEVEL_3_ANI_LEFT:
		left = x - 12 - WHIP_LEVEL_3_BBOX_WIDTH;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_3_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_3_BBOX_HEIGHT;
		break;
	case WHIP_LEVEL_3_ANI_RIGHT:
		left = x + SIMON_BBOX_WIDTH + 11;
		top = y + WHIP_DELTA_POSITION_BOX_HEIGHT;
		right = left + WHIP_LEVEL_3_BBOX_WIDTH;
		bottom = top + WHIP_LEVEL_3_BBOX_HEIGHT;
		break;
	default:
		break;
	}
}

Whip::Whip()
{
	AddAnimation(300);
	AddAnimation(301);
	AddAnimation(302);
	AddAnimation(303);
	AddAnimation(304);
	AddAnimation(305);

	damage = 1;
	level = WHIP_LEVEL_1;
	indexAni = 0;
}

Whip::~Whip()
{
}
