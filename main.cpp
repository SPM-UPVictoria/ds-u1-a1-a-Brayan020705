#include "gradebook.hpp"
#include <iostream>

using namespace std;

int main() {
    int numEstudiantes, numMaterias;
    int opcion;
    
    cout << "============================================" << endl;
    cout << "  SISTEMA DE GESTIÓN DE CALIFICACIONES" << endl;
    cout << "============================================" << endl;
    
    // Solicitar número de estudiantes y materias
    cout << "\nIngrese el número de estudiantes: ";
    cin >> numEstudiantes;
    
    cout << "Ingrese el número de materias: ";
    cin >> numMaterias;
    
    // Crear objeto GradeBook (puedes cambiar el tipo: int, float, double)
    GradeBook<float> libro(numEstudiantes, numMaterias);
    
    // Menú de opciones
    cout << "\n¿Cómo desea ingresar las calificaciones?" << endl;
    cout << "1. Manualmente" << endl;
    cout << "2. Aleatoriamente" << endl;
    cout << "Opción: ";
    cin >> opcion;
    
    if (opcion == 1) {
        libro.llenarManual();
    } else {
        libro.llenarAleatorio();
    }
    
    // Mostrar tabla de calificaciones
    libro.mostrarCalificaciones();
    
    // Generar reporte completo
    libro.generarReporte();
    
    cout << "\n============================================" << endl;
    cout << "  Programa finalizado exitosamente" << endl;
    cout << "============================================" << endl;
    
    return 0;
}