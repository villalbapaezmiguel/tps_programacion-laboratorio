/*
 * Informe.c
 *
 *  Created on: 29 oct. 2022
 *      Author: miguel
 */
#include "Informes.h"


void subMenu_informe(eJugador* listadoJugador , int largoJugador , eConfederacion* listadoConfederacion , int largoConfederacion)
{
	int opcion ;

	if(listadoJugador != NULL && largoJugador > 0 && listadoConfederacion != NULL && largoConfederacion > 0)
	{
		do {
			printf("\n1)Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.");
			printf("\n2)Listado de confederaciones con sus jugadores");
			printf("\n3)Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio");
			printf("\n4)Informar la confederación con mayor cantidad de años de contratos total.");
			printf("\n5)Informar porcentaje de jugadores por cada confederación.");
			printf("\n6)Informar cual es la región con más jugadores y el listado de los mismos.");
			printf("\n7)Salir");
			if(utn_pedirNumeroEntero(&opcion, "\nIngrese opcion :", "\nError", 7, 1) == 0)
			{
				switch(opcion)
				{
				case 1:
					printf("\n<<Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador>>");



					break;
				case 2:
					printf("\n<<2)Listado de confederaciones con sus jugadores>>");
					break;
				case 3:
					printf("\n<<3)Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio>>");
					break;
				case 4:
					printf("\n<<4)Informar la confederación con mayor cantidad de años de contratos total>>");
					break;
				case 5:
					printf("\n<<5)Informar porcentaje de jugadores por cada confederación.>>");
					break;
				case 6:
					printf("\n<<6)Informar cual es la región con más jugadores y el listado de los mismos>>");
					break;
				case 7:
					printf("\n<<7)Salir>>");
					break;
				}
			}
		} while (opcion != 7);

	}

}

//Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador

void informe_oredenarAlfabeticamenteNombreConfederacion(eJugador* listadoJugador , int largoJugador, eConfederacion* listadoConferacion , int largoConfederacion)
{



	if(listadoJugador != NULL && listadoConferacion != NULL && largoJugador > 0 && largoConfederacion > 0)
	{



	}




}

