#include <iostream>
#include <cstdlib>
#include "modificar_datos.h"
#include "finalizar.h"
#include <windows.h>

using namespace std;

// void ingresarEstudiantes();
// void eliminarDelSistema();
// void modificarDatosEstudiantes();
// void consultarEstudiantes();
// void ingresarNotas();
// void reportes();
// void finalizarSistema();

void mostrarMenu() {
    SetConsoleOutputCP(CP_UTF8);
    int opcion = 0;
    
    do {
        system("cls");
        cout << "-----------------------------------------------------" <<endl;
        cout << "                  MENU PRINCIPAL                     " <<endl;
        cout << "-----------------------------------------------------" <<endl;
        cout << " 1. INGRESAR ESTUDIANTES (AL SISTEMA)" <<endl;
        cout << " 2. ELIMINAR DEL SISTEMA" <<endl;
        cout << " 3. MODIFICAR DATOS DE ESTUDIANTES" <<endl;
        cout << " 4. CONSULTAR ESTUDIANTES" <<endl;
        cout << " 5. INGRESAR NOTAS" <<endl;
        cout << " 6. REPORTES" <<endl;
        cout << " 7. FINALIZAR CICLO" <<endl;
        cout << " 8. SALIR" <<endl;
        cout << "----------------------------------------------------" <<endl;
        cout << " Seleccione una opcion [1-8]: ";
        
        
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n[ERROR] Entrada invalida. Ingrese un numero del 1 al 8.\n";
            system("pause");
            continue;
        }

        system("cls");
        switch (opcion) {
            case 1:
                cout << "--- INGRESAR ESTUDIANTES (AL SISTEMA) ---\n";
                break;
            case 2:
                cout << "--- ELIMINAR DEL SISTEMA ---\n";
                break;
            case 3:
                cout << "--- MODIFICAR DATOS DE ESTUDIANTES ---\n";
                modificarDatosEstudiantes();
                break;
            case 4:
                cout << "--- CONSULTAR ESTUDIANTES ---\n";
                break;
            case 5:
                cout << "--- INGRESAR NOTAS ---\n";
                break;
            case 6:
                cout << "--- REPORTES ---\n";
                break;
            case 7:
                cout << "--- FINALIZAR CICLO ---\n";
                finalizarSistema();
                break;
            case 8:
                cout << "\nSaliendo del sistema...\n";
                break;
            default:
                cout << "\n[ERROR] Opcion fuera de rango. Intente de nuevo.\n";
                break;
        }
        
        if (opcion != 8) {
            cout << "\n";
            system("pause");
        }
    } while (opcion != 8);
    
}
int main() {
    mostrarMenu(); 
    return 0;
}
