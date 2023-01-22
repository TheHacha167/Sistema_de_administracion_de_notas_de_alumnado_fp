#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cabecera.h"
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
