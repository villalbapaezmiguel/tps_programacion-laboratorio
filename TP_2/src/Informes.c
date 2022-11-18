/*
 * Informe.c
 *
 *  Created on: 29 oct. 2022
 *      Author: miguel
 */
#include "Informes.h"

/*void informar_jugador(eJugador* punteroArrayJugador , int largoJugador)
 *Objetivo de la funcion :
 * 	da un listados de todos los campos de la estructura Jugador que esten ocupados
 *
 *ParaMetros : void
 * Parametro : eJugador* punteroArrayJugador , tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largoJugador : tipo entero , es el largo del array de estrutura
 *
 *Variables :
 * int i ; tipo entero , es un contador que va a ir incrementando dentro del for
 * int anchoColumnaIdTransporte : tipo entero , cantidad de espacios que va a ocupar en el printf()
 * int respuestaPesoCarga : tipo entero , es una bandera para verificar si lo que devolvio la funcion esta bien
 * int respuestaCantidadBulto : tipo entero , es una bandera para verificar si lo que devolvio la funcion esta bien
 * int anchoColumnaDescripcion : tipo entero , es la cantidad de espacio que va ocupar en el Printf()
 *
 *Retono : void
 **/
void informar_jugador(eJugador* punteroArrayJugador , int largoJugador)
{

	int anchoColumnaIdJugador = -10;
	int anchoColumnaNombre = -20;
	int anchoColumnaPosicion = -15;
	int anchoColumnaNumeroCamiseta = -16;
	int anchoColumnaNumeroCamisetaDos = -15;
	int anchoColumnaIdConfederacion = -20;
	int anchoColumnaSalario = -20;
	int anchoColumnaAniosContrato = -20;
	int i ;

	if(punteroArrayJugador != NULL && largoJugador > 0)
	{
		printf("\n");
		printf("+**********+********************+***************+***************+********************+********************+********************+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n", anchoColumnaIdJugador,"ID",anchoColumnaNombre,"NOMBRE", anchoColumnaPosicion, "POSICION", anchoColumnaNumeroCamiseta, "N° CAMISETA", anchoColumnaSalario,"SALARIO", anchoColumnaIdConfederacion, "CONFEDERACION", anchoColumnaAniosContrato, "AÑIOS DE CONTRATO");
		printf("+**********+********************+***************+***************+********************+********************+********************+\n");
		for (i = 0; i < largoJugador; ++i) {

			if((*(punteroArrayJugador+i)).isEmpty == OCUPADO)
			{

				switch((*(punteroArrayJugador+i)).idConfederacion)
				{
				case 100:
					printf("|%*d|%*s|%*s|%*i|%*f|%*s|%*d|\n", anchoColumnaIdJugador,(*(punteroArrayJugador+i)).id,anchoColumnaNombre,(*(punteroArrayJugador+i)).nombre,
							anchoColumnaPosicion, (*(punteroArrayJugador+i)).posicion, anchoColumnaNumeroCamisetaDos, (*(punteroArrayJugador+i)).numeroCamiseta,anchoColumnaSalario, (*(punteroArrayJugador+i)).salario,
							anchoColumnaIdConfederacion, "CONMEBOL", anchoColumnaAniosContrato, (*(punteroArrayJugador+i)).aniosContrato);
					printf("+----------+--------------------+---------------+---------------+--------------------+--------------------+--------------------+\n");
					break;
				case 101:
					printf("|%*d|%*s|%*s|%*i|%*f|%*s|%*d|\n", anchoColumnaIdJugador,(*(punteroArrayJugador+i)).id,anchoColumnaNombre,(*(punteroArrayJugador+i)).nombre,
							anchoColumnaPosicion, (*(punteroArrayJugador+i)).posicion, anchoColumnaNumeroCamisetaDos, (*(punteroArrayJugador+i)).numeroCamiseta,anchoColumnaSalario, (*(punteroArrayJugador+i)).salario,
							anchoColumnaIdConfederacion, "UEFA", anchoColumnaAniosContrato, (*(punteroArrayJugador+i)).aniosContrato);
					printf("+----------+--------------------+---------------+---------------+--------------------+--------------------+--------------------+\n");

					break;
				case 102:
					printf("|%*d|%*s|%*s|%*i|%*f|%*s|%*d|\n", anchoColumnaIdJugador,(*(punteroArrayJugador+i)).id,anchoColumnaNombre,(*(punteroArrayJugador+i)).nombre,
							anchoColumnaPosicion, (*(punteroArrayJugador+i)).posicion, anchoColumnaNumeroCamisetaDos, (*(punteroArrayJugador+i)).numeroCamiseta,anchoColumnaSalario, (*(punteroArrayJugador+i)).salario,
							anchoColumnaIdConfederacion, "AFC", anchoColumnaAniosContrato, (*(punteroArrayJugador+i)).aniosContrato);
					printf("+----------+--------------------+---------------+---------------+--------------------+--------------------+--------------------+\n");

					break;
				case 103:
					printf("|%*d|%*s|%*s|%*i|%*f|%*s|%*d|\n", anchoColumnaIdJugador,(*(punteroArrayJugador+i)).id,anchoColumnaNombre,(*(punteroArrayJugador+i)).nombre,
							anchoColumnaPosicion, (*(punteroArrayJugador+i)).posicion, anchoColumnaNumeroCamisetaDos, (*(punteroArrayJugador+i)).numeroCamiseta,anchoColumnaSalario, (*(punteroArrayJugador+i)).salario,
							anchoColumnaIdConfederacion, "CAF", anchoColumnaAniosContrato, (*(punteroArrayJugador+i)).aniosContrato);
					printf("+----------+--------------------+---------------+---------------+--------------------+--------------------+--------------------+\n");

					break;
				case 104:
					printf("|%*d|%*s|%*s|%*i|%*f|%*s|%*d|\n", anchoColumnaIdJugador,(*(punteroArrayJugador+i)).id,anchoColumnaNombre,(*(punteroArrayJugador+i)).nombre,
							anchoColumnaPosicion, (*(punteroArrayJugador+i)).posicion, anchoColumnaNumeroCamisetaDos, (*(punteroArrayJugador+i)).numeroCamiseta,anchoColumnaSalario, (*(punteroArrayJugador+i)).salario,
							anchoColumnaIdConfederacion, "CONCACAF", anchoColumnaAniosContrato, (*(punteroArrayJugador+i)).aniosContrato);
					printf("+----------+--------------------+---------------+---------------+--------------------+--------------------+--------------------+\n");

					break;
				case 105:
					printf("|%*d|%*s|%*s|%*i|%*f|%*s|%*d|\n", anchoColumnaIdJugador,(*(punteroArrayJugador+i)).id,anchoColumnaNombre,(*(punteroArrayJugador+i)).nombre,
							anchoColumnaPosicion, (*(punteroArrayJugador+i)).posicion, anchoColumnaNumeroCamisetaDos, (*(punteroArrayJugador+i)).numeroCamiseta,anchoColumnaSalario, (*(punteroArrayJugador+i)).salario,
							anchoColumnaIdConfederacion, "OFC", anchoColumnaAniosContrato, (*(punteroArrayJugador+i)).aniosContrato);
					printf("+----------+--------------------+---------------+---------------+--------------------+--------------------+--------------------+\n");

					break;
				}
			}
		}
	}
}




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

					if(informe_oredenarAlfabeticamenteNombreConfederacion(listadoJugador, largoJugador, listadoConfederacion, largoConfederacion) == 0)
					{
						printf("\nInforme OK");
					}

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

int informe_oredenarAlfabeticamenteNombreConfederacion(eJugador* listadoJugador , int largoJugador, eConfederacion* listadoConferacion , int largoConfederacion)
{
	int retorno = -1;
//	eJugador auxJugador;
//	eConfederacion auxConfederacion ;
//	int  i, j;
//	int k, l;
//	int bandera ;
int i;

	if(listadoJugador != NULL && listadoConferacion != NULL && largoJugador > 0 && largoConfederacion > 0)
	{

		informar_ordenarAlfabeticamente_confederacion(listadoConferacion, largoConfederacion);
		for (i = 0; i < largoConfederacion; ++i) {

			printf("\nNombre : %s", listadoConferacion[i].nombre);
		}

//		for (i = 0; i < largoConfederacion; ++i) {
////			printf("\nCONFEDERACION %s",(*(listadoConferacion+i)).nombre);
//			for (j = 0; j < largoJugador; ++j) {
//
//				if((*(listadoJugador+j)).idConfederacion == (*(listadoConferacion+i)).id)
//				{
////					printf("\n Nombre Jugador : %s", (*(listadoJugador+j)).nombre);
//					if(strncmp(listadoJugador[i].nombre, listadoJugador[j+1].nombre, LARGO_NOMBRE) == 0)//segundo criterio
//					{
//						auxJugador = listadoJugador[i];
//						listadoJugador[i] = listadoJugador[j+1];
//						listadoJugador[j+1] = auxJugador;
//					}
//
//				}
//			}
//		}
//
//
//		for (k = 0; k < largoConfederacion; ++k) {
//			printf("\nCONFEDERACION %s",(*(listadoConferacion+k)).nombre);
//			for (l = 0; l < largoJugador; ++l) {
//
//				if((*(listadoJugador+l)).idConfederacion == (*(listadoConferacion+k)).id)
//				{
//					printf("\n Nombre Jugador : %s", (*(listadoJugador+l)).nombre);
//					if(strncmp(listadoJugador[k].nombre, listadoJugador[l+1].nombre, LARGO_NOMBRE) == 0)//segundo criterio
//					{
//						auxJugador = listadoJugador[k];
//						listadoJugador[k] = listadoJugador[l+1];
//						listadoJugador[l+1] = auxJugador;
//					}
//
//				}
//			}
//		}



		//				if(strncmp(listadoConferacion[i].nombre, listadoConferacion[j+1].nombre, NOMBRE_CONFEDERACION) > 0)//primer criterio
		//				{
		////					bandera = 1;
		//					auxJugador = listadoJugador[i];
		//					listadoJugador[i] = listadoJugador[j+1];
		//					listadoJugador[j+1] = auxJugador;
		//
		//				}else if(strncmp(listadoJugador[i].nombre, listadoJugador[j+1].nombre, LARGO_NOMBRE) == 0)//segundo criterio
		//				{
		////					bandera = 1;
		//					auxJugador = listadoJugador[i];
		//					listadoJugador[i] = listadoJugador[j+1];
		//					listadoJugador[j+1] = auxJugador;
		//				}
//		do {
//			bandera = 0;
//			for (i = 0; i < largoConfederacion -1; ++i) {
//
//				if(strncmp(listadoConferacion[i].nombre, listadoConferacion[i+1].nombre, NOMBRE_CONFEDERACION) > 0)//primer criterio
//				{
//					bandera = 1;
//					auxJugador = listadoJugador[i];
//					listadoJugador[i] = listadoJugador[i+1];
//					listadoJugador[i+1] = auxJugador;
//
//				}else if(strncmp(listadoJugador[i].nombre, listadoJugador[i+1].nombre, LARGO_NOMBRE) == 0)//segundo criterio
//				{
//					bandera = 1;
//					auxJugador = listadoJugador[i];
//					listadoJugador[i] = listadoJugador[i+1];
//					listadoJugador[i+1] = auxJugador;
//				}
//			}
//			largoConfederacion--;
//		} while (bandera);
//		informar_jugador(listadoJugador, largoJugador);


	}



	 return retorno;
}

void informar_ordenarAlfabeticamente_confederacion (eConfederacion* listaConfederacion , int largoConfederacion)
{
	eConfederacion auxConfederacion ;
	int i;

	for (i = 0; i < NOMBRE_CONFEDERACION; ++i) {//ordenamos la confederacion

		if(strncmp(listaConfederacion[i].nombre, listaConfederacion[i+1].nombre, NOMBRE_CONFEDERACION) > 0)
		{
				auxConfederacion = listaConfederacion[i];
				listaConfederacion[i] = listaConfederacion[i+1];
				listaConfederacion[i+1] = auxConfederacion;
		}
	}


}



