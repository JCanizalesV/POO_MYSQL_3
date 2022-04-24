
#include <mysql.h>
#include <iostream>
#include "Proveedor.h"

using namespace std;

int menu;

int main()
{

    string proveedo, nit, direccion;
    int telefono;

    cout << "                   .: CRUD MENU :.                   " << endl;
    cout << "" << endl;
    cout << "1.------        CREAR NUEVO PROVEEDOR          %%%%%%" << endl;
    cout << "2.------         MOSTRAR PROVEEDORES           %%%%%%" << endl;
    cout << "3.------         ACTUALIZAR PROVEEDOR          %%%%%%" << endl;
    cout << "4.------          ELIMINAR PROVEEDOR           %%%%%%" << endl;
    cout << "" << endl;
    cout << "Ingrese la opcion que desea realizar:       ";
    cin >> menu;


    if (menu == 1)
    {
        system("cls");

        cout << "1.------        CREAR NUEVO PROVEEDOR          %%%%%%" << endl;
        cout << "" << endl;

        cout << "Ingrese Proveedor:     ";
        cin >> proveedo;
        cout << "Ingrese NIT:           ";
        cin >> nit;
        cout << "Ingrese Direccion:     ";
        cin >> direccion;
        cout << "Ingrese Telefono:      ";
        cin >> telefono;
     

        Proveedor c = Proveedor(proveedo, telefono, direccion, nit);
        c.crear();
        
        cout << "" << endl;
        system("pause");
       }

   if (menu == 2)
    {
        system("cls");

        cout << "2.------         MOSTRAR PROVEEDORES           %%%%%%" << endl;
        cout << "" << endl;

        Proveedor c = Proveedor();
        c.mostrar();
    }

    if (menu == 3)
    {
        system("cls");

        cout << "3.------         ACTUALIZAR PROVEEDOR          %%%%%%" << endl;
        cout << "" << endl;

        cout << "Ingrese Proveedor:     ";
        cin >> proveedo;
        cout << "Ingrese NIT:           ";
        cin >> nit;
        cout << "Ingrese Direccion:     ";
        cin >> direccion;
        cout << "Ingrese Telefono:      ";
        cin >> telefono;

        Proveedor c = Proveedor(proveedo, telefono, direccion, nit);
        c.actualizar();
    }

    if (menu == 4)
    {
        system("cls");

        cout << "4.------          ELIMINAR PROVEEDOR           %%%%%%" << endl;
        cout << "" << endl;

        Proveedor c = Proveedor();
        c.borrar();

    }



    cout << "" << endl;
    return 0;
}


