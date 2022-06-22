#include "UserManager.h"
#include "pch.h"

void pmbll::UserManager::registerNewUser()
{
	std::string username;
	std::string password;

	std::cin >> username;
	std::cin >> password;

	this->username = username;
	this->password = password;
}

void pmbll::UserManager::setUsername(std::string username)
{
	username = this->username;
}

void pmbll::UserManager::setPassword(std::string password)
{
	password = this->password;
}


