#pragma once
#include <iostream>
#include <string>
class Creature
{
public:
	enum Action{Attack=1, Special=2, Recharge=3, Dodge=4, Heal=5};
	Creature();

	void PrintStatus();

	virtual int Choice()=0; //Used to decide what action to take. User inputs a key / computer uses algorthirm to determine best action to take
	int Outcome(std::string OppName); //Once action is selected it is performed
	void Response(int actionNo, int actionAmount); //Used to alter the stats of a character if they have been damaged or changed chance to hit
	virtual void EndOfRound()=0; //Used to reset any values that were used by characters

	
	bool IsAlive();
	std::string GetName();
	bool GetHasHealedThisTurn();

protected:
	//Health
	int m_Health = 0;
	const int m_MinHealth = 0;
	const int m_MaxHealth = 100;

	//Energy
	int m_Energy = 0;
	const int m_MinEnergy = 0;
	const int m_MaxEnergy = 50;

	//Hit chance
	int m_ChanceToHit = 0;
	const int m_MaxChance = 100; 
	const int m_MinChance = 0;
	int m_ChangeToHitChance = 0;

	//Recharge
	int m_RechargeAmount = 0;
	int m_RechargeTimes = 0;

	//Misc
	std::string m_Name = "";
	int m_Action = 0;

	//Output from random number generator 
	int RolledNumber = 0;
	
	//Sent to the other character 
	int m_Damage = 0;

	bool m_Alive = false;
	bool m_HealedThisTurn = false;


};

