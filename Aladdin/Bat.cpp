#include "Bat.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include"Bat.h"

void Bat::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CEnemy::Update(dt, coObject);

	if (init) {
		x_start = this->x; y_start = this->y;
		init = false;
	}

	x += dx;
	y += dy;
	D3DXVECTOR3 alaPos = Aladdin::GetInstance()->GetPosition();
	float x = alaPos.x, y = alaPos.y;

	if (!reverse && GetTickCount() - lastActive > BAT_TIME_REVERSE) {
		if (abs(this->x - x) < BAT_DELTA_X && y - this->y < BAT_DELTA_Y) {
			if (init) {
				direction = this->x < x ? LEFT : RIGHT;
				init = false;
			}
			else {
				if (this->y <= y) {
					vy += BAT_VY * dt;
					vx = direction == LEFT ? -0.01 : 0.01;
					state = BAT_STATE_FLY;
				}
				else {
					vy = 0;
					vx = direction == LEFT ? -BAT_VX : BAT_VX;

					if (abs(this->x - x_start) > BAT_DELTA_X_REVERSE) reverse = true;
				}
			}
			state = abs(this->x - x) < BAT_DELTA_X_ATTACK ? BAT_STATE_SWING : BAT_STATE_FLY;
		}
		else {
			state = BAT_STATE_WAIT;
		}
	}
	else if (reverse) {
		state = abs(this->x - x) < BAT_DELTA_X_ATTACK ? BAT_STATE_SWING : BAT_STATE_FLY;
		if (abs(this->x - x_start) < 5 && this->y < y_start) {
			state = BAT_STATE_WAIT;
			vx = vy = 0;
			this->x = x_start; this->y = y_start;
			reverse = false;
			init = true;
			lastActive = GetTickCount();
		}
		else if (abs(this->x - x_start) > 5) {
			vx = direction == LEFT ? BAT_VX : -BAT_VX;
		}
		else {
			vy = -0.1;
			vx = 0;
		}

	}

	if (isDead) {
		if (!finalAni) {
			state = BAT_STATE_DIE;
			if (animations[BAT_ANI_DIE]->currentFrame == (animations[BAT_ANI_DIE]->frames.size() - 1)) {
				finalAni = true;
			}
		}
	}
	if (isDead) {
		x = -5;
		y = -5;
		vx = 0;
		vy = 0;
	}
}

void Bat::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (!isDead) {
		if (wait) {
			left = x;
			top = y + 5;
			right = left + BAT_WAIT_BBOX_WIDTH;
			bottom = top + BAT_WAIT_BBOX_HEIGHT;
		}
		else if (fly) {
			left = x;
			top = y + 10;
			right = left + BAT_FLY_BBOX_WIDTH;
			bottom = top + BAT_FLY_BBOX_HEIGHT;
		}
		else if (swing) {
			left = x;
			top = y + 10;
			right = left + BAT_ROLATE_BBOX_WIDTH;
			bottom = top + BAT_ROLATE_BBOX_HEIGHT;
		}
		else {
			left = x;
			top = y;
			right = left + BAT_DIE_BBOX_WIDTH;
			bottom = top + BAT_DIE_BBOX_HEIGHT;
		}
	}

}
void Bat::Render()
{
	if (!finalAni) {
		switch (state) {
		case BAT_STATE_WAIT:
			animations[BAT_ANI_WAIT]->Render(x, y, 255);
			RenderBoundingBox();
			break;
		case BAT_STATE_FLY:
			animations[BAT_ANI_FLY]->Render(x, y, 255);
			RenderBoundingBox();
			break;
		case BAT_STATE_DIE:
			animations[BAT_ANI_DIE]->Render(x, y, 255);
			RenderBoundingBox();
			break;
		case BAT_STATE_SWING:
			animations[BAT_ANI_SWING]->Render(x, y, 255);
			RenderBoundingBox();
			break;
		}
	}
}

Bat::Bat() :CEnemy() 
{	
	width = BAT_WAIT_BBOX_WIDTH;
	height = BAT_WAIT_BBOX_HEIGHT;

	//wait = true; fly = false; swing = false; die = false;
	state = BAT_STATE_WAIT;
	hp = BAT_MAX_HP;
	type = OBJECT_BAT;
	finalAni = reverse = false;
	init = true;

	AddAnimation(500);		// wait

	AddAnimation(501);		// swing

	AddAnimation(502);		// fly

	AddAnimation(503);		//die
}

Bat::~Bat() {

}