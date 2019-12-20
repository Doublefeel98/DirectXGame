#include "Spitfire.h"
#include "Define.h"
#include "Aladdin.h"
void Spitfire::Render()
{
}

void Spitfire::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	Aladdin* aladdin = Aladdin::GetInstance();
	if (aladdin->y + ALADDIN_BBOX_HEIGHT <= this->y) {
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

void Spitfire::Update(DWORD dt)
{
}
