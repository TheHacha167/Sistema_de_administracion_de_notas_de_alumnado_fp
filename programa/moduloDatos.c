#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cabecera.h"

void cargarDatosDeArchivo(struct alumno alumnos[], int *numAlumnos)
{
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

void guardarDatos(struct alumno alumnos[], int numAlumnos)
{

    FILE *fp;
    fp = fopen("datos", "w");
    for (int i = 0; i < numAlumnos; i++)
    {
        fprintf(fp, "%s,%s,%s,%d,%s,%f,%f,%f,%f,%f\n", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].curso, alumnos[i].email, alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
    }
    fclose(fp);
    printf("Los datos de los alumnos se han guardado en el archivo datos.txt\n");
}

void modificarEliminarAlumno(struct alumno alumnos[], int *numAlumnos)
{
    int dni;
    int index = -1;
    int opcion;
    printf("Introduce el DNI del alumno a modificar o eliminar: ");
    scanf("%d", &dni);
    for (int i = 0; i < *numAlumnos; i++)
    {
        if (alumnos[i].dni == dni)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("No se ha encontrado ningún alumno con ese DNI\n");
        return;
    }
    printf("¿Qué deseas hacer con el alumno?\n1. Modificar\n2. Eliminar\n");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        printf("Introduce el nuevo nombre del alumno: ");
        scanf("%s", alumnos[index].nombre);
        printf("Introduce los nuevos apellidos del alumno: ");
        scanf("%s", alumnos[index].apellidos);
        printf("Introduce el nuevo curso del alumno: ");
        scanf("%s", alumnos[index].curso);
        printf("Introduce el nuevo email del alumno: ");
        scanf("%s", alumnos[index].email);
        printf("Introduce la nueva nota de la asignatura 1: ");
        scanf("%f", &alumnos[index].asig1);
        printf("Introduce la nueva nota de la asignatura 2: ");
        scanf("%f", &alumnos[index].asig2);
        printf("Introduce la nueva nota de la asignatura 3: ");
        scanf("%f", &alumnos[index].asig3);
        printf("Introduce la nueva nota de la asignatura 4: ");
        scanf("%f", &alumnos[index].asig4);
        printf("Introduce la nueva nota de la asignatura 5: ");
        scanf("%f", &alumnos[index].asig5);
        printf("Los datos del alumno han sido actualizados\n");
        break;
    case 2:
        for (int i = index; i < *numAlumnos - 1; i++)
        {
            alumnos[i] = alumnos[i + 1];
        }
        (*numAlumnos)--;
        printf("El alumno ha sido eliminado\n");
        break;
    default:
        printf("Opción no válida\n");
    }
}
void visualizar_datos()
{
    int character_read;
    int w = 0, l = 0, c, contador = 0;
    FILE *fp;
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

       printf("test %s\n", alumnos[contador].dni);

        contador++;


   }/*
for (size_t i = 0; i < contador; i++)
{
  // printf(" test %s\n", alumnos[contador].dni);
}
*/ 


    while ((character_read = fgetc(fp)) != EOF) // checking if the end of the file
    {
        // One character was read
        c++;
        // Check if it is a separator char (count another word)
        if (character_read == '|' || character_read == '\n' || character_read == '\t')

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

