#include "ThinPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void ThinPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CEnemy::Update(dt, coObject);
	if (!isDead) {
		CEnemy::Update(dt, coObject);
		D3DXVECTOR3 alaPosition = Aladdin::GetInstance()->GetPosition();

		nx = this->x >= alaPosition.x ? -1 : 1;

		if (state == TGUARD_STATE_WALK)
		{
			//x += dx;
			//y += dy;
		}
		else if (state == TGUARD_STATE_SURPRISE)
		{
			if (GetTickCount() - timeBeAttack > 890)
			{
				state = TGUARD_STATE_ATTACK;
				timeBeAttack = GetTickCount();
				resetAniAttack();
			}
			return;
		}

		if (abs(this->x - alaPosition.x) < GUARD_DELTA_X && abs(this->y - alaPosition.y) < ALADDIN_BBOX_HEIGHT)
		{
			if (!init)
			{
				init = true;
				//startX = this->x;
				//startY = this->y;

				//SetState(TGUARD_STATE_WALK);
			}
			else if (abs(startX - this->x) < GUARD_DELTA_WALK_X) {
				SetState(TGUARD_STATE_WALK);
			}
			else {
				DWORD now = GetTickCount();
				guardSword->SetEnable(false);
				guardSword->SetFighting(false);
				if (nx > 0)
				{
					guardSword->SetState(SWORD_STATE_RIGHT);
					guardSword->SetPosition(x + THIN_GUARD_BBOX_WIDTH, y + 10);
				}
				else {
					guardSword->SetState(SWORD_STATE_LEFT);
					guardSword->SetPosition(x, y + 10);
				}
				if (now - timeAttack >= 300 && timeAttack != 0)
				{
					if (!guardSword->IsFighting())
					{
						guardSword->SetEnable(true);
						guardSword->SetFighting(true);
						if(nx>0)
							guardSword->SetPosition(x + THIN_GUARD_BBOX_WIDTH, y + 10);
						else
							guardSword->SetPosition(x, y + 10);
					}
				}

				if (now - timeAttack > 590 && timeAttack != 0)
				{
					guardSword->SetEnable(false);
				}

				if (timeAttack == 0)
				{
					timeAttack = now;
					SetState(TGUARD_STATE_ATTACK);
				}
				else if (now - timeAttack > 590)
				{
					timeAttack = 0;
					resetAniAttack();
				}
			}
		}
		else {
			SetState(TGUARD_STATE_IDLE);
		}
	}
	guardSword->Update(dt, coObject);
}

void ThinPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDead) {
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else {
		int boxWidth = THIN_GUARD_BBOX_WIDTH;
		int boxHeight = THIN_GUARD_BBOX_HEIGHT;
		left = x;
		right = left + boxWidth;
		top = y;
		bottom = top + boxHeight;
		/*switch (state)
		{
		case TGUARD_STATE_WALK:

			break;
		case TGUARD_STATE_ATTACK:
			boxWidth = THIN_GUARD_ATTACK_BBOX_WIDTH;
			boxHeight = THIN_GUARD_ATTACK_BBOX_HEIGHT;
			break;
		case TGUARD_STATE_SURPRISE:
			boxWidth = THIN_GUARD_SURPRISE_BBOX_WIDTH;
			boxHeight = THIN_GUARD_SURPRISE_BBOX_HEIGHT;
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
		}*/
	}
}

void ThinPalaceGuard::SetState(int stateNew)
{
	CEnemy::SetState(stateNew);
	switch (stateNew)
	{
	case TGUARD_STATE_IDLE:
		vx = 0;
		break;
	case TGUARD_STATE_WALK:
		if (nx > 0)
		{
			vx = GUARD_WALKING_SPEED;
		}
		else {
			vx = -GUARD_WALKING_SPEED;
		}
		break;
	case TGUARD_STATE_ATTACK:
		vx = 0;
		break;
	case TGUARD_STATE_SURPRISE:
		timeBeAttack = GetTickCount();
		vx = 0;
		break;
	default:
		break;
	}
}

void ThinPalaceGuard::Render()
{
	if (!isDead) {
		int posX = x, posY = y;
		switch (state)
		{
		case TGUARD_STATE_IDLE:
			if (nx > 0)
			{
				ani = THIN_GUARD_ANI_IDLE_RIGHT;
			}
			else {
				ani = THIN_GUARD_ANI_IDLE_LEFT;
			}
			break;
		case TGUARD_STATE_WALK:
			if (nx > 0)
			{
				ani = THIN_GUARD_ANI_WALK_RIGHT;
			}
			else {
				ani = THIN_GUARD_ANI_WALK_LEFT;
			}
			break;
		case TGUARD_STATE_ATTACK:
			posY = y;
			if (nx > 0)
			{
				ani = THIN_GUARD_ANI_ATTACK_RIGHT;
			}
			else {
				ani = THIN_GUARD_ANI_ATTACK_LEFT;
			}
			break;
		case TGUARD_STATE_SURPRISE:
			posY = y;
			if (nx > 0)
			{
				ani = THIN_GUARD_ANI_SURPRISE_RIGHT;
			}
			else {
				ani = THIN_GUARD_ANI_SURPRISE_LEFT;
			}
			break;
		default:
			break;
		}

		animations[ani]->Render(posX, posY);
		RenderBoundingBox();

		guardSword->Render();
	}
}

void ThinPalaceGuard::resetAniAttack()
{
	animations[THIN_GUARD_ANI_ATTACK_RIGHT]->reset();
	animations[THIN_GUARD_ANI_ATTACK_LEFT]->reset();
}

void ThinPalaceGuard::resetAniSurprise()
{
	animations[THIN_GUARD_ANI_SURPRISE_RIGHT]->reset();
	animations[THIN_GUARD_ANI_SURPRISE_LEFT]->reset();
}

ThinPalaceGuard::ThinPalaceGuard() : CEnemy()
{
	guardSword = new GuardSword();

	width = THIN_GUARD_BBOX_WIDTH;
	height = THIN_GUARD_BBOX_HEIGHT;

	hp = THIN_GUARD_MAX_HP;

	AddAnimation(201);		// idle right
	AddAnimation(202);		// idle left

	AddAnimation(203);		// walk right
	AddAnimation(204);		// walk left

	AddAnimation(205);		// attack right
	AddAnimation(206);		// attack left

	AddAnimation(207);		// surprise right
	AddAnimation(208);		// surprise left

}
ThinPalaceGuard::~ThinPalaceGuard() {

}