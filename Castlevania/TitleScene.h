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

	vector<int> listIdTextures;
	vector<int> listIdSprites;
	vector<int> listIdAnimations;
	vector<int> listIdAnimationSets;

	void _ParseSection_TEXTURES(string line);
	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);
	void _ParseSection_SETTINGS(string line);
	void _ParseSection_ANIMATION_SETS(string line);

	bool is_switch_scene;
	DWORD time_switch_scene;
public:
	friend class CPlayScenceKeyHandler;
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
