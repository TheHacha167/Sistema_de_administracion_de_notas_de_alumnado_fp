#ifndef cabecera
#define cabecera

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

void calcularNotasMedias(struct alumno alumnos[], int numAlumnos);
void cargarDatosDeArchivo(struct alumno alumnos[], int *numAlumnos);
void seleccionarArchivo();
void guardarDatos(struct alumno alumnos[], int numAlumnos);
void modificarEliminarAlumno(struct alumno alumnos[], int *numAlumnos);
void entradaDatos();
void agregarEntradas(struct alumno alumnos[], int masEntradas);
void menuOpciones(const char *datos, alumno *alumnos);

#endif