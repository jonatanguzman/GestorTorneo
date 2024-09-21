#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

bool FechaValida(int dia, int mes, int anio);

class Fecha
{
private:
    int dia, mes, anio;
public:

    void Cargar();
    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio;
    }
    ///set's
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    ///get's
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
};
void Fecha::Cargar() {
    bool entra;
    entra=true;
    while (entra){
        cout<<"Dia: ";
        cin>>dia;
        if (dia<=31 && dia>=1)
        {
            entra=false;
        }
        else
        {
            cout<<"El Dia Ingresado no es Valido, Por Favor Ingreselo Nuevamente."<<endl;
        }
    }
    entra=true;
    while (entra==true){
        cout<<"Mes: ";
        cin>>mes;
        if (mes>=1 && mes<=12){
            entra=false;
        }else{
            cout<<"El Mes Ingresado no es Valido, Por Favor Ingreselo Nuevamente."<<endl;
        }
    }
    entra=true;
    while (entra){
        cout<<"Anio: ";
        cin>>anio;
        if (anio>=1000){
            entra=false;
        }else{
            cout<<"El Anio Ingresado no es Valido, Por Favor Ingreselo Nuevamente."<<endl;
        }
    }
    if (!FechaValida(dia, mes, anio)) {
        cout << "La Fecha Ingresada No es Valida,Por Favor Ingresela Nuevamente." << endl;
        Cargar();
    }
}
bool FechaValida(int dia, int mes, int anio) {
    time_t now = time(0);
    tm *f = localtime(&now);
    if (anio > f->tm_year + 1900 || (anio == f->tm_year + 1900 && mes > f->tm_mon + 1) || (anio == f->tm_year + 1900 && mes == f->tm_mon + 1 && dia > f->tm_mday)) {
        cout << "La Fecha debe ser anterior o igual a la Fecha actual" << endl;
        cout << "Fecha Actual:" << f->tm_mday << "/" << f->tm_mon + 1 << "/" << f->tm_year + 1900 << endl;
        return false;
    }
    bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);

    if (mes == 2) {
        if (esBisiesto) {
            return dia >= 1 && dia <= 29;
        } else {
            return dia >= 1 && dia <= 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return dia >= 1 && dia <= 30;
    }
    return true;
}


#endif // CLSFECHA_H_INCLUDED
