//9959 24 11603 GE
#include "MenuAlmacenes.h"
#include <iostream>
#include <limits>

// Funci�n que muestra el men� de gesti�n de almacenes
void MenuAlmacenes::mostrar(std::vector<Almacen>& lista, usuarios& usuarioActual) {
    int opcion;          // Variable para almacenar la opci�n ingresada por el usuario
    std::string input;   // Para capturar IDs u otros textos desde el teclado

    do {
        system("cls"); // Limpia la pantalla (solo en sistemas Windows)

        // Muestra el men� principal con el nombre del usuario actual
        std::cout << "=== MEN� ALMACENES ===\n"
                  << "\t\t| Usuario: " << usuarioActual.getNombre() << "\n"
                  << "1. Agregar Almacen\n"
                  << "2. Mostrar Almacenes\n"
                  << "3. Modificar Almacen\n"
                  << "4. Eliminar Almacen\n"
                  << "5. Volver al men� principal\n"
                  << "\t\t=====================\n"
                  << "\t\tSeleccione una opci�n: ";

        // Validaci�n de entrada para asegurarse de que se ingrese un n�mero
        while (!(std::cin >> opcion)) {
            std::cin.clear(); // Limpia el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta entrada inv�lida
            std::cout << "Entrada inv�lida. Ingrese un n�mero: ";
        }

        std::cin.ignore(); // Limpia el salto de l�nea tras ingresar n�mero

        // L�gica del men� seg�n la opci�n seleccionada
        switch (opcion) {
            case 1:
                // Agrega un nuevo almac�n
                Almacen::agregar(lista, usuarioActual.getNombre());
                break;
            case 2:
                // Muestra todos los almacenes registrados
                Almacen::mostrar(lista);
                system("pause"); // Pausa para que el usuario pueda ver los datos
                break;
            case 3: {
                // Solicita y modifica un almac�n existente
                Almacen::mostrar(lista); // Primero muestra los almacenes
                std::cout << "ID a modificar: ";
                std::getline(std::cin, input);
                Almacen::modificar(lista, usuarioActual.getNombre(), input);
                break;
            }
            case 4: {
                // Solicita y elimina un almac�n existente
                Almacen::mostrar(lista); // Primero muestra los almacenes
                std::cout << "ID a eliminar: ";
                std::getline(std::cin, input);
                Almacen::eliminar(lista, usuarioActual.getNombre(), input);
                break;
            }
            case 5:
                // Sale del men� de almacenes y vuelve al men� principal
                return;
            default:
                // Opci�n no v�lida
                std::cout << "Opci�n inv�lida\n";
                system("pause"); // Pausa para mostrar el mensaje
        }
    } while (true); // Bucle infinito hasta que se seleccione la opci�n de salir
}
