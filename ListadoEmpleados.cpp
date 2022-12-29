/*  4. Hacer un programa en c++. Para guardar numeros telefonicos y que muestre un menu con las siguientes opciones:

    1. Crear ( nombre , apellido , numero )
    2. Agregar mas contactos ( nombre , apellido , numero , )
    3. Visualizar contactos existentes
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;
fstream datosA("datos.txt");
string arreglo[2];
void menu();

struct DatosEmpleado{
    string nombre;
    string apellido;
    string edad;
    string correo;
    string telefono;
    string salario;
    string puesto;
    string estudios;
}datos;

bool login(){
    bool confirmacion=false;
    string linea,dato,usuario,pass; 
    size_t pos=0;
    int contador=0,fin=0; 
    system("clear");
    cout << "User: "; cin >> usuario;
    cout << "Password: "; cin >> pass;
    while(getline(datosA,linea)&&fin==0){
        while ((pos=linea.find(",")) !=string::npos){
            dato=linea.substr(0, pos); 
            arreglo[contador]=dato; 
            linea.erase(0,pos+1); 
            contador++; 
        }
            if (arreglo[0].find(usuario,0)!=string::npos){
                fin=1; 
            }
        contador=0;     
    }
        if (usuario==arreglo[0] and (pass==arreglo[1])){
            system("clear");
            cout<<"Bienvenido "<<"Yose"<<".";
            confirmacion = true;
        }
        else{
            system("clear");
            cout<<"Los datos ingresados no se encuentran en sistema.\n";
            cout<<"Uso de mayusculas o minusculas podria estar incorrecto.\n";
        }
    return confirmacion;
}

void logout(){
    cout<<"Adios "<<"Yose"<<endl;
}
void crear(){
    ofstream archivo;
    archivo.open("Empleados.dat",ios::out | ios::binary);
     archivo<<"\t    EMPLEADOS\n\n";
    if(archivo.fail()){
        cout<<"No se pudo crear el archivo."<<endl;
        exit(1);
    }
}

void agregar(){
    string respuesta;
    ofstream archivo;
    ifstream verificador;
    verificador.open("Empleados.dat",ios::in | ios::binary);
    archivo.open("Empleados.dat",ios::app | ios::binary);
    if(archivo.fail() or verificador.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    do{
        system("clear");
        fflush(stdin);
        cout<<"\nNombre: "; getline(cin,datos.nombre);
        cout<<"Apellido: "; getline(cin,datos.apellido);
        cout<<"Correo: "; getline(cin,datos.correo);
        cout<<"Telefono: "; getline(cin,datos.telefono);
        cout<<"Edad: "; getline(cin,datos.edad);
        cout<<"Nivel de estudios: "; getline(cin,datos.estudios);
        cout<<"Puesto: "; getline(cin,datos.puesto);
        cout<<"Salario: "; getline(cin,datos.salario);

        if(true){
            archivo<<"Nombre: "<<datos.nombre<<endl;
            archivo<<"Apellido: "<<datos.apellido<<endl;
            archivo<<"Edad: "<<datos.edad<<endl;
            archivo<<"Correo: "<<datos.correo<<endl;
            archivo<<"Telefono: "<<datos.telefono<<endl;
            archivo<<"Nivel de estudios: "<<datos.estudios<<endl;
            archivo<<"Puesto: "<<datos.puesto<<endl;
            archivo<<"Salario: "<<datos.salario<<endl<<endl;
        }
        else{
            cout<<"Contacto ya existente...\n";
        }
        cout<<"Desea agregar otro contacto? (y/n): "; cin>>respuesta;
        
    }while(respuesta=="y" or respuesta=="Y");
    archivo.close();
}

void mostrar(){
    ifstream archivo;
    string texto;
    archivo.open("Empleados.dat",ios::in | ios::binary);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    while(!archivo.eof()){
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
}

void app(){
    int opcion;
    do{
        cout<<"\t...INICIO...\n";
        cout<<"1. Iniciar sesion\n2. Apagar\nOpcion:";
        cin>>opcion;
        switch(opcion){
            case 1:
                system("clear");
                if(login()){
                    menu();
                }
                break;
            case 2:
                system("clear");
                break;
            default: cout<<"Opcion invalida...";
        }
    }while(opcion!=2);
}

void menu(){
    int opcion;
    do{
        cout<<"\n\t--MENU--\n";
        cout<<"1. Agregar\n2. Mostrar\n3. Salir\nOpcion: "; 
        cin>>opcion;
        switch(opcion){
            /*case 1: 
                system("clear");
                    crear();
                system("clear");
                cout<<"La agenda se creo correctamente...";
            break;*/
            case 1:
                system("clear");
                agregar();
                system("clear");
                cout<<"Se ha agregado el contacto correctamente...";
            break;
            case 2:
                system("clear");
                mostrar();
            break;
            case 3: 
                system("clear");
            break;
            default: cout<<"Opcion inexistente...";
        }
    }while(opcion!=3);
}

int main(){
    app();
    return 0;
}
