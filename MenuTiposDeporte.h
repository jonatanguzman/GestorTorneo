#ifndef MENUTIPOSDEPORTE_H_INCLUDED
#define MENUTIPOSDEPORTE_H_INCLUDED

#include <cstdio>
#include <cstring>

bool agregarRegistroTipoDeporte();
bool buscarPorIDtipo();

void MenuTiposDeporte(){
     ArchivoTiposDeporte archiTip("TipodeDeporte.dat");
    int opc;
    while(true){
        system("cls");
        cout<<"---------- Menu Tipos de Deportes ----------"<<endl;
        cout<<"Opcion 1 -> Agregar Tipo Deporte "<<endl;
        cout<<"Opcion 2 -> Mostrar Tipo de Deporte por ID "<<endl;
        cout<<"Opcion 3 -> Mostrar Todo "<<endl;
        cout<<"Opcion 4 -> Modificar Nivel de Dificultad"<<endl;
        cout<<"Opcion 5 -> Eliminar Registro de Tipo Deporte"<<endl;
        cout<<"Opcion 6 -> Dar de Alta Registro de Tipo Deporte"<<endl;
        cout<<"opcion 0 -> Volver al Menu Principal"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"Seleccione una Opcion: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistroTipoDeporte();
                break;
            case 2: buscarPorIDtipo();
                break;
            case 3: archiTip.MostrarTipos();
                break;
            case 4: if(modificarNivel()==true){
                cout<<endl<<"===================="<<endl<<"Registro Modificado!"<<endl<<"===================="<<endl<<endl;}
                    else cout<<"Atencion!! No se pudo Modificar el Registro."<<endl;
                break;
            case 5: if(eliminarRegistroTipoDeporte()==true){
            cout<<endl<<"========================="<<endl<<"Tipo de Deporte Eliminado!"<<endl<<"========================="<<endl<<endl;}
                    else cout<<"Atencion!! No se pudo Eliminar el Registro."<<endl;
                break;
            case 6:if(altaRegistroTipoDeporte()==true){
            cout<<endl<<"======================"<<endl<<"Registro Dado de Alta!"<<endl<<"======================"<<endl<<endl;}
                    else cout<<"Atencion!! No se Pudo Dar de Alta Registro."<<endl;
                break;
            case 0:return;
                break;
            default:cout<<endl<<"Opcion Inexistente"<<endl;
            cout<<"vuelve a Seleccionar otra Opcion"<<endl;
            cout<<"================================"<<endl<<endl;
                break;
        }
        system("pause");
    }
}

#endif // MENUTIPOSDEPORTE_H_INCLUDED
