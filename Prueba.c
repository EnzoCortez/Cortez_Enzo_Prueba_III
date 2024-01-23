#include <stdio.h>

// Definición de la estructura alumno
struct alumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char materia[50];
    float nota;
};

// funciones para la manipulacion de archivos
void ingresarAlumnos(struct alumno lista[], int n);
void mostrarAlumnos(struct alumno lista[], int n);
void guardarEnArchivo(struct alumno lista[], int n);
void leerDesdeArchivo(struct alumno lista[], int n);

