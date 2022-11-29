/*
 * utn.c
 *
 *  Created on: 4 sep. 2022
 *      Author: miguel
 */
#include "utn.h"

/*int validarAfanumerico(char* pRespuesta , int largo)
 *Objetivo de la funcion :
 *  	verifica si la cadena ingresada es alfanumerica
 *
 *Parametros :
 *parametro : char* pRespuesta , Puntero al espacio de memoria donde se copiara la cadena obtenida
 *parametro : int largo , tipo entero :  Define el tamaño de cadena
 *
 *Variables :
 *varible : int retorno , tipo entero :  es el encargado de informar si salio todo ok
 *varible : int indice , tipo entero ; es el indice del bucle for
 *varible : int banderaChar , tipo entero : es una bandera que determina que lo que haya en char* pRespuesta contenga por lo menos un caracter ,en caso que sea V(bandera = 0) en caso contraio F(bandera = -1)
 *varible : int banderaInt , tipo entero : es una bandera que determina que lo que haya en char* pRespuesta contenga por lo menos un numero , en caso que sea V(bandera = 0) en caso contraio F(bandera = -1)
 *
 *Retorno :
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 * */
int validarAfanumerico(char* pRespuesta , int largo)
{
	int retorno = -1;
	int indice = 0;
	int banderaChar = -1;
	int banderaInt = -1;


	if(pRespuesta != NULL && largo > 0 )
	{
		for (indice = 0; pRespuesta[indice] != '\0' && indice <= largo; ++indice) {

			if(isalpha(pRespuesta[indice]) !=  0 )
			{
				banderaChar = 0;
			}else if(isdigit(pRespuesta[indice]) != 0)
			{
				banderaInt = 0;
			}
		}

		if(banderaChar == 0 && banderaInt == 0)
		{
			retorno = 0;
		}
	}


	return retorno;

}


/**int pedirDatos(char* datos, int largo)
 * Objetivo de la funcion :
 * 		Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en datos(char* datos)
 *
 *Parametros :
 *
 *parametro : char* pDatos , Puntero al espacio de memoria donde se copiara la cadena obtenida
 *parametro : int largo , tipo entero : Define el tamaño de cadena
 *
 *Varibles :
 *
 *	int retorno :tipo entero , es el encargado de informar si salio todo ok
 *	char bufferString: tipo char , se encarga de pedir el dato al usuario para luego pasarle al puntero pDatos que se encuentra como parametro (char* pDatos)
 *
 *Retorno :
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 */
int pedirDatos(char* pDatos, int largo)
{
	int retorno = -1;
	char bufferString [4020];

	if(fgets(bufferString , sizeof(bufferString), stdin) != NULL)
	{
		if(strcmp(bufferString, "\n")==0)
		{
			printf("\nError , ENTER No es un dato correcto...");
		}else{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) -1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) -1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= largo)
			{
				strncpy(pDatos,bufferString , largo);
				retorno = 0;
			}
		}
	}

	return retorno;
}

/*int utn_pedirAlfanumerico(char* pRespuesta, int largo , char* mensaje , char* mensajeError)
 *Objetivo de la funcion :
 * pide un alfanumerico al usuario , lo valida , comprueba y devuelve el resultado.
 *
 *ParaMetros :
 * Parametro : char* pRespuesta, : tipo puntero de cadena de caracteres , Puntero a una cadena de caracteres , alli se dejara el nombre ingresado
 * Parametro : int largo : tipo entero , es el largo de la cadena de caracteres
 * Parametro : char* mensaje : tipo char , es una cadena de caracteres que contendra un mensaje para pedir que ingrese una letra
 * Parametro : char* mensajeError : tipo char , es una cadena de caracteres que contendra un mensaje de ERROR para resaltar que algo salio mal al ingreso del caracter
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * char bufferString : tipo char , se encarga de pedir el nombre para luego pasarle al puntero pRespuetas que se encuentra como parametro (char* pRespuesta)
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
int utn_pedirAlfanumerico(char* pRespuesta, int largo , char* mensaje , char* mensajeError)
{
	int retorno = -1;
	char bufferString [largo];

	if(pRespuesta != NULL && largo > 0 && mensaje != NULL && mensajeError != NULL )
	{
		printf("\n%s",mensaje);//imprimimos el mensaje

		if(pedirDatos(bufferString, largo) == 0)//pedimos los datos (en formato string)
		{
			if(validarAfanumerico(bufferString, largo) == 0)//validamos que ese string sea de valor alfanumerico
			{
				strncpy(pRespuesta, bufferString , largo);
				retorno = 0;//todo salio ok

			}else{
				printf("\n%s", mensajeError);//mostramos un mensaje de error
			}
		}
	}

	return retorno;
}

/*int validarNumeroEntero(char* caracter )
 *Objetivo de la funcion :
 *		verifica si la cadena ingresada (char* pRespuesta) es numerica
 *
 *Parametros :
 *parametro : char* pRespuesta , Puntero al espacio de memoria donde se copiara la cadena obtenida
 *
 *Variables :
 *varible : int retorno , tipo entero :  es el encargado de informar si salio todo ok
 *varible : int i , tipo entero ; es el indice del bucle for
 *
 *Retorno :
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 * */
int validarNumeroEntero(char* pRespuesta )
{
	int retorno  = -1;
	int i = 0;

	if(pRespuesta != NULL)
	{
		retorno = 0;
		if(pRespuesta[0] == '-')
		{
			i = 1;
		}
		for (; pRespuesta[i] != '\0'; ++i) {

			if(pRespuesta[i] > '9' || pRespuesta[i] < '0')
			{
				retorno = -1;
				break;
			}
		}
	}


	return retorno;
}


/*int utn_pedirNumeroEntero(int* pRespuesta , char* mensaje  , char* mensajeError , int maximo , int minimo)
 *Objetivo de la funcion :
 * pide un numero Entero al usuario , lo valida , comprueba y devuelve el resultado.
 *
 *ParaMetros :
 * Parametro : int* pRespuesta  : tipo entero , Puntero a un entero , alli se dejara el numero ingresado como parametro
 * Parametro : char* mensaje : tipo char , es una cadena de caracteres que contendra un mensaje para pedir que ingrese una letra
 * Parametro : char* mensajeError : tipo char , es una cadena de caracteres que contendra un mensaje de ERROR para resaltar que algo salio mal al ingreso del caracter
 * Parametro : int maximo : int enetro , Valor maximo aceptado
 * Parametro : int minimo : int entero , Valor mimini aceptado
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * char bufferString : tipo char , se encarga de pedir el numero para luego pasarle al puntero pRespuetas que se encuentra como parametro (int* pRespuesta)
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
int utn_pedirNumeroEntero(int* pRespuesta , char* mensaje  , char* mensajeError , int maximo , int minimo)
{
	int retorno =-1 ;
	char bufferString [4000];

	if(pRespuesta != NULL && mensaje != NULL && mensajeError !=NULL && (maximo > minimo))//validamos los parametros
	{
		printf("\n%s", mensaje);//imprimimos el mensaje
		if(pedirDatos(bufferString, sizeof(bufferString)) == 0)//pedimos los datos (en formato string)
		{
			if(validarNumeroEntero(bufferString) == 0)//validamos que ese string sea un numero entero
			{
				*pRespuesta = atoi(bufferString);//lo pasamos a un numero enteto

				if(*pRespuesta <= maximo && *pRespuesta >= minimo)//varificamos si ese entero esta entre los parametros de maximo y minimo
				{
					retorno = 0;//todo salio ok

				}else{
					printf("\n%s",mensajeError);//imprimimos mensaje error
				}
			}else{
				printf("\n%s", mensajeError);//imprimimos mensaje error
			}
		}
	}

	return retorno;
}


/*int utn_pedirNumeroShort(short* pRespuesta , char* mensaje  , char* mensajeError , int maximo , int minimo)
 *Objetivo de la funcion :
 * pide un numero Entero al usuario , lo valida , comprueba y devuelve el resultado.
 * Su rango es de -128 hasta 127
 *
 *ParaMetros :
 * Parametro : int* pRespuesta  : tipo entero , Puntero a un entero , alli se dejara el numero ingresado como parametro
 * Parametro : char* mensaje : tipo char , es una cadena de caracteres que contendra un mensaje para pedir que ingrese una letra
 * Parametro : char* mensajeError : tipo char , es una cadena de caracteres que contendra un mensaje de ERROR para resaltar que algo salio mal al ingreso del caracter
 * Parametro : int maximo : int enetro , Valor maximo aceptado
 * Parametro : int minimo : int entero , Valor mimini aceptado
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * char bufferString : tipo char , se encarga de pedir el numero para luego pasarle al puntero pRespuetas que se encuentra como parametro (int* pRespuesta)
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
int utn_pedirNumeroShort(short* pRespuesta , char* mensaje  , char* mensajeError , int maximo , int minimo)
{
	int retorno =-1 ;
	char bufferString [4000];

	if(pRespuesta != NULL && mensaje != NULL && mensajeError !=NULL && (maximo > minimo))//validamos los parametros
	{
		printf("\n%s", mensaje);//imprimimos el mensaje
		if(pedirDatos(bufferString, sizeof(bufferString)) == 0)//pedimos los datos (en formato string)
		{
			if(validarNumeroEntero(bufferString) == 0)//validamos que ese string sea un numero entero
			{
				*pRespuesta = atoi(bufferString);//lo pasamos a un numero enteto

				if(*pRespuesta <= maximo && *pRespuesta >= minimo)//varificamos si ese entero esta entre los parametros de maximo y minimo
				{
					retorno = 0;//todo salio ok

				}else{
					retorno = -1;
					printf("\n%s",mensajeError);//imprimimos mensaje error
					printf("\nEl numero ingresado excede los limites del valor maximo o minimo ");
				}
			}else{
				printf("\n%s", mensajeError);//imprimimos mensaje error
			}
		}
	}

	return retorno;
}


/*int utn_pedirNombre(char* pRespuesta, int largo , char* mensaje , char* mensajeError)
 *Objetivo de la funcion :
 * pide un nombre al usuario , lo valida , comprueba y devuelve el resultado.
 *
 *ParaMetros :
 * Parametro : char* pRespuesta, : tipo puntero de cadena de caracteres , Puntero a una cadena de caracteres , alli se dejara el nombre ingresado
 * Parametro : int largo : tipo entero , es el largo de la cadena de caracteres
 * Parametro : char* mensaje : tipo char , es una cadena de caracteres que contendra un mensaje para pedir que ingrese una letra
 * Parametro : char* mensajeError : tipo char , es una cadena de caracteres que contendra un mensaje de ERROR para resaltar que algo salio mal al ingreso del caracter
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * char bufferString : tipo char , se encarga de pedir el nombre para luego pasarle al puntero pRespuetas que se encuentra como parametro (char* pRespuesta)
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
int utn_pedirNombre(char* pRespuesta, int largo , char* mensaje , char* mensajeError)
{
	int retorno = -1;
	char bufferString [largo];

	if(pRespuesta != NULL && largo > 0 && mensaje != NULL && mensajeError != NULL )//validamos los parametros
	{
		printf("\n%s",mensaje);//imprimimos mensaje

		if(pedirDatos(bufferString, largo) == 0)//pedimos los datos (en formato string)
		{
			if(validarNombre(bufferString, largo) == 0)//validamos que lo que nos haya devuelto sea un nombre
			{
				bufferString[0] = toupper(bufferString[0]);
				strncpy(pRespuesta, bufferString , largo);
				retorno = 0;//todo salio ok
			}else{
				printf("\n%s", mensajeError);//mensaje de error
			}
		}
	}

	return retorno;
}

/*int utn_pedirNombre(char* pRespuesta, int largo , char* mensaje , char* mensajeError)
 *Objetivo de la funcion :
 * pide un nombre al usuario , lo valida , comprueba y devuelve el resultado.
 *
 *ParaMetros :
 * Parametro : char* pRespuesta, : tipo puntero de cadena de caracteres , Puntero a una cadena de caracteres , alli se dejara el nombre ingresado
 * Parametro : int largo : tipo entero , es el largo de la cadena de caracteres
 * Parametro : char* mensaje : tipo char , es una cadena de caracteres que contendra un mensaje para pedir que ingrese una letra
 * Parametro : char* mensajeError : tipo char , es una cadena de caracteres que contendra un mensaje de ERROR para resaltar que algo salio mal al ingreso del caracter
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * char bufferString : tipo char , se encarga de pedir el nombre para luego pasarle al puntero pRespuetas que se encuentra como parametro (char* pRespuesta)
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
int utn_pedirNombreConEspacio(char* pRespuesta, int largo , char* mensaje , char* mensajeError)
{
	int retorno = -1;
	char bufferString [largo];

	if(pRespuesta != NULL && largo > 0 && mensaje != NULL && mensajeError != NULL )//validamos los parametros
	{
		printf("\n%s",mensaje);//imprimimos mensaje

		if(pedirDatos(bufferString, largo) == 0)//pedimos los datos (en formato string)
		{
			if(esNombre(bufferString, largo)== 1)//validamos que lo que nos haya devuelto sea un nombre
			{
				strncpy(pRespuesta, bufferString , largo);
				retorno = 0;//todo salio ok
			}else{
				printf("\n%s", mensajeError);//mensaje de error
			}
		}
	}

	return retorno;
}

/*int validarNombre(char* nombre , int largo)
 *Objetivo de la funcion :
 *		verifica si la cadena ingresada es un nombre (char* pRespuesta)
 *
 *Parametros :
 *parametro : char* pRespuesta , Puntero al espacio de memoria donde se copiara la cadena obtenida
 *Parametro : int largo : tipo entero , es el largo de la cadena de caracteres
 *
 *Variables :
 *varible : int retorno , tipo entero :  es el encargado de informar si salio todo ok
 *varible : int i , tipo entero ; es el indice del bucle for
 *
 *Retorno :
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 * */
int validarNombre(char* pCadena , int largo)
{
	int retorno = -1;
	int i;

	if(pCadena != NULL && largo > 0)
	{
		if(pCadena[0]  <= 'Z' && pCadena[0] >= 'A')
		{
			retorno = 0;
			for (i = 1; pCadena[i] != '\0' ; ++i) {

				if(pCadena[i] < 'a' || pCadena[i] > 'z' )
				{
					retorno = -1;
					break;
				}
			}
		}else{
			printf("La primera letra de un nombre tiene que ir con MAYUSCULAS");
		}
	}
	return retorno;
}


/*int validarNombre(char* nombre , int largo)
 *Objetivo de la funcion :
 *		verifica si la cadena ingresada es un nombre (char* pRespuesta)
 *
 *Parametros :
 *parametro : char* pRespuesta , Puntero al espacio de memoria donde se copiara la cadena obtenida
 *Parametro : int largo : tipo entero , es el largo de la cadena de caracteres
 *
 *Variables :
 *varible : int retorno , tipo entero :  es el encargado de informar si salio todo ok
 *varible : int i , tipo entero ; es el indice del bucle for
 *
 *Retorno :
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 * */
int esNombre(char* cadena,int longitud)//agregar q acepte parentesis
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{

		cadena[0] = toupper(cadena[0]);
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] == ' ' || cadena[i] == '(' || cadena[i] == ')')
			{
				cadena[i+1] = toupper(cadena[i+1]);
			}
			if(cadena[i] == '(' && cadena[i] == ')' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
	//cadena[i] == '(' && cadena[i] == ')' && ///28/10
//&& cadena[i] != ' '
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*int validarNumeroFlotante(char* caracter
 *Objetivo de la funcion :
 *		verifica si la cadena ingresada es flotante
 *
 *Parametros :
 *parametro : char* pRespuesta , Puntero al espacio de memoria donde se copiara la cadena obtenida
 *
 *Variables :
 *varible : int retorno , tipo entero :  es el encargado de informar si salio todo ok
 *varible : int i , tipo entero ; es el indice del bucle for
 *varible : banderaFloatnte : tipo entero : es una bandera que determina que lo que haya en char* pRespuesta sea un entero con decimales , en caso que sea V(bandera = 0) en caso contraio F(bandera = -1)
 *
 *Retorno :
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 * */
int validarNumeroFlotante(char* pRespuesta )
{
	int retorno  = -1;
	int i = 0;
//	int banderaFlotante = -1;

	if(pRespuesta != NULL)
	{
		retorno = 0;
		if(pRespuesta[0] == '-')
		{
			i = 1;
		}
		for (; pRespuesta[i] != '\0'; ++i) {

//			if(pRespuesta[i] == '.')
//			{
//				banderaFlotante = 0;
//				continue;
//			}
			if(pRespuesta[i] > '9' || pRespuesta[i] < '0')
			{
				retorno = -1;
				break;
			}
		}
//		if(banderaFlotante != 0)
//		{
//			retorno = -1;
//		}
	}


	return retorno;
}


/*int utn_pedirNumeroFlotante(float* pRespuesta , char* mensaje  , char* mensajeError , float maximo , float minimo)
 *Objetivo de la funcion :
 * pide un numero Flotante al usuario , lo valida , comprueba y devuelve el resultado.
 *
 *ParaMetros :
 * Parametro : Flolat* numero : tipo flotante , Puntero a un flotante , alli se dejara el numero ingresado como parametro
 * Parametro : char* mensaje : tipo char , es una cadena de caracteres que contendra un mensaje para pedir que ingrese una letra
 * Parametro : char* mensajeError : tipo char , es una cadena de caracteres que contendra un mensaje de ERROR para resaltar que algo salio mal al ingreso del caracter
 * Parametro : float maximo : float flotante , Valor maximo aceptado
 * Parametro : float minimo : float flotante , Valor mimini aceptado
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * char bufferString : tipo char , se encarga de pedir el numero para luego pasarle al puntero pRespuetas que se encuentra como parametro (float* pRespuesta)
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
int utn_pedirNumeroFlotante(float* pRespuesta , char* mensaje  , char* mensajeError , float maximo , float minimo)
{
	int retorno =-1 ;
	char bufferString [4000];

	if(pRespuesta != NULL && mensaje != NULL && mensajeError !=NULL && (maximo > minimo))
	{
		printf("\n%s", mensaje);//imprimimos mensaje
		if(pedirDatos(bufferString, sizeof(bufferString)) == 0)//pedimos los datos (en formato string)
		{
			if(validarNumeroFlotante(bufferString) == 0)//validamos que ese string sea un numero flotante
			{
				*pRespuesta = atof(bufferString);//lo convertimos a un floante

				if(*pRespuesta <= maximo && *pRespuesta >= minimo)//varificamos si ese flotante esta entre los parametros de maximo y minimo
				{
					retorno = 0;//salio todo ok

				}else{
					printf("\n%s",mensajeError);//imprimimos mensaje de error
					printf("\nEl numero ingresado excede los limites del valor maximo o minimo ");
				}
			}else{
				printf("\n%s", mensajeError);//imprimimos mensaje de error
			}
		}
	}

	return retorno;
}

/*int pedirLetra(char* letra , char* mensaje , char* mensajeError)
 *Objetivo de la funcion :
 * pide una letra al usuario , lo valida , comprueba y devuelve el resultado.
 *
 *ParaMetros :
 * Parametro : char* pLetra, : tipo puntero a un caracter , Puntero a un caracter , alli se dejara el caracter ingresado
 * Parametro : char* mensaje : tipo char , es una cadena de caracteres que contendra un mensaje para pedir que ingrese una letra
 * Parametro : char* mensajeError : tipo char , es una cadena de caracteres que contendra un mensaje de ERROR para resaltar que algo salio mal al ingreso del caracter
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * char bufferString : tipo char , se encarga de pedir el nombre para luego pasarle al puntero pRespuetas que se encuentra como parametro (char* pRespuesta)
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
int utn_pedirLetra(char* pLetra , char* mensaje , char* mensajeError)
{
	int retorno = -1;
	char bufferCaracter [5];

	if(mensaje != NULL && mensajeError != NULL)
	{
		printf("\nsolo se va tomar como letra el primer caracter (ejemp : si ingreso ->Hola , va a tomar la -> H)");
		printf("%s",mensaje);
		fflush(stdin);

		if(fgets(bufferCaracter, sizeof(bufferCaracter), stdin) != NULL)
		{
			if(validarLetra(bufferCaracter) == 0)
			{
				*pLetra = bufferCaracter[0];
				retorno = 0;
			}else{
				printf("\n%s", mensajeError);
			}
		}
	}
	return retorno ;
}

/*int validarLetra(char* pLetra)
 *Objetivo de la funcion :
 *		verifica si la cadena ingresada sea una letra , en caso que sea una cadena de caracteres , solo se va a tomar la primera letra y se pondra un \0 en la segunda posicion de la cadena
 *
 *Parametros :
 *parametro : char* pLetra , Puntero al espacio de memoria donde se copiara la cadena obtenida
 *
 *Variables :
 *varible : int retorno , tipo entero :  es el encargado de informar si salio todo ok
 *
 *Retorno :
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 * */
int validarLetra(char* pLetra)
{
	int retorno =-1;

	if(pLetra != NULL)
	{

		if((pLetra[0] <= 'Z' && pLetra[0] >= 'A') || (pLetra[0] <= 'z' && pLetra[0] >= 'a'))
		{
			pLetra[1] = '\0';
			retorno = 0;
		}
	}
	return retorno;
}


/*int utn_pedirNombre(char* pRespuesta, int largo , char* mensaje , char* mensajeError)
 *Objetivo de la funcion :
 * pide un nombre al usuario , lo valida , comprueba y devuelve el resultado.
 *
 *ParaMetros :
 * Parametro : char* pRespuesta, : tipo puntero de cadena de caracteres , Puntero a una cadena de caracteres , alli se dejara el nombre ingresado
 * Parametro : int largo : tipo entero , es el largo de la cadena de caracteres
 * Parametro : char* mensaje : tipo char , es una cadena de caracteres que contendra un mensaje para pedir que ingrese una letra
 * Parametro : char* mensajeError : tipo char , es una cadena de caracteres que contendra un mensaje de ERROR para resaltar que algo salio mal al ingreso del caracter
 *
 *Variables :
 * int retorno : tipo entero , es el encargado de informar si salio todo ok
 * char bufferString : tipo char , se encarga de pedir el nombre para luego pasarle al puntero pRespuetas que se encuentra como parametro (char* pRespuesta)
 *
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 **/
int utn_pedirPalabra(char* pRespuesta, int largo , char* mensaje , char* mensajeError)
{
	int retorno = -1;
	char bufferString [largo];

	if(pRespuesta != NULL && largo > 0 && mensaje != NULL && mensajeError != NULL )//validamos los parametros
	{
		printf("\n%s",mensaje);//imprimimos mensaje

		if(pedirDatos(bufferString, largo) == 0)//pedimos los datos (en formato string)
		{
			if(validarPalabra(bufferString, largo) == 0)//validamos que lo que nos haya devuelto sea un nombre
			{
				strncpy(pRespuesta, bufferString , largo);
				retorno = 0;//todo salio ok
			}else{
				printf("\n%s", mensajeError);//mensaje de error
			}
		}
	}

	return retorno;
}


/*int validarPalabra(char* pRespuesta , int largo)
 *Objetivo de la funcion :
 *		verifica si la cadena ingresada sea una palabra (char* pRespuesta)
 *
 *Parametros :
 *parametro : char* pRespuesta , Puntero al espacio de memoria donde se copiara la cadena obtenida
 *Parametro : int largo : tipo entero , es el largo de la cadena de caracteres
 *
 *Variables :
 *varible : int retorno , tipo entero :  es el encargado de informar si salio todo ok
 *varible : int i , tipo entero ; es el indice del bucle for
 *
 *Retorno :
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 * */
int validarPalabra(char* pRespuesta , int largo)
{
	int retorno = -1;
	int i;

	if(pRespuesta != NULL && largo > 0)
	{
			for (i = 1; *(pRespuesta+i) != '\0' ; ++i) {

				if((*(pRespuesta+i) < 'A' || *(pRespuesta+i) > 'Z') || (*(pRespuesta+i)  < 'a' || *(pRespuesta+i) > 'Z' ))
				{
					retorno = 0;
					break;
				}
			}
	}
	return retorno;
}


/*int convertidor_minusculas(char* pRespuesta , int largo)
 *Objetivo de la funcion :
 *		convierte una cadena de caracteres a minusculas
 *
 *Parametros :
 *parametro : char* pRespuesta , Puntero al espacio de memoria donde se copiara la cadena obtenida
 *Parametro : int largo : tipo entero , es el largo de la cadena de caracteres
 *
 *Variables :
 *variable : int retorno , tipo entero :  es el encargado de informar si salio todo ok
 *variable : int i , tipo entero ; es el indice del bucle for
 *variable : char aux , tipo cadena de caracter , es una cadena auxiliar
 *variable : int bandera , tipo entero , es una bandera vara verificar que haya salio todo ok
 *
 *Retorno :
 *Retono : retorna 0 si salio todo bien , caso contrario -1
 * */
int convertidor_minusculas(char* pRespuesta , int largo)
{
	int retorno = -1;
	int i;
	char aux[largo];
	int bandera = 0;

	if(pRespuesta != NULL && largo > 0)
	{
		strncpy(aux , pRespuesta , largo);

		for (i = 0; i < largo; ++i) {

			if(isupper(aux[i]) != 0)
			{
				aux[i] = tolower(aux[i]);

			}
			if(isupper(aux[i]) == 0)
			{
				bandera = -1;
			}
		}
		if(bandera == 0)
		{
			strncpy(pRespuesta , aux , largo);
			retorno = 0;
		}
	}
	return retorno;
}



