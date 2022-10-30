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

}eConfederacion;

#include "JugadorABM.h"

eConfederacion altaForzadaConfederacion(int id, char* nombre , char* region, int aniosCreacion );


#endif /* CONFEDERACIONABM_H_ */
