/*
// Funciones del sistema
void entradaDatos();
void calcularNotasMedias();
void visualizarDatos();
void modificarEliminarDatos();
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Booleanos
#include <stdlib.h>
// #include "funciones.h"

int numAlumnos = 100;
int masEntradas = 0;
int seguir = 1;
const char *datos = "datos.txt";

typedef struct alumno
{
    char dni[200];
    char nombre[200];
    char apellidos[200];
    int curso;
    char email[200];
    float asig1, asig2, asig3, asig4, asig5;
} alumno;

void cargarDatosDeArchivo(struct alumno alumnos[], int *numAlumnos)
{
    numAlumnos;
    FILE *archivo = fopen("datos.txt", "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }
    fscanf(archivo, "%d", numAlumnos);
    for (int i = 0; i < *numAlumnos; i++)
    {
        fscanf(archivo, "%s %s %s %d %s %f %f %f %f %f", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, &alumnos[i].curso, alumnos[i].email, &alumnos[i].asig1, &alumnos[i].asig2, &alumnos[i].asig3, &alumnos[i].asig4, &alumnos[i].asig5);
    }
    fclose(archivo);
}

void seleccionarArchivo()
{

    int opcion;
    printf("Selecciona el archivo de alumnos que deseas utilizar:\n");
    printf("1.datos predeterminados\n");
    printf("2.datos usuario\n");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:

        numAlumnos = 100;
        break;
    case 2:
        numAlumnos = 0;
        break;
    default:
        printf("Opcion no valida.\n");
    }
}

// void guardarDatos(struct alumno alumnos[], int numAlumnos)
// {

//     FILE *fp;
//     fp = fopen("datos.txt", "w");
//     for (int i = 0; i < numAlumnos; i++)
//     {
//         fprintf(fp, "%s,%s,%s,%d,%s,%f,%f,%f,%f,%f\n", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].curso, alumnos[i].email, alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
//     }
//     fclose(fp);
//     printf("Los datos de los alumnos se han guardado en el archivo datos.txt\n");
// }

void agregarEntradas(struct alumno alumnos[], int masEntradas)
{

    FILE *datos = fopen("/datos.txt", "a");
    if (datos == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    for (int i = numAlumnos; i < numAlumnos + masEntradas; i++)
    {
        printf("Ingrese el DNI del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].dni);
        printf("Ingrese el nombre del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].nombre);
        printf("Ingrese el apellido del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].apellidos);
        printf("Ingrese el curso %d: ", i + 1);
        scanf("%d", &alumnos[i].curso);
        printf("Ingrese el email del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].email);
        printf("Ingrese las 5 notas del alumno %d: ", i + 1);
        scanf("%f %f %f %f %f", &alumnos[i].asig1, &alumnos[i].asig2, &alumnos[i].asig3, &alumnos[i].asig4, &alumnos[i].asig5);

        // Escribir en archivo
        fprintf(datos, "%s,%s,%s,%d,%s,%.1f,%.1f,%.1f,%.1f,%.1f\n", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].curso, alumnos[i].email, alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
    }
    numAlumnos += masEntradas;
    fclose(datos);
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
    FILE *datos = fopen("datos.txt", "a");
    if (datos == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }
    for (int i = 0; i < numAlumnos; i++)
    {
        fscanf(datos, "%s %s %s %d %s %f %f %f %f %f", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, &alumnos[i].curso, alumnos[i].email, &alumnos[i].asig1, &alumnos[i].asig2, &alumnos[i].asig3, &alumnos[i].asig4, &alumnos[i].asig5);
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
    fclose(datos);
}
void visualizar_datos()
{
    int character_read;
    int w = 0, l = 0, c, contador = 0;
    FILE *fp;
    fp = fopen("datos.txt", "r");

    alumno alumnos[500];
    fp = fopen("datos.txt", "r");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo datos.txt\n");
        return;
    }
    printf("\n");
    while (fscanf(fp, "%s|%c|%c|%d|%s|%f|%f|%f|%f|%f\n", alumnos[contador].dni, alumnos[contador].nombre, alumnos[contador].apellidos, &alumnos[contador].curso, alumnos[contador].email, &alumnos[contador].asig1, &alumnos[contador].asig2, &alumnos[contador].asig3, &alumnos[contador].asig4, &alumnos[contador].asig5) != EOF)
    {

        printf("test %s\n", alumnos[contador].apellidos);

        contador++;
    }
    while ((character_read = fgetc(fp)) != EOF) // checking if the end of the file
    {
        // One character was read
        c++;
        // Check if it is a separator char (count another word)
        if (character_read == ' ' || character_read == '\n' || character_read == '\t')

        {
            w++;
        }
        // Check if it was a newline (count a new line)
        if (character_read == '\n')
            l++;
    }
    printf("_________________\n");
    printf("%d", contador);
    printf("_________________\n");
    printf("The number of lines is: %d\n", l);
    printf("The number of words is: %d\n", w);
    printf("The number of characters is: %d\n", c);
    fclose(fp);
    int opcion = 1;
    while (opcion != 6)
    {
        printf("1. Ver datos de todos los alumnos\n");
        printf("2. Ver datos de un alumno específico\n");
        printf("3. Ver asignaturas de un curso\n");
        printf("4. Ver notas de una asignatura\n");
        printf("5. Ver notas medias de un curso\n");
        printf("6. Salir\n");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            for (int i = 0; i < numAlumnos; i++)
            {
                printf("DNI: %s\n", alumnos[i].dni);
                printf("Nombre: %s\n", alumnos[i].nombre);
                printf("Apellidos: %s\n", alumnos[i].apellidos);
                printf("Curso: %d\n", alumnos[i].curso);
                printf("Email: %s\n", alumnos[i].email);
                printf("Notas: %f %f %f %f %f\n", alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
            }
        }
        if (opcion == 2)
        {
            char dni[10];
            printf("Introduce el DNI del alumno: ");
            scanf("%s", dni);
            for (int i = 0; i < numAlumnos; i++)
            {
                if (strcmp(alumnos[i].dni, dni) == 0)
                {
                    printf("DNI: %s\n", alumnos[i].dni);
                    printf("Nombre: %s\n", alumnos[i].nombre);
                    printf("Apellidos: %s\n", alumnos[i].apellidos);
                    printf("Curso: %d\n", alumnos[i].curso);
                    printf("Email: %s\n", alumnos[i].email);
                    printf("Notas: %f %f %f %f %f\n", alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
                    break;
                }
            }
        }
        if (opcion == 3)
        {
            int curso;
            printf("Introduce el curso: ");
            scanf("%d", &curso);
            for (int i = 0; i < numAlumnos; i++)
            {
                if (alumnos[i].curso == curso)
                {
                    printf("%s %s\n", alumnos[i].nombre, alumnos[i].apellidos);
                }
            }
        }
        if (opcion == 4)
        {
            int asignatura;
            printf("Introduce la asignatura: ");
            scanf("%d", &asignatura);
            for (int i = 0; i < numAlumnos; i++)
            {
                if (asignatura == 2)
                    printf("%s %s: %f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig2);
                if (asignatura == 3)
                    printf("%s %s: %f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig3);
                if (asignatura == 4)
                    printf("%s %s: %f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig4);
                if (asignatura == 5)
                    printf("%s %s: %f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig5);
            }
        }
        if (opcion == 5)
        {
            int curso;
            printf("Introduce el curso: ");
            scanf("%d", &curso);
            float notas_curso[numAlumnos][5];
            int contador = 0;
            for (int i = 0; i < numAlumnos; i++)
            {
                if (alumnos[i].curso == curso)
                {
                    notas_curso[contador][0] = alumnos[i].asig1;
                    notas_curso[contador][1] = alumnos[i].asig2;
                    notas_curso[contador][2] = alumnos[i].asig3;
                    notas_curso[contador][3] = alumnos[i].asig4;
                    notas_curso[contador][4] = alumnos[i].asig5;
                    contador++;
                }
            }
            float notas_medias[contador];
            float media_curso = 0;
            for (int i = 0; i < contador; i++)
            {
                notas_medias[i] = (notas_curso[i][0] + notas_curso[i][1] + notas_curso[i][2] + notas_curso[i][3] + notas_curso[i][4]) / 5;
                printf("Nota media del alumno %d: %f\n", i + 1, notas_medias[i]);
                media_curso += notas_medias[i];
            }
            printf("Nota media del curso: %f\n", media_curso / contador);
        }
        if (opcion == 6)
        {
            printf("Saliendo del programa...\n");
            break;
        }
    }
}

void menuOpciones(const char *datos, alumno *alumnos)
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
            printf("Ingrese el numero de entradas a añadir: ");
            scanf("%d", &masEntradas);
            // printf("entradas_____%d ", masEntradas);

            agregarEntradas(alumnos, numAlumnos);
            numAlumnos = numAlumnos + masEntradas;
            masEntradas = 0;
            break;
        case 2:
            calcularNotasMedias(alumnos, numAlumnos);
            break;
        case 3:
            visualizar_datos();
            break;
        case 4:
            // modificarEliminarDatos(alumnos, numAlumnos);
            break;
        case 5:
            printf("Saliendo del sistema...\n");
            break;
        default:
            printf("Opcion incorrecta. Por favor, seleccione una opcion valida.\n");
        }
    }
}

int main()
{
    alumno alumnos[numAlumnos];
    seleccionarArchivo();

    while (seguir)
    {
        printf("¿Desea continuar en el programa? (1: Si / 0: No) : ");
        scanf("%d", &seguir);
        if (seguir)
            menuOpciones(datos, alumnos);
    }

    // cargarDatosDeArchivo(alumnos, &numAlumnos);
    // visualizarDatos(alumnos, numAlumnos);

    return 0;
}
