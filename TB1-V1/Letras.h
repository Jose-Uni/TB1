#pragma once
#include "header.h"

using namespace std;
struct Vacio {
	string borrar =
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n";
	void borrarL(int x, int y, HANDLE hConsole) {
		istringstream iss(borrar);
		string linea;
		int contL = 0;
		while (getline(iss, linea)) {
			COORD coord;
			coord.X = x;
			coord.Y = y + contL;
			SetConsoleCursorPosition(hConsole, coord);
			cout << linea;
			contL++;
		}
	}
};
struct C {
	Vacio vacio;
	bool llego = false;
	string lineasC = 
		"     ___     \n"
		"    /  /\\    \n"
		"   /  /:/    \n"
		"  /  /:/     \n"
		" /  /:/  ___ \n"
		"/__/:/  /  /\\\n"
		"\\  \\:\\ /  /:/\n"
		" \\  \\:\\  /:/ \n"
		"  \\  \\:\\/:/  \n"
		"   \\  \\::/   \n"
		"    \\__\\/    \n";
	void mostrar(int x, int y,HANDLE hConsole) {
		istringstream iss(lineasC);
		string linea;
		int contL = 0;
		while (getline(iss,linea)) {
			COORD coord;
			coord.X = x;
			coord.Y = y + contL;
			SetConsoleCursorPosition(hConsole, coord);
			cout << linea;
			contL++;
		}
	}
	void animar(int x, int y, int dx, HANDLE hConsole) {
		llego = false;
		while (true) {
			vacio.borrarL(x, y, hConsole);
			x += dx;
			mostrar(x, y, hConsole);
			Sleep(1);
			if (x <= 32) {
				dx *= 0;
				llego = true;
				break;
			}
		}
	}
	bool getLlego() {
		return llego;
	}
};
struct H {
	Vacio vacio;
	bool llego = false;
	string lineasH =
		"     ___     \n"
		"    /__/\\    \n"
		"    \\  \\:\\   \n"
		"     \\__\\:\\  \n"
		" ___ /  /::\\ \n"
		"/__/\\  /:/\\:\\\n"
		"\\  \\:\\/:/__\\/\n"
		" \\  \\::/     \n"
		"  \\  \\:\\     \n"
		"   \\  \\:\\    \n"
		"    \\__\\/    \n"
		"             \n";
	void mostrar(int x, int y, HANDLE hConsole) {
		istringstream iss(lineasH);
		string linea;
		int contL = 0;
		while (getline(iss, linea)) {
			COORD coord;
			coord.X = x;
			coord.Y = y + contL;
			SetConsoleCursorPosition(hConsole, coord);
			cout << linea;
			contL++;
		}
	}
	void animar(int x, int y, int dx, HANDLE hConsole) {
		llego = false;
		while (true) {
			vacio.borrarL(x, y, hConsole);
			x += dx;
			mostrar(x, y, hConsole);
			Sleep(1);
			if (x <= 46) {
				llego = true;
				dx *= 0;
				break;
			}
		}
	}
	bool getLlego() {
		return llego;
	}

};
struct E {
	Vacio vacio;
	bool llego = false;
	string lineasE =
		"     ___     \n"
		"    /  /\\    \n"
		"   /  /:/_   \n"
		"  /  /:/ /\\  \n"
		" /  /:/ /:/  \n"
		"/__/:/ /:/ /\\\n"
		"\\  \\:\\/:/ /:/\n"
		" \\  \\::/ /:/ \n"
		"  \\  \\:\\/:/  \n"
		"   \\  \\::/   \n"
		"    \\__\\/    \n";
	void mostrar(int x, int y, HANDLE hConsole) {
		istringstream iss(lineasE);
		string linea;
		int contL = 0;
		while (getline(iss, linea)) {
			COORD coord;
			coord.X = x;
			coord.Y = y + contL;
			SetConsoleCursorPosition(hConsole, coord);
			cout << linea;
			contL++;
		}
	}
	void animar(int x, int y, int dx, HANDLE hConsole) {
		llego = false;
		while (true) {
			vacio.borrarL(x, y, hConsole);
			x += dx;
			mostrar(x, y, hConsole);
			Sleep(1);
			if (x <= 60) {
				dx *= 0;
				llego = true;
				break;
			}
		}
	}
	bool getLlego() {
		return llego;
	}
};
struct T {
	Vacio vacio;
	bool llego = false;
	string lineaT =
		"             \n"
		"     ___     \n"
		"    /  /\\    \n"
		"   /  /:/    \n"
		"  /  /:/     \n"
		" /  /::\\     \n"
		"/__/:/\\:\\    \n"
		"\\__\\/  \\:\\   \n"
		"     \\  \\:\\  \n"
		"      \\__\\/  \n"
		"             \n";
	void mostrar(int x, int y,HANDLE hConsole) {
		istringstream iss(lineaT);
		string linea;
		int contL = 0;
		while (getline(iss,linea)) {
			COORD coord;
			coord.X = x;
			coord.Y = y + contL;
			SetConsoleCursorPosition(hConsole, coord);
			cout << linea;
			contL++;
		}
	}
	void animar(int x, int y, int dx, HANDLE hConsole) {
		llego = false;
		while (true) {
			vacio.borrarL(x, y, hConsole);
			x += dx;
			mostrar(x, y, hConsole);
			Sleep(1);
			if (x <= 74) {
				dx *= 0;
				llego = true;
				break;
			}
		}
	}
	bool getLlego() {
		return llego;
	}
};
struct N {
	Vacio vacio;
	bool llego = false;
	string lineasN =
		"     ___     \n"
		"    /__/\\    \n"
		"    \\  \\:\\   \n"
		"     \\  \\:\\  \n"
		" _____\\__\\:\\ \n"
		"/__/::::::::\\\n"
		"\\  \\:\\~~\\~~\\/\n"
		" \\  \\:\\  ~~~ \n"
		"  \\  \\:\\     \n"
		"   \\  \\:\\    \n"
		"    \\__\\/    \n";
	void mostrar(int x, int y,HANDLE hConsole) {
		istringstream iss(lineasN);
		string linea;
		int contL = 0;
		while (getline(iss,linea)) {
			COORD coord;
			coord.X = x;
			coord.Y = y + contL;
			SetConsoleCursorPosition(hConsole, coord);
			cout << linea;
			contL++;
		}
	}
	void animar(int x, int y, int dx, HANDLE hConsole) {
		llego = false;
		while (true) {
			vacio.borrarL(x, y, hConsole);
			x += dx;
			mostrar(x, y, hConsole);
			Sleep(1);
			if (x <= 38) {
				dx *= 0;
				llego = true;
				break;
			}
		}
	}
	bool getLlego() {
		return llego;
	}
};
struct E2 {
	Vacio vacio;
	bool llego = false;
	string lineasE2 =
		"     ___     \n"
		"    /  /\\    \n"
		"   /  /:/_   \n"
		"  /  /:/ /\\  \n"
		" /  /:/ /:/  \n"
		"/__/:/ /:/ /\\\n"
		"\\  \\:\\/:/ /:/\n"
		" \\  \\::/ /:/ \n"
		"  \\  \\:\\/:/  \n"
		"   \\  \\::/   \n"
		"    \\__\\/    \n";
	void mostrar(int x, int y,HANDLE hConsole) {
		istringstream iss(lineasE2);
		string linea;
		int contL = 0;
		while (getline(iss,linea)) {
			COORD coord;
			coord.X = x;
			coord.Y = y + contL;
			SetConsoleCursorPosition(hConsole, coord);
			cout << linea;
			contL++;
		}
	}
	void animar(int x, int y, int dx, HANDLE hConsole) {
		llego = false;
		while (true) {
			vacio.borrarL(x, y, hConsole);
			x += dx;
			mostrar(x, y, hConsole);
			Sleep(1);
			if (x <= 52) {
				dx *= 0;
				llego = true;
				break;
			}
		}
	}
	bool getLlego() {
		return llego;
	}
};
struct G {
	Vacio vacio;
	bool llego = false;
	string lineasG =
		"     ___     \n"
		"    /  /\\    \n"
		"   /  /:/_   \n"
		"  /  /:/ /\\  \n"
		" /  /:/_/::\\ \n"
		"/__/:/__\\/\\:\\\n"
		"\\  \\:\\ /~~/:/\n"
		" \\  \\:\\  /:/ \n"
		"  \\  \\:\\/:/  \n"
		"   \\  \\::/   \n"
		"    \\__\\/    \n";
	void mostrar(int x, int y,HANDLE hConsole) {
		istringstream iss(lineasG);
		string linea;
		int contL = 0;
		while (getline(iss,linea)) {
			COORD coord;
			coord.X = x;
			coord.Y = y + contL;
			SetConsoleCursorPosition(hConsole, coord);
			cout << linea;
			contL++;
		}
	}
	void animar(int x, int y, int dx, HANDLE hConsole) {
		llego = false;
		while (true) {
			vacio.borrarL(x, y, hConsole);
			x += dx;
			mostrar(x, y, hConsole);
			Sleep(1);
			if (x <= 66) {
				dx *= 0;
				llego = true;
				break;
			}
		}
	}
	bool getLlego() {
		return llego;
	}
};


