#pragma once
#include "Scene.h"
class CSceneManager
{
private:
	CSceneManager();
	static CSceneManager* __instance;
	CScene* currentScene;
public:
	static CSceneManager* GetInstance();
	~CSceneManager();

	CScene* GetCurrentScene();
	void Update(float dt);
	void ChangeScene(CScene* scene);
};

