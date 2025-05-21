//Marlon De León 5001
#include "Login.h" // Archivo de cabecera asociado al módulo de login
#include <iostream> // Librería para entrada/salida estándar
#include <fstream> // Librería para manejo de archivos
#include <string> // Librería para usar strings
#include "encabezado.h" //  contiene definiciones globales 'usuarioActual'

using namespace std;


// Función: usuarioExiste
// Parámetro: username - nombre de usuario a verificar
// Retorna: true si el usuario ya está registrado, false si no
// Descripción: Abre el archivo 'usuarios.txt' y busca si el usuario ya existe.


bool usuarioExiste(const string& username) {
    ifstream file("usuarios.txt"); // Abre archivo de usuarios en modo lectura
    string user, pass;
    while (file >> user >> pass) { // Lee línea por línea (usuario y contraseña)
        if (user == username) {
            return true; // Usuario ya existe
        }
    }
    return false; // Usuario no encontrado
}


// Función: registrarUsuario
// Retorna: true si el registro fue exitoso, false si el usuario ya existe
// Descripción: Permite al usuario registrar un nuevo nombre de usuario y contraseña.
//              Verifica primero que no exista ese usuario.
bool registrarUsuario() {
    system("cls"); // Limpia la pantalla
    string username, password;
    cout << "\n--- Registro de Usuario ---\n";
    cout << "Ingrese nombre de usuario: ";
    cin >> username;

    // Verifica si el nombre ya está en uso
    if (usuarioExiste(username)) {
        cout << "El usuario ya existe.\n";
        return false;  // Registro fallido
    }

    cout << "Ingrese contraseña: ";
    cin >> password;

    // Abre el archivo de usuarios en modo append (agregar al final)
    ofstream file("usuarios.txt", ios::app);
    file << username << " " << password << "\n";
    file.close();

    cout << "Usuario registrado exitosamente.\n";
    return true;
}


// Función: iniciarSesion
// Parámetro: usuarioActual (referencia) - para guardar el usuario que inició sesión
// Retorna: true si las credenciales son correctas, false si no
// Descripción: Solicita credenciales al usuario y valida contra los datos del archivo.
//              Si coinciden, guarda el nombre del usuario para futuras operaciones.
bool iniciarSesion(string& usuarioActual) {
    system("cls"); // Limpia la pantalla
    string username, password;
    cout << "\n--- Inicio de Sesion ---\n";
    cout << "Usuario: ";
    cin >> username;
    cout << "Contraseña: ";
    cin >> password;

    ifstream file("usuarios.txt"); // Abre el archivo de usuarios
    string user, pass;
    while (file >> user >> pass) {  // Lee línea por línea
        if (user == username && pass == password) {
            usuarioActual = username; // Guarda el nombre para uso global (por ejemplo, bitácoras)
            cout << "Inicio de sesión exitoso. Bienvenido, " << username << ".\n";
            return true;
        }
    }

    cout << "Credenciales incorrectas.\n";
    return false;
}
