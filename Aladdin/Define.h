#pragma once
#define WINDOW_CLASS_NAME L"Aladdin"
#define MAIN_WINDOW_TITLE L"Aladdin"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 255, 200)
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 384

#define MAX_FRAME_RATE 120

//ID TEXTURES
#define ID_TEX_ALADDIN 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20


#define ID_TEX_MAP_ONE -10

//ID SPRITES
#define ID_SPRITE_MAP_ONE -10

//ID ANIMATIONS
#define ID_TEX_ALADDIN_GO_RIGHT 0
#define ID_TEX_ALADDIN_GO_LEFT 1

//ID OBJECTS
#define	OBJECT_GROUND -100
#define OBJECT_PILLAR_1 -90
#define OBJECT_PILLAR_2 -80
#define OBJECT_PILLAR_3 -70
#define OBJECT_PILLAR_4 -60
#define OBJECT_ROCK -60

//ALADDIN
#define ALADDIN_WALKING_SPEED		0.1f 
//0.1f
#define ALADDIN_JUMP_SPEED_Y		0.5f
#define ALADDIN_JUMP_DEFLECT_SPEED 0.2f
#define ALADDIN_GRAVITY			0.002f
#define ALADDIN_DIE_DEFLECT_SPEED	 0.5f

#define ALADDIN_STATE_IDLE			100
#define ALADDIN_STATE_SIT_DOWN		200
#define ALADDIN_STATE_LOOKING_UP	300
#define ALADDIN_STATE_STANDING		400

#define ALADDIN_STATE_WALKING_RIGHT	500
#define ALADDIN_STATE_WALKING_LEFT	600
#define ALADDIN_STATE_STOP			700
#define ALADDIN_STATE_JUMP			800
#define ALADDIN_ANI_RUN_JUMP		900
#define ALADDIN_STATE_STANDING_SLASH	1000
#define ALADDIN_STATE_SITTING_SLASH	11000
#define ALADDIN_STATE_LOOKING_UP_SLASH	1200
#define ALADDIN_STATE_JUMPING_SLASH	1300

#define ALADDIN_STATE_THROW_APPLE	1400
#define ALADDIN_STATE_SITTING_THROW_APPLE	15000
#define ALADDIN_STATE_JUMPING_THROW_APPLE	1600

#define ALADDIN_STATE_CLIMBING		1700
#define ALADDIN_STATE_FALLING_AFTER_CLIMBING	1800
#define ALADDIN_STATE_CLIMBING_SLASH	1900
#define ALADDIN_STATE_CLIMBING__THROW_APPLE	2000

#define ALADDIN_STATE_RIDE_THE_CARPET	2100

#define ALADDIN_STATE_DIE			2200

#define ALADDIN_ANI_IDLE_RIGHT		0
#define ALADDIN_ANI_IDLE_LEFT		1
#define ALADDIN_ANI_SIT_DOWN_RIGHT	2
#define ALADDIN_ANI_SIT_DOWN_LEFT	3
#define ALADDIN_ANI_LOOKING_UP_RIGHT	4
#define ALADDIN_ANI_LOOKING_UP_LEFT	5

#define ALADDIN_ANI_STANDING_RIGHT 6
#define ALADDIN_ANI_STANDING_LEFT 7

#define ALADDIN_ANI_WALKING_RIGHT		8
#define ALADDIN_ANI_WALKING_LEFT		9
#define ALADDIN_ANI_STOP_RIGHT			10
#define ALADDIN_ANI_STOP_LEFT			11
#define ALADDIN_ANI_JUMPING_RIGHT		12
#define ALADDIN_ANI_JUMPING_LEFT		13
#define ALADDIN_ANI_RUN_JUMP_RIGHT		14
#define ALADDIN_ANI_RUN_JUMP_LEFT		15

#define ALADDIN_ANI_STANDING_SLASH_RIGHT		16
#define ALADDIN_ANI_STANDING_SLASH_LEFT		17
#define ALADDIN_ANI_SITTING_SLASH_RIGHT		18
#define ALADDIN_ANI_SITTING_SLASH_LEFT		19
#define ALADDIN_ANI_LOOKING_UP_SLASH_RIGHT	20
#define ALADDIN_ANI_LOOKING_UP_SLASH_LEFT	21
#define ALADDIN_ANI_JUMPING_SLASH_RIGHT		22
#define ALADDIN_ANI_JUMPING_SLASH_LEFT		23

#define ALADDIN_ANI_THROW_APPLE_RIGHT		24
#define ALADDIN_ANI_THROW_APPLE_LEFT		25
#define ALADDIN_ANI_SITTING_THROW_APPLE_RIGHT	26
#define ALADDIN_ANI_SITTING_THROW_APPLE_LEFT	27
#define ALADDIN_ANI_JUMPING_THROW_APPLE_RIGHT	28
#define ALADDIN_ANI_JUMPING_THROW_APPLE_LEFT	29

#define ALADDIN_ANI_CLIMBING		30
#define ALADDIN_ANI_FALLING_AFTER_CLIMBING	31
#define ALADDIN_ANI_CLIMBING_SLASH_RIGHT	32
#define ALADDIN_ANI_CLIMBING_SLASH_LEFT		33
#define ALADDIN_ANI_CLIMBING__THROW_APPLE_RIGHT		34
#define ALADDIN_ANI_CLIMBING__THROW_APPLE_LEFT		35

#define ALADDIN_ANI_RIDE_THE_CARPET_RIGHT	36
#define ALADDIN_ANI_RIDE_THE_CARPET_LEFT	37

#define ALADDIN_ANI_DIE				38

#define ALADDIN_BBOX_WIDTH  41
#define ALADDIN_BBOX_HEIGHT 51

#define ALADDIN_RUN_BBOX_WIDTH  41
#define ALADDIN_RUN_BBOX_HEIGHT 58

#define ALADDIN_JUMP_BBOX_WIDTH 59
#define ALADDIN_JUMP_BBOX_HEIGHT 93

#define ALADDIN_STANDING_SLASH_BBOX_WIDTH 82
#define ALADDIN_STANDING_SLASH_BBOX_HEIGHT 74

#define ALADDIN_UNTOUCHABLE_TIME 5000

//Ground
#define GROUND_BBOX_WIDTH				32
#define GROUND_BBOX_HEIGHT				5