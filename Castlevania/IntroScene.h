#pragma once
#include "../Framework/Scence.h"
#include "Simon.h"
#include "ScoreBoard.h"
#include "BatIntro.h"
#include "Helicopter.h"


#define SCENE_INTRO_LIVE_TIME	1500

class IntroScene : public CScene
{
protected:
	Simon* player;
	ScoreBoard* scoreBoard;
	LPSPRITE background;

	BatIntro* batIntro1;
	BatIntro* batIntro2;
	Helicopter* helicopter;
	vector<LPGAMEOBJECT> objects;

	DWORD timeDelay;

	void _ParseSection_SETTINGS(string line);
	float background_x, background_y;

public:
	friend class TitleSceneKeyHandler;
	IntroScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
};

class IntroSceneKeyHandler : public CScenceKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	IntroSceneKeyHandler(CScene* s) :CScenceKeyHandler(s) {};
};
