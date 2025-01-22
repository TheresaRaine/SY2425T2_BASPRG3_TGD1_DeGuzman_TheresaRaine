#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "SoundManager.h"
#include "Bullet.h"
#include "Scene.h"



class Player : public GameObject
{
public:
	~Player();
	void start();
	void update();
	void draw();
	
private:
	int x;
	int y;
	int width;
	int height;
	int speed;
	int DefSpeed;
	int HighSpeed;
	int LowSpeed;


	float reloadTime;
	float currentreloadTime;

	SDL_Texture* texture;
	Mix_Chunk* sound;

	std::vector<Bullet*> bullets;
};

