#include"Skeleton.h"
Skeleton::Skeleton(int x, int y, Direction d) :ActionObject(x, y, WIDTH, HEIGHT, d)
{
	center_region_y = y;

	this->hitpoints = MAX_HP;
	this->destroyed = false;
	this->nameObject = SKELETON;
	this->SetState(STAND);
	LoadResource();
}
Skeleton::~Skeleton() {

}
void Skeleton::Update(DWORD dt, vector<Object*>* list) {
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
void Skeleton::Render() {
	if (destroyed) return;
	ActionObject::Render();
}
void Skeleton::LoadResource() {
	MyTexture* texture = Texture::Instance()->GetTexture(TSKELETON);

	vector<RECT*> stand = Texture::Instance()->GetSourceRect(SSKELETONEXPLODE);
	animation->Sprites[State::STAND] = new Sprite(texture, stand, 1);

	vector<RECT*> explode = Texture::Instance()->GetSourceRect(SSKELETONSTAND);
	animation->Sprites[State::EXPLODE] = new Sprite(texture, explode, 1);
}
BoundingBox Skeleton::GetBoundingBox()
{
	BoundingBox bound;
	bound.x = x - WIDTH / 2;
	bound.y = y - HEIGHT / 2;
	bound.w = WIDTH;
	bound.h = HEIGHT;
	return bound;
}
void Skeleton::SetState(State s)
{
	this->state = s;
}

void Skeleton::SetDirection(Direction d)
{
	this->direction = d;
}
void Skeleton::Reset(int x, int y, Direction d) {
	this->direction = d;
	this->x = x;
	this->y = y;
	this->hitpoints = MAX_HP;
	this->destroyed = false;
	this->nameObject = SKELETON;
}