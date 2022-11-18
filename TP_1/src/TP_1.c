/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"

int main(void) {

	setbuf(stdout,NULL);

	int opcion;
	//banderas que nos sirven para que el usuario no pueda ingresar al punto 3 y 4 si no tienen datos ingresados en los puntos 1 y 2.
	int banderaPuntoUno = -1;
	int banderaPuntoDos = -1;

	//Costos del matentenimiento iniciciales
	float costoTransporte_inicial = 0;
	float costoHospedaje_inicial = 0;
	float costoComida_inicial = 0;
	int opcionCosto ;

	//Carga de jugadores
	int contadorArqueros = 0;
	int contadorDefensores = 0;
	int contadorMediocampistas = 0;
	int contadorDelanteros = 0;
	int confederacion ;

	//cantidad de jugadores ingresados
	int contadorJugadoresIngresados = 0;

	//Varibles del Punto A
	int contador_AFC_ASIA = 0;
	int contador_CAF_AFRICA = 0;
	int contador_CONCACAF_ZONA_NORTE = 0;
	int contador_CONMEBOL_SUDAMERICA = 0;
	int contador_UEFA_EUROPA = 0;
	int contador_OFC_OCEANIA = 0;
	float promedio_AFC_ASIA = 0;
	float promedio_CAF_AFRICA = 0;
	float promedio_CONCACAF_ZONA_NORTE = 0;
	float promedio_CONMEBOL_SUDAMERICA = 0;
	float promedio_UEFA_EUROPA = 0;
	float promedio_OFC_OCEANIA = 0;

	//Varibles del Punto B
	float costoMantenimientoTotal;


	//Varibles del Punto C
	int auxCostoAumento ;
	int banderaAumento = -1;
	float costoMantenimientoTotal_conAumento;

	printf("\n------------------------Menu Principal------------------------\n");
	do {
		printf("\n1.Ingreso de los costos de mantenimiento\n Costo Transporte -> $%.2f\n Costo Hospedaje -> $%.2f\n Costo Comida -> $%.2f",costoTransporte_inicial, costoHospedaje_inicial, costoComida_inicial);
		printf("\n2.Carga de Jugadores\n Arqueros -> %d\n Defensores -> %d\n Mediocampistas -> %d\n Delanteros -> %d",contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);
		printf("\n3.Realizar todos los Calculos\n4.Informar todos los Resultados\n5.Salir");
		utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion : ", "\nError", 5, 1);
		switch(opcion)
		{
			case 1:
				printf("\n********Costos de mantenimiento*********\n");
				banderaPuntoUno = 0;
				if(subMenu_costosDeMantenimiento(&opcionCosto, &costoTransporte_inicial, &costoHospedaje_inicial, &costoComida_inicial) == 0)
				{
					printf("\n------------------Costos de Mantenimiento OK------------------\n");
				}
				break;
			case 2:
				printf("\n*********Carga de jugadores*********\n");
				banderaPuntoDos = 0;
				if(subMenu_cargaJugadores(&contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros, &confederacion) == 0)
				{
					contadorJugadoresIngresados ++;
					switch(confederacion)
					{
						case 1:
							contador_AFC_ASIA ++;
							printf("\n*********AFC en Asi : %d *********\n", contador_AFC_ASIA);
							break;
						case 2:
							contador_CAF_AFRICA ++;
							printf("\n*********CAF en Africa : %d *********\n", contador_CAF_AFRICA);
							break;
						case 3:
							contador_CONCACAF_ZONA_NORTE ++;
							printf("\n*********CONCACAF en zona del Norte : %d *********\n", contador_CONCACAF_ZONA_NORTE);
							break;
						case 4:
							contador_CONMEBOL_SUDAMERICA ++;
							printf("\n*********CONMEBOL en sudAmerica : %d *********\n", contador_CONMEBOL_SUDAMERICA);
							break;
						case 5:
							contador_UEFA_EUROPA ++;
							printf("\n*********UEFA en Europa : %d *********\n", contador_UEFA_EUROPA);
							break;
						case 6:
							contador_OFC_OCEANIA ++;
							printf("\n*********OFC en Oceania : %d *********\n", contador_OFC_OCEANIA);
							break;
					}

					printf("\n------------------Carga de Jugadores OK------------------\n");
				}
				break;
			case 3:
				if(banderaPuntoUno == 0 && banderaPuntoDos == 0)
				{
					printf("\n*********Realizar todos los Calculos*********\n");

						if(puntoA_calcularPromedios(&contadorJugadoresIngresados, &contador_AFC_ASIA, &contador_CAF_AFRICA, &contador_CONCACAF_ZONA_NORTE, &contador_CONMEBOL_SUDAMERICA, &contador_UEFA_EUROPA, &contador_OFC_OCEANIA,
								&promedio_AFC_ASIA, &promedio_CAF_AFRICA, &promedio_CONCACAF_ZONA_NORTE, &promedio_CONMEBOL_SUDAMERICA, &promedio_UEFA_EUROPA, &promedio_OFC_OCEANIA) == 0)
						{
							printf("\npunto A ok");
						}
						if(puntoB_calcularCostosMantenimientos(&contadorJugadoresIngresados, &costoTransporte_inicial, &costoHospedaje_inicial, &costoComida_inicial, &costoMantenimientoTotal) == 0)
						{
							printf("\npunto B ok");
						}
						if(contador_UEFA_EUROPA > contador_AFC_ASIA && contador_UEFA_EUROPA > contador_CAF_AFRICA && contador_UEFA_EUROPA  > contador_CONCACAF_ZONA_NORTE && contador_UEFA_EUROPA > contador_CONMEBOL_SUDAMERICA && contador_UEFA_EUROPA > contador_OFC_OCEANIA)
						{
							auxCostoAumento = costoMantenimientoTotal ;
							auxCostoAumento = auxCostoAumento * 35 /100;
							costoMantenimientoTotal_conAumento = costoMantenimientoTotal + auxCostoAumento;
							banderaAumento = 0;
							printf("\nPunto C ok");
						}

				}else{
					printf("\nERROR no tienen datos ingresados en los puntos 1 y 2\n");
				}
				break;
			case 4:
				if(banderaPuntoUno == 0 && banderaPuntoDos == 0)
				{
					printf("\n*********Informar todos los Resultados*********\n");
					informar(&promedio_AFC_ASIA, &promedio_CAF_AFRICA, &promedio_CONCACAF_ZONA_NORTE, &promedio_CONMEBOL_SUDAMERICA, &promedio_UEFA_EUROPA, &promedio_OFC_OCEANIA, &costoMantenimientoTotal, &auxCostoAumento, &banderaAumento, &costoMantenimientoTotal_conAumento);

				}else{
					printf("\nERROR no tienen datos ingresados en los puntos 1 y 2\n");
				}

				break;
			case 5:
				printf("\n*********Salir*********\n");
				break;
			default : printf("\nOpcion Incorrecta ");
		}

	} while (opcion != 5);

	return EXIT_SUCCESS;

}

