#pragma once
#include <d3dx9.h>

class CCamera
{
private:
	D3DXVECTOR3 cameraPosition;
	static CCamera* __instance;
	CCamera(float x, float y);
	bool is_lock;
public:
	static CCamera* GetInstance();
	~CCamera();
	D3DXVECTOR3 GetPositionInCamera(D3DXVECTOR3 position);
	void SetCameraPosition(float x, float y);
	D3DXVECTOR3 GetCameraPosition();
	void SetLock(bool isLock) { is_lock = isLock; }
	bool IsLock() { return is_lock; }
};
