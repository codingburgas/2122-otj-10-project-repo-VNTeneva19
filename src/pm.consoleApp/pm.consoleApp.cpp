#include <iostream>
#include "../pm.bll/UserManager.cpp"
#include "../pm.dal/UserStore.h"
#include "../pm.types/User.h"

int main()
{
	std::string firstName, lastName, email, password, createdOn;

	unsigned short age;

	UserManager user;

	pmtypes::User users;

	std::cin >> firstName >> lastName >> email >> age >> password;

	user.registerNewUser(firstName, lastName, email, age, password);

}
