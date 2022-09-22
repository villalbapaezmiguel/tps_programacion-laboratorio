/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CONFEDERACION_AFC_ASIA 0//en Asia
#define CONFEDERACION_CAF_AFRICA 1//en Africa
#define CONFEDERACION_CONCACAF_ZONA_NORTE 2//en Zona del Norte
#define CONFEDERACION_CONMEBOL_SUDAMERICA 3//en Sudamerica
#define CONFEDERACION_UEFA_EUROPA 4//en Europa
#define CONFEDERACION_OFC_OCEANIA 5//en Oceania

int cargar_confederaciones (int* confederacion );
int	subMenu_costosDeMantenimiento (int* opcionCostos ,float* costoTransporte , float* costoHospedaje ,float* costoComida);
void menuPrincipal(void);
int cargarJugador(int* contadorArqueros , int* contadorDefensores , int* contadorMediocampistas , int* contadorDelanteros  );
int subMenu_cargaJugadores(int* contadorArqueros , int* contadorDefensores , int* contadorMediocampistas , int* contadorDelanteros , int* confederacion);

int main(void) {

	setbuf(stdout,NULL);
	menuPrincipal();



	return EXIT_SUCCESS;
}

/*void menuPrincipal(int* opcion )
 *Objetivo de la funcion :
 * 	le muestra un menu de opciones al usuario
 *
 *ParaMetros :
 * Parametro : int* pOpcion  : tipo entero , Puntero a un entero , alli se dejara el numero ingresado como parametro
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * char bufferString : tipo char , se encarga de pedir el numero para luego pasarle al puntero pRespuetas que se encuentra como parametro (int* pRespuesta)
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
void menuPrincipal(void)
{
	int opcion;
	//Costos del matentenimiento
	float costoTransporte = 0;
	float costoHospedaje = 0;
	float costoComida = 0;
//	float costoMatenimientoTotal = 0;
	int opcionCosto ;

	//Carga de jugadores
	int contadorArqueros = 0;
	int contadorDefensores = 0;
	int contadorMediocampistas = 0;
	int contadorDelanteros = 0;
	int confederacion ;

	printf("\n------------------------Menu Principal------------------------\n");
	do {
		printf("\n1.Ingreso de los costos de mantenimiento\n Costo Transporte -> $%.2f\n Costo Hospedaje -> $%.2f\n Costo Comida -> $%.2f",costoTransporte, costoHospedaje, costoComida);
		printf("\n2.Carga de Jugadores\n Arqueros -> %d\n Defensores -> %d\n Mediocampistas -> %d\n Delanteros -> %d",contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);
		printf("\n3.Realizar todos los Calculos\n4.Informar todos los Resultados\n5.Salir");
		utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion : ", "\nError", 5, 1);

		switch(opcion)
		{
			case 1:
				printf("\n********Costos de mantenimiento*********\n");
				if(subMenu_costosDeMantenimiento(&opcionCosto, &costoTransporte, &costoHospedaje, &costoComida) == 0)
				{
					printf("\n------------------Mantenimiento OK------------------\n");
				}
				break;
			case 2:
				printf("\n*********Carga de jugadores*********\n");
				if(subMenu_cargaJugadores(&contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros, &confederacion) == 0)
				{
					printf("\n------------------Carga OK------------------\n");
				}
				break;
			case 3:
				printf("\n*********Realizar todos los Calculos*********\n");
				break;
			case 4:
				printf("\n*********Informar todos los Resultados*********\n");
				break;
			case 5:
				printf("\n*********Salir*********\n");
				break;
			default : printf("\nOpcion Incorrecta ");
		}


	} while (opcion != 5);



}

int subMenu_cargaJugadores(int* contadorArqueros , int* contadorDefensores , int* contadorMediocampistas , int* contadorDelanteros , int* confederacion)
{
	int retorno = -1;
	int opcion ;
	int banderaCamisetas = -1;
	int banderaPosicion = -1;
	int banderaConfederacion = -1;
	int banderaSalir = -1;
	int camisetas ;


	if(contadorArqueros != NULL && contadorDefensores != NULL && contadorMediocampistas != NULL && contadorDelanteros != NULL && confederacion != NULL)
	{
		retorno = 0;
		do {
			printf("\n1)Numero de camiseta \n2)Posicion \n3)Confederación en la que está jugando\n4)salir");
			utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion :", "\nError", 4, 1);
			switch(opcion)
			{
				case 1:
					if(utn_pedirNumeroEntero(&camisetas, "\ningrese un numero de camisata (entre 1 y 32):", "\nError", 32, 1) == 0)
					{
						printf("\n--> numero de camiseta OK<--\n");
						banderaCamisetas = 0;
					}
					break;
				case 2:
					if(cargarJugador(contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros) == 0)
					{
						printf("\n--> Posicion OK <--\n");
						banderaPosicion = 0;
					}
					break;
				case 3:
					if(cargar_confederaciones(confederacion) == 0)
					{
						printf("\n-->Confederacion OK <--\n");
						banderaConfederacion = 0;
					}
					break;
				case 4://salir
					if(banderaCamisetas == 0 && banderaConfederacion == 0 && banderaPosicion == 0 )
					{
						banderaSalir = 0;
					}else{
						if(banderaCamisetas == 0 && banderaConfederacion == 0 && banderaPosicion == -1)
						{
							printf("\nLe falta la posicion del jugador , no puede salir");

						}else if(banderaConfederacion == 0 && banderaPosicion == 0 && banderaCamisetas == -1)
						{
							printf("\nLe falta el numero de camiseta , no puede salir");

						}else if(banderaCamisetas == 0 && banderaPosicion == 0 && banderaConfederacion == -1)
						{
							printf("\nLe falta la confederacion , no puede salir");
						}else{

							if(banderaCamisetas == 0 && banderaConfederacion == -1 && banderaPosicion == -1)
							{
								printf("\nLe falta la confederacion , no puede salir");
								printf("\nLe falta la posicion del jugador , no puede salir");
							}else if(banderaConfederacion == 0 && banderaCamisetas == -1 && banderaPosicion == -1)
							{
								printf("\nLe falta el numero de camiseta , no puede salir");
								printf("\nLe falta la posicion del jugador , no puede salir");
							}else if(banderaPosicion == 0 && banderaConfederacion == -1 && banderaCamisetas == -1)
							{
								printf("\nLe falta la confederacion , no puede salir");
								printf("\nLe falta el numero de camiseta , no puede salir");
							}
						}
					}
					break;
			}

		} while (banderaSalir == -1);
	}


	return retorno;
}



int cargarJugador(int* contadorArqueros , int* contadorDefensores , int* contadorMediocampistas , int* contadorDelanteros  )
{
	int opcion ;
	int bandera = -1;
	int retorno = -1;
//	int aux_contadorArqueros = 0;
//	int aux_contadorDefensores = 0;
//	int aux_contadorMediocampistas = 0;
//	int aux_contadorDelanteros = 0;


	if(contadorArqueros != NULL && contadorDefensores != NULL && contadorMediocampistas != NULL && contadorDelanteros != NULL)
	{
		retorno = 0;
		do {
			printf("\n1)Arquero\n2)Defensor\n3)Mediocampista\n4)Delantero");
			utn_pedirNumeroEntero(&opcion, "\nIngrese una posicion  :", "\nError", 4, 1);
			switch(opcion)
			{
				case 1:
					if(*contadorArqueros < 2 && bandera == -1 )
					{
						printf("\n--> Posicion Arquero OK<--\n");

						*contadorArqueros += 1;
						bandera = 0;
					}else{
						printf("\nXXXXXXXXX->NO puede haber mas de 2 Arqueros <-XXXXXXXXX\n");
					}
					break;
				case 2:
					if(*contadorDefensores < 8 && bandera == -1 )
					{
						printf("\n--> Posicion Defensor OK<--\n");

						*contadorDefensores += 1;
						bandera = 0;

					}else{
						printf("\nXXXXXXXXX-> NO puede haber mas de 8 Defensores <-XXXXXXXXX\n");
					}
					break;
				case 3:
					if(*contadorMediocampistas < 8 && bandera == -1)
					{
						printf("\n--> Posicion Mediocampista OK<--\n");
						*contadorMediocampistas += 1;

						bandera = 0;

					}else{
						printf("\nXXXXXXXXX-> NO puede haber mas de 8 Mediocampistas <-XXXXXXXXX\n");
					}
					break;
				case 4:
					if(*contadorDelanteros < 4 && bandera == -1)
					{
						printf("\n--> Posicion Delantero OK<--\n");
						*contadorDelanteros += 1;
						bandera = 0;
					}else{
						printf("\nXXXXXXXXX-> NO puede haber mas de 4 Delanteros <-XXXXXXXXX\n");
					}
					break;
				default : printf("\nOpcion incorrecta");
			}

		} while (bandera == -1);
	}

	return retorno;
}


int cargar_confederaciones (int* confederacion )
{
	int opcion ;
	int bandera= -1;
	int retorno = -1;

	if(confederacion != NULL)
	{
		retorno = 0;
		do {
			printf("\n1)AFC en Asia\n2)CAF en Africa\n3)CONCACAF en zona del Norte\n4)CONMEBOL en sudAmerica\n5)UEFA en Europa\n6)OFC en Oceania");
			utn_pedirNumeroEntero(&opcion, "\nIngrese una confederacion : ", "\nError", 6, 1);
			switch(opcion)
			{
				case 1:
					printf("\n*********AFC en Asia*********\n");
					if(bandera == -1)
					{
						bandera = 0;
						*confederacion = CONFEDERACION_AFC_ASIA;
					}
					break;
				case 2:
					printf("\n*********CAF en Africa*********\n");
					if(bandera == -1)
					{
						bandera = 0;
						*confederacion = CONFEDERACION_CAF_AFRICA;
					}
					break;
				case 3:
					printf("\n*********CONCACAF en zona del Norte*********\n");
					if(bandera == -1)
					{
						*confederacion = CONFEDERACION_CONCACAF_ZONA_NORTE;
						bandera = 0;
					}
					break;
				case 4:
					printf("\n*********CONMEBOL en sudAmerica*********\n");
					if(bandera == -1)
					{
						bandera = 0;
						*confederacion = CONFEDERACION_CONMEBOL_SUDAMERICA;
					}
					break;
				case 5:
					printf("\n*********UEFA en Europa*********\n");
					if(bandera == -1)
					{
						bandera = 0;
						*confederacion = CONFEDERACION_UEFA_EUROPA;
					}
					break;
				case 6:
					printf("\n*********OFC en Oceania*********\n");
					if(bandera == -1)
					{
						bandera = 0;
						*confederacion = CONFEDERACION_OFC_OCEANIA;
					}
					break;
				default : printf("\nOpcion Incorrecta ");
			}
		} while (bandera == -1);

	}

	return retorno;
}

int	subMenu_costosDeMantenimiento (int* opcionCostos ,float* costoTransporte , float* costoHospedaje ,float* costoComida )
{
	int retono = -1;
	int opcion ;
	int banderaCostoHospedaje = -1;
	int banderaCostoComida	= -1;
	int banderaCostoTransporte = -1;
	int banderaSalir = -1;

	if(opcionCostos != NULL && costoTransporte != NULL && costoHospedaje != NULL && costoComida != NULL )
	{
		retono = 0;
		printf("------------------------subMenu Costos de Mantenimiento------------------------");
		printf("\nHasta que cada Costo no tenga un valor definido , no se le va a dejar salir \n");
		do {
			printf("\n1)Costo de hospedaje\n2)Costo de comida\n3)Costo de transporte\n4)Salir");
			utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion :", "\nError", 4, 1);
			switch(opcion)
			{
				case 1:
					printf("\n*********Costo de Hospedaje*********\n");
					if(utn_pedirNumeroFlotante(costoHospedaje,"\nIngrese el costo del Hospedaje (entre 0.0 y 10000.00): ", "\nError", 10000.00, 0.0) == 0)
					{
						printf("\n--> Costo de Hospedaje OK <--\n");
						banderaCostoHospedaje = 0;
					}
					break;
				case 2:
					printf("\n*********Costo de comida*********\n");
					if(utn_pedirNumeroFlotante(costoComida, "\nIngrese el costo de la Comida (entre 0.0 y 10000.00): ", "\nError", 10000.0, 0.0) == 0)
					{
						printf("\n--> Costo de comida OK <--\n");
						banderaCostoComida = 0;
					}
					break;
				case 3:
					printf("\n*********Costo de transporte*********\n");
					if(utn_pedirNumeroFlotante(costoTransporte, "\nIngrese el costo del Transporte (entre 0.0 y 10000.00): ", "\nError", 10000.0, 0.0) == 0)
					{
						printf("\n--> Costo de transporte OK <--\n");
						banderaCostoTransporte = 0;

					}
					break;
				case 4:
						if(banderaCostoComida == 0 && banderaCostoHospedaje == 0 && banderaCostoTransporte == 0)
						{
							printf("\n*********Salir*********\n");
							banderaSalir = 0;

						}else{
							printf("\nHasta que cada Costo no tenga un valor definido , no se le va a dejar salir \n");
						}
					break;

				default : printf("\nOpcion Incorrecta ");
			}
		} while (banderaSalir == -1);

	}


	return retono;
}
