#include "Creature.h"

Creature::Creature()
{
	//Initalise starting variables
	m_Health = m_MaxHealth;
	m_Energy = m_MaxEnergy;

	m_RechargeAmount = 10;
	m_RechargeTimes = 1;

	m_Alive = true;
}

void Creature::PrintStatus()
{
	//Prints out characters health and energy
	std::cout << m_Name << " is on " << m_Health << " health and has " << m_Energy << " energy!" << std::endl << std::endl;
}

bool Creature::IsAlive()
{
	//Returns if this creature is alive or dead
	return m_Alive;
}

std::string Creature::GetName()
{
	return m_Name;
}

bool Creature::GetHasHealedThisTurn()
{
	return m_HealedThisTurn;
}

int Creature::Outcome(std::string OppName)
{
	switch (m_Action)
	{
		//Attack action
	case Attack:
		std::cout << m_Name << " attempts to attack." << std::endl;
		std::cout << " " << std::endl;
		m_ChanceToHit = 60;
		m_ChanceToHit = m_ChanceToHit + m_ChangeToHitChance;
		if (m_ChanceToHit > m_MaxChance) 
		{
			m_ChanceToHit = m_MaxChance;
		}
		RolledNumber = (1 + (rand() % m_MaxChance));
		if (RolledNumber > m_MinChance && RolledNumber <= m_ChanceToHit)  //Character successfully hit
		{
			m_Damage = (1 + (rand() % 10)); //The damage amount is randomly generated. Only between 1 and 10
			std::cout << m_Name << " successfully hit " << OppName << " dealing " << m_Damage << " damage!" << std::endl;
		}
		else
		{
			//Missed
			std::cout << m_Name << " swung their sword and missed!" << std::endl;
		}
		return m_Damage;

		//Special action
	case Special:
		std::cout << m_Name << " attempts to perform a special attack!" << std::endl;
		if (m_Energy == m_MaxEnergy) //Character can perform a special attack 
		{
			m_ChanceToHit = 40;
			m_ChanceToHit = m_ChanceToHit + m_ChangeToHitChance;
			if (m_ChanceToHit > m_MaxChance)
			{
				m_ChanceToHit = m_MaxChance;
			}
			m_Energy = m_Energy - 50;
			RolledNumber = (1 + (rand() % m_MaxChance));
			if (RolledNumber > m_MinChance && RolledNumber <= m_ChanceToHit)
			{
				m_Damage = (1 + (rand() % 20));
				if (m_Damage <= 4) //Special attack deals between 5 and 20 damage. If rolled damage number is smaller then 4 then 4 is applied to the number
				{
					m_Damage += 4;
				}
				//Player hit computer with special
				std::cout << m_Name << " successfully hit " << OppName << " dealing " << m_Damage << " damage!" << std::endl;
			}
			else
			{
				//The player has missed
				std::cout << m_Name << " attempted to perform a special attack but missed!" << std::endl;

			}

			std::cout << m_Name << "'s energy has been drained as a result of performing the special attack!" << std::endl;


		}
		return m_Damage;

		//Recharge action
	case Recharge:
		std::cout << m_Name << " attempts to re-charge their energy!" << std::endl;
		//Player will recharge more energy at the end of the round but be more likely to get hit
		std::cout << m_Name << " will recharge additional energy this turn! But is more vulnerable to attacks!" << std::endl;
		m_RechargeTimes = 4;
		m_ChangeToHitChance = 10;
		return m_ChangeToHitChance;

		//Dodge action
	case Dodge: //TO DO -------------------------------------------------------------------------------------------------------------------------------------
		//Player will try to dodge next attack but be more likely to get hit
		std::cout << m_Name << " will attempt to dodge the next attack!" << std::endl;
		m_ChangeToHitChance = -20;
		return m_ChangeToHitChance;

		//Heal action
	case Heal: //Trades 20 energy to heal 10 points
		m_Energy = m_Energy - 20;
		if (m_Energy < m_MinEnergy) 
		{
			m_Energy = m_MinEnergy;
		}
		m_Health = m_Health + 10;
		if (m_Health > m_MaxHealth) 
		{
			m_Health = m_MaxHealth;
		}
		//Player has healed for half of their total energy 
		std::cout << m_Name << " has healed for 10!" << std::endl;
		m_HealedThisTurn = true;
		return 0;
	}
}

void Creature::Response(int actionNo, int actionAmount)
{
	if (actionNo == 1 || actionNo == 2) //Take damage
	{
		m_Health = m_Health - actionAmount;
		if (m_Health <= m_MinHealth) 
		{
			m_Alive = false;
		}
	}
	else if  (actionNo == 3) //Recharge. 10% more likely to be hit opponent
	{
		m_ChangeToHitChance = actionAmount;
	}
	else //Dodge //20% more likely to miss target
	{
		m_ChangeToHitChance = actionAmount;
	}
}


