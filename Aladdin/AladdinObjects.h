#pragma once
#include "../Framework/Scene.h";
#include "ScoreBoard.h";
#include "Define.h"
#include"WreckingBall.h"
#include"Trap.h"
#include"Brick.h"
#include"Stone.h"
#include"Bat.h"
#include"NormalPalaceGuard.h"
#include"ExplodingSkeleton.h"
#include"Penny.h"
#include"ThrowApples.h"
#include"Vase.h"
#include"ThinPalaceGuard.h"
#include"GenieBonusLevel.h"
#include"Heart.h"
#include"Apple.h"
class AladdinObjects
{
public:
	AladdinObjects();
	~AladdinObjects();
	void Load(string file, vector<LPGAMEOBJECT>* listObject);
	void LoadListObject(string file, vector<LPGAMEOBJECT>* listObject);
	void LoadObject(int id, int type, float x, float y, vector<LPGAMEOBJECT>* listObject);
	void LoadObject(int id, int type, float x, float y, int width, int height, int delay, vector<LPGAMEOBJECT>* listObject);
};

