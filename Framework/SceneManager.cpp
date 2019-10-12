#include "SceneManager.h"
CSceneManager* CSceneManager::__instance = NULL;

CSceneManager::CSceneManager()
{
	currentScene = nullptr;
}

CSceneManager::~CSceneManager()
{
}

CSceneManager* CSceneManager::GetInstance()
{
	if (!__instance)
		__instance = new CSceneManager();

	return __instance;
}

CScene* CSceneManager::GetCurrentScene()
{
	return currentScene;
}

void CSceneManager::Update(float dt)
{
	currentScene->Update(dt);
}

void CSceneManager::ChangeScene(CScene* scene)
{
	delete currentScene;

	currentScene = scene;
}