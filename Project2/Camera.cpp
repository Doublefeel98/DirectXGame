#include"Camera.h"

Camera* Camera::instance;

Camera::Camera() {
	
	this->auto_moving_x = false;
	this->locked = false;
}
Camera::~Camera() {
	
}
Camera* Camera::Instance() {
	if (!instance) {
		instance = new Camera();
	}
	return instance;
}
void Camera::Update(float x, float y) {
	//if (this->locked) {
	//	return;
	//}
	//if (this->auto_moving_x) {
	//	this->x += 3;
	//
	//}
	//return;
	this->x = x - G_ScreenWidth / 2;
	this->y = y + 3 * G_ScreenHeight / 4 - 40;

	if (this->x < 0)
		this->x = 0;
	if (this->y < G_ScreenHeight)
		this->y = G_ScreenHeight;

}

void Camera::Reset() {
	x = 0;
	y = G_ScreenWidth;
}
D3DXVECTOR2 Camera::GetPositionInViewPort(float x, float y)
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	matrix._22 = -1;
	matrix._41 = -this->x;
	matrix._42 = this->y;

	D3DXVECTOR3 pos3(x, y, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrix);

	D3DXVECTOR2 result = D3DXVECTOR2(MatrixResult.x, MatrixResult.y);
	return result;
}
void Camera::GetCameraPosition(float& x, float& y)
{
	x = this->x;
	y = this->y;
}

Box Camera::GetBound()
{
	return Box(this->x / G_Scale.x, this->y / G_Scale.y, G_ScreenWidth / G_Scale.x, G_ScreenHeight / G_Scale.y);
}