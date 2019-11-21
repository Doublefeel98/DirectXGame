#pragma once
#ifndef Global_H_
#define Global_H_


#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>

#define KEY_BUFFER_SIZE 1024
#define ADDITIONS 1143

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
extern D3DXVECTOR2 G_Scale;
extern D3DXVECTOR2 G_ScaleFlipX;
extern D3DXVECTOR2 G_ScaleFlipY;


extern bool			G_IsFullScreen;

extern bool			G_IsInitedDX;		//check if dx is inited

extern char* G_GameName;		//name of game, view in caption
extern int			G_FrameRate;		//frame rate(30 -> 60)

extern int			G_ScreenWidth;			//width of game screen
extern int			G_ScreenHeight;			//height of game screen
extern RECT			G_WindowSize;			//size of game screen

extern HINSTANCE					G_hInstance;		// Handle of the game instance
extern HWND							G_hWnd;			// Handle of the Game Window

extern LPDIRECT3D9					G_DirectX;			//handle dx
extern LPDIRECT3DDEVICE9			G_Device;			//dx device
extern LPDIRECT3DSURFACE9			G_BackBuffer;		//backbuffer
extern D3DFORMAT					G_BackBufferFormat;//backbuffer format, used in initing dx

extern LPDIRECTINPUT8				G_DirectInput;		// The DirectInput object         
extern LPDIRECTINPUTDEVICE8			G_KeyBoard;			// The keyboard device 
extern LPD3DXSPRITE					G_SpriteHandler;	// spriteHandler to draw texture


/*
//VASE
#define WIDTH 20
#define HEIGHT 30

//PENNY
#define WIDTH 15
#define HEIGHT 15

//HEART
#define WIDTH 15
#define HEIGHT 15

//APPLE
#define WIDTH 10
#define HEIGHT 10


//FACE
#define WIDTH 30
#define HEIGHT 35
*/

//blue bafeca
/*
blue bafeca
deep blue 78c198
pink ff00ff
*/
enum Direction {
	LEFT,
	RIGHT
};
enum EController {
	NoneControl,
	LeftControl,
	RightControl,
	SliceControl,
	JumpControl,
	KneelControl,
	ThrowControl,
};
enum State {
	LOOKAROUND,
	THROW,
	SLICE,
	SLICE2SIDES,
	DODGE,
	KNEEL,
	KNEELTHROW,
	KNEELSLICE,
	JUMPLAND,
	FLY,
	LAND,
	JUMPSLICE,
	RUN,
	STOPRUN,
	CLIMB,
	KNEELDODGE,
	DODGESTAND,
	KNEELSTAY,
	//SKELETON
	EXPLODE,
	STAND,
	//FACE
	ROTATE,

	//GUaRD
	DIE,
	ATTEND,
	WELCOME,
	TAB,

	//Objects
	WAIT,
	ACTIVE

};
enum TypeObject {
	VIRTUALOBJECT,
	HEART,
	ALADIN,
	PENNY,
	FACE,
	SKELETON,
	GUARD,
	TRAP,
	BIRD, 
	APPLE,
	LAMP,
	BAT,
	CAPRET,
	SMOKE,
	VASE,
	BALL,
	STONE,
	LIFE
};
void GLTrace(char* format, ...);

void GLMessage(const char* text);

void GLTitle(char* text);
#endif
