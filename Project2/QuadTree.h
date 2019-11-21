#pragma once
#ifndef QuadTree_H
#define QuadTree_H
#include<map>
#include"Node.h"
#include"Texture.h"
#include"Bat.h"
#include"Global.h"
#include"Bat.h"
#include"Apple.h"
#include"Guard.h"
#include"Skeleton.h"
#include"Stone.h"
#include"Face.h"
#include"Vase.h"
#include"Trap.h"
#include"Penny.h"
#include"Heart.h"
#include"Ball.h"
//#include"VirtualObject.h"
enum {
	QAPPLE,
	QBAT,
	QGUARD,
	QSKELETON,
	QSTONE,
	QFACE,
	QVASE,
	QTRAP,
	QPENNY,
	QHEART,
	QBALL,
};
using namespace std;
class QuadTree {
private:
	static QuadTree* instance;
	map<int, Node*> Nodes;
	map<int, Object*> Objects;

public:
	QuadTree();
	~QuadTree();

	static QuadTree* Instance();
	void LoadObjects();
	void LoadNodes();
	void BuildTree();

	Object* CreateObject(int id, int x, int y, int d);
	int CountWords(string st);
	vector<Object*> GetObjects(Box cam);
};
#endif // !QuadTree_H
