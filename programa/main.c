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

#include "cabecera.h"



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
