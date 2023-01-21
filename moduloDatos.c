#include "moduloDatos.h"

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
