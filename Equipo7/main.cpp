#include <iostream>
#include "SistemaVentas.h"
#include "Login.h"
#include "bitacora.h"
#include <fstream>
#include <string>


using namespace std;


string usuarioActual; // Para guardar el nombre del usuario bitacora
//prototipos de funciones
void mostrarMenuPrincipal(); //muestra el munu principal despues del login
void mostrarArchivo();  // Función para mostrar el archivo bitacora.txt
int main() {
    int opcion;
    bool accesoPermitido = false;// Controla si el usuario inició sesión correctamente

// Bucle para mostrar menú de inicio (login o registro)
    do {

        system ("cls");//limpia pantalla
        cout << "\n--- Bienvenido al Sistema ---\n";
        cout << "1. Iniciar Sesion\n";
        cout << "2. Registrarse\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();// Limpia el buffer de entrada (por getline o strings)


        switch (opcion) {
            case 1:// Llama a iniciarSesion y guarda el usuario actual si es exitoso
                accesoPermitido = iniciarSesion(usuarioActual);
                break;
            case 2:// Llama a la función de registro de usuario
                registrarUsuario();
                break;
            case 3:// Opción para salir del programa
                cout << "\n\nSaliendo del sistema...\n";
                return 0;
            default: // Opción inválida
                cout << "Opcion invalida.\n";
        }
    } while (!accesoPermitido);// Repite hasta que se inicie sesión correctamente
 // Si se inicia sesión correctamente, entra al menú principal
    mostrarMenuPrincipal();
    // Al salir del menú principal, registra el cierre de sesión
     registrarEvento(usuarioActual, "Cerro sesion desde menu principal");
    return 0;
}




void mostrarMenuPrincipal() {
    SistemaVentas sistema;// Instancia de la clase SistemaVentas
    int opcion;
    do {
        system ("cls");
        cout << "\n--- Menu General ---\n";
        cout << "1. Archivo\n";
        cout << "2. Catalogos\n";
        cout << "3. Procesos\n";
        cout << "4. Informes\n";
        cout << "5. Salir del sistema\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:// Bitácora de acceso al menú Archivo (aún sin funcionalidad)
                registrarEvento(usuarioActual, "Entro a la opción Archivo");
                cout<< "sin funcion\n";
                system("pause");
                break;
            case 2:// Bitácora de acceso y llama al menú de catálogos
                registrarEvento(usuarioActual, "Entro a la opción Catálogos");
                sistema.mostrarMenu();
                break;
            case 3: // Bitácora de acceso y llama al proceso de ventas
                registrarEvento(usuarioActual, "Entro a la opción Procesos");
                sistema.realizarVenta();
                break;
            case 4:// Bitácora y muestra el contenido de bitacora.bin
                registrarEvento(usuarioActual, "Entro a la opción Informes");
                mostrarArchivo(); // Mostrar contenido de bitacora.txt
                system ("pause");
                break;
            case 5:// Cierre de sesión registrado
                registrarEvento(usuarioActual, "Salio del menú general");
                cout << "Cerrando sesion...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);
}



void mostrarArchivo() {
    system("cls");
    std::ifstream archivo("bitacora.bin", std::ios::binary); //abre bitacora en binario
    if (!archivo) {
        std::cout << "No se pudo abrir bitacora.bin" << std::endl;
        return;
    }

    std::cout << "=== Contenido de bitacora.bin ===" << std::endl;
    size_t longitud;
    std::string mensaje;
// Lee cada mensaje: primero la longitud, luego el contenido
    while (archivo.read(reinterpret_cast<char*>(&longitud), sizeof(longitud))) {
        mensaje.resize(longitud);
        archivo.read(&mensaje[0], longitud);
        std::cout << mensaje << std::endl;
    }

    archivo.close();
}
