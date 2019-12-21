#include "LifeNumber.h"

void LifeNumber::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	int text;
	for (int i = 0; i < lifeNumber.size(); i++)
	{
		char temp = lifeNumber[i];
		switch (temp)
		{
		case '0':
			text = 20228;
			break;
		case '1':
			text = 20229;
			break;
		case '2':
			text = 20230;
			break;
		case '3':
			text = 20231;
			break;
		case '4':
			text = 20232;
			break;
		case '5':
			text = 20233;
			break;
		case '6':
			text = 20234;
			break;
		case '7':
			text = 20235;
			break;
		case '8':
			text = 20236;
			break;
		case '9':
			text = 20237;
			break;
		default:
			text = -1;
			break;
		}
		if (text != -1)
		{
			//DebugOut(L"[INFO] index: %d\n", i);
			sprites->Get(text)->DrawWithoutCamera(x + i * width, y);
		}
	}
}

void LifeNumber::Update(wstring lifeNumber)
{
	this->lifeNumber = lifeNumber;
}

void LifeNumber::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}

LifeNumber::LifeNumber()
{
	width = 8;
	height = 8;
}
