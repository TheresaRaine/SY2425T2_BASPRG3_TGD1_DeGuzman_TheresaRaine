#include "Player.h"

Player::~Player()
{
	// Memory manage our bullets. Delete all bullets on player deletion/death
	for (int i = 0; i < bullets.size(); i++)
	{
		delete bullets[i];
	}

	bullets.clear();
}

void Player::start()
{
	// Load Texture
	texture = loadTexture("gfx/player.png");

	// Initialize to avaoid garvage values
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	speed = 5;

	reloadTime = 8;
	currentReloadTime = reloadTime;

	// Query the texture to set our width and height
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	// Initialize sound
	sound = SoundManager::loadSound("sound/334227__jradcoolness__laser.ogg");
}

void Player::update()
{
	if (currentReloadTime > 0)
	{
		currentReloadTime--;
	}

	if (app.keyboard[SDL_SCANCODE_SPACE] &&
		currentReloadTime <= 0)
	{
		Bullet* bullet = new Bullet(x + width - 2,
			y + (height / 2) - 5,
			1, 0, 5);

		getScene()->addGameObject(bullet);

		bullets.push_back(bullet);

		SoundManager::playSound(sound);

		currentReloadTime = reloadTime;
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->getPositionX() > SCREEN_WIDTH)
		{
			// Cache the variable so we can delete it later
			// We can't delete it after erasing from the vector (leaked pointer)
			Bullet* bulletToErase = bullets[i];
			bullets.erase(bullets.begin() + i);

			delete bulletToErase;

			// We can't mutate (change) our vector while looping inside it
			// this might crash on the next loop iteration
			// To counter that, we only delete one bullet per frame
			break;
		}
	}

	if (app.keyboard[SDL_SCANCODE_W])
	{
		y -= speed;
	}

	if (app.keyboard[SDL_SCANCODE_S])
	{
		y += speed;
	}

	if (app.keyboard[SDL_SCANCODE_A])
	{
		x -= speed;
	}

	if (app.keyboard[SDL_SCANCODE_D])
	{
		x += speed;
	}
}

void Player::draw()
{
	blit(texture, x, y);
}

int Player::GetPositionX()
{
	return x;
}

int Player::GetPositionY()
{
	return y;
}
