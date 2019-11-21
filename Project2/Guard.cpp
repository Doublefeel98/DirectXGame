#include"Guard.h"
Guard::Guard(int x, int y, Direction d) :ActionObject(x, y, WIDTH, HEIGHT, d)
{
	center_region_y = y;

	this->hitpoints = MAX_HP;
	this->destroyed = false;
	this->nameObject = GUARD;
	this->SetState(WELCOME);
	LoadResource();
}
Guard::~Guard() {

}
void Guard::Update(DWORD dt, vector<Object*>* list) {
	//float x, y;
	//Aladin::Instance()->GetPosition(x, y);

	if (destroyed) {
		return;
	}
	if (this->hitpoints <= 0)
	{
		//this->destroyed = true;
		//Smoke* tmp = new Smoke(this->x, this->y, RIGHT, 0);
		//tmp->SetState(GUARD);
		//return;
	}
	
}
void Guard::Render() {
	if (destroyed) return;
	ActionObject::Render();
}
void Guard::LoadResource() {
	MyTexture* texture = Texture::Instance()->GetTexture(TGUARD);

	vector<RECT*> attend = Texture::Instance()->GetSourceRect(SGUARDATTEND);
	animation->Sprites[State::ATTEND] = new Sprite(texture, attend, 8);

	vector<RECT*> die = Texture::Instance()->GetSourceRect(SGUARDDIE);
	animation->Sprites[State::DIE] = new Sprite(texture, die, 4);

	vector<RECT*> dodge = Texture::Instance()->GetSourceRect(SGUARDDODGE);
	animation->Sprites[State::DODGE] = new Sprite(texture, dodge, 6);

	vector<RECT*> slice = Texture::Instance()->GetSourceRect(SGUARDSLICE);
	animation->Sprites[State::SLICE] = new Sprite(texture, slice, 5);

	vector<RECT*> tab = Texture::Instance()->GetSourceRect(SGUARDTAB);
	animation->Sprites[State::TAB] = new Sprite(texture, tab, 6);

	vector<RECT*> welcome = Texture::Instance()->GetSourceRect(SGUARDWELCOME);
	animation->Sprites[State::WELCOME] = new Sprite(texture, welcome, 6);


}
BoundingBox Guard::GetBoundingBox()
{
	BoundingBox bound;
	bound.x = x - WIDTH / 2;
	bound.y = y - HEIGHT / 2;
	bound.w = WIDTH;
	bound.h = HEIGHT;
	return bound;
}
void Guard::SetState(State s)
{
	this->state = s;
}

void Guard::SetDirection(Direction d)
{
	this->direction = d;
}
void Guard::Reset(int x, int y, Direction d) {
	this->direction = d;
	this->x = x;
	this->y = y;
	this->hitpoints = MAX_HP;
	this->destroyed = false;
	this->nameObject = GUARD;
	this->SetState(WELCOME);
}