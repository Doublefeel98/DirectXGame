#include"Apple.h"
Apple::Apple(int x, int y, Direction d) :ActionObject(x, y, WIDTH, HEIGHT, d)
{
	center_region_y = y;

	this->destroyed = false;
	this->nameObject = APPLE;
	this->SetState(WAIT);
	LoadResource();
}
Apple::~Apple() {

}
void Apple::Update(DWORD dt, vector<Object*>* list) {
	//float x, y;
	//Aladin::Instance()->GetPosition(x, y);

	if (destroyed) {
		return;
	}
	if (this->hitpoints <= 0)
	{
		this->destroyed = true;
		return;
	}

}
void Apple::Render() {
	if (destroyed) return;
	ActionObject::Render();
}
void Apple::LoadResource() {
	MyTexture* texture = Texture::Instance()->GetTexture(TITEMS);

	vector<RECT*> wait_rect = Texture::Instance()->GetSourceRect(SAPPLE);
	animation->Sprites[State::WAIT] = new Sprite(texture, wait_rect, 1);
}
BoundingBox Apple::GetBoundingBox()
{
	BoundingBox bound;
	bound.x = x - WIDTH / 2;
	bound.y = y - HEIGHT / 2;
	bound.w = WIDTH;
	bound.h = HEIGHT;
	return bound;
}
void Apple::SetState(State s)
{
	this->state = s;
}

void Apple::SetDirection(Direction d)
{
	this->direction = d;
}
void Apple::Reset(int x, int y, Direction d) {
	this->direction = d;
	this->x = x;
	this->y = y;
	this->destroyed = false;
	this->nameObject = APPLE;
}