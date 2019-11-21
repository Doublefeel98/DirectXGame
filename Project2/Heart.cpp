//#include"Heart.h"
//
//Heart::Heart(int x, int y, Direction d) :ActionObject(x, y, WIDTH, HEIGHT, d) {
//
//	center_region_y = y;
//	vy = VY;
//
//	this->hitpoints = HP;
//	this->destroyed = false;
//	this->attack = false;
//	this->active = false;
//
//	this->nameObject = HEART;
//	this->SetState(WAIT);
//	LoadResource();
//}
//Heart::~Heart() {
//
//}
//void Heart::Update(DWORD dt, vector<Object*>* list) {
//	if (this->destroyed) return;
//	if (this->hitpoints <= 0) {
//		this->destroyed = true;
//
//	}
//	if (this->hitpoints <= 0)
//	{
//		//this->destroyed = true;
//		//Smoke* tmp = new Smoke(this->x, this->y, RIGHT, 0);
//		//tmp->SetState(HEART);
//		return;
//	}
//
//}
//void Heart::Render() {
//	if (this->destroyed) return;
//	ActionObject::Render();
//}
//void Heart::LoadResource() {
//	MyTexture* texture = Texture::Instance()->GetTexture(THEART);
//
//	vector<RECT*> wait_rect = Texture::Instance()->GetSourceRect(SHEART);
//	animation->Sprites[State::WAIT] = new Sprite(texture, wait_rect, 1);
//
//}
//BoundingBox Heart::GetBoundingBox() {
//	if (this->destroyed) return BoundingBox();
//	BoundingBox bound;
//	bound.x = x - WIDTH / 2;
//	bound.y = y - HEIGHT / 2;
//	bound.w = WIDTH;
//	bound.h = HEIGHT;
//	bound.vx = dx;
//	bound.vy = dy;
//	return bound;
//}
//void Heart::SetState(State s)
//{
//	this->state = s;
//}
//
//void Heart::SetDirection(Direction d)
//{
//	this->direction = d;
//}
//void Heart::Reset(int x, int y, Direction d, float vx, float vy)
//{
//	this->vx = (d == LEFT) ? -vx : vx;
//	this->vy = -vy;
//	this->direction = d;
//	this->destroyed = false;
//	this->x = x;
//	this->y = y;
//	this->active = false;
//	this->attack = false;
//
//	this->hitpoints = HP;
//}