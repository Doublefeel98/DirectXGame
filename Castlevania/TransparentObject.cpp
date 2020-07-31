#include "TransparentObject.h"

TransparentObject::TransparentObject()
{
	isDead = false;
	isEnable = true;
}

void TransparentObject::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	if (tokens.size() > 9) {
		item_x = atoi(tokens[9].c_str());
		item_y = atoi(tokens[10].c_str());
		is_grow_up = atoi(tokens[11].c_str());
	}
	else {
		item_x = x;
		item_y = y;
		is_grow_up = false;
	}
}

TransparentObject::~TransparentObject()
{

}

void TransparentObject::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{

}

void TransparentObject::Render()
{

}

void TransparentObject::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (!isDead && isEnable)
	{
		l = x;
		t = y;
		r = l + width;
		b = t + height;
	}
}
