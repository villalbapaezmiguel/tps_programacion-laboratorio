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
int	subMenu_confederaciones (void);//falta mejorarlos
int	subMenu_costosDeMantenimiento (void);//falta mejorarlos
int main(void) {

//	int costoTransporte ;
//	int costoHospedaje ;
//	int costoComida ;
//	int costoMatenimientoTotal ;


	subMenu_costosDeMantenimiento();


	return EXIT_SUCCESS;
}

int	subMenu_confederaciones (void)
{
	int retono = -1;
	int opcion ;

	printf("------------------------subMenu de Confederaciones------------------------");
	do {
		printf("\n1)AFC en Asia\n2)CAF en Africa\n3)CONCACAF en zona del Norte\n4)CONMEBOL en sudAmerica\n5)UEFA en Europa\n6)OFC en Oceania\n7)Salir");
		utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion : ", "\nError", 7, 1);
		switch(opcion)
		{
			case 1:
				printf("\n*********AFC en Asia*********\n");
				break;
			case 2:
				printf("\n*********CAF en Africa*********\n");
				break;
			case 3:
				printf("\n*********CONCACAF en zona del Norte*********\n");
				break;
			case 4:
				printf("\n*********CONMEBOL en sudAmerica*********\n");
				break;
			case 5:
				printf("\n*********UEFA en Europa*********\n");
				break;
			case 6:
				printf("\n*********OFC en Oceania*********\n");
				break;
			case 7:
				printf("\n*********Salir*********\n");
				break;
			default : printf("\nOpcion Incorrecta ");
		}


	} while (opcion != 7);

	return retono;
}

int	subMenu_costosDeMantenimiento (void)
{
	int retono = -1;
	int opcion ;

	printf("------------------------subMenu Costos de Mantenimiento------------------------");
	do {
		printf("\n1)Costo de hospedaje\n2)Costo de comida\n3)Costo de transporte\n4)Salir");
		utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion :", "\nError", 4, 1);
		switch(opcion)
		{
			case 1:
				printf("\n*********Costo de hospedaje*********\n");
				break;
			case 2:
				printf("\n*********Costo de comida*********\n");
				break;
			case 3:
				printf("\n*********Costo de transporte*********\n");
				break;
			case 4:
				printf("\n*********Salir*********\n");
				break;

			default : printf("\nOpcion Incorrecta ");
		}


	} while (opcion != 4);

	return retono;
}
