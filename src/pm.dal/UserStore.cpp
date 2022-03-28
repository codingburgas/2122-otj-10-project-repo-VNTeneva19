#include "pch.h"
#include "UserStore.h"
#include <vector>
#include "../pm.types/User.h"

static std::vector<pm::types::User> users;

void pm::dal::UserStore::create(pm::types::User user)
{
	// If the user exists (check email) - throw exception (find_if)
	// Generate new id
	users.push_back(user);
}

std::vector<pm::types::User> pm::dal::UserStore::getAll()
{
	return std::vector<pm::types::User>();
}

void pm::dal::UserStore::remove(size_t id)
{
}

void pm::dal::UserStore::update(pm::types::User user)
{
	// find the user by id
	// If it does not exist - throw exception
}

pm::types::User pm::dal::UserStore::getById(size_t id)
{
	return pm::types::User();
}

pm::types::User pm::dal::UserStore::getByEmail(std::string email)
{
	return pm::types::User();
}
