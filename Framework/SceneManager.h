#pragma once
#include "Scence.h"
#include "Player.h"
#include <unordered_map>
using namespace std;

class CSceneManager
{
private:
	CSceneManager();
	static CSceneManager* __instance;
	unordered_map<int, LPSCENE> scenes;
	int current_scene;
	int next_scene;

	void _ParseSection_SETTINGS(string line);
	void _ParseSection_SCENES(string line);
	CPlayer* player;
	bool _isSwitchScene;
public:
	void SetPlayer(CPlayer* player);
	static CSceneManager* GetInstance();
	~CSceneManager();

	void Load(LPCWSTR gameFile);
	LPSCENE GetCurrentScene();
	void SwitchScene();
	void BeforeSwitchScene(int scene_id);
	bool IsSwitchScene() { return _isSwitchScene; };
};


