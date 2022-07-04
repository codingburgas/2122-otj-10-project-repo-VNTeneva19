#pragma once
#include "../pm.dal/UserStore.h"
#include "pch.h"


struct UserManager
{
	std::string hashString(std::string str);
	std::string createdOn();
	bool checkPassword(std::string password);
	bool checkEmail(std::string email);
	void registerNewUser(std::string firstName, std::string lastName, std::string email, unsigned short age, std::string password);
};


