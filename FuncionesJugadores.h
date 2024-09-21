#ifndef FUNCIONESJUGADORES_H_INCLUDED
#define FUNCIONESJUGADORES_H_INCLUDED

bool buscarPorNombre(){
    char nombre[30];
    Jugador reg;
    FILE *pjug;
    bool existe=false;
    pjug=fopen("Jugadores.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    cout<<"INGRESAR NOMBRE A BUSCAR ";
    cin>>nombre;
    while(fread(&jug,sizeof(Jugador),1,pjug)==1){
        if(strcmp(reg.getNombre(),nombre)==0){
            reg.Mostrar();
            existe=true;
        }
    }
    fclose(pjug);
    if(existe==false){
        cout<<"NO HAY REGISTROS CON ESE NOMBRE"<<endl;
    }
    return true;
}

#endif // FUNCIONESJUGADORES_H_INCLUDED
