#pragma once
#include "Menu.h"
#include "Enemy.h"
#include "Player.h"

class Game
{
public:
	void Start();
	void Loop();


	void FlipGameRunning();

private:
	bool IsGameRunning = false;

	std::string name = "";



};

