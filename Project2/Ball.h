#pragma once
#ifndef Ball_H
#define Ball_H
#include"ActionObject.h"
#include"Aladin.h"

#define MAX_HP 3

#define WIDTH 30
#define HEIGHT 30

class Ball :public ActionObject {
private:
	int center_region_y;
public:
	Ball();
	Ball(int x, int y, Direction d);
	~Ball();

	void Update(DWORD dt, vector<Object*>* list);
	void Render();
	void LoadResource();

	BoundingBox GetBoundingBox();
	void SetState(State s);
	void SetDirection(Direction d);
	void Reset(int x, int y, Direction d);
};

#endif // !Ball