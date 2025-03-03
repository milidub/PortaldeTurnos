#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class FechaActual{
     private:
        int dia, mes, anio;
        int minuto, hora;
    public:
        FechaActual(){
            time_t hoy = time(0);
            tm *time = localtime(&hoy);
            dia = time->tm_mday;
            mes = time->tm_mon+1;
            anio = time->tm_year+1900;

            minuto = time->tm_min;
            hora = time->tm_hour;
        }
        void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
        void MostrarHora(){
            cout<<hora<<":"<<minuto<<endl;
        }
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ~FechaActual(){}
};

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(){
            dia=1;
            mes=1;
            anio=1976;
        }
        void Cargar(){
            FechaActual fa;
            while(true){
                bool bandera = true;
                cout<<"DIA: ";
                cin>>dia;
                if(dia<1 || dia>31){
                    cout<<"ERROR DIA"<<endl;
                    bandera = false;
                }
                cout<<"MES: ";
                cin>>mes;
                if((mes<1 || mes>12)){
                    cout<<"ERROR MES"<<endl;
                    bandera = false;
                }
                cout<<"ANIO: ";
                cin>>anio;
                if(anio<1976 || anio > fa.getAnio()){
                    cout<<"ERROR ANIO"<<endl;
                    bandera = false;
                }

                if(bandera==true){
                    break;
                }
                else{}
            }
        }
        void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
};

#endif // CLSFECHA_H_INCLUDED
