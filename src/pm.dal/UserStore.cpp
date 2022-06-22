#include "UserStore.h"


void pmdal::UserStore::registerNewUserInTxt(std::string username, std::string password)
{
	std::ofstream myFile;
	// Creates a file for the new user
	myFile.open("data\\" + username + ".txt");

	// Adds the user's username and password into the file
	myFile << username << std::endl;
	myFile << password;

	// Closes the file
	myFile.close();
}