#include"Vase.h"

Vase::Vase(int x, int y, Direction d) :ActionObject(x, y, WIDTH, HEIGHT, d) {

	center_region_y = y;
	vy = VY;

	this->hitpoints = HP;
	this->destroyed = false;
	this->attack = false;
	this->active = false;

	this->nameObject = VASE;
	this->SetState(WAIT);
	LoadResource();
}
Vase::~Vase() {

}
void Vase::Update(DWORD dt, vector<Object*>* list) {
	if (this->destroyed) return;
	if (this->hitpoints <= 0) {
		this->destroyed = true;

	}
	if (this->hitpoints <= 0)
	{
		//this->destroyed = true;
		//Smoke* tmp = new Smoke(this->x, this->y, RIGHT, 0);
		//tmp->SetState(VASE);
		return;
	}

}
void Vase::Render() {
	if (this->destroyed) return;
	ActionObject::Render();
}
void Vase::LoadResource() {
	MyTexture* texture = Texture::Instance()->GetTexture(TITEMS);

	vector<RECT*> wait_rect = Texture::Instance()->GetSourceRect(SVASE);
	animation->Sprites[State::ACTIVE] = new Sprite(texture, wait_rect, 1);

	vector<RECT*> attack_rect = Texture::Instance()->GetSourceRect(SVASEACTIVE);
	animation->Sprites[State::WAIT] = new Sprite(texture, attack_rect, 1);


}
BoundingBox Vase::GetBoundingBox() {
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
void Vase::SetState(State s)
{
	this->state = s;
}

void Vase::SetDirection(Direction d)
{
	this->direction = d;
}
void Vase::Reset(int x, int y, Direction d, float vx, float vy)
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