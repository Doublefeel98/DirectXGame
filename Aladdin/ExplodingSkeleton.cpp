#include "ExplodingSkeleton.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "Aladdin.h"

void ExplodingSkeleton::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CEnemy::Update(dt, coObject);
	if (isDead) {
		x = -5;
		y = -5;
		vx = 0;
		vy = 0;
	}
	else {
		CEnemy::Update(dt, coObject);
		D3DXVECTOR3 alaPosition = Aladdin::GetInstance()->GetPosition();

		if (bones->IsEnable())
		{
			bones->Update(dt, coObject);
		}

		nx = this->x >= alaPosition.x ? -1 : 1;

		if (animations[2]->IsLastFrame || animations[3]->IsLastFrame) {
			bones->SetPosition(x, y);
			bones->SetEnable(true);
			bones->SetState(BONE_STATE_FLY);
		}

		if (abs(this->x - alaPosition.x) < SKELETON_DELTA_X && abs(this->y - alaPosition.y) < SKELETON_DELTA_Y)
		{
			SetState(SKELETON_STATE_STAND_UP);
		}
		else {
			SetState(SKELETON_STATE_WAIT);

			animations[2]->reset();
			animations[3]->reset();
		}
	}
}

void ExplodingSkeleton::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	//if (animations[SKELETON_ANI_WAIT]->currentFrame >= 2 && animations[SKELETON_ANI_WAIT]->currentFrame <= 8) {
	//	left = x;
	//	top = y + 10;
	//	right = left + SKELETON_BBOX_WIDTH_WIDE;
	//	bottom = top + SKELETON_BBOX_HEIGHT;
	//}
	//else {
	//	left = x + 25;
	//	top = y + 10;
	//	right = left + SKELETON_BBOX_WIDTH;
	//	bottom = top + SKELETON_BBOX_HEIGHT;
	//}

	left = x;
	top = y;
	right = x + SKELETON_BBOX_WIDTH;

	if (isDead)
		bottom = y + 0;
	else
		bottom = y + SKELETON_BBOX_HEIGHT;
}
void ExplodingSkeleton::SetState(int state)
{
	CEnemy::SetState(state);
}
void ExplodingSkeleton::Render()
{
	if (isEnable && !isDead)
	{
		int posX = x, posY = y;
		switch (state)
		{
		case SKELETON_STATE_WAIT:
			if (nx > 0)
			{
				ani = SKELETON_ANI_WAIT_RIGHT;
			}
			else {
				ani = SKELETON_ANI_WAIT_LEFT;
			}
			break;
		case SKELETON_STATE_STAND_UP:
			if (nx > 0)
			{
				ani = SKELETON_ANI_STAND_UP_RIGHT;
			}
			else {
				ani = SKELETON_ANI_STAND_UP_LEFT;
			}
			break;
		default:
			break;
		}

		animations[ani]->Render(posX, posY);
		RenderBoundingBox();

		if (bones->IsEnable())
		{
			bones->Render();
		}
	}
}

ExplodingSkeleton::ExplodingSkeleton() : CEnemy()
{
	width = SKELETON_BBOX_WIDTH;
	height = SKELETON_BBOX_HEIGHT;

	hp = SKELETON_MAX_HP;

	AddAnimation(600);		// wait right
	AddAnimation(601);		// wait left

	AddAnimation(602);		// stand up right
	AddAnimation(603);		// stand up left

	bones = new Bone();
}

ExplodingSkeleton::~ExplodingSkeleton() {

}