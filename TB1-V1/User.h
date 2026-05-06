#pragma once
#include "header.h"


struct User {
	string usuario;
	string password;
	User() : usuario(""), password("") {}
	User(string usuario, string password) : usuario(usuario), password(password) {}
};