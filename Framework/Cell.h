#pragma once
#include "GameObject.h"
class Cell
{
	int iD;
	vector <LPGAMEOBJECT> listObj;
	vector <int> listIdObj;
public:
	Cell();
	~Cell();
	void Insert(LPGAMEOBJECT object); 
	void InsertIdObject(int idObject);
	vector<LPGAMEOBJECT> GetListObjects() { return listObj; }
	vector <int> GetListIdObjects() { return listIdObj; }
};

class Cell;
typedef Cell * LPCELL;