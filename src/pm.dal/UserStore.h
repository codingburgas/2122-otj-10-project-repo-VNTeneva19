#pragma once
#include "pch.h"
#include "../pm.types/User.h"


namespace pmdal
{
	struct UserStore
	{
		void registerNewUserInTxt(pmtypes::User& user);
		void displayAllUsers();
	};

}
