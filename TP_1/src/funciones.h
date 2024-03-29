/*
 * funciones.h
 *
 *  Created on: 25 sep. 2022
 *      Author: miguel
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define CONFEDERACION_AFC_ASIA 1//en Asia
#define CONFEDERACION_CAF_AFRICA 2//en Africa
#define CONFEDERACION_CONCACAF_ZONA_NORTE 3//en Zona del Norte
#define CONFEDERACION_CONMEBOL_SUDAMERICA 4//en Sudamerica
#define CONFEDERACION_UEFA_EUROPA 5//en Europa
#define CONFEDERACION_OFC_OCEANIA 6//en Oceania

int subMenu_cargarConfederacion (int* confederacion );
int	subMenu_costosDeMantenimiento (int* opcionCostos ,float* costoTransporte , float* costoHospedaje ,float* costoComida);
void menuPrincipal(void);
int subMenu_cargarPosicionDeJugador(int* contadorArqueros , int* contadorDefensores , int* contadorMediocampistas , int* contadorDelanteros  );
int subMenu_cargaJugadores(int* contadorArqueros , int* contadorDefensores , int* contadorMediocampistas , int* contadorDelanteros , int* confederacion);
float puntoA_calcularPromedioJugadorMercado (int* cantidadJugadoresIngresados ,int* contadorConfederaciones);
int puntoA_calcularPromedios(int* cantiadadJugadoresIngresados ,int* contador_AFC_ASIA , int* contador_CAF_AFRICA , int* contador_CONCACAF_ZONA_NORTE , int* contador_CONMEBOL_SUDAMERICA , int* contador_UEFA_EUROPA , int* contador_OFC_OCEANIA,
		float* promedio_AFC_ASIA , float* promedio_CAF_AFRICA , float* promedio_CONCACAF_ZONA_NORTE , float* promedio_CONMEBOL_SUDAMERICA , float* promedio_UEFA_EUROPA , float* promedio_OFC_OCEANIA);
int puntoB_calcularCostosMantenimientos(int* cantiadadJugadoresIngresados , float* costoTransporte , float* costoHospedaje , float* costoComida ,float* costoMantenimientoTotal );
void informar (float* promedio_AFC_ASIA , float* promedio_CAF_AFRICA , float* promedio_CONCACAF_ZONA_NORTE , float* promedio_CONMEBOL_SUDAMERICA , float* promedio_UEFA_EUROPA , float* promedio_OFC_OCEANIA ,
		float* costoMantenimientoTotal , int* auxAumento, int* banderaAumento , float* costoMantenimientoTotalConAumento);



#endif /* FUNCIONES_H_ */
