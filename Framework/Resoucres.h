#include <string>
#include <iostream>
#include <fstream>
#include "GameObject.h"

class CResoucres
{
public:
	void Load(string file, vector<LPGAMEOBJECT>* listObject);
	virtual void LoadObject(int id, int type, float x, float y, int width, int height, vector<LPGAMEOBJECT>* listObject) = 0;
	CResoucres();
	~CResoucres();
};
