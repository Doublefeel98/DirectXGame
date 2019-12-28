#pragma once
#define WINDOW_CLASS_NAME L"Aladdin"
#define MAIN_WINDOW_TITLE L"Aladdin"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define MAX_FRAME_RATE 120

//ID TEXTURES
#define ID_TEX_ALADDIN_GO_RIGHT 0
#define ID_TEX_ALADDIN_GO_LEFT 1
#define ID_TEX_ALADDIN_FULL_RIGHT 2
#define ID_TEX_ALADDIN_FULL_LEFT 3
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20
#define ID_TEX_ITEM -1
#define ID_TEX_OBSTACLE -100
#define ID_TEX_BAT		-101
#define ID_TEX_GUARD	-102
#define ID_TEX_THIN_GUARD	-103
#define ID_TEX_SKELETON	-104
#define ID_TEX_ENEMY_EXPLOSIONS	-105
#define ID_TEX_JAFAR	-106
#define ID_TEX_IAGO_RIGHT	-107
#define ID_TEX_IAGO_LEFT	-108
#define ID_TEX_STATUE_RIGHT	-109
#define ID_TEX_STATUE_LEFT	-110

#define ID_TEX_MAP_ONE -10
#define ID_TEX_MAP_BOSS -11
#define ID_TEX_MAP -20

//ID SPRITES
#define ID_SPRITE_MAP_ONE -10
#define ID_SPRITE_MAP_BOSS	-11
#define ID_SPRITE_MAP_START -20


// config game
#define DEVIATION_X						18


//ID OBJECTS
#define	OBJECT_APPLE					1
#define OBJECT_GOLD						2
#define OBJECT_GENIE_FACE				3
#define OBJECT_GENIE_VASE				4
#define OBJECT_BAT						5
#define OBJECT_NORMAL_PALACE_GUARD		6
#define OBJECT_THIN_PALACE_GUARD		7
#define OBJECT_FAT_PALACE_GUARD			8
#define OBJECT_EXPLODING_SKELETON		9
#define OBJECT_PEDDLER					10
#define OBJECT_BRICK					11
#define OBJECT_SPIKE_TRAP				12
#define OBJECT_WRECKING_BALL			13
#define OBJECT_CHAINS					14
#define OBJECT_FENCE					15
#define OBJECT_ROCK_BAR					16
#define OBJECT_WOOD						17
#define OBJECT_GROUND					18
#define OBJECT_PILAR_5					19
#define OBJECT_EXIT						20
#define OBJECT_FANCE					21


//ALADDIN
#define ALADDIN_WALKING_SPEED		0.11f
//0.1f
#define ALADDIN_JUMP_SPEED_Y		0.55f
#define ALADDIN_CLIMB_SPEED_Y		0.1f 
#define ALADDIN_JUMP_DEFLECT_SPEED	0.2f
#define ALADDIN_GRAVITY				0.0015f
#define ALADDIN_MAX_SPEED			1.0f
#define ALADDIN_DIE_DEFLECT_SPEED	0.5f

#define ALADDIN_ATTACK_TIME			490
#define ALADDIN_SIT_ATTACK_TIME		690
#define ALADDIN_IDLE_TIME			1001
#define ALADDIN_SIT_TIME			390
#define ALADDIN_LOOKAROUND_TIME		1000
#define ALADDIN_STAND_TIME			4390
#define ALADDIN_LOOK_UP_TIME		290
#define ALADDIN_LOOK_UP_ATTACK_TIME	4390
#define ALADDIN_THROW_TIME			590
#define ALADDIN_SIT_THROW_TIME		490
#define ALADDIN_RUN_JUMP_TIME		890
#define ALADDIN_RUN_SLASH_TIME		590
#define ALADDIN_RUN_THROW_TIME		590
#define ALADDIN_CLIMB_SLASH_TIME	690
#define ALADDIN_CLIMB_THROW_TIME	590
#define ALADDIN_JUMP_SLASH_TIME		590
#define ALADDIN_JUMP_THROW_TIME		490

#define ALADDIN_ENABLE_SWORD_TIME			300
#define ALADDIN_SIT_ENABLE_SWORD_TIME		200
#define ALADDIN_LOOK_UP_ENABLE_SWORD_TIME	200
#define ALADDIN_JUMP_ENABLE_SWORD_TIME		400
#define ALADDIN_CLIMB_ENABLE_SWORD_TIME		200
#define ALADDIN_RUN_ENABLE_SWORD_TIME		400

#define ALADDIN_STATE_IDLE			100
#define ALADDIN_STATE_SIT_DOWN		200
#define ALADDIN_STATE_LOOKING_UP	300
#define ALADDIN_STATE_STANDING		400

#define ALADDIN_STATE_WALKING_RIGHT	500
#define ALADDIN_STATE_WALKING_LEFT	600
#define ALADDIN_STATE_STOP			700
#define ALADDIN_STATE_JUMP			800
#define ALADDIN_STATE_RUN_JUMP		900
#define ALADDIN_STATE_STANDING_SLASH	1000
#define ALADDIN_STATE_SITTING_SLASH		1100
#define ALADDIN_STATE_LOOKING_UP_SLASH	1200
#define ALADDIN_STATE_JUMPING_SLASH		1300

#define ALADDIN_STATE_THROW_APPLE	1400
#define ALADDIN_STATE_SITTING_THROW_APPLE	1500
#define ALADDIN_STATE_JUMPING_THROW_APPLE	1600

#define ALADDIN_STATE_CLIMB			1700
#define ALADDIN_STATE_CLIMB_UP		1800
#define ALADDIN_STATE_CLIMB_DOWN	1900
#define ALADDIN_STATE_FALLING_AFTER_CLIMBING	2000
#define ALADDIN_STATE_CLIMBING_SLASH			2100
#define ALADDIN_STATE_CLIMBING__THROW_APPLE		2200

#define ALADDIN_STATE_RIDE_THE_CARPET	2300

#define ALADDIN_STATE_BE_ATTACKED	2400

#define ALADDIN_STATE_RUN_SLASH		2500
#define ALADDIN_STATE_RUN_THROW		2600
#define ALADDIN_STATE_CLIMB_JUMP	2700



#define ALADDIN_STATE_DIE			10000

#define ALADDIN_ANI_IDLE_RIGHT						0
#define ALADDIN_ANI_IDLE_LEFT						1
#define ALADDIN_ANI_SIT_DOWN_RIGHT					2
#define ALADDIN_ANI_SIT_DOWN_LEFT					3
#define ALADDIN_ANI_LOOKING_UP_RIGHT				4
#define ALADDIN_ANI_LOOKING_UP_LEFT					5

#define ALADDIN_ANI_STANDING_RIGHT					6
#define ALADDIN_ANI_STANDING_LEFT					7

#define ALADDIN_ANI_WALKING_RIGHT					8
#define ALADDIN_ANI_WALKING_LEFT					9
#define ALADDIN_ANI_STOP_RIGHT						10
#define ALADDIN_ANI_STOP_LEFT						11
#define ALADDIN_ANI_JUMPING_RIGHT					12
#define ALADDIN_ANI_JUMPING_LEFT					13
#define ALADDIN_ANI_RUN_JUMP_RIGHT					14
#define ALADDIN_ANI_RUN_JUMP_LEFT					15
#define ALADDIN_ANI_RUN_SLASH_RIGHT					16
#define ALADDIN_ANI_RUN_SLASH_LEFT					17
#define ALADDIN_ANI_RUN_THROW_RIGHT					18
#define ALADDIN_ANI_RUN_THROW_LEFT					19

#define ALADDIN_ANI_STANDING_SLASH_RIGHT			20
#define ALADDIN_ANI_STANDING_SLASH_LEFT				21
#define ALADDIN_ANI_SITTING_SLASH_RIGHT				22
#define ALADDIN_ANI_SITTING_SLASH_LEFT				23
#define ALADDIN_ANI_LOOKING_UP_SLASH_RIGHT			24
#define ALADDIN_ANI_LOOKING_UP_SLASH_LEFT			25
#define ALADDIN_ANI_JUMPING_SLASH_RIGHT				26
#define ALADDIN_ANI_JUMPING_SLASH_LEFT				27

#define ALADDIN_ANI_THROW_APPLE_RIGHT				28
#define ALADDIN_ANI_THROW_APPLE_LEFT				29
#define ALADDIN_ANI_SITTING_THROW_APPLE_RIGHT		30
#define ALADDIN_ANI_SITTING_THROW_APPLE_LEFT		31
#define ALADDIN_ANI_JUMPING_THROW_APPLE_RIGHT		32
#define ALADDIN_ANI_JUMPING_THROW_APPLE_LEFT		33

#define ALADDIN_ANI_CLIMBING						34
#define ALADDIN_ANI_FALLING_AFTER_CLIMBING			35
#define ALADDIN_ANI_CLIMBING_SLASH_RIGHT			36
#define ALADDIN_ANI_CLIMBING_SLASH_LEFT				37
#define ALADDIN_ANI_CLIMBING_THROW_APPLE_RIGHT		38
#define ALADDIN_ANI_CLIMBING_THROW_APPLE_LEFT		39

#define ALADDIN_ANI_RIDE_THE_CARPET_RIGHT			40
#define ALADDIN_ANI_RIDE_THE_CARPET_LEFT			41

#define ALADDIN_ANI_LOOK_AROUND_RIGHT				42
#define ALADDIN_ANI_LOOK_AROUND_LEFT				43

#define ALADDIN_ANI_BE_ATTACKED_RIGHT				44
#define ALADDIN_ANI_BE_ATTACKED_LEFT				45

#define ALADDIN_ANI_DIE								46

#define ALADDIN_BBOX_WIDTH  41
#define ALADDIN_BBOX_HEIGHT 51

#define ALADDIN_SIT_BBOX_WIDTH  50
#define ALADDIN_SIT_BBOX_HEIGHT 35

#define ALADDIN_RUN_BBOX_WIDTH  41
#define ALADDIN_RUN_BBOX_HEIGHT 58

#define ALADDIN_JUMP_BBOX_WIDTH 25
#define ALADDIN_JUMP_BBOX_HEIGHT 35

#define ALADDIN_STANDING_SLASH_BBOX_WIDTH 82
#define ALADDIN_STANDING_SLASH_BBOX_HEIGHT 74

#define ALADDIN_UNTOUCHABLE_TIME					2000
#define ALADDIN_HURTABLE_TIME						600

#define ALADDIN_MAX_HP 8


// apple
#define THROW_APPLE_GRAVITY							0.002f
#define THROW_APPLE_SPEED							0.5f

#define THROW_APPLE_STATE_RIGHT						0
#define THROW_APPLE_STATE_LEFT						1

#define THROW_APPLE_BBOX_HEIGHT						12
#define THROW_APPLE_BBOX_WIDTH						11

//sword
#define SWORD_STATE_LEFT							0
#define SWORD_STATE_RIGHT							1

#define SWORD_STATE_SIT_LEFT						2
#define SWORD_STATE_SIT_RIGHT						3

#define SWORD_STATE_JUMP_LEFT						4
#define SWORD_STATE_JUMP_RIGHT						5

#define SWORD_STATE_LOOKUP_LEFT						6
#define SWORD_STATE_LOOKUP_RIGHT					7

#define SWORD_STATE_RUN_LEFT						8
#define SWORD_STATE_RUN_RIGHT						9

#define SWORD_STATE_CLIMB_LEFT						10
#define SWORD_STATE_CLIMB_RIGHT						11

#define SWORD_BBOX_WIDTH							42
#define SWORD_BBOX_HEIGHT							61

#define SWORD_BBOX_SIT_WIDTH						40
#define SWORD_BBOX_SIT_HEIGHT						35

#define SWORD_BBOX_JUMP_WIDTH						44
#define SWORD_BBOX_JUMP_HEIGHT						50

#define SWORD_BBOX_LOOKUP_WIDTH						24
#define SWORD_BBOX_LOOKUP_HEIGHT					37

#define SWORD_BBOX_RUN_WIDTH						25
#define SWORD_BBOX_RUN_HEIGHT						35

#define SWORD_BBOX_CLIMB_WIDTH						25
#define SWORD_BBOX_CLIMB_HEIGHT						35

#define GUARD_SWORD_SLASH_STATE_LEFT					0
#define GUARD_SWORD_SLASH_STATE_RIGHT					1
#define GUARD_SWORD_STAB_STATE_LEFT						2
#define GUARD_SWORD_STAB_STATE_RIGHT					3
#define TGUARD_SWORD_STATE_LEFT							4
#define TGUARD_SWORD_STATE_RIGHT						5

#define GUARD_SWORD_SLASH_BBOX_WIDTH					45
#define GUARD_SWORD_SLASH_BBOX_HEIGHT					30
#define GUARD_SWORD_STAB_BBOX_WIDTH						45
#define GUARD_SWORD_STAB_BBOX_HEIGHT					30
#define TGUARD_SWORD_BBOX_WIDTH							50
#define TGUARD_SWORD_BBOX_HEIGHT						20


#define STONE_ANI_WAIT								0

#define STONE_BBOX_WIDTH 28
#define STONE_BBOX_HEIGHT 11

#define TRAP_ANI_WAIT								0

#define TRAP_BBOX_WIDTH 28
#define TRAP_BBOX_HEIGHT 12

#define BALL_ANI_WAIT								0

#define BALL_BBOX_WIDTH 26
#define BALL_BBOX_HEIGHT 31

//Bat
#define BAT_STATE_WAIT 0
#define BAT_STATE_FLY 2
#define BAT_STATE_SWING 3
#define BAT_STATE_DIE 4

#define BAT_ANI_WAIT								0
#define BAT_ANI_SWING								1
#define BAT_ANI_FLY									2			
#define BAT_ANI_DIE									3			

#define BAT_WAIT_BBOX_HEIGHT	16
#define BAT_WAIT_BBOX_WIDTH		9
#define BAT_FLY_BBOX_WIDTH	30
#define BAT_FLY_BBOX_HEIGHT 25
#define BAT_ROLATE_BBOX_WIDTH	20
#define BAT_ROLATE_BBOX_HEIGHT	23
#define BAT_DIE_BBOX_WIDTH	20
#define BAT_DIE_BBOX_HEIGHT	53

#define BAT_VX	0.1
#define BAT_VY	0.0005
#define BAT_DELTA_X	80
#define BAT_DELTA_Y	100
#define BAT_DELTA_X_REVERSE	80
#define BAT_DELTA_X_ATTACK	50
#define BAT_TIME_REVERSE	1000

// Thin guard
#define TGUARD_STATE_IDLE		0
#define TGUARD_STATE_WALK		1
#define TGUARD_STATE_ATTACK 	2
#define TGUARD_STATE_SURPRISE 	3

#define THIN_GUARD_ANI_IDLE_RIGHT					0
#define THIN_GUARD_ANI_IDLE_LEFT					1
#define THIN_GUARD_ANI_WALK_RIGHT					2
#define THIN_GUARD_ANI_WALK_LEFT					3
#define THIN_GUARD_ANI_ATTACK_RIGHT					4
#define THIN_GUARD_ANI_ATTACK_LEFT					5
#define THIN_GUARD_ANI_SURPRISE_RIGHT				6
#define THIN_GUARD_ANI_SURPRISE_LEFT				7

#define THIN_GUARD_BBOX_HEIGHT	58
#define THIN_GUARD_BBOX_WIDTH	34
#define THIN_GUARD_ATTACK_BBOX_HEIGHT	74
#define THIN_GUARD_ATTACK_BBOX_WIDTH	33
#define THIN_GUARD_SURPRISE_BBOX_HEIGHT 58
#define THIN_GUARD_SURPRISE_BBOX_WIDTH	34

//Normal guard
#define NGUARD_ENABLE_SWORD_TIME			100

#define NGUARD_STATE_IDLE		0
#define NGUARD_STATE_WALK		1
#define NGUARD_STATE_WAIT		2
#define NGUARD_STATE_STAB 		3
#define NGUARD_STATE_SLASH 		4
#define NGUARD_STATE_SURPRISE 	5

#define NORMAL_GUARD_ANI_IDLE_RIGHT					0
#define NORMAL_GUARD_ANI_IDLE_LEFT					1			
#define NORMAL_GUARD_ANI_WALK_RIGHT					2
#define NORMAL_GUARD_ANI_WALK_LEFT					3
#define NORMAL_GUARD_ANI_WAIT_RIGHT					4
#define NORMAL_GUARD_ANI_WAIT_LEFT					5
#define NORMAL_GUARD_ANI_ATTACK_STAB_RIGHT			6
#define NORMAL_GUARD_ANI_ATTACK_STAB_LEFT			7
#define NORMAL_GUARD_ANI_ATTACK_SLASH_RIGHT			8
#define NORMAL_GUARD_ANI_ATTACK_SLASH_LEFT			9
#define NORMAL_GUARD_ANI_SURPRISE_RIGHT				10
#define NORMAL_GUARD_ANI_SURPRISE_LEFT				11

#define GUARD_BBOX_HEIGHT	53
#define GUARD_BBOX_WIDTH	44
#define GUARD_STAB_BBOX_HEIGHT	53
#define GUARD_STAB_BBOX_WIDTH	42
#define GUARD_SLASH_BBOX_HEIGHT 53
#define GUARD_SLASH_BBOX_WIDTH	50
#define GUARD_SURPRISE_BBOX_HEIGHT 53
#define GUARD_SURSPRISE_BBOX_WIDTH 50

#define GUARD_DELTA_X								200
#define GUARD_DELTA_WALK_X							50
#define GUARD_WALKING_SPEED							0.1f 

// Fat guard

#define FAT_GUARD_ANI_IDLE_RIGHT					0
#define FAT_GUARD_ANI_IDLE_LEFT						1
#define FAT_GUARD_ANI_WALK_RIGHT					2
#define FAT_GUARD_ANI_WALK_LEFT						3
#define FAT_GUARD_ANI_ATTACK_RIGHT					4
#define FAT_GUARD_ANI_ATTACK_LEFT					5
#define FAT_GUARD_ANI_SURPRISE_RIGHT				6
#define FAT_GUARD_ANI_SURPRISE_LEFT					7

// Skeleton
#define SKELETON_STATE_WAIT				0
#define SKELETON_STATE_STAND_UP 		1

#define SKELETON_ANI_WAIT_RIGHT						0
#define SKELETON_ANI_WAIT_LEFT						1
#define SKELETON_ANI_STAND_UP_RIGHT					2
#define SKELETON_ANI_STAND_UP_LEFT					3

#define SKELETON_BBOX_WIDTH							40
#define SKELETON_BBOX_HEIGHT						80
#define SKELETON_BBOX_WIDTH_WIDE					80

#define SKELETON_DELTA_X							150
#define SKELETON_DELTA_Y							150

#define COUNT_BONE									5

//bone
#define BONE_BBOX_WIDTH				12
#define BONE_BBOX_HEIGHT			10

#define BONE_STATE_IDLE			0
#define BONE_STATE_FLY			1
#define BONE_STATE_THROW		2
#define BONE_STATE_DIE			3

#define BONE_GRAVITY			0.002f

#define BONE_MIN_SPEED_X		0.05f
#define BONE_MAX_SPEED_X		0.8f

#define BONE_MIN_SPEED_Y		0.05f
#define BONE_MAX_SPEED_Y		0.5f

#define BONE_DAMAGE				1

// Boss

#define JAFAR_ANI_IDLE_RIGHT						0
#define JAFAR_ANI_IDLE_LEFT							1
#define JAFAR_ANI_ATTACK_RIGHT						2
#define JAFAR_ANI_ATTACK_LEFT						3
#define JAFAR_ANI_SNAKE_RIGHT						4
#define JAFAR_ANI_SNAKE_LEFT						5

#define JAFAR_STATE_IDLE					0
#define JAFAR_STATE_ATTACK					1
#define JAFAR_STATE_SNAKE					2

#define JAFAR_HP							30

#define JAFAR_BBOX_WIDTH 85
#define JAFAR_BBOX_HEIGHT 71

#define JAFAR_SNAKE_BBOX_WIDTH	70
#define JAFAR_SNAKE_BBOX_HEIGHT	84

//star
#define STAR_BBOX_WIDTH								28
#define STAR_BBOX_HEIGHT							16

#define STAR_STATE_RIGHT							0
#define STAR_STATE_LEFT								1

#define STAR_SPEED									0.15f
#define STAR_GRAVITATION							0.03f

//fire
#define FIRE										0

#define FIRE_BBOX_WIDTH	30
#define FIRE_BBOX_HEIGHT 53

#define FIRE_DAMAGE		1

// snake fire
#define FIRE_SNAKE_BBOX_WIDTH	64
#define FIRE_SNAKE_BBOX_HEIGHT	51

#define FIRE_SNAKE_STATE_RIGHT	0
#define FIRE_SNAKE_STATE_LEFT	1

#define FIRE_SNAKE_DAMAGE		1

#define FIRE_SNAKE_SPEED 0.05f;
// Item

#define APPLE_ANI_WAIT								0
#define ITEM_ANI_EFFECT								1

#define PENNY_ANI_WAIT								0
#define PENNY_BBOX_HEIGHT 17
#define PENNY_BBOX_WIDTH  17

#define VASE_ANI_WAIT								0
#define VASE_ANI_STOP								1
#define VASE_ANI_ACTIVE								2
#define VASE_BBOX_HEIGHT 30
#define VASE_BBOX_WIDTH 20

#define GENNIE_ANI_WAIT								0
#define GENNIE_ANI_ACTIVE							1
#define GENNIE_ANI_EFFECT							2
#define	GENNIE_BBOX_WIDTH 35
#define	GENNIE_BBOX_HEIGHT 50

#define HEART_ANI_WAIT								0
#define	HEART_BBOX_WIDTH 20
#define	HEART_BBOX_HEIGH 20

#define BRICK_BBOX_WIDTH  36
#define BRICK_BBOX_HEIGHT 14

#define THROW_APPLE_BBOX_HEIGHT 7
#define THROW_APPLE_BBOX_WIDTH  7

//Ground
#define GROUND_BBOX_WIDTH				32
#define GROUND_BBOX_HEIGHT				32

//pilar
#define PILAR_STATE_1								0
#define PILAR_STATE_2								1
#define PILAR_STATE_3								2
#define PILAR_STATE_4								3
#define PILAR_STATE_5								5

#define PILAR_BBOX_WIDTH_5				80
#define PILAR_BBOX_HEIGHT_5				734

//exit
#define EXIT_STATE						0

#define EXIT_BBOX_WIDTH	78
#define EXIT_BBOX_HEIGHT 208

#define FANCE_STATE						0

#define FANCE_BBOX_WIDTH	0
#define FANCE_BBOX_HEIGHT 0

//MAX_HP 
#define BAT_MAX_HP 1
#define GUARD_MAX_HP 2
#define THIN_GUARD_MAX_HP 2
#define FAT_GUARD_MAX_HP 2
#define SKELETON_MAX_HP 1
#define IAGO_MAX_HP 1
#define STATUE_MAX_HP 1

//Sound

#define AUDIO_FORMAT_TAG		WAVE_FORMAT_PCM
#define	AUDIO_NUM_OF_CHANNEL	2
#define AUDIO_SAMPLE_SPEED		22050
#define AUDIO_BITS_PER_SAMPLE	16
#define AUDIO_FLAGS				0
#define AUDIO_BUFFER_SIZE		640000
#define AUDIO_GUID				GUID_NULL
#define BACKGROUND_MUSIC	"resources\\sound\\Ending.wav"
#define GAME1_MUSIC			 "resources\\sound\\man1.wav"
#define BOSS_MUSIC			"resources\\sound\\bosstheme.wav"
#define CUT_MUSIC			"resources\\sound\\Low Sword.wav"
#define SPLAT_MUSIC			"resources\\sound\\Apple Splat.wav"
#define CAMEL_MUSIC			"resources\\sound\\Camel Spit.wav"
#define HURT_MUSIC			"resources\\sound\\Aladdin Hurt.wav"
#define COLLECT_MUSIC		"resources\\sound\\Apple Collect.wav"
#define APPLE_POP_MUSIC		"resources\\sound\\Balloon Pop.wav"
#define SWORD_MUSIC			"resources\\sound\\Sword Ching.wav"
#define TRAP_MUSIC			"resources\\sound\\Sword Spinning.wav"
#define DIE_MUSIC			"resources\\sound\\chet.wav"
#define JAFAR_HURT_MUSIC	"resources\\sound\\Jafar Snake.wav"
#define SHOOT_MUSIC			"resources\\sound\\shoot.wav"
#define NEXT_MUSIC			"resources\\sound\\level_complete.wav"
#define SNAKE_MUSIC			"resources\\sound\\Jafar Snake.wav"
#define GUARD_THIN_MUSIC	"resources\\sound\\Guard Hit 1.wav"
#define GUARD_NORMAL_MUSIC	 "resources\\sound\\Guard Hit 2.wav"
#define THEEND_MUSIC		"resources\\sound\\theend.wav"
#define POT_MUSIC			"resources\\sound\\Clay Pot.wav"
#define COMEOUT_MUSIC		"resources\\sound\\Coming Out.wav"
#define COMEIN_MUSIC		"resources\\sound\\Continue Point.wav"
#define FIRE_MUSIC			"resources\\sound\\Fire From Coal.wav"
#define LAMP_MUSIC			"resources\\sound\\Splash.wav"
#define WOW_MUSIC			"resources\\sound\\Wow!.wav"
#define THROW_MUSIC			"resources\\sound\\Object Throw.wav"
#define BRICK_MUSIC			"resources\\sound\\Stone Rumble.wav"
#define SKELETON_MUSIC		"resources\\sound\\Skeleton.wav"
#define BONE_MUSIC			"resources\\sound\\Bones Tinkle.wav"
#define MENU_MUSIC			"resources\\sound\\Menu.wav"
#define SELECT_MUSIC		"resources\\sound\\Menu Select.wav"
#define MAIN_MUSIC			"resources\\sound\\man1.wav"



#define AUDIO_BLOCK_ALIGN(bitPerSample, nChannels)		(WORD)(bitPerSample / 8 * nChannels)
#define AUDIO_AVERAGE_BPS(samplesPerSec, blockAlign)	(DWORD)(samplesPerSec * blockAlign)