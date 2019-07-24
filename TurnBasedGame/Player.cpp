#include "Player.h"

Player::Player(std::string name)
{
	m_Name = name;
}

int Player::Choice()
{
	std::cout << "Select an action to use" << std::endl;
	std::cout << "Attack(1), Special Attack(2), Recharge(3), Dodge(4), Heal(5) (Use these numbers ONLY or else risk breaking the game)" << std::endl;
	std::cin >> m_Action;
	if (m_Action < 1 || m_Action > 5)
	{
		std::cout << "Invalid Number entered, try again!" << std::endl;
		//std::cin.clear();
		//std::cin.ignore();
		Choice();
	}

	if ((m_Energy != m_MaxEnergy) && m_Action == Special) //Not enough energy to perform special attack
	{
		std::cout << "Not enough energy to perform special attack, repick an action." << std::endl;
		Choice();
	}

	if ((m_Energy == m_MaxEnergy) && m_Action == Recharge)//Full energy so can't recharge
	{
		std::cout << "Full energy so can't recharge, repick an action." << std::endl;
		Choice();
	}

	if ((m_HealedThisTurn == true && m_Action == Heal)) //Already healed this turn so can't heal
	{
		std::cout << "Already healed this turn, repick an action." << std::endl;
		Choice();
	}

	if ((m_Health == m_MaxHealth && m_Action == Heal)) //health is max 
	{
		std::cout << "Health is at max, repick an action." << std::endl;
		Choice();
	}

	if ((m_Energy < 20 && m_Action == Heal)) //not enough energy
	{
		std::cout << "Not enough energy to heal, repick an action." << std::endl;
		Choice();
	}
	return m_Action;
}

void Player::EndOfRound()
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
}

int Player::GetHealth()
{
	return m_Health;
}




