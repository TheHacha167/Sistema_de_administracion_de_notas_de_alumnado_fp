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
char full_name[100];
char first_name[100]; // dni
char last_name1[100]; // nombre
char last_name2[100]; // apellido
char curso[100];      // curso
char email[100];      // email
char nota1[100];      // nota1
char nota2[100];      // nota2
char nota3[100];      // nota3
char nota4[100];      // nota4
char nota5[100];      // nota5
int i;
int start = 0; // Comienzo en la entrada 50
int count = 0; // Contador de entradas

struct student
{
    char dni[10];
    char nombre[100];
    char apellido[100];
    char curso[100];
    char email[100];
    float notas[5];
    float nota_media;
};
typedef struct alumno
{
    char dni[10];
    char nombre[30];
    char apellidos[50];
    int curso;
    char email[40];
    float asig1, asig2, asig3, asig4, asig5;
} alumno;
struct student students[1000];

void split_name(char *full_name, char *first_name, char *last_name1, char *last_name2, char *curso, char *email, char *nota1, char *nota2, char *nota3, char *nota4, char *nota5)
{
    char *token = strtok(full_name, "-");
    strcpy(first_name, token);
    token = strtok(NULL, "-");
    strcpy(last_name1, token);
    token = strtok(NULL, "-");
    strcpy(last_name2, token);
    token = strtok(NULL, "-");
    strcpy(curso, token);
    token = strtok(NULL, "-");
    strcpy(email, token);
    token = strtok(NULL, "-");
    strcpy(nota1, token);
    token = strtok(NULL, "-");
    strcpy(nota2, token);
    token = strtok(NULL, "-");
    strcpy(nota3, token);
    token = strtok(NULL, "-");
    strcpy(nota4, token);
    token = strtok(NULL, "-");
    strcpy(nota5, token);
}
//
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
// terminado
void agregarEntradas()
{

    FILE *file = fopen("datos.txt", "a");
    if (file == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    struct student new_student;
    printf("Ingrese el dni del estudiante: ");
    scanf("%s", new_student.dni);
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", new_student.nombre);
    printf("Ingrese el apellido del estudiante: ");
    scanf("%s", new_student.apellido);
    printf("Ingrese el curso del estudiante: ");
    scanf("%s", new_student.curso);
    printf("Ingrese el email del estudiante: ");
    scanf("%s", new_student.email);
    printf("Ingrese la primera nota del estudiante: ");
    scanf("%f", &new_student.notas[0]);
    printf("Ingrese la segunda nota del estudiante: ");
    scanf("%f", &new_student.notas[1]);
    printf("Ingrese la tercera nota del estudiante: ");
    scanf("%f", &new_student.notas[2]);
    printf("Ingrese la cuarta nota del estudiante: ");
    scanf("%f", &new_student.notas[3]);
    printf("Ingrese la quinta nota del estudiante: ");
    scanf("%f", &new_student.notas[4]);

    fprintf(file, "%s-%s-%s-%s-%s-%f-%f-%f-%f-%f-\n", new_student.dni, new_student.nombre, new_student.apellido, new_student.curso, new_student.email, new_student.notas[0], new_student.notas[1], new_student.notas[2], new_student.notas[3], new_student.notas[4]);
    fclose(file);
}

// terminado
int compare(const void *a, const void *b)
{
    struct student *studentA = (struct student *)a;
    struct student *studentB = (struct student *)b;
    return (studentB->nota_media - studentA->nota_media);
}
void calcularNotasMedias(int maximo_entradas)
{
    struct student students[100];
    char full_name[100];
    char course_to_search[100];
    int count = 0;
    float total_notas = 0;
    int i;
    FILE *file = fopen("datos.txt", "r");
    if (file == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    printf("Ingrese el curso a buscar: ");
    scanf("%s", course_to_search);
    while (fgets(full_name, 100, file) != NULL)
    {
        sscanf(full_name, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%f-%f-%f-%f-%f", students[count].dni, students[count].nombre, students[count].apellido, students[count].curso, students[count].email, &students[count].notas[0], &students[count].notas[1], &students[count].notas[2], &students[count].notas[3], &students[count].notas[4]);
        if (strcmp(students[count].curso, course_to_search) == 0)
        {
            for (i = 0; i < 5; i++)
            {
                total_notas += students[count].notas[i];
            }
            students[count].nota_media = total_notas / 5;
            count++;
        }
        total_notas = 0;
    }
    fclose(file);
    qsort(students, count, sizeof(struct student), compare);
    printf("Notas medias de los alumnos del curso %s (de mayor a menor):\n", course_to_search);
    for (i = 0; i < count; i++)
    {
        printf("%s %s: %f\n", students[i].nombre, students[i].apellido, students[i].nota_media);
    }
    return;
}

// acabada
void visualizar_datos(int maximo_entradas)

{
    int Max_Alumnos = 100;
    maximo_entradas = Max_Alumnos;
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

            FILE *file = fopen("datos.txt", "r");
            if (file == NULL)
            {
                printf("Error al abrir el archivo\n");
                return;
            }
            for (i = 0; i < Max_Alumnos; i++)
            {
                if (fgets(full_name, Max_Alumnos, file) == NULL)
                    return;
                if (count >= start)
                {
                    split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);
                    printf("dni: %s\n", first_name);
                    printf("nombre: %s\n", last_name1);
                    printf("apellido: %s\n", last_name2);
                    printf("curso: %s\n", curso);
                    printf("email: %s\n", email);
                    printf("nota1: %s\n", nota1);
                    printf("nota2: %s\n", nota2);
                    printf("nota3: %s\n", nota3);
                    printf("nota4: %s\n", nota4);
                    printf("nota5: %s\n", nota5);
                }
                count++;
            }
            fclose(file);
        }
        if (opcion == 2)
        {
            char name_to_search[Max_Alumnos];
            int found = 0;

            FILE *file = fopen("datos.txt", "r");
            if (file == NULL)
            {
                printf("Error al abrir el archivo\n");
                return;
            }
            printf("Ingrese el DNI: ");
            scanf("%s", name_to_search);
            while (fgets(full_name, Max_Alumnos, file) != NULL)
            {
                split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);
                if (strcmp(first_name, name_to_search) == 0)
                {
                    found = 1;
                    printf("dni: %s\n", first_name);
                    printf("nojmbre: %s\n", last_name1);
                    printf("apellido: %s\n", last_name2);
                    printf("curso: %s\n", curso);
                    printf("email: %s\n", email);
                    printf("nota1: %s\n", nota1);
                    printf("nota2: %s\n", nota2);
                    printf("nota3: %s\n", nota3);
                    printf("nota4: %s\n", nota4);
                    printf("nota5: %s\n", nota5);
                    return;
                }
            }
            fclose(file);
            if (!found)
                printf("Nombre no encontrado\n");
        }
        if (opcion == 3)
        {
            char name_to_search[Max_Alumnos];
            int found = 0;

            FILE *file = fopen("datos.txt", "r");
            if (file == NULL)
            {
                printf("Error al abrir el archivo\n");
                return;
            }
            printf("Ingrese el curso: ");
            scanf("%s", name_to_search);
            while (fgets(full_name, Max_Alumnos, file) != NULL)
            {
                split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);
                if (strcmp(curso, name_to_search) == 0)
                {
                    found = 1;
                    printf("dni: %s\n", first_name);
                    printf("nojmbre: %s\n", last_name1);
                    printf("apellido: %s\n", last_name2);
                    printf("curso: %s\n", curso);
                    printf("email: %s\n", email);
                    printf("nota1: %s\n", nota1);
                    printf("nota2: %s\n", nota2);
                    printf("nota3: %s\n", nota3);
                    printf("nota4: %s\n", nota4);
                    printf("nota5: %s\n", nota5);
                }
            }
            return;
            fclose(file);
            if (!found)
                printf("Curso no encontrado\n");
        }
        if (opcion == 4)
        {
            int name_to_search;
            int found = 0;

            FILE *file = fopen("datos.txt", "r");
            if (file == NULL)
            {
                printf("Error al abrir el archivo\n");
                return;
            }
            printf("Ingrese la asignatura(1-2-3-4-5): ");
            scanf("%d", &name_to_search);
            while (fgets(full_name, Max_Alumnos, file) != NULL)
            {
                if (name_to_search == 1)
                {
                    split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);

                    found = 1;

                    printf("dni: %s\n", first_name);
                    printf("nojmbre: %s\n", last_name1);
                    printf("apellido: %s\n", last_name2);
                    printf("curso: %s\n", curso);
                    printf("email: %s\n", email);
                    printf("nota1: %s\n", nota1);
                    printf("\n");
                }
                if (name_to_search == 2)
                {
                    split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);

                    found = 1;

                    printf("dni: %s\n", first_name);
                    printf("nojmbre: %s\n", last_name1);
                    printf("apellido: %s\n", last_name2);
                    printf("curso: %s\n", curso);
                    printf("email: %s\n", email);
                    printf("nota2: %s\n", nota2);
                    printf("\n");
                }
                if (name_to_search == 3)
                {
                    split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);

                    found = 1;

                    printf("dni: %s\n", first_name);
                    printf("nojmbre: %s\n", last_name1);
                    printf("apellido: %s\n", last_name2);
                    printf("curso: %s\n", curso);
                    printf("email: %s\n", email);
                    printf("nota3: %s\n", nota3);
                    printf("\n");
                }
                if (name_to_search == 4)
                {
                    split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);

                    found = 1;

                    printf("dni: %s\n", first_name);
                    printf("nojmbre: %s\n", last_name1);
                    printf("apellido: %s\n", last_name2);
                    printf("curso: %s\n", curso);
                    printf("email: %s\n", email);
                    printf("nota4: %s\n", nota4);
                    printf("\n");
                }
                if (name_to_search == 5)
                {
                    split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);

                    found = 1;

                    printf("dni: %s\n", first_name);
                    printf("nojmbre: %s\n", last_name1);
                    printf("apellido: %s\n", last_name2);
                    printf("curso: %s\n", curso);
                    printf("email: %s\n", email);
                    printf("nota5: %s\n", nota5);
                    printf("\n");
                }
            }
            return;
            fclose(file);
            if (!found)
                printf("Asignatura no encontrada\n");
        }
        if (opcion == 5)
        {

            char course_to_search[Max_Alumnos]; // Curso a buscar
            int found = 0;
            int count = 0;
            float total_notas = 0;
            FILE *file = fopen("datos.txt", "r");
            if (file == NULL)
            {
                printf("Error al abrir el archivo\n");
                return;
            }
            printf("Ingrese el curso a buscar: ");
            scanf("%s", course_to_search);
            while (fgets(full_name, Max_Alumnos, file) != NULL)
            {
                split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);
                if (strcmp(curso, course_to_search) == 0)
                {
                    found = 1;
                    count++;
                    total_notas += (atof(nota1) + atof(nota2) + atof(nota3) + atof(nota4) + atof(nota5)) / 5;
                }
            }
            if (found)
            {
                printf("Media de notas del curso %s: %f\n", course_to_search, total_notas / count);
            }
            else
            {
                printf("Curso no encontrado\n");
            }
            fclose(file);
            return;
        }
    }
    if (opcion == 6)
    {
        printf("Saliendo del programa...\n");
        return;
    }
}
/*
void modificarEliminarDatos()
{
    int Max_Alumnos = 100;
    char name_to_search[Max_Alumnos];
    int found = 0;
    int num = 0;
    int contador = 0;

    FILE *file = fopen("datos.txt", "r+");
    if (file == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }
    printf("Ingrese el DNI: ");
    scanf("%s", name_to_search);

    char full_name[Max_Alumnos], first_name[Max_Alumnos], last_name1[Max_Alumnos], last_name2[Max_Alumnos], curso[Max_Alumnos], email[Max_Alumnos], nota1[Max_Alumnos], nota2[Max_Alumnos], nota3[Max_Alumnos], nota4[Max_Alumnos], nota5[Max_Alumnos];
    while (fgets(full_name, Max_Alumnos, file) != NULL)
    {
        split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);
        if (strcmp(first_name, name_to_search) == 0)
        {
            found = 1;
            printf("1-dni: %s\n", first_name);
            printf("2-nojmbre: %s\n", last_name1);
            printf("3-apellido: %s\n", last_name2);
            printf("4-curso: %s\n", curso);
            printf("5-email: %s\n", email);
            printf("6-nota1: %s\n", nota1);
            printf("7-nota2: %s\n", nota2);
            printf("8-nota3: %s\n", nota3);
            printf("9-nota4: %s\n", nota4);
            printf("10-nota5: %s\n", nota5);
            printf("\n");
            printf("Cual quiere modificar, marque del (1-10): ");
            scanf("%d", &num);
            if (num == 1)
            {
                printf("Ingrese el nuevo dni: ");
                scanf("%s", first_name);
            }
            else if (num == 2)
            {
                printf("Ingrese el nuevo nombre: ");
                scanf("%s", last_name1);
            }
            else if (num == 3)
            {
                printf("Ingrese el nuevo apellido: ");
                scanf("%s", last_name2);
            }
            else if (num == 4)
            {
                printf("Ingrese el nuevo curso: ");
                scanf("%s", curso);
            }
            else if (num == 5)
            {
                printf("Ingrese el nuevo email: ");
                scanf("%s", email);
            }
            else if (num == 6)
            {
                printf("Ingrese la nueva nota 1: ");
                scanf("%s", nota1);
            }
            else if (num == 7)
            {
                printf("Ingrese la nueva nota 2: ");
                scanf("%s", nota2);
            }
            else if (num == 8)
            {
                printf("Ingrese la nueva nota 3: ");
                scanf("%s", nota3);
            }
            else if (num == 9)
            {
                printf("Ingrese la nueva nota 4: ");
                scanf("%s", nota4);
            }
            else if (num == 10)
            {
                printf("Ingrese la nueva nota 5: ");
                scanf("%s", nota5);
            }
            else
            {
                printf("Opción no válida.\n");
                return;
            }

            // Mover el cursor al inicio de la línea correspondiente
            fseek(file, contador, SEEK_SET);

            // Escribir los cambios en el archivo
            char new_line[Max_Alumnos];
            sprintf(new_line, "%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-\n", first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);
            fwrite(new_line, sizeof(char), strlen(new_line), file);
            break;

            break;
        }
    }

    if (!found)
    {
        printf("No se ha encontrado al alumno con DNI %s\n", name_to_search);
    }
    fclose(file);
}
*/
void modificarEliminarDatos()
{
    int Max_Alumnos = 100;
    char name_to_search[Max_Alumnos];
    int found = 0;
    int num = 0;

    FILE *file = fopen("datos.txt", "r");
    if (file == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    // Crear archivo temporal
    FILE *temp = fopen("datos_temp.txt", "w");
    if (temp == NULL)
    {
        printf("Error al abrir el archivo temporal\n");
        return;
    }

    printf("Ingrese el DNI: ");
    scanf("%s", name_to_search);

    // char full_name[Max_Alumnos], first_name[Max_Alumnos], last_name1[Max_Alumnos], last_name2[Max_Alumnos], curso[Max_Alumnos], email[Max_Alumnos], nota1[Max_Alumnos], nota2[Max_Alumnos], nota3[Max_Alumnos], nota4[Max_Alumnos], nota5[Max_Alumnos];
    while (fgets(full_name, Max_Alumnos, file) != NULL)
    {
        split_name(full_name, first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);
        if (strcmp(first_name, name_to_search) == 0)
        {
            found = 1;
            printf("1-dni: %s\n", first_name);
            printf("2-nojmbre: %s\n", last_name1);
            printf("3-apellido: %s\n", last_name2);
            printf("4-curso: %s\n", curso);
            printf("5-email: %s\n", email);
            printf("6-nota1: %s\n", nota1);
            printf("7-nota2: %s\n", nota2);
            printf("8-nota3: %s\n", nota3);
            printf("9-nota4: %s\n", nota4);
            printf("10-nota5: %s\n", nota5);
            printf("\n");

            printf("Cual quiere modificar, marque del (1-10): ");
            scanf("%d", &num);
            if (num == 1)
            {
                printf("Ingreseel nuevo dni: ");
                scanf("%s", first_name);
            }
            else if (num == 2)
            {
                printf("Ingrese el nuevo nombre: ");
                scanf("%s", last_name1);
            }
            else if (num == 3)
            {
                printf("Ingrese el nuevo apellido: ");
                scanf("%s", last_name2);
            }
            else if (num == 4)
            {
                printf("Ingrese el nuevo curso: ");
                scanf("%s", curso);
            }
            else if (num == 5)
            {
                printf("Ingrese el nuevo email: ");
                scanf("%s", email);
            }
            else if (num == 6)
            {
                printf("Ingrese la nueva nota 1: ");
                scanf("%s", nota1);
            }
            else if (num == 7)
            {
                printf("Ingrese la nueva nota 2: ");
                scanf("%s", nota2);
            }
            else if (num == 8)
            {
                printf("Ingrese la nueva nota 3: ");
                scanf("%s", nota3);
            }
            else if (num == 9)
            {
                printf("Ingrese la nueva nota 4: ");
                scanf("%s", nota4);
            }
            else if (num == 10)
            {
                printf("Ingrese la nueva nota 5: ");
                scanf("%s", nota5);
            }
        }
        fprintf(temp, "%s-%s-%s-%s-%s-%s-%s-%s-%s-%s-\n", first_name, last_name1, last_name2, curso, email, nota1, nota2, nota3, nota4, nota5);
    }

    // Cerrar archivos
    fclose(file);
    fclose(temp);

    // Reemplazar archivo original con archivo temporal
    remove("datos.txt");
    rename("datos_temp.txt", "datos.txt");

    if (!found)
        printf("No se encontró al alumno con DNI %s\n", name_to_search);
}

void menuOpciones()
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
            agregarEntradas();

            break;
        case 2:
            calcularNotasMedias(numAlumnos);
            break;
        case 3:
            visualizar_datos(numAlumnos);
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

    return 0;
}