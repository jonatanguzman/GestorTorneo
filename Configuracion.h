#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void opcion1 (){
    int opc;
    cout<<"Desea Realizar la Copia de Seguridad del Archivo Jugadores? "<<endl;
    cout<<"Opcion 1 -> SI! "<<endl;
    cout<<"Opcion 2 -> NO! "<<endl;
    cin>>opc;
        switch(opc){
            case 1: system("copy Jugadores.dat Jugadores.bkp");
            cout<<"Copia de Seguridad Realizada!"<<endl;
            return;
                break;
            case 2: return;
                break;
            default: cout<<"Opcion Incorrecta"<<endl;
                break;
        }
}

void opcion2 (){
    int opc;
    cout<<"Desea Realizar la Copia de Seguridad del Archivo Deportes? "<<endl;
    cout<<"Opcion 1 -> SI! "<<endl;
    cout<<"Opcion 2 -> NO! "<<endl;
    cin>>opc;
        switch(opc){
            case 1: system("copy Deportes.dat Deportes.bkp");
            cout<<"Copia de Seguridad Realizada!"<<endl;
            return;
                break;
            case 2: return;
                break;
            default: cout<<"Opcion Incorrecta"<<endl;
                break;
        }
}

void opcion3 (){
    int opc;
    cout<<"Desea Realizar la Copia de Seguridad del Archivo Equipos? "<<endl;
    cout<<"Opcion 1 -> SI! "<<endl;
    cout<<"Opcion 2 -> NO! "<<endl;
    cin>>opc;
        switch(opc){
            case 1: system("copy Equipos.dat Equipos.bkp");
            cout<<"Copia de Seguridad Realizada!"<<endl;
            return;
                break;
            case 2: return;
                break;
            default: cout<<"Opcion Incorrecta"<<endl;
                break;
        }
}

void opcion4 (){
    int opc;
    cout<<"Desea Realizar la Copia de Seguridad del Archivo Tipos de Deporte? "<<endl;
    cout<<"Opcion 1 -> SI! "<<endl;
    cout<<"Opcion 2 -> NO! "<<endl;
    cin>>opc;
        switch(opc){
            case 1: system("copy TipodeDeporte.dat TiposdeDeporte.bkp");
            cout<<"Copia de Seguridad Realizada!"<<endl;
            return;
                break;
            case 2: return;
                break;
            default: cout<<"Opcion Incorrecta"<<endl;
                break;
        }
}

void opcion5 (){
    int opc;
    cout<<"Desea Restaurar el Arhivo Jugadores? "<<endl;
    cout<<"Opcion 1 -> SI! "<<endl;
    cout<<"Opcion 2 -> NO! "<<endl;
    cin>>opc;
        switch(opc){
            case 1: system("copy Jugadores.bkp Jugadores.dat");
            cout<<"Restauracion Realizada!"<<endl;
            return;
                break;
            case 2: return;
                break;
            default: cout<<"Opcion Incorrecta"<<endl;
                break;
        }
}

void opcion6 (){
    int opc;
    cout<<"Desea Restaurar el Arhivo Deportes? "<<endl;
    cout<<"Opcion 1 -> SI! "<<endl;
    cout<<"Opcion 2 -> NO! "<<endl;
    cin>>opc;
        switch(opc){
            case 1: system("copy Deportes.bkr Deportes.dat");
            cout<<"Restauracion Realizada!"<<endl;
            return;
                break;
            case 2: return;
                break;
            default: cout<<"Opcion Incorrecta"<<endl;
                break;
        }
}

void opcion7 (){
    int opc;
    cout<<"Desea Restaurar el Arhivo Equipos? "<<endl;
    cout<<"Opcion 1 -> SI! "<<endl;
    cout<<"Opcion 2 -> NO! "<<endl;
    cin>>opc;
        switch(opc){
            case 1: system("copy Equipos.bkr Equipos.dat");
            cout<<"Restauracion Realizada!"<<endl;
            return;
                break;
            case 2: return;
                break;
            default: cout<<"Opcion Incorrecta"<<endl;
                break;
        }
}

void opcion8 (){
    int opc;
    cout<<"Desea Restaurar el Arhivo Tipos de Deporte? "<<endl;
    cout<<"Opcion 1 -> SI! "<<endl;
    cout<<"Opcion 2 -> NO! "<<endl;
    cin>>opc;
        switch(opc){
            case 1: system("copy TiposdeDeporte.bkr TiposdeDeporte.dat");
            cout<<"Restauracion Realizada!"<<endl;
            return;
                break;
            case 2: return;
                break;
            default: cout<<"Opcion Incorrecta"<<endl;
                break;
        }
}

void opcion9 (){
    int opc;
    cout<<"Desea Restablecer los Datos de Inicio? "<<endl;
    cout<<"Opcion 1 -> SI! "<<endl;
    cout<<"Opcion 2 -> NO! "<<endl;
    cin>>opc;
        switch(opc){
            case 1: system("copy Jugadores.dat.inicio Jugadores.dat");
            system("copy Deportes.dat.inicio Deportes.dat");
            system("copy Equipos.dat.inicio Equipos.dat");
            system("copy TipodeDeporte.dat.inicio TipodeDeporte.dat");
            cout<<"Restauraciones Realizadas con Exito!"<<endl;
            return;
                break;
            case 2: return;
                break;
            default: cout<<"Opcion Incorrecta"<<endl;
                break;
        }
}

#endif // CONFIGURACION_H_INCLUDED
