#include "FireBall.h"
#include "Define.h"

void FireBall::Update(DWORD dt)
{
	if (nx > 0)
		vx = FIRE_BALL_SPEED;
	else
		vx = -FIRE_BALL_SPEED;
	CGameObject::Update(dt);
	x += dx;
	y += dy;

}

void FireBall::Render()
{
	if (isEnable)
	{
		CSprites* sprites = CSprites::GetInstance();
		sprite = sprites->Get(24001);
		sprite->Draw( x, y);
	}
	D3DXVECTOR3 currentcamera = CCamera::GetInstance()->GetCameraPosition();
	if (x < currentcamera.x || x>currentcamera.x + SCREEN_WIDTH)
		isEnable = false;
	CGameObject::Render();
}
void FireBall::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = l + FIRE_BALL_BBOX_WIDTH;
	b = t + FIRE_BALL_BBOX_HEIGHT;
}

FireBall::FireBall()
{

}


FireBall::~FireBall()
{
}
