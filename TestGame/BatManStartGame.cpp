#include "BatManStartGame.h"

BatManStartGame::BatManStartGame() :CGameObject()
{
	this->AddAnimation(ID_ANI_BATMAN_1);
	this->AddAnimation(ID_ANI_BATMAN_2);
	this->AddAnimation(ID_ANI_BATMAN_3);
	this->AddAnimation(ID_ANI_BATMAN_4);
	this->AddAnimation(ID_ANI_BATMAN_5);
	this->AddAnimation(ID_ANI_BATMAN_6);
}

BatManStartGame::~BatManStartGame()
{

}

void BatManStartGame::Update(DWORD dt)
{
	if (ani == 0)
	{
		getFrame = animations[0];
		if (getFrame->getCurrentFrame() == 12)
			ani = 1;
	}
}

void BatManStartGame::Render()
{
	animations[ani]->Render(x, y);
}

void BatManStartGame::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = t = r = b = 0;
}

int BatManStartGame::GetCurrentFrame()
{
	getFrame = animations[ani];
	return getFrame->getCurrentFrame();
}
