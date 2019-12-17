#include "Sword.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "../Framework/Enemy.h"
#include "../Framework/debug.h"
#include "Aladdin.h"
Sword::Sword()
{
	x = -5;
	y = -5;
	width = SWORD_BBOX_WIDTH;
	height = SWORD_BBOX_HEIGHT;
	isEnable = false;
	vx = 0;
	vy = 0;
	damage = 1;
}

Sword::~Sword()
{

}

void Sword::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (isEnable) {
		CGameObject::Update(dt);

		for (UINT i = 0; i < coObjects->size(); i++)
		{
			if (dynamic_cast<CEnemy*>(coObjects->at(i))) {

				CEnemy* enemy = dynamic_cast<CEnemy*>(coObjects->at(i));

				float l1, t1, r1, b1, l2, t2, r2, b2;
				GetBoundingBox(l1, t1, r1, b1);
				enemy->GetBoundingBox(l2, t2, r2, b2);

				if (CGame::isColliding(l1, t1, r1, b1, l2, t2, r2, b2)) {
					if ((coObjects->at(i))->nx != 0)
					{
						//enemy->GetColliderEffect()->SetEnable(true);
						if (enemy->isEnable) {
							int typeObject;
							enemy->SetHP(enemy->GetHP() - this->damage);
							typeObject = enemy->GetType();
							switch (typeObject) {
							case OBJECT_BAT:
								enemy->SetState(BAT_STATE_DIE);
								break;
							case OBJECT_NORMAL_PALACE_GUARD:
								enemy->SetState(NGUARD_STATE_SURPRISE);
								break;
							}

							this->isEnable = false;
						}
					}
				}

			}
		}
	}
	else {
		x = -5;
		y = -5;
	}
}

void Sword::Render()
{
	RenderBoundingBox();
}

void Sword::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isEnable) {

		left = x;
		top = y;
		switch (state)
		{
		case SWORD_STATE_RIGHT:
			right = left + SWORD_BBOX_WIDTH;
			bottom = top + SWORD_BBOX_HEIGHT;
			break;
		case SWORD_STATE_LEFT:
			left = x - SWORD_BBOX_WIDTH;
			right = x;
			bottom = top + SWORD_BBOX_HEIGHT;
			break;

		case SWORD_STATE_SIT_RIGHT:
			right = left + SWORD_BBOX_SIT_WIDTH;
			bottom = top + SWORD_BBOX_SIT_HEIGHT;
			break;
		case SWORD_STATE_SIT_LEFT:
			left = x - SWORD_BBOX_SIT_WIDTH;
			right = x;
			bottom = top + SWORD_BBOX_SIT_HEIGHT;
			break;

		case SWORD_STATE_JUMP_RIGHT:
			right = left + SWORD_BBOX_JUMP_WIDTH;
			bottom = top + SWORD_BBOX_JUMP_HEIGHT;
			break;
		case SWORD_STATE_JUMP_LEFT:
			left = x - SWORD_BBOX_JUMP_WIDTH;
			right = x;
			bottom = top + SWORD_BBOX_JUMP_HEIGHT;
			break;

		case SWORD_STATE_LOOKUP_RIGHT:
			right = left + SWORD_BBOX_LOOKUP_WIDTH;
			bottom = top + SWORD_BBOX_LOOKUP_HEIGHT;
			break;
		case SWORD_STATE_LOOKUP_LEFT:
			left = x - SWORD_BBOX_LOOKUP_WIDTH;
			right = x;
			bottom = top + SWORD_BBOX_LOOKUP_HEIGHT;
			break;

		case SWORD_STATE_RUN_RIGHT:
			right = left + SWORD_BBOX_RUN_WIDTH;
			bottom = top + SWORD_BBOX_RUN_HEIGHT;
			break;
		case SWORD_STATE_RUN_LEFT:
			left = x - SWORD_BBOX_RUN_WIDTH;
			right = x;
			bottom = top + SWORD_BBOX_RUN_HEIGHT;
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

void Sword::SetState(int state)
{
	CGameObject::SetState(state);
}
