#pragma once
#pragma once
#ifndef Map_H_
#define Map_H_

#include"Sprite.h"
#include"Camera.h"
#include<string>
#include<d3dx9.h>
#define WIDTH_MAP 2271
#define HEIGHT_MAP 1127

class Map
{
private:
	MyTexture* texture;
	Sprite* background;
	RECT sourceDraw;

public:
	Map();
	~Map();

	void LoadResource();
	void Render();
};


#endif // !Map_H_