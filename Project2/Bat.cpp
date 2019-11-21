#include"Bat.h"

Bat::Bat(int x, int y, Direction d) :ActionObject(x, y, WIDTH, HEIGHT, d) {
	
	center_region_y = y;
	vy = VY;

	this->hitpoints = HP;
	this->destroyed = false;
	this->attack = false;
	this->active = false;
	
	this->nameObject = BAT;
	this->SetState(WAIT);
	LoadResource();
}
Bat::~Bat() {

}
void Bat::Update(DWORD dt, vector<Object*>* list) {
	if (this->destroyed) return;
	if (this->hitpoints <= 0) {
		this->destroyed = true;
		
	}
	if (this->hitpoints <= 0)
	{
		//this->destroyed = true;
		//Smoke* tmp = new Smoke(this->x, this->y, RIGHT, 0);
		//tmp->SetState(BAT);
		return;
	}

}
void Bat::Render() {
	if (this->destroyed) return;
	ActionObject::Render();
}
void Bat::LoadResource() {
	MyTexture* texture = Texture::Instance()->GetTexture(TBAT);
	
	vector<RECT*> wait_rect = Texture::Instance()->GetSourceRect(SBATWAIT);
	animation->Sprites[State::WAIT] = new Sprite(texture, wait_rect, 1);

	vector<RECT*> attack_rect = Texture::Instance()->GetSourceRect(SBATROTATE);
	animation->Sprites[State::ROTATE] = new Sprite(texture, attack_rect, 3);

	vector<RECT*> destroyed_rect = Texture::Instance()->GetSourceRect(SBATDIE);
	animation->Sprites[State::DIE] = new Sprite(texture, destroyed_rect, 9);

	vector<RECT*> active_rect = Texture::Instance()->GetSourceRect(SBATFLY);
	animation->Sprites[State::FLY] = new Sprite(texture, active_rect, 7);


}
BoundingBox Bat::GetBoundingBox() {
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
void Bat::SetState(State s)
{
	this->state = s;
}

void Bat::SetDirection(Direction d)
{
	this->direction = d;
}
void Bat::Reset(int x, int y, Direction d, float vx, float vy)
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