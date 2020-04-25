#pragma once
#include "Scence.h"
#include <unordered_map>
using namespace std;

class CSceneManager
{
private:
	CSceneManager();
	static CSceneManager* __instance;
	unordered_map<int, LPSCENE> scenes;
	int current_scene;

	void _ParseSection_SETTINGS(string line);
	void _ParseSection_SCENES(string line);
public:
	static CSceneManager* GetInstance();
	~CSceneManager();

	void Load(LPCWSTR gameFile);
	LPSCENE GetCurrentScene();
	void SwitchScene(int scene_id);
};


