#ifndef CLSARCHIVOPACIENTE_H_INCLUDED
#define CLSARCHIVOPACIENTE_H_INCLUDED

class ArchivoPaciente{
    private:
        char nombre[30];
    public:
        ArchivoPaciente(const char *n="pacientes.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Paciente obj);
        void modificarRegistro(Paciente obj, int pos);
        Paciente leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarRegistro(int num);
};

void ArchivoPaciente::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoPaciente::grabarRegistro(Paciente obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoPaciente::modificarRegistro(Paciente obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Paciente ArchivoPaciente::leerRegistro(int pos){
    Paciente obj;
    obj.setDNI(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setDNI(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoPaciente::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Paciente);
}

void ArchivoPaciente::listarArchivo(){
    int cant=contarRegistros();
    Paciente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

int ArchivoPaciente::buscarRegistro(int num){
    int cant=contarRegistros();
    Paciente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getDni()){
            return i;
        }
    }
    return -1;
}

#endif // CLSARCHIVOPACIENTE_H_INCLUDED
