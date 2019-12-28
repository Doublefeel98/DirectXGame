#include "ExplodingSkeleton.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "Aladdin.h"
#include "Sound.h"

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

		if (enableBones)
		{
			for (int i = 0; i < COUNT_BONE; i++)
			{
				bones[i]->Update(dt, coObject);
			}
		}

		nx = this->x >= alaPosition.x ? -1 : 1;

		if (animations[2]->IsLastFrame || animations[3]->IsLastFrame) {
			if (!enableBones)
			{
				if (sound == false) {
					sound = true;
					Sound::getInstance()->playOnce(SKELETON_MUSIC, "skeleton");

				}
				for (int i = 0; i < COUNT_BONE; i++)
				{
					bones[i]->SetPosition(x + SKELETON_BBOX_WIDTH / 2, y + SKELETON_BBOX_HEIGHT / 2);
					bones[i]->SetEnable(true);
					bones[i]->SetState(BONE_STATE_FLY);
				}
				enableBones = true;
			}
		}

		if (abs(this->x - alaPosition.x) < SKELETON_DELTA_X && abs(this->y - alaPosition.y) < ALADDIN_BBOX_HEIGHT)
		{
			SetState(SKELETON_STATE_STAND_UP);
			sound = false;
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

	if (!enableBones)
	{
		left = x;
		top = y;
		right = x + SKELETON_BBOX_WIDTH;
		bottom = y + SKELETON_BBOX_HEIGHT;
	}
	else
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}

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

		if (!enableBones)
		{
			animations[ani]->Render(posX, posY);
			RenderBoundingBox();
		}


		if (enableBones) {
			for (int i = 0; i < COUNT_BONE; i++)
			{
				bones[i]->Render();
			}
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

	for (int i = 0; i < COUNT_BONE; i++)
	{
		bones[i] = new Bone();
	}

	enableBones = false;
}

ExplodingSkeleton::~ExplodingSkeleton() {

}