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
    //return 1;
	int retorno = -1;
	Jugador* unJugador=NULL;
	char bufferJugador[6][200];
	int cantidad;
	//int contadorDeJugadores = 0;
	if(pFile != NULL && pArrayListJugador != NULL)
	{
		//lectura fantasma
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferJugador[0],bufferJugador[1],bufferJugador[2],
				bufferJugador[3],bufferJugador[4],bufferJugador[5]);
		while(!feof(pFile))
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferJugador[0],bufferJugador[1],
					bufferJugador[2],bufferJugador[3],bufferJugador[4],bufferJugador[5]);
			if(cantidad < 6)
			{
				jug_delete(unJugador);
				unJugador = NULL;
				retorno=-1;
				break;
			}else
			{
				unJugador = jug_newParametros(
						bufferJugador[0],
						bufferJugador[1],
						bufferJugador[2],
						bufferJugador[3],
						bufferJugador[4],
						bufferJugador[5]);
				if(unJugador != NULL)
				{
					ll_add(pArrayListJugador,(Jugador*)unJugador);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos de los jugadores desde el ARCHIVO BINARIO.
 *
 * \param path pfile*Puntero al archivo a ser descargado
 * \param pArrayListJugador LinkedList* puntero a la lista a ser cargada
 * \return int (-1) ERROR  0) OK
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)//lista de seleccion??
{
	int retorno = -1;
	int cantidad;
	Jugador auxJugador;
	Jugador* nuevoJugador;
	if(pFile != NULL && pArrayListJugador != NULL)
	{
		retorno =0;
		while(!feof(pFile)) //RECORRO HASTA QUE LEA CADA LINEA DEL ARCHIVO
		{
			cantidad = fread(&auxJugador,sizeof(Jugador),1,pFile);
			if(cantidad < 1)
			{ //VERIFICO QUE HAYA PODIDO LEVANTAR El jugador
				break;
			}
			nuevoJugador = jugador_newConParametros_tomaDatoArchivo(&auxJugador.id, auxJugador.nombreCompleto,&auxJugador.edad,auxJugador.posicion,auxJugador.nacionalidad,&auxJugador.idSeleccion); //CONSTRUYO UN NUEVO EMPLEADO
			if(nuevoJugador != NULL){
				ll_add(pArrayListJugador, nuevoJugador); //AGREGO AL LINKEDLIST
			}

		}
	}
	return retorno;
}
/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
    //return 1;
	int retorno = -1;
	Seleccion* auxSeleccion;
	char auxId[1024];
	char auxPais[1024];
	char auxConfederacion[1024];
	char auxConvocados[1024];
	int contadorSelecciones = 0;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,]%[^\n]\n",
				auxId,auxPais,auxConfederacion,auxConvocados);
			do
			{
				fscanf(pFile,"%[^,],%[^,],%[^,]%[^\n]\n",
						auxId,
						auxPais,
						auxConfederacion,
						auxConvocados);
						auxSeleccion = selec_newParametros(auxId,
								auxPais,
								auxConfederacion,
								auxConvocados);
						ll_add(pArrayListSeleccion,(Seleccion*)auxSeleccion);
							retorno = 0;
							contadorSelecciones++;
			}while(!feof(pFile));
	}
//	printf("Se cargaron %d selecciones\n",contadorSelecciones);//32 selecciones
	return retorno;
}


