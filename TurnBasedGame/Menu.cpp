#include "Menu.h"

void Menu::MainAsk()
{
	system("CLS");
	std::string MenuChoice = "";
	std::cout << "Would you like to (P)lay the game, view (I)nstructions or (E)xit the game?" << std::endl;
	std::cin >> MenuChoice;
	MainChoice(MenuChoice);
}

void Menu::MainChoice(std::string MenuChoice)
{
	if (MenuChoice == "P" || MenuChoice == "p") //Starts the while loop in main essentially starting the game
	{
		
		system("CLS");
		ChooseName();

	}
	else if (MenuChoice == "I" || MenuChoice == "i") //Prints the game instructions and waits for the user to press a key before returning to main menu
	{
		system("CLS");
		std::cout << "This is a single player version of Pong. You can control your paddles by using the up and down arrow keys." << std::endl << std::endl;
		std::cout << "You can increase your score by hitting the ball with your paddles." << std::endl << std::endl;
		std::cout << "If the ball hits the different coloured wall behind your paddle, the game will end." << std::endl << std::endl;
		std::cout << "Press a key to return to the menu." << std::endl;
		_getch();
		MainAsk();
	}
	else if (MenuChoice == "E" || MenuChoice == "e") //Exits the console
	{
		exit(0);
	}
	else //If user doesnt input a valid key then the program reasks what they want to do
	{
		MainAsk();
	}
}

void Menu::ChooseName()
{
	std::cout << "Choose a name:";
	std::cin >> name;
}

std::string Menu::GetChosenName()
{
	return name;
}
