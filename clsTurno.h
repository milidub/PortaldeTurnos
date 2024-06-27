#ifndef CLSTURNO_H_INCLUDED
#define CLSTURNO_H_INCLUDED

///TURNO:
/**
matriculaProfesional [Recibe el parametro de la matricula Profesional]
dniPaciente [recibe el parametro del dni Paciente]
observaciones (char)
fecha (FECHA)
hora (int)
minuto (int)
estado (bool)
*/

class Turno{
    private:
        int matriculaProfesional;
        int dniPaciente;
        char observaciones[400];
        Fecha fecha;
        int hora, minuto;
        bool estado;
    public:
        bool Mostrar(){
            cout<<"DNI DEL PACIENTE: "<<dniPaciente<<endl;
            cout<<"MATRICULA PROFESIONAL: "<<matriculaProfesional<<endl;
            cout<<"OBSERVACIONES: "<<observaciones<<endl;
            cout<<"FECHA: ";
            fecha.Mostrar();
            cout<<"HORA Y MINUTO: "<<hora<<" : "<<minuto<<endl;
            return estado;
        }
        void setDniPaciente(int dni){dniPaciente = dni;}
        void setMatriculaProfesional(int matricula){matriculaProfesional = matricula;}
        void setObservaciones(const char *o){strcpy(observaciones, o);}
        void setFecha(Fecha f){fecha = f;}
        void setHora(int h){hora = h;}
        void setMinuto(int m){minuto = m;}
        void setEstado(bool e){estado = e;}

        bool getEstado(){return estado;}
        int getDniPaciente(){return dniPaciente;}
};

#endif // CLSTURNO_H_INCLUDED
