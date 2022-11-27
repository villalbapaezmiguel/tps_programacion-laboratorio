#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED
#define NOMBRE_LEN 100
#define POSICION_LEN 30
#define NACIONALIDAD_LEN 30

typedef struct
{
	int id;
	char nombreCompleto[NOMBRE_LEN];
	int edad;
	char posicion[POSICION_LEN];
	char nacionalidad[NACIONALIDAD_LEN];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);
int jug_setID(Jugador *this, int *id);
int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);
//int jug_obtenerElmaxId(Jugador* this,int* id);
int jug_getID(Jugador *this, int *id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);
//mias
int jugador_obtenerElmaximoId(Jugador* this,int* id);
void jug_encabezado();
int jug_imprimirUnJugador(Jugador* this);

Jugador* jug_newParametrosReales(int id,char* nombreC,int edad,char* posicion, char*nacionalidad, int idSeleccion);

Jugador* jug_newParametrosReales2(int* id,char* nombreC,int* edad,char* posicion, char*nacionalidad, int* idSeleccion);
int convertirIdEnPosicion(int id, char* nombreDeLaPosicion);
void subMenuListadoPosiciones();
void subMenuListadoNacionalidades();

int jug_ordenarPorNacionalidad(void* p1,void*p2);

int jug_ordenarPorEdad(void* p1,void*p2);

int jug_ordenarPorNombre(void* p1,void*p2);
int jug_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int jug_imprimirJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, int referenciaDeUso);
int jug_Solicitar_Id(LinkedList* pArrayListJugador, int * indice ,char * mensaje);
int jug_BuscarPorId(LinkedList* pArrayListJugador, int idBuscado, int* indice);
int jug_Quitar_Convocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

#endif // jug_H_INCLUDED
