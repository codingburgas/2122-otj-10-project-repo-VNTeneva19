#include "userLogin.h"
#include "../pm.bll/UserManager.h"
#include <iostream>
#include<conio.h>
#include<windows.h>

void UserLogin::gotoXY(int x, int y)
{
	COORD coords;

	coords.X = x;
	coords.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
}

void UserLogin::displayMainMenu()
{
	gotoXY(15, 0);  std::cout << " _____   _____   _____     ___   _____   _____   _____     __  __    ___    _   _    ___    _____   _____   __  __   _____   _   _   _____  " << std::endl;
	gotoXY(15, 1); std::cout << "| ___ "<< R"(\)" <<" | ___ " << R"(\)" <<" |  _  |   |_  | |  ___| /  __ " << R"(\)" << " |_   _|   |  " << R"(\)" <<"/  |  / _ " << R"(\)" << "  | " << R"(\)" << " | |  / _ " << R"(\)" <<"  |  __ " << R"(\)" <<" |  ___| |  " << R"(\)" <<"/  | |  ___| | " << R"(\)" << " | | |_   _|" << std::endl;
	gotoXY(15, 2); std::cout << "| |_/ / | |_/ / | | | |     | | | |__   | /  " << R"(\)" << "/   | |     | .  . | / /_" << R"(\)" << " " << R"(\)" << " |  " << R"(\)" << "| | / /_" << R"(\)" << " " << R"(\)" << " | |  " << R"(\)" << "/ | |__   | .  . | | |__   |  " << R"(\)" << "| |   | |   " << std::endl;
	gotoXY(15, 3); std::cout << "|  __/  |    /  | | | |     | | |  __|  | |       | |     | |" << R"(\)" << "/| | |  _  | | . ` | |  _  | | | __  |  __|  | |" << R"(\)" << "/| | |  __|  | . ` |   | |   " << std::endl;
	gotoXY(15, 4); std::cout << "| |     | |" << R"(\)" << " "<< R"(\)" <<"  "<< R"(\)" <<" "<< R"(\)" <<"_/ / /"<< R"(\)" <<"__/ / | |___  | "<< R"(\)" <<"__/"<< R"(\)" <<"   | |     | |  | | | | | | | |"<< R"(\)" <<"  | | | | | | |_"<< R"(\)" <<" "<< R"(\)" <<" | |___  | |  | | | |___  | |"<< R"(\)" <<"  |   | |   " << std::endl;
	gotoXY(15, 5); std::cout << R"(\)" << "_|     "<< R"(\)" <<"_| "<< R"(\)" <<"_|  "<< R"(\)" <<"___/  "<< R"(\)" <<"____/  "<< R"(\)" <<"____/   "<< R"(\)" <<"____/   "<< R"(\)" <<"_/     "<< R"(\)" <<"_|  |_/ "<< R"(\)" <<"_| |_/ "<< R"(\)" <<"_| "<< R"(\)" <<"_/ "<< R"(\)" <<"_| |_/  "<< R"(\)" <<"____/ "<< R"(\)" <<"____/  "<< R"(\)" <<"_|  |_/ "<< R"(\)" <<"____/  "<< R"(\)" <<"_| "<< R"(\)" <<"_/   "<< R"(\)" <<"_/  " << std::endl;
  
	std::cout << std::endl;
}

int UserLogin::choiceMenu()
{
	displayMainMenu();

	gotoXY(75, 7); std::cout << "1. Register";
	gotoXY(75, 8); std::cout << "2. Login";
	gotoXY(75, 9); std::cout << "0. Exit" << std::endl;

	int choice;

	gotoXY(75, 10); std::cin >> choice;

	switch (choice)
	{
	case 0:
		system("CLS");
		gotoXY(55, 0); std::cout << "You have successfully exited the application!";
		return 0;
	case 1:
		registerMenu();
		break;
	case 2:
		loginMenu();
		break;
	default:
		std::cout << "Wrong choice! Choose again." << std::endl;
		Sleep(1000);
		system("CLS");
		choiceMenu();
	}
}

void UserLogin::registerMenu()
{
	system("cls");

	displayMainMenu();

	std::string firstName, lastName, email, password;
	unsigned short age;

	UserManager check;

	bool checker = true;

	while(checker)
	{
		gotoXY(55, 7); std::cout << "        -- SIGN IN --         " << std::endl;
		gotoXY(55, 8); std::cout << " ------------------------------ " << std::endl;
		gotoXY(55, 9); std::cout << "|          First Name:         |";
	    gotoXY(55, 10); std::cout << "|         -> "; std::cin >> firstName; std::cout << "\033[F";
		gotoXY(55, 11); std::cout << "|          Last Name:          |" << std::endl;
		gotoXY(55, 12); std::cout << "|         -> "; std::cin >> lastName;  std::cout << "\033[F";
		gotoXY(55, 13); std::cout << "|            Email             |" << std::endl;
		gotoXY(55, 14); std::cout << "|         -> "; std::cin >> email;  std::cout << "\033[F";
		if (!check.checkEmail(email))
		{
			gotoXY(55, 16);
			Sleep(1000);
			system("CLS");
			choiceMenu();
		}
		gotoXY(55, 15); std::cout << "|             Age              |" << std::endl;
		gotoXY(55, 16); std::cout << "|         -> "; std::cin >> age;  std::cout << "\033[F";
		gotoXY(55, 17); std::cout << "|           Password           |" << std::endl;
		gotoXY(55, 18); std::cout << "|         -> "; std::cin >> password;  std::cout << "\033[F";
		gotoXY(55, 19); std::cout << " ------------------------------ " << std::endl;
		
		checker = false;
	}
	
	check.registerNewUser(firstName, lastName, email, age, password);

	system("CLS");
	choiceMenu();
}

void UserLogin::loginMenu()
{
	system("cls");

	displayMainMenu();

	std::string email, password;

	UserManager check;

	bool checker = true;

	while (checker)
	{
		gotoXY(55, 7); std::cout << "          -- LOG IN --          " << std::endl;
		gotoXY(55, 8); std::cout << " ------------------------------ " << std::endl;
		gotoXY(55, 9); std::cout << "|            Email             |" << std::endl;
		gotoXY(55, 10); std::cout << "|         -> "; std::cin >> email;  std::cout << "\033[F";
		if (!check.checkEmail(email))
		{
			gotoXY(55, 11);
			Sleep(1000);
			system("CLS");
			choiceMenu();
		}
		gotoXY(55, 11); std::cout << "|           Password           |" << std::endl;
		gotoXY(55, 12); std::cout << "|         -> "; std::cin >> password;  std::cout << "\033[F";
		gotoXY(55, 13); std::cout << " ------------------------------ " << std::endl;

		if (check.loginUser(email, password) == true)
		{
			gotoXY(55, 14); std::cout << "Wrong email or password";
			Sleep(1000);
			system("CLS");
			choiceMenu();
		}
		else if (check.loginUser(email, password) == false)
		{
			system("CLS");
			userManagementView();
		}
	}

	

}

void UserLogin::userManagementView()
{
	system("cls");

	displayMainMenu();

	pmdal::UserStore user;

	gotoXY(75, 7); std::cout << "1. Display all users";
	gotoXY(75, 8); std::cout << "0. Back" << std::endl;

	int choice;

	gotoXY(75, 10); std::cin >> choice;

	switch (choice)
	{
	case 0:
		system("CLS");
		choiceMenu();
	case 1:
		system("CLS");
		user.displayAllUsers();
		break;
	default:
		std::cout << "Wrong choice! Choose again." << std::endl;
		Sleep(1000);
		system("CLS");
		choiceMenu();
	}
}


