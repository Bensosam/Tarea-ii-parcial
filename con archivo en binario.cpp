#include <iostream>
#include <fstream>


using namespace std;

struct Estudiante {
    int id;
    char nombres[50];
    char apellidos[50];
    float notas[4];
    float promedio;
    char resultado[20];
};

void calcularPromedio(Estudiante& estudiante) {
    float suma = 0;
    for (int i = 0; i < 4; ++i) suma += estudiante.notas[i];
    estudiante.promedio = suma / 4;
    strcpy(estudiante.resultado, (estudiante.promedio > 60) ? "Aprobado" : "Reprobado");
}

void agregarEstudiante(fstream& archivo, Estudiante& estudiante) {
    archivo.write(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));
}

void mostrarEstudiante(Estudiante& estudiante) {
    cout << "ID: " << estudiante.id << ", Nombres: " << estudiante.nombres << ", Apellidos: " << estudiante.apellidos
         << ", Promedio: " << estudiante.promedio << ", Resultado: " << estudiante.resultado << endl;
}

int main() {
    fstream archivo("notas.dat", ios::in | ios::out | ios::binary | ios::app);
    if (!archivo) {
        cerr << "Error al abrir el archivo. Creando un nuevo archivo..." << endl;
        archivo.open("notas.dat", ios::out | ios::binary);
        archivo.close();
        archivo.open("notas.dat", ios::in | ios::out | ios::binary | ios::app);
    }

    int opcion;
    while (true) {
        cout << "\nMenu:\n1. Agregar estudiante\n2. Mostrar todos los estudiantes\n3. Salir\nSeleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                Estudiante nuevoEstudiante;
                cout << "ID: "; cin >> nuevoEstudiante.id;
                cout << "Nombres: "; cin >> nuevoEstudiante.nombres;
                cout << "Apellidos: "; cin >> nuevoEstudiante.apellidos;
                cout << "Notas: ";
                for (int i = 0; i < 4; ++i) cin >> nuevoEstudiante.notas[i];
                calcularPromedio(nuevoEstudiante);
                agregarEstudiante(archivo, nuevoEstudiante);
                break;
            }
            case 2: {
                archivo.seekg(0);
                Estudiante estudiante;
                while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante)))
                    mostrarEstudiante(estudiante);
                break;
            }
            case 3: {
                archivo.close();
                cout << "Saliendo del programa." << endl;
                return 0;
            }
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }
    }
}