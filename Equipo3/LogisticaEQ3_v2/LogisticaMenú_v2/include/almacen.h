//9959 24 11603 GE
#ifndef ALMACEN_H
#define ALMACEN_H

#include <string>
#include <vector>

class Almacen {
public:
    // Constructor
    Almacen();

    // M�todos est�ticos p�blicos
    static std::string generarID(const std::vector<Almacen>& lista);
    static bool validarEstado(const std::string& estado);

    // M�todos de instancia
    std::string getId() const { return id; }
    std::string getDireccion() const { return direccion; }
    std::string getEstado() const { return estado; }
    std::string getResponsable() const { return responsable; }
    std::string getContacto() const { return contacto; }
    int getCapacidad() const { return capacidad; }

    // M�todos CRUD est�ticos
    static void agregar(std::vector<Almacen>& lista, const std::string& usuario);
    static void mostrar(const std::vector<Almacen>& lista);
    static void modificar(std::vector<Almacen>& lista, const std::string& usuario, const std::string& id);
    static void eliminar(std::vector<Almacen>& lista, const std::string& usuario, const std::string& id);
    static void guardarEnArchivo(const std::vector<Almacen>& lista);
    static void cargarDesdeArchivo(std::vector<Almacen>& lista);

private:
    std::string id;
    std::string direccion;
    int capacidad;
    std::string responsable;
    std::string contacto;
    std::string estado;
};

#endif // ALMACEN_H
