#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

#define CONFEDERACION_LEN 30
#define PAIS_LEN 30

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete();

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);

int selec_getConfederacion(Seleccion* this,char* confederacion);

void encabezadoSelecciones();
int selec_imprimirUnaSeleccion(Seleccion* this);
int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);
int selec_ordenarPorConfederacion(void* p1,void*p2);

int selec_AsignarDescripcionPais(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, int indice, char *descripcionPais);
int selec_Solicitar_Id(LinkedList* pArrayListSeleccion, int* indice);
int selec_buscarPorId(LinkedList* pArrayListSeleccion, int idBuscado, int *indice);
int selec_AsignarDescripcionPais(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, int indice, char *descripcionPais);
int selec_ordenarPorId(void* p1,void*p2);
#endif // selec_H_INCLUDED
