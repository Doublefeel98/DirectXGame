#pragma once
#include "../Framework/Scene.h";

class CastlevaniaObjects
{
public:
	CastlevaniaObjects();
	~CastlevaniaObjects();
	void Load(string file, vector<LPGAMEOBJECT>* listObject);
	void LoadObject(int id, int type, float x, float y, int width, int height, int delay, vector<LPGAMEOBJECT>* listObject);
};

