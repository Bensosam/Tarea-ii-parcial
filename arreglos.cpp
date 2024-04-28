#include <iostream>

using namespace std;

struct Estudiante {
    int id;
    char nombres[50];
    char apellidos[50];
    float notas[4];
    float promedio;
};

void calcularPromedio(Estudiante& estudiante) {
    float suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiante.notas[i];
    }
    estudiante.promedio = suma / 4;
}

void Resultado(Estudiante& estudiante) {
    cout << "ID: " << estudiante.id << endl;
    cout << "Nombres: " << estudiante.nombres << endl;
    cout << "Apellidos: " << estudiante.apellidos << endl;
    cout << "Promedio: " << estudiante.promedio << endl;
    if (estudiante.promedio > 60) {
        cout << "Estado: Aprobado" << endl;
    } else {
        cout << "Estado: Reprobado" << endl;
    }
    cout << "-----------------------------" << endl;
}

int main() {
    int N;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N;

    Estudiante estudiantes[N];

    for (int i = 0; i < N; ++i) {
        cout << "Ingrese el ID del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].id;
        cout << "Ingrese los nombres del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nombres;
        cout << "Ingrese los apellidos del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].apellidos;
        for (int j = 0; j < 4; ++j) {
            cout << "Ingrese la nota " << j + 1 << " del estudiante " << i + 1 << ": ";
            cin >> estudiantes[i].notas[j];
        }
        calcularPromedio(estudiantes[i]);
    }

    cout << "\nResultados:" << endl;
    for (int i = 0; i < N; ++i) {
        Resultado(estudiantes[i]);
    }

    return 0;
}