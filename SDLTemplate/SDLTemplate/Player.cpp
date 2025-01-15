#include "Player.h"

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

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void Player::update()
{
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
