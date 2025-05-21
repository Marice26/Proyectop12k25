//Programado por Priscila Sarai Guzm�n Calgua 9959-23-450
#ifndef NOMINAS_H
#define NOMINAS_H
#include "Bitacora.h"
#include <string>
#include <vector>
#include "Bitacora.h"
#include "Moneda.h"

using namespace std;

struct EmpleadoNomina {
    string nombre;
    string telefono;
    string codigo;
    string direccion;
    double salario; // Siempre en GTQ
};

class Nominas {
private:
    vector<EmpleadoNomina> empleados; // Lista en memoria de empleados
    void cargarEmpleados();           // Carga desde empleados.txt
    void guardarEmpleados();          // Guarda toda la lista en empleados.txt
    void ordenarEmpleados();          // Ordena alfab�ticamente por nombre

public:
    void menuNominas();       // Muestra el men� principal
    void crearEmpleado();     // Agrega un nuevo empleado
    void borrarEmpleado();    // Borra un empleado por nombre y c�digo
    void buscarEmpleado();    // Busca un empleado por nombre y c�digo
    void modificarEmpleado(); // Modifica un empleado existente
    void desplegarEmpleados();// Muestra todos los empleados

    void limpiarPantalla();   // Limpia la consola
    void pausar();            // Pausa hasta que se presione ENTER
};

#endif


