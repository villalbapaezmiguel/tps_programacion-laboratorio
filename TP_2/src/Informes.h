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
void informar_listadoConfederacionConSusJugadores(eJugador* pListadoJugador, int largoJugador,eConfederacion* pListadoConfederacion, int largoConfederacion );
float calcular_PromedioJugador (int* cantidadJugadoresIngresados ,int* contadorConfederaciones);
void informar_totalPromedioSalarios(eJugador* pListadoJugador, int largoJugador);
void informar_confederacionMayorCantidadContratoTotal(eJugador* pListaJugador, int largoJugador);
void informar_porcentajeJugadoresPorCadaConfederacion(eJugador* pListaJugador , int largoJugador);
void informar_regionConMasJugadores(eJugador* pListaJugador , int largoJugador , eConfederacion* pListaConfederacion , int largoConfederacion);
int calcular_mayorCantidadJugadoresRegion(eJugador* pListaJugador, int largoJugador , eConfederacion* pListaConfederacion , int largoConfederacion );
void subMenu_informar_regionConMasJugadores(eJugador* pListadoJugador , int largoJugador);
int listado_jugadoresPorConfederacion(eJugador* pListadoJugador , int largoJugador , int* idConfederacion );
#endif /* INFORMES_H_ */
