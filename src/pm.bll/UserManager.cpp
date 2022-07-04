#include "UserManager.h"
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


void pmbll::UserManager::registerNewUser(std::string firstName, std::string lastName, std::string email, unsigned short age, std::string password, 
	std::time_t createdOn)
{
	pmtypes::User user;

	user.firstName = firstName;
	user.lastName = lastName;


}




