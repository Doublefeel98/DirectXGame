#include "NormalPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void NormalPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CEnemy::Update(dt, coObject);
	D3DXVECTOR3 alaPosition = Aladdin::GetInstance()->GetPosition();
	int x = alaPosition.x, y = alaPosition.y;

	if (this->x < x) direction = RIGHT;
	else direction = LEFT;
	bool left = direction == LEFT && (animations[state * 2 + 1]->getCurrentFrame() == animations[state * 2 + 1]->frames.size() - 1),
		right = direction == RIGHT && (animations[state * 2]->getCurrentFrame() == animations[state * 2]->frames.size() - 1);

	if (isDead) {
		//if (!finalAni) {
		//	state = NGUARD_STATE_SURPRISE;
		//	if(left||right){finalAni = true;}
		//} 
	}
	else {
		if ((state == NGUARD_STATE_SURPRISE && (left || right)) || (state != NGUARD_STATE_SURPRISE)) {
			if (abs(this->x - x) < 100) SetState(rand() % 2 == 0 ? NGUARD_STATE_SLASH : NGUARD_STATE_STAB);
			else { SetState(NGUARD_STATE_IDLE); }
		}
		else {
			state = NGUARD_STATE_SURPRISE;
		}
	}

	if (isDead) {
		x = -5;
		y = -5;
		vx = 0;
		vy = 0;
	}
}

void NormalPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + GUARD_BBOX_WIDTH_WAIT;

	if (!isDead)
		bottom = y + 0;
	else
		bottom = y + GUARD_BBOX_HEIGHT;
}
void NormalPalaceGuard::SetState(int stateNew)
{
	//if (stateNew != NGUARD_STATE_SURPRISE) {
	//	
	//}
	//else { SetState(stateNew); }
	//int frameSize = animations[state * 2 + 1]->frames.size() - 1;
	bool left = direction == LEFT && (animations[state * 2 + 1]->getCurrentFrame() == animations[state * 2 + 1]->frames.size() - 1),
		right = direction == RIGHT && (animations[state * 2]->getCurrentFrame() == animations[state * 2]->frames.size() - 1);
	//int currentFrame = direction == LEFT ?
	//	(animations[state * 2 + 1]->getCurrentFrame()) :
	//	(animations[state * 2]->getCurrentFrame());
	if (left || right) {
		CGameObject::SetState(stateNew);
	}

	//CEnemy::SetState(stateNew);

}

void NormalPalaceGuard::Render()
{
	if (!isDead) {
		//if (isEnable)
	//{
	//	animations[NORMAL_GUARD_ANI_WAIT_LEFT]->Render(x, y, 255);
	//	CEnemy::Render();
	//	RenderBoundingBox();
	//}
		if (direction == LEFT) {
			switch (state) {
			case NGUARD_STATE_IDLE:
				animations[NORMAL_GUARD_ANI_IDLE_LEFT]->Render(x, y, 255);
				RenderBoundingBox();
				break;
			case NGUARD_STATE_STAB:
				animations[NORMAL_GUARD_ANI_ATTACK_STAB_LEFT]->Render(x, y, 255);
				RenderBoundingBox();
				break;
			case NGUARD_STATE_SLASH:
				animations[NORMAL_GUARD_ANI_ATTACK_SLASH_LEFT]->Render(x, y, 255);
				RenderBoundingBox();
				break;
			case NGUARD_STATE_SURPRISE:
				animations[NORMAL_GUARD_ANI_SURPRISE_LEFT]->Render(x, y, 255);
				RenderBoundingBox();
				break;
			}
		}
		else {
			switch (state) {
			case NGUARD_STATE_IDLE:
				animations[NORMAL_GUARD_ANI_IDLE_RIGHT]->Render(x, y, 255);
				RenderBoundingBox();
				break;
			case NGUARD_STATE_STAB:
				animations[NORMAL_GUARD_ANI_ATTACK_STAB_RIGHT]->Render(x, y, 255);
				RenderBoundingBox();
				break;
			case NGUARD_STATE_SLASH:
				animations[NORMAL_GUARD_ANI_ATTACK_SLASH_RIGHT]->Render(x, y, 255);
				RenderBoundingBox();
				break;
			case NGUARD_STATE_SURPRISE:
				animations[NORMAL_GUARD_ANI_SURPRISE_RIGHT]->Render(x, y, 255);
				RenderBoundingBox();
				break;
			}
		}
	}
}

NormalPalaceGuard::NormalPalaceGuard() : CEnemy()
{
	width = GUARD_BBOX_WIDTH_WAIT;
	height = GUARD_BBOX_HEIGHT;

	//wait = false; stab = false; wave = false; jump = false; surprise = false; die = true;
	hp = GUARD_MAX_HP;
	state = NGUARD_STATE_IDLE;
	type = TYPE_NORMAL_GUARD;
	finalAni = false;

	AddAnimation(300);		// idle right
	AddAnimation(301);		// idle left

	AddAnimation(302);		// walk right
	AddAnimation(303);		// walk left

	AddAnimation(304);		// wait right
	AddAnimation(305);		// wait left

	AddAnimation(306);		// attack stab right
	AddAnimation(307);		// attack stab left

	AddAnimation(308);		// attack slash right
	AddAnimation(329);		// attack slash left

	AddAnimation(312);		// surprise right
	AddAnimation(311);		// surprise left
}

NormalPalaceGuard::~NormalPalaceGuard()
{

}