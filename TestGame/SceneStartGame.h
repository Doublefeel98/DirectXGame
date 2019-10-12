#pragma once
#include "../Framework/Scene.h";
#include "KeyStartObject.h"
#include "BatManStartGame.h"

#define SCENE_START_GAME_LIVE_TIME 3000
class SceneStartGame : public CScene
{
	KeyStartObject* keyStartObject;
	//Scenes* scene;
	BatManStartGame* batstartgame;
	DWORD timeDelay;
public:

	static bool isPress;
public:
	SceneStartGame();
	void Render();
	void Update(DWORD dt);
	bool GetChangingScene();
	void SetChangingScene(bool status);
	void DestroyAll();
	~SceneStartGame();
};

