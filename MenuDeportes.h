#ifndef MENUDEPORTES_H_INCLUDED
#define MENUDEPORTES_H_INCLUDED
#include <cstdio>
#include <cstring>

bool agregarRegistroDeporte();
bool buscarPorID();

void MenuDeportes(){
     ArchivoDeportes archiDep("Deportes.dat");
    int opc;
    while(true){
        system("cls");
        cout<<"------------ Menu Deportes ------------"<<endl;
        cout<<"Opcion 1 -> Agregar Deporte "<<endl;
        cout<<"Opcion 2 -> Mostrar Deporte por ID "<<endl;
        cout<<"Opcion 3 -> Mostrar Todos "<<endl;
        cout<<"Opcion 4 -> Modificar Anio de Origen"<<endl;
        cout<<"Opcion 5 -> Eliminar Registro de Deporte"<<endl;
        cout<<"Opcion 6 -> Dar de Alta Registro de Deporte"<<endl;
        cout<<"opcion 0 -> Volver al Menu Principal"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"Seleccione una Opcion: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistroDeporte();
                break;
            case 2: buscarPorID();
                break;
            case 3: archiDep.MostrarDeportes();
                break;
            case 4: if(modificarAnio()==true){
                cout<<endl<<"===================="<<endl<<"Registro Modificado!"<<endl<<"===================="<<endl<<endl;}
                    else cout<<"Atencion!! No se pudo Modificar el Registro."<<endl;
                break;
            case 5: if(eliminarRegistroDeporte()==true){
            cout<<endl<<"=================="<<endl<<"Deporte Eliminado!"<<endl<<"=================="<<endl<<endl;}
                    else cout<<"Atencion!! No se pudo Eliminar el Registro."<<endl;
                break;
            case 6:if(altaRegistroDeporte()==true){
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

#endif // MENUDEPORTES_H_INCLUDED
