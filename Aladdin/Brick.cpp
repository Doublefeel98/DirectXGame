#include "Brick.h"

void Brick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CGameObject::Update(dt);

}


void Brick::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}

void Brick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = x + BRICK_BBOX_WIDTH;
	b = y + BRICK_BBOX_HEIGHT;
}

Brick::Brick() :CGameObject() {
	width = BRICK_BBOX_WIDTH;
	height = BRICK_BBOX_WIDTH;

	enabled = false;

	AddAnimation(2040);
}
Brick::~Brick() {

}