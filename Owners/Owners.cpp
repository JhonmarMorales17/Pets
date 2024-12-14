#include<iostream>
#include<limits>
#include<fstream>
#include"./Owners.h"
using namespace std;
void Owners::AddOwner(){
    Owners o;
    string line;
    int newid = 0;
    ifstream OwnersFile("../Datos/Owners.csv");

    while(getline(OwnersFile,line)){
        newid++;
    }
    OwnersFile.close();

    cout << "Ingrese los siguientes datos:" << endl;
    o.id = newid;
    cout << "Nombre: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, o.Name);
    cout << "Apellido: ";
    getline(cin, o.LastName);
    cout << "Correo: ";
    getline(cin, o.Email);
    cout << "id de la mascota que adopto: ";
    cin>>o.pet_id;

    ofstream OwnersFile2("../Datos/Owners.csv", ios::app);
    OwnersFile2 << o.id << "," << o.Name << "," << o.LastName << "," << o.Email << "," << o.pet_id << endl;
    OwnersFile2.close();
    cout<<"Cliente agregado con exito"<<endl;
}