#ifndef CLASEEQUIPOS_H_INCLUDED
#define CLASEEQUIPOS_H_INCLUDED

class Equipo{
private:
    int IDequipo,nivel;
    char nombre[30];
    bool estado;
public:
    ///Set's
    void setNombre(const char *n){strcpy(nombre,n);}
    void setIDequipo(int e){IDequipo=e;}
    void setNivel(int n){
      if(n>0&&n<4){
        nivel=n;
      }
      else nivel=0;
    }
    void setEstado(bool s){estado=s;}
    ///Get's
    const char *getNombre(){return nombre;}
    int getIDequipo(){return IDequipo;}
    int getNivel(){return nivel;}
    bool getEstado(){return estado;}

  void Cargar(int cantreg){
      IDequipo=++cantreg;
      cout<<"El Nuevo Ingreso del Equipo es Autonumerico!"<<endl;
      cout<<"ID del Equipo: ";
      cout<<IDequipo<<endl;
      bool entra=true;
      cout<<"Nombre del Equipo: ";
      cargarCadena (nombre,29);
      while (entra){
      cout<<"Nivel (1:Principiante|2:Intermedio|3:Avanzado): ";
      cin>>nivel;
      if (nivel>0 && nivel<4){entra=false;}
        else{cout<<"Opcion Incorrecta! Seleccione una Opcion Valida! "<<endl;}
    }
      estado=true;
  }
  void Mostrar(){
if(estado==true){
    cout<<setw(4)<<"ID:";
    cout<<setw(6)<<IDequipo;
    cout<<setw(20)<<nombre;
        if (nivel==1){cout<<setw(13)<<"1 Principiante "<<endl;}
        if (nivel==2){cout<<setw(13)<<"2 Intermedio "<<endl;}
        if (nivel==3){cout<<setw(13)<<"3 Avanzado "<<endl;}
  }
        if(estado==false){
            cout<<"El ID: "<<IDequipo<<" se Encuentra Dado de Baja!"<<endl;
        }
  }
};

#endif // CLASEEQUIPOS_H_INCLUDED
