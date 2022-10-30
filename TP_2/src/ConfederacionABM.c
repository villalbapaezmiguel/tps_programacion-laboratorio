/*
 * ConfederacionABM.c
 *
 *  Created on: 29 oct. 2022
 *      Author: miguel
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "ConfederacionABM.h"


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
