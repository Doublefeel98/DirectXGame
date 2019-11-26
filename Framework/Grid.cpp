#include "Grid.h"
#include "debug.h"

bool Grid::checkExistCell(int cellX, int cellY)
{
	if (cellX < 0 || cellX >= rows) return false;
	if (cellY < 0 || cellY >= columns) return false;
	return true;
}

Grid::Grid(int widthmap,int heightmap, int screenWidth, int screenHeight)
{
	this->heightCell = screenHeight / 2;
	this->widthCell = screenWidth / 2;
	rows = heightmap / heightCell;
	columns = widthmap / widthCell;
	cells = new Cell*[rows];
	for (int i = 0; i < rows; i++)
		cells[i] = new Cell[columns];
}



Grid::~Grid()
{
}

void Grid::Add(vector <LPGAMEOBJECT> *listObject)
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
		float left, top, right, bottom;
		left = object->x;
		top = object->y;
		right = left + object->GetWidth();
		bottom = top + object->GetHeight();

		int cellLeft = (int)(left / widthCell) - 1;
		int cellRight = (int)(right / widthCell) - 1;
		int cellTop = (int)(top / heightCell) - 1;
		int cellBottom = (int)(bottom / heightCell) - 1;

		if (cellLeft == cellRight)
		{
			if (cellTop == cellBottom)
			{
				if(checkExistCell(cellLeft, cellTop))
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

void Grid::GetListOfObjects(vector<LPGAMEOBJECT>* list_object, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	CCamera* camera = CCamera::GetInstance();
	list_object->clear();
	int xs, ys;
	int xe, ye;
	int i, j, k;
	xs = (int)camera->GetCameraPosition().x / widthCell;
	ys = (int)camera->GetCameraPosition().y / heightCell;

	xe = (int)(camera->GetCameraPosition().x + SCREEN_WIDTH) / widthCell;
	ye = (int)(camera->GetCameraPosition().y + SCREEN_HEIGHT) / heightCell;
	if (xe == columns-1)
		xe += 1;
	for (i = ys; i < ye; i++)
	for (j = xs; j < xe; j++)
	{
		if (cells[i][j].GetListObjects().size() != 0)
			for (k = 0; k < cells[i][j].GetListObjects().size(); k++)
			{
				LPGAMEOBJECT e = cells[i][j].GetListObjects()[k];
				list_object->push_back(e);
			}
	}
}
