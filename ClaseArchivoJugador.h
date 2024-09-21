#ifndef CLASEARCHIVOJUGADOR_H_INCLUDED
#define CLASEARCHIVOJUGADOR_H_INCLUDED

class ArchivoJugador{
private:
    char nombre[30];
public:
    ArchivoJugador(const char *n){
        strcpy(nombre, n);
    }
    bool MostrarJugadores();
    int contarRegistros();
    int buscarDNI(int dni);
    Jugador leerRegistro(int pos);
    bool modificarRegistro(Jugador reg, int pos);
    bool grabarRegistro(Jugador reg);
};

    int ArchivoJugador::contarRegistros(){
        FILE *j;
        j=fopen(nombre,"rb");
        if(j==NULL) return 0;
        fseek(j, 0,2);
        int tam=ftell(j);
        fclose(j);
        return tam/sizeof(Deporte);
    }

int buscarDNI(int dni);

bool agregarRegistroJugador(){
    Jugador reg;
    ArchivoJugador archi("Jugadores.dat");
    int dni;
    cout<<"Complete el Siguiente Formulario. "<<endl;
    cout<<"Documento: ";
    cin>>dni;
    int pos=archi.buscarDNI(dni);
    if(pos==-1){
        reg.Cargar(dni);
        bool escribio=archi.grabarRegistro(reg);
        cout<<"Registro agregado!!"<<endl;
        return escribio;
    }
    cout<<endl<<"======================================="<<endl;
    cout<<"El Documento Ya se Encuentra Ingresado! "<<endl;
    cout<<"======================================="<<endl<<endl;
    reg=archi.leerRegistro(pos);
        if(reg.getEstado()==false){
            cout<<"=========================================="<<endl;
            cout<<"Pero su Registro se Encuentra Dado de Baja"<<endl;
            cout<<"=========================================="<<endl<<endl;
        }
    return false;
}

bool ArchivoJugador::grabarRegistro(Jugador reg){
    FILE *p;
    p=fopen("Jugadores.dat","ab");
    if(p==NULL){
        cout<<"Error de Archivo."<<endl;
        return false;
    }
    bool escribio=fwrite(&reg,sizeof(Jugador),1,p);
    fclose(p);
    return escribio;
}

bool ArchivoJugador::MostrarJugadores(){
	Jugador reg;
    FILE *pJug;
    pJug=fopen(nombre,"rb");
    if(pJug==NULL){
        cout<<"Error de Archivo."<<endl;
        return false;
    }
        cout<< left;
        cout<<setw(8) <<"DNI";
        cout<<setw(10)<<"Nombre";
        cout<<setw(10)<<"Apellido";
        cout<<setw(20)<<"Email";
        cout<<setw(10)<<"Telefono";
        cout<<setw(13)<<"Claustro";
        cout<<setw(10)<<"Deporte";
        cout<<setw(10)<<"Equipo";
        cout<<setw(11)<<"Matricula";
        cout<<setw(10)<<"Fecha Inscripcion"<<endl;
        cout<<"------------------------------------------------------------";
        cout<<"------------------------------------------------------------"<<endl<<endl;
    while(fread(&reg,sizeof(Jugador),1,pJug)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(pJug);
    return true;
}

int ArchivoJugador::buscarDNI(int dni){
    Jugador reg;
    FILE *pJug;
    pJug=fopen("Jugadores.dat","rb");
    if(pJug==NULL){
        cout<<"Error De Archivo."<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Jugador),1,pJug)==1){
        if(reg.getDNI()==dni){
            fclose(pJug);
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(pJug);
    return -1;
}

Jugador ArchivoJugador::leerRegistro(int pos){
    Jugador reg;
    reg.setDNI(-1);
    FILE *pJug;
    pJug=fopen(nombre,"rb");
    if(pJug==NULL){
        cout<<"Error De Archivo."<<endl;
        return reg;
    }
    fseek(pJug,sizeof reg*pos,0);
    int leyo=fread(&reg,sizeof(Jugador),1,pJug);
    fclose(pJug);

if(leyo==0) reg.setDNI(-1);
    return reg;
}

bool ArchivoJugador::modificarRegistro(Jugador reg, int pos){
    FILE *pJug;
    pJug=fopen(nombre,"rb+");
    if(pJug==NULL){
        cout<<"Error De Archivo."<<endl;
        return false;
    }
    fseek(pJug,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Jugador),1,pJug);
    fclose(pJug);
    return escribio;
}

bool modificarFecha(){
    ArchivoJugador archi("Jugadores.dat");
    int dni;
    cout<<"Ingrese el DNI para Buscar el Registro: ";
    cin>>dni;
    int pos=archi.buscarDNI(dni);
    if(pos==-1){
        cout<<endl<<"------------------------------"<<endl;
        cout<<"No Existe Registro con ese DNI "<<endl;
        cout<<"------------------------------"<<endl<<endl;
        return false;
    }
    Jugador reg;
    reg=archi.leerRegistro(pos);
        if(reg.getEstado()==false){
            cout<<endl<<"--------------------------------------"<<endl;
            cout<<"El Registro se Encuentra Dado de Baja!"<<endl;
            cout<<"--------------------------------------"<<endl<<endl;
            return false;
        }
    Fecha nuevaFecha;
    cout<<"Cargar Nueva Fecha de Inscripcion: "<<endl;
    nuevaFecha.Cargar();
    reg.setFechaInscripcion(nuevaFecha);
    bool quePaso=archi.modificarRegistro(reg, pos);
        return quePaso;
}

bool eliminarRegistro(){
    ArchivoJugador archi("Jugadores.dat");
    int dni;
    cout<<"Ingrese el DNI que desea Eliminar: ";
    cin>>dni;
    int pos=archi.buscarDNI(dni);
    if(pos==-1){
        cout<<endl<<"-------------------------------"<<endl;
        cout<<"No Existe Registro con ese DNI "<<endl;
        cout<<"-------------------------------"<<endl<<endl;
        return false;
    }
    Jugador reg;
    reg=archi.leerRegistro(pos);
        if(reg.getEstado()==false){
            cout<<endl<<"-----------------------------------------"<<endl;
            cout<<"El Registro Ya Se Encuentra Dado de Baja!"<<endl;
            cout<<"-----------------------------------------"<<endl<<endl;
            return false;
        }
        reg.setEstado(false);
    bool quePaso=archi.modificarRegistro(reg, pos);
        return quePaso;
}

bool darAltaRegistro(){
    ArchivoJugador archi("Jugadores.dat");
    int dni;
    cout<<"Ingrese el DNI que desea Dar de Alta: ";
    cin>>dni;
    int pos=archi.buscarDNI(dni);
    if(pos==-1){
        cout<<endl<<"-------------------------------"<<endl;
        cout<<"No Existe Registro con ese DNI "<<endl;
        cout<<"-------------------------------"<<endl<<endl;
        return false;
    }
    Jugador reg;
    reg=archi.leerRegistro(pos);
        if(reg.getEstado()==true){
            cout<<endl<<"-----------------------------------------"<<endl;
            cout<<"El Registro No Se Encuentra Dado de Baja!"<<endl;
            cout<<"-----------------------------------------"<<endl<<endl;
            return false;
        }
        reg.setEstado(true);
    bool quePaso=archi.modificarRegistro(reg, pos);
        return quePaso;
}

bool buscarPorDNI(){
    int dni;
    Jugador reg;
    FILE *pJug;
    bool existe=false;
    pJug=fopen("Jugadores.dat","rb");
    if(pJug==NULL){
        cout<<"Error de Archivo!"<<endl;
        return false;
    }
    cout<<"Ingrese Numero de DNI que Desea Buscar: "<<endl;
    cin>>dni;
    cout<<endl;
        cout<< left;
        cout<<setw(8) <<"DNI";
        cout<<setw(10)<<"Nombre";
        cout<<setw(10)<<"Apellido";
        cout<<setw(20)<<"Email";
        cout<<setw(10)<<"Telefono";
        cout<<setw(13)<<"Claustro";
        cout<<setw(10)<<"Deporte";
        cout<<setw(10)<<"Equipo";
        cout<<setw(11)<<"Matricula";
        cout<<setw(10)<<"Fecha Inscripcion"<<endl;
        cout<<"------------------------------------------------------------";
        cout<<"------------------------------------------------------------"<<endl<<endl;
    while(fread(&reg,sizeof(Jugador),1,pJug)==1){
        if(reg.getDNI()==dni){
            reg.Mostrar();
            cout<<endl;
            existe=true;
        }
    }
    fclose(pJug);
    if(existe==false){
        cout<<"-------------------------------------------"<<endl;
        cout<<"No Existen Registros con ese Numero de DNI."<<endl;
        cout<<"-------------------------------------------"<<endl<<endl;
    }
    return true;
}

#endif // CLASEARCHIVOJUGADOR_H_INCLUDED
