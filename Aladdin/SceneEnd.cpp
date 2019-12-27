#include "SceneEnd.h"

#include "../Framework/debug.h"

SceneEnd::SceneEnd()
{
	sprites = CSprites::GetInstance();
	endBackground = sprites->Get(91000);
	complete = sprites->Get(91100);

	x = 65;
	y = 140;

	time = 0;
	timeDelay = 0;
	isDelay = false;
}

void SceneEnd::Render()
{
	endBackground->DrawWithoutCamera(0, 0);
	complete->DrawWithoutCamera(40, 20);
}

void SceneEnd::Update(DWORD dt)
{
	//if (isChangeScene)
	//{
	//	DWORD now = GetTickCount();
	//	if (time == 0)
	//	{
	//		time = now;
	//	}
	//	else {
	//		if (now - time > 1000)
	//		{
	//			CSceneManager::GetInstance()->ChangeScene(new SceneStart());
	//		}
	//		else if (timeDelay == 0) {
	//			timeDelay = now;
	//			isDelay = !isDelay;
	//		}
	//		else if (now - timeDelay > 100)
	//		{
	//			timeDelay = now;
	//			isDelay = !isDelay;
	//		}
	//	}
	//}
}

void SceneEnd::DestroyAll()
{
}
