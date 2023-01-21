#ifndef moduloDatos.h
#define moduloDatos .h

void cargarDatosDeArchivo(struct alumno alumnos[], int *numAlumnos);
void seleccionarArchivo();
void guardarDatos(struct alumno alumnos[], int numAlumnos);
void modificarEliminarAlumno(struct alumno alumnos[], int *numAlumnos);

#endif
