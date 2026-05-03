#include <iostream>
#include "Intro.h"

using namespace std;

int main()  {
	Intro* intro = new Intro();
	intro->colorBF(0,10);
	intro->Animación();
	system("pause");
	delete intro;
   
}
