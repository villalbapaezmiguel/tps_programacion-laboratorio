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
					informar_listadoConfederacionConSusJugadores(listadoJugador, largoJugador, listadoConfederacion, largoConfederacion);
					break;
				case 3:
					printf("\n<<3)Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio>>");
					informar_totalPromedioSalarios(listadoJugador, largoJugador);
					break;
				case 4:
					printf("\n<<4)Informar la confederación con mayor cantidad de años de contratos total>>");
					informar_confederacionMayorCantidadContratoTotal(listadoJugador, largoJugador);
					break;
				case 5:
					printf("\n<<5)Informar porcentaje de jugadores por cada confederación.>>");
					informar_porcentajeJugadoresPorCadaConfederacion(listadoJugador, largoJugador);
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

	for (i = 0; i < largoConfederacion; ++i) {//ordenamos la confederacion

		if(strncmp(listaConfederacion[i].nombre, listaConfederacion[i+1].nombre, NOMBRE_CONFEDERACION) > 0)
		{
				auxConfederacion = listaConfederacion[i];
				listaConfederacion[i] = listaConfederacion[i+1];
				listaConfederacion[i+1] = auxConfederacion;
		}
	}

}

/*void informar_listadoConfederacionConSusJugadores(eJugador* pListadoJugador, int largoJugador,eConfederacion* pListadoConfederacion, int largoConfederacion )
 *Objetivo de la funcion :
 * 	da un listados a todas las confederaciones con sus jugadores.
 *
 *ParaMetros : void
 * Parametro : eJugador* punteroArrayJugador , tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largoJugador : tipo entero , es el largo del array de estrutura
 * Parametro : eConfederacion* pListadoConfederacion, tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largoConfederacion : tipo entero , es el largo del array de estrutura
 *
 *Variables :
 * int i ; tipo entero , es un contador que va a ir incrementando dentro del for
 *Retono : void
 **/
void informar_listadoConfederacionConSusJugadores(eJugador* pListadoJugador, int largoJugador,eConfederacion* pListadoConfederacion, int largoConfederacion )
{
	int i,j;

			for (i = 0; i < largoConfederacion; ++i) {
				printf("*************************\n");
				printf("\nCONFEDERACION %s",(*(pListadoConfederacion+i)).nombre);
				printf("*************************\n");
				for (j = 0; j < largoJugador; ++j) {

					if((*(pListadoJugador+j)).idConfederacion == (*(pListadoConfederacion+i)).id)
					{
						printf("\n Nombre Jugador : %s", (*(pListadoJugador+j)).nombre);
						printf("---------------------------\n");
					}
				}
			}
}


/*void informar_listadoConfederacionConSusJugadores(eJugador* pListadoJugador, int largoJugador,eConfederacion* pListadoConfederacion, int largoConfederacion )
 *Objetivo de la funcion :
 * 	da un listado  del total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio
 *
 *ParaMetros : void
 * Parametro : eJugador* punteroArrayJugador , tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largoJugador : tipo entero , es el largo del array de estrutura
 *
 *Variables :
 * int i ; tipo entero , tipo entero ,es un contador que va a ir incrementando dentro del for
 * int j : tipo entero , tipo entero ,es un contador que va a ir incrementando dentro del for
 * float acumuladorSalarios : tipo flotante , es un cumulador de salarios
 * int contadorSalarios : tipo entero , cuenta la cantidad de salirios
 * float promedioSalrios : tipo flotante , va a guardar el promedio de los salarios
 * int contadorCantidadJugadoresSuperanPromedio : tipo entero , cuanta la cantidad de jugadores que superan el promedio
 *Retono : void
 **/
void informar_totalPromedioSalarios(eJugador* pListadoJugador, int largoJugador)
{
	float acumuladorSalarios = 0;
	int contadorSalarios = 0;
	int i, j;
	float promedioSalrios ;
	int contadorCantidadJugadoresSuperanPromedio = 0;

	if(pListadoJugador != NULL && largoJugador > 0)
	{
		for (i = 0; i < largoJugador; ++i) {

			if((*(pListadoJugador+i)).isEmpty == OCUPADO)
			{
				contadorSalarios ++;
				acumuladorSalarios += (*(pListadoJugador+i)).salario;
			}
		}
		promedioSalrios = acumuladorSalarios/contadorSalarios;


		for (j = 0; j < largoJugador; ++j) {

			if((*(pListadoJugador+j)).isEmpty == OCUPADO)
			{
				if((*(pListadoJugador+j)).salario > promedioSalrios)
				{
					contadorCantidadJugadoresSuperanPromedio++;
				}
			}
		}
		printf("\n***************************************************************************************************");
		printf("\nEl total de todos los salarios : %.2f\nEl promedio de todos los salarios : %.2f\nLa cantidad de jugadores que combran mas del salario promedio son : %d",
				acumuladorSalarios, promedioSalrios, contadorCantidadJugadoresSuperanPromedio);
		printf("\n***************************************************************************************************");
	}
}




/*float puntoA_calcularPromedioJugadorMercado (int* cantidadJugadoresIngresados ,int* contadorConfederaciones)

 *Objetivo de la funcion :
 * 	Esta funcion calcula el promedio de un jugador y lo retorna
 *
 *ParaMetros:
 *
 * Parametro : int* cantiadadJugadoresIngresados : tipo entero , Puntero a un entero , es la cantidad de jugadores que fueron ingresados
 * Paramatro : int* contadorConfederaciones : tipo entero , Puntero a un entero , es la cantidad total de una confederacion , pasa por refencia
 *
 *Variables :
 *
 * Variable : float promeddio : tipo flotante ,	es el producto de la cantidad de jugadores de una confederacion multiplicado por 100 y devidido por la cantidad de jugadores ingresados

 *Retono : retorna > 0 si salio bien , de lo contrario -1
 **/
float calcular_PromedioJugador (int* cantidadJugadoresIngresados ,int* contadorConfederaciones)
{
	float promedio = -1;
	if(cantidadJugadoresIngresados != NULL && contadorConfederaciones != NULL)
	{
		promedio = (float)*contadorConfederaciones * 100 / *cantidadJugadoresIngresados;

	}
	return promedio;
}



//Informar la confederación con mayor cantidad de años de contratos total.
/*void informar_listadoConfederacionConSusJugadores(eJugador* pListadoJugador, int largoJugador,eConfederacion* pListadoConfederacion, int largoConfederacion )
 *Objetivo de la funcion :
 * 	informa la confederacion con mayor cantidad de años de contratos Total
 *
 *ParaMetros : void
 * Parametro : eJugador* pListaJugador , tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largoJugador : tipo entero , es el largo del array de estrutura
 *
 *Variables :
 * int i ; tipo entero , tipo entero ,es un contador que va a ir incrementando dentro del for
 *	int acumuladorAniosCONMEBOL : tipo entero , acumula la cantidad de años de contrato de CONMEBOL
 *	int acumuladorAniosUEFA : tipo entero , acumula la cantidad de años de contrato de UEFA
 *	int acumuladorAniosAFC : tipo entero , acumula la cantidad de años de contrato de AFC
 *	int acumuladorAniosCAF : tipo entero , acumula la cantidad de años de contrato de CAF
 *	int acumuladorAniosCONCACAF : tipo entero , acumula la cantidad de años de contrato de CONCACAF
 *	int acumuladorAniosOFC : tipo entero , acumula la cantidad de años de contrato de OFC
 *
 *Retono : void
 **/
void informar_confederacionMayorCantidadContratoTotal(eJugador* pListaJugador, int largoJugador)
{
	int acumuladorAniosCONMEBOL = 0;
	int acumuladorAniosUEFA = 0;
	int acumuladorAniosAFC = 0;
	int acumuladorAniosCAF = 0;
	int acumuladorAniosCONCACAF = 0;
	int acumuladorAniosOFC = 0;
	int i;

	if(pListaJugador != NULL && largoJugador > 0)
	{
		for (i = 0; i < largoJugador; ++i) {

			if((*(pListaJugador+i)).isEmpty == OCUPADO)
			{
				switch((*(pListaJugador+i)).idConfederacion)
				{
				case 100:
					acumuladorAniosCONMEBOL += (*(pListaJugador+i)).aniosContrato;
					break;
				case 101:
					acumuladorAniosUEFA += (*(pListaJugador+i)).aniosContrato;
					break;
				case 102:
					acumuladorAniosAFC += (*(pListaJugador+i)).aniosContrato;
					break;
				case 103:
					acumuladorAniosCAF += (*(pListaJugador+i)).aniosContrato;
					break;
				case 104:
					acumuladorAniosCONCACAF += (*(pListaJugador+i)).aniosContrato;
					break;
				case 105:
					acumuladorAniosOFC += (*(pListaJugador+i)).aniosContrato;
					break;
				}
			}
		}

		if(acumuladorAniosCONMEBOL > acumuladorAniosUEFA &&
				acumuladorAniosCONMEBOL > acumuladorAniosAFC &&
				acumuladorAniosCONMEBOL > acumuladorAniosCAF &&
				acumuladorAniosCONMEBOL > acumuladorAniosCONCACAF &&
				acumuladorAniosCONMEBOL > acumuladorAniosOFC)
		{
			printf("\n***************************************************************************************************");
			printf("\nLa confederacion con mayor cantidad de años total es : CONMEBOL con %d años Totales", acumuladorAniosCONMEBOL);
			printf("\n***************************************************************************************************");
		}
		if(acumuladorAniosUEFA > acumuladorAniosCONMEBOL &&
				acumuladorAniosUEFA > acumuladorAniosAFC &&
				acumuladorAniosUEFA > acumuladorAniosCAF &&
				acumuladorAniosUEFA > acumuladorAniosCONCACAF &&
				acumuladorAniosUEFA > acumuladorAniosOFC)
		{
			printf("\n***************************************************************************************************");
			printf("\nLa confederacion con mayor cantidad de años total es : UEFA con %d años Totales", acumuladorAniosUEFA);
			printf("\n***************************************************************************************************");
		}
		if(acumuladorAniosAFC > acumuladorAniosUEFA &&
				acumuladorAniosAFC > acumuladorAniosCONMEBOL &&
				acumuladorAniosAFC > acumuladorAniosCAF &&
				acumuladorAniosAFC > acumuladorAniosCONCACAF &&
				acumuladorAniosAFC > acumuladorAniosOFC)
		{
			printf("\n***************************************************************************************************");
			printf("\nLa confederacion con mayor cantidad de años total es : AFC con %d años Totales", acumuladorAniosAFC);
			printf("\n***************************************************************************************************");
		}
		if(acumuladorAniosCAF > acumuladorAniosUEFA &&
				acumuladorAniosCAF > acumuladorAniosCONMEBOL &&
				acumuladorAniosCAF > acumuladorAniosCONMEBOL &&
				acumuladorAniosCAF > acumuladorAniosCONCACAF &&
				acumuladorAniosCAF > acumuladorAniosOFC)
		{
			printf("\n***************************************************************************************************");
			printf("\nLa confederacion con mayor cantidad de años total es : CAF con %d años Totales", acumuladorAniosCAF);
			printf("\n***************************************************************************************************");
		}
		if(acumuladorAniosCONCACAF > acumuladorAniosUEFA &&
				acumuladorAniosCONCACAF > acumuladorAniosAFC &&
				acumuladorAniosCONCACAF > acumuladorAniosCAF &&
				acumuladorAniosCONCACAF > acumuladorAniosCONMEBOL &&
				acumuladorAniosCONCACAF > acumuladorAniosOFC)
		{
			printf("\n***************************************************************************************************");
			printf("\nLa confederacion con mayor cantidad de años total es : CONCACAF con %d años Totales", acumuladorAniosCONCACAF);
			printf("\n***************************************************************************************************");
		}
		if(acumuladorAniosOFC > acumuladorAniosUEFA &&
				acumuladorAniosOFC > acumuladorAniosAFC &&
				acumuladorAniosOFC > acumuladorAniosCAF &&
				acumuladorAniosOFC > acumuladorAniosCONMEBOL &&
				acumuladorAniosOFC > acumuladorAniosCONCACAF )
		{
			printf("\n***************************************************************************************************");
			printf("\nLa confederacion con mayor cantidad de años total es : OFC con %d años Totales", acumuladorAniosOFC);
			printf("\n***************************************************************************************************");
		}
	}else{
		printf("\nError con la lista de confederaciones y los jugadores!! ");
	}
}


/*void informar_porcentajeJugadoresPorCadaConfederacion(eJugador* pListaJugador , int largoJugador)
 *Objetivo de la funcion :
 * 	Informar el porcentaje de jugadores por cada confederación.
 *
 *ParaMetros : void
 * Parametro : eJugador* pListaJugador , tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largoJugador : tipo entero , es el largo del array de estrutura
 *
 *Variables :
 * int i ; tipo entero , tipo entero ,es un contador que va a ir incrementando dentro del for
 *	int contadorCONMEBOL : tipo entero , acumula la cantidad de años de contrato de CONMEBOL
 *	int contadorUEFA : tipo entero , cuenta la cantidad de jugadores de UEFA
 *	int contadorAFC : tipo entero , cuenta la cantidad de jugadores de  AFC
 *	int contadorCAF : tipo entero , cuenta la cantidad de jugadores de CAF
 *	int contadorCONCACAF : tipo entero , cuenta la cantidad de jugadores de CONCACAF
 *	int contadorOFC : tipo entero , cuenta la cantidad de jugadores de OFC
 *
 *Retono : void
 **/
void informar_porcentajeJugadoresPorCadaConfederacion(eJugador* pListaJugador , int largoJugador)
{

	int i;
//contador de cada confederacion
	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorOFC = 0;
//porcentaje de cada confederacion
	float porcentajeCONMEBOL = 0;
	float porcentajeUEFA = 0;
	float porcentajeAFC = 0;
	float porcentajeCAF = 0;
	float porcentajeCONCACAF = 0;
	float porcentajeOFC = 0;
//contador total de jugadores ingresados
	int contadorTotalJugadores = 0;
	char porcentaje = '%';

	if(pListaJugador != NULL && largoJugador)
	{

		for (i = 0; i < largoJugador; ++i) {

			if((*(pListaJugador+i)).isEmpty == OCUPADO)
			{
				contadorTotalJugadores ++;
				switch((*(pListaJugador+i)).idConfederacion)
				{
				case 100:
					contadorCONMEBOL ++;
					break;
				case 101:
					contadorUEFA ++;
					break;
				case 102:
					contadorAFC ++;
					break;
				case 103:
					contadorCAF ++;
					break;
				case 104:
					contadorCONCACAF ++;
					break;
				case 105:
					contadorOFC ++;
					break;
				}
			}
		}

		porcentajeUEFA = (float)(100*contadorUEFA)/contadorTotalJugadores;
		porcentajeCONMEBOL = (float) (100*contadorCONMEBOL)/contadorTotalJugadores;
		porcentajeCAF = (float)(100*contadorCAF)/contadorTotalJugadores;
		porcentajeCONCACAF = (float)(100*contadorCONCACAF)/contadorTotalJugadores;
		porcentajeAFC = (float)(100*contadorAFC)/contadorTotalJugadores;
		porcentajeOFC = (float)(100*contadorOFC)/contadorTotalJugadores;


		printf("\n**************************************");
		printf("\nUEFA : %.2f %c", porcentajeUEFA, porcentaje);
		printf("\nCONMEBOL : %.2f %c", porcentajeCONMEBOL, porcentaje);
		printf("\nCAF : %.2f %c", porcentajeCAF , porcentaje);
		printf("\nCONCACAF : %.2f %c", porcentajeCONCACAF , porcentaje);
		printf("\nAFC : %.2f %c", porcentajeAFC , porcentaje);
		printf("\nOFC : %.2f %c", porcentajeOFC , porcentaje);
		printf("\n**************************************");

	}
}










