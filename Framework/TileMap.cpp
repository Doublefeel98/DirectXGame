#include "TileMap.h"
#include "Camera.h"
#include "../Framework/Helper.h"


TileMap::TileMap(float _width, float _height, CSprite *_sprite, float _tileWidth, float _tileHeight)
{
	width = _width;
	height = _height;
	sprite = _sprite;

	tileWidth = _tileWidth;
	tileHeight = _tileHeight;

	spritePerRow =  (sprite->right - sprite->left + 1)/ tileWidth;

	rows = height / tileHeight;
	cols = width / tileWidth;
	matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];
}


TileMap::~TileMap()
{
	if (matrix)
	{
		for (int i = 0; i < rows; i++)
		{
			delete matrix[i];
		}
		delete matrix;
		matrix = nullptr;
	}

	if (sprite)
	{
		delete sprite;
		sprite = nullptr;
	}
}

void TileMap::LoadListTileFromFile(const char *file)
{
	fstream pFile;
	pFile.open(file, fstream::in);
	string lineString;
	int *posSpace = new int[cols];
	string subString;
	int i = 0;

	std::vector<std::string> listRow;

	while (pFile.good())
	{
		getline(pFile, lineString);
		if (lineString.find("END") != string::npos)
			break;

		//for (int j = 0; j < cols; j++)
		//{
		//	if (j == 0)
		//	{
		//		posSpace[0] = lineString.find(" ", 0);
		//		subString = lineString.substr(0, posSpace[0]);
		//		int id = atoi(subString.c_str());
		//		matrix[i][j] = id;
		//	}
		//	else
		//	{	
		//		posSpace[j] = lineString.find(" ", posSpace[j - 1] + 1);
		//		subString = lineString.substr(posSpace[j - 1] + 1, posSpace[j] - (posSpace[j - 1] + 1));
		//		int id = atoi(subString.c_str());
		//		matrix[i][j] = id;
		//	}
		//}

		listRow = Helper::split(lineString, ',');
		for (int j = 0; j < cols; j++)
		{
			int id = atoi(listRow[j].c_str());
			matrix[i][j] = id;
		}
		i++;
	}
}

void TileMap::Render(int screenWidth, int screenHeight)
{
	RECT rect;
	D3DXVECTOR3 pos;

	CCamera* camera = CCamera::GetInstance();
	D3DXVECTOR3 cameraPosition = camera->GetCameraPosition();
	int rowStart;
	int rowEnd;
	int colStart;
	int colEnd;
	if ((cameraPosition.y / tileHeight) < 0)
		rowStart = 0;
	else
		rowStart=(cameraPosition.y / tileHeight);

	if (((cameraPosition.y + screenHeight) / tileHeight + 1) >rows)
		rowEnd = rows - 1;
	else
		rowEnd = (cameraPosition.y + screenHeight) / tileHeight + 1;

	if ((cameraPosition.x / tileWidth)<0)
		colStart = 0;
	else
		colStart = (cameraPosition.x / tileWidth);

	if (((cameraPosition.x + screenWidth) / tileWidth  + 1) > cols)
		colEnd = cols - 1;
	else
		colEnd = (cameraPosition.x + screenWidth) / tileWidth + 1;

	for (int i = rowStart; i < rowEnd; i++)
	{
		for (int j = colStart; j < colEnd; j++)
		{
			rect.left = (matrix[i][j] % spritePerRow) * tileWidth;
			rect.top = (matrix[i][j] / spritePerRow) * tileHeight;
			rect.right = rect.left + tileWidth;
			rect.bottom = rect.top + tileHeight;
			pos.x = j * tileWidth;
			pos.y = i * tileHeight;
			pos.z = 0;
			sprite->Draw(pos, rect);
		}
	}
}
