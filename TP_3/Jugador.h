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
/*********************************************************************************/
int jugador_obtenerElmaximoId(Jugador* this,int* id);
void jugador_encabezado();
int jugador_imprimirUnJugador(Jugador* this);

Jugador* jugador_newConParametros(int id,char* nombreC,int edad,char* posicion, char*nacionalidad, int idSeleccion);
Jugador* jugador_newConParametros_tomaDatoArchivo(int* id,char* nombreC,int* edad,char* posicion, char*nacionalidad, int* idSeleccion);

int jugador_convertirIdEnPosicion(int id, char* nombreDeLaPosicion);
void jugador_subMenuListadoPosiciones();
void jugador_subMenuListadoNacionalidades();
int jugador_imprimirListaJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, int referenciaDeUso);

int jugador_ordenarPorNacionalidad(void* p1,void*p2);
int jugador_ordenarPorEdad(void* p1,void*p2);
int jugador_ordenarPorNombre(void* p1,void*p2);

int jugador_paraConvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int jugador_sacarConvocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int jugador_pedirId(LinkedList* pArrayListJugador, int * indice ,char * mensaje);
int jugador_buscarPorId(LinkedList* pArrayListJugador, int idBuscado, int* indice);

#endif // jug_H_INCLUDED
