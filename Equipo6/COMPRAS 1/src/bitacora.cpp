#include "bitacora.h"
#include <map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const string Bitacora::ARCHIVO_BITACORA = "bitacora.txt";
string Bitacora::usuarioActual = "";

const map<int, string> DESCRIPCIONES_CODIGOS = {
    // Autenticaci�n
    {CodigosAccion::LOGIN_EXITOSO, "Inicio de sesi�n exitoso"},
    {CodigosAccion::LOGIN_FALLIDO, "Intento fallido de inicio de sesi�n"},
    {CodigosAccion::LOGOUT, "Cierre de sesi�n"},
    {CodigosAccion::BLOQUEO_USUARIO, "Usuario bloqueado"},
    {CodigosAccion::CAMBIO_CONTRASENA, "Cambio de contrase�a"},

    // Operaciones CRUD
    {CodigosAccion::CREACION_CLIENTE, "Creaci�n de nuevo cliente"},
    {CodigosAccion::LECTURA_CLIENTE, "Consulta de cliente"},
    {CodigosAccion::ACTUALIZACION_CLIENTE, "Actualizaci�n de cliente"},
    {CodigosAccion::ELIMINACION_CLIENTE, "Eliminaci�n de cliente"},
    {CodigosAccion::CREACION_PRODUCTO, "Creaci�n de producto"},
    {CodigosAccion::ACTUALIZACION_PRODUCTO, "Actualizaci�n de producto"},
    {CodigosAccion::ELIMINACION_PRODUCTO, "Eliminaci�n de producto"},

    // Contraversia
    {CodigosAccion::SELECCION_FACUNDO, "Selecci�n de Men� Facundo"},
    {CodigosAccion::SELECCION_TURQUE_SALUD, "Selecci�n de Turque Salud"},

    // Archivos
    {CodigosAccion::RESPALDO_CREADO, "Respaldo de datos creado"},
    {CodigosAccion::RESTAURACION_COMPLETADA, "Datos restaurados desde respaldo"},
    {CodigosAccion::EXPORTACION_DATOS, "Exportaci�n de datos"},

    // Errores
    {CodigosAccion::ERROR_SISTEMA, "Error del sistema"},
    {CodigosAccion::ERROR_ARCHIVO, "Error al acceder a archivo"},
    {CodigosAccion::ERROR_PERMISOS, "Error de permisos"}
};

string Bitacora::obtenerDescripcionCodigo(int codigo) {
    auto it = DESCRIPCIONES_CODIGOS.find(codigo);
    if (it != DESCRIPCIONES_CODIGOS.end()) {
        return it->second;
    }
    return "C�digo no reconocido";
}

void Bitacora::registrarAccion(const std::string& usuario, int codigoAccion, const std::string& descripcion) {
    usuarioActual = usuario;
    ofstream archivo(ARCHIVO_BITACORA, ios::app);
    if (archivo.is_open()) {
        archivo << obtenerFechaHoraActual() << " | "
                << "Usuario: " << usuario << " | "
                << "C�digo: " << codigoAccion << " (" << obtenerDescripcionCodigo(codigoAccion) << ") | "
                << "Detalles: " << descripcion << endl;
        archivo.close();
    } else {
        cerr << "Error: No se pudo abrir el archivo de bit�cora para escritura." << endl;
    }
}

void Bitacora::mostrarBitacora() {
    ifstream archivo(ARCHIVO_BITACORA);
    if (archivo.is_open()) {
        cout << "\n=== CONTENIDO DE LA BIT�CORA ===" << endl;
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        cout << "=== FIN DE LA BIT�CORA ===" << endl;
        archivo.close();
    } else {
        cerr << "Error: No se pudo abrir el archivo de bit�cora para lectura." << endl;
    }
}

string Bitacora::obtenerFechaHoraActual() {
    time_t ahora = time(nullptr);
    tm* tiempoLocal = localtime(&ahora);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempoLocal);
    return string(buffer);
}

string Bitacora::obtenerUsuarioActual() {
    return usuarioActual;
}
