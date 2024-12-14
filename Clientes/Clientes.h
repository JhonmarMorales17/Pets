#ifndef CLIENTES_H
#define CLIENTES_H
#include<string>
using namespace std;
class Clientes{
    private:
    int id;
    string Nombre;
    string Apellido;
    string correo;
    int id_mascota;

    public:
    void AgregarCliente();
    void EliminarCliente();
    void ActualizarCliente();
    void ConsultarCliente();
};

#endif