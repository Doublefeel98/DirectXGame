#include "Item.h"
#include "Define.h"
#include <time.h>
#include "Brick.h"
#include "../Framework/BoundingMap.h"
#include "../Framework/Ground.h"
#include "../Framework/Utils.h"

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
		typeItem = ITEM_WHIP;
	}
	else if (percent < 60)
	{
		typeItem = ITEM_HEART;
	}
}

void Item::RandomWeapon()
{
	int percent = rand() % 100;

	if (percent < 40)
	{
		typeItem = ITEM_AXE;
	}
	else if (percent < 80)
	{
		typeItem = ITEM_CROSS;
	}
	else if (percent < 90)
	{
		typeItem = ITEM_HOLY_WATER;
	}
	else if (percent < 95)
	{
		typeItem = ITEM_DAGGER;
	}
	else
	{
		typeItem = ITEM_STOP_WATCH;
	}
}

void Item::Init()
{
	IsGround = false;
	vy = 0;
	switch (typeItem)
	{
	case ITEM_WHIP:
		this->width = 32;
		this->height = 32;
		break;
	case ITEM_HEART:
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

Item::Item(int typeItem)
{
	isDead = false;
	isEnable = false;
	this->typeItem = typeItem;
	Init();
}

Item::~Item()
{
}

void Item::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (!isDead)
	{
		if (!isEnable)
		{
			left = x;
			top = y;
			right = x + width;
			bottom = y + height;
		}
		else {
			switch (typeItem)
			{
			case ITEM_WHIP:
				left = x;
				top = y;
				right = x + 16;
				bottom = y + 16;
				break;
			case ITEM_HEART:
				left = x;
				top = y;
				right = x + 12;
				bottom = y + 10;
				break;
			case ITEM_SMALL_HEART:
				left = x;
				top = y;
				right = x + 8;
				bottom = y + 8;
				break;
			case ITEM_KNIFE:
				left = x;
				top = y;
				right = x + 16;
				bottom = y + 9;
				break;
			case ITEM_BOOMERANG:
				left = x;
				top = y;
				right = x + 15;
				bottom = y + 14;
				break;
			default:
				break;
			}
		}
	}
}

void Item::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!isDead && isEnable)
	{
		CGameObject::Update(dt, coObjects);
		if (typeItem != ITEM_SMALL_HEART) {
			vy += SIMON_GRAVITY * dt;
		}
		else {
			vy = SIMON_GRAVITY * dt * 2;
			if (!IsGround) {
				DWORD now = GetTickCount();
				int temp = 300;
				if (IsFirstTime) {
					//temp = temp / 2;
				}

				if (now - timeStartEnable >= temp) {
					if (IsFirstTime) {
						IsFirstTime = false;
						DebugOut(L"[INFO] item vx1 %d\n", nx);
					}
					if (nx == 1) {
						vx = -SIMON_WALKING_SPEED;
						nx = -1;
					}
					else {
						vx = SIMON_WALKING_SPEED;
						nx = 1;
					}
					DebugOut(L"[INFO] item vx2 %d\n", nx);

					timeStartEnable = now;
				}
				else {
					if (nx == 1) {
						vx = SIMON_WALKING_SPEED;
					}
					else {
						vx = -SIMON_WALKING_SPEED;
					}
				}
			}
			else {
				vx = 0;
			}
		}

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
			float rdx = 0;
			float rdy = 0;

			// TODO: This is a very ugly designed function!!!!
			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny, rdx, rdy);

			for (UINT i = 0; i < coEventsResult.size(); i++)
			{
				LPCOLLISIONEVENT e = coEventsResult[i];
				if (dynamic_cast<Ground*>(e->obj))
				{
					if (e->ny < 0)
					{
						x += min_tx * dx + nx * 0.4f;
						y += min_ty * dy + ny * 0.4f;

						if (nx != 0) vx = 0;
						if (ny != 0) vy = 0;
						IsGround = true;
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
		animation_set->at(typeItem)->Render(x, y);
		RenderBoundingBox();
	}
}

void Item::TurnOnTimeStartEnable()
{
	timeStartEnable = GetTickCount();
	nx = 1;
	vx = SIMON_WALKING_SPEED;
	vy = SIMON_GRAVITY * dt * 2;
	IsFirstTime = true;
}
