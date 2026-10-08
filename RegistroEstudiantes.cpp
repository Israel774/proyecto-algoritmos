#include <chrono>
#include <ctime>
#include <fstream> // Necesaria para el manejo de archivos (ifstream y ofstream)
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Variable global para controlar el correlativo (ahora se actualizará
// dinámicamente)
int contadorCarnet = 1;

struct Alumno {
  string carnet;
  string nombreCompleto;
  string apellidosCompleto;
  string direccion;
  string telefono;
  string carrera;
  chrono::system_clock::time_point fechaInscripcion;
};

string generarCarnetAutomatico() {
  stringstream ss;
  ss << setw(4) << setfill('0') << contadorCarnet;
  contadorCarnet++;
  return ss.str();
}

string formatearFechaString(const chrono::system_clock::time_point &fecha) {
  time_t tiempoConvertido = chrono::system_clock::to_time_t(fecha);
  tm tiempoLocal;
#if defined(_MSC_VER)
  localtime_s(&tiempoLocal, &tiempoConvertido);
#else
  localtime_r(&tiempoConvertido, &tiempoLocal);
#endif
  char bufferFecha[80];
  strftime(bufferFecha, sizeof(bufferFecha), "%d/%m/%Y a las %H:%M hrs.",
           &tiempoLocal);
  return string(bufferFecha);
}

void mostrarFechaInscripcion(const Alumno &estudiante) {
  cout << "Fecha de Inscripcion: "
       << formatearFechaString(estudiante.fechaInscripcion) << endl;
}

void guardarAlumnoEnArchivo(const Alumno &estudiante) {
  ofstream archivo("expedientes_alumnos.txt", ios::app);

  if (archivo.is_open()) {
    archivo << estudiante.carnet << "|" << estudiante.nombreCompleto << "|"
            << estudiante.apellidosCompleto << "|" << estudiante.direccion
            << "|" << estudiante.telefono << "|" << estudiante.carrera << "|"
            << formatearFechaString(estudiante.fechaInscripcion) << "\n";

    archivo.close();
    cout << "-> Datos respaldados con exito en 'expedientes_alumnos.txt'"
         << endl;
  } else {
    cout << "Error: No se pudo abrir el archivo para guardar los datos."
         << endl;
  }
}

// FUNCIÓN NUEVA: Lee el archivo para recuperar el correlativo correcto
void cargarContadorDesdeArchivo() {
  ifstream archivo("expedientes_alumnos.txt");

  // Si el archivo no existe todavía (es la primera vez que corre el programa),
  // se salta la lectura
  if (!archivo.is_open()) {
    contadorCarnet = 1;
    return;
  }

  string linea;
  int cantidadAlumnos = 0;

  // Leemos el archivo línea por línea contando los registros guardados
  while (getline(archivo, linea)) {
    // Evitamos contar líneas en blanco accidentales
    if (!linea.empty()) {
      cantidadAlumnos++;
    }
  }

  archivo.close();

  // El próximo carnet asignado será el total de alumnos existentes + 1
  contadorCarnet = cantidadAlumnos + 1;
}

int main() {
  // CONFIGURACIÓN INICIAL: Recuperamos el correlativo antes de registrar a
  // nadie
  cargarContadorDesdeArchivo();

  char opcion;

  do {
    Alumno nuevoAlumno;

    cout << "\n=== SISTEMA DE REGISTRO ESCOLAR ===" << endl;

    // Asignación automática que ahora toma en cuenta los registros pasados
    nuevoAlumno.carnet = generarCarnetAutomatico();
    cout << "-> Carnet asignado automaticamente: " << nuevoAlumno.carnet << endl
         << endl;

    cout << "Ingrese el nombre completo del estudiante: ";
    getline(cin, nuevoAlumno.nombreCompleto);

    cout << "Ingrese los apellidos completo del estudiante: ";
    getline(cin, nuevoAlumno.apellidosCompleto);

    cout << "Ingrese la direccion del estudiante: ";
    getline(cin, nuevoAlumno.direccion);

    cout << "Ingrese el telefono del estudiante: ";
    getline(cin, nuevoAlumno.telefono);

    cout << "Ingrese la carrera: ";
    getline(cin, nuevoAlumno.carrera);

    nuevoAlumno.fechaInscripcion = chrono::system_clock::now();

    cout << "\n===================================" << endl;
    cout << "  ALUMNO REGISTRADO CON EXITO      " << endl;
    cout << "===================================" << endl;
    cout << "Carnet:    " << nuevoAlumno.carnet << endl;
    cout << "Nombres:   " << nuevoAlumno.nombreCompleto << endl;
    cout << "Apellidos: " << nuevoAlumno.apellidosCompleto << endl;
    cout << "Direccion: " << nuevoAlumno.direccion << endl;
    cout << "Telefono:  " << nuevoAlumno.telefono << endl;
    cout << "Carrera:   " << nuevoAlumno.carrera << endl;
    mostrarFechaInscripcion(nuevoAlumno);

    guardarAlumnoEnArchivo(nuevoAlumno);
    cout << "===================================" << endl;

    cout << "\n¿Desea registrar otro alumno? (s/n): ";
    cin >> opcion;

    cin.ignore();

  } while (opcion == 's' || opcion == 'S');

  cout << "\nGracias por usar el sistema escolar. ¡Hasta luego!\n" << endl;
  return 0;
}
