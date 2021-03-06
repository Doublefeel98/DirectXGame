﻿#include "Item.h"
#include "Define.h"
#include <time.h>
#include "Brick.h"
#include "../Framework/BoundingMap.h"
#include "../Framework/Ground.h"
#include "../Framework/Utils.h"
#include "Simon.h"

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
	Simon* simon = Simon::GetInstance();
	int percent = rand() % 100;

	if (percent < 60)
	{
		if (simon->GetLevelWhip() < WHIP_LEVEL_3)
		{
			typeItem = ITEM_MORNING_STAIR;
		}
		else
		{
			typeItem = ITEM_SMALL_HEART;
		}
	}
	else if (percent < 70)
	{
		typeItem = ITEM_LARGE_HEART;
	}
	else if (percent < 74)
	{
		typeItem = ITEM_MONEY_BAG_RED;
	}
	else if (percent < 78)
	{
		typeItem = ITEM_MONEY_BAG_PURPLE;
	}
	else if (percent < 82)
	{
		typeItem = ITEM_MONEY_BAG_WHITE;
	}

	else if (percent < 86)
	{
		typeItem = ITEM_CHEST;
	}
	else if (percent < 90)
	{
		typeItem = ITEM_CROWN;
	}

	else if (percent < 92)
	{
		typeItem = ITEM_PORK_CHOP;
	}
	else if (percent < 95)
	{
		if (simon->GetTypeShotCollect() == 1) {
			typeItem = ITEM_DOUBLE_SHOT;
		}
		else if (simon->GetTypeShotCollect() == 2) {
			typeItem = ITEM_TRIPLE_SHOT;
		}
		else {
			typeItem = ITEM_LARGE_HEART;
		}
	}
	else if (percent < 98)
	{
		typeItem = ITEM_BONUSES;
	}
	else if (percent < 99)
	{
		typeItem = ITEM_INVISIBILITY_POTION;
	}
	else
	{
		typeItem = ITEM_CROSS;

	}
}

void Item::RandomWeapon()
{
	int percent = rand() % 100;

	if (percent < 40)
	{
		typeItem = ITEM_DAGGER;
	}
	else if (percent < 60)
	{
		typeItem = ITEM_AXE;
	}
	else if (percent < 80)
	{
		typeItem = ITEM_HOLY_WATER;
	}
	else if (percent < 90)
	{
		typeItem = ITEM_BOOMERANG;
	}
	else
	{
		typeItem = ITEM_STOP_WATCH;
	}
}

void Item::Init()
{
	SetAnimationSet(40);
	IsGround = false;
	vy = 0;
	timeDisplayMax = 3000;
	is_grow_up = false;
	switch (typeItem)
	{
	case ITEM_MONEY_BAG_RED:
		moneyEffect = new MoneyEffect(MONEY_EFFECT_100);
		break;
	case ITEM_MONEY_BAG_PURPLE:
		moneyEffect = new MoneyEffect(MONEY_EFFECT_400);
		break;
	case ITEM_MONEY_BAG_WHITE:
		moneyEffect = new MoneyEffect(MONEY_EFFECT_700);
		break;
	case ITEM_BONUSES:
		timeDisplayMax = 5000;
		moneyEffect = new MoneyEffect(MONEY_EFFECT_1000);
		break;
	case ITEM_CROWN:
	case ITEM_CHEST:
		moneyEffect = new MoneyEffect(MONEY_EFFECT_2000);
		timeDisplayMax = 5000;
		break;
	case ITEM_DOUBLE_SHOT:
		timeDisplayMax = 5000;
		break;
	case ITEM_SMALL_HEART:
		timeDisplayMax = 6000;
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
		left = x;
		top = y;
		right = x + 0;
		bottom = y + 0;
		if (!isEnable)
		{
			right = x + width;
			bottom = y + height;
		}
		else {
			switch (typeItem)
			{
			case ITEM_MORNING_STAIR:
				right = x + 16;
				bottom = y + 16;
				break;
			case ITEM_LARGE_HEART:
				right = x + 12;
				bottom = y + 10;
				break;
			case ITEM_SMALL_HEART:
				right = x + 8;
				bottom = y + 16;
				break;
			case ITEM_MONEY_BAG_RED:
			case ITEM_MONEY_BAG_PURPLE:
			case ITEM_MONEY_BAG_WHITE:
			case ITEM_BONUSES:
				right = x + 15;
				bottom = y + 15;
				break;
			case ITEM_DAGGER:
				right = x + 16;
				bottom = y + 9;
				break;
			case ITEM_AXE:
				right = x + 15;
				bottom = y + 14;
				break;
			case ITEM_HOLY_WATER:
				right = x + 16;
				bottom = y + 16;
				break;
			case ITEM_CROWN:
			case ITEM_BOOMERANG:
				right = x + 15;
				bottom = y + 16;
				break;
			case ITEM_STOP_WATCH:
				right = x + 15;
				bottom = y + 14;
				break;
			case ITEM_CROSS:
				right = x + 16;
				bottom = y + 16;
				break;
			case ITEM_INVISIBILITY_POTION:
				right = x + 13;
				bottom = y + 16;
				break;
			case ITEM_PORK_CHOP:
				right = x + 15;
				bottom = y + 14;
				break;
			case ITEM_DOUBLE_SHOT:
			case ITEM_TRIPLE_SHOT:
				right = x + 14;
				bottom = y + 14;
				break;
			case ITEM_MAGIC_CRYSTAL:
				right = x + 14;
				bottom = y + 16;
				break;
			case ITEM_CHEST:
				right = x + 16;
				bottom = y + 12;
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
		if (GetTickCount() - timeDisplay >= timeDisplayMax) {
			isEnable = false;
			isDead = true;
			return;
		}

		CGameObject::Update(dt, coObjects);
		if (typeItem != ITEM_SMALL_HEART) {
			if (is_grow_up) {
				vy -= ITEM_GROW_UP * dt;
			}
			else {
				vy += ITEM_GRAVITY * dt;
			}
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
					}
					if (nx == 1) {
						vx = -SIMON_WALKING_SPEED;
						nx = -1;
					}
					else {
						vx = SIMON_WALKING_SPEED;
						nx = 1;
					}

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

		if (is_grow_up) {
			x += dx;
			y += dy;
			if (y <= start_y) {
				is_grow_up = false;
			}
		}
		else {
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

				bool isColisionGround = false;
				for (UINT i = 0; i < coEventsResult.size(); i++)
				{
					LPCOLLISIONEVENT e = coEventsResult[i];
					if (dynamic_cast<Ground*>(e->obj) || dynamic_cast<BoundingMap*>(e->obj))
					{
						IsGround = true;
						isColisionGround = true;
					}
				}

				if (!isColisionGround) {
					x += dx;
					y += dy;
				}
				else {
					x += min_tx * dx + nx * 0.4f;
					y += min_ty * dy + ny * 0.4f;

					if (nx != 0) vx = 0;
					if (ny != 0) vy = 0;
				}

			}
			for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
		}

	}
	if (moneyEffect != nullptr) {
		Simon* simon = Simon::GetInstance();
		if (simon->nx > 0) {
			moneyEffect->SetPosition(x + 15, y - 10);
		}
		else {
			moneyEffect->SetPosition(x - 15, y - 10);
		}

		moneyEffect->Update(dt);
	}
}

void Item::Render()
{
	if (this->isEnable == true && animation_set->size()) {
		animation_set->at(typeItem)->Render(x, y);
		RenderBoundingBox();
	}

	if (moneyEffect != nullptr) {
		moneyEffect->Render();
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

void Item::Enable()
{
	SetEnable(true);
	timeDisplay = GetTickCount();
}

void Item::SetIsGrowUp(bool is_grow_up)
{
	this->is_grow_up = is_grow_up;
	float l, r, t, b;
	GetBoundingBox(l, t, r, b);
	start_y = y - (b - t) - 1;
}
