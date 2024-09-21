#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

///Opciones Vacias para Realizar Parcial
void puntoA();
void puntoB();
void puntoC();

void MenuReportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"--------------- Reportes ---------------"<<endl;
        cout<<"Opcion 1 -> Punto A) "<<endl;
        cout<<"Opcion 2 -> Punto B) "<<endl;
        cout<<"Opcion 3 -> Punto C) "<<endl;
        cout<<"opcion 0 -> Volver al Menu Principal"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"Seleccione una Opcion: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: puntoA();
                break;
            case 2: puntoB();
                break;
            case 3: puntoC();
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

#endif // MENUREPORTES_H_INCLUDED
