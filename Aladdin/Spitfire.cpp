#include "Spitfire.h"
#include "Define.h"
#include "Aladdin.h"
#include <algorithm>

Spitfire::Spitfire() : CGameObject()
{
	aladdin = Aladdin::GetInstance();
	for (int i = 0; i < 3; i++)
	{
		fires[i] = new Fire();
	}
	isEnable = false;
	isEnableFire = false;
}
Spitfire::~Spitfire()
{
}
void Spitfire::Render()
{
	if (isEnableFire)
	{
		for (int i = 0; i < 3; i++)
		{
			fires[i]->Render();
		}
	}

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

void Spitfire::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	CGameObject::Update(dt);

	if (isEnableFire)
	{
		for (int i = 0; i < 3; i++)
		{
			fires[i]->Update(dt);
		}

		if (isEnable)
		{
			float rePosX = 0;
			for (int i = 0; i < 3; i++)
			{
				if (!fires[i]->IsEnable())
				{
					int posX = aladdin->x;
					if (posX < x)
					{
						posX = x;
					}
					else if (posX >= x + width - FIRE_BBOX_WIDTH)
					{
						posX = x + width - FIRE_BBOX_WIDTH;
					}
					if (rePosX != 0)
					{
						if (abs(posX - rePosX) < FIRE_BBOX_WIDTH)
						{
							break;
						}
					}
					fires[i]->SetEnable(true);
					fires[i]->SetPosition(posX, y - FIRE_BBOX_HEIGHT);
					break;
				}
				else {
					rePosX = fires[i]->x;
				}
			}
			isEnable = false;
		}
	}
}
