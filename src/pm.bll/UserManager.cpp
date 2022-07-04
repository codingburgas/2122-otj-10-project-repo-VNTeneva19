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

	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	return dt;
	
}

void pmbll::UserManager::registerNewUser(std::string firstName, std::string lastName, std::string email, unsigned short age, std::string password)
{
	pmtypes::User user;

	user.firstName = firstName;
	user.lastName = lastName;
	user.email = email;
	user.age = age;
	user.password = hashString(password);
	user.createdOn = createdOn();

}



