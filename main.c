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
// #include "funciones.h"

int numAlumnos = 100;
int masEntradas = 0;
int seguir = 1;
const char *datos = "datos.txt";

typedef struct alumno
{
    char dni[10];
    char nombre[30];
    char apellidos[50];
    int curso;
    char email[40];
    float asig1, asig2, asig3, asig4, asig5;
} alumno;

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
/*
void visualizarDatos(struct alumno alumnos[], int numAlumnos)
{
    int opcion = 0;
    char dni[9];
    int curso;
    int asignatura2 = 0;
    int curso2;


    while (opcion != 6)
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
*/
/*
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
        guardarDatos(alumnos, numAlumnos); // para guardar los datos de los alumnos
        char respuesta[10];
        printf("Desea introducir mas alumnos? (S/N): ");
        scanf("%s", respuesta);
        if (strcmp(respuesta, "N") == 0 || strcmp(respuesta, "n") == 0)
        {
            continuar = false;
            // menuOpciones();
        }
    }
}*/
/*
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
*/
/*
void pedirDatosAlumnos(const char *archivoSeleccionado, int numAlumnos, alumno *alumnos)
{
    printf("____________________\n");
    printf("funcioon pedir datos\n");
    printf("____________________\n");

    int i = 0;
    FILE *archivo = fopen(archivoSeleccionado, "r");
    printf("____________________\n");
    printf("lee los datos\n");
    printf("____________________\n");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
    }
    else
    {
        while (!EOF && i < numAlumnos)
        {
            printf("____________________\n");
            printf(" while funcioon pedir datos\n");
            printf("____________________\n");
            fscanf(archivo, "%s,%s,%s,%d,%s,%f,%f,%f,%f,%f", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, &alumnos[i].curso, alumnos[i].email, &alumnos[i].asig1, &alumnos[i].asig2, &alumnos[i].asig3, &alumnos[i].asig4, &alumnos[i].asig5);
            i++;
        }


    }
    fclose(archivo);
}
*/
/*
void agregarEntradas(int numAlumnos, int masEntradas)
{
    struct alumno alumnos[numAlumnos];
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
        printf("Ingrese lel curso %d: ", i + 1);
        scanf("%d", &alumnos[i].curso);
        printf("Ingrese el email del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].email);
        printf("Ingrese las 5 notas del alumno %d: ", i + 1);
        scanf("%f %f %f %f %f", &alumnos[i].asig1, &alumnos[i].asig2, &alumnos[i].asig3, &alumnos[i].asig4, &alumnos[i].asig5);
        fprintf(datos, "%s,%s,%s,%d,%s,%f,%f,%f,%f,%f\n", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].curso, alumnos[i].email, alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
    }

    fclose(datos);
}
*/
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
void mostrarDatosAlumnos(int numAlumnos, const char *datos)
{
    printf("____________________\n");
    printf("funcioon pedir datos\n");
    printf("____________________\n");
    struct alumno alumnos[numAlumnos];
    FILE *archivo = fopen(datos, "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
    }
    else
    {
        printf("____________________\n");
        printf(" else funcioon pedir datos\n");
        printf("____________________\n");
        for (int i = 0; i < numAlumnos; i++)
        {
            // LEER ARCHIVO TXT ERROR
            fscanf(archivo, "%s %s %s %d %s %f %f %f %f %f", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].curso, alumnos[i].email, &alumnos[i].asig1, &alumnos[i].asig2, &alumnos[i].asig3, &alumnos[i].asig4, &alumnos[i].asig5);
            printf("%s,%s,%s,%d,%s,%.1f,%.1f,%.1f,%.1f,%.1f\n", alumnos[i].dni, alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].curso, alumnos[i].email, alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
        }
    }
    fclose(archivo);
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

#include <stdio.h>


void visualizar_datos(){
    char dni[10];
    FILE *fp;
    fp=fopen("datos.txt", "r");
    alumno alumnos[100];
    while(fscanf(fp, "%s %s %s %d %s %f %f %f %f %f", alumnos[numAlumnos].dni, alumnos[numAlumnos].nombre, alumnos[numAlumnos].apellidos, &alumnos[numAlumnos].curso, alumnos[numAlumnos].email, &alumnos[numAlumnos].asig1, &alumnos[numAlumnos].asig2, &alumnos[numAlumnos].asig3, &alumnos[numAlumnos].asig4, &alumnos[numAlumnos].asig5) != EOF) {
      numAlumnos++;
    }
    fclose(fp);
    int opcion=1;
    while(opcion!=6){
        printf("1. Ver datos de todos los alumnos\n");
        printf("2. Ver datos de un alumno específico\n");
        printf("3. Ver asignaturas de un curso\n");
        printf("4. Ver notas de una asignatura\n");
        printf("5. Ver notas medias de un curso\n");
        printf("6. Salir\n");
        scanf("%d", &opcion);
        if(opcion==1){
            for(int i=0; i<numAlumnos; i++) {
                printf("DNI: %s\n", alumnos[i].dni);
                printf("Nombre: %s\n", alumnos[i].nombre);
                printf("Apellidos: %s\n", alumnos[i].apellidos);
                printf("Curso: %d\n", alumnos[i].curso);
                printf("Email: %s\n", alumnos[i].email);
                printf("Notas: %f %f %f %f %f\n", alumnos[i].asig1, alumnos[i].asig2, alumnos[i].asig3, alumnos[i].asig4, alumnos[i].asig5);
            }
        }
        if(opcion==2){
            printf("Introduce el DNI del alumno: ");
            scanf("%s", &dni);
            for(int i=0; i<numAlumnos; i++) {
                if(strcmp(alumnos[i].dni, dni)==0){
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
        if(opcion==3){
            printf("Introduce el curso: ");
            scanf("%d", &dni);
            for(int i=0; i<numAlumnos; i++) {
                if(alumnos[i].curso == dni){
                    printf("%s %s\n", alumnos[i].nombre, alumnos[i].apellidos);
                }
            }
        }
        if(opcion==4){
            printf("Introduce la asignatura: ");
            scanf("%d", &dni);
            for(int i=0; i<numAlumnos; i++) {
                if(dni==1) printf("%s %s: %f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig1);
                if(dni==2) printf("%s %s: %f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig2);
                if(dni==3) printf("%s %s: %f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig3);
                if(dni==4) printf("%s %s: %f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig4);
                if(dni==5) printf("%s %s: %f\n", alumnos[i].nombre, alumnos[i].apellidos, alumnos[i].asig5);
            }
        }
        if(opcion==5){
                        printf("Introduce el curso: ");
            scanf("%d", &dni);
            float notas_curso[numAlumnos][5];
            int contador = 0;
            for(int i=0; i<numAlumnos; i++) {
                if(alumnos[i].curso == dni){
                    notas_curso[contador][0] = alumnos[i].asig1;
                    notas_curso[contador][1] = alumnos[i].asig2;
                    notas_curso[contador][2] = alumnos[i].asig3;
                    notas_curso[contador][3] = alumnos[i].asig4;
                    notas_curso[contador][4] = alumnos[i].asig5;
                    contador++;
                }
            }
            float notas_medias[contador];
            float media_curso=0;
            for(int i=0; i<contador; i++) {
                notas_medias[i] = (notas_curso[i][0] + notas_curso[i][1] + notas_curso[i][2] + notas_curso[i][3] + notas_curso[i][4])/5;
                printf("Nota media del alumno %d: %f\n", i+1, notas_medias[i]);
                media_curso += notas_medias[i];
            }
            printf("Nota media del curso: %f\n", media_curso/contador);
        }
        if(opcion==6){
            printf("Saliendo del programa...\n");
            break;
        }
    }
}


/*void modificarEliminarAlumno(struct alumno alumnos[], int *numAlumnos) {
    int dni;
    int index = -1;
    int opcion;
    printf("Introduce el DNI del alumno a modificar o eliminar: ");
    scanf("%d", &dni);
    for (int i = 0; i < *numAlumnos; i++) {
        if (alumnos[i].dni == dni) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("No se ha encontrado ningún alumno con ese DNI\n");
        return;
    }
    printf("¿Qué deseas hacer con el alumno?\n1. Modificar\n2. Eliminar\n");
    scanf("%d", &opcion);
    switch (opcion) {
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
            for (int i = index; i < *numAlumnos - 1; i++) {
                alumnos[i] = alumnos[i + 1];
            }
            (*numAlumnos)--;
            printf("El alumno ha sido eliminado\n");
            break;
        default:
            printf("Opción no válida\n");
    }
}
*/

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
