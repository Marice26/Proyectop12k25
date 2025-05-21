#include "clientes.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bitacora.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <limits> // Para numeric_limits

using namespace std;

// Rango de c�digos para clientes
const int CODIGO_INICIAL = 3107;
const int CODIGO_FINAL = 3157;

/**
 * Genera un ID �nico dentro del rango permitido (3107�3157) para un nuevo cliente.
 * @param lista Lista actual de clientes.
 * @return ID disponible como string, o cadena vac�a si el rango est� lleno.
 */
std::string Clientes::generarIdUnico(const std::vector<Clientes>& lista) {
    for (int i = CODIGO_INICIAL; i <= CODIGO_FINAL; ++i) {
        std::string id = std::to_string(i);
        if (idDisponible(lista, id)) {
            return id;
        }
    }
    return ""; // Retorna cadena vac�a si no hay c�digos disponibles
}

/**
 * Verifica si un ID est� disponible (no repetido) en la lista de clientes.
 * @param lista Lista de clientes.
 * @param id ID a verificar.
 * @return true si el ID no est� en uso, false si ya est� ocupado.
 */
bool Clientes::idDisponible(const std::vector<Clientes>& lista, const std::string& id) {
    return std::none_of(lista.begin(), lista.end(),
        [&id](const Clientes& c) { return c.id == id; });
}

/**
 * Valida si un ID es un n�mero dentro del rango permitido.
 * @param id ID a validar.
 * @return true si es v�lido, false si no.
 */
bool Clientes::esIdValido(const std::string& id) {
    try {
        int num = std::stoi(id);
        return (num >= CODIGO_INICIAL && num <= CODIGO_FINAL);
    } catch (...) {
        return false;
    }
}

/**
 * Agrega un nuevo cliente a la lista, solicitando los datos desde la entrada est�ndar.
 * Asigna autom�ticamente un ID �nico, guarda en archivo y registra en bit�cora.
 * @param lista Lista de clientes (modificable).
 * @param usuarioActual Nombre del usuario activo (para bit�cora).
 */
void Clientes::agregar(std::vector<Clientes>& lista, const std::string& usuarioActual) {
    Clientes nuevo;

    // Asignar ID autom�tico
    nuevo.id = generarIdUnico(lista);
    if (nuevo.id.empty()) {
        std::cerr << "\n\t\tError: No hay c�digos disponibles para nuevos clientes (rango lleno)\n";
        system("pause");
        return;
    }

    std::cout << "\n\t\t=== AGREGAR CLIENTE (ID Auto-Asignado: " << nuevo.id << ") ===\n";

    // Limpiar buffer antes de getline()
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\t\tNombre completo: ";
    std::getline(std::cin, nuevo.nombre);

    std::cout << "\t\tDirecci�n: ";
    std::getline(std::cin, nuevo.direccion);

    std::cout << "\t\tTel�fono: ";
    std::getline(std::cin, nuevo.telefono);

    std::cout << "\t\tNIT: ";
    std::getline(std::cin, nuevo.nit);

    lista.push_back(nuevo);
    guardarEnArchivo(lista);

    bitacora::registrar(usuarioActual, "CLIENTES", "Cliente agregado - ID: " + nuevo.id);
    std::cout << "\n\t\tCliente registrado exitosamente con ID: " << nuevo.id << "\n";
    system("pause");
}

/**
 * Muestra todos los clientes actualmente almacenados en la lista.
 * Si la lista est� vac�a, muestra un mensaje apropiado.
 * @param lista Lista de clientes a mostrar.
 */
/**
 * Muestra todos los clientes actualmente almacenados en la lista.
 * Si la lista est� vac�a, muestra un mensaje apropiado.
 * @param lista Lista de clientes a mostrar.
 */
void Clientes::mostrar(const std::vector<Clientes>& lista) {
    if (lista.empty()) {
        cout << "\n\t--- NO HAY CLIENTES REGISTRADOS ---\n";
        cout << "\tEl archivo puede estar vac�o o no se carg� correctamente.\n";
    } else {
        // Cabecera
        cout << "\n\t" << string(100, '-') << "\n";
        cout << "\t" << left
             << setw(10) << "| ID |"
             << setw(30) << " NOMBRE COMPLETO |"
             << setw(25) << " DIRECCI�N |"
             << setw(15) << " TEL�FONO |"
             << setw(15) << " NIT |" << "\n";
        cout << "\t" << string(100, '-') << "\n";

        // Datos
        for (const auto& cliente : lista) {
            cout << "\t" << left
                 << "| " << setw(6) << cliente.id << "| "
                 << setw(28) << cliente.nombre << "| "
                 << setw(23) << cliente.direccion << "| "
                 << setw(13) << cliente.telefono << "| "
                 << setw(13) << cliente.nit << "|" << "\n";
        }
        cout << "\t" << string(100, '-') << "\n";
    }
    system("pause");
}

/**
 * Modifica los datos de un cliente existente seg�n su ID.
 * Guarda los cambios en el archivo y registra en la bit�cora.
 * @param lista Lista de clientes (modificable).
 * @param usuarioActual Usuario que realiza la modificaci�n.
 * @param id ID del cliente a modificar.
 */
void Clientes::modificar(std::vector<Clientes>& lista, const std::string& usuarioActual, const std::string& id) {
    auto it = find_if(lista.begin(), lista.end(),
        [&id](const Clientes& c) { return c.id == id; });

    if (it != lista.end()) {
        cout << "\n--- MODIFICAR CLIENTE (ID: " << id << ") ---\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer

        cout << "Nuevo nombre (" << it->nombre << "): ";
        getline(cin, it->nombre);

        cout << "Nueva direcci�n (" << it->direccion << "): ";
        getline(cin, it->direccion);

        cout << "Nuevo tel�fono (" << it->telefono << "): ";
        getline(cin, it->telefono);

        cout << "Nuevo NIT (" << it->nit << "): ";
        getline(cin, it->nit);

        guardarEnArchivo(lista);
        bitacora::registrar(usuarioActual, "CLIENTES", "Cliente modificado - ID: " + id);
        cout << "Cliente modificado!\n";
    } else {
        cout << "Cliente no encontrado.\n";
    }
    system("pause");
}

/**
 * Elimina un cliente de la lista dado su ID.
 * Guarda los cambios y registra la acci�n en bit�cora.
 * @param lista Lista de clientes (modificable).
 * @param usuarioActual Usuario que realiza la eliminaci�n.
 * @param id ID del cliente a eliminar.
 */
void Clientes::eliminar(std::vector<Clientes>& lista, const std::string& usuarioActual, const std::string& id) {
    auto it = find_if(lista.begin(), lista.end(),
        [&id](const Clientes& c) { return c.id == id; });

    if (it != lista.end()) {
        lista.erase(it);
        guardarEnArchivo(lista);
        bitacora::registrar(usuarioActual, "CLIENTES", "Cliente eliminado - ID: " + id);
        cout << "Cliente eliminado!\n";
    } else {
        cout << "Cliente no encontrado.\n";
    }
    system("pause");
}

/**
 * Guarda la lista completa de clientes en formato tabular en el archivo `Clientes.txt`.
 * Se usa un archivo temporal (`Clientes.tmp`) para evitar errores de escritura parcial.
 * Si hay fallos, se cancela el guardado para proteger la integridad del archivo.
 * @param lista Lista actual de clientes.
 */
void Clientes::guardarEnArchivo(const std::vector<Clientes>& lista) {
    ofstream archivo("Clientes.tmp", ios::out);
    if (!archivo.is_open()) {
        cerr << "\n\t\tError cr�tico: No se pudo crear archivo temporal!\n";
        return;
    }

    archivo << "---------------------------------- Lista de Clientes ----------------------------------\n";
    archivo << std::left
            << std::setw(10) << "ID"
            << std::setw(25) << "Nombre"
            << std::setw(25) << "Direcci�n"
            << std::setw(15) << "Tel�fono"
            << std::setw(15) << "NIT" << "\n";
    archivo << std::string(90, '-') << "\n";

    for (const auto& cliente : lista) {
        archivo << std::left
                << std::setw(10) << cliente.id
                << std::setw(25) << cliente.nombre
                << std::setw(25) << cliente.direccion
                << std::setw(15) << cliente.telefono
                << std::setw(15) << cliente.nit << "\n";
    }

    archivo << std::string(90, '-') << "\n";

    archivo.flush();
    if (!archivo) {
        cerr << "\n\t\tError: Fallo al guardar los datos en formato tabular!\n";
        archivo.close();
        remove("Clientes.tmp");
        return;
    }

    archivo.close();

    if (remove("Clientes.txt") != 0 && errno != ENOENT) {
        cerr << "\n\t\tAdvertencia: No se pudo eliminar el archivo anterior\n";
    }
    if (rename("Clientes.tmp", "Clientes.txt") != 0) {
        cerr << "\n\t\tError cr�tico: Fall� el guardado final!\n";
    }
}

/**
 * Carga los datos de clientes desde el archivo `Clientes.txt`.
 * Versi�n mejorada que maneja el formato tabular del archivo.
 * @param lista Lista de clientes a llenar (se limpia antes).
 */
void Clientes::cargarDesdeArchivo(std::vector<Clientes>& lista) {
    lista.clear();
    ifstream archivo("Clientes.txt");

    if (!archivo) {
        // Si el archivo no existe, se crea vac�o
        ofstream nuevoArchivo("Clientes.txt");
        if (!nuevoArchivo) {
            cerr << "\n\t\tError: No se pudo crear archivo de clientes!\n";
        }
        return;
    }

    string linea;
    int lineasValidas = 0;

    // Saltar las primeras 3 l�neas (cabecera)
    for (int i = 0; i < 3; ++i) {
        getline(archivo, linea);
    }

    while (getline(archivo, linea)) {
        // Saltar l�neas separadoras
        if (linea.find("---") != string::npos || linea.empty()) {
            continue;
        }

        istringstream ss(linea);
        Clientes temp;

        // Leer campos seg�n el formato de columnas fijas
        if (linea.length() >= 90) { // Asumiendo el ancho total de la l�nea
            temp.id = linea.substr(0, 10);
            temp.nombre = linea.substr(10, 25);
            temp.direccion = linea.substr(35, 25);
            temp.telefono = linea.substr(60, 15);
            temp.nit = linea.substr(75, 15);

            // Eliminar espacios en blanco sobrantes
            temp.id.erase(temp.id.find_last_not_of(" \t") + 1);
            temp.nombre.erase(temp.nombre.find_last_not_of(" \t") + 1);
            temp.direccion.erase(temp.direccion.find_last_not_of(" \t") + 1);
            temp.telefono.erase(temp.telefono.find_last_not_of(" \t") + 1);
            temp.nit.erase(temp.nit.find_last_not_of(" \t") + 1);

            if (!temp.id.empty() && esIdValido(temp.id)) {
                lista.push_back(temp);
                lineasValidas++;
            }
        }
    }

    cout << "\n\t\tSe cargaron " << lineasValidas << " clientes desde el archivo.\n";
}
