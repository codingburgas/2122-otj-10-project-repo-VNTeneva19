#pragma once
#include "../pm.dal/UserStore.h"
#include "UserManager.cpp"
#include "pch.h"


namespace pmbll
{
	class UserManager
	{
	public:
		void registerNewUser(std::string firstName, std::string lastName, std::string email, unsigned short age, std::string password,
			std::time_t createdOn);
	private:
		std::string username;
		std::string password;
	};

}






