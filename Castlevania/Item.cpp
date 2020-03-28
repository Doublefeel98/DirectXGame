#include "Item.h"
#include "Define.h"
#include <time.h>
#include "Brick.h"

void Item::RandomType()
{
	srand(time(0));
	int percent = rand() % 100;

	if (percent < 90)
		RandomItem();
	else
		RandomWeapon();
}

void Item::RandomItem()
{
	int percent = rand() % 100;

	if (percent > 60)
	{
		type = ITEM_WHIP;
	}
	else if (percent < 60)
	{
		type = ITEM_HEART;
	}
}

void Item::RandomWeapon()
{
	int percent = rand() % 100;

	if (percent < 40)
	{
		type = ITEM_AXE;
	}
	else if (percent < 80)
	{
		type = ITEM_CROSS;
	}
	else if (percent < 90)
	{
		type = ITEM_HOLY_WATER;
	}
	else if (percent < 95)
	{
		type = ITEM_DAGGER;
	}
	else
	{
		type = ITEM_STOP_WATCH;
	}
}

void Item::Init()
{
	switch (type)
	{
	case ITEM_WHIP:
		this->AddAnimation(600);
		this->width = 32;
		this->height = 32;
		break;
	case ITEM_HEART:
		this->AddAnimation(601);
		this->width = 24;
		this->height = 20;
		break;
	}
}

Item::Item()
{
	isDead = false;
	isEnable = false;
	RandomType();
	Init();
}

Item::Item(int type)
{
	isDead = false;
	isEnable = false;
	this->type = type;
	Init();
}

Item::~Item()
{
}

void Item::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (!isDead)
	{
		left = x;
		top = y;
		right = x + width;
		bottom = y + height;
	}
}

void Item::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!isDead && isEnable)
	{
		CGameObject::Update(dt, coObjects);
		vy += SIMON_GRAVITY * dt;
		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		CalcPotentialCollisions(coObjects, coEvents);

		/*if (this->state == ITEM_STATE_UP)
		{
			vy += -0.00100f;
			if (vy <= -0.118f)
				this->SetState(ITEM_STATE_IDLE);
		}*/

		if (coEvents.size() == 0)
		{
			x += dx;
			y += dy;
		}
		else
		{
			float min_tx, min_ty, nx = 0, ny;

			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

			for (UINT i = 0; i < coEventsResult.size(); i++)
			{
				LPCOLLISIONEVENT e = coEventsResult[i];
				if (dynamic_cast<Brick*>(e->obj))
				{
					if (e->ny < 0)
					{
						x += min_tx * dx + nx * 0.4f;
						y += min_ty * dy + ny * 0.4f;

						if (nx != 0) vx = 0;
						if (ny != 0) vy = 0;
					}
				}

			}
		}
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}
}

void Item::Render()
{
	if (this->isEnable == true) {
		animations[0]->Render(x, y);
	}
}
