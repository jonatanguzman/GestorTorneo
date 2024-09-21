#ifndef MENUJUGADORES_H_INCLUDED
#define MENUJUGADORES_H_INCLUDED
#include <cstdio>
#include <cstring>

///PROTOTIPOS
bool agregarRegistroJugador();
bool buscarPorDNI();

void MenuJugadores(){
    int opc;
     ArchivoJugador archiJug("Jugadores.dat");
    while(true){
        system("cls");
        cout<<"------------ Menu Jugadores ------------"<<endl;
        cout<<"Opcion 1 -> Agregar Jugador"<<endl;
        cout<<"Opcion 2 -> Mostrar Jugador por DNI"<<endl;
        cout<<"Opcion 3 -> Mostrar Todos los Jugadores"<<endl;
        cout<<"Opcion 4 -> Modificar Fecha de Inscripcion"<<endl;
        cout<<"Opcion 5 -> Eliminar Registro de Jugador"<<endl;
        cout<<"Opcion 6 -> Dar de Alta Registro de Jugador"<<endl;
        cout<<"opcion 0 -> Volver al Menu Principal"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"Seleccione una Opcion: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistroJugador();
                break;
            case 2: buscarPorDNI();
                break;
            case 3:archiJug.MostrarJugadores();
                break;
            case 4: if(modificarFecha()==true){
                cout<<endl<<"===================="<<endl<<"Registro Modificado!"<<endl<<endl<<"===================="<<endl<<endl;}
                    else cout<<"Atencion!! No se Pudo Modificar el Registro."<<endl;
                break;
            case 5:if(eliminarRegistro()==true){
            cout<<endl<<"=================="<<endl<<"Jugador Eliminado!"<<endl<<"=================="<<endl<<endl;}
                    else cout<<"Atencion!! No se Pudo Eliminar el Registro."<<endl;
                break;
            case 6:if(darAltaRegistro()==true){
            cout<<endl<<"======================"<<endl<<"Registro Dado de Alta!"<<endl<<"======================"<<endl<<endl;}
                    else cout<<"Atencion!! No se Pudo Dar de Alta Registro."<<endl;
                break;
            case 0:return;
                break;
            default:cout<<endl<<"Opcion Inexistente"<<endl;
            cout<<"vuelve a Seleccionar otra Opcion"<<endl;
            cout<<"================================"<<endl<<endl;
        }
        system("pause");
    }
}


#endif // MENUJUGADORES_H_INCLUDED
