#ifndef PETS_H
#define PETS_H
#include<string>
using namespace std;
class Pets{
    private:
    int id;
    string pet_type;
    int age;
    string color;
    float height;
    int id_owner;
    public:
    void AddPet();
    void DeletePet();
    void UpdatePet();
    void ViewPet();
};

#endif