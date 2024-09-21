#ifndef CLASETIPODEPORTE_H_INCLUDED
#define CLASETIPODEPORTE_H_INCLUDED

class TipoDeporte{
private:
    int IDtipo,nivel;
    char nombre[30];
    bool estado;
public:
    ///Set's
    void setNombre(const char *n){strcpy(nombre,n);}
    void setIDtipo(int e){IDtipo=e;}
    void setNivel(int n){
      if(n>0&&n<9){
        nivel=n;
      }
      else nivel=0;
    }
    void setEstado(bool s){estado=s;}
    ///Get's
    const char *getNombre(){return nombre;}
    int getIDtipo(){return IDtipo;}
    int getNivel(){return nivel;}
    bool getEstado(){return estado;}

  void Cargar(int cantreg){
      IDtipo=++cantreg;
      cout<<"El Nuevo Ingreso del Tipo de Deporte es Autonumerico!"<<endl;
      cout<<"ID del Tipo de Deporte: ";
      cout<<IDtipo<<endl;
      bool entra=true;
      cout<<"Nombre Del Tipo de Deporte: ";
      cargarCadena (nombre,29);
      while (entra){
      cout<<"Nivel de Dificultad (Entre 1 y 8): ";
      cin>>nivel;
      if (nivel>0 && nivel<9){entra=false;}
        else{cout<<"Opcion Incorrecta! Seleccione una Opcion Valida! "<<endl;}
    }
      estado=true;
  }
  void Mostrar(){
if(estado==true){
    cout<<setw(4)<<"ID:";
    cout<<setw(6)<<IDtipo;
    cout<<setw(20)<<nombre;
    cout<<setw(10)<<nivel<<endl;
  }
        if(estado==false){
            cout<<"EL Tipo de Deporte Numero: "<<IDtipo<<" se Encuentra Dado de Baja!"<<endl;
        }
  }
};

#endif // CLASETIPODEPORTE_H_INCLUDED
