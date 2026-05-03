#pragma once
#include "Opportunities.h"

template<typename T>
class OpportunityList
{
private:
    struct Nodo
    {
        Opportunity<T>* oportunidad;
        Nodo* prev;
        Nodo* next;
        Nodo(Opportunity<T>& data, Nodo* des = nullptr, Nodo* ant = nullptr) : Opportunity<T>(&data), next(des), prev(ant) {};
    };
    Nodo* head;
    int len;

public:
    OpportunityList() : head(nullptr), len(0) {};
    ~OpportunityList() {
        while (head != nullptr) {
            Nodo* aux = head;
            head = head->next;
            delete aux;
        }
    };

    bool Vacio() {
        return len == 0;
    }

    Nodo* Indice(int pos) {
        if (pos >= len) {
            return nullptr;
        }
        int index = 0;
        Nodo* aux = head;
        while (index < pos) {
            aux = aux->next;
            index++;
        }
        return aux;
    }

    void pushback(Opportunity<T> dat) {
        Nodo* nuevo = new Nodo(dat);
        if (head == nullptr) head = nuevo;
        else {
            Nodo* aux = Indice(len - 1);
            aux->next = nuevo;
            nuevo->prev = aux;

        }
        len++;  
    }

    void pushfront(Opportunity<T> data) {
        Nodo* node = new Nodo(data);
        if (Vacio()) {
            node->prev = nullptr;
            node->next = nullptr;
        }
        else {
            Nodo* aux = head;
            node->prev = nullptr;
            node->next = head;
            aux->prev = node;


        }
        head = node;
        len++;
    }

    Nodo* FindID(T id) {
        if (this->Vacio()) {
            std::cout << "La lista esta vacia!\n";
            return nullptr;
        }

        Nodo* aux = head;
        while (aux != nullptr) {

            if (aux->oportunidad->getId() == id) {
                return aux;
            }
            aux = aux->next;
        }
        std::cout << "No se encontro el contacto!\n";
        return nullptr;
    }

    void DeleteID(T i) {
        Nodo* aux = FindID(i);

        if (aux == nullptr) return;

        if (aux == head) head = aux->next;
        else {
            Nodo* auxaux = aux->prev;
            auxaux->next = aux->next;
            if (aux->next) aux->next->prev = auxaux;
        }

        delete aux->oportunidad;
        delete aux;
        len--;

    }

    Opportunity<T>* GetOportunidad(T id) {
        Nodo* aux = FindID(id);
        if (aux == nullptr) return nullptr;
        return aux->oportunidad;
    }

    OpportunityList FiltrarEtapa(Etapa e) {
        OpportunityList aaa;
        if (Vacio()) {
            std::cout << "La lista esta vacia!\n";
            return aaa;
        }
        Nodo* aux = head;
        while (aux != nullptr) {
            if (aux->oportunidad->getAvance() == e) {
                aaa.pushback(*aux->oportunidad);
            }
            aux = aux->next;
        }
        return aaa;
    }

    OpportunityList FiltrarContacto(T i) {
        OpportunityList aaa;
        if (Vacio()) {
            std::cout << "La lista esta vacia!\n";
            return aaa;
        }
        Nodo* aux = head;
        while (aux != nullptr) {
            if (aux->oportunidad->getContacto() == i) {
                aaa.pushback(*aux->oportunidad);
            }
            aux = aux->next;
        }
        return aaa;
    }

    OpportunityList FiltrarVendedor(T i) {
        OpportunityList aaa;
        if (Vacio()) {
            std::cout << "La lista esta vacia!\n";
            return aaa;
        }
        Nodo* aux = head;
        while (aux != nullptr) {
            if (aux->oportunidad->getVendedor() == i) {
                aaa.pushback(*aux->oportunidad);
            }
            aux = aux->next;
        }
        return aaa;
    }

    float ValorTotal() {
        float valor = 0;
        if (Vacio()) {
            std::cout << "La lista esta vacia!\n";
            return valor;
        }
        Nodo* aux = head;
        while (aux != nullptr) {
            valor += aux->oportunidad->getValor();
            aux = aux->next;
        }

        return valor;
    }




};
