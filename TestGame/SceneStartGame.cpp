#include "SceneStartGame.h"

SceneStartGame::SceneStartGame() : CScene()
{
	changeScene = false;
	camera->SetCameraPosition(0, 0);
}

void SceneStartGame::Render()
{

}

void SceneStartGame::Update(DWORD dt)
{
	batstartgame->Update(dt);
	if (isPress == true)
	{
		CAnimations* animations = CAnimations::GetInstance();
		LPANIMATION ani;
		if (batstartgame->GetAnimation() < 2)
		{
			if (batstartgame->GetAnimation() == 0)
			{
				if (batstartgame->GetCurrentFrame() == 0)
				{
					ani = new CAnimation(65);
					ani->Add(2001);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 1)
				{
					ani = new CAnimation(65);
					ani->Add(2002);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 2)
				{
					ani = new CAnimation(65);
					ani->Add(2003);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 3)
				{
					ani = new CAnimation(65);
					ani->Add(2004);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 4)
				{
					ani = new CAnimation(65);
					ani->Add(2005);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 5)
				{
					ani = new CAnimation(65);
					ani->Add(2006);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 6)
				{
					ani = new CAnimation(65);
					ani->Add(2007);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 7)
				{
					ani = new CAnimation(65);
					ani->Add(2008);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 8)
				{
					ani = new CAnimation(65);
					ani->Add(2009);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 9)
				{
					ani = new CAnimation(65);
					ani->Add(2010);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 10)
				{
					ani = new CAnimation(65);
					ani->Add(2011);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 11)
				{
					ani = new CAnimation(65);
					ani->Add(2012);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 12)
				{
					ani = new CAnimation(65);
					ani->Add(2013);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
			}
			if (batstartgame->GetAnimation() == 1)
			{
				if (batstartgame->GetCurrentFrame() == 0)
				{
					ani = new CAnimation(65);
					ani->Add(2013);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 1)
				{
					ani = new CAnimation(65);
					ani->Add(2014);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
				if (batstartgame->GetCurrentFrame() == 2)
				{
					ani = new CAnimation(65);
					ani->Add(2015);
					animations->Add(2003, ani);
					batstartgame->AddAnimation(2003);
					batstartgame->SetAnimation(2);
				}
			}
		}

		keyStartObject->Update(dt);
		timeDelay += dt;
		if (timeDelay >= SCENE_START_GAME_LIVE_TIME)
		{
			SetChangingScene(true);
		}

	}
}

bool SceneStartGame::GetChangingScene()
{
	return CScene::GetChangingScene();
}
void SceneStartGame::SetChangingScene(bool status)
{
	CScene::SetChangingScene(status);
}

void SceneStartGame::DestroyAll()
{
	delete(camera);
	listObject.clear();
	coObjects.clear();
}

SceneStartGame::~SceneStartGame()
{
}
