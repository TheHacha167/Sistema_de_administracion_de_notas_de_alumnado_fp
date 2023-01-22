#include <stdio.h>
#include <string.h>

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

int main()
{
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
    int start =0; // Comienzo en la entrada 50
    int count = 0; // Contador de entradas
    FILE *file = fopen("datos copy.txt", "r");
    if (file == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    for (i = 0; i < 100; i++)
    {
        if (fgets(full_name, 100, file) == NULL) 
            break;
        if (count >= start) {
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
    return 0;

}