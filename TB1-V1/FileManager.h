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
	FileManager() {};
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
		ofstream file("contactos.txt");

		if (!file.is_open()) {
			cout << "Error al abrir contactos.txt\n";
			return;
		}
		for (auto i = listaContactos->begin(); i != listaContactos->end(); ++i) {
			file << (*i).getId() << "\n";
			file << (*i).getNombre() << "\n";
			file << (*i).getApellido() << "\n";
			file << (*i).getEmail() << "\n";
			file << (*i).getTelefono() << "\n";
			file << (*i).getEmpresa() << "\n";
			file << (*i).getCargo() << "\n";
			file << static_cast<int>((*i).getTipo()) << "\n";
			file << "---\n";   
		}

		file.close();
	}

	void LoadContacts() {
		ifstream file("contactos.txt");
		if (!file.is_open()) return;    

		string linea;
		while (getline(file, linea)) {
			if (linea == "---") continue;    

			Contact<string> c;
			c.setId(linea);                 

			getline(file, linea);
			c.setNombre(linea);

			getline(file, linea);
			c.setApellido(linea);

			getline(file, linea);
			c.setEmail(linea);

			getline(file, linea);
			c.setTelefono(stoi(linea));      

			getline(file, linea);
			c.setEmpresa(linea);

			getline(file, linea);
			c.setCargo(linea);

			getline(file, linea);
			c.setTipo(static_cast<Tag>(stoi(linea)));   

			getline(file, linea);   

			listaContactos->pushback(c);
		}

		file.close();
	}

	void SaveOpportunities() {
		ofstream file("oportunidades.txt");

		if (!file.is_open()) return;
		listaOportunidades->recorrer(file);
		file.close();

	}

	void LoadOpportunities() {
		ifstream file("oportunidades.txt");
		if (!file.is_open()) return;

		string linea;
		while (getline(file, linea)) {
			if (linea == "---") continue;

			Opportunity<string> o;
			o.setId(linea);

			getline(file, linea);
			o.setTitulo(linea);

			getline(file, linea);
			o.setValor(static_cast<float>(stoi(linea)));

			getline(file, linea);
			o.setAvance(static_cast<Etapa>(stoi(linea)));

			getline(file, linea);
			o.setFechaI(linea);

			getline(file, linea);
			o.setFechaC(linea);

			getline(file, linea);
			o.setVendedor(linea);

			getline(file, linea);
			o.setContacto(linea);

			getline(file, linea);

			listaOportunidades->pushback(o);
		}

		file.close();

	}

	void SaveUsers() {
		ofstream file("usuarios.txt");
		if (!file.is_open()) return;

		listaUsuarios->recorrer(file);
		file.close();


	}

	void LoadUsers() {
		ifstream file("usuarios.txt");
		if (!file.is_open()) return;

		string linea;
		while (getline(file, linea)) {
			if (linea == "---") continue;
			User u;

			u.setUser(linea);

			getline(file, linea);
			u.setUserPass(linea);

			getline(file, linea);
			u.setPass(linea);

			getline(file, linea);
			u.setId(linea);

			getline(file, linea);

			listaUsuarios->pushback(u);
		}

		file.close();
	}




};
