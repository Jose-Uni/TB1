#pragma once
#include "Opportunities.h"
#include <functional>
#include <vector>
#include <fstream>

template<typename T>
class OpportunityList
{
private:
    struct Nodo
    {
        Opportunity<T>* oportunidad;
        Nodo* prev;
        Nodo* next;
        Nodo(Opportunity<T>& data, Nodo* des = nullptr, Nodo* ant = nullptr) : oportunidad(&data), next(des), prev(ant) {};
    };
    Nodo* head;
    int len;

    void Orden(vector<Opportunity<T>>& vec, function<bool(Opportunity<T>&, Opportunity<T>&)> comparar) {

        bool ordenado;

        for (int i = 0; i < vec.size()-1; i++) {
            ordenado = true;
            for (int j = 0; j < vec.size() - i - 1; j++) {
                if (comparar(vec[j], vec[j+1])) {
                    swap(vec[j], vec[j+1]);
                    ordenado = false;
                }
            }
            if (ordenado) break;
        }
    }

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
    
    void sumEtapa(function<void(Opportunity<T>&)> accion) {
        Nodo* aux = head;
        while (aux != nullptr) {
            accion(*aux->oportunidad);
            aux = aux->next;
        }
    }

    void recorrer(ofstream& file) {
        Nodo* aux = head;
        while (aux != nullptr) {
            file << aux->oportunidad->getId() << "\n";
            file << aux->oportunidad->getTitulo() << "\n";
            file << static_cast<float>(aux->oportunidad->getValor()) << "\n";
            file << static_cast<int>(aux->oportunidad->getAvance()) << "\n";
            file << aux->oportunidad->getFechaI() << "\n";
            file << aux->oportunidad->getFechaC() << "\n";
            file << aux->oportunidad->getVendedor() << "\n";
            file << aux->oportunidad->getContacto() << "\n";
            file << "---\n";
            aux = aux->next;
        }
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
        Opportunity<T>* nuevo = new Opportunity<T>(dat);   
        Nodo* neo = new Nodo(*nuevo);
        if (head == nullptr) head = neo;//#Cambie el nuevo por el neo
        else {
            Nodo* aux = Indice(len - 1);
            aux->next = neo;
            neo->prev = aux;

        }
        len++;  
    }

    void pushfront(Opportunity<T> data) {
        Opportunity<T>* nuevo = new Opportunity<T>(data);  
        Nodo* node = new Nodo(*nuevo);
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

    void Orden(function<bool(Opportunity<T>&, Opportunity<T>&)> comparar) {
        if (len <= 1) return;

        vector<Opportunity<T>> vec;
        Nodo* aux = head;
        while (aux != nullptr) {
            vec.push_back(*aux->oportunidad);
            aux = aux->next;
        }

        Orden(vec, comparar);

        aux = head;
        for (int i = 0; i < vec.size(); i++) {
            *aux->oportunidad = vec[i];
            aux = aux->next;
        }
    }


};
