#include <iostream>
#include <string>

using namespace std;

const int MAX_ESTUDIANTES = 500;

struct Estudiante {
    string carne;
    string nombre;
    string apellido;
    string carrera;
    bool activoEnSistema;
    bool activoEnCarrera;
};


float matrizNotas[MAX_ESTUDIANTES][4]; 
Estudiante estudiantes[MAX_ESTUDIANTES];
int totalEstudiantes = 0;

void eliminarDelSistema() {
    int subOpcion = 0;
    
    cout << "____________________________________________________\n";
    cout << "                ELIMINAR / DAR DE BAJA              \n";
    cout << "____________________________________________________\n";
    cout << " 1. ELIMINAR AL ALUMNO DEL SISTEMA\n";
    cout << " 2. ELIMINAR AL ALUMNO DE UNA CARRERA\n";
    cout << " 3. REGRESAR\n";
    cout << "____________________________________________________\n";
    cout << " Seleccione una opcion: ";
    cin >> subOpcion;

    if (subOpcion == 3) return;

    if (totalEstudiantes == 0) {
        cout << "\n[AVISO] No hay estudiantes registrados en el sistema.\n";
        return;
    }

    string carneBuscado;
    cout << "\nIngrese el carne del estudiante: ";
    cin >> carneBuscado;

    int pos = -1;
    for (int i = 0; i < totalEstudiantes; i++) {
        if (estudiantes[i].carne == carneBuscado) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "\n[ERROR] Estudiante no encontrado con el carne ingresado.\n";
        return;
    }

    if (subOpcion == 1) {
       
        estudiantes[pos].activoEnSistema = false;
        estudiantes[pos].activoEnCarrera = false;
        
        for (int j = 0; j < 4; j++) {
            matrizNotas[pos][j] = 0.0f;
        }
        cout << "\n[EXITO] El estudiante ha sido ELIMINADO DEL SISTEMA completamente.\n";
    } 
    else if (subOpcion == 2) {
    
        estudiantes[pos].activoEnCarrera = false;
        cout << "\n[EXITO] El estudiante ha sido ELIMINADO DE LA CARRERA (" 
             << estudiantes[pos].carrera << ").\n";
    }
}
int main() {
  
    eliminarDelSistema();
    return 0;
}
