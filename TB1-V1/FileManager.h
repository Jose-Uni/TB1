#pragma once
#include "Contactlist.h"
#include "OpportunityList.h"
#include "UserList.h"
#include "Dataset.h"
#include <fstream>


class FileManager
{
private:
	Contactlist<string>* listaContactos;
	OpportunityList<string>* listaOportunidades;
	UserList* listaUsuarios;

	const int CANT = 20;
public:
	FileManager() {};
	~FileManager() {
		SaveContacts();
		SaveOpportunities();
		SaveUsers();
	};

	void setContactos(Contactlist<string>* c) { listaContactos = c; }
	void setOportunidades(OpportunityList<string>* o) { listaOportunidades = o; }
	void setUsuarios(UserList* u) { listaUsuarios = u; }

	bool ArchivoVacio(string archivo) {
		ifstream Archivo(archivo);
		if (!Archivo.is_open()) return true;
		if (Archivo.peek() == EOF) return true;
	
		else return false;
	}

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
		if (ArchivoVacio("contactos.txt")) {
			for (int i = 0; i < CANT; i++) {
				GenerarContacto();
			}
			return;
		}

		ifstream file("contactos.txt");
		if (!file.is_open()) return;

		string linea;
		while (std::getline(file, linea)) {
			if (linea == "---") continue;    

			Contact<string> c;
			c.setId(linea);                 

			std::getline(file, linea);
			c.setNombre(linea);

			std::getline(file, linea);
			c.setApellido(linea);

			std::getline(file, linea);
			c.setEmail(linea);

			std::getline(file, linea);
			c.setTelefono(stoi(linea));      

			std::getline(file, linea);
			c.setEmpresa(linea);

			std::getline(file, linea);
			c.setCargo(linea);

			std::getline(file, linea);
			c.setTipo(static_cast<Tag>(stoi(linea)));   

			std::getline(file, linea);

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
		if (ArchivoVacio("oportunidades.txt")) {
			for (int i = 0; i < CANT; i++) {
				GenerarOportunidad();
			}
			return;
		}

		ifstream file("oportunidades.txt");
		if (!file.is_open()) return;

		string linea;
		while (std::getline(file, linea)) {
			if (linea == "---") continue;

			Opportunity<string> o;
			o.setId(linea);

			std::getline(file, linea);
			o.setTitulo(linea);

			std::getline(file, linea);
			o.setValor(static_cast<float>(stoi(linea)));

			std::getline(file, linea);
			o.setAvance(static_cast<Etapa>(stoi(linea)));

			std::getline(file, linea);
			o.setFechaI(linea);

			std::getline(file, linea);
			o.setFechaC(linea);

			std::getline(file, linea);
			o.setVendedor(linea);

			std::getline(file, linea);
			o.setContacto(linea);

			std::getline(file, linea);

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
		while (std::getline(file, linea)) {
			if (linea == "---") continue;
			User u;

			u.setUser(linea);

			std::getline(file, linea);
			u.setPass(linea);

			std::getline(file, linea);
			u.setId(linea);

			std::getline(file, linea);

			listaUsuarios->pushback(u);
		}

		file.close();
	}

	std::string ToLower(std::string s) {
		for (char& c : s) c = tolower(c);
		return s;
	}

	void GenerarContacto() {
		std::string nombre = nombres[rand() % CANT];
		std::string apellido = apellidos[rand() % CANT];
		std::string empresa = empresas[rand() % CANT];
		std::string cargo = cargos[rand() % CANT];
		std::string email = ToLower(nombre) + "." + ToLower(apellido) + "@mail.com";
		int telefono = 900000000 + (rand() % 99999999);
		Tag tag = static_cast<Tag>(rand() % 7);

		Contact<string> c(nombre, apellido, email, telefono, empresa, cargo, tag);
		listaContactos->pushback(c);
	}

	void GenerarOportunidad() {
		if (listaContactos->vacio()) return;   

		string titulo = titulos[rand() % 10];
		float valor = static_cast<float>(500 + rand() % 49500);
		Etapa avance = static_cast<Etapa>(rand() % 4);
		string vendedor = vendedores[rand() % 5];

		int diaI = 1 + rand() % 28, mesI = 1 + rand() % 12;
		int diaF = 1 + rand() % 28, mesF = 1 + rand() % 12;
		string fechaI = std::to_string(diaI) + "/" + std::to_string(mesI) + "/26";
		string fechaF = std::to_string(diaF) + "/" + std::to_string(mesF) + "/26";

		int indiceContacto = rand() % listaContactos->length();
		Contact<string>* contacto = listaContactos->GetContactoPorIndice(indiceContacto); 
		if (contacto == nullptr) return;
		string idContacto = contacto->getId();

		Opportunity<string> o(titulo, valor, avance, fechaI, fechaF, vendedor, idContacto);
		listaOportunidades->pushback(o);
	}



	




};
