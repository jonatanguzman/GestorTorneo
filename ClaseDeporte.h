#ifndef CLASEDEPORTE_H_INCLUDED
#define CLASEDEPORTE_H_INCLUDED

class Deporte{
private:
    int ID,tipoDeporte,anio;
    char nombre[30];
    bool estado;
public:
    ///Set's
    void setID(int i){ID=i;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTipoDeporte(int d){
      if (d>0&&d<=21){
        tipoDeporte=d;
      }
      else
        tipoDeporte=00;
    }
    void setAnio(int a){
      if(a>1800&&a<2024){
        anio=a;
      }
      else anio=2023;
    }
    void setEstado(bool s){estado=s;}
    ///Get's
    int getID(){return ID;}
    const char *getNombre(){return nombre;}
    int getTipoDeporte(){return tipoDeporte;}
    int getAnio(){return anio;}
    bool getEstado(){return estado;}

  void Cargar(int cantreg){
      ID=++cantreg;
      cout<<"El Nuevo Ingreso de Deporte es Autonumerico!"<<endl;
      cout<<"ID: ";
      cout<<ID<<endl;
      cout<<"Nombre del Deporte: ";
      cargarCadena (nombre,29);
      bool entra=true;
      while (entra){
      cout<<"Tipo de Deporte(entre 1 y 21): ";
      cin>>tipoDeporte;
      if (tipoDeporte>0 && tipoDeporte<22){entra=false;}
        else{cout<<"Numero Incorrecto, Ingrese un Numero Valido! (entre 1 y 21) "<<endl;}
    TipoDeporte reg;
    FILE *pTip;
    bool existe=false;
    pTip=fopen("TipodeDeporte.dat","rb");
    if(pTip==NULL){
        cout<<"Error de Archivo!"<<endl;
        return ;
    }
    while(fread(&reg,sizeof(TipoDeporte),1,pTip)==1){
        if(reg.getIDtipo()==tipoDeporte){
            existe=true;
        if (reg.getEstado()==false){
            cout<<"El Registro se Encuentra Dado de Baja"<<endl;
            cout<<"Ingrese Nuevamente."<<endl;
            entra=true;
        }
        }
    }
    fclose(pTip);
    if(existe==false){
        cout<<"No existen Registros con ese Tipo de Deporte."<<endl;
        cout<<"Ingrese un Numero de Tipo de Deporte Existente."<<endl;
        entra=true;
    }
    }
        entra=true;
      while (entra){
      cout<<"Anio de Origen: ";
      cin>>anio;
      if (anio>1800 && anio<=2023){entra=false;}
        else{cout<<"Anio Incorrecto! Ingreselo Nuevamente "<<endl;}
    }
      estado=true;
  }
  void Mostrar(){
if(estado==true){

    cout<<setw(4)<<"ID:";
    cout<<setw(6)<<ID;
    cout<<setw(12)<<nombre;
    cout<<setw(5)<<"Num:";
    cout<<setw(5)<<tipoDeporte;
    cout<<setw(10)<<anio<<endl;
  }
        if(estado==false){
            cout<<"EL Numero de ID: "<<ID<<" se Encuentra Dado de Baja!"<<endl;
        }
  }
};

#endif // CLASEDEPORTE_H_INCLUDED
