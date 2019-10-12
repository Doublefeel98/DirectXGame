#include "KeyStartObject.h"

void KeyStartObject::Update(DWORD dt)
{
	CGameObject::Update(dt);
	timeDisplay += dt;
	if (timeDisplay >= TIME_DISPLAY)
	{
		isEnable = !isEnable;
		timeDisplay -= TIME_DISPLAY;
	}
}

void KeyStartObject::Render()
{
	D3DXVECTOR3 pos;
	RECT rect;
	pos = D3DXVECTOR3(x, y, 0);
	rect.left = x;
	rect.top = y;
	rect.right = x + width;
	rect.bottom = y + height;
	CSprites* sprites = CSprites::GetInstance();
	if (isEnable != true)
	{
		sprite = sprites->Get(ID_TEX_BLACK);
		sprite->Draw(pos, rect);
	}
}

void KeyStartObject::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + width;
	b = y + height;
}

KeyStartObject::KeyStartObject(int width, int height)
{
	timeDisplay = 0;
	this->width = width;
	this->height = height;
}

KeyStartObject::~KeyStartObject()
{
}
