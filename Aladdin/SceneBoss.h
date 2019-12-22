#pragma once
#include "../Framework/Scene.h";
#include "ScoreBoard.h";
#include "Define.h"
#include "AladdinObjects.h"
#include "Aladdin.h"
#include "Jafar.h"
#include "Spitfire.h"
#include "../Framework/MapCollision.h"
class SceneBoss : public CScene
{
	Aladdin* aladdin;
	AladdinObjects* aladinObjects;
	ScoreBoard* scoreboard;
	vector<Spitfire*> spitFires;
	Jafar* jafar;
	bool IsEnableSpitFire;
public:
	SceneBoss(Aladdin* aladdin);
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};

