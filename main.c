/*


#include <stdio.h>

// Funciones del sistema
void entradaDatos();
void calcularNotasMedias();
void visualizarDatos();
void modificarEliminarDatos();

int main() {
    int opcion = 0;
    while (opcion != 5) {
        printf("Menu de opciones\n");
        printf("1. Entrada de datos\n");
        printf("2. Calcular notas medias\n");
        printf("3. Visualizar datos\n");
        printf("4. Modificar y eliminar datos\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                entradaDatos();
                break;
            case 2:
                calcularNotasMedias();
                break;
            case 3:
                visualizarDatos();
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












struct alumno {
    char dni[10];
    char nombre[50];
    char apellidos[100];
    int curso;
    char email[50];
    float asig1;
    float asig2;
    float asig3;
    float asig4;
    float asig5;
};

void entradaDatos() {
    int numAlumnos;
    printf("Introduce el numero de alumnos: ");
    scanf("%d", &numAlumnos);
    struct alumno alumnos[numAlumnos];
    for (int i = 0; i < numAlumnos; i++) {
        printf("Introduce el DNI del alumno %d: ", i+1);
        scanf("%s", alumnos[i].dni);
        printf("Introduce el nombre del alumno %d: ", i+1);
        scanf("%s", alumnos[i].nombre);
        printf("Introduce los apellidos del alumno %d: ", i+1);
        scanf("%s", alumnos[i].apellidos);
        printf("Introduce el curso del alumno %d: ", i+1);
        scanf("%d", &alumnos[i].curso);
        printf("Introduce el email del alumno %d: ", i+1);
        scanf("%s", alumnos[i].email);
        printf("Introduce la nota de la asignatura 1 del alumno %d: ", i+1);
        scanf("%f", &alumnos[i].asig1);
        printf("Introduce la nota de la asignatura 2 del alumno %d: ", i+1);
        scanf("%f", &alumnos[i].asig2);
        printf("Introduce la nota de la asignatura 3 del alumno %d: ", i+1);
        scanf("%f", &alumnos[i].asig3);
        printf("Introduce la nota de la asignatura 4 del alumno %d: ", i+1);
        scanf("%f", &alumnos[i].asig4);
        printf("Introduce la nota de la asignatura 5 del alumno %d: ", i+1);
        scanf("%f", &alumnos[i].asig5);
    }
    // Aquí podrías incluir código para ordenar los datos de los alumnos o para guardarlos en un fichero
}



void guardarDatos(struct alumno alumnos[], int numAlumnos) {
    FILE *fp;
    fp = fopen("alumnos.txt", "w");
    for (int i = 0; i < numAlumnos; i++) {
        fprintf(fp, "%s,%s,%s,%d,%s,%f,%f,%f,%f,%f\n", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].curso, alumnos[i].email, alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
    }
    fclose(fp);
    printf("Los datos de los alumnos se han guardado en el archivo alumnos.txt\n");
}




*/
// hacer una funcion que pida al usuario un numero#
#include <stdio.h>
#include <string.h>
#include "funciones.h"