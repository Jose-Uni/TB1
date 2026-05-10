#pragma once
#include "Contactlist.h"
#include "OpportunityList.h"
#include "UserList.h"
#include <fstream>

class FileManager
{
private:
	Contactlist<string>* listaContactos;
	OpportunityList<string>* listaOportunidades;
	UserList* listaUsuarios;


public:
	FileManager(Contactlist<string>* c, OpportunityList<string>* o, UserList* u): listaContactos(c),
	listaOportunidades(o),listaUsuarios(u){
	
		LoadContacts();
		LoadOpportunities();
		LoadUsers();
	};
	~FileManager() {
		SaveContacts();
		SaveOpportunities();
		SaveUsers();
	};

	void SaveContacts() {

	}

	void LoadContacts() {

	}

	void SaveOpportunities() {

	}

	void LoadOpportunities() {

	}

	void SaveUsers() {

	}

	void LoadUsers() {

	}




};
