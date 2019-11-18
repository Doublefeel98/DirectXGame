#pragma once
#include "GameObject.h"
#include <vector>
#include "Game.h"
#include "Cell.h"
#include "Camera.h"

class Grid
{
	friend class CGameObject;
	int widthCell;
	int heightCell;
	LPCELL *cells;
	int rows;
	int columns;
public:
	Grid(int widthmap, int heightmap, int screenWidth, int screenHeight);
	~Grid();
	void Add(vector <LPGAMEOBJECT> *listObject);
	void GetListOfObjects(vector<LPGAMEOBJECT> *list_object, int screenWidth, int screenHeight);
};

