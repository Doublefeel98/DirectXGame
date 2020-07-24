#pragma once
#include "../Framework/Scence.h"
#include "Simon.h"
class SceneIntro : public CScene
{
protected:
	Simon* player;					// A play scene has to have player, right? 
	StartKeyObject* startkeyobject;
	Scenes* scene;
	Batstartgame* batstartgame;
	DWORD timeDelay;
public:
	friend class CPlayScenceKeyHandler;
	SceneIntro(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
};

class SceneIntroKeyHandler : public CScenceKeyHandler
{
public:
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	SceneIntroKeyHandler(CScene* s) :CScenceKeyHandler(s) {};
};

