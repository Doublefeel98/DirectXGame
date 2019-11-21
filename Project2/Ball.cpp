#include"Ball.h"
Ball::Ball(int x, int y, Direction d) :ActionObject(x, y, WIDTH, HEIGHT, d)
{
	center_region_y = y;

	this->hitpoints = MAX_HP;
	this->destroyed = false;
	this->nameObject = BALL;
	this->SetState(WAIT);
	LoadResource();
}
Ball::~Ball() {

}
void Ball::Update(DWORD dt, vector<Object*>* list) {
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
void Ball::Render() {
	if (destroyed) return;
	ActionObject::Render();
}
void Ball::LoadResource() {
	MyTexture* texture = Texture::Instance()->GetTexture(TBALL);

	vector<RECT*> wait_rect = Texture::Instance()->GetSourceRect(SBALL);
	animation->Sprites[State::WAIT] = new Sprite(texture, wait_rect, 20);

}
BoundingBox Ball::GetBoundingBox()
{
	BoundingBox bound;
	bound.x = x - WIDTH / 2;
	bound.y = y - HEIGHT / 2;
	bound.w = WIDTH;
	bound.h = HEIGHT;
	return bound;
}
void Ball::SetState(State s)
{
	this->state = s;
}

void Ball::SetDirection(Direction d)
{
	this->direction = d;
}
void Ball::Reset(int x, int y, Direction d) {
	this->direction = d;
	this->x = x;
	this->y = y;
	this->hitpoints = MAX_HP;
	this->destroyed = false;
	this->nameObject = BALL;
}