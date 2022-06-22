#include <iostream>
#include "../pm.bll/UserManager.h"

int main()
{
	pmbll::UserManager a;
	a.registerNewUser();

	std::string username;
	std::string password;

	a.setUsername(username);
	a.setPassword(password);

	pmdal::UserStore b;

	b.registerNewUserInTxt(username, password);

}