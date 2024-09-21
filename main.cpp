#include <iostream>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <iomanip>

using namespace std;

#include "FuncionesGenerales.h"
#include "ClaseFecha.h"
#include "ClaseTipoDeporte.h"
#include "ClaseArchivoTiposDeporte.h"
#include "ClaseDeporte.h"
#include "ClaseArchivoDeportes.h"
#include "ClaseEquipo.h"
#include "ClaseArchivoEquipos.h"
#include "ClaseJugador.h"
#include "ClaseArchivoJugador.h"
#include "MenuDeportes.h"
#include "MenuJugadores.h"
#include "MenuConfiguracion.h"
#include "Configuracion.h"
#include "MenuReportes.h"
#include "Reportes.h"
#include "MenuEquipos.h"
#include "MenuTiposDeporte.h"

int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"------- Menu Principal -----"<<endl;
        cout<<"Opcion 1 -> Menu Jugadores "<<endl;
        cout<<"Opcion 2 -> Menu Deportes "<<endl;
        cout<<"Opcion 3 -> Menu Equipos "<<endl;
        cout<<"Opcion 4 -> Tipos de Deporte "<<endl;
        cout<<"Opcion 5 -> Reportes "<<endl;
        cout<<"Opcion 6 -> Configuracion "<<endl;
        cout<<"Opcion 0 -> Fin del Programa "<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"Seleccione una Opcion: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: MenuJugadores();
                break;
            case 2: MenuDeportes();
                break;
            case 3: MenuEquipos();
                break;
            case 4: MenuTiposDeporte();
                break;
            case 5: MenuReportes();
                break;
            case 6: MenuConfiguracion();
                break;
            case 0: cout<<endl<<"- Gracias por Haber Utilizado el Programa. -"<<endl;
            return 0;
                break;
            default:cout<<endl<<"Opcion Inexistente"<<endl;
            cout<<"vuelve a Seleccionar otra Opcion"<<endl;
            cout<<"================================"<<endl<<endl;
        }
        system("pause");
    }
    return 0;
}
