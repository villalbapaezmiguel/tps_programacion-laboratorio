#include "Jugador.h"


Jugador* jug_new()
{
	return (Jugador*)calloc(1,sizeof(Jugador));//para que nos inicialize todos los campos
}

void jug_delete(Jugador* this)
{
	free(this);

}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr,
		char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* unJugador;
	unJugador = jug_new();

	if(unJugador != NULL)
	{
		/*todos los set*/
		jug_delete(unJugador);
		unJugador = NULL;

	}

	return unJugador;

}



int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion != NULL)
	{



	}

	return retorno;
}
