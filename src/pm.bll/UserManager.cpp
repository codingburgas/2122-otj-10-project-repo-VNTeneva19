#include "UserManager.h"
#include "../pm.tools/md5.h"
#include "../pm.types/User.h"
#include "pch.h"

//Hashing via md5
std::string pmbll::UserManager::hashString(std::string str)
{
	return md5(str);

	std::string newStr(str);

	//for (size_t i = 0; i < newStr.size(); i++)
	//{
	//	newStr[i] = newStr[i] ^ 15;
	//}

	//return newStr;
}

std::string pmbll::UserManager::createdOn()
{

	// Current date and time based on current system
	time_t now = time(0);

	// Convert 'now' to string form
	char* dt = ctime(&now);

	return dt;
	
}

bool pmbll::UserManager::checkPassword(std::string password)
{
	// Password requirements

	int flag = 0;

	// Check if first letter is in uppercase
	if (password[0] < 65 || password[0] > 90)
	{
		throw "First letter must be in uppercase!";
		flag++;
	}

	// Check if password lenghts is more than 8 characters
	if (password.length() <= 8)
	{
		throw "Password must be more than 8 characters!";
		flag++;
	}

	if (flag < 2)
	{
		return false;
	}

	return true;
}

void pmbll::UserManager::registerNewUser(std::string firstName, std::string lastName, std::string email, unsigned short age, std::string password)
{
	pmtypes::User user;

	pmbll::UserManager::checkPassword(password);

	user.firstName = firstName;
	user.lastName = lastName;
	user.email = email;
	user.age = age;
	user.password = hashString(password);
	user.createdOn = createdOn();

}



