#include<iostream>
#include<limits>
#include<fstream>
#include"./Owners.h"
#include<string>
#include<sstream>
#include<./Pets.h>
using namespace std;

void Owners::AddOwner(){
    Owners o;
    string line;
    int newid = 0;
    ifstream OwnersFile("../Data/Owners.csv");

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

    ofstream OwnersFile2("../Data/Owners.csv", ios::app);
    OwnersFile2 << o.id << "," << o.Name << "," << o.LastName << "," << o.Email << "," << o.pet_id << endl;
    OwnersFile2.close();
    cout<<"Cliente agregado con exito"<<endl;
}

int Owners::getid(){
    return id;
}






void Pets::AddPet(){
    ifstream ArchivoMascotas("../Data/Pets.csv");
    Pets p;
    string line;
    int newid;
    while(getline(ArchivoMascotas,line)){
        newid++;
    }
    ArchivoMascotas.close();
    p.id = newid;
    cout<<"Ingrese el tipo de animal: ";
    getline(cin,p.pet_type);
    cout<<"Ingrese la edad de la mascota: ";
    cin>>p.age;
    cout<<"Ingrese el color de la mascota: ";
    getline(cin,p.color);
    cout<<"Ingrese el peso de la mascota: ";
    cin>>p.height;
    cout<<"Ingrese el id del cliente que compro la mascota (si no tiene ingrese 0):";
    cin>>p.id_owner;

    ofstream ArchivoMascotas2("../Data/Pets.csv", ios::app);
    ArchivoMascotas2 << p.id << "," << p.pet_type << ',' << p.age << ',' << p.color << ',' << p.height << ',' <<p.id_owner<<endl;
    ArchivoMascotas2.close();
    cout<<"Mascota agregada con exito"<<endl;
}

void Pets::DeletePet(){
    Pets p;
    Owners o;
    string line, line2;
    cout<<"Ingrese el id de la mascota que desea eliminar: ";
    cin>>p.id;
    ofstream TemporalMascotas("../Data/TempPets.csv",ios::out);
    ifstream ArchivoMascotas("../Data/Pets.csv", ios::in);

    ofstream TemporalOwners("../Data/TempOwners.csv",ios::out);
    ifstream ArchivoOwners("../Data/Owners.csv", ios::in);

    while(getline(ArchivoOwners,line2)){
        int actual_id2 = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id2!= o.getid()){
            TemporalOwners<<line<<endl;
        }
    }

    while(getline(ArchivoMascotas,line)){
        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id!= p.id){
            TemporalMascotas<<line<<endl;
        }
    }

    TemporalMascotas.close();
    ArchivoMascotas.close();

    remove("../Data/Pets.csv");
    rename("../Data/TempPets.csv","../Data/Pets.csv");

    remove("../Data/Owners.csv");
    rename("../Data/TempOwners.csv","../Data/Owners.csv");

    cout<<"Mascota eliminada con exito"<<endl;
}
