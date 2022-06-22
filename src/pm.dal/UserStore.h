#pragma once
#include "pch.h"
#include "../pm.types/User.h"


namespace pmdal
{
	struct UserStore
	{
		void registerNewUserInTxt(std::string username, std::string password);
	};

}
