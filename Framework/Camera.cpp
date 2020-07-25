#include "Camera.h"
#include "SceneManager.h"

CCamera* CCamera::__instance = NULL;

CCamera* CCamera::GetInstance()
{
	if (__instance == NULL) __instance = new CCamera(0, 0);
	return __instance;
}


CCamera::CCamera(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
	this->position.z = 0;
	is_follow_player = true;
}


CCamera::~CCamera()
{
}

D3DXVECTOR3 CCamera::GetPositionInCamera(D3DXVECTOR3 position)
{
	D3DXVECTOR3 pos;
	pos.x = position.x - this->position.x;
	pos.y = position.y - this->position.y;
	return D3DXVECTOR3(pos.x, pos.y, 0);
}

void CCamera::SetCameraPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

D3DXVECTOR3 CCamera::GetPosition()
{
	return this->position;
}

void CCamera::HandleUpdateFollowPlayer(int mapWidth, int mapHeight)
{
	float player_x, player_y;

	CPlayer* player = CSceneManager::GetInstance()->GetPlayer();

	player->GetPosition(player_x, player_y);

	if (mapWidth > width - 15) {
		if (player_x < (width - 15) / 2) {
			player_x = 0;
		}
		else if (player_x + (width - 15) / 2 > mapWidth) {
			player_x = mapWidth - (width - 15);
		}
		else {
			player_x = player_x + (width - 15) / 2 - (width - 15);
		}
	}
	else {
		player_x = 0;
	}

	if (mapHeight > height)
	{
		if (player_y + player->GetHeight() / 2 < mapHeight - height / 2) {
			player_y = player_y + player->GetHeight() / 2 - height / 2;
		}
		else {
			player_y = mapHeight - height;
		}
	}
	else {
		player_y = mapHeight > height;
	}

	if (is_follow_player) {
		this->SetCameraPosition((int)player_x, (int)player_y);
	}
	else {
		if (player->x <= this->GetX()) {
			player->x = this->GetX();
		}
		if (player->x >= this->GetX() + width - player->GetWidth() - 1) {
			player->x = this->GetX() + width - player->GetWidth() - 1;
		}
	}
}

void CCamera::SetSize(int _width, int _height)
{
	this->width = _width; this->height = _height;
}
