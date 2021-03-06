#include "Candle.h"

Candle::Candle()
{
	collisionEffect = new CollisionEffect();
	deadEffect = new DeadEffect();

	isEnable = true;
}

void Candle::Render()
{
	if (this->isEnable)
	{
		animation_set->at(0)->Render(x, y);
		RenderBoundingBox();
	}


	collisionEffect->Render();
	deadEffect->Render();
}

void Candle::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + 8;
	b = y + 16;
}

void Candle::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	if (isEnable)
	{
		collisionEffect->SetPosition(x + 8, y + 5);
		deadEffect->SetPosition(x + 8, y - 2);
	}

	collisionEffect->Update(dt);
	deadEffect->Update(dt);
}
