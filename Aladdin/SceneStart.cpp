#include "SceneStart.h"
#include "../Framework/debug.h"
#include "../Framework/SceneManager.h"
#include "SceneOne.h"
#include "Sound.h"
SceneStart::SceneStart()
{
	sprites = CSprites::GetInstance();
	background = sprites->Get(90000);

	intro = sprites->Get(90100);

	x = 65;
	y = 140;

	time = 0;
	timeDelay = 0;
	isDelay = false;
}

void SceneStart::Render()
{
	background->DrawWithoutCamera(0, 0);
	intro->DrawWithoutCamera(40, 20);

	if (!isDelay)
	{
		sprites->Get(20215)->DrawWithoutCamera(x + 10, y);
		sprites->Get(20217)->DrawWithoutCamera(x + 20, y);
		sprites->Get(20204)->DrawWithoutCamera(x + 30, y);
		sprites->Get(20218)->DrawWithoutCamera(x + 40, y);
		sprites->Get(20218)->DrawWithoutCamera(x + 50, y);

		sprites->Get(20200)->DrawWithoutCamera(x + 70, y);
		sprites->Get(20213)->DrawWithoutCamera(x + 80, y);
		sprites->Get(20224)->DrawWithoutCamera(x + 90, y);

		sprites->Get(20201)->DrawWithoutCamera(x + 110, y);
		sprites->Get(20220)->DrawWithoutCamera(x + 120, y);
		sprites->Get(20219)->DrawWithoutCamera(x + 130, y);
		sprites->Get(20219)->DrawWithoutCamera(x + 140, y);
		sprites->Get(20214)->DrawWithoutCamera(x + 150, y);
		sprites->Get(20213)->DrawWithoutCamera(x + 160, y);
	}
}

void SceneStart::Update(DWORD dt)
{
	if (sound == false) {
		Sound::getInstance()->playRep(MENU_MUSIC, "menu");
		sound = true;
	}
	if (isChangeScene)
	{

		DWORD now = GetTickCount();
		if (time == 0)
		{
			time = now;
		}
		else {
			if (now - time > 1000)
			{
				Sound::getInstance()->playOnce(SELECT_MUSIC, "select");
				Sound::getInstance()->stop("menu");

				CSceneManager::GetInstance()->ChangeScene(new SceneOne());
			}
			else if (timeDelay == 0) {
				timeDelay = now;
				isDelay = !isDelay;
			}
			else if (now - timeDelay > 100)
			{
				timeDelay = now;
				isDelay = !isDelay;
			}
		}
	}
}

void SceneStart::DestroyAll()
{
}
