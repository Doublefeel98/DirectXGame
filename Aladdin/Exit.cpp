#include "Exit.h"
#include "Define.h"

Exit::Exit()
{
	AddAnimation(2060);		//exit
}

void Exit::Render()
{
	animations[0]->Render(x, y);
}

void Exit::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + EXIT_BBOX_WIDTH;
	b = y + EXIT_BBOX_HEIGHT;
}
