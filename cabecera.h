#ifndef cabecera
#define cabecera
#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Booleanos
#include <stdlib.h>
#include "cabecera.h"
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
void split_name(char *full_name, char *first_name, char *last_name1, char *last_name2, char *curso, char *email, char *nota1, char *nota2, char *nota3, char *nota4, char *nota5);
void agregarEntradas();
int compare(const void *a, const void *b);
void calcularNotasMedias(int maximo_entradas);
void visualizar_datos(int maximo_entradas);
void modificarEliminarDatos();
void menuOpciones();

#endif