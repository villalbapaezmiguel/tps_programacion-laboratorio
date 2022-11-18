/*
 * Informe.h
 *
 *  Created on: 29 oct. 2022
 *      Author: miguel
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "JugadorABM.h"
#include "ConfederacionABM.h"

void subMenu_informe(eJugador* listadoJugador , int largoJugador , eConfederacion* listadoConfederacion , int largoConfederacion);
void informar_jugador(eJugador* punteroArrayJugador , int largoJugador);
int informe_oredenarAlfabeticamenteNombreConfederacion(eJugador* listadoJugador , int largoJugador, eConfederacion* listadoConferacion , int largoConfederacion);
void informar_ordenarAlfabeticamente_confederacion (eConfederacion* listaConfederacion , int largoConfederacion);
#endif /* INFORMES_H_ */
