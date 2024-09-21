#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

///Generar un archivo con los equipos que tengan todos sus integrantes del claustro docente.
///Cada registro debe tener el ID y el nombre del equipo, y la cantidad de integrantes del equipo.
class PuntoA{ ///Turno15
private:
    int IDequipo;
    char nombreEquipo[30];
	int cantidadIntegrantes;
    bool estado;
public:
    ///set`s
    void setIDEquipo(int id){
        IDequipo=id;
    }
    void setNombreEquipo(const char *ne){
        strcpy(nombreEquipo,ne);
    }
    void setCantidadIntegrantes (const int c){cantidadIntegrantes=c;}
    void setActivo(bool e){estado=e;}
    ///Get`s
    int getIDEquipo(){return IDequipo;}
    const char* getNombreEquipo(){return nombreEquipo;}
    int getCantidadIntegrantes (){return cantidadIntegrantes;}
    bool getEstado(){return estado;}

    void Mostrar(){
        cout<<"ID del Equipo: ";
        cout<<IDequipo<<endl;
        cout<<"Nombre del Equipo: ";
        cout<<nombreEquipo<<endl;
        cout<<"Cantida de Integrantes: ";
        cout<<cantidadIntegrantes<<endl;
    }
};

class ArchivoPuntoA{
private:
    char nombre[30];
public:
    ArchivoPuntoA(const char *n){
        strcpy(nombre, n);
    }
    PuntoA leerRegistro(int pos){
        PuntoA reg;
        reg.setActivo(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
  int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(PuntoA);
    }
    bool grabarRegistro(PuntoA reg){
        FILE *p;
        p=fopen(nombre, "ab");/// WB si el Archivo no existe lo crea y si existe lo reemplaza por uno nuevo.
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};

bool MostrarRegistros(){///Mostramos los Registros
	PuntoA reg;
    FILE *p;
    p=fopen("PuntoA.dat","rb");///Leemos el Archivo
    if(p==NULL){
        cout<<"Error de Archivo."<<endl;
        return false;
    }
    while(fread(&reg,sizeof(reg),1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}

///Generar un archivo con los equipos que tengan todos sus integrantes del claustro docente.
///Cada registro debe tener el ID y el nombre del equipo, y la cantidad de integrantes del equipo.
void puntoA(){
    ArchivoPuntoA archiPA("PuntoA.dat");///Archivo donde vamos a Escribir el Punto 1
    PuntoA pA;
    ArchivoJugador archiJ("Jugadores.dat");///Archivo donde se Encuentran lo Registros
    Jugador regJ;
    ArchivoEquipos archiE("Equipos.dat");///Archivo donde se Encuentran lo Registros
    Equipo regE;
    int cantReg=archiJ.contarRegistros();///Contamos Cantidad de Registros
    int i;
    int canInt=0;
for(i=0;i<cantReg;i++){
        regJ=archiJ.leerRegistro(i);///Leemos Los Registros del Archivo
        if(regJ.getClaustro()==1){ ///Si cumple Condicion Escribimos el Archivo
            if(regJ.getEstado()==true){
                if (regJ.getNumEquipo()==regE.getIDequipo()){
                pA.setIDEquipo(regE.getIDequipo());
                pA.setNombreEquipo(regE.getNombre());
                canInt++;
                }
                pA.setCantidadIntegrantes(canInt);
                archiPA.grabarRegistro(pA);
                    if(archiPA.grabarRegistro(pA)==false){
                            cout<<"Error de Archivo."<<endl;
                            return;
                    }
            }
            else{cout<<"El Registro se Encuentra Dado de Baja"<<endl;}
                }
                }
MostrarRegistros();
}

///Listar la cantidad de jugadores de cada uno de los claustros inscriptos este año.
void mostrarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }
}

void puntoB(){
    ArchivoJugador archiJ("Jugadores.dat");
    Jugador regJ;
    int cantReg=archiJ.contarRegistros();
	int vClaustro[4]={0};
	int i;
for(i=0;i<cantReg;i++){
        regJ=archiJ.leerRegistro(i);
        if(regJ.getEstado()==true){
        if(regJ.getfechaInscripcion().getAnio()==2023){
			vClaustro[regJ.getClaustro()-1]++;
        }
            }
            else{cout<<"El Registro se Encuentra Dado de Baja"<<endl;}
                }
   	mostrarVector(vClaustro,4);
}


///Resolver el punto 2 utilizando un vector dinámico.
void puntoC (){
   /* ArchivoJugador archiJ("Jugadores.dat");
    Jugador regJ;
    int cantReg=archiJ.contarRegistros();

    Punto2* vec = nullptr;
    vec = new PuntoA[cantReg];
    if(vec == nullptr)return;

    for(i=0;i<cantReg;i++){
        regJ=archiJ.leerRegistro(i);
        if(regJ.getEstado()==true){
        if(regJ.getfechaInscripcion().getAnio()==2023){
			vClaustro[regJ.getClaustro()-1]++;
        }
            }
            else{cout<<"El Registro se Encuentra Dado de Baja"<<endl;}
                }

    for (int i=0 ; i<cantReg ; i++ ){
        vec[i] = archiJ.leerRegistro(i);
    }*/
}

#endif // REPORTES_H_INCLUDED
