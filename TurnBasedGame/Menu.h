#pragma once
#include <iostream>
#include <string>
#include <conio.h>
class Menu
{
public:
	void MainAsk();
	void MainChoice(std::string MenuChoice);
	void ChooseName();
	std::string GetChosenName();



private:
	std::string name;


};

