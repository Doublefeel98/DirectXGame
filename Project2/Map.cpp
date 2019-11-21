#include"Map.h"
Map::Map() {
	LoadResource();
}
Map::~Map() {

}
void Map::LoadResource() {
	vector<RECT*> source_rect;
	RECT* rect = new RECT();
	rect->top = 0;
	rect->left = 0;
	rect->right = WIDTH_MAP;
	rect->bottom = HEIGHT_MAP;
	source_rect.push_back(rect);
	texture = new MyTexture((char*)"C:\\Users\\ngoho\\Desktop\\map.png", D3DCOLOR_XRGB(0, 0, 0));
	background = new Sprite(texture, source_rect, 1);
}
void Map::Render() {
	float x, y;
	Camera::Instance()->GetCameraPosition(x, y);
	

	y -= ADDITIONS * G_Scale.y;
	y = HEIGHT_MAP * G_Scale.y - y;
	//RECT sourceDraw;

	sourceDraw.top = y / G_Scale.y;
	sourceDraw.left = x / G_Scale.x;
	sourceDraw.right = x / G_Scale.x + G_ScreenWidth / G_Scale.x;
	sourceDraw.bottom = y / G_Scale.y + G_ScreenHeight / G_Scale.y;

	x = G_ScreenWidth / 2;
	y = G_ScreenHeight / 2;
	background->DrawRect(x, y, sourceDraw);
}