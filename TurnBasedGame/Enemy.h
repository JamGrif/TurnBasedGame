#pragma once
#include "Creature.h"
#include "windows.h"
class Enemy :
	public Creature
{
public:
	Enemy();
	
	void FindPlayersHealth(int PHealth);
	int Choice(); //PHealth is players health
	void EndOfRound();

private:
	int PlayerHealth = 0;

	int AttackChance = 22;
	int SpecialChance = 22;
	int RechargeChance = 12;
	int DodgeChance = 22;
	int HealChance = 22;
	int TotalChance = 0;


};

