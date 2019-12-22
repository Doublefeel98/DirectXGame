#include "AladdinObjects.h"
#include "Ground.h"
#include "Pilar.h"
#include "Exit.h"
#include "Fance.h"
#include "Brick.h"
#include "WreckingBall.h"
#include "StoneBar.h"
#include "Wood.h"
#include "Chains.h"


AladdinObjects::AladdinObjects()
{
}

AladdinObjects::~AladdinObjects()
{
}

void AladdinObjects::Load(string file, vector<LPGAMEOBJECT>* listObject)
{
	ifstream input;
	input.open(file, ifstream::in);

	string checkEnd;
	int id;
	int type;
	float x;
	float y;
	int width;
	int height;
	int delay;
	int count = 0;

	while (input >> checkEnd)
	{
		if (checkEnd == "END")
		{
			count++;
			continue;
		}
		if (count == 0)
		{
			id = atoi(checkEnd.c_str());
			input >> type >> x >> y >> width >> height >> delay;
			LoadObject(id, type, x, y, width, height, delay, listObject);
		}
	}
}

void AladdinObjects::LoadObject(int id, int type, float x, float y, int width, int height, int delay, vector<LPGAMEOBJECT>* listObject)
{
	x = x - DEVIATION_X;
	switch (type)
	{
	case OBJECT_APPLE:
	{
		Apple* obj = new Apple();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;

	case OBJECT_GOLD:
	{
		Penny* obj = new Penny();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;

	case OBJECT_GENIE_FACE:
	{
		GenieBonusLevel* obj = new GenieBonusLevel();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;

	case OBJECT_GENIE_VASE:
	{
		Vase* obj = new Vase();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;

	case OBJECT_BAT:
	{
		Bat* obj = new Bat();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;

	case OBJECT_NORMAL_PALACE_GUARD:
	{
		NormalPalaceGuard* obj = new NormalPalaceGuard();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;

	case OBJECT_THIN_PALACE_GUARD:
	{
		ThinPalaceGuard* obj = new ThinPalaceGuard();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;

	//case OBJECT_FAT_PALACE_GUARD:
	//	Ground* obj = new Ground();
	//	obj->SetId(id);
	//	obj->SetType(type);
	//	obj->SetPosition(x, y);
	//	obj->SetWidth(width);
	//	obj->SetHeight(height);
	//	listObject->push_back(obj);
	//	break;

	case OBJECT_EXPLODING_SKELETON:
	{
		ExplodingSkeleton* obj = new ExplodingSkeleton();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;

	//case OBJECT_PEDDLER:
	//	Ground* obj = new Ground();
	//	obj->SetId(id);
	//	obj->SetType(type);
	//	obj->SetPosition(x, y);
	//	obj->SetWidth(width);
	//	obj->SetHeight(height);
	//	listObject->push_back(obj);
	//	break;

	case OBJECT_BRICK:
	{
		Brick* obj = new Brick();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		if (delay) {
			obj->setDelay();
		}
		listObject->push_back(obj);
	}
	break;

	case OBJECT_SPIKE_TRAP:
	{
		Trap* obj = new Trap();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		if (delay) {
			obj->setDelay();
		}
		listObject->push_back(obj);
	}
	break;

	case OBJECT_WRECKING_BALL:
	{
		WreckingBall* obj = new WreckingBall();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		if (delay) {
			obj->setDelay();
		}
		listObject->push_back(obj);
	}
	break;
	case OBJECT_CHAINS:
	{
		Chains* obj = new Chains();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}

	break;

	/*case OBJECT_FENCE:
		Ground* obj = new Ground();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
		break;*/
	case OBJECT_ROCK_BAR:
	{
		StoneBar* obj = new StoneBar();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;
	case OBJECT_WOOD:
	{
		Wood* obj = new Wood();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;
	case OBJECT_GROUND:
	{
		Ground* obj = new Ground();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);

	}
	break;
	case OBJECT_PILAR_5:
	{
		Pilar* obj = new Pilar();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetState(PILAR_STATE_5);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;
	case OBJECT_EXIT:
	{
		Exit* obj = new Exit();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetState(EXIT_STATE);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;
	case OBJECT_FANCE:
	{
		Fance* obj = new Fance();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetState(FANCE_STATE);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;
	default:
		break;
	}
}
