#pragma once
#include "pch.h"
#include <string>
#include <ctime>

namespace pmtypes
{
	struct User
	{
		std::string firstName;
		std::string lastName;
		std::string email;
		unsigned short age;
		std::string password;
		std::string createdOn;
	};
}

