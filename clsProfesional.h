#ifndef CLSPROFESIONAL_H_INCLUDED
#define CLSPROFESIONAL_H_INCLUDED

///PROFESIONAL:
/**
nombre (char)
apellido (char)
matricula (int)
fecha de ingreso (FECHA)
especialidad (int)
direccion (char)
telefono (int)
email (char)
estado (bool)
*/

class Profesional{
    private:
         char nombre[50];
        char apellido[50];
        int matricula;
        Fecha fechaIngreso;
        int especialidad;
        char direccion[100];
        int telefono;
        char email[50];
        bool estado;
    public:
        void Cargar(){
            cout<<"NOMBRE: ";
            cargarCadena(nombre, 50);
            cout<<"APELLIDO: ";
            cargarCadena(apellido, 50);
            cout<<"MATRICULA: ";
            cin>>matricula;
            cout<<"FECHA DE INGRESO: ";
            cout<<endl;
            fechaIngreso.Cargar();
            cout<<"ESPECIALIDAD: ";
            cin>>especialidad;
            cout<<"DIRECCION: ";
            cin>>direccion;
            cout<<"NUMERO DE TELEFONO: ";
            cin>>telefono;
            cout<<"EMAIL: ";
            cin>>email;
            estado=true;
        }
        bool Mostrar(){
            cout<<"NOMBRE: "<<nombre<<endl;
            cout<<"APELLIDO: "<<apellido<<endl;
            cout<<"MATRICULA: "<<matricula<<endl;
            cout<<"FECHA DE INGRESO: ";
            fechaIngreso.Mostrar();
            cout<<"ESPECIALIDAD: "<<especialidad<<endl;
            cout<<"DIRECCION: "<<direccion<<endl;
            cout<<"NUMERO DE TELEFONO: "<<telefono<<endl;
            cout<<"EMAIL: "<<email<<endl;
            return estado;
        }
        int getMatricula(){return matricula;}
        void setMatricula(int m){matricula = m;}
        bool getEstado(){return estado;}
        void setEstado(bool e){estado=e;}

};

#endif // CLSPROFESIONAL_H_INCLUDED
