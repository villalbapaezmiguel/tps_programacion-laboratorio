/*
 * funciones.c
 *
 *  Created on: 25 sep. 2022
 *      Author: miguel
 */
#include "funciones.h"

/*void menuPrincipal(int* opcion )
 *Objetivo de la funcion :
 * 	es el menu principal , sus opciones son : 1. Ingreso de los costos de Mantenimiento , 2. Carga de jugadores , 3. Realizar todos los cálculos , 4. Informar todos los resultados , 5. Salir.
 *
 *ParaMetros : ninguno
 *
 *Variables :
 * int opcion : tipo entero
 * char bufferString : tipo char , se encarga de pedir el numero para luego pasarle al puntero pRespuetas que se encuentra como parametro (int* pRespuesta)
 *
 *Retono : no retorna nada
 *
 **/
void menuPrincipal(void)
{
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


}


/*void informar (float* promedio_AFC_ASIA , float* promedio_CAF_AFRICA , float* promedio_CONCACAF_ZONA_NORTE , float* promedio_CONMEBOL_SUDAMERICA , float* promedio_UEFA_EUROPA , float* promedio_OFC_OCEANIA ,float* costoMantenimientoTotal , int* auxAumento, int* banderaAumento , float* costoMantenimientoTotalConAumento)
 *Objetivo de la funcion :
 * 	imprime todos los datos calculados del punto 3 y si el costo de mantenimiento recibió un aumento ,
 * 	va a informar el valor original, el valor del aumento y el valor actualizado con el aumento agregado
 *
 *ParaMetros:
 *
 * Parametro : float* promedio_AFC_ASIA  : tipo flotante , Puntero a un flotante , es el promedio de AFC de Asia
 * Parametro : float* promedio_ CAF_AFRICA : tipo flotante , Puntero a un flotante , es el promedio de CAF de Africa
 * Parametro : float* promedio_ CONCACAF_ZONA_NORTE : tipo flotante , Puntero a un flotante , es el promedio de CONCACAF de Zona norte
 * Parametro : float* promedio_ CONMEBOL_SUDAMERICA : tipo flotante , Puntero a un flotante , es el promedio de CONMEBOL en Sudamerica
 * Parametro : float* promedio_ CONMEBOL_UEFA_EUROPA : tipo flotante , Puntero a un flotante , es el promedio de UEFA en Europa
 * Parametro : float* promedio_ CONMEBOL_OFC_OCEANIA : tipo flotante , Puntero a un flotante , es el promedio de OFC  en Oceania
 * Parametro : float* costoMantenimientoTotal : tipo flotante , Puntero a un flotante , es el costo de mantenimiento total SIN aumento
 * Parametro : int* auxAumento : tipo entero : Puntero a un entero , es un auxiliar costo de mantenimiento , nos pasa por referencia el valor de cuanto se va a aumentar el costo
 * Parametro : int* banderaAumento , tipo entero : Puntero a un entero , es una bandera que nos va devolver 0 Si la mayoría del plantel está compuesta por
 * jugadores de la confederación europea el costo de mantenimiento va a tener un aumento del 35%.
 * Parametro : float* costoMantenimientoTotalConAumento , tipo floatante : Puntero a un flotante , es el costo de mantenimiento total CON aumento
 *
 *Variables : ninguna
 *
 *Retono : no retorna nada
 **/
void informar (float* promedio_AFC_ASIA , float* promedio_CAF_AFRICA , float* promedio_CONCACAF_ZONA_NORTE , float* promedio_CONMEBOL_SUDAMERICA , float* promedio_UEFA_EUROPA , float* promedio_OFC_OCEANIA ,float* costoMantenimientoTotal , int* auxAumento, int* banderaAumento , float* costoMantenimientoTotalConAumento)
{

	if(promedio_AFC_ASIA != NULL && promedio_CAF_AFRICA != NULL && promedio_CONCACAF_ZONA_NORTE != NULL && promedio_CONMEBOL_SUDAMERICA != NULL && promedio_UEFA_EUROPA != NULL &&
			promedio_OFC_OCEANIA != NULL && costoMantenimientoTotal != NULL && banderaAumento != NULL && auxAumento != NULL && costoMantenimientoTotalConAumento != NULL)
	{
		printf("\nPorcentaje AFC en Asia : %.2f",*promedio_AFC_ASIA);
		printf("\nPorcentaje CAF en Africa : %.2f", *promedio_CAF_AFRICA);
		printf("\nPorcentaje CONCACAF en Zona Norte : %.2f", *promedio_CONCACAF_ZONA_NORTE);
		printf("\nPorcentaje CONMEBOL en Sedamerica : %.2f", *promedio_CONMEBOL_SUDAMERICA);
		printf("\nPorcentaje UEFA en Europa : %.2f", *promedio_UEFA_EUROPA);
		printf("\nPorcentaje OFC en Oceania: %.2f", *promedio_OFC_OCEANIA);
		printf("\nbandera aumento : %d", *banderaAumento);
		if(*banderaAumento == 0)
		{
			printf("\nEl costo de mantenimiento era de $ %.2f y recibio un aumento de : $ %d , su nuevo valor es de : $ %.2f\n", *costoMantenimientoTotal, *auxAumento, *costoMantenimientoTotalConAumento);
		}else{
			printf("\nEl costo de mantenimiento era de $%.2f \n", *costoMantenimientoTotal);
		}

	}else{
		printf("\nError al informar \n");
	}

}



/*int puntoB_calcularCostosMantenimientos(int* cantiadadJugadoresIngresados , float* costoTransporte , float* costoHospedaje , float* costoComida ,float* costoMantenimientoTotal )

 *Objetivo de la funcion :
 * 	Esta funcion calcula los costo(NO los muestra ) del punto 3.b : Calcular el costo de mantenimiento
 *
 *ParaMetros:
 *
 * Parametro : int* cantiadadJugadoresIngresados : tipo entero , Puntero a un entero , es la cantidad de jugadores que fueron ingresados
 * Parametro :  float* costoTransporte : tipo flotante , Puntero a un flotante , es el costo del Transporte pasado por refencia
 * Parametro : float* costoHospedaje : tipo flotante , Puntero a un flotante , es el costo del Hospedaje pasado por refencia
 * Parametro : float* costoComida : tipo flotante , Puntero a un flotante , es el costo del Comida pasado por refencia
 * Parametro : float* costoMantenimientoTotal : tipo flotante , Puntero a un flotante , es el costo de mantenimiento pasado por refencia
 *
 *Variables :
 *
 * Variable : int retorno : tipo entero , es el encargado de informar si salio todo ok
 * Variable : float costoTransporteTotal , se encarga de obtener el valor total del costo del Transporte
 * Variable : float costoHospedajeTotal , se encarga de obtener el valor total del costo del Hospedaje
 * Variable : float costoComidaTotal , se encarga de obtener el valor total del costo de la Comida
 *
 *Retono : retorna 0 si salio bien , de lo contrario -1
 **/
int puntoB_calcularCostosMantenimientos(int* cantiadadJugadoresIngresados , float* costoTransporte , float* costoHospedaje , float* costoComida ,float* costoMantenimientoTotal )
{
	int retorno = -1;
	float costoTransporteTotal ;
	float costoHospedajeTotal;
	float costoComidaTotal;
//validar todo
	if(cantiadadJugadoresIngresados != NULL && costoTransporte != NULL && costoHospedaje != NULL && costoComida != NULL && costoMantenimientoTotal != NULL )
	{

		costoTransporteTotal = *costoTransporte * *cantiadadJugadoresIngresados;
		costoHospedajeTotal =  *costoHospedaje * *cantiadadJugadoresIngresados;
		costoComidaTotal = *costoComida * *cantiadadJugadoresIngresados ;

		*costoMantenimientoTotal = (float)costoTransporteTotal + costoHospedajeTotal + costoComidaTotal ;
		retorno = 0;
	}

	return retorno;
}


/*int puntoA_calcularPromedios(int* cantiadadJugadoresIngresados ,int* contador_AFC_ASIA , int* contador_CAF_AFRICA , int* contador_CONCACAF_ZONA_NORTE , int* contador_CONMEBOL_SUDAMERICA , int* contador_UEFA_EUROPA , int* contador_OFC_OCEANIA,
		float* promedio_AFC_ASIA , float* promedio_CAF_AFRICA , float* promedio_CONCACAF_ZONA_NORTE , float* promedio_CONMEBOL_SUDAMERICA , float* promedio_UEFA_EUROPA , float* promedio_OFC_OCEANIA)
 *Objetivo de la funcion :
 * 	Esta funcion calcula(NO los muestra ) el promedio de todos lo jugadores y los pasa por referencia del punto 3.a : Calcular el promedio de jugadores de cada mercado
 *
 *ParaMetros:
 *
 * Parametro : int* cantiadadJugadoresIngresados : tipo entero , Puntero a un entero , es la cantidad de jugadores que fueron ingresados ,pasado por referencia
 * Parametro : int* contador_AFC_ASIA : tipo entero , Puntero a un entero , son las cantidad de veces que ingresaron a la confederacion AFC en Asia , pasado por referencia
 * Parametro : int* contador_CAF_AFRICA : tipo entero , Puntero a un entero , son las cantidad de veces que ingresaron a la confederacion CAF en Africa , pasado por referencia
 * Parametro : int* contador_CONCACAF_ZONA_NORTE : tipo entero , Puntero a un entero , son las cantidad de veces que ingresaron a la confederacion CONCACAF en Zona del Norte , pasado por referencia
 * Parametro : int* contador_CONCACAF_ZONA_NORTE : tipo entero , Puntero a un entero , son las cantidad de veces que ingresaron a la confederacion CONCACAF en Zona del Norte , pasado por referencia
 * Parametro : int* contador_CONMEBOL_SUDAMERICA : tipo entero , Puntero a un entero , son las cantidad de veces que ingresaron a la confederacion CONMEBOL en Sudamerica , pasado por referencia
 * Parametro : int* contador_UEFA_EUROPA : tipo entero , Puntero a un entero , son las cantidad de veces que ingresaron a la confederacion UEFA en Europa , pasado por referencia
 * Parametro : int* contador_OFC_OCEANIA : tipo entero , Puntero a un entero , son las cantidad de veces que ingresaron a la confederacion OFC en Oceania , pasado por referencia
 * Parametro : float* promedio_AFC_ASIA  : tipo flotante , Puntero a un flotante , es el promedio de AFC de Asia
 * Parametro : float* promedio_ CAF_AFRICA : tipo flotante , Puntero a un flotante , es el promedio de CAF de Africa
 * Parametro : float* promedio_ CONCACAF_ZONA_NORTE : tipo flotante , Puntero a un flotante , es el promedio de CONCACAF de Zona norte
 * Parametro : float* promedio_ CONMEBOL_SUDAMERICA : tipo flotante , Puntero a un flotante , es el promedio de CONMEBOL en Sudamerica
 * Parametro : float* promedio_ CONMEBOL_UEFA_EUROPA : tipo flotante , Puntero a un flotante , es el promedio de UEFA en Europa
 * Parametro : float* promedio_ CONMEBOL_OFC_OCEANIA : tipo flotante , Puntero a un flotante , es el promedio de OFC  en Oceania
 * Parametro : float* costoMantenimientoTotal : tipo flotante , Puntero a un flotante , es el costo de mantenimiento total SIN aumento
 * Parametro : int* auxAumento : tipo entero : Puntero a un entero , es un auxiliar costo de mantenimiento , nos pasa por referencia el valor de cuanto se va a aumentar el costo
 * Parametro : int* banderaAumento , tipo entero : Puntero a un entero , es una bandera que nos va devolver 0 Si la mayoría del plantel está compuesta por
 * jugadores de la confederación europea el costo de mantenimiento va a tener un aumento del 35%.
 * Parametro : float* costoMantenimientoTotalConAumento , tipo floatante : Puntero a un flotante , es el costo de mantenimiento total CON aumento
 *
 *Variables :
 * Variable : int retorno : tipo entero  , es el encargado de informar si salio todo ok
 *
 *Retono :
 * return :  retorna 0 si salio bien , de lo contrario -1
 **/
int puntoA_calcularPromedios(int* cantiadadJugadoresIngresados ,int* contador_AFC_ASIA , int* contador_CAF_AFRICA , int* contador_CONCACAF_ZONA_NORTE , int* contador_CONMEBOL_SUDAMERICA , int* contador_UEFA_EUROPA , int* contador_OFC_OCEANIA,
		float* promedio_AFC_ASIA , float* promedio_CAF_AFRICA , float* promedio_CONCACAF_ZONA_NORTE , float* promedio_CONMEBOL_SUDAMERICA , float* promedio_UEFA_EUROPA , float* promedio_OFC_OCEANIA)
{
	int retorno = -1;

	if(cantiadadJugadoresIngresados != NULL && contador_AFC_ASIA != NULL && contador_CAF_AFRICA != NULL && contador_CONCACAF_ZONA_NORTE != NULL && contador_CONMEBOL_SUDAMERICA != NULL &&
			promedio_AFC_ASIA != NULL && promedio_CAF_AFRICA != NULL && promedio_CONCACAF_ZONA_NORTE != NULL && promedio_CONMEBOL_SUDAMERICA != NULL && promedio_UEFA_EUROPA != NULL && promedio_OFC_OCEANIA != NULL)
	{
		*promedio_AFC_ASIA = puntoA_calcularPromedioJugadorMercado(cantiadadJugadoresIngresados, contador_AFC_ASIA);
		*promedio_CAF_AFRICA = puntoA_calcularPromedioJugadorMercado(cantiadadJugadoresIngresados, contador_CAF_AFRICA);
		*promedio_CONCACAF_ZONA_NORTE = puntoA_calcularPromedioJugadorMercado(cantiadadJugadoresIngresados, contador_CONCACAF_ZONA_NORTE);
		*promedio_CONMEBOL_SUDAMERICA = puntoA_calcularPromedioJugadorMercado(cantiadadJugadoresIngresados, contador_CONMEBOL_SUDAMERICA);
		*promedio_UEFA_EUROPA = puntoA_calcularPromedioJugadorMercado(cantiadadJugadoresIngresados, contador_UEFA_EUROPA);
		*promedio_OFC_OCEANIA = puntoA_calcularPromedioJugadorMercado(cantiadadJugadoresIngresados, contador_OFC_OCEANIA);

		retorno = 0;
	}

	return retorno;
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
float puntoA_calcularPromedioJugadorMercado (int* cantidadJugadoresIngresados ,int* contadorConfederaciones)
{
	float promedio = -1;
	if(cantidadJugadoresIngresados != NULL && contadorConfederaciones != NULL)
	{
		promedio = (float)*contadorConfederaciones * 100 / *cantidadJugadoresIngresados;

	}
	return promedio;
}


/*int subMenu_cargaJugadores(int* contadorArqueros , int* contadorDefensores , int* contadorMediocampistas , int* contadorDelanteros , int* confederacion)

 *Objetivo de la funcion :
 * 		es un menu de para cargar jugadores , eso quiere decir que va tener opciones :  el número de camiseta, posición y la confederación en la que está jugando.
 *
 *ParaMetros:
 *
 * Parametro : int* contadorArqueros : tipo entero , Puntero a un entero , es la cantidad de Arqueros que fueron ingresados , pasa por refencia
 * Parametro : int* contadorDefensores : tipo entero , Puntero a un entero , es la cantidad de Defensores que fueron ingresados , pasa por refencia
 * Parametro : int* contadorMediocampistas : tipo entero , Puntero a un entero , es la cantidad de Mediocampistas que fueron ingresados , pasa por refencia
 * Parametro : int* contadorDelanteros : tipo entero , Puntero a un entero , es la cantidad de Delanteros que fueron ingresados , pasa por refencia
 * Parametro : int* confederacion : tipo entero , Puntero a un entero , es la confederacion que se eligio , pasa por refencia
 *
 *Variables :
 *
 *	Variable : int retorno : tipo entero , es el encargado de informar si salio todo ok
 *	Variable : int opcion : tipo entero , se encarga de tomar la opcion que quiera el usuario
 *	Variable : int banderaCamiseta : tipo entero , es una bandera que nos avisa si entro o no en esa ocpion (NO entro : -1 | entro : 0)
 *	Variable : int banderaPosicion : tipo entero , es una bandera que nos avisa si entro o no en esa ocpion (NO entro : -1 | entro : 0)
 *	Variable : int banderaConfederacion : tipo entero , es una bandera que nos avisa si entro o no en esa ocpion (NO entro : -1 | entro : 0)
 *	Variable : int banderaSalir : tipo entero , es una bandera que nos avisa si entro o no en esa ocpion (NO entro : -1 | entro : 0)
 *	Variable : int camiseta : tipo entero , toma el numero de la camiseta que el usuario haya ingresado
 *
 *
 *Retono : retorna > 0 si salio bien , de lo contrario -1
 **/
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
			printf("\n1)Numero de camiseta \n2)Posicion \n3)Confederación en la que está jugando\n4)salir para que se guarden los datos ingresados");
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
					if(subMenu_cargarPosicionDeJugador(contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros) == 0)
					{
						printf("\n--> Posicion OK <--\n");
						banderaPosicion = 0;
					}
					break;
				case 3:
					if(subMenu_cargarConfederacion(confederacion) == 0)
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


/*int cargarJugador(int* contadorArqueros , int* contadorDefensores , int* contadorMediocampistas , int* contadorDelanteros  )

 *Objetivo de la funcion :
 *	es un menu para cargar la posicon del jugador . eso quiere decir que va a tener opciones : arquero , defensor , mediocampista y delantero
 *
 *ParaMetros:
 *
 * Parametro : int* contadorArqueros : tipo entero , Puntero a un entero , es la cantidad de Arqueros que fueron ingresados , pasa por refencia
 * Parametro : int* contadorDefensores : tipo entero , Puntero a un entero , es la cantidad de Defensores que fueron ingresados , pasa por refencia
 * Parametro : int* contadorMediocampistas : tipo entero , Puntero a un entero , es la cantidad de Mediocampistas que fueron ingresados , pasa por refencia
 * Parametro : int* contadorDelanteros : tipo entero , Puntero a un entero , es la cantidad de Delanteros que fueron ingresados , pasa por refencia
 *
 *Variables :
 *
 *	Variable : int retorno : tipo entero , es el encargado de informar si salio todo ok
 *	Variable : int opcion : tipo entero , se encarga de tomar la opcion que quiera el usuario
 *	Variable : int bandera : tipo entero , es una bandera que nos avisa si entro o no en esa ocpion (NO entro : -1 | entro : 0)
 *
 *
 *Retono : retorna > 0 si salio bien , de lo contrario -1
 **/
int subMenu_cargarPosicionDeJugador(int* contadorArqueros , int* contadorDefensores , int* contadorMediocampistas , int* contadorDelanteros  )
{
	int opcion ;
	int bandera = -1;
	int retorno = -1;

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


/*int subMenu_cargarConfederacion (int* confederacion )

 *Objetivo de la funcion :
 *	es un menu para cargar la confederacion de un jugador . eso quiere decir que va a tener opciones : AFC en Asia; CAF en África; CONCACAF en zona del Norte; CONMEBOL en Sudamérica;
	UEFA en Europa; OFC en Oceanía
 *
 *ParaMetros:
 *
 * Parametro : int* confederacion : tipo entero , Puntero a un entero , es la confederacion , pasa por refencia
 *
 *Variables :
 *
 *	Variable : int retorno : tipo entero , es el encargado de informar si salio todo ok
 *	Variable : int opcion : tipo entero , se encarga de tomar la opcion que quiera el usuario
 *	Variable : int bandera : tipo entero , es una bandera que nos avisa si entro o no en esa ocpion (NO entro : -1 | entro : 0)
 *
 *
 *Retono : retorna > 0 si salio bien , de lo contrario -1
 **/
int subMenu_cargarConfederacion (int* confederacion )
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



/*int	subMenu_costosDeMantenimiento (int* opcionCostos ,float* costoTransporte , float* costoHospedaje ,float* costoComida )

 *Objetivo de la funcion :
 *	es un menu para cargar la los costos del mantenimiento de un jugador . eso quiere decir que va a tener opciones : costos de transporte , hospedaje y comida
 *
 *ParaMetros:
 *
 * Parametro : int* opcionCostos : tipo entero , Puntero a un entero , es la opcion que elegio el usuario , pasa por refencia
 * Parametro : float* costoTransporte , tipo flotante , Puntero a un flotante , es el costo dek transporte , pasa por referencia
 * Parametro : float* costoHospedaje , tipo flotante , Puntero a un flotante , es el costo dek hospedaje , pasa por referencia
 * Parametro : float* costoComida , tipo flotante , Puntero a un flotante , es el costo de la comida , pasa por referencia
 *
 *Variables :
 *
 *	Variable : int retorno : tipo entero , es el encargado de informar si salio todo ok
 *	Variable : int opcion : tipo entero , se encarga de tomar la opcion que quiera el usuario
 *	Variable : int banderaCostoHospedaje : tipo entero , es una bandera que nos avisa si entro o no en esa ocpion (NO entro : -1 | entro : 0)
 *	Variable : int banderaCostoComida : tipo entero , es una bandera que nos avisa si entro o no en esa ocpion (NO entro : -1 | entro : 0)
 *	Variable : int banderaCostoTransporte : tipo entero , es una bandera que nos avisa si entro o no en esa ocpion (NO entro : -1 | entro : 0)
 *	Variable : int banderaSalir : tipo entero , es una bandera que nos avisa si entro o no en esa ocpion (NO entro : -1 | entro : 0)
 *
 *Retono : retorna > 0 si salio bien , de lo contrario -1
 **/
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
					if(utn_pedirNumeroFlotante(costoHospedaje,"\nIngrese el costo del Hospedaje (entre 1 y 10000): ", "\nError", 10000, 1) == 0)
					{
						printf("\n--> Costo de Hospedaje OK <--\n");
						banderaCostoHospedaje = 0;
					}
					break;
				case 2:
					printf("\n*********Costo de comida*********\n");
					if(utn_pedirNumeroFlotante(costoComida, "\nIngrese el costo de la Comida (entre 1 y 10000): ", "\nError", 10000, 1) == 0)
					{
						printf("\n--> Costo de comida OK <--\n");
						banderaCostoComida = 0;
					}
					break;
				case 3:
					printf("\n*********Costo de transporte*********\n");
					if(utn_pedirNumeroFlotante(costoTransporte, "\nIngrese el costo del Transporte (entre 1 y 10000): ", "\nError", 10000, 1) == 0)
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
