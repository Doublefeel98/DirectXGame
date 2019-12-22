#include "StoneBar.h"
#include "Aladdin.h"
#include "Define.h"

StoneBar::StoneBar()
{
	isEnable = false;
}

void StoneBar::Render()
{
	RenderBoundingBox();
}

void StoneBar::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	Aladdin* aladdin = Aladdin::GetInstance();
	if (aladdin->y + ALADDIN_BBOX_HEIGHT < this->y) {
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
	//if (isEnable) {
	//	l = x;
	//	t = y;
	//	r = x + width;
	//	b = y + height;
	//}
	//else {
	//	l = 0;
	//	t = 0;
	//	r = 0;
	//	b = 0;
	//}
}

void StoneBar::Update(DWORD dt)
{
	Aladdin* aladdin = Aladdin::GetInstance();
	if (aladdin->y + ALADDIN_BBOX_HEIGHT < this->y) {
		isEnable = true;
	}
	else {
		isEnable = false;
	}
}
