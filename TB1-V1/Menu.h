#pragma once
#include <sstream>
#include "Contact.h"
#include "ContactList.h"
#include "Opportunities.h"
#include "OpportunityList.h"
#include "LeadQueue.h"
#include "Enums.h"

struct Principal {
	string mensaje =
		"# # ### ### # #     ##  ##  ### ###  ## ### ##   #  #  \n"
		"### #   # # # #     # # # #  #  # # #    #  # # # # #  \n"
		"### ##  # # # #     ##  ##   #  # # #    #  ##  ### #  \n"
		"# # #   # # # #     #   # #  #  # # #    #  #   # # #  \n"
		"# # ### # # ###     #   # # ### # #  ## ### #   # # ###\n";
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
			cout << endl;
			contL++;
		}
	}
};
class Menu {
private:
	Principal pr;
	int x, y;
	CONSOLE_CURSOR_INFO cursorVisible;
	HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	Menu() {
		this->x = 0;
		this->y = 0;
		cursorVisible.bVisible = FALSE;
		cursorVisible.dwSize = 1;
		SetConsoleCursorInfo(hConsol, &cursorVisible);
	}
	~Menu() {};
	void setXY(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(hConsol, coord);
	}
	void menu() {
		int xn = (120 - 55) / 2;
		pr.mostrar(xn,y+1, hConsol);
		encuadre1();
		_getch();
		
	}
	void encuadre1() {
		int xn = 0, yn = 8;
		for (int i = 1; i < 90 ; i++) {
			setXY(i,yn);
			cout << "-";
		}
		for (int i = 1; i < 90 ; i++) {
			setXY(i,yn+18);
			cout << "-";
		}
		for (int i = 8; i < 26; i++) {
			setXY(xn, i);
			cout << "|";
		}
		for (int i = 8; i < 26; i++) {
			setXY(xn+89, i);
			cout << "|";
		}
	}
	
};
