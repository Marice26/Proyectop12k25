#ifndef USUARIO_H
#define USUARIO_H

#include <string> // Necesario para usar std::string

// Clase que representa un usuario del sistema
class Usuario {
public:
    std::string username; // Nombre de usuario
    std::string password; // Contraseña del usuario

    // Constructor que inicializa el nombre de usuario y la contraseña
    Usuario(std::string u, std::string p);
};

#endif // USUARIO_H
