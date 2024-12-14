#ifndef OWNERS_H
#define OWNERS_H
#include<string>
using namespace std;
class Owners{
    private:
    int id;
    string Name;
    string LastName;
    string Email;
    int pet_id;

    public:
    void AddOwner();
    void DeleteOwner();
    void UpdateOwner();
    void ViewOwner();
    int getidOwners();
};

#endif