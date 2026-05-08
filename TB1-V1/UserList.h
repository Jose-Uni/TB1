#pragma once
#include "User.h"

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
	UserList(): head(nullptr), len(0) {};
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

	void FindAccess(string user, string contra) {
		Nodo* aux = head;
		int pos = 0;
		while (aux != nullptr) {
			if (aux->user->getUser() == user && aux->user->getPass() == contra) {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 52, 20 });
				std::cout << "Acceso concedido.\n";
				Sleep(500);
				pass = true;
				return;
			}
			else {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 52, 20 });
				std::cout << "Acceso denegado.\n";
				Sleep(500);
				break;
			}
			aux = aux->next;
			pos++;
		}
	}


};

