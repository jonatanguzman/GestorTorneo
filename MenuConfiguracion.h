#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

void opcion1();
void opcion2();
void opcion3();
void opcion4();
void opcion5();
void opcion6();
void opcion7();
void opcion8();
void opcion9();

void MenuConfiguracion(){
    int opc;
    while(true){
        system("cls");
        cout<<"--------------------- Configuracion ---------------------"<<endl;
        cout<<"Opcion 1 -> Copia de Seguridad del Archivo Jugadores "<<endl;
        cout<<"Opcion 2 -> Copia de Seguridad del Archivo Deportes "<<endl;
        cout<<"Opcion 3 -> Copia de Seguridad del Archivo Equipos "<<endl;
        cout<<"Opcion 4 -> Copia de Seguridad del Archivo Tipos de Deporte "<<endl;
        cout<<"Opcion 5 -> Restaurar el Arhivo Jugadores "<<endl;
        cout<<"Opcion 6 -> Restaurar el Archivo Deportes"<<endl;
        cout<<"Opcion 7 -> Restaurar el Archivo Equipos"<<endl;
        cout<<"Opcion 8 -> Restaurar el Archivo Tipos de Deporte"<<endl;
        cout<<"Opcion 9 -> Establecer Datos de Inicio"<<endl;
        cout<<"opcion 0 -> Volver al Menu Principal"<<endl;
        cout<<"----------------------------------------------------------"<<endl;
        cout<<"Seleccione una Opcion: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: opcion1();
                break;
            case 2: opcion2();
                break;
            case 3: opcion3();
                break;
            case 4: opcion4();
                break;
            case 5: opcion5();
                break;
            case 6: opcion6();
                break;
            case 7: opcion7();
                break;
            case 8: opcion8();
                break;
            case 9: opcion9();
                break;
            case 0:return;
                break;
            default:cout<<"Opcion Inexistente"<<endl;
            cout<<"vuelve a Seleccionar otra Opcion"<<endl;
                break;
        }
        system("pause");
    }
}

#endif // MENUCONFIGURACION_H_INCLUDED
