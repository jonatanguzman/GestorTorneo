#ifndef MENUEQUIPOS_H_INCLUDED
#define MENUEQUIPOS_H_INCLUDED

bool agregarRegistroEquipo();
bool buscarPorIDequipo();

void MenuEquipos(){
     ArchivoEquipos archiEqu("Equipos.dat");
    int opc;
    while(true){
        system("cls");
        cout<<"------------- Menu Equipos -------------"<<endl;
        cout<<"Opcion 1 -> Agregar Equipo "<<endl;
        cout<<"Opcion 2 -> Mostrar Equipo por ID "<<endl;
        cout<<"Opcion 3 -> Mostrar Todo "<<endl;
        cout<<"Opcion 4 -> Modificar Nombre"<<endl;
        cout<<"Opcion 5 -> Eliminar Registro de Equipo"<<endl;
        cout<<"Opcion 6 -> Dar de Alta Registro de Equipo"<<endl;
        cout<<"opcion 0 -> Volver al Menu Principal"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"Seleccione una Opcion: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistroEquipo();
                break;
            case 2: buscarPorIDequipo();
                break;
            case 3: archiEqu.MostrarEquipos();
                break;
            case 4: if(modificarNombre()==true){
                cout<<endl<<"===================="<<endl<<"Registro Modificado!"<<endl<<"===================="<<endl<<endl;}
                    else cout<<"Atencion!! No se pudo Modificar el Registro."<<endl;
                break;
            case 5: if(eliminarRegistroEquipo()==true){
            cout<<endl<<"=================="<<endl<<"Equipo Eliminado!"<<endl<<"=================="<<endl<<endl;}
                    else cout<<"Atenion!! No se pudo Eliminar el Registro."<<endl;
                break;
            case 6:if(altaRegistroEquipo()==true){
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

#endif // MENUEQUIPOS_H_INCLUDED
