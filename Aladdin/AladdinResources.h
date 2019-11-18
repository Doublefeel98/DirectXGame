#pragma once
#include "../Framework/Scene.h";
#include "ScoreBoard.h";
#include "Define.h"
class AladdinResources
{
public:
	AladdinResources();
	~AladdinResources();
	void Load(string file, vector<LPGAMEOBJECT>* listObject);
	void LoadObject(int id, int type, float x, float y, int width, int height, vector<LPGAMEOBJECT>* listObject);
};

