#pragma once
#include "../Framework/Scene.h"
#include "../Framework/SceneManager.h"
#include "ScoreBoard.h"
#include "Simon.h"
#include "CastlevaniaObjects.h"
#include "ScoreBoard.h"
#include "Item.h"

class SceneOutCastle : public CScene
{
	Simon* simon;
	CastlevaniaObjects* castlevaniaObjects;
	ScoreBoard* scoreboard;
	vector<LPITEM> listItems;
public:
	SceneOutCastle();
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};

