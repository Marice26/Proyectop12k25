#ifndef VENTA_H
#define VENTA_H

// Incluye la definición de la clase Cliente
#include "Cliente.h"

// Incluye la definición de la clase Producto
#include "Producto.h"

// Clase que representa una venta realizada
class Venta {
public:
    Cliente cliente;      // Cliente que realiza la compra
    Producto producto;    // Producto comprado
    int cantidad;         // Cantidad del producto comprada

    // Constructor que inicializa los datos de la venta
    Venta(Cliente c, Producto p, int cant);
};

#endif // VENTA_H
