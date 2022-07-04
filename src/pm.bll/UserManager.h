#pragma once
#include "../pm.dal/UserStore.h"
#include "UserManager.cpp"
#include "pch.h"


namespace pmbll
{
	class UserManager
	{
	public:
		std::string hashString(std::string str);
		std::string createdOn();
		void registerNewUser(std::string firstName, std::string lastName, std::string email, unsigned short age, std::string password);
	private:
		std::string username;
		std::string password;
	};

}






