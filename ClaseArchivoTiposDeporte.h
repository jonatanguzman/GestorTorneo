#ifndef CLASEARCHIVOTIPOSDEPORTE_H_INCLUDED
#define CLASEARCHIVOTIPOSDEPORTE_H_INCLUDED

class ArchivoTiposDeporte{
private:
    char nombre[30];
public:
    ArchivoTiposDeporte(const char *n){
        strcpy(nombre, n);
    }
    bool MostrarTipos();
    int buscarIDtipo(int id);
    int contarRegistros();
    TipoDeporte leerRegistro(int pos);
    bool modificarRegistro(TipoDeporte reg, int pos);
    bool grabarRegistro(TipoDeporte reg);
};


bool agregarRegistroTipoDeporte(){
    ArchivoTiposDeporte archi("TipodeDeporte.dat");
    TipoDeporte reg;
    int cantReg=archi.contarRegistros();
        reg.Cargar(cantReg);
        cout<<"Registro Agregado!!"<<endl;
        bool escribio=archi.grabarRegistro(reg);
        return escribio;
}

int ArchivoTiposDeporte::contarRegistros(){
        FILE *t;
        t=fopen(nombre,"rb");
        if(t==NULL) return 0;
        fseek(t, 0,2);
        int tam=ftell(t);
        fclose(t);
        return tam/sizeof(TipoDeporte);
}

bool ArchivoTiposDeporte::grabarRegistro(TipoDeporte reg){
    FILE *t;
    t=fopen("TipodeDeporte.dat","ab");
    if(t==NULL){
        cout<<"Error De Archivo."<<endl;
        return false;
    }
    bool escribio=fwrite(&reg,sizeof(TipoDeporte),1,t);
    fclose(t);
    return escribio;
}

bool ArchivoTiposDeporte::MostrarTipos(){
	TipoDeporte reg;
    FILE *pTip;
    pTip=fopen(nombre,"rb");
    if(pTip==NULL){
        cout<<"Error de Archivo."<<endl;
        return false;
    }
    cout<< left;
    cout<<setw(10) <<"Tipo";
    cout<<setw(20) <<"Nombre";
    cout<<setw(10) <<"Nivel"<<endl;
    cout<<"-----------------------------------"<<endl;
    while(fread(&reg,sizeof(TipoDeporte),1,pTip)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(pTip);
    return true;
}

int ArchivoTiposDeporte::buscarIDtipo(int id){
    TipoDeporte reg;
    FILE *pTip;
    pTip=fopen("TipodeDeporte.dat","rb");
    if(pTip==NULL){
        cout<<"Error de Archivo."<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(TipoDeporte),1,pTip)==1){
        if(reg.getIDtipo()==id){
            fclose(pTip);
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(pTip);
    return -1;
}
TipoDeporte ArchivoTiposDeporte::leerRegistro(int pos){
    TipoDeporte reg;
    reg.setIDtipo(-1);
    FILE *pTip;
    pTip=fopen(nombre,"rb");
    if(pTip==NULL){
        cout<<"Error De Archivo."<<endl;
        return reg;
    }
    fseek(pTip,sizeof reg*pos,0);
    int leyo=fread(&reg,sizeof(TipoDeporte),1,pTip);
    fclose(pTip);

if(leyo==0) reg.setIDtipo(-1);
    return reg;
}

bool ArchivoTiposDeporte::modificarRegistro(TipoDeporte reg, int pos){
    FILE *pTip;
    pTip=fopen(nombre,"rb+");
    if(pTip==NULL){
        cout<<"Error De Archivo."<<endl;
        return false;
    }
    fseek(pTip,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(TipoDeporte),1,pTip);
    fclose(pTip);
    return escribio;
}

bool modificarNivel(){
    ArchivoTiposDeporte archi("TipodeDeporte.dat");
    int id,nuevoNivel;
    cout<<"Ingrese el ID del Tipo de Deporte para Buscar el Registro: ";
    cin>>id;
    int pos=archi.buscarIDtipo(id);
    if(pos==-1){
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<"No Existe Registro con ese Numero de ID"<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        return false;
    }
    TipoDeporte reg;
    reg=archi.leerRegistro(pos);
        if(reg.getEstado()==false){
            cout<<endl<<"---------------------------------------"<<endl;
            cout<<"El Registro se Encuentra Dado de Baja!"<<endl;
            cout<<"---------------------------------------"<<endl<<endl;
            return false;
        }
    cout<<"Cargar Nuevo Nivel de Deficultad: ";
    cin>>nuevoNivel;
    reg.setNivel(nuevoNivel);
    bool quePaso=archi.modificarRegistro(reg, pos);
        return quePaso;
}

bool eliminarRegistroTipoDeporte(){
    ArchivoTiposDeporte archi("TipodeDeporte.dat");
    int id;
    cout<<"Ingrese el ID del Tipo de Deporte que Desea Eliminar: ";
    cin>>id;
    int pos=archi.buscarIDtipo(id);
    if(pos==-1){
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<"No Existe Registro con ese Numero de ID"<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        return false;
    }
    TipoDeporte reg;
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

bool altaRegistroTipoDeporte(){
    ArchivoTiposDeporte archi("TipodeDeporte.dat");
    int id;
    cout<<"Ingrese el ID que desea Volver a Dar de Alta: ";
    cin>>id;
    int pos=archi.buscarIDtipo(id);
    if(pos==-1){
        cout<<endl<<"---------------------------------------"<<endl;
        cout<<"No Existe Registro con ese Numero de ID"<<endl;
        cout<<"---------------------------------------"<<endl<<endl;
        return false;
    }
    TipoDeporte reg;
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

bool buscarPorIDtipo(){
    int id;
    TipoDeporte reg;
    FILE *pTip;
    bool existe=false;
    pTip=fopen("TipodeDeporte.dat","rb");
    if(pTip==NULL){
        cout<<"Error de Archivo."<<endl;
        return false;
    }
    cout<<"Ingrese Numero de ID del Tipo de Deporte que Desea Buscar: ";
    cin>>id;
    cout<<endl;
    while(fread(&reg,sizeof(TipoDeporte),1,pTip)==1){
        if(reg.getIDtipo()==id){
       if(reg.getEstado()==true){
        cout<< left;
        cout<<setw(10) <<"Tipo";
        cout<<setw(20) <<"Nombre";
        cout<<setw(10) <<"Nivel"<<endl;
    cout<<"-----------------------------------"<<endl;
            reg.Mostrar();
            cout<<endl;
            existe=true;}
        else{    reg.Mostrar();
            cout<<endl;
            existe=true;}
        }
    }
    fclose(pTip);
    if(existe==false){
        cout<<"------------------------------------------"<<endl;
        cout<<"No Existen Registros con ese Numero de ID."<<endl;
        cout<<"------------------------------------------"<<endl<<endl;
    }
    return true;
}

#endif // CLASEARCHIVOTIPOSDEPORTE_H_INCLUDED
