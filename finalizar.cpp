#include <iostream>

using namespace std;

const int MAX_ESTUDIANTES = 500;
const int EVALUACIONES = 4; 

float matrizNotas[MAX_ESTUDIANTES][EVALUACIONES];
 int totalEstudiantes;

void finalizarSistema() {
    cout << "_____________________________________________________\n";
    cout << "                  FINALIZAR SISTEMA                  \n";
    cout << "_____________________________________________________\n";
    cout << "Esta opcion borrara las notas guardadas en la matriz\n";
    cout << "y reiniciara el sistema para el nuevo ciclo academico.\n";
    cout << "______________________________________________________\n";
    
    char confirmacion;
    cout << "�Desea confirmar la finalizacion y reinicio del ciclo? (S/N): ";
    cin >> confirmacion;

    if (confirmacion == 'S' || confirmacion == 's') {
        
        for (int i = 0; i < MAX_ESTUDIANTES; i++) {
            for (int j = 0; j < EVALUACIONES; j++) {
                matrizNotas[i][j] = 0.0f; 
            }
        }
        
        totalEstudiantes = 0; 
        cout << "\n[EXITO] Sistema finalizado y restablecido correctamente para el nuevo ciclo.\n";
    } else {
        cout << "\n[CANCELADO] Proceso de finalizacion cancelado.\n";
    }
}
// int main() {
    
//     finalizarSistema();
    
//     cout << "\n--- Verificacion del Main ---";
//     cout << "\nTotal de estudiantes en el sistema ahora: " << totalEstudiantes << "\n\n";
    
//     system("pause"); 
//     return 0;
// }
