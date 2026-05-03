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


};
