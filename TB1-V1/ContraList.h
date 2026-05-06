#pragma once
#include <iostream>
#include <string>
#include "Enums.h"

template <typename T>
class Nodo {
public:
	T data;
	Nodo<T>* next;

	Nodo(T data) : data(data), next(nullptr) {}
	Nodo(T data, Nodo<T>* next) : data(data), next(next) {}
};

template <typename T>
class ContraList {
private:
	Nodo<T>* head;
	bool pass;
	int length;
public:
	ContraList() : head(nullptr), pass(false), length(0) {}
	~ContraList() {
		Nodo<T>* aux = head;
		Nodo<T>* aux2;
		// Este código hace que el puntero aux, salte de nodo en nodo hasta eliminar el último
		while (aux != nullptr) {
			aux2 = aux->next;
			delete aux;
			aux = aux2;
		}
	}
	void AddFirst(T data) {
		Nodo<T>* node = new Nodo<T>(data, IsEmpty() ? nullptr : head);
		head = node;
		length++;
	}
	void FindAccess(std::string user, std::string contra) {
		Nodo<T>* aux = head;
		int pos = 0;
		while (aux != nullptr) {
			if (aux->data.usuario == user && aux->data.password == contra) {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 52, 20 });
				std::cout << "Acceso concedido.\n";
				Sleep(500);
				pass = true;
				return;
			}else {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 52, 20 });
				std::cout << "Acceso denegado.\n";
				Sleep(500);
				break;
			}
			aux = aux->next;
			pos++;
		}
	}
	bool getPass() {
		return pass;
	}
	int Length() {
		return length;
	}
	bool IsEmpty() {
		return length == 0;
	}
};