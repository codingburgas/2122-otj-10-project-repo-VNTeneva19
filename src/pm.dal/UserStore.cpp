#include "UserStore.h"
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"

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