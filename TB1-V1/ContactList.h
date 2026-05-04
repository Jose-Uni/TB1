#pragma once
#include "Contact.h"
#include <functional>

template <typename T>
class Contactlist
{
private:
	struct Nodo
	{
		Contact<T>* contacto;
		Nodo* next;
		Nodo(Contact<T>& cont, Nodo* nex = nullptr) : contacto(&cont), next(nex) {};
	};

	Nodo* head;
	int len;

public:
	Contactlist() : head(nullptr), len(0) {};
	~Contactlist() {
		Nodo* aux = head;
		Nodo* aux2;

		while (aux != nullptr) {
			aux2 = aux->next;
			delete aux;
			aux = aux2;
		}
	};

	class Iterador
	{
	private:
		Nodo* current;
	public:
		Iterador(Nodo* n) : current(n) {};
		~Iterador() {};

		Contact<T>& operator*() {
			return *(current->contacto);
		}

		Iterador& operator++() {
			current = current->next;
			return *this;
		}

		bool operator!=(const Iterador& otro)const {
			return current != otro.current;
		}

	};

	Iterador begin() { return Iterador(head); }
	Iterador end() { return Iterador(nullptr); }

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

	Nodo* FindPrev(Nodo* a) {
		Nodo* prev = head;

		while (prev->next != a) {
			prev = prev->next;
		}
		return prev;

	}

	void pushback(Contact<T> c) {
		Contact<T>* nuevo = new Contact<T>(c);
		Nodo* neo = new Nodo(*nuevo);
		if (vacio()) head = neo;
		else {
			Nodo* aux = Indice(len - 1);
			aux->next = neo;
		}
		len++;
	}

	void DeleteID(T i) {

		Nodo* aux = FindID(i);

		if (aux == nullptr) return;

		if (aux == head) head = aux->next;
		else {
			Nodo* prev = FindPrev(aux);
			prev->next = aux->next;
		}

		delete aux->contacto;
		delete aux;

	}

	Nodo* FindID(T id) {
		if (vacio()) {
			std::cout << "La lista esta vacia!\n";
			return nullptr;
		}

		Nodo* aux = head;
		while (aux != nullptr) {

			if (aux->contacto->getId() == id) {
				return aux;
			}
			aux = aux->next;
		}
		std::cout << "No se encontro el contacto!\n";
		return nullptr;
	}

	Nodo* FindNombre(T n) {
		if (vacio()) {
			std::cout << "La lista esta vacia!\n";
			return nullptr;
		}

		Nodo* aux = head;
		while (aux != nullptr) {

			if (aux->contacto->getNombre() == n) {
				return aux;
			}
			aux = aux->next;
		}
		std::cout << "No se encontro el contacto!\n";
		return nullptr;
	}

	Nodo* FindEmail(T e) {
		if (vacio()) {
			std::cout << "La lista esta vacia!\n";
			return nullptr;
		}

		Nodo* aux = head;
		while (aux != nullptr) {

			if (aux->contacto->getEmail() == e) {
				return aux;
			}
			aux = aux->next;
		}
		std::cout << "No se encontro el contacto!\n";
		return nullptr;
	}

	Contact<T>* GetContacto(T id) {
		Nodo* aux = FindID(id);

		if (aux == nullptr) return nullptr;

		return aux->contacto;
	}

	Contactlist FiltrarEmpresa(T e) {
		Contactlist aaa;

		if (vacio()) {
			std::cout << "La lista esta vacia!\n";
			return aaa;
		}
		Nodo* aux = head;
		while (aux != nullptr) {

			if (aux->contacto->getEmpresa() == e) {
				aaa.pushback(*aux->contacto);
			}
			aux = aux->next;
		}

		return aaa;

	}

	Contactlist FiltarEstado(bool e) {
		Contactlist aaa;

		if (vacio()) {
			std::cout << "La lista esta vacia!\n";
			return aaa;
		}
		Nodo* aux = head;
		while (aux != nullptr) {

			if (aux->contacto->getEstado() == e) {
				aaa.pushback(*aux->contacto);
			}
			aux = aux->next;
		}

		return aaa;
	}

	Contactlist FiltrarTipo(Tag t) {
		Contactlist aaa;
		if (vacio()) {
			std::cout << "La lista esta vacia!\n";
			return aaa;
		}
		Nodo* aux = head;
		while (aux != nullptr) {
			if (aux->contacto->getTipo() == t) {
				aaa.pushback(*aux->contacto);
			}
			aux = aux->next;
		}
		return aaa;
	}

	void buscarVipActivo(function<void(Contact<T>&)>action) {
		Nodo* aux = head;
		while (aux != nullptr) {
			accion(*aux->contacto);
			aux = aux->next;
		}

	}


};

