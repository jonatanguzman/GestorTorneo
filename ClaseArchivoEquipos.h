#ifndef CLASEARCHIVOEQUIPOS_H_INCLUDED
#define CLASEARCHIVOEQUIPOS_H_INCLUDED

class ArchivoEquipos{
private:
    char nombre[30];
public:
    ArchivoEquipos(const char *n){
        strcpy(nombre, n);
    }
    bool MostrarEquipos();
    int buscarIDequipo(int id);
    int contarRegistros();
    Equipo leerRegistro(int pos);
    bool modificarRegistro(Equipo reg, int pos);
    bool grabarRegistro(Equipo reg);
};

int buscarIDequipo(int id);

bool agregarRegistroEquipo(){
    ArchivoEquipos archi("Equipos.dat");
    Equipo reg;
    int cantReg=archi.contarRegistros();
        reg.Cargar(cantReg);
        cout<<"Registro Agregado!!"<<endl;
        bool escribio=archi.grabarRegistro(reg);
        return escribio;
}

int ArchivoEquipos::contarRegistros(){
        FILE *e;
        e=fopen(nombre,"rb");
        if(e==NULL) return 0;
        fseek(e, 0,2);
        int tam=ftell(e);
        fclose(e);
        return tam/sizeof(Equipo);
}

bool ArchivoEquipos::grabarRegistro(Equipo reg){
    FILE *e;
    e=fopen("Equipos.dat","ab");
    if(e==NULL){
        cout<<"Error De Archivo."<<endl;
        return false;
    }
    bool escribio=fwrite(&reg,sizeof(Equipo),1,e);
    fclose(e);
    return escribio;
}

bool ArchivoEquipos::MostrarEquipos(){
	Equipo reg;
    FILE *pEqu;
    pEqu=fopen(nombre,"rb");
    if(pEqu==NULL){
        cout<<"Error de Archivo."<<endl;
        return false;
    }
    cout<< left;
    cout<<setw(10) <<"Equipo";
    cout<<setw(22) <<"Nombre";
    cout<<setw(10) <<"Nivel"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    while(fread(&reg,sizeof(Equipo),1,pEqu)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(pEqu);
    return true;
}

int ArchivoEquipos::buscarIDequipo(int id){
    Equipo reg;
    FILE *pEqu;
    pEqu=fopen("Equipos.dat","rb");
    if(pEqu==NULL){
        cout<<"Error de Archivo."<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Equipo),1,pEqu)==1){
        if(reg.getIDequipo()==id){
            fclose(pEqu);
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(pEqu);
    return -1;
}

Equipo ArchivoEquipos::leerRegistro(int pos){
    Equipo reg;
    reg.setIDequipo(-1);
    FILE *pEqu;
    pEqu=fopen(nombre,"rb");
    if(pEqu==NULL){
        cout<<"Error De Archivo."<<endl;
        return reg;
    }
    fseek(pEqu,sizeof reg*pos,0);
    int leyo=fread(&reg,sizeof(Equipo),1,pEqu);
    fclose(pEqu);

if(leyo==0) reg.setIDequipo(-1);
    return reg;
}

bool ArchivoEquipos::modificarRegistro(Equipo reg, int pos){
    FILE *pEqu;
    pEqu=fopen(nombre,"rb+");
    if(pEqu==NULL){
        cout<<"Error De Archivo."<<endl;
        return false;
    }
    fseek(pEqu,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Equipo),1,pEqu);
    fclose(pEqu);
    return escribio;
}

bool modificarNombre(){
    ArchivoEquipos archi("Equipos.dat");
    int id;
    char nombre[30],nuevoNombre[30];
    cout<<"Ingrese el ID del Equipo para Buscar el Registro: ";
    cin>>id;
    int pos=archi.buscarIDequipo(id);
    if(pos==-1){
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<"No Existe Registro con ese Numero de ID"<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        return false;
    }
    Equipo reg;
    reg=archi.leerRegistro(pos);
        if(reg.getEstado()==false){
            cout<<endl<<"--------------------------------------"<<endl;
            cout<<"El Registro se Encuentra Dado de Baja!"<<endl;
            cout<<"--------------------------------------"<<endl<<endl;
            return false;
        }
    cout<<"Ingrese el Nombre del Equipo: ";
    cargarCadena (nombre,29);
    cout<<"Cargar Nuevo Nombre de Equipo: "<<endl;
    cargarCadena(nuevoNombre,29);
    reg.setNombre(nuevoNombre);
    bool quePaso=archi.modificarRegistro(reg, pos);
        return quePaso;
}

bool eliminarRegistroEquipo(){
    ArchivoEquipos archi("Equipos.dat");
    int id;
    cout<<"Ingrese el ID del Equipo que Desea Eliminar: ";
    cin>>id;
    int pos=archi.buscarIDequipo(id);
    if(pos==-1){
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<"No Existe Registro con ese Numero de ID"<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        return false;
    }
    Equipo reg;
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

bool altaRegistroEquipo(){
    ArchivoEquipos archi("Equipos.dat");
    int id;
    cout<<"Ingrese el ID que desea Volver a Dar de Alta: ";
    cin>>id;
    int pos=archi.buscarIDequipo(id);
    if(pos==-1){
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<"No Existe Registro con ese Numero de ID "<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        return false;
    }
    Equipo reg;
    reg=archi.leerRegistro(pos);
        if(reg.getEstado()==true){
            cout<<endl<<"-----------------------------------------"<<endl;
            cout<<"El Registro No se Encuentra Dado de Baja!"<<endl;
            cout<<"-----------------------------------------"<<endl<<endl;
            return false;
        }
        reg.setEstado(true);
    bool quePaso=archi.modificarRegistro(reg, pos);
        return quePaso;
}

bool buscarPorIDequipo(){
    int id;
    Equipo reg;
    FILE *pEqu;
    bool existe=false;
    pEqu=fopen("Equipos.dat","rb");
    if(pEqu==NULL){
        cout<<"Error de Archivo."<<endl;
        return false;
    }
    cout<<"Ingrese Numero de ID del Equipo que Desea Buscar: ";
    cin>>id;
    cout<<endl;
    while(fread(&reg,sizeof(Equipo),1,pEqu)==1){
        if(reg.getIDequipo()==id){
        if(reg.getEstado()==true){
        cout<< left;
        cout<<setw(10) <<"Equipo";
        cout<<setw(22) <<"Nombre";
        cout<<setw(10) <<"Nivel"<<endl;
    cout<<"-----------------------------------------------"<<endl;
            reg.Mostrar();
            cout<<endl;
            existe=true;}
        else{    reg.Mostrar();
            cout<<endl;
            existe=true;}
        }
    }
    fclose(pEqu);
    if(existe==false){
        cout<<"------------------------------------------"<<endl;
        cout<<"No Existen Registros con ese Numero de ID."<<endl;
        cout<<"------------------------------------------"<<endl<<endl;
    }
    return true;
}


#endif // CLASEARCHIVOEQUIPOS_H_INCLUDED
