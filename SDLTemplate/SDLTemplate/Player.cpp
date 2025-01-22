#include "Player.h"

Player::~Player()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		delete bullets[i];
	}

	bullets.clear();
}

void Player::start()
{
	texture = loadTexture("gfx/player.png");

	x = 0;
	y = 0;
	width = 0;
	height = 0;
	LowSpeed = 1;
	DefSpeed = LowSpeed;
	HighSpeed = 5;

	reloadTime = 8;
	currentreloadTime = reloadTime;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	sound = SoundManager::loadSound("sound/334227__jradcoolness__laser.ogg");
}

void Player::update()
{
	if (currentreloadTime > 0)
	{
		currentreloadTime--;
	}

	if (app.keyboard[SDL_SCANCODE_F] && currentreloadTime <= 0)
	{
		Bullet* bullet = new Bullet(x + width - 2,
			y + (height / 2) - 5,
			1, 0, 5);
		getScene()->addGameObject(bullet);
		bullet->start();

		bullets.push_back(bullet);

		SoundManager::playSound(sound);

		currentreloadTime = reloadTime;
	}

	if (app.keyboard[SDL_SCANCODE_G] && currentreloadTime <= 0)
	{
		Bullet* bullet = new Bullet(x + width - 2, y + (height / 2) - 20,1, 0, 5);
		Bullet* bullet2 = new Bullet(x + width - 2, y + (height / 2) + 15, 1, 0, 5);
		getScene()->addGameObject(bullet);
		getScene()->addGameObject(bullet2);
		bullet->start();
		bullet2->start();

		bullets.push_back(bullet);
		bullets.push_back(bullet2);

		SoundManager::playSound(sound);

		currentreloadTime = reloadTime - 5;

	}


	

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->getPositionX() > SCREEN_WIDTH)
		{
			Bullet* bulletToErase = bullets[i];
			bullets.erase(bullets.begin() + 1);

			delete bulletToErase;

			break;
		}
	}
	if (app.keyboard[SDL_SCANCODE_W])
	{

		y -= DefSpeed;
	}
	if (app.keyboard[SDL_SCANCODE_S])
	{
		y += DefSpeed;

	}
	if (app.keyboard[SDL_SCANCODE_A])
	{

		x -= DefSpeed;
	}
	if (app.keyboard[SDL_SCANCODE_D])
	{

		x += DefSpeed;
	}
	if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{

		DefSpeed = HighSpeed;
	}
	if (app.keyboard[SDL_SCANCODE_BACKSPACE])
	{

		DefSpeed = LowSpeed;
	}
}

void Player::draw()
{
	blit(texture, x, y);
}
