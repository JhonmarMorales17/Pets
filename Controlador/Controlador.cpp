#include<iostream>
#include<limits>
#include<fstream>
#include"./Owners.h"
#include<string>
#include<sstream>
#include"./Pets.h"
using namespace std;
void Owners::AddOwner(){
    Owners o;
    string line;
    int newid = 0;
    ifstream OwnersFile("./Data/Owners.csv");
    if(!OwnersFile.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
    }
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

    ofstream OwnersFile2("./Data/Owners.csv", ios::app);
    OwnersFile2 << o.id << "," << o.Name << "," << o.LastName << "," << o.Email << "," << o.pet_id << endl;
    OwnersFile2.close();
    cout<<"Cliente agregado con exito"<<endl;
}

void Owners::DeleteOwner(){
    Owners o;
    Pets p;
    string line, line2;
    cout<<"Ingrese el id del cliente que desea eliminar: ";
    cin>>o.id;
    ofstream TemporalOwners("./Data/TempOwners.csv",ios::out);
    ifstream ArchivoOwners("./Data/Owners.csv", ios::in);
      
    while(getline(ArchivoOwners,line)){
        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id!= o.id){
            TemporalOwners<<line<<endl;
        }
    }

    TemporalOwners.close();
    ArchivoOwners.close();

    remove("./Data/Owners.csv");
    rename("./Data/TempOwners.csv","./Data/Owners.csv");
    cout<<"Cliente eliminado con exito"<<endl;
}

void Owners::UpdateOwner(){
    Owners o;
    string line;
    cout<<"Ingrese el id del dueno que quiere actualizar:"<<endl;
    cin>>o.id;
    ifstream OwnersFile("./Data/Owners.csv", ios::in);
    ofstream OwnersTemp("./Data/TempOwners.csv",ios::out);
    while(getline(OwnersFile,line)){
        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id!=o.id){
            OwnersTemp<<line<<endl;
        }
        else{
            cout << "Nombre: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, o.Name);
            cout << "Apellido: ";
            cin>>o.LastName;
            cout << "Correo: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, o.Email);
            cout << "Id de la mascota que adopto: ";
            cin>>o.pet_id;
            OwnersTemp << o.id << "," << o.Name << "," << o.LastName << "," << o.Email << "," << o.pet_id<<endl;
            OwnersTemp.close();
            OwnersFile.close();

            remove("./Data/Owners.csv");
            rename("./Data/TempOwners.csv","./Data/Owners.csv");
            cout<<"Persona actualizada de forma exitosa"<<endl;
        }
    }
}

void Owners::ViewOwner(){
    Owners o;
    cout<<"Ingrese el id de la persona que desea consultar: ";
    cin>>o.id;
    string line;
    ifstream OwnersFile("./Data/Owners.csv", ios::in);
    while(getline(OwnersFile,line)){
        size_t pos = 0;
        size_t next_pos = line.find(',');

        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id==o.id){
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            o.Name = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            o.LastName = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            o.Email = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            o.pet_id = stoi(line.substr(pos));

            cout << "\nID: " << o.id << endl;
            cout << "Nombre: " << o.Name << endl;
            cout << "Apellido: " << o.LastName << endl;
            cout << "Correo: " << o.Email << endl;
            cout << "Id de la macota que adopto: " << o.pet_id << endl;
        }
    }
    OwnersFile.close();
}

int Owners::getidOwners(){
    return id;
}

void Pets::AddPet(){
    ifstream ArchivoMascotas("./Data/Pets.csv");
    if(!ArchivoMascotas.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    Pets p;
    string line;
    int newid;
    while(getline(ArchivoMascotas,line)){
        newid++;
    }
    ArchivoMascotas.close();
    p.id = newid;
    cout<<"Ingrese el tipo de animal: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,p.pet_type);
    cout<<"Ingrese la edad de la mascota: ";
    cin>>p.age;
    cout<<"Ingrese el color de la mascota: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,p.color);
    cout<<"Ingrese el peso de la mascota: ";
    cin>>p.height;
    cout<<"Ingrese el id del cliente que compro la mascota (si no tiene ingrese 0):";
    cin>>p.id_owner;

    ofstream ArchivoMascotas2("./Data/Pets.csv", ios::app);
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
    ofstream TemporalMascotas("./Data/TempPets.csv",ios::out);
    ifstream ArchivoMascotas("./Data/Pets.csv", ios::in);

    while(getline(ArchivoMascotas,line)){
        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id!= p.id){
            TemporalMascotas<<line<<endl;
        }
    }

    TemporalMascotas.close();
    ArchivoMascotas.close();

    remove("./Data/Pets.csv");
    rename("./Data/TempPets.csv","./Data/Pets.csv");

    cout<<"Mascota eliminada con exito"<<endl;
}

void Pets::UpdatePet(){
    Pets p;
    string line;
    cout<<"Ingrese el id de la mascota que quiere actualizar:"<<endl;
    cin>>p.id;
    ifstream PetsFile("./Data/Pets.csv", ios::in);
    ofstream PetsTemp("./Data/TempPets.csv",ios::out);
    while(getline(PetsFile,line)){
        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id!=p.id){
            PetsTemp<<line<<endl;
        }
        else{
            cout << "Tipo de mascota: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, p.pet_type);
            cout << "Edad de la mascota: ";
            cin>>p.age;
            cout << "Color de la mascota: ";
            getline(cin, p.color);
            cout << "Peso: ";
            cin>>p.height;
            cout << "id del cliente que compro la mascota: ";
            cin>>p.id_owner;
            PetsTemp << p.id << "," << p.pet_type << "," << p.age << "," << p.color << "," << p.height << "," << p.id_owner <<endl;
            PetsTemp.close();
            PetsFile.close();

            remove("./Data/Pets.csv");
            rename("./Data/TempPets.csv","./Data/Pets.csv");
            cout<<"Mascota actualizada de forma exitosa"<<endl;
        }
    }
}

void Pets::ViewPet(){
    Pets p;
    cout<<"Ingrese el id de la mascota que desea consultar: ";
    cin>>p.id;
    string line;
    ifstream PetsFile("./Data/Pets.csv", ios::in);
    while(getline(PetsFile,line)){
        size_t pos = 0;
        size_t next_pos = line.find(',');

        int actual_id = atoi(line.substr(0,line.find(',')).c_str());
        if(actual_id==p.id){
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            p.pet_type = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            p.age = stoi(line.substr(pos, next_pos - pos));
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            p.color = line.substr(pos, next_pos - pos);
            pos = next_pos + 1;

            next_pos = line.find(',', pos);
            p.height = stoi(line.substr(pos, next_pos - pos));
            pos = next_pos + 1;

            p.id_owner = stoi(line.substr(pos));

            cout << "\nID: " << p.id << endl;
            cout << "Tipo de mascota: " << p.pet_type << endl;
            cout << "Edad de la mascota: " << p.age << endl;
            cout << "Color: " << p.color << endl;
            cout << "Peso: " << p.height << endl;
            cout << "Id dueno: " << p.id_owner << endl;
        }
    }
    PetsFile.close();
}

int Pets::getidPets(){
    return id;
}