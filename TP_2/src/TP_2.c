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
	int largoJugadores = JUGADOORES_LEN;

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
		int opcionModificar ;
		int posicionIdModificar ;
		int respuestaOpcion = -1;
		int respuestaIdModificar = -1;
		int respuestaBaja = -1;
		banderaAlta = -1;
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<_MENU_>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		do {
			printf("\n1)ALTA DE JUGADOR \n2)BAJA DEL JUGADOR \n3)MODIFICACION DEL JUGADOR \n4)INFORMES\n5)SALIR");
			respuestaOpcion = utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion : ", "\nError", 5, 1);
			if(respuestaOpcion == 0)
			{
				switch(opcion)
				{
				case 1:
					printf("\n-----------------------------ALTA DE JUGADOR-----------------------------------------");

					posicionLibre = buscarLugarLibre(jugadores, JUGADOORES_LEN);
					if(posicionLibre >= 0)
					{
						*(jugadores+posicionLibre) = altaJugador(jugadores ,largoJugadores);
						banderaAlta = 0;
					}
					break;
				case 2:
					printf("\n-----------------------------BAJA DEL JUGADOR-----------------------------------------");
					if(banderaAlta == 0)
					{
						respuestaBaja = baja_jugador(jugadores, JUGADOORES_LEN);

						if(respuestaBaja == 0)
						{
							printf("\n++++++++++++++++++++++++++++++++++++++++");
							printf("\nJugador dato de BAJA de menera Exitosa !!!");
							printf("\n++++++++++++++++++++++++++++++++++++++++");
						}else if(respuestaBaja == 1)
						{
							printf("\n++++++++++++++++++++++++++++++++++++++++");
							printf("\nEl Jugador NO fue dado de BAJA !!!");
							printf("\n++++++++++++++++++++++++++++++++++++++++");
						}
					}else{
						printf("\nNo se puede ingresar a los casos 2, 3 y 4 sin antes haber realizado la carga de algún jugador.");
						printf("\nADVERTENCIA -> tiene que ingresar POR LO MENOS un Jugador para poder entrar en esta opcion .\n");
					}
					break;
				case 3:
					printf("\n-----------------------------MODIFICACION DEL JUGADOR-----------------------------------------");
					if(banderaAlta == 0)
					{
						informar_jugador(jugadores, JUGADOORES_LEN);
						do {
							respuestaIdModificar = utn_pedirNumeroEntero(&idModificar, "\nIngrese el ID a modificar : ", "\nError", JUGADOORES_LEN, 0);
						} while (respuestaIdModificar == -1);

						if( respuestaIdModificar == 0)
						{
							posicionIdModificar = buscarPorId(jugadores, JUGADOORES_LEN, idModificar);
							if(posicionIdModificar >= 0)
							{
								printf("\nID : %d | NOMBRE : %s | POSICION : %s | N° CAMISETA : %d | ID CONFEDERACION : %d | SALARIO : %.2f | ANIOS CONTRATO : %d",
										(*(jugadores+posicionIdModificar)).id, (*(jugadores+posicionIdModificar)).nombre, (*(jugadores+posicionIdModificar)).posicion ,(*(jugadores+posicionIdModificar)).numeroCamiseta,
										(*(jugadores+posicionIdModificar)).idConfederacion , (*(jugadores+posicionIdModificar)).salario, (*(jugadores+posicionIdModificar)).aniosContrato);

								int respuestaModificar = -1;
								do {
									respuestaModificar = utn_pedirNumeroEntero(&opcionModificar,"\nEsta seguro de modificar este jugador (1-SI/2-NO)??", "\nERROR", 2, 1);

								} while (respuestaModificar == -1);

								if(opcionModificar == 1)
								{
									if(modificacionJugador(jugadores , JUGADOORES_LEN, &posicionIdModificar) == 0)
									{
										printf("\nModificacion del Jugador : ");
										printf("\nID : %d | NOMBRE : %s | POSICION : %s | N° CAMISETA : %d | ID CONFEDERACION : %d | SALARIO : %.2f | ANIOS CONTRATO : %d\n",
												(*(jugadores+posicionIdModificar)).id, (*(jugadores+posicionIdModificar)).nombre, (*(jugadores+posicionIdModificar)).posicion ,(*(jugadores+posicionIdModificar)).numeroCamiseta,
												(*(jugadores+posicionIdModificar)).idConfederacion , (*(jugadores+posicionIdModificar)).salario, (*(jugadores+posicionIdModificar)).aniosContrato);
										printf("\n++++++++++++++++++++++++++++++++++++++++");
										printf("\nMODIFICACION del Jugador exitosa !!!");
										printf("\n++++++++++++++++++++++++++++++++++++++++");
									}else if(opcionModificar == 2)
									{
										printf("\nError al modificar el jugador...");
									}
								}else{
									printf("\n++++++++++++++++++++++++++++++++++++++++");
									printf("\nEl jugador NO fue MODIFICADO");
									printf("\n++++++++++++++++++++++++++++++++++++++++\n");
								}
							}else{
								printf("\nError el id ingresado no existe...");
							}
						}
					}else{
						printf("\nNo se puede ingresar a los casos 2, 3 y 4 sin antes haber realizado la carga de algún jugador.");
						printf("\nADVERTENCIA -> tiene que ingresar POR LO MENOS un Jugador para poder entrar en esta opcion .\n");
					}
					break;
				case 4:
					printf("\n-----------------------------INFORMES-----------------------------------------");
					if(banderaAlta == 0)
					{
						subMenu_informe(jugadores, JUGADOORES_LEN, confederacion, CONFEDERACION_LEN);

					}else{
						printf("\nNo se puede ingresar a los casos 2, 3 y 4 sin antes haber realizado la carga de algún jugador.");
						printf("\nADVERTENCIA -> tiene que ingresar POR LO MENOS un Jugador para poder entrar en esta opcion .\n");
					}
					break;
				case 5:
					printf("\n-----------------------------SALIR-----------------------------------------");
					int respuesSalir = -1;

					do {
						printf("\nSeguro que desea salir ??");
						respuesSalir = utn_pedirNumeroEntero(&banderaSalir, "\n(1-Si / 2-NO) : ", "\nError", 2, 1);
					} while (respuesSalir == -1);
					if(banderaSalir == 1)
					{
						printf("\nSalio del programa...");
						printf("\nGracias por usar este programa <3");
					}

					break;
				default : printf("\nError Opcion incorrecta...\n");
				}
			}
		} while (banderaSalir != 1);

	}

	return EXIT_SUCCESS;
}





