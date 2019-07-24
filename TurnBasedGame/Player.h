#pragma once
#include "Creature.h"
class Player :
	public Creature
{
public:
	Player(std::string name);
	
	int Choice();
	void EndOfRound();
	int GetHealth();



private:
	

};

