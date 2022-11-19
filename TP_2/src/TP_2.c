/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "JugadorABM.h"
#include "ConfederacionABM.h"
#include "Informes.h"


int main(void) {

	setbuf(stdout, NULL);
	eConfederacion confederacion [CONFEDERACION_LEN];
	eJugador jugadores [JUGADOORES_LEN];
	int banderaSalir = -1;

	if(inicializar_Jugador(jugadores, JUGADOORES_LEN) == 0)
	{
		printf("init ok\n");
		*(jugadores+0) = altaForzadaJugador(1, "Emiliano Martinez", "arquero", 1, 100, 100000.0, 4);
		*(jugadores+1) = altaForzadaJugador(2, "Juan Musso", "arquero", 7, 100, 80000.0, 2);
		*(jugadores+2) = altaForzadaJugador(3, "Leo Messi", "delantero", 10, 100, 80000.0, 4);
		*(jugadores+3) = altaForzadaJugador(4, "Almirez Ali", "delantero", 9, 100, 55000.0, 1);
		*(jugadores+4) = altaForzadaJugador(5, "Harry Maguire", "defensor", 2, 101, 70000.0, 4);
		*(jugadores+5) = altaForzadaJugador(6, "Eric Dier", "defensor", 3, 101, 60000.0, 2);
		*(jugadores+6) = altaForzadaJugador(7, "Harry Kane", "delantero", 10, 101, 3000.0, 2);
		*(jugadores+7) = altaForzadaJugador(8, "Alfred Gomis", "arquero", 1, 101, 9000.0, 1);
		*(jugadores+8) = altaForzadaJugador(9, "Abdelkarim Hassan", "mediocampista", 8, 101, 48000.0, 1);
		*(jugadores+9) = altaForzadaJugador(10, "Guillermo Ochoa", "arquero", 1, 104, 90000.0, 4);
		*(jugadores+10) = altaForzadaJugador(11, "Tecatito", "delantero", 11, 104, 100000.0, 3);
		*(jugadores+11) = altaForzadaJugador(12, "Luis Romo", "medicampista", 7, 104, 100000.0, 2);
		*(jugadores+12) = altaForzadaJugador(13, "Bamba Dieng", "delantero", 9, 103, 100000.0, 2);
		*(jugadores+13) = altaForzadaJugador(14, "Demba Seck", "delantero", 11, 103, 6000.0, 2);
//		*(jugadores+14) = altaForzadaJugador(15, "Tarek Salman", "defensor", 6, 102, 78000.0, 5);

		*(confederacion+0) = altaForzadaConfederacion(CONFEDERACION_CONMEBOL, "CONMEBOL", "Sudamerica", 1916);
		*(confederacion+1) = altaForzadaConfederacion(CONFEDERACION_UEFA, "UEFA", "Europa", 1954);
		*(confederacion+2) = altaForzadaConfederacion(CONFEDERACION_AFC,"AFC","Asia",1954);
		*(confederacion+3) = altaForzadaConfederacion(CONFEDERACION_CAF,"CAF","Africa",1957);
		*(confederacion+4) = altaForzadaConfederacion(CONFEDERACION_CONCACAF,"CONCACAF","America del Norte",1961);
		*(confederacion+5) = altaForzadaConfederacion(CONFEDERACION_OFC,"OFC","Oceania",1966);


		int opcion ;
		int banderaAlta = -1;
		int posicionLibre ;
		int idModificar ;

		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<_MENU_>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		do {
			printf("\n1)ALTA DE JUGADOR \n2)BAJA DEL JUGADOR \n3)MODIFICACION DEL JUGADOR \n4)INFORMES\n5)SALIR");
			utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion : ", "\nError", 5, 1);
			switch(opcion)
			{
			case 1:
				printf("\n-----------------------------ALTA DE JUGADOR-----------------------------------------");

				posicionLibre = buscarLugarLibre(jugadores, JUGADOORES_LEN);
				if(posicionLibre >= 0)
				{
					*(jugadores+posicionLibre) = altaJugador();

					banderaAlta = 0;
				}
				break;
			case 2:
				printf("\n-----------------------------BAJA DEL JUGADOR-----------------------------------------");
				if(banderaAlta == 0)
				{
					baja_jugador(jugadores, JUGADOORES_LEN);
				}else{
					printf("\nNo se puede ingresar a los casos 2, 3 y 4 sin antes haber realizado la carga de algún jugador.");
				}
				break;
			case 3:
				printf("\n-----------------------------MODIFICACION DEL JUGADOR-----------------------------------------");
				if(banderaAlta == 0)
				{
					informar_jugador(jugadores, JUGADOORES_LEN);
					if(utn_pedirNumeroEntero(&idModificar, "\nIngrese el ID a modificar : ", "\nError", JUGADOORES_LEN, 0) == 0)
					{
						if(buscarPorId(jugadores, JUGADOORES_LEN, idModificar) >= 0)
						{
							printf("\nEl id es el : %d", idModificar);
							if(modificacionJugador(jugadores , JUGADOORES_LEN, &idModificar) == 0)
							{
								printf("\nMoficacion ok");
							}
						}
					}
				}else{
					printf("\nNo se puede ingresar a los casos 2, 3 y 4 sin antes haber realizado la carga de algún jugador.");
				}
				break;
			case 4:
				printf("\n-----------------------------INFORMES-----------------------------------------");
				if(banderaAlta == 0)
				{
//					informar_jugador(jugadores, JUGADOORES_LEN);

					subMenu_informe(jugadores, JUGADOORES_LEN, confederacion, CONFEDERACION_LEN);

				}else{
					printf("\nNo se puede ingresar a los casos 2, 3 y 4 sin antes haber realizado la carga de algún jugador.");
				}
				break;
			case 5:
				printf("\n-----------------------------SALIR-----------------------------------------");
				printf("\nSeguro que desea salir ??");
				if(utn_pedirNumeroEntero(&banderaSalir, "\n(1-Si / 2-NO) : ", "\nError", 2, 1) == 0)
				{
					if(banderaSalir == 1)
					{
						printf("\nSalio del programa");
					}
				}else{
					printf("\nOpcion incorrecta");
				}
				break;
			default : printf("\nOpcion incorrecta");
			}
		} while (banderaSalir != 1);

	}



	return EXIT_SUCCESS;
}





