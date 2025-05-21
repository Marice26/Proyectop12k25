// Encabezado de protecci�n para evitar inclusiones m�ltiples
#ifndef PRODUCTO_H
#define PRODUCTO_H

// Bibliotecas necesarias para el funcionamiento
#include <vector>
#include <string>
#include "bitacora.h"

//JENNIFER ALBA DAYAMI BARRIOS FLORES 9959-24-10016
//COORD EQUIPO 3
//MAYO 2025

// Clase que representa un producto en el sistema
class Producto {
public:
    // Variables miembro (atributos) de la clase
    std::string codigo;    // Almacena el c�digo �nico del producto
    std::string nombre;    // Guarda el nombre del producto
    double precio;         // Contiene el precio del producto
    int stock;             // Lleva el conteo de cu�ntos hay en inventario

    // M�todos para las operaciones b�sicas (CRUD)

    // A�ade un nuevo producto a la lista
    static void agregar(std::vector<Producto>& lista, const std::string& usuarioActual);

    // Muestra todos los productos disponibles
    static void mostrar(const std::vector<Producto>& lista);

    // Cambia los datos de un producto existente
    static void modificar(std::vector<Producto>& lista, const std::string& usuarioActual, const std::string& codigo);

    // Elimina un producto de la lista
    static void eliminar(std::vector<Producto>& lista, const std::string& usuarioActual, const std::string& codigo);

    // M�todos para trabajar con archivos

    // Guarda todos los productos en un archivo
    static void guardarEnArchivo(const std::vector<Producto>& lista);

    // Carga los productos desde un archivo
    static void cargarDesdeArchivo(std::vector<Producto>& lista);

    // M�todos de validaci�n

    // Verifica si un c�digo es v�lido
    static bool esCodigoValido(const std::string& codigo);

    // Crea un c�digo nuevo que no exista
    static std::string generarCodigoUnico(const std::vector<Producto>& lista);

    // Revisa si un c�digo ya est� en uso
    static bool codigoDisponible(const std::vector<Producto>& lista, const std::string& codigo);

    void setStock(int nuevoStock);

    std::string getCodigo() const { return codigo; }
    std::string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }
};

// Fin del encabezado
#endif // PRODUCTO_H
