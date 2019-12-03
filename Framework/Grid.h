#pragma once
#include "GameObject.h"
#include <vector>
#include "Game.h"
#include "Cell.h"
#include "Camera.h"

class Grid
{
	friend class CGameObject;
	int cellSize;
	LPCELL* cells;
	int numXCells;
	int numYCells;
	bool checkExistCell(int cellX, int cellY);
public:
	Grid(int widthmap, int heightmap, int cellSize);
	Grid(const char* file, int widthmap, int heightmap, int cellSize, vector <LPGAMEOBJECT>* listObject);
	~Grid();
	void Add(vector <LPGAMEOBJECT>* listObject);
	void AddById(vector <LPGAMEOBJECT>* listObject);
	void GetListOfObjects(vector<LPGAMEOBJECT> *list_object, int screenWidth, int screenHeight);
};

