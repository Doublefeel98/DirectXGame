#include "Bat.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include"Bat.h"

void Bat::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{	
	if (init) {
		x_start = this->x; y_start = this->y;
		init = false;
	}

	CEnemy::Update(dt, coObject);
	x += dx;
	y += dy;
	D3DXVECTOR3 alaPos = Aladdin::GetInstance()->GetPosition();
	float x = alaPos.x, y = alaPos.y;
	if (!reverse && GetTickCount()-lastActive > 5000) {
		if (abs(this->x - x) < 300 && this->y <= y + 20 && this->y - y > -300) {
			if (init) {
				direction = this->x < x ? LEFT : RIGHT;
				init = false;
			}
			else {
				if (this->y <= y) {
					vy += 0.001 * dt;
					vx = 0;
					state = BAT_STATE_FLY;
				}
				else {
					vy = 0;
					vx = direction == LEFT ? -0.05 : 0.05;

					if (abs(this->x - x_start) > 300) reverse = true;
				}
			}
		}
		state = abs(this->x - x) < 50 ? BAT_STATE_SWING : BAT_STATE_FLY;
	}
	else if(reverse){
		state = abs(this->x - x) < 50 ? BAT_STATE_SWING : BAT_STATE_FLY;
		if (abs(this->x - x_start) < 5 && this->y < y_start) {
			state = BAT_STATE_WAIT;
			vx = vy = 0;
			this->x = x_start; this->y = y_start;
			reverse = false;
			init = true;
			lastActive = GetTickCount();
		}else if (abs(this->x - x_start) > 5) {
			vx = direction == LEFT?  0.05:-0.05;
		}
		else {
			vy = -0.1;
			vx = 0;
		}
				
	}
	//if (abs(this->x - x) < 300 && this->y<=y+20 && this->y-y>-300) {
	//	if (reverse) {
	//		if (abs(this->x - x_start) > 5) {
	//			if (this->x < x_start) vx = 0.1;
	//			else vx = -0.1;
	//		}
	//		else {
	//			vy = -0.1;
	//		}
	//		if (abs(this->x - x_start) < 5 && abs(this->y - y_start) < 5) {
	//			state = BAT_STATE_WAIT;
	//			vx = vy = 0;
	//			reverse = false;
	//		}
	//	}
	//	else {
	//		if (this->y <= y) {
	//			vy += 0.02*dt;
	//			vx = 0.1;
	//			state = BAT_STATE_FLY;
	//		}
	//		else {
	//			vy = 0;
	//
	//			if (this->x < x) vx = 0.1;
	//			else vx = -0.1;
	//
	//			if (abs(this->x - x_start) > 300) reverse = true;
	//		}
	//	}
	//	
	//}
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
			right = left + BAT_BBOX_WIDTH_WAIT;
			bottom = top + BAT_BBOX_HEIGHT;
		}
		else if (fly) {
			left = x;
			top = y + 10;
			right = left + BAT_BBOX_WIDTH_FLY;
			bottom = top + BAT_BBOX_HEIGHT;
		}
		else if (swing) {
			left = x;
			top = y + 10;
			right = left + BAT_BBOX_WIDTH_ROTATE;
			bottom = top + BAT_BBOX_HEIGHT;
		}
		else {
			left = x;
			top = y;
			right = left + BAT_BBOX_WIDTH_DIE;
			bottom = top + BAT_BBOX_HEIGHT;
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
	
	//if (wait) {
	//	animations[BAT_ANI_WAIT]->Render(x, y, 255);
	//	RenderBoundingBox();
	//}
	//else if (fly) {
	//	animations[BAT_ANI_FLY]->Render(x, y, 255);
	//	RenderBoundingBox();
	//}
	//else if (swing) {
	//	animations[BAT_ANI_SWING]->Render(x, y, 255);
	//	RenderBoundingBox();
	//}
	//else {
	//	animations[BAT_ANI_DIE]->Render(x, y, 255);
	//	RenderBoundingBox();
	//}

	//if (isEnable)
	//{
	//	animations[BAT_ANI_SWING]->Render(x, y, 255);
	//	CEnemy::Render();
	//	RenderBoundingBox();
	//}
}

Bat::Bat() :CEnemy() 
{	
	width = BAT_BBOX_WIDTH_WAIT;
	height = BAT_BBOX_HEIGHT;

	//wait = true; fly = false; swing = false; die = false;
	state = BAT_STATE_WAIT;
	hp = BAT_MAX_HP;
	type = TYPE_BAT;
	finalAni = reverse = false; init = true;

	AddAnimation(230);		// wait

	AddAnimation(231);		// swing

	AddAnimation(232);		// fly

	AddAnimation(233);		//die
}

Bat::~Bat() {

}