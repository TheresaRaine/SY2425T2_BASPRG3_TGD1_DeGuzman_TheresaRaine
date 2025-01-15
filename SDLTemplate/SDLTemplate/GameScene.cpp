#include "GameScene.h"

GameScene::GameScene()
{
	player = new Player();
	this->addGameObject(player);
	// Register and add game objects on constructor
}

GameScene::~GameScene()
{
	delete player;
}

void GameScene::start()
{
	Scene::start();
	// Initialize any scene logic here
}

void GameScene::draw()
{
	Scene::draw();
}

void GameScene::update()
{
	Scene::update();
}
