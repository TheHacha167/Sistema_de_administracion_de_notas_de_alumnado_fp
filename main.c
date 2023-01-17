/*

// Funciones del sistema
void entradaDatos();
void calcularNotasMedias();
void visualizarDatos();
void modificarEliminarDatos();


*/
// hacer una funcion que pida al usuario un numero#
#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Booleanos
#include "funciones.h"

const char *ARCHIVO_A = "alumnos.txt";
const char *ARCHIVO_B = "usuario.txt";
const char *archivoSeleccionado;
int numAlumnos = 100;

struct alumno
{
    char dni[10];
    char nombre[30];
    char apellidos[50];
    int curso;
    char email[40];
    float asig1, asig2, asig3, asig4, asig5;
};

void seleccionarArchivo()
{
    int opcion;
    printf("Selecciona el archivo de alumnos que deseas utilizar:\n");
    printf("1.datos predeterminados %s\n", ARCHIVO_A);
    printf("2.datos usuario %s\n", ARCHIVO_B);
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        archivoSeleccionado = ARCHIVO_A;
        numAlumnos = 100;
        break;
    case 2:
        archivoSeleccionado = ARCHIVO_B;
        numAlumnos = 0;
        break;
    default:
        printf("Opcion no valida.\n");
    }
}

void entradaDatos()
{
    int numAlumnos;
    printf("Introduce el numero de alumnos: ");
    scanf("%d", &numAlumnos);
    struct alumno alumnos[numAlumnos];
    for (int i = 0; i < numAlumnos; i++)
    {
        printf("Introduce el DNI del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].dni);
        printf("Introduce el nombre del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].nombre);
        printf("Introduce los apellidos del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].apellidos);
        printf("Introduce el curso del alumno %d: ", i + 1);
        scanf("%d", alumnos[i].curso);
        printf("Introduce el email del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].email);
        printf("Introduce la nota de la asignatura 1 del alumno %d: ", i + 1);
        scanf("%f", &alumnos[i].asig1);
        printf("Introduce la nota de la asignatura 2 del alumno %d: ", i + 1);
        scanf("%f", &alumnos[i].asig2);
        printf("Introduce la nota de la asignatura 3 del alumno %d: ", i + 1);
        scanf("%f", &alumnos[i].asig3);
        printf("Introduce la nota de la asignatura 4 del alumno %d: ", i + 1);
        scanf("%f", &alumnos[i].asig4);
        printf("Introduce la nota de la asignatura 5 del alumno %d: ", i + 1);
        scanf("%f", &alumnos[i].asig5);
    }
}

void guardarDatos(struct alumno alumnos[], int numAlumnos)
{

    FILE *fp;
    fp = fopen("archivoSeleccionado", "w");
    for (int i = 0; i < numAlumnos; i++)
    {
        fprintf(fp, "%s,%s,%s,%d,%s,%f,%f,%f,%f,%f\n", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].curso, alumnos[i].email, alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
    }
    fclose(fp);
    printf("Los datos de los alumnos se han guardado en el archivo alumnos.txt\n");
}

void visualizarDatos(struct alumno alumnos[], int numAlumnos)
{
    int opcion = 0;
    while (opcion != 7)
    {
        printf("Menu de opciones de visualizacion de datos\n");
        printf("1. Ver datos de todos los alumnos\n");
        printf("2. Ver datos de un alumno especifico\n");
        printf("3. Ver asignaturas de un curso\n");
        printf("4. Ver notas de una asignatura\n");
        printf("5. Ver notas medias de un curso\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < numAlumnos; i++)
            {
                printf("DNI: %s\n", alumnos[i].dni);
                printf("Nombre: %s\n", alumnos[i].nombre);
                printf("Apellidos: %s\n", alumnos[i].apellidos);
                printf("Curso: %d\n", alumnos[i].curso);
                printf("Email: %s\n", alumnos[i].email);
                printf("Nota asignatura 1: %.2f\n", alumnos[i].asig1);
                printf("Nota asignatura 2: %.2f\n", alumnos[i].asig2);
                printf("Nota asignatura 3: %.2f\n", alumnos[i].asig3);
                printf("Nota asignatura 4: %.2f\n", alumnos[i].asig4);
                printf("Nota asignatura 5: %.2f\n", alumnos[i].asig5);
                printf("Media: %.2f\n", (alumnos[i].asig1 + alumnos[i].asig2 + alumnos[i].asig3 + alumnos[i].asig4 + alumnos[i].asig5) / 5);
            }
            break;
        case 2:
            char dni[9];
            printf("Ingrese el DNI del alumno: ");
            scanf("%s", dni);
            int alumnoEncontrado = 0;
            for (int i = 0; i < numAlumnos; i++)
            {
                if (strcmp(alumnos[i].dni, dni) == 0)
                {
                    printf("DNI: %s\n", alumnos[i].dni);
                    printf("Nombre: %s\n", alumnos[i].nombre);
                    printf("Apellidos: %s\n", alumnos[i].apellidos);
                    printf("Curso: %d\n", alumnos[i].curso);
                    printf("Email: %s\n", alumnos[i].email);
                    printf("Nota asignatura 1: %.2f\n", alumnos[i].asig1);
                    printf("Nota asignatura 2: %.2f\n", alumnos[i].asig2);
                    printf("Nota asignatura 3: %.2f\n", alumnos[i].asig3);
                    printf("Nota asignatura 4: %.2f\n", alumnos[i].asig4);
                    printf("Nota asignatura 5: %.2f\n", alumnos[i].asig5);
                    printf("Media: %.2f\n", (alumnos[i].asig1 + alumnos[i].asig2 + alumnos[i].asig3 + alumnos[i].asig4 + alumnos[i].asig5) / 5);
                    alumnoEncontrado = 1;
                    break;
                }
            }
            if (!alumnoEncontrado)
            {
                printf("Alumno no encontrado\n");
            }
            break;
        case 3:
            int curso;
            printf("Ingrese el curso: ");
            scanf("%d", &curso);
            for (int i = 0; i < numAlumnos; i++)
            {
                if (alumnos[i].curso == curso)
                {
                    printf("Asignatura 1: %.2f\n", alumnos[i].asig1);
                    printf("Asignatura 2: %.2f\n", alumnos[i].asig2);
                    printf("Asignatura 3: %.2f\n", alumnos[i].asig3);
                    printf("Asignatura 4: %.2f\n", alumnos[i].asig4);
                    printf("Asignatura 5: %.2f\n", alumnos[i].asig5);
                    printf("Nota media: %.2f\n", (alumnos[i].asig1 + alumnos[i].asig2 + alumnos[i].asig3 + alumnos[i].asig4 + alumnos[i].asig5) / 5);
                    // Aqui se podria anadir el calculo para mostrar la nota mas alta y la mas baja de cada asignatura
                }
            }
            break;

        case 4:
            char asignatura2[20];
            printf("Ingrese la asignatura: 1,2,3,4,5 ");
            scanf("%s", asignatura2);

            if (asignatura2 == 1)
            {
                for (int i = 0; i < numAlumnos; i++)
                {

                    printf("%s %s - Nota: %.2f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig1);
                }
                break;
            }
            else
            {
                if (asignatura2 == 2)
                {
                    for (int i = 0; i < numAlumnos; i++)
                    {

                        printf("%s %s - Nota: %.2f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig2);
                    }
                    break;
                }
                else
                {
                    if (asignatura2 == 3)
                    {
                        for (int i = 0; i < numAlumnos; i++)
                        {

                            printf("%s %s - Nota: %.2f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig3);
                        }
                        break;
                    }
                    else
                    {
                        if (asignatura2 == 4)
                        {
                            for (int i = 0; i < numAlumnos; i++)
                            {

                                printf("%s %s - Nota: %.2f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig4);
                            }
                            break;
                        }
                        else
                        {
                            if (asignatura2 == 5)
                            {
                                for (int i = 0; i < numAlumnos; i++)
                                {

                                    printf("%s %s - Nota: %.2f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig5);
                                }
                                break;
                            }
                        }
                    }
                }
            }

        case 5:
            int curso2;
            printf("Ingrese el curso: ");
            scanf("%d", &curso2);
            for (int i = 0; i < numAlumnos; i++)
            {
                if (alumnos[i].curso == curso2)
                {
                    printf("%s %s - Nota media: %.2f\n", alumnos[i].nombre, alumnos[i].apellidos, (alumnos[i].asig1 + alumnos[i].asig2 + alumnos[i].asig3 + alumnos[i].asig4 + alumnos[i].asig5) / 5);
                }
            }
            break;
        case 6:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    }
}

void entradaDatos()
{
    int numAlumnos;
    bool continuar = true;
    while (continuar)
    {
        printf("Introduce el numero de alumnos: ");
        scanf("%d", &numAlumnos);
        struct alumno alumnos[numAlumnos];
        for (int i = 0; i < numAlumnos; i++)
        {
            printf("Introduce el DNI del alumno %d: ", i + 1);
            scanf("%s", alumnos[i].dni);
            printf("Introduce el nombre del alumno %d: ", i + 1);
            scanf("%s", alumnos[i].nombre);
            printf("Introduce los apellidos del alumno %d: ", i + 1);
            scanf("%s", alumnos[i].apellidos);
            printf("Introduce el curso del alumno %d: ", i + 1);
            scanf("%d", &alumnos[i].curso);
            printf("Introduce el email del alumno %d: ", i + 1);
            scanf("%s", alumnos[i].email);
            printf("Introduce la nota de la asignatura 1 del alumno %d: ", i + 1);
            scanf("%f", &alumnos[i].asig1);
            printf("Introduce la nota de la asignatura 2 del alumno %d: ", i + 1);
            scanf("%f", &alumnos[i].asig2);
            printf("Introduce la nota de la asignatura 3 del alumno %d: ", i + 1);
            scanf("%f", &alumnos[i].asig3);
            printf("Introduce la nota de la asignatura 4 del alumno %d: ", i + 1);
            scanf("%f", &alumnos[i].asig4);
            printf("Introduce la nota de la asignatura 5 del alumno %d: ", i + 1);
            scanf("%f", &alumnos[i].asig5);
        }
        guardarDatos(alumnos, numAlumnos); // para guardar los datos de los alumnos
        char respuesta[10];
        printf("Desea introducir mas alumnos? (S/N): ");
        scanf("%s", respuesta);
        if (strcmp(respuesta, "N") == 0 || strcmp(respuesta, "n") == 0)
        {
            continuar = false;
            menuOpciones();
        }
    }
}

void calcularNotasMedias(struct alumno alumnos[], int numAlumnos)
{
    float mediaAsig1 = 0;
    float mediaAsig2 = 0;
    float mediaAsig3 = 0;
    float mediaAsig4 = 0;
    float mediaAsig5 = 0;
    float notaMaxima = 0;
    float notaMinima = 100;
    FILE *archivo = fopen("archivoSeleccionado", "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }
    for (int i = 0; i < numAlumnos; i++)
    {
        fscanf(archivo, "%f %f %f %f %f", &alumnos[i].asig1, &alumnos[i].asig2, &alumnos[i].asig3, &alumnos[i].asig4, &alumnos[i].asig5);
        mediaAsig1 += alumnos[i].asig1;
        mediaAsig2 += alumnos[i].asig2;
        mediaAsig3 += alumnos[i].asig3;
        mediaAsig4 += alumnos[i].asig4;
        mediaAsig5 += alumnos[i].asig5;

        if (alumnos[i].asig1 > notaMaxima)
            notaMaxima = alumnos[i].asig1;
        if (alumnos[i].asig1 < notaMinima)
            notaMinima = alumnos[i].asig1;
    }
    mediaAsig1 /= numAlumnos;
    mediaAsig2 /= numAlumnos;
    mediaAsig3 /= numAlumnos;
    mediaAsig4 /= numAlumnos;
    mediaAsig5 /= numAlumnos;
    printf("Nota media asignatura 1: %.2f\n", mediaAsig1);
    printf("Nota media asignatura 2: %.2f\n", mediaAsig2);
    printf("Nota media asignatura 3: %.2f\n", mediaAsig3);
    printf("Nota media asignatura 4: %.2f\n", mediaAsig4);
    printf("Nota media asignatura 5: %.2f\n", mediaAsig5);
    printf("Nota maxima: %.2f\n", notaMaxima);
    printf("Nota minima: %.2f\n", notaMinima);
    fclose(archivo);
}

int menuOpciones()
{
    int opcion = 0;
    while (opcion != 5)
    {
        printf("Menu de opciones\n");
        printf("1. Entrada de datos\n");
        printf("2. Calcular notas medias\n");
        printf("3. Visualizar datos\n");
        printf("4. Modificar y eliminar datos\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            entradaDatos();
            break;
        case 2:
            calcularNotasMedias(alumno,numAlumnos);
            break;
        case 3:
            visualizarDatos(alumno[],numAlumnos);
            break;
        case 4:
            modificarEliminarDatos();
            break;
        case 5:
            printf("Saliendo del sistema...\n");
            break;
        default:
            printf("Opcion incorrecta. Por favor, seleccione una opcion valida.\n");
        }
    }
    return 0;
}
int main()
{
    seleccionarArchivo();
    menuOpciones();
}