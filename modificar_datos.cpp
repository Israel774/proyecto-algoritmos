#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void modificarDatosEstudiantes() {
    string idEstudiante;
    cout << "Función para modificar datos de estudiantes.\n";
    cout << "Buscar estudiante por ID o nombre...\n";
    cin >> idEstudiante;

    cout << "Estudiante encontrado: " << idEstudiante << "\n";

    cout << "+" << setfill('-') << setw(50) << "+" << endl;
    cout << left << setw(12) << "Carne" << setw(25) << "Nombre" << setw(20) << "Carrera" << endl;

}


// int main() {
//     modificarDatosEstudiantes();
//     return 0;
// }