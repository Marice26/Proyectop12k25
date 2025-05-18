#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string> // Incluye la clase string para manejar nombres

// Clase que representa un producto del sistema
class Producto {
public:
    std::string nombre; // Nombre del producto
    double precio;      // Precio del producto

    // Constructor que inicializa el nombre y el precio del producto
    Producto(std::string n, double p);
};

#endif // PRODUCTO_H
