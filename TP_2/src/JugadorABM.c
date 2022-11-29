/*
 * FuncionesABM.c
 *
 *  Created on: 13 oct. 2022
 *      Author: miguel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "JugadorABM.h"
#include "Informes.h"
#include "ConfederacionABM.h"
static int nuevoIdJugador(void);

/*int inicializar_jugador (eJugador* punteroArrayTransporte, int largoJugador )
 *Objetivo de la funcion :
 * inicializa todos los campos isEmtpy en Vacio
 *
 *ParaMetros :
 * Parametro : eJugador* punteroArrayJugador , tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largoJugador : tipo entero , es el largo del array de estrutura
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * int i ; tipo entero , es un contador que va a ir incrementando dentro del for
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
int inicializar_Jugador (eJugador* punteroArrayJugador, int largoJugador )
{
	int retorno = -1;
	int i ;

	if(punteroArrayJugador != NULL && largoJugador > 0 )
	{
		retorno = 0;
		for (i = 0; i < largoJugador; ++i) {
			(*(punteroArrayJugador+i)).isEmpty = VACIO;
		}
	}


	return retorno;
}


/*int buscarLugarLibre (eJUgador* punteroArray, int largo)
 *Objetivo de la funcion :
 * Busca la primera primera posicion libre que encuentra y la devuelve
 *
 *ParaMetros :
 * Parametro : eJugador* punteroArrayJugador, tipo puntero a un array de estructura , es el puntero a un array de estructura
 * Parametro : int largorJugador : tipo entero , es el largo del array de estrutura
 *
 *
 *Variables :
 *
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * int i ; tipo entero , es un contador que va a ir incrementando dentro del for
 *
 *Retono : int retorno , si salio todo bien retorna un entero >= 0 , de lo contrario -1
 **/
int buscarLugarLibre (eJugador* punteroArray, int largo)
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


/*int buscarPorId(eJugador* punteroArray , int largo , int idIngresado)
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
int buscarPorId(eJugador* pListaJugador , int largo , int idIngresado)
{
	int retorno  = -1;
	int i ;

	if(largo > 0 )
	{
		for (i = 0; i < largo; ++i) {

			if((*(pListaJugador+i)).isEmpty == OCUPADO)
			{
				if((*(pListaJugador+i)).id == idIngresado)
				{
					retorno = i;
					break;
				}
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
 *	Parametro : int* cantidadJugadores , tipo puntero a entero , el largo del array
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
eJugador altaJugador (eJugador* pListaJugador , int largo)
{
	eJugador auxJugador ;
	eConfederacion auxConfederacion;

	int respuestaNombre = -1;
	int respuestaNumeroCamiseta = -1;
	int respuestaSalario = -1;
	int respuestaAniosContrato = -1;
	int i;

	do {
		respuestaNombre = utn_pedirNombreConEspacio(auxJugador.nombre, LARGO_NOMBRE, "\nIngrese el nombre del Jugador : ", "\nError");
	} while (respuestaNombre == -1);

	subMenu_seleccionarPosicion(auxJugador.posicion);

	do {
		respuestaNumeroCamiseta =utn_pedirNumeroShort(&auxJugador.numeroCamiseta, "\nIngrese numero de camiseta (entre 1 y 127): ", "\nError", 127, 1);

	} while (respuestaNumeroCamiseta == -1);


	do {
		respuestaSalario = utn_pedirNumeroFlotante(&auxJugador.salario, "\nIngrese el salario del jugador (entre 100.0 y 100000.0): ", "\nError", 100000.0, 100.0);
	} while (respuestaSalario == -1);

	do {

		respuestaAniosContrato = utn_pedirNumeroShort(&auxJugador.aniosContrato, "\nIngrese años de contrato (entre 1 y 8 años): ", "\nError", 8, 1);

	} while (respuestaAniosContrato == -1);

	subMenu_Confederacion(&auxConfederacion.id);
	auxJugador.idConfederacion = auxConfederacion.id;//estructuras relacionadas
	auxJugador.id = nuevoIdJugador();
	auxJugador.isEmpty = OCUPADO;

	for (i = 0; i < largo; ++i) {

		if((*(pListaJugador+i)).isEmpty == OCUPADO)
		{
			if((*(pListaJugador+i)).id == auxJugador.id)
			{
				auxJugador.id = nuevoIdJugador();
			}
		}
	}




	printf("*********************************************************************************************************************\n");
	printf("Se cargo el Jugador :\n");
	printf("\nID : %d | NOMBRE : %s | POSICION : %s | N° CAMISETA : %d | ID CONFEDERACION : %d | SALARIO : %.2f | ANIOS CONTRATO : %d\n",
			auxJugador.id, auxJugador.nombre, auxJugador.posicion ,auxJugador.numeroCamiseta ,
			auxJugador.idConfederacion , auxJugador.salario, auxJugador.aniosContrato);
	printf("*********************************************************************************************************************\n");
	printf("\n++++++++++++++++++++++++++++++++++++++++");
	printf("\nJugador dato de ALTA de menera Exitosa !!!");
	printf("\n++++++++++++++++++++++++++++++++++++++++");
	return auxJugador ;
}



/*void subMenu_Confederacion(int* tipoConfederacion)
 *Objetivo de la funcion :
 * Es un subMenu para que el usuario pueda elegir un tipo de camion y el tipo de transporte se guarda en la variable idTransporte
 *
 *ParaMetros :
 * Parametro : int* tipoConfederacion , tipo puntero a entero , es el id de una estructura Confederacion
 *
 *Variables :
 *
 * int opcion : tipo entero , es una variable que me va a decir que opcion eligio
 * int banderaConfederacion : tipo entero , es una bandera para verificar si lo que devolvio la funcion esta bien
 *
 *Retono : void
 **/
void subMenu_Confederacion(int* tipoConfederacion)
{

	int banderaConfederacion = -1;
//	int bandaeraDos = -1;
	int opcion ;
		do {
			printf("\n1)CONMEBOL \n2)UEFA\n3)AFC\n4)CAF \n5)CONCACAF\n6)OFC\n7)Guardar y salir");
			if(banderaConfederacion == 0)
			{
				switch(*tipoConfederacion)
				{
				case 100:
					printf("\n**************************************");
					printf("\nEligio confederacion : CONMEBOL");
					printf("\n**************************************");
					break;
				case 101:
					printf("\n**************************************");
					printf("\nEligio confederacion : UEFA");
					printf("\n**************************************");
					break;
				case 102:
					printf("\n**************************************");
					printf("\nEligio confederacion : AFC");
					printf("\n**************************************");
					break;
				case 103:
					printf("\n**************************************");
					printf("\nEligio confederacion : CAF");
					printf("\n**************************************");
					break;
				case 104:
					printf("\n**************************************");
					printf("\nEligio confederacion : CONCACAF");
					printf("\n**************************************");
					break;
				case 105:
					printf("\n**************************************");
					printf("\nEligio confederacion : OFC");
					printf("\n**************************************");
					break;
				}

			}
			utn_pedirNumeroEntero(&opcion, "\nIngrese un opcion :", "\nError", 7, 1);

			switch(opcion)
			{
			case 1:
				*tipoConfederacion = CONFEDERACION_CONMEBOL;
				banderaConfederacion = 0;
				break;
			case 2:
				*tipoConfederacion = CONFEDERACION_UEFA;
				banderaConfederacion = 0;
				break;
			case 3:
				*tipoConfederacion = CONFEDERACION_AFC;
				banderaConfederacion = 0;
				break;
			case 4:
				*tipoConfederacion = CONFEDERACION_CAF;
				banderaConfederacion = 0;
				break;
			case 5:
				*tipoConfederacion = CONFEDERACION_CONCACAF;
				banderaConfederacion = 0;
				break;
			case 6:
				*tipoConfederacion = CONFEDERACION_OFC;
				banderaConfederacion = 0;
				break;
			case 7:
				if(banderaConfederacion == 0)
				{
					printf("tipo de confederacion Guardado\n");
				}else{
					opcion = 2;
					printf("\nERROR Tiene que elegir un tipo de confederacion");
				}
				break;
			default : printf("\nOpcion incorrecta ");
			}
		} while (opcion != 7 );

}


/*static int nuevoId()
 *int contador = es el contador y va agregando +1  cada vez que se lo llame
 *se encangar de generar un nuevo id*/
static int nuevoIdJugador(void)
{
	static int contador =0;

	return (contador++);
}


/*int baja_jugador(eJugador* punteroArrayJugador , int largoJugador)
 *Objetivo de la funcion :
 * da debaja a un jugador: pone su isEmpty en VACIO
 *
 *ParaMetros : void
 *  Parametro : eJugador* punteroArrayJugador , tipo puntero a un array de estructura , es el puntero a un array de estructura
 *  Parametro : int largoJugador : tipo entero , es el largo del array de estrutura
 *
 *Variables :
 *  int retorno : tipo entero , es el encargado de informar si salio todo ok
 *  int idBajaIngresado , tipo entero , va a tomar el id del jugador uqe quiere dar de baja
 *  int posicion , tipo entero , va a tomar el retrono  de la funcion buscarPorId , si sale != -1 es porque lo encontro
 *  int opcionBaja , tipo entero , toma la opcion que eligio el usuario (1-SI / 2-NO)
 *	int respuestaBaja = -1, tipo entero ,  es una bandera para verificar si lo que devolvio la funcion esta bien
 *	int sinJugador , tipo entero , es una bandera para verificar si lo que devolvio la funcion esta bien
 *	int i, tipo entero , es el contador que se incrementa en el for
 *
 *Retono :int retorno , si salio todo bien retorna un entero >= 0 , si no quiso dar de baja al jugador retorna 1 , de lo contrario -1
 **/
int baja_jugador(eJugador* punteroArrayJugador , int largoJugador)
{
	int retorno = -1;
	int idBajaIngresado;
	int posicion = -1;
	int opcionBaja ;
	int respuestaBaja = -1;
	int sinJugador = 0;
	int i;
	int respuesIdBaja = -1;

	if(punteroArrayJugador != NULL && largoJugador > 0)
	{
		for (i = 0; i < largoJugador; ++i) {

			if((*(punteroArrayJugador +i)).isEmpty == OCUPADO)
			{
				break;//encontro un jugador
			}else{
				sinJugador = 1;//no encontro ningun jugador
				printf("\nNo se puede hacer mas bajas , no hay jugadores !!");
				printf("\nPor favor ingrese jugadores !!!");
				break;
			}
		}

		if(sinJugador == 0)
		{
			informar_jugador(punteroArrayJugador, largoJugador);
			do {
				respuesIdBaja = utn_pedirNumeroEntero(&idBajaIngresado, "\nIngrese un ID para dar de baja :", "\nError", largoJugador, 0);
			} while (respuesIdBaja == -1);

			if(idBajaIngresado >= 0)
			{
				posicion = buscarPorId(punteroArrayJugador, largoJugador, idBajaIngresado);
				if(posicion != -1)
				{
					printf("\nID : %d | NOMBRE : %s | POSICION : %s | N° CAMISETA : %d | ID CONFEDERACION : %d | SALARIO : %.2f | ANIOS CONTRATO : %d",
					(*(punteroArrayJugador+posicion)).id, (*(punteroArrayJugador+posicion)).nombre, (*(punteroArrayJugador+posicion)).posicion ,(*(punteroArrayJugador+posicion)).numeroCamiseta,
					(*(punteroArrayJugador+posicion)).idConfederacion , (*(punteroArrayJugador+posicion)).salario, (*(punteroArrayJugador+posicion)).aniosContrato);

					do {
						respuestaBaja = utn_pedirNumeroEntero(&opcionBaja,"\nSegura/o  que quiere eliminar a este jugador (1-SI / 2-NO)??", "\nError", 2, 1);

					} while (respuestaBaja == -1);

					if(opcionBaja == 1 )
					{
						(*(punteroArrayJugador+posicion)).isEmpty = VACIO;
					}else if(opcionBaja == 2){
						retorno = 1;
					}
				}else{
					printf("\nERROR El id no fue encontrado...");
				}
			}else{
				printf("\nError no se encontro el ID : %d...", idBajaIngresado);
			}

		}

	}

	return retorno;
}


/*eJugador altaForzadaJugador(int id, char* nombre , char* posicion, short numeroCamiseta , short idConfederacion , float salario , short aniosContrato )
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
 * eJugador auxilia : tipo estructura , es una estructura auxiliar para poder almacenar los datos que nos pasan por parametros
 *
 *Retono : Retorna una estructura con datos que nos pasaron por parametros guardados en los campos de la estructura
 **/
eJugador altaForzadaJugador(int id, char* nombre , char* posicion, short numeroCamiseta , short idConfederacion , float salario , short aniosContrato )
{
	eJugador auxiliar ;

	auxiliar.id = id;
	strncpy(auxiliar.nombre, nombre, LARGO_NOMBRE);
	strncpy(auxiliar.posicion, posicion, LARGO_POSICION);
	auxiliar.numeroCamiseta = numeroCamiseta;
	auxiliar.idConfederacion = idConfederacion;
	auxiliar.salario = salario;
	auxiliar.aniosContrato = aniosContrato;
	auxiliar.isEmpty = OCUPADO;
	nuevoIdJugador();

	return auxiliar;
}


/*int modificacionJugador (eJugador* listaJugador, int largoJugador ,  int* idModificar )
 *Objetivo de la funcion :
 * hace modificaciones en los campos de la estructura del jugador
 *
 *ParaMetros : void
 *	Pametro :int* idModificar , tipo puntero a entero , es el id ingresedo por el usuario para modificar
 *  Parametro : eJugador* punteroArrayJugador , tipo puntero a un array de estructura , es el puntero a un array de estructura
 *  Parametro : int largoJugador : tipo entero , es el largo del array de estrutura
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * eConfederacion auxConfederacion : tipo estructura , es una estructura auxiliar para poder almacenar los datos
 *
 *Retono : int retorno , si salio todo bien retorna un entero >= 0 , de lo contrario -1
 **/
int modificacionJugador (eJugador* listaJugador, int largoJugador ,  int* posicionIdModificar )
{
	eConfederacion auxConfederacion;
	int retorno = -1;

	if(listaJugador != NULL && largoJugador > 0 && posicionIdModificar != NULL )
	{
		subMenu_modificacion(listaJugador, largoJugador, posicionIdModificar, &auxConfederacion.id);
		retorno = 0;
	}

	return retorno ;
}


/*void subMenu_modificacion (eJugador* listaJugador , int largo , int* idModificar , int* tipoConfederacion)
 *Objetivo de la funcion :
 * Es un subMenu para que el usuario pueda elegir los campos que quiera modificar
 *
 *ParaMetros :
 * Parametro : eJugador* listaJugador , tipo puntero a entero , es el id de una estructura Confederacion
 * Parametro : int largo  , tipo entero ,
 * Parametro : int* idModificar , tipo puntero a un entero , va a tener el valor de la direccion de memoria del a modificar
 * Parametro : int* tipoConfederacion , tipo puntero a un entero ,  va a tener el valor de la direccion de memoria del tipo de confederacion
 *
 *Variables :
 *
 * int opcion : tipo entero , es una variable que me va a decir que opcion eligio
 * int banderaConfederacion : tipo entero , es una bandera para verificar si lo que devolvio la funcion esta bien
 *
 *Retono : void
 **/
void subMenu_modificacion (eJugador* listaJugador , int largo , int* posicionIdModificar , int* tipoConfederacion )
{
	int opcion ;
	int respuestaNombre = -1;
	int respuestaNumeroCamiseta = -1;
	int respuestaSalario = -1;
	int respuestaAniosContrato = -1;

	if(listaJugador != NULL && largo > 0 )
	{

		printf("\nSeleccione el campo que desea modificar");
		do {
			printf("\n1)Nombre del jugador\n2)Posicion del jugador\n3)Numero de camiseta\n4)Salario del jugador\n5)Años de contrato\n6)Confederacion \n7)Guardar y Salir");
			utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion :", "\nError", 7, 1);
			switch(opcion)
			{
				case 1://nombre
					printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<_Nombre_>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
					do {
						respuestaNombre = utn_pedirNombreConEspacio((*(listaJugador+*posicionIdModificar)).nombre, LARGO_NOMBRE, "\nIngrese el Nuevo nombre del Jugador : ", "\nError");
					} while (respuestaNombre == -1);

					break;
				case 2://posicion del jugador
					printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<_Posicion del jugador_>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
					subMenu_seleccionarPosicion((*(listaJugador+*posicionIdModificar)).posicion);
					break;
				case 3://numero de camiseta
					printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<_Numero de camiseta_>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
					do {
						respuestaNumeroCamiseta =utn_pedirNumeroShort(&(*(listaJugador+*posicionIdModificar)).numeroCamiseta, "\nIngrese el Nuevo numero de camiseta (entre 1 y 127): ", "\nError", 127, 1);

					} while (respuestaNumeroCamiseta == -1);

					break;
				case 4://salario
					printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<_Salario_>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
					do {
						respuestaSalario = utn_pedirNumeroFlotante(&(*(listaJugador+*posicionIdModificar)).salario, "\nIngrese el Nuevo salario del jugador (entre 100.0 y 100000.0): ", "\nError", 100000.0, 100.0);
					} while (respuestaSalario == -1);

					break;
				case 5://años de contrato
					printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<_Años de contrato_>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
					do {
						respuestaAniosContrato = utn_pedirNumeroShort(&(*(listaJugador+*posicionIdModificar)).aniosContrato, "\nIngrese el Nuevo años de contrato (entre 1 y 8 años): ", "\nError", 8, 1);

					} while (respuestaAniosContrato == -1);

					break;
				case 6://confederacion
					printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<_Confederacion_>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
					subMenu_Confederacion(tipoConfederacion);
					(*(listaJugador+*posicionIdModificar)).idConfederacion = *tipoConfederacion;
					break;
				case 7://salir
					printf("\nSaliste del menu de Modificacion ");
					break;
			}
		} while (opcion != 7 );
//			(*(listaJugador+*posicionIdModificar)).id = *posicionIdModificar;
			(*(listaJugador+*posicionIdModificar)).isEmpty = OCUPADO;
	}
}

/*void subMenu_seleccionarPosicion(char* posicion )
 *Objetivo de la funcion :
 * Es un subMenu para que el usuario pueda elegir el campo de la posicion del jugador
 *
 *ParaMetros :
 * char* posicionr , tipo puntero a una cadena de caracteres
 *
 *Variables :
 *
 * int opcion : tipo entero , es una variable que me va a decir que opcion eligio
 * int banderaConfederacion : tipo entero , es una bandera para verificar si lo que devolvio la funcion esta bien
 *
 *Retono : void
 **/
void subMenu_seleccionarPosicion(char* posicion )
{
	int opcion ;
	int bandera = -1;
	int banderaDos = -1;
	if(posicion != NULL)
	{
		printf("\nTiene que eleigir si o si una posicion");
		do {
			printf("\n1)Arquero\n2)Defensor\n3)Mediocampista\n4)Delantero\n5)Guardar y Salir");
			if(banderaDos == 0)
			{
				printf("\n**************************************");
				printf("\nEligio la posicion : %s", posicion);
				printf("\n**************************************");
			}
			utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion : ", "\nError", 5, 1);
			switch(opcion)
			{
			case 1://arquero
				if(bandera == -1 || banderaDos == 0)
				{
					strncpy(posicion,"Arquero",LARGO_POSICION);
					bandera = 0;
					banderaDos = 0 ;
				}else{
					printf("\nTiene que eleigir si o si una posicion");
				}
				break;
			case 2://defensor
				if(bandera == -1 || banderaDos == 0)
				{
					strncpy(posicion,"Defensor",LARGO_POSICION);
					bandera = 0;
					banderaDos = 0;
				}else{
					printf("\nTiene que eleigir si o si una posicion");
				}
				break;
			case 3://mediocampista
				if(bandera == -1 || banderaDos == 0 )
				{
					strncpy(posicion,"Mediocampista",LARGO_POSICION);
					bandera = 0;
					banderaDos = 0;
				}else{
					printf("\nTiene que eleigir si o si una posicion");
				}
				break;
			case 4://delantero
				if(bandera == -1 || banderaDos == 0)
				{
					strncpy(posicion,"Delantero",LARGO_POSICION);
					bandera = 0;
					banderaDos = 0;
				}else{
					printf("\nTiene que eleigir si o si una posicion");
				}
				break;
			case 5://salir
				if(bandera == 0 || banderaDos == 0)
				{
					banderaDos = 0;
				}else{
					opcion = 2;
					printf("\nTiene que eleigir si o si una posicion");
				}
				break;
			default : printf("\nOpcion incorrecta ");
			}
		} while ( opcion != 5 );
	}
}






