#pragma once
#ifndef Skeleton_H
#define Skeleton_H
#include"ActionObject.h"
#include"Aladin.h"

#define MAX_HP 3

#define WIDTH 40
#define HEIGHT 70
#define WIDTH_ATTACK 100

class Skeleton :public ActionObject {
private:
	int center_region_y;
public:
	Skeleton();
	Skeleton(int x, int y, Direction d);
	~Skeleton();

	void Update(DWORD dt, vector<Object*>* list);
	void Render();
	void LoadResource();

	BoundingBox GetBoundingBox();
	void SetState(State s);
	void SetDirection(Direction d);
	void Reset(int x, int y, Direction d);
};

#endif // !SKELETON
