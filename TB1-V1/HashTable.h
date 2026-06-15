#pragma once
#include "header.h"

template<typename K, typename V>
class HashTable
{
private:
	struct Node
	{
		K key;
		V value;
		Node* next;
		Node(K k, V v) : key(k), value(v), next(nullptr) {};

	};

	struct Table 
	{
		Node* head;
		int len = 0;
		Table() : head(nullptr) {};

		void pushback(K k, V v) {
			Node* aux = head;

			while (aux->next!=nullptr) {
				if (aux->key == k) {
					aux->value = v;
					return;
				}
				aux = aux->next;
			}
			Node* neo = new Node(k, v);
			neo->next = head;
			head = neo;

			len++;
		}

		void clear() {
			while (head) {
				Node* aux = head;
				head = head->next;
				delete aux;
			}
		}

		V search(K k) {
			Node* aux = head;
			while (aux->next != nullptr) {
				if (aux->key == k) return aux->value;
			}

			return -1;
		}

		void eliminate(K k) {
			if (len == 0) return;
			Node* aux = head;

			if (head->key == k) {
				head=head->next;
				delete aux;
				return;
			}

			while (aux->next != nullptr) {
				if (aux->next->key == k) {
					Node* auxaux = aux->next;
					aux->next = auxaux->next;
					delete auxaux;
					return;
				}
				aux = aux->next;
			}
			
		}

	};
	static const int gruposHash = 10;
	Table* table[gruposHash];

	

public:
	HashTable() {
		for (int i = 0; i < gruposHash; i++) {
			table[i] = nullptr;
		}
	};
	~HashTable() {
		for (int i = 0; i < gruposHash; i++) {
			table[i].clear();
		}
		delete[] table;
	};

	bool vacio() {
		int sum;
		for (int i = 0; i < gruposHash; i++) {
			sum += table[i].len;
		}

		if (!sum) {
			return true;
		}
		return false;
	};

	int Hash(K key) {
		int h = 0;
		for (char c : key) {
			h += c;
		}
		return h % gruposHash;
	}

	void insert(K k, V v) {
		int valorHash = Hash(k);
		Node* aux = head;

		while (aux->next != nullptr) {
			if (aux->key == k) {
				aux->value = v;
				return;
			}
			aux = aux->next;
		}
		table[valorHash].pushback(k, v);


	}

	void remove(K key) {
		int id = Hash(key);

		table[id].eliminate(key);

	}

	V get(K key) {
		int ind = Hash(key);

		Node* aux = table[ind];

		while (aux != nullptr) {
			if (aux->key == key) return aux->value;
			aux = aux->next;
		}
		return nullptr;
	}



};
