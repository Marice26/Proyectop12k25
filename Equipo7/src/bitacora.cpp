#include "bitacora.h"
#include <fstream>
#include <ctime>
#include <string>
#include <iostream>
#include <cstdint> // Para uint32_t

void registrarEvento(const std::string& usuario, const std::string& evento) {
    std::ofstream archivo("bitacora.bin", std::ios::binary | std::ios::app);
    if (!archivo) {
        std::cerr << "No se pudo abrir bitacora.bin para escribir." << std::endl;
        return;
    }

    // Obtener fecha y hora actual
    time_t t = time(nullptr);
    char fechaHora[100];
    strftime(fechaHora, sizeof(fechaHora), "%Y-%m-%d %H:%M:%S", localtime(&t));

    std::string mensaje = std::string(fechaHora) + " | Usuario: " + usuario + " | " + evento;

    // Usar uint32_t para longitud fija
    uint32_t longitud = static_cast<uint32_t>(mensaje.size());
    archivo.write(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    archivo.write(mensaje.c_str(), longitud);

    archivo.close();
}
