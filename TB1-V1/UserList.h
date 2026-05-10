#pragma once
#include "User.h"
#include <fstream>

class UserList
{
private:
	struct Nodo
	{
		User* user;
		Nodo* next;
		Nodo(User& u, Nodo* nex = nullptr) : user(&u), next(nex) {};
	};
	Nodo* head;
	int len;

public:
	UserList() : head(nullptr), len(0) {};
	~UserList() {
		Nodo* aux = head;
		Nodo* aux2;

		while (aux != nullptr) {
			aux2 = aux->next;
			delete aux;
			aux = aux2;
		}
	};

	bool vacio() {
		return len == 0;
	}

	Nodo* Indice(int pos) {
		if (pos >= len) {
			std::cout << "Input invalido!\n";
			return nullptr;
		}
		int i = 0;
		Nodo* aux = head;
		while (i < pos) {
			aux = aux->next;
			i++;
		}
		return aux;
	}

	void pushback(User u) {
		User* nuevo = new User(u);
		Nodo* neo = new Nodo(*nuevo);
		if (vacio()) head = neo;
		else {
			Nodo* aux = Indice(len - 1);
			aux->next = neo;
		}
		len++;

	}

	string nombreUsuario() {
		Nodo* aux = head;
		while (aux != nullptr) {
			if (aux->user->getUserPass() != "") {
				return aux->user->getUserPass();
			}
			aux = aux->next;  
		}
		return ""; 
	}

	bool FindAccess(string user, string contra) {
		Nodo* aux = head;

		while (aux != nullptr) {
			if (aux->user->getUser() == user && aux->user->getPass() == contra) {
				aux->user->setUserPass(user);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 52, 20 });
				std::cout << "Acceso concedido.\n";
				Sleep(500);
				return true;
			}
			else {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 52, 20 });
				std::cout << "Acceso denegado.\n";
				Sleep(500);
				return false;

			}
			aux = aux->next;

		}
	}

	Nodo* FindNombre(string n) {
		if (vacio()) {
			std::cout << "La lista esta vacia!\n";
			return nullptr;
		}

		Nodo* aux = head;
		while (aux != nullptr) {

			if (aux->user->getUser() == n) {
				return aux;
			}
			aux = aux->next;
		}
		std::cout << "No se encontro el contacto!\n";
		return nullptr;
	}

	User* ObternerUsuario(string n) {
		Nodo* aux= FindNombre(n);

		if (aux == nullptr) return nullptr;
		return aux->user;
	}

	void recorrer(ofstream& file) {
		Nodo* aux = head;
		while (aux != nullptr) {
			file << aux->user->getUser() << "\n";
			file << aux->user->getUserPass() << "\n";
			file << aux->user->getPass() << "\n";
			file << aux->user->getId() << "\n";
			file << "---\n";
			aux = aux->next;
		}
	}
};

