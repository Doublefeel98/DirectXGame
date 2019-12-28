#pragma once
#include "../Framework/Scene.h";
#include "../Framework/SceneManager.h"
#include "ScoreBoard.h";
#include "Define.h"
#include "AladdinObjects.h"
#include "Aladdin.h"
#include "Jafar.h"
#include "Spitfire.h"
#include "Apple.h"
#include "../Framework/Helper.h"
class SceneBoss : public CScene
{
	Aladdin* aladdin;
	AladdinObjects* aladinObjects;
	ScoreBoard* scoreboard;
	vector<Spitfire*> spitFires;
	Jafar* jafar;
	bool IsEnableSpitFire;
	bool isCheck, sound;
public:
	SceneBoss();
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};

