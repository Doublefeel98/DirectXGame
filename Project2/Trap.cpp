#include"Trap.h"
Trap::Trap(int x, int y, Direction d) :ActionObject(x, y, WIDTH, HEIGHT, d)
{
	center_region_y = y;

	this->hitpoints = MAX_HP;
	this->destroyed = false;
	this->nameObject = TRAP;
	this->SetState(WAIT);
	LoadResource();
}
Trap::~Trap() {

}
void Trap::Update(DWORD dt, vector<Object*>* list) {
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
void Trap::Render() {
	if (destroyed) return;
	ActionObject::Render();
}
void Trap::LoadResource() {
	MyTexture* texture = Texture::Instance()->GetTexture(TMAP);

	vector<RECT*> wait_rect = Texture::Instance()->GetSourceRect(STRAP);
	animation->Sprites[State::WAIT] = new Sprite(texture, wait_rect, 6);

}
BoundingBox Trap::GetBoundingBox()
{
	BoundingBox bound;
	bound.x = x - WIDTH / 2;
	bound.y = y - HEIGHT / 2;
	bound.w = WIDTH;
	bound.h = HEIGHT;
	return bound;
}
void Trap::SetState(State s)
{
	this->state = s;
}

void Trap::SetDirection(Direction d)
{
	this->direction = d;
}
void Trap::Reset(int x, int y, Direction d) {
	this->direction = d;
	this->x = x;
	this->y = y;
	this->hitpoints = MAX_HP;
	this->destroyed = false;
	this->nameObject = TRAP;
}