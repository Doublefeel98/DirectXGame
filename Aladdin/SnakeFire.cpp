#include "SnakeFire.h"
#include "../Framework/Game.h"
#include "../Framework/MapCollision.h"
#include "Ground.h"

SnakeFire::SnakeFire()
{
	AddAnimation(802);
	AddAnimation(803);

	isEnable = true;
	aladdin = Aladdin::GetInstance();
	damage = FIRE_SNAKE_DAMAGE;

	vy = 0;
}

SnakeFire::~SnakeFire()
{
}

void SnakeFire::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	if (isEnable)
	{
		// Calculate dx, dy 
		CGameObject::Update(dt);

		vy += 0.00025f * dt;

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		objects.clear();
		objects.push_back(aladdin);

		for (int i = 0; i < colliable_objects->size(); i++)
		{
			objects.push_back(colliable_objects->at(i));
		}

		CalcPotentialCollisions(&objects, coEvents);

		// No collision occured, proceed normally
		if (coEvents.size() == 0)
		{
			x += dx;
			y += dy;
		}
		else
		{
			float min_tx, min_ty, nx = 0, ny;

			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

			x += dx;


			// Collision logic with Goombas
			for (UINT i = 0; i < coEventsResult.size(); i++)
			{
				LPCOLLISIONEVENT e = coEventsResult[i];

				if (dynamic_cast<MapCollision*>(e->obj)) // if e->obj is Goomba 
				{
					MapCollision* mapCollision = dynamic_cast<MapCollision*>(e->obj);

					isEnable = false;
				}
				else if (dynamic_cast<Aladdin*>(e->obj))
				{
					if (aladdin->untouchable == 0 && !aladdin->IsEnemyHurt)
					{
						aladdin->StartHurting(damage);
					}
				}
				else if (dynamic_cast<Ground*>(e->obj))
				{
					y += min_ty * dy + ny * 0.4f;

					//if (nx != 0) vx = 0;
					if (ny != 0) vy = 0;

					if (state == FIRE_SNAKE_STATE_RIGHT)
					{
						vx = 0.17f;
					}
					else {
						vx = -0.17f;
					}
				}
			}
		}

		// clean up collision events
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}
	else {
		x = 0;
		y = 0;
	}
}

void SnakeFire::Render()
{
	if (isEnable)
	{
		animations[state]->Render(x, y);
		RenderBoundingBox();
	}
}

void SnakeFire::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isEnable)
	{
		switch (state)
		{
		case FIRE_SNAKE_STATE_RIGHT:
			if (animations[FIRE_SNAKE_STATE_RIGHT]->currentFrame != -1)
			{
				float witdhSprite = animations[FIRE_SNAKE_STATE_RIGHT]->frames[animations[FIRE_SNAKE_STATE_RIGHT]->currentFrame]->GetSprite()->right -
					animations[FIRE_SNAKE_STATE_RIGHT]->frames[animations[FIRE_SNAKE_STATE_RIGHT]->currentFrame]->GetSprite()->left;

				float heightSprite = animations[FIRE_SNAKE_STATE_LEFT]->frames[animations[FIRE_SNAKE_STATE_RIGHT]->currentFrame]->GetSprite()->bottom -
					animations[FIRE_SNAKE_STATE_RIGHT]->frames[animations[FIRE_SNAKE_STATE_RIGHT]->currentFrame]->GetSprite()->top;

				left = x;
				top = y + FIRE_BBOX_HEIGHT - heightSprite;
				right = left + witdhSprite;
				bottom = top + heightSprite;
			}
			break;
		case FIRE_SNAKE_STATE_LEFT:
			if (animations[FIRE_SNAKE_STATE_LEFT]->currentFrame != -1)
			{
				float witdhSprite = animations[FIRE_SNAKE_STATE_LEFT]->frames[animations[FIRE_SNAKE_STATE_LEFT]->currentFrame]->GetSprite()->right -
					animations[FIRE_SNAKE_STATE_LEFT]->frames[animations[FIRE_SNAKE_STATE_LEFT]->currentFrame]->GetSprite()->left;

				float heightSprite = animations[FIRE_SNAKE_STATE_LEFT]->frames[animations[FIRE_SNAKE_STATE_LEFT]->currentFrame]->GetSprite()->bottom -
					animations[FIRE_SNAKE_STATE_LEFT]->frames[animations[FIRE_SNAKE_STATE_LEFT]->currentFrame]->GetSprite()->top;

				left = x;
				top = y + FIRE_BBOX_HEIGHT - heightSprite;
				right = left + witdhSprite;
				bottom = top + heightSprite;
			}
			break;
		default:
			break;
		}

	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}

void SnakeFire::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case FIRE_SNAKE_STATE_RIGHT:
		vx = FIRE_SNAKE_SPEED;
		nx = 1;
		break;
	case FIRE_SNAKE_STATE_LEFT:
		vx = -FIRE_SNAKE_SPEED;
		nx = -1;
		break;
	default:
		break;
	}
}
