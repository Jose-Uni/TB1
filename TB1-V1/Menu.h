#pragma once
#include <sstream>
#include "FileManager.h"
#include "header.h"

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
	string idUsuario;

	UserList* userPs;
	Contactlist<string> contactoList;
	OpportunityList<string> oportunidadList;
	FileManager archivos=FileManager(&contactoList, &oportunidadList, userPs);

	CONSOLE_CURSOR_INFO cursorVisible;
	HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	Menu(UserList* user, string id) : userPs(user), idUsuario(id) {
		this->x = 0;
		this->y = 0;
		cursorVisible.bVisible = FALSE;
		cursorVisible.dwSize = 1;
		SetConsoleCursorInfo(hConsol, &cursorVisible);
	}
	~Menu() {
	
	};
	void setXY(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(hConsol, coord);
	}
	void menu() {
		int xn = (120 - 55) / 2;
		pr.mostrar(xn, y + 1, hConsol);
		encuadre1();
		encuadre2();
		opciones();


	}
	void encuadre1() {
		int xn = 0, yn = 8;
		for (int i = 1; i < 90; i++) {
			setXY(i, yn);
			cout << "-";
		}
		for (int i = 1; i < 90; i++) {
			setXY(i, yn + 18);
			cout << "-";
		}
		for (int i = 8; i < 27; i++) {
			setXY(xn, i);
			cout << "|";
		}
		for (int i = 8; i < 27; i++) {
			setXY(xn + 89, i);
			cout << "|";
		}
	}
	void encuadre2() {
		int xn = 90, yn = 8;
		for (int i = 1; i < 28; i++) {
			setXY(xn + i, yn);
			cout << "-";
		}
		for (int i = 1; i < 28; i++) {
			setXY(xn + i, yn + 18);
			cout << "-";
		}
		for (int i = 8; i < 27; i++) {
			setXY(xn, i);
			cout << "|";
		}
		for (int i = 8; i < 27; i++) {
			setXY(xn + 28, i);
			cout << "|";
		}
	}

	// lo anterior es todo lo visual

	void opciones() {
		int opcion = 0;
		do {
			system("cls");
			int xn = (120 - 55) / 2;
			pr.mostrar(xn, y + 1, hConsol);
			encuadre1();
			encuadre2();
			setXY(2, 9); cout << "Hola, usuario " << userPs->nombreUsuario() << "\n";
			setXY(2, 11); cout << "[1] SubMenu contactos\n";
			setXY(2, 12); cout << "[2] SubMenu ventas\n";
			setXY(2, 13); cout << "[3] Ver contactos\n";
			setXY(2, 14); cout << "[4] Ver ventas\n";
			setXY(2, 15); cout << "[5] Ver oportunidades\n";
			setXY(2, 16); cout << "[6] Verificar leads\n";
			setXY(2, 17); cout << "[7] Salir\n";
			setXY(2, 19); cout << "Opcion: [   ]";
			setXY(12, 19); cin >> opcion;
			switch (opcion) {
			case 1: {
				system("cls");
				int opcionC = 0;
				int xn = (120 - 55) / 2;
				pr.mostrar(xn, y + 1, hConsol);
				encuadre1();
				encuadre2();
				setXY(2, 9); cout << "SubMenu Contactos";
				setXY(2, 11); cout << "[1] Anadir contacto\n";
				setXY(2, 12); cout << "[2] Editar contacto\n";
				setXY(2, 13); cout << "[3] Eliminar contacto\n";
				setXY(2, 14); cout << "[4] Regresar\n";
				setXY(2, 15); cout << "Opcion: [   ]";
				setXY(12, 15); cin >> opcionC;
				switch (opcionC) {
				case 1: {
					system("cls");
					int xn = (120 - 55) / 2;
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1();
					encuadre2();
					setXY(2, 9); cout << "Anadir Contactos";
					string nombre, apellido, email, empresa, cargo;
					int telefeno, tag;
					setXY(2, 11); cout << "Ingrese el nombre: "; cin.ignore(); getline(cin, nombre);
					setXY(2, 12); cout << "Ingrese el apellido: "; getline(cin, apellido);
					setXY(2, 13); cout << "Ingrese el email: "; getline(cin, email);
					setXY(2, 14); cout << "Ingrese el teléfono: "; cin >> telefeno;
					setXY(2, 15); cout << "Ingrese la empresa: "; cin.ignore(); getline(cin, empresa);
					setXY(2, 16); cout << "Ingrese el cargo: "; getline(cin, cargo);
					setXY(2, 17); cout << "Ingrese el Tipo (de 0 a 6): ";
					setXY(2, 18); cout << "LEAD,PROSPECTO,CLIENTE,VIP,INACTIVO,FRECUENTE,CORPORATIVO: "; cin >> tag;
					setXY(2, 19); cout << "Contacto añadido exitosamente!";
					Contact<string> contacto(nombre, apellido, email, telefeno, empresa, cargo, static_cast<Tag>(tag));
					contactoList.pushback(contacto);
					break;
				}
				case 2: {
					system("cls");
					int xn = (120 - 55) / 2;
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1();
					encuadre2();
					setXY(2, 9); cout << "Editar Contactos";
					string nombre, apellido, email, empresa, cargo;
					int telefeno, tag;
					string id;
					setXY(2, 10); cout << "Ingrese el ID del contacto a editar: ";
					setXY(2, 11); cout << "ID = 2 1eras letras de: Nombre, Apelldio, Empresa y Cargo: "; cin >> id;
					Contact<string>* contacto = contactoList.GetContacto(id);
					if (contacto != nullptr) {
						char rpta;
						setXY(2, 12); cout << "Modificar el nombre ? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(25, 12); cout << "Ingrese el nuevo nombre: "; cin.ignore(); getline(cin, nombre);
						}
						setXY(2, 13); cout << "Modificar el apellido? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(26, 13); cout << "Ingrese el nuevo apellido: "; cin.ignore(); getline(cin, apellido);
						}
						setXY(2, 14); cout << "Modificar el email? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(23, 14); cout << "Ingrese el nuevo email: "; cin.ignore(); getline(cin, email);
						}
						setXY(2, 15); cout << "Modificar el teléfono? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(26, 15); cout << "Ingrese el nuevo teléfono: "; cin >> telefeno;
						}
						setXY(2, 16); cout << "Modificar la empresa? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(25, 16); cout << "Ingrese la nueva empresa: "; cin.ignore(); getline(cin, empresa);
						}
						setXY(2, 17); cout << "Modificar el cargo? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(23, 17); cout << "Ingrese el nuevo cargo: "; cin.ignore(); getline(cin, cargo);
						}
						setXY(2, 18); cout << "Modificar el Tipo? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(22, 18); cout << "Ingresar el Tipo nuevo: "; cin >> tag;
						}
						contacto->setId();
						setXY(2, 19); cout << "Contacto modificado exitosamente!"; cin >> rpta;
					}
					else {
						setXY(2, 10); cout << "Contacto no encontrado!\n";
					}
					break;
				}
				case 3: {
					system("cls");
					int xn = (120 - 55) / 2;
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1();
					encuadre2();
					string id;
					setXY(2, 9); cout << "Eliminar Contactos";
					setXY(2, 10); cout << "Ingrese el ID del contacto a eliminar: ";
					setXY(2, 11); cout << "ID = 2 1eras letras de: Nombre, Apelldio, Empresa y Cargo: "; cin >> id;
					Contact<string>* contacto = contactoList.GetContacto(id);
					contacto->setTipo(Tag::INACTIVO);
				}
				case 4:
					break;
				}
				break;
			}
			case 2: {
				system("cls");
				int opcionV = 0;
				int xn = (120 - 55) / 2;
				pr.mostrar(xn, y + 1, hConsol);
				encuadre1();
				encuadre2();
				setXY(2, 9); cout << "SubMenu Ventas";
				setXY(2, 11); cout << "[1] Atender Leads\n";
				setXY(2, 12); cout << "[2] Agregar nueva venta\n";
				setXY(2, 13); cout << "[3] Editar venta\n";
				setXY(2, 14); cout << "[4] Cerrar venta\n";
				setXY(2, 15); cout << "[5] Regresar\n";
				setXY(2, 16); cout << "Opcion: [   ]";
				setXY(12, 16); cin >> opcionV;
				switch (opcionV) {
				case 1: {

				}
				case 2: {
					system("cls");
					int xn = (120 - 55) / 2;
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1();
					encuadre2();
					setXY(2, 9); cout << "Agregar nueva venta";
					setXY(2, 10); cout << "Ingrese el Id del contacto: "; string id; cin >> id;
					Contact <string>* contacto = contactoList.GetContacto(id);
					if (contacto != nullptr) {
						string titulo, fechaI, fechaF, vendedor;
						float valor; int avance;
						setXY(2, 11); cout << "Ingrese el titulo: "; cin.ignore(); getline(cin, titulo);
						setXY(2, 12); cout << "Ingrese el valor: "; cin >> valor;
						setXY(2, 13); cout << "Ingrese el avance ";
						setXY(2, 14); cout << "PROPUESTA,NEGOCIACION,CERRADO_GANADO,CERRADO_PERDIDO"; cin >> avance;
						setXY(2, 14); cout << "Ingrese la fecha de inicio: "; cin.ignore(); getline(cin, fechaI);
						setXY(2, 15); cout << "Ingrese la fecha de cierre: "; cin.ignore(); getline(cin, fechaF);
						setXY(2, 16); cout << "Ingrese el vendedor: "; cin.ignore(); getline(cin, vendedor);
						setXY(2, 17); cout << "Venta creada exitosamente!";
						Opportunity<string> oportunidad(titulo, valor, static_cast<Etapa>(avance), fechaI, fechaF, vendedor, id);
						oportunidadList.pushback(oportunidad);

					}
					else {
						setXY(2, 11); cout << "No existe contacto con ese ID";

					}
					break;
				}
				case 3: {
					system("cls");
					int xn = (120 - 55) / 2;
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1();
					encuadre2();
					setXY(2, 9); cout << "Editar Contactos";
					string titulo, fechaI, fechaF, vendedor;
					float valor; int avance;
					string id;
					setXY(2, 10); cout << "Ingrese el ID de la venta a editar: ";
					setXY(2, 11); cout << "ID = 2 1eras letras de: Titulo,Vendedor asignado, Fecha Inicio y Fecha Cierre: "; cin >> id;
					Opportunity<string>* oportunidad = oportunidadList.GetOportunidad(id);
					if (oportunidad != nullptr) {
						char rpta;
						setXY(2, 12); cout << "Modificar el titulo ? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(25, 12); cout << "Ingrese el nuevo titulo: "; cin.ignore(); getline(cin, titulo);
						}
						setXY(2, 13); cout << "Modificar el valor? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(26, 13); cout << "Ingrese el nuevo valor: "; cin >> valor;
						}
						setXY(2, 14); cout << "Modificar el avance? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(23, 14); cout << "Ingrese el nuevo avance: "; cin >> avance;
						}
						setXY(2, 15); cout << "Modificar la fecha de inicio? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(26, 15); cout << "Ingrese la nueva fecha de inicio: "; cin.ignore(); getline(cin, fechaI);
						}
						setXY(2, 16); cout << "Modificar la fecha de cierre? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(25, 16); cout << "Ingrese la nueva fecha de cierre: "; cin.ignore(); getline(cin, fechaF);
						}
						setXY(2, 17); cout << "Modificar el vendedor? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(23, 17); cout << "Ingrese el nuevo vendedor: "; cin.ignore(); getline(cin, vendedor);
						}
						oportunidad->setId();
						setXY(2, 19); cout << "Venta modificada exitosamente!"; cin >> rpta;
					}
					else {
						setXY(2, 10); cout << "Venta no encontrada!\n";

					}
					break;
				}
				case 4: {
					break;
				case 5:
					break;
				}

				}
			}
			case 3: {
				system("cls");
				int opcionC = 0;
				int xn = (120 - 55) / 2;
				pr.mostrar(xn, y + 1, hConsol);
				encuadre1();
				encuadre2();
			}
			case 4: {
				system("cls");
				int opcionC = 0;
				int xn = (120 - 55) / 2;
				pr.mostrar(xn, y + 1, hConsol);
				encuadre1();
				encuadre2();
			}
			case 5: {
				system("cls");
				int opcionC = 0;
				int xn = (120 - 55) / 2;
				pr.mostrar(xn, y + 1, hConsol);
				encuadre1();
				encuadre2();
			}
			case 6: {
				system("cls");
				int opcionC = 0;
				int xn = (120 - 55) / 2;
				pr.mostrar(xn, y + 1, hConsol);
				encuadre1();
				encuadre2();
			}
			case 7:
				break;

			}
		} while (opcion != 7);
	}
	
};
