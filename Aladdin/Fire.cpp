#include "Fire.h"
#include "../Framework/Game.h"

Fire::Fire()
{
	AddAnimation(900);

	isEnable = false;
	aladdin = Aladdin::GetInstance();
	objects.push_back(aladdin);
	damage = FIRE_DAMAGE;
}

Fire::~Fire()
{
}

void Fire::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	if (isEnable)
	{

		if (animations[0]->IsLastFrame)
		{
			isEnable = false;

			animations[0]->reset();
			return;
		}

		// Calculate dx, dy 
		CGameObject::Update(dt);

		// Simple fall down
		if (state != BONE_STATE_DIE)
			vy += BONE_GRAVITY * dt;

		float l1, t1, r1, b1, l2, t2, r2, b2;
		GetBoundingBox(l1, t1, r1, b1);
		aladdin->GetBoundingBox(l2, t2, r2, b2);
		if (CGame::isColliding(l1, t1, r1, b1, l2, t2, r2, b2)) {
			/*if (aladdin->GetHP() > 0)
			{
				if (aladdin->untouchable == 0 && !aladdin->IsEnemyHurt)
				{
					aladdin->StartHurting(damage);

					isEnable = false;

				}
			}*/

			if (aladdin->untouchable == 0 && !aladdin->IsEnemyHurt)
			{
				aladdin->StartHurting(damage);

			}
		}

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		CalcPotentialCollisions(&objects, coEvents);

		// No collision occured, proceed normally
		if (coEvents.size() == 0)
		{

		}
		else
		{
			if (aladdin->untouchable == 0 && !aladdin->IsEnemyHurt)
			{
				aladdin->StartHurting(damage);
			}
			/*if (aladdin->GetHP() > 0)
			{
				if (aladdin->untouchable == 0 && !aladdin->IsEnemyHurt)
				{
					aladdin->StartHurting(damage);

					isEnable = false;
				}
			}*/
		}

		// clean up collision events
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}
	else {
		x = 0;
		y = 0;
	}
}

void Fire::Render()
{
	if (isEnable)
	{
		animations[0]->Render(x, y);
		RenderBoundingBox();
	}
}

void Fire::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isEnable)
	{
		left = x;
		top = y;
		right = left + FIRE_BBOX_WIDTH;
		bottom = top + FIRE_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}

void Fire::SetState(int state)
{
}
