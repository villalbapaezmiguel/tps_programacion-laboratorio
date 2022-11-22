/*
 * ConfederacionABM.h
 *
 *  Created on: 29 oct. 2022
 *      Author: miguel
 */

#ifndef CONFEDERACIONABM_H_
#define CONFEDERACIONABM_H_

#define CONFEDERACION_LEN 6
#define LARGO_REGION 50
#define NOMBRE_CONFEDERACION 50

typedef struct{

	int id;
	char nombre[NOMBRE_CONFEDERACION];
	char region[LARGO_REGION];
	int anioCreacion ;
	int isEmpty ; // lo agregue para poder hacer el Alta , Baja y Modificacion , porque sino no puedo hacer ningun alta , ya que necesito saber si esa estructra esta o no libre

}eConfederacion;

#include "JugadorABM.h"

eConfederacion altaForzadaConfederacion(int id, char* nombre , char* region, int aniosCreacion );
int confederacion_inicializar_ (eConfederacion* punteroArrayConfederacion, int largoConderacion );
int confederacion_buscarLugarLibre (eConfederacion* punteroArray, int largo);
int confederacion_buscarPorId(int* idJugadorConfederacion , eConfederacion* punteroArray , int largo , int* idEncontrado);
eConfederacion confederacion_alta (void);
int confederacion_Baja(eConfederacion* punteroArrayConfederacion , int largoConfederacion);
int confederacion_modificacion(eConfederacion* listaConfederacion, int largoConfederacion ,  int* idModificar );
void confederacion_subMenu_modificacion(eConfederacion* pListaConfederacion , int largo , int* idModificar , int* tipoConfederacion);
#endif /* CONFEDERACIONABM_H_ */
