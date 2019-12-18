#include "Bone.h"
#include "Aladdin.h"

Bone::Bone()
{
	AddAnimation(604);
	isEnable = false;
}

Bone::~Bone()
{

}

void Bone::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (isEnable)
	{
		// Calculate dx, dy 
		CGameObject::Update(dt);

		// Simple fall down
		//vy += BONE_GRAVITY * dt;

		x += dx;
		y += dy;

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		// turn off collision when die 
		//if (state != BONE_STATE_DIE)
		//	CalcPotentialCollisions(coObjects, coEvents);

		//// No collision occured, proceed normally
		//if (coEvents.size() == 0)
		//{
		//	x += dx;
		//	y += dy;
		//}
		//else
		//{
		//	float min_tx, min_ty, nx = 0, ny;

		//	FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		//	// block 
		//	/*x += min_tx * dx + nx * 0.4f;
		//	y += min_ty * dy + ny * 0.4f;

		//	if (nx != 0) vx = 0;
		//	if (ny != 0) vy = 0;*/

		//	// Collision logic with Goombas
		//	for (UINT i = 0; i < coEventsResult.size(); i++)
		//	{
		//		LPCOLLISIONEVENT e = coEventsResult[i];

		//		if (dynamic_cast<Aladdin*>(e->obj)) // if e->obj is Goomba 
		//		{
		//			if (e->nx != 0)
		//			{
		//				/*if (untouchable == 0)
		//				{
		//					if (goomba->GetState() != GOOMBA_STATE_DIE)
		//					{
		//						if (level > MARIO_LEVEL_SMALL)
		//						{
		//							level = MARIO_LEVEL_SMALL;
		//							StartUntouchable();
		//						}
		//						else
		//							SetState(MARIO_STATE_DIE);
		//					}
		//				}*/
		//			}
		//		}
		//	}
		//	isEnable = false;
		//}

		//// clean up collision events
		//for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}
}

void Bone::Render()
{
	if (isEnable)
	{
		animations[0]->Render(x, y);
		RenderBoundingBox();
	}
}

void Bone::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = left + BONE_BBOX_WIDTH;
	bottom = top + BONE_BBOX_HEIGHT;
}

void Bone::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BONE_STATE_FLY:
		vx = BONE_SPEED_X;
		vy = -BONE_SPEED_Y;
		nx = 1;
		break;
	case BONE_STATE_THROW:
		vx = BONE_SPEED_X;
		vy = 0;
		nx = 1;
		break;
	}
}
