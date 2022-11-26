#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
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
void encabezado();
int jug_imprimirUnJugador(Jugador* this);

Jugador* jug_newParametrosReales(int id,char* nombreC,int edad,char* posicion, char*nacionalidad, int idSeleccion);

Jugador* jug_newParametrosReales2(int* id,char* nombreC,int* edad,char* posicion, char*nacionalidad, int* idSeleccion);
int convertirIdEnPosicion(int id, char* nombreDeLaPosicion);
void subMenuListadoPosiciones();
void subMenuListadoNacionalidades();

int jug_ordenarPorNacionalidad(void* p1,void*p2);

int jug_ordenarPorEdad(void* p1,void*p2);

int jug_ordenarPorNombre(void* p1,void*p2);

#endif // jug_H_INCLUDED
