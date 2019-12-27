#include "Bone.h"
#include "Aladdin.h"
#include "../Framework/debug.h"
#include "Ground.h"
#include "StoneBar.h"
#include "Wood.h"
#include "../Framework/Helper.h"

Bone::Bone() : CGameObject()
{
	AddAnimation(604);
	isEnable = false;

	velocityRamdomX = 0;
	velocityRamdomY = 0;
	aladdin = Aladdin::GetInstance();
	damage = BONE_DAMAGE;
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
		if (state != BONE_STATE_DIE)
			vy += BONE_GRAVITY * dt;


		objects.clear();
		objects.push_back(aladdin);
		for (int i = 0; i < coObjects->size(); i++)
		{
			if (dynamic_cast<Ground*>(coObjects->at(i)) || dynamic_cast<StoneBar*>(coObjects->at(i)) || dynamic_cast<Wood*>(coObjects->at(i)))
			{
				objects.push_back(coObjects->at(i));
			}
		}

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		CalcPotentialCollisions(&objects, coEvents);

		// No collision occured, proceed normally
		if (coEvents.size() == 0)
		{
			x += dx;
			y += dy;
		}
		else
		{
			aladdin->EnemyHurted(damage);

			isEnable = false;
		}

		// clean up collision events
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}
	else {
		x = 0;
		y = 0;
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
	if (isEnable)
	{
		left = x;
		top = y;
		right = left + BONE_BBOX_WIDTH;
		bottom = top + BONE_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}

}

void Bone::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BONE_STATE_FLY:
		nx = Helper::random(0, 1) == 0 ? -1 : 1;

		velocityRamdomX = Helper::float_rand(BONE_MIN_SPEED_X, BONE_MAX_SPEED_X);
		velocityRamdomY = Helper::float_rand(BONE_MIN_SPEED_Y, BONE_MAX_SPEED_Y);

		DebugOut(L"[INFO] bone nx: %d\n", nx);

		DebugOut(L"[INFO] bone velocityRamdomX: %f\n", velocityRamdomX);
		DebugOut(L"[INFO] bone velocityRamdomY: %f\n", velocityRamdomY);


		vx = nx * velocityRamdomX;
		vy = -velocityRamdomY;
		timeStartFly = GetTickCount();
		break;
		//case BONE_STATE_THROW:
		//	vx = velocityRamdomX;
		//	vy = 0;
		//	break;
	}
}


