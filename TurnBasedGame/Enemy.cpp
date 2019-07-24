#include "Enemy.h"

Enemy::Enemy()
{
	m_Name = "Knight";
}

void Enemy::FindPlayersHealth(int PHealth)
{
	PlayerHealth = PHealth;
}

int Enemy::Choice()
{
	// significantly = 15 while slightly = 5
	std::cout << m_Name << " is deciding what action to use..." << std::endl << std::endl;
	Sleep(1000);
	//% chance of each action is calculated first ------------------------------------------------------------------------------------------------------
	if ((m_Health == m_MaxHealth) || (m_HealedThisTurn == true) || (m_Energy <= 1))	//This means the computer will not heal this round because they either don't need to, already healed this turn or don't have enough energy
	{
		HealChance = 0;
	}
	if (m_Energy == m_MaxEnergy) // This means the computer will not recharge this round because they are already at maximum energy
	{
		RechargeChance = 0;
	}
	if (m_Energy != 50) //This means the computer will not use their special attack as they do not have enough energy
	{
		SpecialChance = 0;
	}
	//The code above will run no matter what
	if (PlayerHealth <= m_MaxHealth / 4) //If the players health is low the computer will attempt to kill them quickly
	{
		AttackChance = AttackChance + 15;
		if (SpecialChance != 0)
		{
			SpecialChance = SpecialChance + 5;
		}

		if (m_Health <= (m_MaxHealth / 4)) //Additionally if the computers health is also low their healing and dodge chance is also slightly increased
		{
			DodgeChance = DodgeChance + 5;
			if (HealChance != 0)
			{
				HealChance = HealChance + 5;
			}

		}

		if (RechargeChance != 0) //This means the computer will not use their special attack as they do not have enough energy
		{
			RechargeChance = RechargeChance / 2;
		}

	}

	//If the players health is not less then 25% then the computer will go into a larger algorithm which changes chances of different actions depending on the computers health
	if ((m_Health <= m_MaxHealth) && (m_Health >= 85)) //This happens if the computers health is between 100 and 85
	{
		AttackChance = AttackChance + 15;
		if (SpecialChance != 0)
		{
			SpecialChance = SpecialChance + 15;
		}
		DodgeChance = 0;
		HealChance = 0;
	}
	else if ((m_Health <= 84) && (m_Health >= 75)) //This happens if the computers health is between 84 and 75
	{
		AttackChance = AttackChance + 15;
		if (SpecialChance != 0)
		{
			SpecialChance = SpecialChance + 15;
		}
		DodgeChance = DodgeChance - 15;
		if (HealChance != 0)
		{
			HealChance = HealChance - 15;
		}
	}
	else if ((m_Health <= 74) && (m_Health >= 50)) //This happens if the computers health is between 74 and 50
	{
		AttackChance = AttackChance + 5;
		if (SpecialChance != 0)
		{
			SpecialChance = SpecialChance + 5;
		}
		DodgeChance = DodgeChance + 5;
		if (HealChance != 0)
		{
			HealChance = HealChance + 5;
		}
	}
	else if ((m_Health <= 49) && (m_Health >= 25)) //This happens if the computers health is between 49 and 25
	{
		AttackChance = AttackChance - 15;
		if (SpecialChance != 0)
		{
			SpecialChance = SpecialChance - 15;
		}
		DodgeChance = DodgeChance + 15;
		if (HealChance != 0)
		{
			HealChance = HealChance + 15;
		}
	}
	else //This happens if the computers health is below 25
	{
		DodgeChance = DodgeChance + 15;
		if (HealChance != 0)
		{
			HealChance = HealChance + 15;
		}
		AttackChance = 0;
		SpecialChance = 0;
	}
	if ((m_Energy < m_MaxEnergy) && (m_Energy > m_MinEnergy)) //If the computers energy level is either not empty and not full the computers recharge chance will increase by a small amount
	{
		RechargeChance = RechargeChance + 5;
	}
	else if (m_Energy == m_MinEnergy) //If the computers energy level is 0 then the recharge chance will be increased by a modest amount
	{
		RechargeChance = RechargeChance + 10;
	}
	//Once %'s are chosen the chosen action is randomly decided ------------------------------------------------------------------------------------------------------
	TotalChance = AttackChance + SpecialChance + RechargeChance + DodgeChance + HealChance;
	RolledNumber = (1 + (rand() % TotalChance));

	if ((RolledNumber > 0) && (RolledNumber < AttackChance)) //chancenumber is between 0 and attackchance
	{
		//Attack
		m_Action = Attack;
		return m_Action;
	}

	else if ((RolledNumber >= (AttackChance + 1)) && (RolledNumber < (AttackChance + SpecialChance))) //chancenumber is between attackchance and specialchance
	{
		//Special Attack
		m_Action = Special;
		return m_Action;
	}

	else if (RolledNumber >= (AttackChance + SpecialChance + 1) && (RolledNumber < (AttackChance + SpecialChance + RechargeChance))) //chancenumber is between specialchance and rechargechance
	{
		//ReCharge
		m_Action = Recharge;
		return m_Action;
	}

	else if (RolledNumber >= (AttackChance + SpecialChance + RechargeChance + 1) && (RolledNumber < (AttackChance + SpecialChance + RechargeChance + DodgeChance))) //chancenumber is between rechargechance and dodgechance
	{
		//Dodge
		m_Action = Dodge;
		return m_Action;
	}

	else if (RolledNumber >= (AttackChance + SpecialChance + RechargeChance + DodgeChance + 1) && (RolledNumber < TotalChance)) //chancenumber is between dodgechance and total chance
	{
		//Heal
		m_Action = Heal;
		return m_Action;
	}
}

void Enemy::EndOfRound()
{
	m_HealedThisTurn = false;
	m_Action = 0;

	m_Energy = m_Energy + (m_RechargeAmount * m_RechargeTimes);
	if (m_Energy > m_MaxEnergy)
	{
		m_Energy = m_MaxEnergy;
	}
	RolledNumber = 0;
	m_RechargeTimes = 1;
	std::cout << m_Name << "has finished their turn. They are gaining end of round energy!" << std::endl;

	int AttackChance = 22;
	int SpecialChance = 22;
	int RechargeChance = 12;
	int DodgeChance = 22;
	int HealChance = 22;
	int TotalChance = 0;
}


