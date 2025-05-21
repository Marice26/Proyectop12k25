// LUIS ANGEL MENDEZ FUENTES 9959-24-6845
#ifndef BITACORA_H
#define BITACORA_H

#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <unordered_map>  // Necesario para std::unordered_map

class CodigosBitacora {
private:
    static std::unordered_map<std::string, int> rangos;
public:
    static int getCodigo(const std::string& modulo) {  // Cambiado a un solo par�metro
        // Asigna c�digos incrementales dentro del rango del m�dulo
        if (rangos.find(modulo) == rangos.end()) {
            rangos[modulo] = 3000; // Inicializa el rango base seg�n m�dulo
        }
        return rangos[modulo]++;
    }
};

// Inicializaci�n de rangos (debe estar en el .cpp)
// std::unordered_map<std::string, int> CodigosBitacora::rangos = {
//     {"PEDIDOS", 3100}, {"ENVIOS", 3300}, {"INVENTARIO", 3200},
//     {"FACTURACION", 3350}, {"REPORTES", 3400}, {"USUARIOS", 3000}
// };

class bitacora {
public:
    // M�todo para registrar acciones (cambiar de static a m�todo normal si es necesario)
    static void registrar(const std::string& usuario,
                        const std::string& modulo,
                        const std::string& descripcion);

    // M�todo alternativo para compatibilidad
    static void insertar(const std::string& usuario,
                       const std::string& modulo,
                       const std::string& descripcion) {
        registrar(usuario, modulo, descripcion);
    }

    // M�todo para generar backups
    static void generarBackup();

    // M�todo para mostrar la bit�cora
    static void mostrarBitacora();

    // M�todo del men� de bit�cora
    static void menuBitacora();

    // M�todo para reiniciar la bit�cora
    static void reiniciarBitacora();

private:
    // Funci�n interna para obtener fecha formateada
    static std::string obtenerFechaActual();
};

#endif // BITACORA_H
