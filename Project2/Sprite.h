#pragma once
#ifndef Sprite_H_
#define Sprite_H_
#include <d3d9.h>
#include<d3dx9.h>
#include<vector>
using namespace std;
#include"MyTexture.h"

class Sprite {
public:
	MyTexture* texture;
	int current_frame;
	int number_of_frame;
	int animation_time;
	int animation_count_time;
	vector<RECT*> List_source_rect;
	
	Sprite();
	~Sprite();

	Sprite(const Sprite& sprite);
	Sprite(MyTexture* texture, vector<RECT*> List_source_rect, int animation_t);

	void Next();
	void Reset();
	void Set_current_frame(int index);
	void Draw(int x, int y);
	void DrawFlipX(int x, int y);
	void DrawFlipY(int x, int y);
	void DrawRect(int x, int Y, RECT SrcRect);
	void DrawCurrentFrame(int index, int X, int Y);
	int GetCurrentFrame();
	bool IsFinalFrame();
};
#endif 