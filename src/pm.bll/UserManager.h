#pragma once
#include "../pm.dal/UserStore.h"
#include "UserManager.cpp"
#include "pch.h"


namespace pmbll
{
	class UserManager
	{
	public:
		void registerNewUser();
		void setUsername(std::string username);
		void setPassword(std::string password);
	private:
		std::string username;
		std::string password;
	};

}






