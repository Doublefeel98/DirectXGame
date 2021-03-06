﻿#include "VampireBat.h"
#include "Simon.h"
#include "Define.h"
#include "../Framework/Utils.h"

VampireBat::VampireBat() :Enemy()
{
	this->hp = VAMPIRE_BAT_HP;
	isEnable = true;

	damage = VAMPIRE_BAT_DAMAGE;

	SetState(VAMPIRE_BAT_STATE_IDLE);

	point = 200;
}

void VampireBat::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	startX = x;
	startY = y;
	if (tokens.size() > 9) {
		distanceX = atof(tokens[9].c_str());
	}
	else {
		distanceX = VAMPIRE_BAT_DISTANCE_ATTACK_X;
	}
}

VampireBat::~VampireBat()
{
}

void VampireBat::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	Enemy::Update(dt, coObject);
	if (!isDead && isEnable && !Enemy::IsStop) {

		float simonX, simonY;

		Simon::GetInstance()->GetPosition(simonX, simonY);

		if (state == VAMPIRE_BAT_STATE_FLYING)
		{
			if (nx > 0) {
				vx = VAMPIRE_BAT_FLYING_SPEED_X;
			}
			else {
				vx = -VAMPIRE_BAT_FLYING_SPEED_X;
			}

			x += dx;
			y += dy;
			if (this->y - simonY >= SIMON_BBOX_HEIGHT / 2 - 5)
			{
				vy = 0;
				y = simonY + SIMON_BBOX_HEIGHT / 2 - 5;
			}
		}
		else if (state == VAMPIRE_BAT_STATE_IDLE) {
			if (abs(this->x - simonX) < distanceX && abs(this->y - simonY) < SIMON_BBOX_HEIGHT) {
				nx = this->x >= simonX ? -1 : 1;
				SetState(VAMPIRE_BAT_STATE_FLYING);
			}
		}
	}
}

void VampireBat::Render()
{
	if (!isDead && isEnable) {
		int posX = x, posY = y;
		int ani = 0;
		switch (state)
		{
		case VAMPIRE_BAT_STATE_IDLE:
		{
			ani = VAMPIRE_BAT_ANI_IDLE;
		}
		break;
		case VAMPIRE_BAT_STATE_FLYING:
		{
			if (nx > 0) {
				ani = VAMPIRE_BAT_ANI_BLACK_FLYING_RIGHT;
			}
			else {
				ani = VAMPIRE_BAT_ANI_BLACK_FLYING_LEFT;
			}
		}
		break;
		default:
			break;
		}

		animation_set->at(ani)->Render(posX, posY, Enemy::IsStop);
		RenderBoundingBox();
	}

	Enemy::Render();
}

void VampireBat::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDead) {
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else {
		left = x;
		right = left + VAMPIRE_BAT_BBOX_WIDTH;
		top = y;
		bottom = top + VAMPIRE_BAT_BBOX_HEIGHT;
	}
}

void VampireBat::SetState(int state)
{
	Enemy::SetState(state);
	switch (state)
	{
	case VAMPIRE_BAT_STATE_IDLE:
		break;
	case VAMPIRE_BAT_STATE_FLYING:
		if (nx > 0) {
			vx = VAMPIRE_BAT_FLYING_SPEED_X;
		}
		else {
			vx = -VAMPIRE_BAT_FLYING_SPEED_X;
		}

		vy = VAMPIRE_BAT_FLYING_SPEED_Y;
		break;
	}
}
