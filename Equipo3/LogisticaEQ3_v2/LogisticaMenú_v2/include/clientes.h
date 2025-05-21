#ifndef CLIENTES_H
#define CLIENTES_H

#include <vector>
#include <string>

/**
 * @class Clientes
 * @brief Clase que representa a un cliente y gestiona operaciones CRUD y de persistencia.
 */
class Clientes {
public:
    /// Identificador �nico del cliente (rango permitido: 3107�3157)
    std::string id;

    /// Nombre completo del cliente
    std::string nombre;

    /// Direcci�n del cliente
    std::string direccion;

    /// N�mero de tel�fono del cliente
    std::string telefono;

    /// NIT (N�mero de Identificaci�n Tributaria) del cliente
    std::string nit;

    // ====================== M�TODOS CRUD ======================

    /**
     * @brief Agrega un nuevo cliente a la lista.
     * @param lista Lista actual de clientes (modificable).
     * @param usuarioActual Nombre del usuario que realiza la acci�n (para bit�cora).
     */
    static void agregar(std::vector<Clientes>& lista, const std::string& usuarioActual);

    /**
     * @brief Muestra todos los clientes en consola.
     * @param lista Lista actual de clientes.
     */
    static void mostrar(const std::vector<Clientes>& lista);

    /**
     * @brief Modifica los datos de un cliente existente por su ID.
     * @param lista Lista actual de clientes (modificable).
     * @param usuarioActual Nombre del usuario que realiza la acci�n (para bit�cora).
     * @param id ID del cliente a modificar.
     */
    static void modificar(std::vector<Clientes>& lista, const std::string& usuarioActual, const std::string& id);

    /**
     * @brief Elimina un cliente de la lista por su ID.
     * @param lista Lista actual de clientes (modificable).
     * @param usuarioActual Nombre del usuario que realiza la acci�n (para bit�cora).
     * @param id ID del cliente a eliminar.
     */
    static void eliminar(std::vector<Clientes>& lista, const std::string& usuarioActual, const std::string& id);

    // ====================== M�TODOS DE ARCHIVO ======================

    /**
     * @brief Guarda toda la lista de clientes en el archivo `Clientes.txt` en formato tabular.
     * @param lista Lista actual de clientes.
     */
    static void guardarEnArchivo(const std::vector<Clientes>& lista);

    /**
     * @brief Carga los clientes desde el archivo `Clientes.txt` a la lista.
     * @param lista Lista que se llenar� con los clientes del archivo.
     */
    static void cargarDesdeArchivo(std::vector<Clientes>& lista);

    // ====================== M�TODOS DE GESTI�N DE ID ======================

    /**
     * @brief Genera un ID �nico para un nuevo cliente dentro del rango 3107�3157.
     * @param lista Lista actual de clientes.
     * @return ID disponible como string o cadena vac�a si ya est�n ocupados todos los c�digos.
     */
    static std::string generarIdUnico(const std::vector<Clientes>& lista);

    /**
     * @brief Verifica si un ID est� disponible (no est� repetido en la lista).
     * @param lista Lista de clientes.
     * @param id ID a verificar.
     * @return true si el ID est� libre, false si est� ocupado.
     */
    static bool idDisponible(const std::vector<Clientes>& lista, const std::string& id);

    /**
     * @brief Valida si un ID es un n�mero dentro del rango permitido.
     * @param id ID a validar.
     * @return true si es v�lido, false en caso contrario.
     */
    static bool esIdValido(const std::string& id);

    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }
};

#endif // CLIENTES_H
