#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <ctime>

template <typename T>
class GradeBook {
private:
    static const int MAX_ESTUDIANTES = 50;  // Máximo número de estudiantes
    static const int MAX_MATERIAS = 10;     // Máximo número de materias
    
    T calificaciones[MAX_ESTUDIANTES][MAX_MATERIAS];  // Arreglo bidimensional estático
    int numEstudiantes;
    int numMaterias;

public:
    // Constructor
    GradeBook(int estudiantes, int materias) 
        : numEstudiantes(estudiantes), numMaterias(materias) {
        
        // Validar que no excedamos los límites
        if (estudiantes > MAX_ESTUDIANTES || materias > MAX_MATERIAS) {
            std::cerr << "Error: Límites excedidos." << std::endl;
            numEstudiantes = 0;
            numMaterias = 0;
        }
        
        // Inicializar todas las calificaciones en 0
        for (int i = 0; i < numEstudiantes; i++) {
            for (int j = 0; j < numMaterias; j++) {
                calificaciones[i][j] = 0;
            }
        }
    }

    // Método para llenar calificaciones manualmente
    void llenarManual() {
        std::cout << "\n=== CAPTURA DE CALIFICACIONES ===" << std::endl;
        for (int i = 0; i < numEstudiantes; i++) {
            std::cout << "\nAlumno " << (i + 1) << ":" << std::endl;
            for (int j = 0; j < numMaterias; j++) {
                std::cout << "  Materia " << (j + 1) << ": ";
                std::cin >> calificaciones[i][j];
            }
        }
    }

    // Método para llenar calificaciones aleatoriamente (entre 0 y 100)
    void llenarAleatorio() {
        srand(static_cast<unsigned int>(time(0)));  // Semilla para números aleatorios
        
        std::cout << "\n=== GENERANDO CALIFICACIONES ALEATORIAS ===" << std::endl;
        for (int i = 0; i < numEstudiantes; i++) {
            for (int j = 0; j < numMaterias; j++) {
                calificaciones[i][j] = static_cast<T>(rand() % 101);  // 0-100
            }
        }
        std::cout << "Calificaciones generadas exitosamente.\n" << std::endl;
    }

    // Calcular promedio por estudiante
    T promedioEstudiante(int estudiante) const {
        if (estudiante < 0 || estudiante >= numEstudiantes) {
            return 0;
        }
        
        T suma = 0;
        for (int j = 0; j < numMaterias; j++) {
            suma += calificaciones[estudiante][j];
        }
        return suma / numMaterias;
    }

    // Calcular promedio por materia
    T promedioMateria(int materia) const {
        if (materia < 0 || materia >= numMaterias) {
            return 0;
        }
        
        T suma = 0;
        for (int i = 0; i < numEstudiantes; i++) {
            suma += calificaciones[i][materia];
        }
        return suma / numEstudiantes;
    }

    // Encontrar calificación mínima general
    T calificacionMinima() const {
        T minimo = calificaciones[0][0];
        
        for (int i = 0; i < numEstudiantes; i++) {
            for (int j = 0; j < numMaterias; j++) {
                if (calificaciones[i][j] < minimo) {
                    minimo = calificaciones[i][j];
                }
            }
        }
        return minimo;
    }

    // Encontrar calificación máxima general
    T calificacionMaxima() const {
        T maximo = calificaciones[0][0];
        
        for (int i = 0; i < numEstudiantes; i++) {
            for (int j = 0; j < numMaterias; j++) {
                if (calificaciones[i][j] > maximo) {
                    maximo = calificaciones[i][j];
                }
            }
        }
        return maximo;
    }

    // Mostrar todas las calificaciones
    void mostrarCalificaciones() const {
        std::cout << "\n=== TABLA DE CALIFICACIONES ===" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        
        // Encabezado
        std::cout << "Alumno\t";
        for (int j = 0; j < numMaterias; j++) {
            std::cout << "Mat" << (j + 1) << "\t";
        }
        std::cout << std::endl;
        
        // Separador
        for (int j = 0; j <= numMaterias; j++) {
            std::cout << "--------";
        }
        std::cout << std::endl;
        
        // Datos
        for (int i = 0; i < numEstudiantes; i++) {
            std::cout << (i + 1) << "\t";
            for (int j = 0; j < numMaterias; j++) {
                std::cout << calificaciones[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Generar reporte completo
    void generarReporte() const {
        std::cout << std::fixed << std::setprecision(2);
        
        // Promedio por estudiante
        std::cout << "\n=== PROMEDIO POR ESTUDIANTE ===" << std::endl;
        for (int i = 0; i < numEstudiantes; i++) {
            std::cout << "Alumno " << (i + 1) << ": " 
                      << promedioEstudiante(i) << std::endl;
        }
        
        // Promedio por materia
        std::cout << "\n=== PROMEDIO POR MATERIA ===" << std::endl;
        for (int j = 0; j < numMaterias; j++) {
            std::cout << "Materia " << (j + 1) << ": " 
                      << promedioMateria(j) << std::endl;
        }
        
        // Estadísticas generales
        std::cout << "\n=== ESTADÍSTICAS GENERALES ===" << std::endl;
        std::cout << "Calificación mínima general: " << calificacionMinima() << std::endl;
        std::cout << "Calificación máxima general: " << calificacionMaxima() << std::endl;
    }

    // Getters
    int getNumEstudiantes() const { return numEstudiantes; }
    int getNumMaterias() const { return numMaterias; }
};

#endif // GRADEBOOK_HPP