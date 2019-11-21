#include"Stone.h"
Stone::Stone(int x, int y, Direction d) :ActionObject(x, y, WIDTH,HEIGHT, d)
{
	center_region_y = y;

	this->hitpoints = MAX_HP;
	this->destroyed = false;
	this->nameObject = STONE;
	this->SetState(WAIT);
	LoadResource();
}
Stone::~Stone() {

}
void Stone::Update(DWORD dt, vector<Object*>* list) {
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
void Stone::Render() {
	if (destroyed) return;
	ActionObject::Render();
}
void Stone::LoadResource() {
	MyTexture* texture = Texture::Instance()->GetTexture(TMAP);

	vector<RECT*> wait_rect = Texture::Instance()->GetSourceRect(SSTONE);
	animation->Sprites[State::WAIT] = new Sprite(texture, wait_rect, 1);

}
BoundingBox Stone::GetBoundingBox()
{
	BoundingBox bound;
	bound.x = x - WIDTH / 2;
	bound.y = y - HEIGHT / 2;
	bound.w = WIDTH;
	bound.h = HEIGHT;
	return bound;
}
void Stone::SetState(State s)
{
	this->state = s;
}

void Stone::SetDirection(Direction d)
{
	this->direction = d;
}
void Stone::Reset(int x, int y, Direction d) {
	this->direction = d;
	this->x = x;
	this->y = y;
	this->hitpoints = MAX_HP;
	this->destroyed = false;
	this->nameObject = STONE;
}