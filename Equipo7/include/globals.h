#ifndef GLOBALS_H
#define GLOBALS_H
#include <string>
#include "globals.h"

class globals
{
    public:
        globals();
        virtual ~globals();
        // Declaración global del usuario actual
        // Definición real de la variable global
        std::string usuarioActual = "INVITADO"; // Puedes cambiar esto luego desde el login
    protected:

    private:
};

#endif // GLOBALS_H
