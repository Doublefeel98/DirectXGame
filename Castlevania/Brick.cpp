#include "Brick.h"
#include "Define.h"

Brick::Brick()
{
	isEnable = true;
	for (int i = 0; i < 4; i++) {
		listEffect[i] = new BrokenBrickEffect(i);
	}
}

void Brick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	if (state == BRICK_STATE_BROKEN)
	{
		for (int i = 0; i < 4; i++) {
			if (listEffect[i]->isEnable) {
				listEffect[i]->Update(dt);
			}
		}
	}
}

void Brick::Render()
{
	if (state == BRICK_STATE_BROKEN) {
		animation_set->at(0)->Render(x, y);

		for (int i = 0; i < 4; i++) {
			if (listEffect[i]->isEnable) {
				listEffect[i]->Render();
			}
		}
	}

	RenderBoundingBox();
}

void Brick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (state == BRICK_STATE_NORMAL) {
		l = x;
		t = y;
		r = x + 16;
		b = y + 16;
	}
	else {
		l = r = t = b = 0;
	}

}

void Brick::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BRICK_STATE_NORMAL:

		break;
	case  BRICK_STATE_BROKEN:
	{
		isDead = true;
		isEnable = false;
		for (int i = 0; i < 4; i++) {
			listEffect[i]->Enable(x, y);
		}
	}
	break;
	}
}
