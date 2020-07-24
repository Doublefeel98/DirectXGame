#include "Portal.h"


CPortal::CPortal()
{
	
}

void CPortal::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	this->scene_id = atoi(tokens[9].c_str());
	this->position = atoi(tokens[10].c_str());
}

void CPortal::Render()
{
	RenderBoundingBox();
}

void CPortal::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + width;
	b = y + height;
}
