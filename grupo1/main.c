/*
// Funciones del sistema
void entradaDatos();
void calcularNotasMedias();
void visualizarDatos();
void modificarEliminarDatos();
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cabecera.h"
int seguir = 0;
int main(void)
{
    alumno alumnos[numAlumnos];

    while (seguir)
    {
        printf("¿Desea continuar en el programa? (1: Si / 0: No) : ");
        scanf("%d", &seguir);
        if (seguir)
            menuOpciones(datos, alumnos);
    }

    return 0;
}