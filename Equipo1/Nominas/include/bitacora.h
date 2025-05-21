#ifndef BITACORA_H
#define BITACORA_H

#include <string>

// Clase que maneja el sistema de bit�cora
class bitacora // Registro de bitacora - Xander Reyes
{
private:
    // Variables para almacenar informaci�n de cada registro
    std::string nombre, aplicacion, accion;

public:
    // Muestra el men� principal al usuario
    void menu();

    // Inserta un nuevo registro en la bit�cora
    void insertar(std::string nombre, std::string aplicacion, std::string accion);

    // Muestra todos los registros almacenados
    void desplegar();
};

#endif
