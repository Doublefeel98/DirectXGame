#include "Raven.h"
#include "Define.h"
#include "Simon.h"

Raven::Raven() : Enemy()
{
	this->hp = 1;
	isEnable = true;
	damage = 1;

	SetState(RAVEN_STATE_IDLE);

	point = 200;
	vy = 0;
}

void Raven::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	startX = x;
	startY = y;
}

Raven::~Raven()
{

}

void Raven::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	Enemy::Update(dt, coObjects);
	if (!isDead && isEnable && !Enemy::IsStop) {

		float simonX, simonY;

		Simon::GetInstance()->GetPosition(simonX, simonY);

		nx = this->x >= simonX ? -1 : 1;
		ny = this->y >= simonY ? -1 : 1;

		if (state == RAVEN_STATE_FLY)
		{
			if (abs(this->x - simonX) >= SIMON_BBOX_WIDTH / 2) {
				x += dx;
			}
			if (!(simonY <= this->y && this->y - simonY <= GHOST_BBOX_HEIGHT / 2 - 5)) {
				y += dy;
			}
			//if (this->y - simonY >= SIMON_BBOX_HEIGHT / 2 - 5)
			//{
			//	vy = 0;
			//	y = simonY + SIMON_BBOX_HEIGHT / 2 - 5;
			//}

			if (nx > 0) {
				vx = RAVEN_FLYING_SPEED_X;
			}
			else {
				vx = -RAVEN_FLYING_SPEED_X;
			}

			if (ny > 0) {
				vy = RAVEN_FLYING_SPEED_Y;
			}
			else {
				vy = -RAVEN_FLYING_SPEED_Y;
			}

			/*if (nx > 0) {
				if (abs(this->x - simonX) <= RAVEN_DISTANCE_WAITING_X + SIMON_BBOX_WIDTH
					&& abs(this->y - simonY) < SIMON_BBOX_HEIGHT / 2) {
					SetState(RAVEN_STATE_WAIT);
				}
			}
			else {
				if (abs(this->x - simonX) <= RAVEN_DISTANCE_WAITING_X
					&& abs(this->y - simonY) < SIMON_BBOX_HEIGHT / 2) {
					SetState(RAVEN_STATE_WAIT);
				}
			}*/

			DWORD now = GetTickCount();
			if (now - time_wait >= 1500) {
				SetState(RAVEN_STATE_WAIT);
			}
		}
		else if (state == RAVEN_STATE_IDLE) {
			if (abs(this->x - simonX) < RAVEN_DISTANCE_ATTACK_X) {
				SetState(RAVEN_STATE_FLY);
			}
		}
		else if (state == RAVEN_STATE_WAIT) {
			DWORD now = GetTickCount();
			if (now - time_wait >= 500) {
				if (abs(this->x - simonX) < RAVEN_DISTANCE_ATTACK_X) {
					SetState(RAVEN_STATE_FLY);
				}
			}

		}
	}
}

void Raven::Render()
{
	if (!isDead && isEnable) {
		int ani = 0;
		switch (state)
		{
		case RAVEN_STATE_IDLE:
		{
			if (nx > 0) {
				ani = RAVEN_ANI_IDLE_RIGHT;
			}
			else {
				ani = RAVEN_ANI_IDLE_LEFT;
			}
		}
		break;
		case RAVEN_STATE_FLY:
		case RAVEN_STATE_WAIT:
		case RAVEN_STATE_ATTACK:
		{
			if (nx > 0) {
				ani = RAVEN_ANI_FLY_RIGHT;
			}
			else {
				ani = RAVEN_ANI_FLY_LEFT;
			}
		}
		break;
		default:
			break;
		}

		animation_set->at(ani)->Render(x, y, Enemy::IsStop);
		RenderBoundingBox();
	}

	Enemy::Render();
}

void Raven::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDead) {
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else {
		left = x;
		top = y;
		if (state == RAVEN_STATE_IDLE) {
			right = left + 16;
			bottom = top + 12;
		}
		else {
			if (animation_set->at(0)->GetCurrentFrame() == 0) {
				right = left + 16;
				bottom = top + 16;
			}
			else if (animation_set->at(0)->GetCurrentFrame() == 1) {
				right = left + 15;
				bottom = top + 15;
			}
			else {
				right = left + 15;
				bottom = top + 15;
			}
		}
	}
}

void Raven::SetState(int state)
{
	Enemy::SetState(state);
	switch (state)
	{
	case RAVEN_STATE_DIE:
		isDead = true;
		isEnable = false;
		break;
	case RAVEN_STATE_IDLE:
		break;
	case RAVEN_STATE_FLY:
		if (nx > 0) {
			vx = RAVEN_FLYING_SPEED_X;
		}
		else {
			vx = -RAVEN_FLYING_SPEED_X;
		}

		if (ny > 0) {
			vy = RAVEN_FLYING_SPEED_Y;
		}
		else {
			vy = -RAVEN_FLYING_SPEED_Y;
		}

		break;
	case RAVEN_STATE_WAIT:
		time_wait = GetTickCount();
		vx = 0;
		vy = 0;
		break;
	}
}
