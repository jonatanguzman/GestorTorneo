#ifndef CLASEARCHIVODEPORTES_H_INCLUDED
#define CLASEARCHIVODEPORTES_H_INCLUDED

class ArchivoDeportes{
private:
    char nombre[30];
public:
    ArchivoDeportes(const char *n){
        strcpy(nombre, n);
    }
    bool MostrarDeportes();
    int buscarID(int id);
    int contarRegistros();
    Deporte leerRegistro(int pos);
    bool modificarRegistro(Deporte reg, int pos);
    bool grabarRegistro(Deporte reg);
};

int buscarID(int id);

bool agregarRegistroDeporte(){
    ArchivoDeportes archi("Deportes.dat");
    Deporte reg;
    int cantReg=archi.contarRegistros();
        reg.Cargar(cantReg);
        cout<<"Registro Agregado!!"<<endl;
        bool escribio=archi.grabarRegistro(reg);
        return escribio;
}

    int ArchivoDeportes::contarRegistros(){
        FILE *d;
        d=fopen(nombre,"rb");
        if(d==NULL) return 0;
        fseek(d, 0,2);
        int tam=ftell(d);
        fclose(d);
        return tam/sizeof(Deporte);
    }

bool ArchivoDeportes::grabarRegistro(Deporte reg){
    FILE *d;
    d=fopen("Deportes.dat","ab");
    if(d==NULL){
        cout<<"Error De Archivo."<<endl;
        return false;
    }
    bool escribio=fwrite(&reg,sizeof(Deporte),1,d);
    fclose(d);
    return escribio;
}

bool ArchivoDeportes::MostrarDeportes(){
	Deporte reg;
    FILE *pDep;
    pDep=fopen(nombre,"rb");
    if(pDep==NULL){
        cout<<"Error de Archivo."<<endl;
        return false;
    }
    cout<< left;
    cout<<setw(10) <<"Deporte";
    cout<<setw(12) <<"Nombre";
    cout<<setw(10) <<"Tipo";
    cout<<setw(10) <<"Anio de Origen"<<endl;
    cout<<"----------------------------------------------"<<endl;
    while(fread(&reg,sizeof(Deporte),1,pDep)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(pDep);
    return true;
}

int ArchivoDeportes::buscarID(int id){
    Deporte reg;
    FILE *pDep;
    pDep=fopen("Deportes.dat","rb");
    if(pDep==NULL){
        cout<<"Error de Archivo."<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Deporte),1,pDep)==1){
        if(reg.getID()==id){
            fclose(pDep);
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(pDep);
    return -1;
}

Deporte ArchivoDeportes::leerRegistro(int pos){
    Deporte reg;
    reg.setID(-1);
    FILE *pDep;
    pDep=fopen(nombre,"rb");
    if(pDep==NULL){
        cout<<"Error De Archivo."<<endl;
        return reg;
    }
    fseek(pDep,sizeof reg*pos,0);
    int leyo=fread(&reg,sizeof(Deporte),1,pDep);
    fclose(pDep);

if(leyo==0) reg.setID(-1);
    return reg;
}

bool ArchivoDeportes::modificarRegistro(Deporte reg, int pos){
    FILE *pDep;
    pDep=fopen(nombre,"rb+");
    if(pDep==NULL){
        cout<<"Error De Archivo."<<endl;
        return false;
    }
    fseek(pDep,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Deporte),1,pDep);
    fclose(pDep);
    return escribio;
}

bool modificarAnio(){
    ArchivoDeportes archi("Deportes.dat");
    int id,nuevoAnio;
    cout<<"Ingrese el ID para Buscar el Registro: ";
    cin>>id;
    int pos=archi.buscarID(id);
    if(pos==-1){
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<"No Existe Registro con ese Numero de ID "<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        return false;
    }
    Deporte reg;
    reg=archi.leerRegistro(pos);
        if(reg.getEstado()==false){
            cout<<endl<<"--------------------------------------"<<endl;
            cout<<"El Registro se Encuentra Dado de Baja!"<<endl;
            cout<<"--------------------------------------"<<endl<<endl;
            return false;
        }
    cout<<"Cargar Nueva Anio de Origen: "<<endl;
    cin>>nuevoAnio;
    reg.setAnio(nuevoAnio);
    bool quePaso=archi.modificarRegistro(reg, pos);
        return quePaso;
}

bool eliminarRegistroDeporte(){
    ArchivoDeportes archi("Deportes.dat");
    int id;
    cout<<"Ingrese el ID del Deporte que Desea Eliminar: ";
    cin>>id;
    int pos=archi.buscarID(id);
    if(pos==-1){
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<"No Existe Registro con ese Numero de ID "<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        return false;
    }
    Deporte reg;
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

bool altaRegistroDeporte(){
    ArchivoDeportes archi("Deportes.dat");
    int id;
    cout<<"Ingrese el ID que desea Volver a Dar de Alta: ";
    cin>>id;
    int pos=archi.buscarID(id);
    if(pos==-1){
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<"No Existe Registro con ese numero de ID "<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        return false;
    }
    Deporte reg;
    reg=archi.leerRegistro(pos);
        if(reg.getEstado()==true){
            cout<<endl<<"------------------------------------------"<<endl;
            cout<<"El Registro No se Encuentra Dado de Baja!"<<endl;
            cout<<"------------------------------------------"<<endl<<endl;
            return false;
        }
        reg.setEstado(true);
    bool quePaso=archi.modificarRegistro(reg, pos);
        return quePaso;
}

bool buscarPorID(){
    int id;
    Deporte reg;
    FILE *pDep;
    bool existe=false;
    pDep=fopen("Deportes.dat","rb");
    if(pDep==NULL){
        cout<<"Error de Archivo!"<<endl;
        return false;
    }
    cout<<"Ingrese Numero ID del Deporte que Desea Buscar: "<<endl;
    cin>>id;
    cout<<endl;
    cout<< left;
    cout<<setw(10) <<"Deporte";
    cout<<setw(12) <<"Nombre";
    cout<<setw(10) <<"Tipo";
    cout<<setw(10) <<"Anio de Origen"<<endl;
    cout<<"----------------------------------------------"<<endl;
    while(fread(&reg,sizeof(Deporte),1,pDep)==1){
        if(reg.getID()==id){
            reg.Mostrar();
            cout<<endl;
            existe=true;
        }
    }
    fclose(pDep);
    if(existe==false){
        cout<<"---------------------------------------"<<endl;
        cout<<"No Existe Registro con ese Numero de ID "<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
    }
    return true;
}
#endif // CLASEARCHIVODEPORTES_H_INCLUDED
