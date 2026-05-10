#pragma once
#include "Contactlist.h"
#include "OpportunityList.h"
#include "UserList.h"
#include <fstream>

class FileManager
{
private:
	Contactlist<string>* listaContactos;
	OpportunityList* listaOportunidades;
	UserList* listaUsuarios;


public:
	FileManager() {};
	~FileManager() {};

	void SaveContacts() {

	}

	void LoadContacts() {

	}




};
