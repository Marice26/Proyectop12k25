// Angoly Araujo Mayo 2025 9959-24-17623

#include "MenuProveedores.h"  // Incluye el encabezado donde se declara la clase MenuProveedores
#include <iostream>           // Librer�a est�ndar para entrada y salida
using namespace std;          // Permite evitar el uso del prefijo std::

/*
 * M�todo est�tico que muestra el men� de gesti�n de proveedores.
 * Permite al usuario actual realizar acciones como agregar, mostrar,
 * modificar y eliminar proveedores.
 */
void MenuProveedores::mostrar(vector<Proveedor>& lista, usuarios& usuarioActual) {
    int opcion; // Variable para almacenar la opci�n del men� elegida por el usuario

    do {
        system("cls"); // Limpia la pantalla (Windows)
        // Muestra el encabezado del men� y el nombre del usuario actual
        cout << "\t\t=== MEN� PROVEEDORES ===\n"
             << "\t\t| Usuario: " << usuarioActual.getNombre() << "\n"
             << "\t\t1. Agregar proveedor\n"
             << "\t\t2. Mostrar proveedores\n"
             << "\t\t3. Modificar proveedor\n"
             << "\t\t4. Eliminar proveedor\n"
             << "\t\t5. Volver\n"
             << "\t\t========================\n"
             << "\t\tIngrese opci�n: ";
        cin >> opcion; // Lee la opci�n seleccionada

        string id; // Variable para capturar el ID del proveedor cuando se requiere
        switch(opcion) {
            case 1:
                // Llama a la funci�n para agregar un nuevo proveedor
                Proveedor::agregar(lista, usuarioActual.getNombre());
                break;
            case 2:
                // Llama a la funci�n para mostrar todos los proveedores
                Proveedor::mostrar(lista);
                break;
            case 3:
                // Solicita el ID del proveedor a modificar
                cout << "\t\tIngrese ID del proveedor a modificar: ";
                cin >> id;
                Proveedor::modificar(lista, usuarioActual.getNombre(), id);
                break;
            case 4:
                // Solicita el ID del proveedor a eliminar
                cout << "\t\tIngrese ID del proveedor a eliminar: ";
                cin >> id;
                Proveedor::eliminar(lista, usuarioActual.getNombre(), id);
                break;
            case 5:
                // Sale del men� de proveedores
                return;
            default:
                // En caso de opci�n inv�lida
                cout << "\t\tOpci�n inv�lida\n";
        }

        // Pausa para que el usuario lea el mensaje antes de continuar
        cout << "\n\t\tPresione Enter para continuar...";
        cin.ignore(); // Limpia el buffer de entrada
        cin.get();    // Espera a que el usuario presione Enter
    } while(opcion != 5); // Se repite hasta que el usuario elija volver
}

