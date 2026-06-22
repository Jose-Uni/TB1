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
	User* usuarioActual;

	UserList* userPs;
	Contactlist<string> contactoList;
	OpportunityList<string> oportunidadList;
	LeadQueue<string> colaa;
	FileManager* archivos;

	CONSOLE_CURSOR_INFO cursorVisible;
	HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);
public:

	Menu(UserList* user, User* ua, FileManager* f) : userPs(user), usuarioActual(ua), archivos(f) {
		this->x = 0;
		this->y = 0;
		cursorVisible.bVisible = FALSE;
		cursorVisible.dwSize = 1;
		SetConsoleCursorInfo(hConsol, &cursorVisible);
		archivos->setContactos(&contactoList);
		archivos->setOportunidades(&oportunidadList);
		archivos->LoadContacts();
		archivos->LoadOpportunities();
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
	//funciones de mostrar de ventas y contactos pq en la lista no puedo hacer aparecer el texto principal
	// y los encuadres, la IA ayudo a adaptarlos a Menu, pq tenía que acceder pero no sabía que metodo usar

	void MostrarContactos() {
		if (contactoList.vacio()) {
			
			setXY(2, 9); cout << "La lista de contactos esta vacia.";
			return;
		}

		int cont = 1;
		int lenTotal = contactoList.length();
		int xn = (120 - 55) / 2;
		string tipoTexto[7] = {
			"LEAD",
			"PROSPECTO",
			"CLIENTE", 
			"VIP", 
			"INACTIVO",
			"FRECUENTE",
			"CORPORATIVO"
		};
		for (auto it = contactoList.begin(); it != contactoList.end(); ++it) {
			system("cls");

			pr.mostrar(xn, y + 1, hConsol);
			encuadre1();
			encuadre2();
			int indice = static_cast<int>((*it).getTipo());
			setXY(2, 9); cout << "Contacto  " << cont << " de " << lenTotal;
			setXY(2, 10); cout << "=====================================";
			setXY(2, 11); cout << "ID:       " << (*it).getId();
			setXY(2, 12); cout << "Nombre:   " << (*it).getNombre();
			setXY(2, 13); cout << "Apellido: " << (*it).getApellido();
			setXY(2, 14); cout << "Email:    " << (*it).getEmail();
			setXY(2, 15); cout << "Telefono: " << (*it).getTelefono();
			setXY(2, 16); cout << "Empresa:  " << (*it).getEmpresa();
			setXY(2, 17); cout << "Cargo:    " << (*it).getCargo();
			setXY(2, 18); cout << "Tipo:    " << tipoTexto[indice];
			
			cont++;

			char tecla;
			do {
				setXY(2, 19); cout << "Presione [ESPACIO] para ver el siguiente.";
				tecla = _getch();				
			} while (tecla != 32);
		}

		system("cls");
		pr.mostrar(xn, y + 1, hConsol);
		encuadre1();
		encuadre2();
		setXY(2, 9); cout << "Has llegado al final de la lista.";
		setXY(2, 11); system("pause");
	}

	void MostrarVemtas() {
		if (oportunidadList.Vacio()) {
			
			setXY(2, 9); cout << "La lista de ventas esta vacia.";
			return;
		}

		int i = 0;
		int lenTotal = oportunidadList.length();
		int xn = (120 - 55) / 2;
		string etapaTexto[4] = {
			"PROPUESTA",
			"NEGOCIACION",
			"CERRADO_GANADO",
			"CERRADO_PERDIDO"
		};
		while (true) { // aqui la IA se uso para que se pudiera navegar hacia adelante y atras, 
			// ya que no esta dentro de la lista por errores de inclusión circular
			Opportunity<string>* op = oportunidadList.GetOportunidadPorIndice(i);

			if (op == nullptr) break;

			system("cls");
			pr.mostrar(xn, y + 1, hConsol);
			encuadre1();
			encuadre2();

			int indiceEtapa = static_cast<int>(op->getAvance());

			setXY(2, 9); std::cout << "Oportunidad " << (i + 1) << " de " << lenTotal;
			setXY(2, 10); std::cout << "================================================";
			setXY(2, 11); std::cout << "ID de la venta: " << op->getId();
			setXY(2, 12); std::cout << "Titulo de la venta: " << op->getTitulo();
			setXY(2, 13); std::cout << "Valor de la venta: $" << op->getValor();
			setXY(2, 14); std::cout << "Avance de la venta: " << etapaTexto[indiceEtapa];
			setXY(2, 15); std::cout << "Fecha de Inicio: " << op->getFechaI();
			setXY(2, 16); std::cout << "Fecha de Cierre: " << op->getFechaC();
			setXY(2, 17); std::cout << "Vendedor: " << op->getVendedor();
			setXY(2, 18); std::cout << "ID del contacto: " << op->getContacto();

			setXY(2, 19); std::cout << "Controles de navegacion:";
			setXY(2, 20); std::cout << "[ESPACIO] Avanzar   - ['B'] Retroceder - [Esc] Salir";

			char tecla = _getch();

			if (tecla == 32) { 
				i++;
				if (i >= lenTotal) { 
					system("cls");
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1();
					encuadre2();
					setXY(2, 9); std::cout << "Has llegado a la ultima venta.";
					setXY(2, 11); std::cout << "Presione una tecla para volver al recuadro...";
					_getch();
					i--; 
				}
			}
			else if (toupper(tecla) == 'B') { 
				i--;
				if (i < 0) { 
					system("cls");
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1();
					encuadre2();
					setXY(2, 9); std::cout << "Estas en la primera venta, no puedes retroceder mas.";
					setXY(2, 11); std::cout << "Presione una tecla para volver al recuadro...";
					_getch();
					i++; 
				}
			}
			else if (tecla == 27) {
				return;
			}
		}

		system("cls");
		pr.mostrar(xn, y + 1, hConsol);
		encuadre1();
		encuadre2();
		setXY(2, 9); cout << "Has llegado al final de la lista.";
		setXY(2, 11); system("pause");
	}

	void opciones() {
		int opcion = 0;
		do {
			system("cls");
			int xn = (120 - 55) / 2;
			pr.mostrar(xn, y + 1, hConsol);
			encuadre1();
			encuadre2();
			setXY(2, 9); cout << "Hola, usuario " << usuarioActual->getUser() << "\n";
			setXY(2, 11); cout << "[1] SubMenu contactos\n";
			setXY(2, 12); cout << "[2] SubMenu ventas\n";
			setXY(2, 13); cout << "[3] Ver contactos\n";
			setXY(2, 14); cout << "[4] Ver ventas\n";
			setXY(2, 15); cout << "[5] Ver filtros\n";
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
					setXY(2, 14); cout << "Ingrese el telefono: "; cin >> telefeno;
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
					setXY(2, 10); cout << "Ingrese el nombre del contacto a editar: "; cin >> nombre;
					string id = contactoList.nombreAid(nombre);
					
					Contact<string>* contacto = contactoList.GetContacto(id);
					if (contacto != nullptr) {
						char rpta;
						setXY(2, 12); cout << "Modificar el nombre ? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(25, 12); cout << " Ingrese el nuevo nombre: "; cin.ignore(); getline(cin, nombre); contacto->setNombre(nombre);
						}
						setXY(2, 13); cout << "Modificar el apellido? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(26, 13); cout << " Ingrese el nuevo apellido: "; cin.ignore(); getline(cin, apellido); contacto->setApellido(apellido);
						}
						setXY(2, 14); cout << "Modificar el email? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(23, 14); cout << " Ingrese el nuevo email: "; cin.ignore(); getline(cin, email); contacto->setEmail(email);
						}
						setXY(2, 15); cout << "Modificar el telefono? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(26, 15); cout << " Ingrese el nuevo telefono: "; cin >> telefeno; contacto->setTelefono(telefeno);
						}
						setXY(2, 16); cout << "Modificar la empresa? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(25, 16); cout << " Ingrese la nueva empresa: "; cin.ignore(); getline(cin, empresa); contacto->setEmpresa(empresa);
						}
						setXY(2, 17); cout << "Modificar el cargo? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(23, 17); cout << " Ingrese el nuevo cargo: "; cin.ignore(); getline(cin, cargo); contacto->setCargo(cargo);
						}
						setXY(2, 18); cout << "Modificar el Tipo? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(22, 18); cout << " Ingresar el Tipo nuevo: "; cin >> tag; contacto->setTipo(static_cast<Tag>(tag));
						}
						contacto->setId();
						setXY(2, 19); cout << "Contacto modificado exitosamente!";
						break;
					}
					else {
						setXY(2, 10); cout << "Contacto no encontrado!\n";
						break;
					}
					break;
				}
				case 3: {
					system("cls");
					int xn = (120 - 55) / 2;
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1();
					encuadre2();
					string nombre;
					setXY(2, 9); cout << "Eliminar Contactos";
					setXY(2, 10); cout << "Ingrese el nombre del contacto a eliminar: ";cin >> nombre;
					string id = contactoList.nombreAid(nombre);
					Contact<string>* contacto = contactoList.GetContacto(id);
					if (contacto != nullptr) {
						contacto->setTipo(Tag::INACTIVO);
					}
					else
					{
						setXY(2, 10); cout << "Contacto no encontrado!\n"; //nose si esta bien encuadrado ya tu lo ves xdd
					}
					break;
				}
				case 4: {
					break;
				}
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
					system("cls");
					int xn = (120 - 55) / 2;
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1(); encuadre2();

					if (colaa.Vacio()) {
						setXY(2, 9); cout << "No hay leads en la cola. Ve a 'Verificar Leads' primero.";
						setXY(2, 11); cout << "Presione una tecla...";
						system("pause");
						break;
					}
					
					Contact<string>* leadExtraido = colaa.dequeue();
					if (leadExtraido == nullptr) break;

					setXY(2, 9); cout << "--- Atendiendo Lead ---";
					setXY(2, 11); cout << "Nombre: " << leadExtraido->getNombre() << " " << leadExtraido->getApellido();
					setXY(2, 12); cout << "Email: " << leadExtraido->getEmail();
					setXY(2, 13); cout << "Telefono: " << leadExtraido->getTelefono();
					setXY(2, 14); cout << "Empresa: " << leadExtraido->getEmpresa();
					setXY(2, 15); cout << "Cargo: " << leadExtraido->getCargo();

					setXY(2, 17); cout << "Resultado de la llamada:";
					setXY(2, 18); cout << "[1] Interesado (Crear Oportunidad)";
					setXY(2, 19); cout << "[2] No contesta (Volver a la cola)";
					setXY(2, 20); cout << "[3] No interesado (Marcar inactivo)";
					setXY(2, 21); cout << "Opcion: ";
					int op; cin >> op;

					Contact<string>* contactoOriginal = contactoList.GetContacto(leadExtraido->getId());

					if (op == 1) {
						
						system("cls");
						pr.mostrar(xn, y + 1, hConsol);
						encuadre1(); encuadre2();

						setXY(2, 9); cout << "Registrar Nueva Oportunidad para: " << leadExtraido->getNombre();

						string titulo, fechaI, fechaF, vendedor;
						float valor;
						int avance;

						setXY(2, 11); cout << "Ingrese el titulo de la venta: "; cin.ignore(); getline(cin, titulo);
						setXY(2, 12); cout << "Ingrese el monto  ($): "; cin >> valor;
						setXY(2, 13); cout << "Ingrese la fecha de inicio (dd/mm/aa): "; cin.ignore(); getline(cin, fechaI);
						setXY(2, 14); cout << "Ingrese la fecha de cierre (dd/mm/aa): "; getline(cin, fechaF);
						setXY(2, 15); cout << "Ingrese el vendedor: "; cin.ignore(); getline(cin, vendedor);
						setXY(2, 16); cout << "Ingrese la etapa (0-3): "; cin >> avance;

						if (contactoOriginal != nullptr) {
							contactoOriginal->setTipo(Tag::PROSPECTO);

							Opportunity<string> oportunidad(titulo, valor, static_cast<Etapa>(avance),
								fechaI, fechaF, vendedor, contactoOriginal->getId());
							oportunidadList.pushback(oportunidad);

							setXY(2, 16); cout << "Oportunidad creada y contacto actualizado a PROSPECTO";

						}
						else {
							setXY(2, 10); cout << "Contacto no encontrado!\n"; //nose si esta bien encuadrado ya tu lo ves xdd
						}
						
					}
					else if (op == 2) {
						colaa.enqueue(*leadExtraido);
						setXY(2, 17); cout << "Lead devuelto a la cola para llamar mas tarde.";
					}
					else if (op == 3) {
						if (contactoOriginal != nullptr) {
							contactoOriginal->setTipo(Tag::INACTIVO);
						}
						setXY(2, 17); cout << "Lead marcado como INACTIVO.";
					}
					delete leadExtraido;
				}break;
				case 2: {
					system("cls");
					int xn = (120 - 55) / 2;
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1();
					encuadre2();
					setXY(2, 9); cout << "Agregar nueva venta";
					setXY(2, 10); cout << "Ingrese el nombre del contacto: "; string nombre; cin >> nombre;
					string id = contactoList.nombreAid(nombre);
					Contact <string>* contacto = contactoList.GetContacto(id);
					if (contacto != nullptr) {
						string titulo, fechaI, fechaF, vendedor;
						float valor; int avance;
						setXY(2, 11); cout << "Ingrese el titulo: "; cin.ignore(); getline(cin, titulo);
						setXY(2, 12); cout << "Ingrese el valor: "; cin >> valor;
						setXY(2, 13); cout << "Ingrese el avance (0 a 3) ";
						setXY(2, 14); cout << "PROPUESTA,NEGOCIACION,CERRADO_GANADO,CERRADO_PERDIDO "; cin >> avance;
						setXY(2, 15); cout << "Ingrese la fecha de inicio: "; cin.ignore(); getline(cin, fechaI);
						setXY(2, 16); cout << "Ingrese la fecha de cierre: "; getline(cin, fechaF);
						setXY(2, 17); cout << "Ingrese el vendedor: "; getline(cin, vendedor);
						setXY(2, 18); cout << "Venta creada exitosamente!";
						Opportunity<string> oportunidad(titulo, valor, static_cast<Etapa>(avance), fechaI, fechaF, vendedor, id);
						oportunidadList.pushback(oportunidad);

					}
					else {
						setXY(2, 11); cout << "No existe contacto con ese nombre";
					}
					
				}break;
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
					setXY(2, 11); cout << "ID = 2 1°eras letras de: Titulo,Vendedor asignado,Fecha Inicio y Cierre: "; cin >> id;
					Opportunity<string>* oportunidad = oportunidadList.GetOportunidad(id);
					if (oportunidad != nullptr) {
						char rpta;
						setXY(2, 12); cout << "Modificar el titulo ? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(25, 12); cout << " Ingrese el nuevo titulo: "; cin.ignore(); getline(cin, titulo); oportunidad->setTitulo(titulo);
						}
						setXY(2, 13); cout << "Modificar el valor? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(23, 13); cout << " Ingrese el nuevo valor: "; cin >> valor; oportunidad->setValor(valor);
						}
						setXY(2, 14); cout << "Modificar el avance? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(24, 14); cout << " Ingrese el nuevo avance: "; cin >> avance; oportunidad->setAvance(static_cast<Etapa>(avance));
						}
						setXY(2, 15); cout << "Modificar la fecha de inicio? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(33, 15); cout << " Ingrese la nueva fecha de inicio: "; cin.ignore(); getline(cin, fechaI); oportunidad->setFechaI(fechaI);
						}
						setXY(2, 16); cout << "Modificar la fecha de cierre? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(33, 16); cout << " Ingrese la nueva fecha de cierre: "; cin.ignore(); getline(cin, fechaF); oportunidad->setFechaC(fechaF);
						}
						setXY(2, 17); cout << "Modificar el vendedor? "; cin >> rpta;
						if (toupper(rpta) == 'S') {
							setXY(26, 17); cout << " Ingrese el nuevo vendedor: "; cin.ignore(); getline(cin, vendedor); oportunidad->setVendedor(vendedor);
						}
						oportunidad->setId();
						setXY(2, 19); cout << "Venta modificada exitosamente!";
						break;
					}
					else {
						setXY(2, 10); cout << "Venta no encontrada!\n";
					}
				}break;
				case 4: {
					system("cls");
					int xn = (120 - 55) / 2;
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1();
					encuadre2();
					string id;
					char rpta;
					setXY(2, 9); cout << "Cerrar venta";
					setXY(2, 10); cout << "Ingrese el ID de la venta a cerrar: ";
					setXY(2, 11); cout << "ID = 2 1°eras letras de: Titulo,Vendedor asignado, Fecha Inicio y Fecha Cierre: "; cin >> id;
					Opportunity<string>* oportunidad = oportunidadList.GetOportunidad(id);
					if (oportunidad != nullptr) {
						setXY(2, 12); cout << "La venta a cerrar fue ganada o perdida? (G/P): "; cin >> rpta;
						if (toupper(rpta) == 'G') {
							oportunidad->setAvance(Etapa::CERRADO_GANADO);
						}
						else if (toupper(rpta) == 'P') {
							oportunidad->setAvance(Etapa::CERRADO_PERDIDO);
						}
					}
					else {
						setXY(2, 10); cout << "Contacto no encontrado!\n"; //no se si esta bien encuadrado 
					}
				}break;
				case 5: {
					//cerrar xd es pa un cambio random
				}break;

				}
				
			}break;
			case 3: {
				system("cls");
				int opcionC = 0;
				int xn = (120 - 55) / 2;
				pr.mostrar(xn, y + 1, hConsol);
				encuadre1();
				encuadre2();
				MostrarContactos();
				
			}break;
			case 4: {
				system("cls");
				int opcionC = 0;
				int xn = (120 - 55) / 2;
				pr.mostrar(xn, y + 1, hConsol);
				encuadre1();
				encuadre2();
				MostrarVemtas();
				
			}break;
			case 5: {
				system("cls");
				int opcionF = 0;
				int xn = (120 - 55) / 2;
				pr.mostrar(xn, y + 1, hConsol);
				encuadre1();
				encuadre2();
				setXY(2, 9);  cout << "Reportes y Filtros Avanzados";
				setXY(2, 11); cout << "[1] Filtrar Contactos VIP";
				setXY(2, 12); cout << "[2] Ordenar Ventas (Por Valor/Etapa) y Ver";
				setXY(2, 13); cout << "[3] Resumen Financiero del Pipeline (Dinero)";
				setXY(2, 15); cout << "[4] Regresar al Menu Principal";
				setXY(2, 17); cout << "Opcion: [   ]";
				setXY(12,17); cin >> opcionF;
				switch (opcionF) {
				case 1: { 
					system("cls");
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1(); encuadre2();
					setXY(2, 9); cout << "=== Contactos VIPs Activos ===";

					
					auto filtrarVIPActivos = [&](Contactlist<string>& lista) {
						Contactlist<string> resultado;
						lista.buscarVipActivo([&](Contact<string>& c) {
							if (c.getTipo() == Tag::VIP) {
								resultado.pushback(c);
							}
							});
						return resultado;
						};

					Contactlist<string> vipsActivos = filtrarVIPActivos(contactoList);

					if (vipsActivos.vacio()) {
						setXY(2, 11); cout << "No hay clientes VIP registrados.";
					}
					else {
						int posY = 11;
						for (auto it = vipsActivos.begin(); it != vipsActivos.end(); ++it) {
							setXY(2, posY++); cout << "- " << (*it).getNombre() << " " << (*it).getApellido();
							setXY(2,13); cout <<	" ,Empresa: " << (*it).getEmpresa() << " ,Cargo: " << (*it).getCargo();
						}
					}
					setXY(2, 20); cout << "Presione cualquier tecla para regresar...";					
				} break;

				case 2: { 
					auto porValor = [](Opportunity<string>& a, Opportunity<string>& b) {
						return a.getValor() > b.getValor();
						};

					auto porEtapa = [](Opportunity<string>& a, Opportunity<string>& b) {
						return static_cast<int>(a.getAvance()) < static_cast<int>(b.getAvance());
						};

					
					oportunidadList.Orden(porValor);
					oportunidadList.Orden(porEtapa);

					system("cls");
					setXY(2, 9); cout << "Lista de oportunidades ordenada correctamente.";
					setXY(2, 10); cout << "Mostrando ventas en Orden";
					
					MostrarVemtas();
				} break;

				case 3: { 
					system("cls");
					pr.mostrar(xn, y + 1, hConsol);
					encuadre1(); encuadre2();
					setXY(2, 9); cout << "=== Resumen Financiero de Ventas ===";


					auto totalPorEtapa = [&](OpportunityList<string>& lista, Etapa etapa) {
						float total = 0.0f;
						lista.sumEtapa([&](Opportunity<string>& o) {
							if (o.getAvance() == etapa) {
								total += o.getValor();
							}
							});
						return total;
						};

				
					float ganadas = totalPorEtapa(oportunidadList, Etapa::CERRADO_GANADO);
					float enNegociacion = totalPorEtapa(oportunidadList, Etapa::NEGOCIACION);
					float perdidas = totalPorEtapa(oportunidadList, Etapa::CERRADO_PERDIDO);
					float enPropuesta = totalPorEtapa(oportunidadList, Etapa::PROPUESTA);

					
					setXY(2, 12); cout << "Dinero en Cierres Ganados: $" << ganadas;
					setXY(2, 13); cout << "Dinero en Negociacion:     $" << enNegociacion;
					setXY(2, 14); cout << "Dinero en Propuestas:      $" << enPropuesta;
					setXY(2, 15); cout << "Dinero Perdido:            $" << perdidas;

					setXY(2, 17); cout << "Total de Negociacion + Propuesta: $" << (enNegociacion + enPropuesta);
					setXY(2, 17); cout << "Total de cierres ganados - perdidas: $" << (ganadas-perdidas);

					setXY(2, 20); cout << "Presione cualquier tecla para regresar..."; system("pause>0");
				} break;

				case 4: break;
				}
				
			}break;
			case 6: {
				system("cls");
				int opcionC = 0;
				int xn = (120 - 55) / 2;
				pr.mostrar(xn, y + 1, hConsol);
				encuadre1();
				encuadre2();
				setXY(2, 9); cout << "--- Verificacion de Leads ---";

				
				colaa = contactoList.GetLeads();

				setXY(2, 11); cout << "Cola de leads actualizada con exito a partir de los contactos.";
				setXY(2, 12); cout << "Cola de tamaño: " << colaa.Size();
				

				setXY(2, 14); cout << "Presione cualquier tecla para regresar..."; system("pause>0");
			}break;
			case 7:
				break;
			}
		} while (opcion != 7);
	}
	
};
