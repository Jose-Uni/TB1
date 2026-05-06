#pragma once
#pragma comment(lib, "winmm.lib")
#include "Enums.h"
using namespace std;

class Intro {
private:
	C c;
	H h;
	E e;
	T t;
	N n;
	E2 e2;
	G g;
	Sonidos son;
	int x, y;
	int dx;
	CONSOLE_CURSOR_INFO cursorVisible;
	HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	Intro() {
		this->x = 0;
		this->y = 0;
		this->dx = -1;
		cursorVisible.bVisible = FALSE;
		cursorVisible.dwSize = 1;
		SetConsoleCursorInfo(hConsol, &cursorVisible);
	};
	~Intro() {};
	void setXY(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(hConsol, coord);
	}
	void colorBF(int b, int f) {
		SetConsoleTextAttribute(hConsol, b | f);
	}
	int setX(int x) {
		return this->x = x;
	}
	int setY(int y) {
		return this->y = y;
	}
	void Animación() {
		setX(106);
		c.animar(this->x,this->y,this->dx, this->hConsol);
		if (c.getLlego()){
			h.animar(this->x,this->y,this->dx, this->hConsol);		
		}
		if (h.getLlego()){
			e.animar(this->x,this->y,this->dx, this->hConsol);		
		}
		if (e.getLlego()){
			t.animar(this->x,this->y,this->dx, this->hConsol);		
		}
		setY(11);
		if (t.getLlego()) {
			n.animar(this->x,this->y,this->dx, this->hConsol);
		}
		if (n.getLlego()) {
			e2.animar(this->x,this->y,this->dx, this->hConsol);
		}
		if (e2.getLlego()) {
			g.animar(this->x,this->y,this->dx, this->hConsol);
		}if (g.getLlego()) {
			Pasar();
		}
	};
	void Pasar() {
		string mensaje = "Presione espacio para continuar...";
		int x = (120 - mensaje.size()) / 2;
		setXY(x,25);
		cout << mensaje;
		char tecla;
		do {
			tecla = _getch();
			if (tecla != 32) {
				son.SonidoError();
			}
		} while (tecla != 32);
		son.SonidoExito();
		system("cls");
	};
};
