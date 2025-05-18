#ifndef CLIENTE_H
#define CLIENTE_H

#include <string> // Se incluye para usar la clase std::string

// Clase que representa un cliente del sistema
class Cliente {
public:
    std::string nombre; // Nombre del cliente
    std::string email;  // Correo electrónico del cliente

    // Constructor que inicializa el nombre y el email del cliente
    Cliente(std::string n, std::string e);
};

#endif // CLIENTE_H
