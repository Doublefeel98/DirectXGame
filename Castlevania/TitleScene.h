#pragma once
#include "../Framework/Scence.h"
#include "Simon.h"
#include "TextTitleScreen.h"
#include "BatStartGame.h"

#define	SCENE_INTRO_GAME_LIVE_TIME 3000

class TitleScene : public CScene
{
protected:
	LPSPRITE background;
	TextTitleScreen* textTitle;
	BatStartGame* batStartGame;

	void _ParseSection_SETTINGS(string line);

	bool is_switch_scene;
	DWORD time_switch_scene;
public:
	friend class TitleSceneKeyHandler;
	TitleScene(int id, LPCWSTR filePath);
	void SwitchScene();

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
};

class TitleSceneKeyHandler : public CScenceKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	TitleSceneKeyHandler(CScene* s) :CScenceKeyHandler(s) {};
};
