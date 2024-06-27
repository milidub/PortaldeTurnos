#ifndef CLSPACIENTE_H_INCLUDED
#define CLSPACIENTE_H_INCLUDED

///PACIENTE:
/**
nombre (char)
apellido (char)
fecha de nacimiento (FECHA)
dni (int)
obra social (int)
direccion (char)
telefono (int)
email (char)
estado (bool)
*/

class Paciente{
    private:
        char nombre[50];
        char apellido[50];
        Fecha fechaNacimiento;
        int dni;
        int obraSocial;
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
            cout<<"FECHA DE NACIMIENTO: ";
            cout<<endl;
            fechaNacimiento.Cargar();
            cout<<"DNI: ";
            cin>>dni;
            cout<<"OBRA SOCIAL: ";
            cin>>obraSocial;
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
            cout<<"FECHA DE NACIMIENTO: ";
            fechaNacimiento.Mostrar();
            cout<<"DNI: "<<dni<<endl;
            cout<<"OBRA SOCIAL: "<<obraSocial<<endl;
            cout<<"DIRECCION: "<<direccion<<endl;
            cout<<"NUMERO DE TELEFONO: "<<telefono<<endl;
            cout<<"EMAIL: "<<email<<endl;
            return estado;
        }
        void setDNI(int d){dni = d;}
        int getDni(){return dni;}
        bool getEstado(){return estado;}
        void setEstado(bool e){estado=e;}

};

#endif // CLSPACIENTE_H_INCLUDED
