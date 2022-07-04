#include "UserStore.h"
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"
#include "pch.h"

std::string account;

size_t generateNewId()
{
	size_t maxId = 0;
	pmtypes::User user;

	for (int i = 0; i < maxId; i++)
	{
		if (user.id > maxId)
		{
			maxId = user.id;
		}
	}

	return maxId + 1;
}

void pmdal::UserStore::registerNewUserInTxt(pmtypes::User& user)
{
	std::ofstream myFile;

	// Creates a file for the new user
	myFile.open("users.txt");
	
	account = user.firstName;
	account += "|";
	account = user.lastName;
	account += "|";
	account = user.email;
	account += "|";
	account = user.age;
	account += "|";
	account = user.password;
	account += "|";
	account = user.createdOn;

	// Adds the user's information into the file
	myFile << account << std::endl;

	// Closes the file
	myFile.close();
}