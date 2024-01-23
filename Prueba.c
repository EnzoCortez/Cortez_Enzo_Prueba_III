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

int main()
{
    int opcion;
    int n;

    // Solicitar al usuario la cantidad de alumnos
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    // Crear un arreglo de estructuras alumno con capacidad para n alumnos
    struct alumno listaAlumnos[n];

    // Cargar datos desde el archivo al inicio del programa
    leerDesdeArchivo(listaAlumnos, n);

    do
    {
        // Menú principal
        printf("\nMenú:\n");
        printf("1. Ingresar alumnos\n");
        printf("2. Mostrar alumnos\n");
        printf("3. Guardar en archivo\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            ingresarAlumnos(listaAlumnos, n);
            break;

        case 2:
            mostrarAlumnos(listaAlumnos, n);
            break;

        case 3:
            guardarEnArchivo(listaAlumnos, n);
            break;

        case 4:
            printf("Guardando en archivo y saliendo del programa.\n");
            guardarEnArchivo(listaAlumnos, n);
            break;

        default:
            printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}


// Función para ingresar la información de alumnos
void ingresarAlumnos(struct alumno lista[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // Solicitar información de cada alumno
        printf("\nIngrese los datos del alumno %d:\n", i + 1);
        printf("Matrícula: ");
        scanf("%d", &lista[i].matricula);

        printf("Nombre: ");
        fflush(stdin);
        fgets(lista[i].nombre, sizeof(lista[i].nombre), stdin);

        printf("Dirección: ");
        fflush(stdin);
        fgets(lista[i].direccion, sizeof(lista[i].direccion), stdin);

        printf("Materia: ");
        fflush(stdin);
        fgets(lista[i].materia, sizeof(lista[i].materia), stdin);

        printf("Nota: ");
        scanf("%f", &lista[i].nota);
    }
}
