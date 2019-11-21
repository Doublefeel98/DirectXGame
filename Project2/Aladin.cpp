#include"Aladin.h"
Aladin* Aladin::instance;

Aladin::Aladin() {
	x = 40 * G_Scale.x;
	y = (40 +ADDITIONS) * G_Scale.y;
	_x = this->x / G_Scale.x;
	_y = 2270 - (this->y / G_Scale.y)+11;

	vy = 0;
	this->isGround = IsGround(0);
	this->isAllowedClimb = true;
	this->direction = RIGHT;
	this->hitpoints = HP;
	this->state = STAND;

	//lifebar = new Animation();
	//penny = new Animation();
	LoadResource();
}
Aladin::~Aladin() {

}
void Aladin::GetPosition(float& x, float& y) {
	x = this->x;
	y = this->y;
}
void Aladin::LoadResource() {
	MyTexture* texture = Texture::Instance()->GetTexture(TALADIN);

	vector<RECT*> climb = Texture::Instance()->GetSourceRect(SALADINCLIMB);
	animation->Sprites[State::CLIMB] = new Sprite(texture, climb, 1);
	
	vector<RECT*> dodge = Texture::Instance()->GetSourceRect(SALADINDODGE);
	animation->Sprites[State::DODGE] = new Sprite(texture, dodge, 1);

	vector<RECT*> dodgestand = Texture::Instance()->GetSourceRect(SALADINDODGESTAND);
	animation->Sprites[State::DODGESTAND] = new Sprite(texture, dodgestand, 1);

	vector<RECT*> fly = Texture::Instance()->GetSourceRect(SALADINFLY);
	animation->Sprites[State::FLY] = new Sprite(texture, fly, 1);

	vector<RECT*> jumpland = Texture::Instance()->GetSourceRect(SALADINJUMPLAND);
	animation->Sprites[State::JUMPLAND] = new Sprite(texture, jumpland, 2);

	vector<RECT*> jumpslice = Texture::Instance()->GetSourceRect(SALADINJUMPSLICE);
	animation->Sprites[State::JUMPSLICE] = new Sprite(texture, jumpslice, 1);

	vector<RECT*> kneel = Texture::Instance()->GetSourceRect(SALADINKNEEL);
	animation->Sprites[State::KNEEL] = new Sprite(texture, kneel, 1);

	vector<RECT*> kneeldodge = Texture::Instance()->GetSourceRect(SALADINKNEELDODGE);
	animation->Sprites[State::KNEELDODGE] = new Sprite(texture, kneeldodge, 1);

	vector<RECT*> kneelslice = Texture::Instance()->GetSourceRect(SALADINKNEELSLICE);
	animation->Sprites[State::KNEELSLICE] = new Sprite(texture, kneelslice, 1);

	vector<RECT*> kneelthrow = Texture::Instance()->GetSourceRect(SALADINKNEELTHROW);
	animation->Sprites[State::KNEELTHROW] = new Sprite(texture, kneelthrow, 1);

	vector<RECT*> land = Texture::Instance()->GetSourceRect(SALADINLAND);
	animation->Sprites[State::LAND] = new Sprite(texture, land, 1);

	vector<RECT*> look = Texture::Instance()->GetSourceRect(SALADINLOOKAROUND);
	animation->Sprites[State::LOOKAROUND] = new Sprite(texture, look, 1);

	vector<RECT*> run = Texture::Instance()->GetSourceRect(SALADINRUN);
	animation->Sprites[State::RUN] = new Sprite(texture, run, 1);

	vector<RECT*> slice = Texture::Instance()->GetSourceRect(SALADINSLICE);
	animation->Sprites[State::SLICE] = new Sprite(texture, slice, 1);

	vector<RECT*> slice2 = Texture::Instance()->GetSourceRect(SALADINSLICE2SIDES);
	animation->Sprites[State::SLICE2SIDES] = new Sprite(texture, slice2, 1);

	vector<RECT*> stop = Texture::Instance()->GetSourceRect(SALADINSTOPRUN);
	animation->Sprites[State::STOPRUN] = new Sprite(texture, stop, 1);

	vector<RECT*> _throw = Texture::Instance()->GetSourceRect(SALADINTHROW);
	animation->Sprites[State::THROW] = new Sprite(texture, _throw, 1);

	vector<RECT*> stand = Texture::Instance()->GetSourceRect(SALADINSTAND);
	animation->Sprites[State::STAND] = new Sprite(texture, stand, 1);

	vector<RECT*> kneelstay = Texture::Instance()->GetSourceRect(SALADINKNEELSTAY);
	animation->Sprites[State::KNEELSTAY] = new Sprite(texture, kneelstay, 1);

}
Aladin* Aladin::Instance() {
	if (!instance) {
		instance = new Aladin();
	}
	return instance;
}
void Aladin::Update(DWORD dt, vector<Object*>* list) {
	if (this->hitpoints <= 0) {
		this->destroyed = true;
		this->state = DIE;
		Camera::Instance()->SetLocked(true);
	}
	
	//vy += GRAVITY * dt;
	Object::Update(dt, list);

	x += dx;
	y += dy;


}
/*void Aladin::ProcessBullet(list<Bullet*> list) {
	for (Bullet * o : list) {
		bool r;
		r = Collision::Instance()->CollisionAABB(this->GetBoundingBox(), o->GetBoundingBox());
		if (r) {
			if (o->GetNameObject() == FACE) {
				o->Reaction();
			}
			else if (o->GetNameObject() == APPLE) {
				this->AddApple();
				o->React();
			}
			else if (o->GetNameObject() == PENNY) {
				this->AddPenny();
				o->React();
			}
			else {
				this->hitpoints -= o->GetDamage();
				o->React();
			}
		}
	}
}
*/
void Aladin::ProcessEnemy(vector<Object*> list) {
	for (Object* o : list) {
		if (((ActionObject*)o)->IsDestroyed()) continue;

		bool r;
		r = Collision::Instance()->CollisionAABB(this->GetBoundingBox(), o->GetBoundingBox());
		if (r) {
			this->hitpoints -= ((ActionObject*)o)->GetDamage();
		}
	}
}
void Aladin::ProcessStatic(vector<Object*>list) {
	for (Object* o : list) {
		if (o->GetNameObject() == APPLE) {
			bool r;
			r = Collision::Instance()->CollisionAABB(this->GetBoundingBox(), o->GetBoundingBox());

			if (r) {
				this->apples += 1;
			}

			continue;
		}
		if (o->GetNameObject() == PENNY) {
			bool r;
			r = Collision::Instance()->CollisionAABB(this->GetBoundingBox(), o->GetBoundingBox());

			if (r) {
				this->pennies += 1;
			}

			continue;
		}
		if (o->GetNameObject() == LIFE) {
			bool r;
			r = Collision::Instance()->CollisionAABB(this->GetBoundingBox(), o->GetBoundingBox());

			if (r) {
				this->life += 1;
			}

			continue;
		}
		//if (o->GetNameObject() == VASE) {
		//	bool r;
		//	r = Collision::Instance()->CollisionAABB(this->GetBoundingBox(), O->GetBoundingBox());
		//
		//	if (r) {
		//		o->Active();
		//	}
		//
		//	continue;
		//}
		//if (o->GetNameObject() == FACE) {
		//	bool r;
		//	r = Collision::Instance()->CollisionAABB(this->GetBoundingBox(), O->GetBoundingBox());
		//
		//	if (r) {
		//		o->Active();
		//	}
		//
		//	continue;
		//}
	}
}
void Aladin::Render() {
	D3DXVECTOR2 position = Camera::Instance()->GetPositionInViewPort(x, y);

	if (this->state == RUN)
	{
		if (this->animation->Sprites[state]->IsFinalFrame())
			this->animation->Sprites[state]->Set_current_frame(2);
	}
	animation->Render(state, direction, position);
	animation->Next(state);
}

BoundingBox Aladin::GetBoundingBox()
{
	BoundingBox bound;
	bound.x = x - WIDTH / 2;
	bound.y = y - HEIGHT / 2;
	bound.w = WIDTH;
	bound.h = HEIGHT;
	bound.vx = dx;
	bound.vy = dy;
	return bound;
}
State Aladin::GetState()
{
	return state;
}
Direction Aladin::GetDirection()
{
	return direction;
}
void Aladin::SetState(State s) {
	if (this->state != s)
		this->animation->Refresh(this->state);
	State preState = this->state;
	switch (s) {
	case RUN:
		vx = (this->direction == RIGHT) ? WALK_SPEED : -WALK_SPEED;
		this->state = RUN;
		break;
	case STAND:
		vx = 0;
		this->state = STAND;
		break;
	case THROW:
	case SLICE:
	case SLICE2SIDES:
	case DODGE:
	case KNEEL:
	case KNEELTHROW:
	case KNEELSLICE:
	case JUMPLAND:
	case FLY:
	case LAND:
	case JUMPSLICE:
	case STOPRUN:
	case CLIMB:
	case KNEELDODGE:
	case DODGESTAND:
		this->state = s;
		break;
	}
}

State Aladin::GetNewState(State currentState, EController controller) {
	State new_state = currentState;
	int temp;
	if (!IsGround(0)) {
		switch (controller)
		{
		case NoneControl:
			new_state = JUMPLAND;
			break;
		case LeftControl:
			break;
		case RightControl:
			break;
		case SliceControl:
			new_state = SLICE;
			break;
		case JumpControl:
			new_state = JUMPLAND;
			vy = WALK_SPEED;
			//startJumping = GetTickCount();
			yStartJump = this->y;
			break;
		case KneelControl:
			new_state = KNEEL;
			break;
		case ThrowControl:
			new_state = THROW;
			break;
		default:
			break;
		}
	}
	switch (currentState) {
	case RUN:
		switch (controller)
		{
		case NoneControl:
			new_state = STAND;
			break;
		case LeftControl:
			break;
		case RightControl:
			break;
		case SliceControl:
			new_state = SLICE;
			break;
		case JumpControl:
			new_state = JUMPLAND;
			vy = WALK_SPEED;
			//startJumping = GetTickCount();
			yStartJump = this->y;
			break;
		case KneelControl:
			new_state = KNEEL;
			break;
		case ThrowControl:
			new_state = THROW;
			break;
		default:
			break;
		}
		break;
	case LOOKAROUND:
		switch (controller)
		{
		case NoneControl:
			break;
		case LeftControl:
			new_state = RUN;
			break;
		case RightControl:
			new_state = RUN;
			break;
		case SliceControl:
			new_state = SLICE;
			break;
		case JumpControl:
			new_state = JUMPLAND;
			vy = WALK_SPEED;
			//startJumping = GetTickCount();
			yStartJump = this->y;

			break;
		case KneelControl:
			new_state = KNEEL;
			break;
		case ThrowControl:
			new_state = THROW;
			break;
		default:
			break;
		}
		break;
	case THROW:
		switch (controller)
		{
		case NoneControl:
			if(this->animation->Sprites[THROW]->IsFinalFrame())
				new_state = STAND;
			break;
		case LeftControl:
			if (this->animation->Sprites[THROW]->IsFinalFrame())
				new_state = RUN;
			break;
		case RightControl:
			if (this->animation->Sprites[THROW]->IsFinalFrame())
				new_state = RUN;
			break;
		case SliceControl:
			if (this->animation->Sprites[THROW]->IsFinalFrame())
				new_state = SLICE;
			break;
		case JumpControl:
			if (this->animation->Sprites[THROW]->IsFinalFrame()) {
				new_state = JUMPLAND;
				vy = WALK_SPEED;
				//startJumping = GetTickCount();
				yStartJump = this->y;
			}
			break;
		case KneelControl:
			if (this->animation->Sprites[THROW]->IsFinalFrame())
				new_state = KNEEL;
			break;
		case ThrowControl:
			if (this->animation->Sprites[THROW]->IsFinalFrame())
				new_state = THROW;
			break;
		default:
			break;
		}
		break;
	case KNEEL:
		switch (controller)
		{
		case NoneControl:
			if (this->animation->Sprites[KNEEL]->IsFinalFrame())
				this->state = STAND;
			break;
		case LeftControl:
			if (this->animation->Sprites[KNEEL]->IsFinalFrame())
				new_state = RUN;
			break;
		case RightControl:
			if (this->animation->Sprites[KNEEL]->IsFinalFrame())
				new_state = RUN;
			break;
		case SliceControl:
			if (this->animation->Sprites[KNEEL]->IsFinalFrame())
				new_state = KNEELSLICE;
			break;
		case JumpControl:
			if (this->animation->Sprites[KNEEL]->IsFinalFrame()) {
				new_state = JUMPLAND;
				vy = WALK_SPEED;
				//startJumping = GetTickCount();
				yStartJump = this->y;
			}
			break;
		case KneelControl:
			if (this->animation->Sprites[KNEEL]->IsFinalFrame())
				new_state = KNEELSTAY;
			break;
		case ThrowControl:
			if (this->animation->Sprites[KNEEL]->IsFinalFrame())
				new_state = KNEELTHROW;
			break;
		default:
			break;
		}
		break;
	case KNEELSTAY:
		switch (controller)
		{
		case NoneControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				this->state = STAND;
			break;
		case LeftControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = RUN;
			break;
		case RightControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = RUN;
			break;
		case SliceControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = KNEELSLICE;
			break;
		case JumpControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame()) {
				new_state = JUMPLAND;
				vy = WALK_SPEED;
				startJumping = GetTickCount();
				yStartJump = this->y;
			}
			break;
		case KneelControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = KNEELSTAY;
			break;
		case ThrowControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = KNEELTHROW;
			break;
		default:
			break;
		}
		break;
	case KNEELTHROW:
	case KNEELSLICE:
	case KNEELDODGE:
		switch (controller)
		{
		case NoneControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = STAND;
			break;
		case LeftControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = RUN;
			break;
		case RightControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = RUN;
			break;
		case SliceControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = SLICE;
			break;
		case JumpControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame()) {
				new_state = JUMPLAND;
				vy = WALK_SPEED;
				startJumping = GetTickCount();
				yStartJump = this->y;
			}
			break;
		case KneelControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = KNEELSTAY;
			break;
		case ThrowControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = THROW;
			break;
		default:
			break;
		}
		break;
	case JUMPLAND:
		switch (controller)
		{
		case NoneControl:
			//if (this->animation->Sprites[currentState]->IsFinalFrame()) {
			//	new_state = STAND;
			//}
			//else 
			if (IsGround(0)) {
				vy = 0;
				new_state = STAND;
			}
			else {
				if (vy > 0+GRAVITY) {
					vy += GRAVITY;
					this->animation->Sprites[currentState]->Set_current_frame(2);
				}
				else if(vy>=(-WALK_SPEED-GRAVITY)){
					if (this->animation->Sprites[currentState]->GetCurrentFrame() >=6) {
						this->animation->Sprites[currentState]->Set_current_frame(7);
					}
					vy += GRAVITY;
				}
				else if (vy == -WALK_SPEED) {
					this->animation->Sprites[currentState]->Set_current_frame(7);
					vy = -WALK_SPEED;
				}
			}
			break;
		case LeftControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = RUN;
			break;
		case RightControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = RUN;
			break;
		case SliceControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = SLICE;
			break;
		case JumpControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame()) {
				new_state = JUMPLAND;
				vy = WALK_SPEED;
				startJumping = GetTickCount();
				yStartJump = this->y;

			}
			else {
				vy -= GRAVITY*(this->animation->Sprites[currentState]->GetCurrentFrame());
			}
			break;
		case KneelControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = KNEEL;
			break;
		case ThrowControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = THROW;
			break;
		default:
			break;
		}
		break;
	case SLICE:
	case SLICE2SIDES:
	case DODGE:
	case DODGESTAND:
	case STAND:
		switch (controller)
		{
		case NoneControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = STAND;
			break;
		case LeftControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = RUN;
			break;
		case RightControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = RUN;
			break;
		case SliceControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = SLICE;
			break;
		case JumpControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame()) {
				new_state = JUMPLAND;
				vy = WALK_SPEED;
				startJumping = GetTickCount();
				yStartJump = this->y;

			}
			break;
		case KneelControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = KNEEL;
			break;
		case ThrowControl:
			if (this->animation->Sprites[currentState]->IsFinalFrame())
				new_state = THROW;
			break;
		default:
			break;
		}
		break;
	case FLY:
	case LAND:
	case JUMPSLICE:
	case STOPRUN:
	case CLIMB:
		break;
	default:
		break;
		/*
		,
	,
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
	DODGESTAND,*/
	}

	return new_state;
}

void Aladin::SetDirection(Direction d)
{
	//==============auto moving when open door, door control===============
	
	switch (state)
	{
	case RUN:
		vx = (this->direction == RIGHT) ? WALK_SPEED : -WALK_SPEED;
		break;
	case FLY:
		vx *= (this->direction == d) ? 1 : -1;
		break;
	}

	this->direction = d;
}
bool Aladin::IsGround(int dis) {
	_x = this->x / G_Scale.x;
	_y = 2270 - (this->y/G_Scale.y) + 11;
	return 
		((_y <= 290) && (_y >= 287) && _x >= 0 && _x <= 104) ||
		((_y <= 1098)&& (_y >= 1095) && _x >= 0 && _x <= 2270) ||
		((_y <= 233) && (_y >= 230) && _x >= 129 && _x <= 270) ||
		((_y <= 273) && (_y >= 270) && _x >= 259 && _x <= 386) ||
		((_y <= 227) && (_y >= 224) && _x >= 362 && _x <= 466) ||
		((_y <= 290) && (_y >= 287) && _x >= 441 && _x <= 558) ||
		((_y <= 217) && (_y >= 214) && _x >= 769 && _x <= 912) ||
		((_y <= 273) && (_y >= 269) && _x >= 930 && _x <= 1119) ||
		((_y <= 209) && (_y >= 206) && _x >= 1098 && _x <= 1263) ||
		((_y <= 257) && (_y >= 254) && _x >= 1306 && _x <= 1411) ||
		((_y <= 208) && (_y >= 205) && _x >= 1386 && _x <= 1555) ||
		((_y <= 241) && (_y >= 238) && _x >= 1874 && _x <= 2129) ||
		((_y <= 211) && (_y >= 208) && _x >= 2082 && _x <= 2270) ||
		((_y <= 449) && (_y >= 446) && _x >= 2033 && _x <= 2270) ||
		((_y <= 593) && (_y >= 590) && _x >= 2088 && _x <= 2270) ||
		((_y <= 369) && (_y >= 366) && _x >= 1792 && _x <= 1950) ||
		((_y <= 529) && (_y >= 526) && _x >= 1618 && _x <= 1792) ||
		((_y <= 369) && (_y >= 366) && _x >= 1232 && _x <= 1728) ||
		((_y <= 320) && (_y >= 327) && _x >= 1161 && _x <= 1261) ||
		((_y <= 482) && (_y >= 479) && _x >= 1065 && _x <= 1231) ||
		((_y <= 449) && (_y >= 446) && _x >= 945 && _x <= 1107) ||
		((_y <= 513) && (_y >= 510) && _x >= 873 && _x <= 970) ||
		((_y <= 313) && (_y >= 310) && _x >= 852 && _x <= 313) ||
		((_y <= 337) && (_y >= 334) && _x >= 769 && _x <= 909) ||
		((_y <= 370) && (_y >= 367) && _x >= 706 && _x <= 790) ||
		((_y <= 586) && (_y >= 583) && _x >= 544 && _x <= 911) ||
		((_y <= 417) && (_y >= 414) && _x >= 619 && _x <= 722) ||
		((_y <= 457) && (_y >= 454) && _x >= 425 && _x <= 639) ||
		((_y <= 370) && (_y >= 367) && _x >= 314 && _x <= 435) ||
		((_y <= 353) && (_y >= 350) && _x >= 142 && _x <= 262) ||
		((_y <= 555) && (_y >= 552) && _x >= 130 && _x <= 270) ||
		((_y <= 497) && (_y >= 494) && _x >= 0 && _x <= 104) ||
		((_y <= 705) && (_y >= 702) && _x >= 0 && _x <= 141) ||
		((_y <= 754) && (_y >= 751) && _x >= 131 && _x <= 255) ||
		((_y <= 864) && (_y >= 861) && _x >= 243 && _x <= 354) ||
		((_y <= 817) && (_y >= 814) && _x >= 426 && _x <= 615) ||
		((_y <= 705) && (_y >= 702) && _x >= 450 && _x <= 780) ||
		((_y <= 738) && (_y >= 735) && _x >= 761 && _x <= 883) ||
		((_y <= 705) && (_y >= 702) && _x >= 865 && _x <= 957) ||
		((_y <= 673) && (_y >= 670) && _x >= 945 && _x <= 1009) ||
		((_y <= 768) && (_y >= 765) && _x >= 1050 && _x <= 1114) ||
		((_y <= 833) && (_y >= 830) && _x >= 905 && _x <= 1117) ||
		((_y <= 688) && (_y >= 685) && _x >= 1113 && _x <= 1277) ||
		((_y <= 753) && (_y >= 750) && _x >= 1243 && _x <= 1395) ||
		((_y <= 817) && (_y >= 814) && _x >= 1321 && _x <= 1418) ||
		((_y <= 608) && (_y >= 605) && _x >= 1393 && _x <= 1625) ||
		((_y <= 721) && (_y >= 718) && _x >= 1562 && _x <= 1674) ||
		((_y <= 865) && (_y >= 862) && _x >= 1425 && _x <= 1496) ||
		((_y <= 769) && (_y >= 766) && _x >= 1638 && _x <= 1818) ||
		((_y <= 608) && (_y >= 605) && _x >= 1767 && _x <= 1950) ||
		((_y <= 849) && (_y >= 846) && _x >= 1846 && _x <= 1903) ||
		((_y <= 593) && (_y >= 590) && _x >= 2089 && _x <= 2270) ||
		((_y <= 705) && (_y >= 702) && _x >= 2147 && _x <= 2270) ||
		((_y <= 817) && (_y >= 814) && _x >= 2178 && _x <= 2270) ||
		((_y <= 1025) && (_y>= 1022) && _x >= 1785 && _x <= 1965) ||
		((_y <= 928) && (_y >= 925) && _x >= 1409 && _x <= 1491) ||
		((_y <= 976) && (_y >= 973) && _x >= 1565 && _x <= 1819) ||
		((_y <= 913) && (_y >= 910) && _x >= 1113 && _x <= 1229) ||
		((_y <= 913) && (_y >= 910) && _x >= 449 && _x <= 933) ||
		((_y <= 898) && (_y >= 895) && _x >= 339 && _x <= 481) ||
		((_y <= 864) && (_y >= 861) && _x >= 243 && _x <= 354);
}
bool Aladin::IsChain() {
	float x = this->x;
	float y= this->y;
	return (x == 89 && y <= 892 && y >= 717) ||
		(x == 136 && y <= 972 && y >= 767) ||
		(x == 314 && y <= 997 && y >= 885) ||
		(x == 88 && y <= 662 && y >= 510) ||
		(x == 473 && y <= 670 && y >= 470) ||
		(x == 281 && y <= 589 && y >= 294) ||
		(x == 90 && y <= 453 && y >= 300) ||
		(x == 1049 && y <= 635 && y >= 471) ||
		(x == 1657 && y <= 686 && y >= 550) ||
		(x == 1802 && y <= 917 && y >= 791) ||
		(x == 2058 && y <= 693 && y >= 471) ||
		(x == 1930 && y <= 550 && y >= 385) ||
		(x == 2073 && y <= 396 && y >= 263);

}