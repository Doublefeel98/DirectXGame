#include"Texture.h"

Texture* Texture::instance;

Texture::Texture()
{
	LoadAllSourceRect();
	LoadAllTexture();
}

Texture::~Texture()
{
}
Texture* Texture::Instance()
{
	if (!instance)
		instance = new Texture();
	return instance;
}
vector<RECT*> Texture::LoadSourceRects(char* path) {
	vector<RECT*> list_source_rect;

	fstream f;
	f.open(path, ios::in);

	int number_of_source_rect;
	string data;

	getline(f, data);
	stringstream stream_data;
	stream_data << data;
	stream_data >> number_of_source_rect;

	for (int i = 0; i < number_of_source_rect; i++)
	{
		data = "";
		stream_data.clear();

		getline(f, data);
		stream_data << data;

		RECT* r = new RECT();
		stream_data >> r->top;
		stream_data >> r->bottom;
		stream_data >> r->left;
		stream_data >> r->right;
	
		list_source_rect.push_back(r);
	}
	f.close();
	return list_source_rect;
}
void Texture::LoadAllSourceRect() {
	fstream f;
	f.open("C:\\Users\\ngoho\\Desktop\\sprites.txt", ios::in);


	int number_of_sprite;
	string data;
	getline(f, data);
	stringstream stream_data;
	stream_data << data;
	stream_data >> number_of_sprite;

	int type_sprite, number_of_source_rect;
	for (int i = 0; i < number_of_sprite; i++)
	{
		
		data = "";
		stream_data.clear();

		getline(f, data);
		stream_data << data;

		stream_data >> type_sprite >> number_of_source_rect;
		
		for (int t = 0; t < number_of_source_rect; t++) {

			data = "";
			stream_data.clear();

			getline(f, data);
			stream_data << data;

			RECT* r = new RECT();
			stream_data >> r->top;
			stream_data >> r->bottom;
			stream_data >> r->left;
			stream_data >> r->right;

			this->SourceRects[(TypeSprite)type_sprite].push_back(r);
		}
		getline(f, data);
	}
	RECT* r = new RECT();
	r->top = 500;
	r->bottom = 548;
	r->left = 378;
	r->right = 431;
	this->SourceRects[SALADINKNEELSTAY].push_back(r);

	r->top = 6;
	r->bottom = 58;
	r->left = 3;
	r->right = 39;
	this->SourceRects[SALADINSTAND].push_back(r);

	r->top = 45;
	r->bottom = 96;
	r->left = 335;
	r->right = 372;
	this->SourceRects[SFACE].push_back(r);

	r->top = 424;
	r->bottom = 461;
	r->left = 19;
	r->right = 38;
	this->SourceRects[SVASE].push_back(r);
	f.close();
}
void Texture::LoadAllTexture() {
	//// ALADIN
	Textures[TALADIN] = new MyTexture((char*)"C:\\Users\\ngoho\\Downloads\\aladin.png", D3DCOLOR_XRGB(255, 0, 255));
	Textures[TBAT] = new MyTexture((char*)"C:\\Users\\ngoho\\Downloads\\bat.png", D3DCOLOR_XRGB(255, 0, 255));
	Textures[TGUARD] = new MyTexture((char*)"C:\\Users\\ngoho\\Downloads\\guard.png", D3DCOLOR_XRGB(120, 193, 152));
	Textures[TSKELETON] = new MyTexture((char*)"C:\\Users\\ngoho\\Downloads\\skeleton.png", D3DCOLOR_XRGB(255, 0, 255));
	Textures[TBIRD] = new MyTexture((char*)"C:\\Users\\ngoho\\Downloads\\bird.png", D3DCOLOR_XRGB(120, 193, 152));
	Textures[TJAFAR] = new MyTexture((char*)"C:\\Users\\ngoho\\Downloads\\jafar.png", D3DCOLOR_XRGB(186, 254, 202));
	Textures[TSMOKE] = new MyTexture((char*)"C:\\Users\\ngoho\\Downloads\\smoke.png", D3DCOLOR_XRGB(186, 254, 202));
	Textures[TITEMS] = new MyTexture((char*)"C:\\Users\\ngoho\\Downloads\\items.png", D3DCOLOR_XRGB(248, 0, 248));
	Textures[TMAP] = new MyTexture((char*)"C:\\Users\\ngoho\\Downloads\\map.png", D3DCOLOR_XRGB(163, 73, 164));
	
	//// Jafar

	//// Palace Guards

	//// Explosive Skeleton

	//// Bat

	//// Iago

	//// Items
}

vector<RECT*> Texture::GetSourceRect(TypeSprite type_sprite)
{
	return this->SourceRects[type_sprite];
}

MyTexture* Texture::GetTexture(TypeTexture type_texture)
{
	return Textures[type_texture];
}