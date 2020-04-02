#include "HP.h"

void HP::Render()
{
	if (type == 2)
	{
		sprite->DrawWithoutCamera(x, y);
		sprite->DrawWithoutCamera(x, y + 20);
	}
	else {
		sprite->DrawWithoutCamera(x, y);
	}

}

HP::HP(int type)
{
	this->type = type;
	CSprites* sprites = CSprites::GetInstance();
	switch (this->type)
	{
	case 1:
		sprite = sprites->Get(50000);
		break;
	case 2:
		sprite = sprites->Get(50001);
		break;
	case 3:
		sprite = sprites->Get(50002);
		break;
	}
}

HP::~HP()
{
}