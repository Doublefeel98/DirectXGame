#include "Ghost.h"
#include "Define.h"
#include "Simon.h"

Ghost::Ghost() :Enemy()
{
	this->hp = GHOST_HP;
	isEnable = true;
	damage = GHOST_DAMAGE;

	SetState(GHOST_STATE_HIDE);

	point = 300;
}

void Ghost::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	startX = x;
	startY = y;
}

Ghost::~Ghost()
{
}

void Ghost::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	Enemy::Update(dt, coObject);
	if (!isDead && isEnable && !Enemy::IsStop) {
		float simonX, simonY;

		Simon::GetInstance()->GetPosition(simonX, simonY);
		nx = this->x >= simonX ? -1 : 1;
		ny = this->y >= simonY ? -1 : 1;
		if (state == GHOST_STATE_FLYING)
		{
			nx = this->x >= simonX ? -1 : 1;

			if (abs(this->x - simonX) >= SIMON_BBOX_WIDTH / 2) {
				x += dx;
			}
			if (!(simonY <= this->y && this->y - simonY <= GHOST_BBOX_HEIGHT / 2)) {
				y += dy;
			}

			if (nx > 0) {
				vx = GHOST_FLYING_SPEED_X;
			}
			else {
				vx = -GHOST_FLYING_SPEED_X;
			}

			if (ny > 0) {
				vy = GHOST_FLYING_SPEED_X;
			}
			else {
				vy = -GHOST_FLYING_SPEED_X;
			}

			//if (nx > 0) {
			//	if (abs(this->x - simonX) <= GHOST_DISTANCE_WAITING_X + SIMON_BBOX_WIDTH && abs(this->y - simonY) < SIMON_BBOX_HEIGHT) {
			//		SetState(GHOST_STATE_WAITTING);
			//	}
			//}
			//else {
			//	if (abs(this->x - simonX) <= GHOST_DISTANCE_WAITING_X && abs(this->y - simonY) < SIMON_BBOX_HEIGHT) {
			//		SetState(GHOST_STATE_WAITTING);
			//	}
			//}
		}
		else if (state == GHOST_STATE_WAITTING) {
			if (GetTickCount() - time_waiting > 500) {
				SetState(GHOST_STATE_FLYING);
			}
		}
		else if (state == GHOST_STATE_COMEBACK) {
			nx = old_nx;

			x += dx;
			if (!(simonY <= this->y && this->y - simonY <= GHOST_BBOX_HEIGHT / 2)) {
				y += dy;
			}

			if (nx > 0) {
				vx = GHOST_FLYING_SPEED_X;
			}
			else {
				vx = -GHOST_FLYING_SPEED_X;
			}

			if (ny > 0) {
				vy = GHOST_FLYING_SPEED_X;
			}
			else {
				vy = -GHOST_FLYING_SPEED_X;
			}

			if ((nx > 0 && x_back <= x) || (nx < 0 && x_back >= x)) {
				SetState(GHOST_STATE_WAITTING);
			}
		}
		else if (state == GHOST_STATE_HIDE) {
			if (nx < 0) {
				if (this->x - (simonX + SIMON_BBOX_WIDTH) >= GHOST_DISTANCE_ATTACK_X) {
					SetState(GHOST_STATE_FLYING);
				}
			}
			else {
				if (simonX - (this->x + GHOST_BBOX_WIDTH) >= GHOST_DISTANCE_ATTACK_X) {
					SetState(GHOST_STATE_FLYING);
				}
			}
		}
	}
}

void Ghost::Render()
{
	if (!isDead && isEnable && state != GHOST_STATE_HIDE) {
		int ani = 0;

		if (nx > 0) {
			ani = GHOST_ANI_FLYING_RIGHT;
		}
		else {
			ani = GHOST_ANI_FLYING_LEFT;
		}

		animation_set->at(ani)->Render(x, y, Enemy::IsStop);
		RenderBoundingBox();
	}

	Enemy::Render();
}

void Ghost::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDead || state == GHOST_STATE_HIDE || state == GHOST_STATE_COMEBACK) {
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else {
		left = x;
		right = left + GHOST_BBOX_WIDTH;
		top = y;
		bottom = top + GHOST_BBOX_HEIGHT;
	}
}

void Ghost::SetState(int state)
{
	Enemy::SetState(state);
	switch (state)
	{
	case GHOST_STATE_DIE:
		isDead = true;
		isEnable = false;
		break;
	case GHOST_STATE_HIDE:

		break;
	case GHOST_STATE_FLYING:
		if (nx > 0) {
			vx = GHOST_FLYING_SPEED_X;
		}
		else {
			vx = -GHOST_FLYING_SPEED_X;
		}

		if (ny > 0) {
			vy = GHOST_FLYING_SPEED_X;
		}
		else {
			vy = -GHOST_FLYING_SPEED_X;
		}
		break;
	case GHOST_STATE_COMEBACK:
		old_nx = nx;
		if (nx > 0) {
			x_back = x + GHOST_DISTANCE_WAITING_X + GHOST_BBOX_WIDTH;
		}
		else {
			x_back = x - SIMON_BBOX_WIDTH - GHOST_DISTANCE_WAITING_X;
		}
	case GHOST_STATE_WAITTING:
		vx = 0;
		vy = 0;
		time_waiting = GetTickCount();
		break;
	}

}
