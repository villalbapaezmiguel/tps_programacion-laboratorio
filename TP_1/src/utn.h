/*
 * utn.h
 *
 *  Created on: 4 sep. 2022
 *      Author: miguel
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//pedir datos:
int pedirDatos(char* datos, int largo);
int utn_pedirAlfanumerico(char* pRespuesta, int largo , char* mensaje , char* mensajeError);
int utn_pedirNombre(char* pRespuesta, int largo , char* mensaje , char* mensajeError);
int utn_pedirNumeroEntero(int* pRespuesta , char* mensaje  , char* mensajeError , int maximo , int minimo);
int utn_pedirNumeroFlotante(float* pRespuesta , char* mensaje  , char* mensajeError , float maximo , float minimo);
int utn_pedirLetra(char* letra , char* mensaje , char* mensajeError);

//valiaciones:
int validarAfanumerico(char* pRespuesta , int largo);
int validarNombre(char* nombre , int largo);
int validarNumeroEntero(char* caracter );
int validarNumeroFlotante(char* caracter );
int validarLetra(char* pLetra);

#endif /* UTN_H_ */
