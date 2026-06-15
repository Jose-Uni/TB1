#pragma once
#include "Contact.h"

template<typename T>
class LeadQueue
{
private:
    struct Nodo {
    
        Contact<T>* Lead;
        Nodo* next;
        Nodo(Contact<T>& cont, Nodo* nex = nullptr) : Lead(&cont), next(nex) {};
    };
    Nodo* head;
    Nodo* tail;
    int len;

public:
	LeadQueue():head(nullptr),tail(nullptr),len(0) {};
	~LeadQueue() {
        while (head != nullptr) {
            Nodo* aux = head;
            head = head->next;
            delete aux->Lead;   
            delete aux;          
        }
    };

    bool Vacio() { return len == 0; }

    int Size() { return len; }

    void enqueue(Contact<T> c) {
        Contact<T>* nuevo = new Contact<T>(c);
        Nodo* neo = new Nodo(*nuevo);
        if (tail == nullptr) {
            head = tail = neo;
            len++;
            return;
        }
        tail->next = neo;
        tail = neo;
        len++;
    }

    Contact<T>* dequeue() {
        if (head == nullptr) {
            throw std::runtime_error("Cola vacia");
        }

        Contact<T>* resultado = head->Lead;
        Nodo* temp = head;
        head = head->next;

        if (head == nullptr) tail = nullptr;

        delete temp; // Solo el nodo, no el contacto
        len--;

        return resultado;
    }


};
