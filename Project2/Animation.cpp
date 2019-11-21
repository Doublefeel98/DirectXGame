#include"Animation.h"
Animation::Animation()
{

}

Animation::~Animation()
{
}

void Animation::Next(State state)
{
	Sprites[state]->Next();
}

void Animation::Render(State state, Direction direction, D3DXVECTOR2 position, D3DXVECTOR2 scale)
{
	if (direction == Direction::LEFT)
		Sprites[state]->DrawFlipX(position.x, position.y);
	else{
		Sprites[state]->Draw(position.x, position.y);
	}
}

void Animation::Refresh(State s)
{
	this->Sprites[s]->Reset();
}