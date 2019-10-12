#pragma once
#include "GameObject.h"
#include <vector>
#include "Game.h"
#include "Cell.h"
#include "Camera.h"

class Grid
{
	friend class CGameObject;
	int cellsizex;
	int cellsizey;
	LPCELL *cells;
	int rows;
	int columns;
public:
	Grid(int widthmap, int heightmap,int cellsizex,int cellsizey);
	~Grid();
	void Add(vector <LPGAMEOBJECT> *listObject);
	void GetListOfObjects(vector<LPGAMEOBJECT> *list_object, int SCREEN_WIDTH, int SCREEN_HEIGHT);
};

