#include<iostream>
#include"./Vista.h"
#include"../Controlador/Pets.h"
#include"../Controlador/Owners.h"
#include"../Controlador/Controlador.cpp"
using namespace std;
void Vista::Menu(){
    Owners c;
    Pets p;
    int opcion;
    do{
        cout<<"\n1. Agregar Cliente"<<endl;
        cout<<"2. Eliminar Cliente"<<endl;
        cout<<"3. Actualizar Cliente"<<endl;
        cout<<"4. Consultar Cliente"<<endl;
        cout<<"5. Agregar Mascota"<<endl;
        cout<<"6. Eliminar Mascota"<<endl;
        cout<<"7. Actualizar Mascota"<<endl;
        cout<<"8. Consultar Mascota"<<endl;
        cout<<"9. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                c.AddOwner();
                break;
            case 2:
                c.DeleteOwner();
                break;
            case 3:
                c.UpdateOwner();
                break;
            case 4:
                c.ViewOwner();
                break;
            case 5:
                p.AddPet();
                break;
            case 6:
                p.DeletePet();
                break;
            case 7:
                p.UpdatePet();
                break;
            case 8:
                p.ViewPet();
                break;
            case 9:
                cout<<"Gracias por usar el programa"<<endl;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(opcion!=9);
}