#include "UserStore.h"
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"
#include "../pm.consoleApp/userLogin.h"

std::vector<pmtypes::User> users;

void pmdal::UserStore::registerNewUserInTxt(pmtypes::User& user)
{
	std::ofstream myFile;

	UserManager construct;

	// Creates a file for the new user
	myFile.open("../pm.dal/users.txt", std::ios::out | std::ios::app);

	// Adds the user's information into the file
	
	std::string account = construct.constructAccount(user);
	myFile << account;


	// Closes the file
	myFile.close();
}


void pmdal::UserStore::displayAllUsers()
{
	std::ifstream myFile;

	std::string line;

	int choice;

	myFile.open("../pm.dal/users.txt", std::ios::in);

	if (!myFile.eof())
	{
		while (std::getline(myFile, line))
		{
			std::cout << line << std::endl;
		}
	}

	UserLogin userView;

	std::cout << "Press 0 to go back";
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		userView.userManagementView();
	}
}


