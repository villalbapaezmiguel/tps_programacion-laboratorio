/*
 * FuncionesABM.h
 *
 *  Created on: 13 oct. 2022
 *      Author: miguel
 */

#ifndef JUGADORABM_H_
#define JUGADORABM_H_

#define VACIO 0
#define OCUPADO 1
#define	CONFEDERACION_CONMEBOL 100
#define CONFEDERACION_UEFA 101
#define CONFEDERACION_AFC 102
#define CONFEDERACION_CAF 103
#define CONFEDERACION_CONCACAF 104
#define CONFEDERACION_OFC 105
#define LARGO_NOMBRE 50
#define LARGO_POSICION 50
#define JUGADOORES_LEN 3000

#include "JugadorABM.h"
#include "ConfederacionABM.h"

typedef struct{

	int id;
	char nombre[LARGO_NOMBRE];
	char posicion [LARGO_POSICION];
	short numeroCamiseta;
	short idConfederacion ;
	float salario;
	short aniosContrato ;
	short isEmpty;

}eJugador;

int inicializar_Jugador (eJugador* punteroArrayJugador, int largoJugador );
int buscarLugarLibre (eJugador* punteroArray, int largo);
int buscarPorId(eJugador* punteroArray , int largo , int idIngresado);
void subMenu_Confederacion(int* tipoConfederacion);
eJugador altaJugador (eJugador* pListaJugador , int largo);
int baja_jugador(eJugador* punteroArrayJugador , int largoJugador);
eJugador altaForzadaJugador(int id, char* nombre , char* posicion, short numeroCamiseta , short idConfederacion , float salario , short aniosContrato );
int modificacionJugador (eJugador* listaJugador, int largoJugador ,  int* idModificar );
void subMenu_modificacion (eJugador* listaJugador , int largo , int* posicionIdModificar , int* tipoConfederacion );
void subMenu_seleccionarPosicion(char* posicion );
#endif /* JUGADORABM_H_ */
