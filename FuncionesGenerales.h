#ifndef FUNCIONESTORNEO_H_INCLUDED
#define FUNCIONESTORNEO_H_INCLUDED


void cargarCadena ();
bool verificarID();

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}


#endif // FUNCIONESTORNEO_H_INCLUDED
