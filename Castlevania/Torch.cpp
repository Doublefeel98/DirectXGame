#include "Torch.h"

Torch::Torch()
{
	collisionEffect = new CollisionEffect();
	deadEffect = new DeadEffect();

	AddAnimation(202);
	isEnable = true;
}

void Torch::Render()
{
	if (this->isEnable)
	{
		animations[0]->Render(x, y);
		RenderBoundingBox();
	}


	collisionEffect->Render();
	deadEffect->Render();
}

void Torch::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + 32;
	b = y + 32;
}

void Torch::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	if (isEnable)
	{
		collisionEffect->SetPosition(x + 16, y + 10);
		deadEffect->SetPosition(x + 16, y - 5);
	}

	collisionEffect->Update(dt);
	deadEffect->Update(dt);
}
