#include "Wood.h"
#include "Define.h"
#include "Aladdin.h"

Wood::Wood()
{
	isEnable = false;
}

void Wood::Render()
{
}

void Wood::GetBoundingBox(float& l, float& t, float& r, float& b)
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
	/*if (isEnable) {
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
	}*/
}

void Wood::Update(DWORD dt)
{
	Aladdin* aladdin = Aladdin::GetInstance();
	if (aladdin->y + ALADDIN_BBOX_HEIGHT < this->y) {
		isEnable = true;
	}
	else {
		isEnable = false;
	}
}
