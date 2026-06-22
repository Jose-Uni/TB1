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

		void pushfront(K k, V v) {

			if (head == nullptr) {
				head = new Node(k, v);
				return;
			}
			Node* aux = head;

			while (aux!=nullptr) {
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
			while (aux!= nullptr) {
				if (aux->key == k) return aux->value;
				aux = aux->next;
			}

			return to_string(- 1);
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
	static const int gruposHash = 13;
	Table table[gruposHash];

	

public:
	HashTable() {
	};
	~HashTable() {
		for (int i = 0; i < gruposHash; i++) {
			table[i].clear();
		}
	};

	bool vacio() {
		int sum=0;
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
		table[valorHash].pushfront(k, v);


	}

	void remove(K key) {
		int id = Hash(key);

		table[id].eliminate(key);

	}

	V get(K key) {
		
		int ind = Hash(key);

		return table[ind].search(key);
	}



};
