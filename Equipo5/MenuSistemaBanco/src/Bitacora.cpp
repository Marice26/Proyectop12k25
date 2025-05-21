//Programado por Priscila Sarai Guzm�n Calgua 9959-23-450
//Boris de Le�n 9959-24-6203
#include "Bitacora.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;
//Registra una acci�n realizada por un usuario en la bitacora
void Bitacora::insertar(const string& usuario, int codigo, const std::string& aplicacion, const std::string& accion) {
    ofstream archivo("bitacora.txt", ios::app);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de bit�cora.\n";
        return;
    }

    time_t now = time(nullptr);//obtenr fecha y hora
    char* fechaHora = ctime(&now);//convierte el tiempo en cadena
    fechaHora[strcspn(fechaHora, "\n")] = '\0';  // eliminar salto de l�nea

    archivo << left << setw(15) << usuario
            << setw(10) << codigo
            << setw(20) << aplicacion
            << setw(30) << accion
            << setw(25) << fechaHora << '\n';

    archivo.close();
}
//Mostarar todos los registros almacenados en bit�cora
void Bitacora::mostrar() {
    ifstream archivo("bitacora.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de bit�cora.\n";
        return;
    }

    string usuario, aplicacion, accion, fechaHora;
    int codigo;

    cout << "\n--- BIT�CORA DE USUARIO ---\n";
    while (archivo >> usuario >> codigo >> aplicacion >> accion) {
        getline(archivo, fechaHora);
        cout << "Usuario: " << usuario << "\n"
             << "C�digo: " << codigo << "\n"
             << "Aplicaci�n: " << aplicacion << "\n"
             << "Acci�n: " << accion << "\n"
             << "Fecha y Hora:" << fechaHora << "\n"
             << "-----------------------------\n";
    }

    archivo.close();
}

void Bitacora::menuBitacora() {
    int opcion;

    do {
        cout << "\n--- MEN� DE BIT�CORA ---\n";
        cout << "1. Desplegar bit�cora\n";
        cout << "2. Regresar al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = 0;
        }

        switch (opcion) {
            case 1:
                mostrar();
                break;
            case 2:
                cout << "Regresando al men� principal...\n";
                break;
            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }

    } while (opcion != 2);
}

