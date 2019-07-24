#include "Game.h"

void Game::Start()
{
	Menu* menu = new Menu;
	menu->MainAsk();
	FlipGameRunning();
	name = menu->GetChosenName();
}

void Game::Loop()
{
	Player* player = new Player(name);
	Enemy* enemy = new Enemy;
	while (IsGameRunning == true) 
	{
		while (player->IsAlive() == true && enemy->IsAlive() == true) 
		{
			system("CLS");
			int Action = 0;
			int ActionValue = 0;

			//Print status
			player->PrintStatus();
			enemy->PrintStatus();

			//User action 
			Action = player->Choice();

			//Perform user action
			ActionValue = player->Outcome(enemy->GetName());

			//If player healed they can perform another action
			if (player->GetHasHealedThisTurn() == true) 
			{
				std::cout << player->GetName() << " has healed so they can choose a second action." << std::endl;
				player->PrintStatus();
				enemy->PrintStatus();
				Action = player->Choice();
				ActionValue = player->Outcome(enemy->GetName());
			}

			//Action is calculated on opponent. 5 = healing which doesnt affect opponent
			if (Action != 5)
			{
				enemy->Response(Action,ActionValue);
			}

			//End of turn stuff
			player->EndOfRound();
			system("pause");

			//Print status
			player->PrintStatus();
			enemy->PrintStatus();

			//Computer action
			enemy->FindPlayersHealth(player->GetHealth());
			Action = enemy->Choice();

			//Perform computer action
			ActionValue = enemy->Outcome(player->GetName());

			//If computer healed they can perform another action
			if (enemy->GetHasHealedThisTurn() == true)
			{
				std::cout << enemy->GetName() << " has healed so they can choose a second action." << std::endl;
				Action = enemy->Choice();
				ActionValue = enemy->Outcome(enemy->GetName());
			}

			//Action is calculated on opponent. 5 = healing which doesnt affect opponent
			if (Action != 5)
			{
				player->Response(Action, ActionValue);
			}

			//End of turn stuff
			enemy->EndOfRound();
			system("pause");

		}
	}
}

void Game::FlipGameRunning()
{
	IsGameRunning == true ? IsGameRunning = false : IsGameRunning = true;
}
