#include "NormalPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void NormalPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{

	//int x = alaPosition.x, y = alaPosition.y;

	//if (this->x < x) direction = RIGHT;
	//else direction = LEFT;
	//bool left = direction == LEFT && (animations[state * 2 + 1]->getCurrentFrame() == animations[state * 2 + 1]->frames.size() - 1),
	//	right = direction == RIGHT && (animations[state * 2]->getCurrentFrame() == animations[state * 2]->frames.size() - 1);

	//if (isDead) {
	//	//if (!finalAni) {
	//	//	state = NGUARD_STATE_SURPRISE;
	//	//	if(left||right){finalAni = true;}
	//	//} 
	//}
	//else {
	//	if ((state == NGUARD_STATE_SURPRISE && (left || right)) || (state != NGUARD_STATE_SURPRISE)) {
	//		if (abs(this->x - x) < 100) SetState(rand() % 2 == 0 ? NGUARD_STATE_SLASH : NGUARD_STATE_STAB);
	//		else { SetState(NGUARD_STATE_IDLE); }
	//	}
	//	else {
	//		state = NGUARD_STATE_SURPRISE;
	//	}
	//}

	//if (isDead) {
	//	x = -5;
	//	y = -5;
	//	vx = 0;
	//	vy = 0;
	//}



	if (!isDead) {
		CEnemy::Update(dt, coObject);
		D3DXVECTOR3 alaPosition = Aladdin::GetInstance()->GetPosition();

		nx = this->x >= alaPosition.x ? -1 : 1;

		if (state == NGUARD_STATE_WALK)
		{
			x += dx;
			y += dy;
		}
		else if (state == NGUARD_STATE_SURPRISE)
		{
			if (GetTickCount() - timeBeAttack > 700)
			{
				state = NGUARD_STATE_SLASH;
				timeBeAttack = GetTickCount();
				resetAniSlash();
				resetAniStab();
			}
			return;
		}


		if (abs(this->x - alaPosition.x) < GUARD_DELTA_X && abs(this->y - alaPosition.y) < ALADDIN_BBOX_HEIGHT)
		{
			if (!init)
			{
				init = true;
				startX = this->x;
				startY = this->y;

				SetState(NGUARD_STATE_WALK);
			}
			else if (abs(startX - this->x) < GUARD_DELTA_WALK_X) {
				SetState(NGUARD_STATE_WALK);
			}
			else {
				DWORD now = GetTickCount();
				if (timeSlash == 0 && timeStab == 0)
				{
					timeSlash = now;
					SetState(NGUARD_STATE_SLASH);
				}
				else if (now - timeSlash > 1090 && timeSlash != 0)
				{
					SetState(NGUARD_STATE_STAB);
					timeSlash = 0;
					timeStab = now;
					resetAniSlash();
				}
				else if (now - timeStab > 600 && timeStab != 0) {
					timeStab = 0;
					resetAniStab();
				}
			}
		}
		else {
			SetState(NGUARD_STATE_WAIT);
		}
	}
}

void NormalPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDead) {
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else {
		int boxWidth = GUARD_BBOX_WIDTH;
		int boxHeight = GUARD_BBOX_HEIGHT;
		switch (state)
		{
		case NGUARD_STATE_WALK:

			break;
		case NGUARD_STATE_WAIT:

			break;
		case NGUARD_STATE_STAB:
			boxWidth = GUARD_STAB_BBOX_WIDTH;
			boxHeight = GUARD_STAB_BBOX_HEIGHT;
			break;
		case NGUARD_STATE_SLASH:
			boxWidth = GUARD_SLASH_BBOX_WIDTH;
			boxHeight = GUARD_SLASH_BBOX_HEIGHT;
			break;
		case NGUARD_STATE_SURPRISE:
			boxWidth = GUARD_SURSPRISE_BBOX_WIDTH;
			boxHeight = GUARD_SURPRISE_BBOX_HEIGHT;
			break;
		default:
			break;
		}
		if (ani == -1)
		{
			left = x;
			top = y;
			right = left + boxWidth;
			bottom = top + boxHeight;
		}
		else {
			int currentFrame = animations[ani]->getCurrentFrame();
			if (currentFrame != -1)
			{
				left = x + animations[ani]->frames[currentFrame]->GetSprite()->dx;
				top = y + animations[ani]->frames[currentFrame]->GetSprite()->dy;
			}
			else {
				left = x;
				top = y;
			}
			right = left + boxWidth;
			bottom = top + boxHeight;
		}
	}
}

void NormalPalaceGuard::SetState(int stateNew)
{
	//if (stateNew != NGUARD_STATE_SURPRISE) {
	//	
	//}
	//else { SetState(stateNew); }
	//int frameSize = animations[state * 2 + 1]->frames.size() - 1;
	/*bool left = direction == LEFT && (animations[state * 2 + 1]->getCurrentFrame() == animations[state * 2 + 1]->frames.size() - 1),
		right = direction == RIGHT && (animations[state * 2]->getCurrentFrame() == animations[state * 2]->frames.size() - 1);*/
		//int currentFrame = direction == LEFT ?
		//	(animations[state * 2 + 1]->getCurrentFrame()) :
		//	(animations[state * 2]->getCurrentFrame());
		/*if (left || right) {
			CGameObject::SetState(stateNew);
		}*/

		//CEnemy::SetState(stateNew);

	CEnemy::SetState(stateNew);
	switch (stateNew)
	{
	case NGUARD_STATE_IDLE:
		vx = 0;
		break;
	case NGUARD_STATE_WALK:
		if (nx > 0)
		{
			vx = GUARD_WALKING_SPEED;
		}
		else {
			vx = -GUARD_WALKING_SPEED;
		}
		break;
	case NGUARD_STATE_WAIT:
		vx = 0;
		break;
	case NGUARD_STATE_STAB:
		vx = 0;
		break;
	case NGUARD_STATE_SLASH:
		vx = 0;
		break;
	case NGUARD_STATE_SURPRISE:
		timeBeAttack = GetTickCount();
		vx = 0;
		break;
	default:
		break;
	}
}

void NormalPalaceGuard::Render()
{
	/*if (!isDead) {
		if (direction == LEFT) {
			switch (state) {
			case NGUARD_STATE_IDLE:
				animations[NORMAL_GUARD_ANI_IDLE_LEFT]->Render(x, y, 255);
				RenderBoundingBox();
				break;
			case NGUARD_STATE_STAB:
				animations[NORMAL_GUARD_ANI_ATTACK_STAB_LEFT]->Render(x, y - 21, 255);
				RenderBoundingBox();
				break;
			case NGUARD_STATE_SLASH:
				animations[NORMAL_GUARD_ANI_ATTACK_SLASH_LEFT]->Render(x, y - 23, 255);
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
				animations[NORMAL_GUARD_ANI_ATTACK_STAB_RIGHT]->Render(x, y - 21, 255);
				RenderBoundingBox();
				break;
			case NGUARD_STATE_SLASH:
				animations[NORMAL_GUARD_ANI_ATTACK_SLASH_RIGHT]->Render(x, y - 23, 255);
				RenderBoundingBox();
				break;
			case NGUARD_STATE_SURPRISE:
				animations[NORMAL_GUARD_ANI_SURPRISE_RIGHT]->Render(x, y, 255);
				RenderBoundingBox();
				break;
			}
		}
	}*/


	if (!isDead) {
		int posX = x, posY = y;
		switch (state)
		{
		case NGUARD_STATE_IDLE:
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_IDLE_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_IDLE_LEFT;
			}
			break;
		case NGUARD_STATE_WALK:
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_WALK_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_WALK_LEFT;
			}
			break;
		case NGUARD_STATE_WAIT:
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_WAIT_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_WAIT_LEFT;
			}
			break;
		case NGUARD_STATE_STAB:
			posY = y - 21;
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_ATTACK_STAB_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_ATTACK_STAB_LEFT;
			}
			break;
		case NGUARD_STATE_SLASH:
			posY = y - 23;
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_ATTACK_SLASH_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_ATTACK_SLASH_LEFT;
			}
			break;
		case NGUARD_STATE_SURPRISE:
			posY = y - 15;
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_SURPRISE_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_SURPRISE_LEFT;
			}
			break;
		default:
			break;
		}

		animations[ani]->Render(posX, posY);
		RenderBoundingBox();
	}
}

void NormalPalaceGuard::resetAniSlash()
{
	animations[NORMAL_GUARD_ANI_ATTACK_SLASH_RIGHT]->reset();
	animations[NORMAL_GUARD_ANI_ATTACK_SLASH_LEFT]->reset();
}

void NormalPalaceGuard::resetAniStab()
{
	animations[NORMAL_GUARD_ANI_ATTACK_STAB_RIGHT]->reset();
	animations[NORMAL_GUARD_ANI_ATTACK_STAB_LEFT]->reset();
}

void NormalPalaceGuard::resetAniSurprise()
{
	animations[NORMAL_GUARD_ANI_SURPRISE_RIGHT]->reset();
	animations[NORMAL_GUARD_ANI_SURPRISE_LEFT]->reset();
}

NormalPalaceGuard::NormalPalaceGuard() : CEnemy()
{
	width = GUARD_BBOX_WIDTH;
	height = GUARD_BBOX_HEIGHT;

	//wait = false; stab = false; wave = false; jump = false; surprise = false; die = true;
	hp = GUARD_MAX_HP;
	state = NGUARD_STATE_IDLE;
	type = OBJECT_NORMAL_PALACE_GUARD;
	finalAni = false;
	timeSlash = 0;
	timeStab = 0;

	ani = -1;

	AddAnimation(300);		// idle right
	AddAnimation(301);		// idle left

	AddAnimation(302);		// walk right
	AddAnimation(303);		// walk left

	AddAnimation(304);		// wait right
	AddAnimation(305);		// wait left

	AddAnimation(306);		// attack stab right
	AddAnimation(307);		// attack stab left

	AddAnimation(308);		// attack slash right
	AddAnimation(309);		// attack slash left

	AddAnimation(310);		// surprise right
	AddAnimation(311);		// surprise left
}

NormalPalaceGuard::~NormalPalaceGuard()
{

}