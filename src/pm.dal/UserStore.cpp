#include "UserStore.h"
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"

std::vector<pmtypes::User> users;

size_t generateNewId()
{
	size_t maxId = 0;

	for (auto user : users)
	{
		if (user.id > maxId)
		{
			maxId = user.id;
		}
	}

	return maxId + 1;
}

void pmdal::UserStore::registerNewUserInTxt(std::string user)
{
	std::ofstream myFile;

	// Creates a file for the new user
	myFile.open("../pm.dal/users.txt", std::ios::out | std::ios::app);

	// Adds the user's information into the file
	//myFile << user.id << "|";
	//myFile << user.firstName << "|";
	//myFile << user.lastName << "|";
	//myFile << user.email << "|";
	//myFile << user.age << "|";
	//myFile << user.password << "|";
	//myFile << user.createdOn;

	myFile << user;



	// Closes the file
	myFile.close();
}