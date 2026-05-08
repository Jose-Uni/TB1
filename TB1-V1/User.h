#pragma once
#include "header.h"

class User
{
private:
	string username;
	string password;
	string id;
	static int cant;

public:
	User(string user, string pass): username(user), password(pass) {
		cant++;
		string idNew = "V"+username.substr(0, 4) + to_string(cant);
		setId(idNew);
	};
	~User() {};

	void setUser(string a) { username = a; }
	void setPass(string a) { password = a; }
	void setId(string a) { id = a; }

	string getUser() { return username; }
	string getPass() { return password; }
	string getId() { return id; }



};

int User::cant = 0;
