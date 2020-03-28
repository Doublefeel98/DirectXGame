#include "CastlevaniaObjects.h"
#include "Define.h"
#include "Brick.h"
#include "Torch.h"
#include "Candle.h"

CastlevaniaObjects::CastlevaniaObjects()
{
}

CastlevaniaObjects::~CastlevaniaObjects()
{
}

void CastlevaniaObjects::Load(string file, vector<LPGAMEOBJECT>* listObject)
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

void CastlevaniaObjects::LoadObject(int id, int type, float x, float y, int width, int height, int delay, vector<LPGAMEOBJECT>* listObject)
{
	x = x;
	switch (type)
	{
	case OBJECT_BRICK_OUT_CASTLE:
	{
		Brick* obj = new Brick();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;
	case OBJECT_TORCH:
	{
		Torch* obj = new Torch();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;
	case OBJECT_BRICK_SENCE_ONE:
	{
		Brick* obj = new Brick();
		obj->SetId(id);
		obj->SetType(type);
		obj->SetPosition(x, y);
		obj->SetWidth(width);
		obj->SetHeight(height);
		listObject->push_back(obj);
	}
	break;
	case OBJECT_CANDLE:
	{
		Candle* obj = new Candle();
		obj->SetId(id);
		obj->SetType(type);
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
