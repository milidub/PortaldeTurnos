#ifndef CLSARCHIVOPROFESIONAL_H_INCLUDED
#define CLSARCHIVOPROFESIONAL_H_INCLUDED

class ArchivoProfesional{
    private:
        char nombre[30];
    public:
        ArchivoProfesional(const char *n="profesionales.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Profesional obj);
        void modificarRegistro(Profesional obj, int pos);
        Profesional leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarRegistro(int num);
};

void ArchivoProfesional::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoProfesional::grabarRegistro(Profesional obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoProfesional::modificarRegistro(Profesional obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Profesional ArchivoProfesional::leerRegistro(int pos){
    Profesional obj;
    obj.setMatricula(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setMatricula(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoProfesional::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Profesional);
}

void ArchivoProfesional::listarArchivo(){
    int cant=contarRegistros();
    Profesional obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

int ArchivoProfesional::buscarRegistro(int num){
    int cant=contarRegistros();
    Profesional obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getMatricula()){
            return i;
        }
    }
    return -1;
}

#endif // CLSARCHIVOPROFESIONAL_H_INCLUDED
