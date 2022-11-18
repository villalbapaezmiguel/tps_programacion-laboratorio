#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
//	int contador = 0;
	char buffer[6][200];
	Jugador* unJugador;
	int cantidad ;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		while(!feof(pFile))
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]\n",
					buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5] );

			if(cantidad < 6)
			{
				jug_delete(unJugador);
				unJugador = NULL;
				retorno = -1;
				break;

			}else{

				unJugador = jug_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);

				if(unJugador != NULL)
				{
					ll_add(pArrayListJugador, (Jugador*)unJugador);
				}
//				printf("%s |%s |%s |%s |%s |%s |");
				retorno = 0;
			}
		}
	}



    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
    return 1;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
    return 1;
}

