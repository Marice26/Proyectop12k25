#include "envios.h"       // Inclusi�n del archivo de cabecera de la clase Envios
#include <iostream>       // Para operaciones de entrada y salida
#include "transportistas.h"

using namespace std;

//JENNIFER BARRIOS COORD EQUIPO 3
//9959-24-10016
//MAYO 2025

// Declaraciones externas para acceder a las variables globales
extern usuarios usuarioRegistrado;  // Usuario actualmente autenticado
extern bitacora auditoria;          // Sistema de auditor�a para registrar acciones

// M�todo principal de la clase 'Envios' para gestionar funciones relacionadas a la log�stica de env�os
void Envios::gestionEnvios() {
    int opcion;
    do {
        // Limpia la consola (funciona en sistemas Windows)
        system("cls");

        // Muestra el men� principal de gesti�n de env�os
        cout << "\t\t========================================" << endl;
        cout << "\t\t| GESTION DE ENVIOS - LOGISTICA        |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Generar guia de envio" << endl;
        cout << "\t\t 2. Asignar transportista" << endl;
        cout << "\t\t 3. Rastrear envio" << endl;
        cout << "\t\t 4. Confirmar entrega" << endl;
        cout << "\t\t 5. Volver al menu anterior" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tOpcion a escoger: ";
        cin >> opcion;

        // Ejecuta la acci�n correspondiente a la opci�n elegida
        switch(opcion) {
            case 1: generarGuia(); break;
//            case 2: asignarTransportista(); break;
//            case 3: rastrearEnvio(); break;
  //          case 4: confirmarEntrega(); break;
            case 5: break; // Salir del men�
            default:
                cout << "\n\t\tOpcion invalida!";
                cin.get(); // Espera una tecla para continuar
        }
    } while(opcion != 5); // Repetir hasta que el usuario decida volver
}

// Genera una gu�a de env�o y registra la acci�n en la bit�cora
void Envios::generarGuia() {
    cout << "\n\t\t[Generando guia de envio...]" << endl;
    //auditoria.insertar(usuarioRegistrado.getNombre(), "300", "GUIA"); // C�digo 300 para gu�a
    system("pause");
}

void Envios::crearEnvio(const std::string& idPedido,
                       const std::vector<Transportistas>& transportistas) {
    // Implementaci�n para crear un env�o
    // Por ejemplo:
    std::ofstream archivo("envios.dat", std::ios::app);
    if (archivo.is_open()) {
        archivo << "Pedido: " << idPedido << " - Transportistas asignados: ";
        for (const auto& t : transportistas) {
            archivo << t.id << " ";
        }
        archivo << "\n";
        archivo.close();
    }
}
