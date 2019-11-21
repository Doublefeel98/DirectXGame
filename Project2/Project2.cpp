#include<Windows.h>
#include"MyGame.h"
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR cmd, int show) {
	MyGame* game = new MyGame(show);
	game->InitGame();
	game->GameRun();
	return 0;
}