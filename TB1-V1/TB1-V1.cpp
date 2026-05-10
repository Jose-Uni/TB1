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
    Menu* menuPrin = new Menu(menuP->obtenerUsuarios(),menuP->getIdSeleccionado());
    menuPrin->menu();
	delete intro;
	delete menuP;

	
   
    //#Lambda1 filtra a las persona vip que estan activas
	Contactlist<string> listaContactos;
    auto filtrarVIPActivos = [&](Contactlist<string>& lista) {
        Contactlist<string> resultado;
        lista.buscarVipActivo([&](Contact<string>& c) {
            if (c.getTipo() == Tag::VIP) {
                resultado.pushback(c);
            }
        });
        return resultado;
    };

    //!Colocar esta linea en el menu
    Contactlist<string> vipsActivos = filtrarVIPActivos(listaContactos);


    //#Lambda2 filtra a las personas por oportunidad
    OpportunityList<string> listaOportunidades;
    auto porValor = [](Opportunity<string>& a, Opportunity<string>& b) {
        return a.getValor() > b.getValor();
    };

    auto porEtapa = [](Opportunity<string>& a, Opportunity<string>& b) {
        return static_cast<int>(a.getAvance()) < static_cast<int>(b.getAvance());
    };

    //!Colocar esta linea en el menu
    listaOportunidades.Orden(porValor);
    listaOportunidades.Orden(porEtapa);


    //#Lambda2 para saber cuanto dinera hay en las oportunidades o en la negociacion
    auto totalPorEtapa = [&](OpportunityList<string>& lista, Etapa etapa) {
        float total = 0.0f;
        lista.sumEtapa([&](Opportunity<string>& o) {
            if (o.getAvance() == etapa) {
                total += o.getValor();
            }
        });
        return total;    
    };

    float ganadas = totalPorEtapa(listaOportunidades, Etapa::CERRADO_GANADO);
    float enNegociacion = totalPorEtapa(listaOportunidades, Etapa::NEGOCIACION);

    return 0;
}
