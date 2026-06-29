#include "Intro.h"
#include "ContactList.h"
#include "OpportunityList.h"
#include "LeadQueue.h"
#include "MenuPass.h"
#include "Menu.h"

using namespace std;

int main()  {
    UserList ListaUsuarios;


	Intro* intro = new Intro();
	intro->colorBF(0,10);
	intro->Animación();
	MenuPass* menuP = new MenuPass(&ListaUsuarios);
    menuP->mostrarMenu();
    Menu* menuPrin = new Menu(menuP->obtenerUsuarios(),menuP->getUserActual(),menuP->getArchivos());
    menuPrin->menu();
	delete intro;
	delete menuP;
	delete menuPrin;


    return 0;
}
