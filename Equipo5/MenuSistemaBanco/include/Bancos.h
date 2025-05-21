//Jonathan Samuel Gonzalez
#ifndef BANCOS_H
#define BANCOS_H

#include <string>
#include "Bitacora.h"
#include "Moneda.h"

class Bancos {
private:
    static Bitacora bitacoraBancos; // Instancia de bit�cora para Bancos

    std::string bancoSeleccionado;
    std::string tipoCuentaSeleccionada;
    std::string monedaSeleccionada;

    void menuSeleccionBanco();
    void menuTipoCuenta();
    void menuTipoMoneda();

public:
    Bancos();

    // Configuraci�n y visualizaci�n
    void menuConfiguracion();
    void mostrarConfiguracion();

    // Funciones auxiliares
    static void limpiarPantalla();
    static void pausar();

    // Getters
    std::string getBanco() const;
    std::string getCuenta() const;
    std::string getMoneda() const;
};

#endif
