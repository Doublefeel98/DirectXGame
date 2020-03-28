#include "Grid.h"
#include "debug.h"
#include "Helper.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "debug.h"

bool Grid::checkExistCell(int cellX, int cellY)
{
	if (cellX < 0 || cellX >= numXCells) return false;
	if (cellY < 0 || cellY >= numYCells) return false;
	return true;
}

Grid::Grid(int widthmap, int heightmap, int cellSize)
{
	this->cellSize = cellSize;
	numYCells = heightmap / cellSize + ((heightmap % cellSize > 0) ? 1 : 0);
	numXCells = widthmap / cellSize + ((widthmap % cellSize > 0) ? 1 : 0);

	cells = new Cell * [numXCells];
	for (int i = 0; i < numXCells; i++)
		cells[i] = new Cell[numYCells];
}

Grid::Grid(const char* file, int widthmap, int heightmap, int cellSize, vector <LPGAMEOBJECT>* listObject)
{
	this->cellSize = cellSize;
	numYCells = heightmap / cellSize + ((heightmap % cellSize > 0) ? 1 : 0);
	numXCells = widthmap / cellSize + ((widthmap % cellSize > 0) ? 1 : 0);

	cells = new Cell * [numXCells];

	for (int i = 0; i < numXCells; i++)
		cells[i] = new Cell[numYCells];

	fstream pFile;
	pFile.open(file, fstream::in);
	string lineString;
	int i = 0;
	//int id;
	int idObject;

	std::vector<std::string> listInfo;

	int indexX;
	int indexY;

	while (pFile.good())
	{
		getline(pFile, lineString);
		if (lineString.find("END") != string::npos)
			break;

		listInfo = Helper::split(lineString, ' ');
		//id = atoi(listInfo[0].c_str());

		indexX = atoi(listInfo[0].c_str());
		indexY = atoi(listInfo[1].c_str());


		for (int j = 2; j < listInfo.size(); j++)
		{
			idObject = atoi(listInfo[j].c_str());
			DebugOut(L"[INFO] Grid loaded Ok: indexX=%d, indexY=%d, id=%d \n", indexX, indexY, idObject);
			cells[indexX][indexY].Insert(listObject->at(idObject));
			cells[indexX][indexY].InsertIdObject(idObject);
		}
		i++;
	}
}



Grid::~Grid()
{
}

void Grid::Add(vector <LPGAMEOBJECT>* listObject)
{
	LPGAMEOBJECT object;
	float left, top, right, bottom;
	for (int i = 0; i < listObject->size(); i++)
	{
		/*int cellY = (int)(listObject->at(i)->x / widthCell);
		int cellX = (int)(listObject->at(i)->y / heightCell);

		int cellY1 = (int)((listObject->at(i)->x + listObject->at(i)->GetWidth()) / widthCell);
		int cellX1 = (int)((listObject->at(i)->y + listObject->at(i)->GetHeight()) / heightCell);

		if (cellX == cellX1)
		{
			if(cellY!= cellY1)
				for (int k = cellY; k < cellY1; k++)
				cells[cellX][k].Insert(listObject->at(i));
			else if (cellY == cellY1)
				cells[cellX][cellY].Insert(listObject->at(i));
		}
		else if (cellX != cellX1)
		{
			if (cellY != cellY1)
				for (int j = cellX; j < cellX1; j++)
					for (int k = cellY; k < cellY1; k++)
						cells[j][k].Insert(listObject->at(i));
			else if (cellY == cellY1)
			{
				for (int j = cellX; j < cellX1; j++)
					cells[j][cellY].Insert(listObject->at(i));
			}
		}*/

		// DebugOut(L"[INFO] index: %d\n", i);
		//if (i == 49)
		//	continue;

		object = listObject->at(i);
		left = object->x;
		top = object->y;
		right = left + object->GetWidth();
		bottom = top + object->GetHeight();

		int cellLeft = (int)(left / cellSize);
		int cellRight = (int)(right / cellSize);
		int cellTop = (int)(top / cellSize);
		int cellBottom = (int)(bottom / cellSize);

		if (cellLeft == cellRight)
		{
			if (cellTop == cellBottom)
			{
				if (checkExistCell(cellLeft, cellTop))
					cells[cellLeft][cellTop].Insert(object);
			}
			else {
				for (int j = cellTop; j <= cellBottom; j++)
				{
					if (checkExistCell(cellLeft, j))
						cells[cellLeft][j].Insert(object);
				}
			}
		}
		else {
			if (cellTop == cellBottom)
			{
				for (int j = cellLeft; j <= cellRight; j++)
				{
					if (checkExistCell(j, cellTop))
						cells[j][cellTop].Insert(object);
				}
			}
			else
			{
				for (int j = cellLeft; j <= cellRight; j++)
				{
					for (int k = cellTop; k <= cellBottom; k++)
					{
						if (checkExistCell(j, k))
							cells[j][k].Insert(object);
					}
				}
			}
		}
	}
}

void Grid::AddById(vector<LPGAMEOBJECT>* listObject)
{

}

bool checkContainId(vector<LPGAMEOBJECT>* list_object, LPGAMEOBJECT e)
{
	LPGAMEOBJECT temp;
	for (int i = 0; i < list_object->size(); i++)
	{
		temp = list_object->at(i);
		if (temp->id == e->id) {
			return true;
		}
	}
	return false;
}

void Grid::GetListOfObjects(vector<LPGAMEOBJECT>* list_object, int screenWidth, int screenHeight)
{
	CCamera* camera = CCamera::GetInstance();
	list_object->clear();
	int left, top, right, bottom;
	int i, j, k;

	left = (int)camera->GetCameraPosition().x / cellSize;
	top = (int)camera->GetCameraPosition().y / cellSize;

	right = (int)(camera->GetCameraPosition().x + screenWidth) / cellSize
		+ ((int)(camera->GetCameraPosition().x + screenWidth) % cellSize ? 1 : 0);

	bottom = (int)(camera->GetCameraPosition().y + screenHeight) / cellSize
		+ ((int)(camera->GetCameraPosition().y + screenHeight) % cellSize ? 1 : 0);

	LPGAMEOBJECT e;

	for (i = left; i < right; i++)
	{
		for (j = top; j < bottom; j++)
		{
			if (cells[i][j].GetListObjects().size() != 0)
			{
				for (k = 0; k < cells[i][j].GetListObjects().size(); k++)
				{
					e = cells[i][j].GetListObjects().at(k);
					if (!checkContainId(list_object, e)) {
						list_object->push_back(e);
					}
				}
			}
		}
	}

}

