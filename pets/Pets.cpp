#include<iostream>
#include"./Pets.h"
#include<../Owners/Owners.h>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

void Pets::AddPet(){
    ifstream ArchivoMascotas("../Datos/Pets.csv");
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

    ofstream ArchivoMascotas2("../Datos/Pets.csv", ios::app);
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
    ofstream TemporalMascotas("../Datos/TempPets.csv",ios::out);
    ifstream ArchivoMascotas("../Datos/Pets.csv", ios::in);

    ofstream TemporalOwners("../Datos/TempOwners.csv",ios::out);
    ifstream ArchivoOwners("../Datos/Owners.csv", ios::in);

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

    remove("../Datos/Pets.csv");
    rename("../Datos/TempPets.csv","../Datos/Pets.csv");

    remove("../Datos/Owners.csv");
    rename("../Datos/TempOwners.csv","../Datos/Owners.csv");

    cout<<"Mascota eliminada con exito"<<endl;
}
