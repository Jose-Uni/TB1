#pragma once
#include "Intro.h"
#include "header.h"
#include "UserList.h"
#include <sstream>

using namespace std;

struct Welcome {
	string mensaje =
		" ____  _                           _     _       _ \n"
		"|  _ \\(_)                         (_)   | |     | |\n"
		"| |_) |_  ___ _ ____   _____ _ __  _  __| | ___ | |\n"
		"|  _ <| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| |/ _` |/ _ \\| |\n"
		"| |_) | |  __/ | | \\ V /  __/ | | | | (_| | (_) |_|\n"
		"|____/|_|\\___|_| |_|\\_/ \\___|_| |_|_|\\__,_|\\___/(_)\n";
	void mostrar(int x, int y, HANDLE hConsol) {
		istringstream iss(mensaje);
		string linea;
		int contL = 0;
		while (getline(iss, linea)) {
			COORD coord;
			coord.X = x;
			coord.Y = y + contL;
			SetConsoleCursorPosition(hConsol, coord);
			cout << linea;
			contL++;
		}
	}
};

class MenuPass {
private:
	int x, y;
	bool pass = false;
	UserList* usuarios;
	Welcome w;
	HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	MenuPass(UserList* lista) {
		this->x = 34;
		this->y = 10;
		usuarios = lista;
	};
	void setXY(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(hConsol, coord);
	}
	int setX(int x) {
		return this->x = x;
	}
	int setY(int y) {
		return this->y = y;
	}
	void mostrarMenu() {
		int z;
		while(!pass) {
			system("cls");
			setXY(x, y);
			w.mostrar(x, y, hConsol);
			string m1 = "1. Entrar     \n";
			string m2 = "2. Registrarse\n";
			int xtemp = (120 - m1.size()) / 2;
			int ytemp = y + 7;
			setXY(xtemp, ytemp);
			cout << m1;
			setXY(xtemp, ytemp + 1);
			cout << m2;
			setXY(xtemp-3, ytemp + 2);
			cout << "> Opcion: [   ]";
			setXY(xtemp +9, ytemp + 2);
			cin >> z;
			system("cls");
			switch (z) {
			case 1: {
				w.mostrar(x, y, hConsol);
				string user, contra;
				string m1 = "1. Usuario:    \n";
				string m2 = "2. Contrasena: \n";
				int x2temp = (120 - m1.size()) / 2;
				int y2temp = y + 7;
				setXY(x2temp, y2temp);
				cout << m1;
				setXY(x2temp, y2temp + 1);
				cout << m2;
				setXY(x2temp + m1.size() - 1, y2temp);
				cin >> user;
				setXY(x2temp + m2.size() - 1, y2temp + 1);
				cin >> contra;
				if (!usuarios->vacio()) {
					pass=usuarios->FindAccess(user,contra);
				}
				else {
					setXY(x2temp + m2.size() - 13, y2temp + 2);
					cout << "Sin usuarios registrados.\n";
				}
				setXY(x2temp + m2.size() - 1, y2temp + 2);
				break;
			}
			case 2: {
				w.mostrar(x, y, hConsol);
				string user, contra;
				string m1 = "1. Usuario:    \n";
				string m2 = "2. Contrasena: \n";
				int x2temp = (120 - m1.size()) / 2;
				int y2temp = y + 7;
				setXY(x2temp, y2temp);
				cout << m1;
				setXY(x2temp, y2temp + 1);
				cout << m2;
				setXY(x2temp + m1.size() - 1, y2temp);
				cin >> user;
				setXY(x2temp + m2.size() - 1, y2temp + 1);
				cin >> contra;
				User newUser(user,contra);
				usuarios->pushback(newUser);
				setXY(x2temp, y2temp + 3);
				cout << "Usuario registrado.\n";
				Sleep(500);
				break;
			}
			};
		}

	}
};
