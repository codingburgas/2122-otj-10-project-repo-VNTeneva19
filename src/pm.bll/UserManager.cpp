#include "UserManager.h"
#include "../pm.dal/UserStore.cpp"
#include "../pm.tools/md5.cpp"
#include "../pm.types/User.h"
#include "pch.h"
#pragma warning(disable : 4996)

//Hashing via md5
std::string UserManager::hashString(std::string str)
{
	return md5(str);

	std::string newStr(str);

	//for (size_t i = 0; i < newStr.size(); i++)
	//{
	//	newStr[i] = newStr[i] ^ 15;
	//}

	//return newStr;
}

std::string UserManager::createdOn()
{

	// Current date and time based on current system
	time_t now = time(0);

	// Convert 'now' to string form
	char* dt = ctime(&now);

	return dt;

}

bool UserManager::checkPassword(std::string password)
{
	// Password requirements

	int flag = 0;

	// Check if first letter is in uppercase
	if (password[0] < 65 || password[0] > 90)
	{
		flag++;
	}

	// Check if password lenghts is more than 8 characters
	if (password.length() <= 8)
	{
		flag++;
	}

	if (flag == 2)
	{
		return false;
	}

	return true;
}


bool UserManager::checkEmail(std::string email)
{
	int flag = 0;
	// Email requirements
	for (size_t i = 0; i < email.size(); i++)
	{
		// Check if email has '@'
		if (email[i] == '@')
		{
			flag++;
			break;
		}
	}
	for (size_t i = 0; i < email.size(); i++)
	{
		// Check if email has a link in it
		if (email[i] == '.')
		{
			flag++;
			break;
		}
	}
	if (flag < 2) {
		std::cout << "Invalid email!";
		return false;
	}

	return true;
}

bool UserManager::checkAge(unsigned short age)
{
	if (!isdigit(age))
	{
		std::cout << "Invalid input!";
		return false;
	}

	return true;
}

std::string UserManager::constructAccount(pmtypes::User user)
{
	std::string account = user.firstName;
	account += "|";
	account += user.lastName;
	account += "|";
	account += user.email;
	account += "|";
	account += std::to_string(user.age);
	account += "|";
	account += hashString(user.password);
	account += "|";
	account += createdOn();

	return account;
}


// Assigns user's information values into pmtypes variables
void UserManager::registerNewUser(std::string firstName, std::string lastName, std::string email, unsigned short age, std::string password)
{
	pmtypes::User user;
	pmdal::UserStore UserStore;

	//bool passChecker = UserManager::checkPassword(password);
	//bool emailChecker = UserManager::checkEmail(email);

	user.firstName = firstName;
	user.lastName = lastName;
	user.email = email;
	user.age = age;
	user.password = hashString(password);
	user.createdOn = createdOn();

	UserStore.registerNewUserInTxt(user);
}

bool UserManager::loginUser(std::string email, std::string password)
{
	std::ifstream myFile;

	std::string fileEmail;
	std::string filePass;
	
	std::string line;

	myFile.open("../pm.dal/users.txt", std::ios::in);


	while (std::getline(myFile, line))
	{
		std::stringstream convertor(line);

		std::string passHash = hashString(password);

		convertor >> fileEmail >> filePass;

		if (fileEmail == email && filePass == passHash)
		{
			return true;
		}

	}
	return false;
}



