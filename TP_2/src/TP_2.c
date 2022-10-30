/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "JugadorABM.h"
#include "ConfederacionABM.h"
#include "Informes.h"


int main(void) {

	setbuf(stdout, NULL);
	eConfederacion confederacion [CONFEDERACION_LEN];
	eJugador jugador [JUGADOORES_LEN];
	int banderaSalir = -1;

	if(inicializar_Jugador(jugador, JUGADOORES_LEN) == 0)
	{
		*(jugador+0) = altaForzadaJugador(0, "Messi", "delantero", 10, 101, 10000.0, 3);
		*(jugador+1) = altaForzadaJugador(1, "Cristiano", "delantero", 7, 101, 11000.0, 5);
		*(jugador+2) = altaForzadaJugador(2, "Maradora", "mediocampista", 10, 103, 1000.0, 2);
		*(jugador+3) = altaForzadaJugador(3, "Ronaldinho", "mediocampista", 90, 101, 5000.0, 4);
		*(jugador+4) = altaForzadaJugador(4, "Neymar", "delantero", 11, 102, 8000.0, 3);
		*(jugador+5) = altaForzadaJugador(5, "Carlos", "defensor", 3, 101, 4000.0, 1);

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

				posicionLibre = buscarLugarLibre(jugador, JUGADOORES_LEN);
				if(posicionLibre >= 0)
				{
					*(jugador+posicionLibre) = altaJugador();

					banderaAlta = 0;
				}
				break;
			case 2:
				printf("\n-----------------------------BAJA DEL JUGADOR-----------------------------------------");
				if(banderaAlta == 0)
				{
					baja_jugador(jugador, JUGADOORES_LEN);
				}else{
					printf("\nNo se puede ingresar a los casos 2, 3 y 4 sin antes haber realizado la carga de algún jugador.");
				}
				break;
			case 3:
				printf("\n-----------------------------MODIFICACION DEL JUGADOR-----------------------------------------");
				if(banderaAlta == 0)
				{
					informar_jugador(jugador, JUGADOORES_LEN);
					if(utn_pedirNumeroEntero(&idModificar, "\nIngrese el ID a modificar : ", "\nError", JUGADOORES_LEN, 0) == 0)
					{
						if(buscarPorId(jugador, JUGADOORES_LEN, idModificar) >= 0)
						{
							printf("\nEl id es el : %d", idModificar);
							if(modificacionJugador(jugador , JUGADOORES_LEN, &idModificar) == 0)
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
					informar_jugador(jugador, JUGADOORES_LEN);

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





