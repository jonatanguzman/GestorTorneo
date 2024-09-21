#ifndef CLASEJUGADOR_H_INCLUDED
#define CLASEJUGADOR_H_INCLUDED

class Jugador{
private:
    int DNI,claustro,IDdeporte,numEquipo;
    char nombre[30],apellido[30],email[30],telefono[20];
    Fecha fechaInscripcion;
    float matricula;
    bool estado;
public:
    Jugador(const char *n="NOMBRE"){
        strcpy(nombre, n);
        estado=true;
        }

    int getDNI(){return DNI;}
    Fecha getfechaInscripcion();

    Jugador(Fecha aux){
        fechaInscripcion=aux;
        estado=true;
    }

    Jugador(int d, int m, int a){
        fechaInscripcion.setDia(d);
        fechaInscripcion.setMes(m);
        fechaInscripcion.setAnio(a);
        estado=true;
    }
    ///Set's
    void setDNI(const int d){DNI=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setClaustro(const int c){if(c>0&&c<5)claustro=c;}
    void setIDdeporte(const int d){if(d>0&&d<11) IDdeporte=d;}
    void setNumEquipo(const int n){numEquipo=n;}
    void setFechaInscripcion(Fecha f){fechaInscripcion=f;}
    void setMatricula(const int m){matricula=m;}
    void setEstado(bool e){estado=e;}
    ///Get`s
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}
    int getClaustro(){return claustro;}
    int getIDDeporte (){return IDdeporte;}
    int getNumEquipo (){return numEquipo;}
    int getMatricula (){return matricula;}
    bool getEstado(){return estado;}


void Cargar(int d=-1){
    if(d==-1){
        cout<<"Documento: ";
        cin>>DNI;
    }
    else{
        DNI=d;
    }
    bool entra=true;
    cout<<"Nombre: ";
    cargarCadena(nombre, 29);
    cout<<"Apellido: ";
    cargarCadena(apellido,29);
    cout<<"Email: ";
    cargarCadena(email,29);
    cout<<"Telefono: ";
    cargarCadena(telefono,29);
    while (entra){
    cout<<"Claustro(1:Docente|2:Alumno|3:No Docente|4:Graduado): ";
    cin>>claustro;
    if (claustro>0 && claustro<5){entra=false;}
        else{cout<<"Opcion Incorrecta, Seleccione una Opcion Valida! "<<endl;}
    }
    entra=true;
 while (entra){
    cout<<"ID de Deporte(Del 1 al 10): ";
    cin>>IDdeporte;
    if (IDdeporte>0 && IDdeporte<11){entra=false;}
      else{cout<<"Opcion Incorrecta! Seleccione una Opcion Valida! "<<endl;}
    Deporte reg;
    FILE *pDep;
    bool existe=false;
    pDep=fopen("Deportes.dat","rb");
    if(pDep==NULL){
        cout<<"Error de Archivo!"<<endl;
        return ;
    }
    while(fread(&reg,sizeof(Deporte),1,pDep)==1){
        if(reg.getID()==IDdeporte){
            existe=true;
        if (reg.getEstado()==false){
            cout<<"El Registro se Encuentra Dado de Baja"<<endl;
            cout<<"Ingrese Nuevamente."<<endl;
            entra=true;
        }
        }
    }
    fclose(pDep);
    if(existe==false){
        cout<<"No existen Registros con ese Numero de ID."<<endl;
    }
    }
    entra=true;
 while (entra){
    cout<<"Numero de Equipo: ";
    cin>>numEquipo;
    Equipo reg;
    FILE *pEqu;
    bool existe=false;
    pEqu=fopen("Equipos.dat","rb");
    if(pEqu==NULL){
        cout<<"Error de Archivo!"<<endl;
        return ;
    }
    while(fread(&reg,sizeof(Equipo),1,pEqu)==1){
        if(reg.getIDequipo()==numEquipo){
            existe=true;
            entra=false;
        }
    }
    fclose(pEqu);
    if(existe==false){
        cout<<"No existen Registros con ese Numero de Equipo."<<endl;
        cout<<"Ingrese un Numero de Equipo Existente."<<endl;
        entra=true;
    }
    }
    cout<<"Fecha de Inscripcion: "<<endl;
    fechaInscripcion.Cargar();
    entra=true;
    while (entra){
    cout<<"Matricula: $";
    cin>>matricula;
    estado=true;
        if (matricula>=0){entra=false;}
        else{cout<<"Opcion Incorrecta! Seleccione una Opcion Valida! "<<endl;}
    }
}

    void Mostrar(){
    if(estado==true){
        cout<<left;
        cout<<setw(8) <<DNI;
        cout<<setw(10)<<nombre;
        cout<<setw(10)<<apellido;
        cout<<setw(20)<<email;
        cout<<setw(10)<<telefono;
        if (claustro==1){cout<<setw(13)<<"1 Docente";}
        if (claustro==2){cout<<setw(13)<<"2 Alumno";}
        if (claustro==3){cout<<setw(13)<<"3 No Docente";}
        if (claustro==4){cout<<setw(13)<<"4 Graduado";}
        cout<<setw(4)<<"ID:";
        cout<<setw(6)<<IDdeporte;
        cout<<setw(5)<<"Num:";
        cout<<setw(5)<<numEquipo;
        cout<<setw(8)<<matricula;
        cout<<setw(3)<<"$";
        fechaInscripcion.Mostrar();
        cout<<endl;
    }
        if(estado==false){

            cout<<"* El Registro con Numero de DNI: "<<DNI<<" se Encuentra Dado de Baja! *"<<endl;
        }
}

};

Fecha Jugador::getfechaInscripcion(){
        return fechaInscripcion;
    }

#endif // CLASEJUGADORES_H_INCLUDED
