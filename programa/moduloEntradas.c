#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cabecera.h"
void entradaDatos()
{
    int Alumnos;
    bool continuar = true;
    while (continuar)
    {
        printf("Introduce el numero de alumnos: ");
        scanf("%d", &Alumnos);
        struct alumno alumnos[Alumnos];
        for (int i = 0; i < Alumnos; i++)
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
    }
}

void agregarEntradas(struct alumno alumnos[], int masEntradas)
{

    FILE *datos = fopen("datos.txt", "a");
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
        fprintf(datos, "%s,%s,%s,%d,%s,%.1f,%.1f,%.1f,%.1f,%.1f\n", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].curso, alumnos[i].email, alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
    }
    numAlumnos += masEntradas;
    fclose(datos);
}