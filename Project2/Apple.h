#pragma once
#ifndef Apple_H
#define Apple_H
#include"ActionObject.h"
#include"Aladin.h"

#define WIDTH 10
#define HEIGHT 10

class Apple :public ActionObject {
private:
	int center_region_y;
public:
	Apple();
	Apple(int x, int y, Direction d);
	~Apple();

	void Update(DWORD dt, vector<Object*>* list);
	void Render();
	void LoadResource();

	BoundingBox GetBoundingBox();
	void SetState(State s);
	void SetDirection(Direction d);
	void Reset(int x, int y, Direction d);
};
#endif