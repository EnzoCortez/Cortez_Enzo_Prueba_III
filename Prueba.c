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

// Función para mostrar la información de los alumnos
void mostrarAlumnos(struct alumno lista[], int n)
{
    printf("\nLista de alumnos ingresados:\n");
    for (int i = 0; i < n; i++)
    {
        // Mostrar información de cada alumno
        printf("\nAlumno %d:\n", i + 1);
        printf("Matrícula: %d\n", lista[i].matricula);
        printf("Nombre: ");
        puts(lista[i].nombre);
        printf("Dirección: ");
        puts(lista[i].direccion);
        printf("Materia: ");
        puts(lista[i].materia);
        printf("Nota: %.2f\n", lista[i].nota);
    }
}

// Función para guardar los datos en un archivo de texto
void guardarEnArchivo(struct alumno lista[], int n)
{
    FILE *archivo;
    archivo = fopen("alumnos.txt", "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(archivo, "%d\n", lista[i].matricula);
        fprintf(archivo, "%s", lista[i].nombre);
        fprintf(archivo, "%s", lista[i].direccion);
        fprintf(archivo, "%s", lista[i].materia);
        fprintf(archivo, "%.2f\n", lista[i].nota);
    }

    fclose(archivo);
    printf("Datos guardados en el archivo correctamente.\n");
}

// Función para leer los datos desde un archivo de texto
void leerDesdeArchivo(struct alumno lista[], int n)
{
    FILE *archivo;
    archivo = fopen("alumnos.txt", "r");

    if (archivo == NULL)
    {
        printf("No se encontró el archivo. Creando uno nuevo.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(archivo, "%d", &lista[i].matricula);
        fgets(lista[i].nombre, sizeof(lista[i].nombre), archivo);
        fgets(lista[i].direccion, sizeof(lista[i].direccion), archivo);
        fgets(lista[i].materia, sizeof(lista[i].materia), archivo);
        fscanf(archivo, "%f", &lista[i].nota);
    }

    fclose(archivo);
    printf("Datos cargados desde el archivo correctamente.\n");
}