#include"Smoke.h"

Smoke::Smoke(int x, int y, Direction d) :ActionObject(x, y, WIDTH, HEIGHT, d) {

	center_region_y = y;
	vy = VY;

	this->hitpoints = HP;
	this->destroyed = false;
	this->attack = false;
	this->active = false;

	this->nameObject = SMOKE;
	this->SetState(WAIT);
	LoadResource();
}
Smoke::~Smoke() {

}
void Smoke::Update(DWORD dt, vector<Object*>* list) {
	if (this->destroyed) return;
	if (this->hitpoints <= 0) {
		this->destroyed = true;

	}
	if (this->hitpoints <= 0)
	{
		//this->destroyed = true;
		//Smoke* tmp = new Smoke(this->x, this->y, RIGHT, 0);
		//tmp->SetState(SMOKE);
		return;
	}

}
void Smoke::Render() {
	if (this->destroyed) return;
	ActionObject::Render();
}
void Smoke::LoadResource() {
	MyTexture* texture = Texture::Instance()->GetTexture(TSMOKE);

	vector<RECT*> wait_rect = Texture::Instance()->GetSourceRect(SSMOKE);
	animation->Sprites[State::WAIT] = new Sprite(texture, wait_rect, 1);


}
BoundingBox Smoke::GetBoundingBox() {
	if (this->destroyed) return BoundingBox();
	BoundingBox bound;
	bound.x = x - WIDTH / 2;
	bound.y = y - HEIGHT / 2;
	bound.w = WIDTH;
	bound.h = HEIGHT;
	bound.vx = dx;
	bound.vy = dy;
	return bound;
}
void Smoke::SetState(State s)
{
	this->state = s;
}

void Smoke::SetDirection(Direction d)
{
	this->direction = d;
}
void Smoke::Reset(int x, int y, Direction d, float vx, float vy)
{
	this->vx = (d == LEFT) ? -vx : vx;
	this->vy = -vy;
	this->direction = d;
	this->destroyed = false;
	this->x = x;
	this->y = y;
	this->active = false;
	this->attack = false;

	this->hitpoints = HP;
}