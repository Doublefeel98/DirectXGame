#include "MapCollision.h"
#include "Camera.h"



MapCollision::MapCollision()
{
	CTextures* textures = CTextures::GetInstance();
	textures->Add(ID_TEX_BBOX, L"textures\\black.png", D3DCOLOR_XRGB(0 ,0 ,0));
}

void MapCollision::Render(Camera * camera)
{
	CSprites * sprites = CSprites::GetInstance();
	sprite = sprites->Get(ID_TEX_TRANSPARENT);
	sprite->Draw(camera, x,y);
}


void MapCollision::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = x;
	t = y;
	r = x + width;
	b = y + height;
}

MapCollision::MapCollision(int width, int height)
{
	this->width = width;
	this->height = height;
}


MapCollision::~MapCollision()
{
}
