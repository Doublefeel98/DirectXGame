#include "StoneBar.h"

void StoneBar::Render()
{
}

void StoneBar::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (isEnable) {
		l = x;
		t = y;
		r = x + width;
		b = y + height;
	}
	else {
		l = 0;
		t = 0;
		r = 0;
		b = 0;
	}
}

void StoneBar::Update(DWORD dt)
{
}
