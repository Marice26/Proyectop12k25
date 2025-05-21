// Inclusi�n de encabezados propios
#include "MenuClientes.h"
#include "Clientes.h"

// Inclusi�n de librer�as est�ndar
#include <iostream>
#include <vector>
#include <string>
#include <limits> // Para manejar entradas inv�lidas y limpiar el buffer de entrada

using namespace std;

// Definici�n de rangos v�lidos para los ID de clientes
const int CODIGO_INICIAL = 3107;
const int CODIGO_FINAL = 3157;

/**
 * Muestra el men� de gesti�n de clientes.
 * Permite agregar, mostrar, modificar o eliminar clientes.
 * @param listaClientes Vector que contiene la lista de todos los clientes registrados.
 * @param usuarioActual Objeto que representa al usuario que est� utilizando el sistema.
 */
void MenuClientes::mostrar(vector<Clientes>& listaClientes, usuarios& usuarioActual) {
    int opcion;
    string input;

    do {
        // Limpiar pantalla y mostrar encabezado del men�
        system("cls");
        cout << "\t\t=== MEN� CLIENTES ===\n"
             << "\t\t| Usuario: " << usuarioActual.getNombre() << "\n"
             << "\t\t1. Agregar cliente\n"
             << "\t\t2. Mostrar clientes\n"
             << "\t\t3. Modificar cliente\n"
             << "\t\t4. Eliminar cliente\n"
             << "\t\t5. Volver al men� principal\n"
             << "\t\t=====================\n"
             << "\t\tSeleccione una opci�n: ";

        // Validaci�n de entrada: solo se aceptan n�meros
        while (!(cin >> opcion)) {
            cin.clear(); // Limpiar estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada inv�lida
            cout << "\t\tEntrada inv�lida. Por favor ingrese un n�mero: ";
        }
        cin.ignore(); // Limpiar el buffer restante

        // Ejecutar la opci�n seleccionada por el usuario
        switch(opcion) {
            case 1:
                // Llamar a la funci�n est�tica para agregar un cliente
                Clientes::agregar(listaClientes, usuarioActual.getNombre());
                break;

            case 2:
                // Mostrar la lista de clientes
                Clientes::mostrar(listaClientes);
                break;

            case 3: {
                // Mostrar la lista antes de modificar
                Clientes::mostrar(listaClientes);
                if (!listaClientes.empty()) {
                    cout << "\n\t\tIngrese ID del cliente a modificar: ";
                    getline(cin, input);

                    // Verificar si el ID ingresado es v�lido antes de modificar
                    if (Clientes::esIdValido(input)) {
                        Clientes::modificar(listaClientes, usuarioActual.getNombre(), input);
                    } else {
                        cout << "\t\tID no v�lido. Debe estar entre " << CODIGO_INICIAL
                             << " y " << CODIGO_FINAL << "\n";
                        system("pause");
                    }
                }
                break;
            }

            case 4: {
                // Mostrar la lista antes de eliminar
                Clientes::mostrar(listaClientes);
                if (!listaClientes.empty()) {
                    cout << "\n\t\tIngrese ID del cliente a eliminar: ";
                    getline(cin, input);

                    // Verificar si el ID ingresado es v�lido antes de eliminar
                    if (Clientes::esIdValido(input)) {
                        Clientes::eliminar(listaClientes, usuarioActual.getNombre(), input);
                    } else {
                        cout << "\t\tID no v�lido. Debe estar entre " << CODIGO_INICIAL
                             << " y " << CODIGO_FINAL << "\n";
                        system("pause");
                    }
                }
                break;
            }

            case 5:
                // Guardar datos en archivo antes de volver al men� principal
                Clientes::guardarEnArchivo(listaClientes);
                return; // Salir del men� de clientes

            default:
                // Opci�n inv�lida
                cout << "\t\tOpci�n no v�lida. Intente nuevamente.\n";
                system("pause");
        }
    } while (true); // Bucle infinito hasta que el usuario elija salir
}
