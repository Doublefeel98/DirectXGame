#pragma once

#include "GameObject.h"

/*
	Object that triggers scene switching
*/
class CPortal : public CGameObject
{
	int scene_id;	// target scene to switch to
	int position;

	int width;
	int height;
public:
	CPortal(float _x, float _y, int _with, int _height, int scene_id, int position);
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	int GetSceneId() { return scene_id; }
	int GetPosistionSimon() { return position; }
};
