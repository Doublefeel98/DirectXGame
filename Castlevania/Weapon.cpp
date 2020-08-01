#include "Weapon.h"
#include "Simon.h"
#include "Torch.h"
#include "Candle.h"
#include "../Framework/Ground.h"
#include "../Framework/BoundingMap.h"

#define SUBWEAPON_SPEED_X 0.1f


void Weapon::_handleLogicCollisionEnemy(Enemy* enemy)
{
	if (enemy->nx != 0)
	{
		if (enemy->isEnable) {
			vx = 0;
			enemy->Hurted(this->damage);
			enemy->GetCollisionEffect()->SetEnable(true);
			if (dynamic_cast<Dagger*>(this)) {
				this->isEnable = false;
			}
		}
	}
}
void Weapon::_checkAABB(vector<LPGAMEOBJECT>* coObjects)
{
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Enemy*>(coObjects->at(i))) {

			Enemy* enemy = dynamic_cast<Enemy*>(coObjects->at(i));

			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			enemy->GetBoundingBox(l2, t2, r2, b2);

			if (CGame::IsColliding(l1, t1, r1, b1, l2, t2, r2, b2)) {
				_handleLogicCollisionEnemy(enemy);
			}

		}

		else if (dynamic_cast<Torch*>(coObjects->at(i))) {
			Torch* torch = dynamic_cast<Torch*>(coObjects->at(i));
			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			torch->GetBoundingBox(l2, t2, r2, b2);

			if (CGame::IsColliding(l1, t1, r1, b1, l2, t2, r2, b2)) {
				if (torch->isEnable) {
					torch->GetCollisionEffect()->SetEnable(true);
					torch->GetDeadEffect()->SetEnable(true);
					torch->isEnable = false;
					torch->isDead = true;
				}
			}
		}
		else if (dynamic_cast<Candle*>(coObjects->at(i))) {

			Candle* candle = dynamic_cast<Candle*>(coObjects->at(i));
			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			candle->GetBoundingBox(l2, t2, r2, b2);

			if (CGame::IsColliding(l1, t1, r1, b1, l2, t2, r2, b2)) {
				if (candle->isEnable) {
					candle->GetCollisionEffect()->SetEnable(true);
					candle->GetDeadEffect()->SetEnable(true);
					candle->isEnable = false;
					candle->isDead = true;
				}
			}
		}
	}
}
void Weapon::_checkSweptAABB(vector<LPGAMEOBJECT>* coObjects)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	if (isEnable)
		CalcPotentialCollisions(coObjects, coEvents);

	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		float rdx = 0;
		float rdy = 0;

		// TODO: This is a very ugly designed function!!!!
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny, rdx, rdy);


		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];

			if ((dynamic_cast<Enemy*>(e->obj))) {
				Enemy* enemy = dynamic_cast<Enemy*>(e->obj);
				_handleLogicCollisionEnemy(enemy);
			}

			else if (dynamic_cast<Torch*>(e->obj)) {
				Torch* torch = dynamic_cast<Torch*>(e->obj);
				if (torch->isEnable) {
					torch->GetCollisionEffect()->SetEnable(true);
					torch->GetDeadEffect()->SetEnable(true);
					torch->isEnable = false;
					torch->isDead = true;
				}
			}
			else if (dynamic_cast<Candle*>(e->obj)) {

				Candle* candle = dynamic_cast<Candle*>(e->obj);
				if (candle->isEnable) {
					candle->GetCollisionEffect()->SetEnable(true);
					candle->GetDeadEffect()->SetEnable(true);
					candle->isEnable = false;
					candle->isDead = true;
				}
			}
			if (dynamic_cast<FireBomb*>(this)) {
				FireBomb* fireBomb = dynamic_cast<FireBomb*>(this);
				if (dynamic_cast<Ground*>(e->obj))
				{
					if (e->ny < 0) {
						fireBomb->IsFiring = true;
					}
				}
			}
		}
	}

	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}
Weapon::Weapon()
{
	isEnable = false;
}

Weapon::~Weapon()
{
}

void Weapon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (nx > 0)
		vx = SUBWEAPON_SPEED_X;
	else if (nx < 0)
		vx = -SUBWEAPON_SPEED_X;

	if (dynamic_cast<FireBomb*>(this))
	{
		FireBomb* fireBomb = dynamic_cast<FireBomb*>(this);
		if (fireBomb->IsFire())
		{
			vx = 0;
			vy = 0;
		}
	}

	CGameObject::Update(dt);
	x += dx;
	y += dy;

	Weapon::_checkAABB(coObjects);
	Weapon::_checkSweptAABB(coObjects);
}

void Weapon::ResetAnimation()
{
	ResetAni(0);
	ResetAni(1);
}

void Weapon::Render()
{
	if (nx > 0)
		animation_set->at(1)->Render(x, y);
	else if (nx < 0)
		animation_set->at(0)->Render(x, y);
}

void Weapon::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}
