#pragma once
#include "Contact.h"

template<typename T>
class LeadQueue
{
private:
    class Nodo {
    public:
        Contact<T>* Lead;
        Nodo* next;
        Nodo(Contact<T>& cont, Nodo* nex = nullptr) : contacto(&cont), next(nex) {};
    };
    Nodo* head;
    Nodo* tail;
    int len;

public:
	LeadQueue():head(nullptr),tail(nullptr),len(0) {};
	~LeadQueue() {};

    bool Vacio() { return len == 0; }

    void enqueue(Contact<T> c) {
        Contact<T>* nuevo = new Contact<T>(c);
        Nodo* neo = new Nodo(nuevo);
        if (tail == nullptr) {
            head = tail = neo;
            return;
        }
        tail->next = neo;
        tail = neo;
        len++;
    }

    void dequeue() {
        if (head == nullptr) return;
        Nodo* aux = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        delete aux;
        len--;
    }


};
