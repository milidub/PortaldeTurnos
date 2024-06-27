#ifndef CLSLOGIN_H_INCLUDED
#define CLSLOGIN_H_INCLUDED


class Login{
    private:
        char usuario[40];
        char contrasena[40];
    public:
        void Cargar(){
            interfazLogin();

            rlutil::locate(50, 12);
            rlutil::setColor(rlutil::CYAN);

            cout<<"USUARIO: ";

            rlutil::locate(50, 14);

            cout<<"CONTRASENA: ";

            rlutil::setColor(rlutil::WHITE);

            rlutil::locate(59, 12);

            cargarCadena(usuario,40);

            rlutil::locate(62, 14);

            cargarCadena(contrasena,40);
        }
        char *getUsuario(){return usuario;}
        char *getContrasena(){return contrasena;}

        void setUsuario(const char *n){strcpy(usuario, n);}
        void setContrasena(const char *c){strcpy(contrasena, c);}

        bool operator==(Login obj){
            if(strcmp(obj.getUsuario(), usuario)==0){
                if(strcmp(obj.getContrasena(), contrasena)==0){
                    return true;
                }
                return false;
            }
            return false;
        }

};

bool grabarLogin(Login l){
    FILE *p=fopen("Login.dat","ab");
    if(p==NULL)return false;
    fwrite(&l, sizeof l, 1, p);
    fclose(p);
    return true;
}

void Logeo(){
    Login obj;
    Login obj2;

    while(true){
    obj.Cargar();
    FILE *p=fopen("Login.dat","rb");
    if(p==NULL)return;
    system("cls");
    while(fread(&obj2, sizeof obj2, 1, p)){
        if(obj==obj2){
            rlutil::setColor(rlutil::GREEN);
            interfazLogin();
            rlutil::locate(50, 13);
            cout<<"ACCEDIDO CORRECTAMENTE"<<endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            return;
        }
    }
    rlutil::setColor(rlutil::RED);
    interfazLogin();
    rlutil::locate(50, 13);
    cout<<"NO SE PUDO ACCEDER"<<endl;
    rlutil::setColor(rlutil::WHITE);

    system("pause");
    system("cls");
    }
}


#endif // CLSLOGIN_H_INCLUDED
