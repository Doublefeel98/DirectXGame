#include "HP.h"

void HP::Render()
{
	int ani = 8;
	switch (hp)
	{
	case 8:
		ani = 0;
		break;
	case 7:
		ani = 1;
		break;
	case 6:
		ani = 2;
		break;
	case 5:
		ani = 3;
		break;
	case 4:
		ani = 4;
		break;
	case 3:
		ani = 5;
		break;
	case 2:
		ani = 6;
		break;
	case 1:
		ani = 7;
		break;
	case 0:
		ani = 8;
		break;
	default:
		break;
	}

	animations[ani]->Render(x, y, 255, false);
}

void HP::Update(int hp)
{
	this->hp = hp;
}

void HP::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}


HP::HP(int hp)
{
	this->hp = hp;
	AddAnimation(-100);		// HP 1
	AddAnimation(-101);		// HP 2
	AddAnimation(-102);		// HP 3
	AddAnimation(-103);		// HP 4
	AddAnimation(-104);		// HP 5
	AddAnimation(-105);		// HP 6
	AddAnimation(-106);		// HP 7
	AddAnimation(-107);		// HP 8
	AddAnimation(-108);		// HP 9
}
