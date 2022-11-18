/*
 * ConfederacionABM.c
 *
 *  Created on: 29 oct. 2022
 *      Author: miguel
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "ConfederacionABM.h"
static int nuevoIdConfederacion(void);

/*eJugador altaForzadaConfederacion(int id, char* nombre , char* region, int aniosCreacion )
 *Objetivo de la funcion :
 * hace un harcodeo en una estructura auxiliar y luego la retorna
 *
 *ParaMetros : void
 *	Pametro :int* idModificar , tipo puntero a entero , es el id ingresedo por el usuario para modificar
 *  Pametro :char* descripcion , tipo puntero a char , es una descripcion ingresada como parametro
 *  Pametro :float pesoCarga , tipo  flotante , es el peso de carga
 *  Pametro :int cantidadBultos , tipo entero , es la cantidad de bultos
 *  Pametro :int id  , tioo entero , es el id que va a tener el auxliar de estructura
 *  Pametro :int idTipo , tipo entero, es el id que va a tener el auxliar de estructura
 *
 *Variables :
 *
 * Transporte auxTransporte : tipo estructura , es una estructura auxiliar para poder almacenar los datos que le vamos a pedir al usuario
 *
 *Retono : Retorna una estructura con datos del usuario guardados en sus campos
 **/
eConfederacion altaForzadaConfederacion(int id, char* nombre , char* region, int aniosCreacion )
{
	eConfederacion auxiliar ;
////hacer bien la documentacion

	if(id >= 0 && nombre != NULL && region != NULL && aniosCreacion > 100)
	{
		auxiliar.id = id;
		strncpy(auxiliar.nombre, nombre, LARGO_NOMBRE);
		strncpy(auxiliar.region, region, LARGO_REGION);
		auxiliar.anioCreacion = aniosCreacion;

	}

	return auxiliar;
}


/*int inicializar_Confederacion (eConfederacion* punteroArrayConfederacion, int largoConderacion )
 *Objetivo de la funcion :
 * inicializa todos los campos isEmtpy en Vacio
 *
 *ParaMetros :
 * Parametro : eConfederacion* punteroArrayConfederacion , tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largoConderacion : tipo entero , es el largo del array de estrutura
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * int i ; tipo entero , es un contador que va a ir incrementando dentro del for
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
int confederacion_inicializar_ (eConfederacion* punteroArrayConfederacion, int largoConderacion )
{
	int retorno = -1;
	int i ;

	if(punteroArrayConfederacion != NULL && largoConderacion > 0 )
	{
		retorno = 0;
		for (i = 0; i < largoConderacion; ++i) {
			(*(punteroArrayConfederacion+i)).isEmpty = VACIO;
		}
	}


	return retorno;
}

/*int buscarLugarLibre (eConfederacion* punteroArray, int largo)
 *Objetivo de la funcion :
 * Busca la primera primera posicion libre que encuentra y la devuelve
 *
 *ParaMetros :
 * Parametro : eConfederacion* punteroArray, tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largor : tipo entero , es el largo del array de estrutura
 *
 *
 *Variables :
 *
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * int i ; tipo entero , es un contador que va a ir incrementando dentro del for
 *
 *Retono : int retorno , si salio todo bien retorna un entero >= 0 , de lo contrario -1
 **/
int confederacion_buscarLugarLibre (eConfederacion* punteroArray, int largo)
{
	int retorno = -1;
	int i ;

	if(punteroArray != NULL && largo > 0 )
	{
		for (i = 0; i < largo; ++i) {

			if((*(punteroArray + i)).isEmpty == VACIO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


/*int confederacion_buscarPorId(eConfederacion* punteroArray , int largo , int idIngresado)
 *Objetivo de la funcion :
 * buscar el id pasado por el parametro y retorna una posicion > 0 si salio todo ok
 *
 *ParaMetros :
 * Parametro : eJugador* punteroArray , tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largo : tipo entero , es el largo del array de estrutura
 * Parametro : int idIngresado : tipo entero , es el idingresado para buscar
 *
 *Variables :
 *
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * int i ; tipo entero , es un contador que va a ir incrementando dentro del for
 *
 *Retono : int retorno , si salio todo bien retorna un entero >= 0 , de lo contrario -1
 **/
int confederacion_buscarPorId(eConfederacion* punteroArray , int largo , int idIngresado)
{
	int retorno  = -1;
	int i ;

	if(largo > 0 )
	{
		for (i = 0; i < largo; ++i) {

			if((punteroArray+i)->id == idIngresado)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


/*Transporte altaTransporte (void)
 *Objetivo de la funcion :
 * pide los campos al usuario(descripcion , pesoCarga , cantidadBultos) y lo guarda en una estructura auxliar ,
 * pone el isEmtpy en OCUPADO ,luego retorna esa misma estructra
 *
 *ParaMetros : void
 *
 *
 *Variables :
 *
 * Transporte auxTransporte : tipo estructura , es una estructura auxiliar para poder almacenar los datos que le vamos a pedir al usuario
 * Tipo auxTipo : tipo estructura , es una estructura auxiliar para poder almacenar los datos que le vamos a pedir al usuario
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * int respuestaDescripcion : tipo entero , es una bandera para verificar si lo que devolvio la funcion esta bien
 * int respuestaPesoCarga : tipo entero , es una bandera para verificar si lo que devolvio la funcion esta bien
 * int respuestaCantidadBulto : tipo entero , es una bandera para verificar si lo que devolvio la funcion esta bien
 *
 *Retono : Retorna una estructura con datos del usuario guardados en sus campos
 **/
eConfederacion confederacion_alta (void)
{
	eConfederacion auxConfederacion;
//	eJugador auxJugador ;

	int respuestaNombre = -1;
	int respuestaRegion = -1;
	int respuestaAnioCreacion = -1;

	do {

		respuestaNombre = utn_pedirNombre(auxConfederacion.nombre, sizeof(auxConfederacion.nombre), "\nIngrese el nombre de la Confederacion (EN MAYUSCULAS): ", "\nError");
	} while (respuestaNombre == -1);

	do {

		respuestaRegion = utn_pedirPalabra(auxConfederacion.region, sizeof(auxConfederacion.region), "\nIngrese el nombre de la Region : ", "\nError");
	} while (respuestaRegion == -1);

	do {
		respuestaAnioCreacion = utn_pedirNumeroEntero(&auxConfederacion.anioCreacion, "\nIngrese el año de creacion (entre 1900 y 2022): ", "\nError", 2022, 1900);
	} while (respuestaAnioCreacion == -1);

//	subMenu_Confederacion(&auxConfederacion.id);
//	auxJugador.idConfederacion = auxConfederacion.id;//estructuras relacionadas
	auxConfederacion.id = nuevoIdConfederacion();
	auxConfederacion.isEmpty = OCUPADO;

	return auxConfederacion ;
}

/*static int nuevoId()
 *int contador = es el contador y va agregando +1  cada vez que se lo llame
 *se encangar de generar un nuevo id*/
static int nuevoIdConfederacion(void)
{
	static int contador =105;

	return (contador++);
}


/**/
int confederacion_Baja(eConfederacion* punteroArrayConfederacion , int largoConfederacion)
{
	int retorno = -1;
	int idBajaIngresado;
	int posicion = -1;

	if(punteroArrayConfederacion != NULL && largoConfederacion > 0)
	{

		if(utn_pedirNumeroEntero(&idBajaIngresado, "\nIngrese un ID de la Confederacion para dar de baja :", "\nError", largoConfederacion, 0) == 0)
		{
			posicion = confederacion_buscarPorId(punteroArrayConfederacion, largoConfederacion, idBajaIngresado);
			if(posicion != -1)
			{
				(*(punteroArrayConfederacion+idBajaIngresado)).isEmpty = VACIO;
			}
		}
	}

	return retorno;
}



/**/
int confederacion_modificacion(eConfederacion* listaConfederacion, int largoConfederacion ,  int* idModificar )
{
	eConfederacion auxConfederacion;
	int retorno = -1;

	if(listaConfederacion != NULL && largoConfederacion > 0 && idModificar != NULL )
	{
		confederacion_subMenu_modificacion(listaConfederacion, largoConfederacion, idModificar, &auxConfederacion.id);
		retorno = 0;
	}


	return retorno ;
}


void confederacion_subMenu_modificacion(eConfederacion* pListaConfederacion , int largo , int* idModificar , int* tipoConfederacion)
{
	int opcion ;

	int respuestaNombreConfederacion = -1;
	int respuestaRegionConfederacion = -1;
	int respuestaAniosConfederacion = -1;
	if(pListaConfederacion != NULL && largo > 0 )
	{

		printf("\nSeleccione el campo que desea modificar");

		do {
			printf("\n1)Nombre de la Confederacion\n2)Nombre de la Region\n3)Año de creacion\n4)Salir");
			utn_pedirNumeroEntero(&opcion, "\nIngrese Opcion :", "\nerror", 3, 1);

			switch(opcion)
			{
			case 1:
				printf("\n<<<<<Nombre de la Confederacion>>>>>");
				do {

					respuestaNombreConfederacion = utn_pedirPalabra((*(pListaConfederacion+*idModificar)).nombre, sizeof(pListaConfederacion->nombre),"\nIngrese el Nuevo nomnbre de la Confederacion", "\nError");
				} while (respuestaNombreConfederacion == -1);
				break;
			case 2:
				printf("\n<<<<<Nombre de la Region>>>>>");
				do {

					respuestaRegionConfederacion = utn_pedirPalabra((*(pListaConfederacion+*idModificar)).region, sizeof((*pListaConfederacion).region),"\nIngrese la Nueva Region de la Confederacion", "\nError");
				} while (respuestaRegionConfederacion == -1);
				break;
			case 3:
				printf("\n<<<<<Año de creacion>>>>>");
				do {
					respuestaAniosConfederacion = utn_pedirNumeroEntero(&(*(pListaConfederacion+*idModificar)).anioCreacion, "\nIngrese el Nuevo año de creacion (entre 1900 y 2022) :", "\nError", 2022, 1900);
				} while (respuestaAniosConfederacion == -1);
				break;
			case 4:
				printf("\nSalion de la modificacion de Confederacion");
				break;
			}

		} while (opcion != 4);

			(*(pListaConfederacion+*idModificar)).id = *idModificar;
			(*(pListaConfederacion+*idModificar)).isEmpty = OCUPADO;
	}

}
