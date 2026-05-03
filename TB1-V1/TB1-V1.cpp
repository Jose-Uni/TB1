#include <iostream>
#include "Intro.h"
#include "ContactList.h"
#include "OpportunityList.h"

using namespace std;

int main()  {
	Intro* intro = new Intro();
	intro->colorBF(0,10);
	intro->Animación();
	system("pause");
	delete intro;

	Contactlist<string> lista;
	OpportunityList<string> lista2;
   
}
