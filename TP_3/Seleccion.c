#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"
#include "utn.h"
#include "Seleccion.h"
/** \brief asigna un lugar de la memoria dinamica para un elemento de tipo seleccion y deja todos sus campos inicializados
 *
 * \return Seleccion* retorna un puntero al lugar de la memoria asignado o devuelve NULL si no lo logro
 *
 */
Seleccion* selec_new()//funciona ok
{
	Seleccion* nuevaSeleccion = NULL;
	int auxId=0;//=0;
	char auxPais[30];
	char auxConfederacion[30];
	nuevaSeleccion = (Seleccion*)malloc(sizeof(Seleccion));
		if(nuevaSeleccion != NULL)
	{
			nuevaSeleccion->id = auxId;
			strcpy(nuevaSeleccion->pais,auxPais);
			strcpy(nuevaSeleccion->confederacion,auxConfederacion);
			selec_setConvocados(nuevaSeleccion,0);
	}
	return nuevaSeleccion;
}
/** \brief reserva espacio de memoria dinamica para un elemento de tipo sleccion cargando en todos sus campos los datos pasados como parametros en formato de cadena de caracteres
 *
 * \param idStr char*
 * \param paisStr char*
 * \param confederacionStr char*
 * \param convocadosStr char*
 * \param nacionalidad char*
 * \return Seleccion* retorna un puntero al lugar de la memoria asignado o devuelve NULL si no lo logro
 *
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)//funciona ok
{
	Seleccion* nuevaSeleccion = NULL;

	if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL)
	{
		nuevaSeleccion = selec_new();
		if(nuevaSeleccion != NULL)
		{
			nuevaSeleccion->id = atoi(idStr);
			strcpy(nuevaSeleccion->pais,paisStr);
			strcpy(nuevaSeleccion->confederacion,confederacionStr);
			selec_setConvocados(nuevaSeleccion,atoi(convocadosStr));
		}
	}
	return nuevaSeleccion;
}
/** \brief Libera el espacio en memoria apuntado por "this"
 *
 * \param Seleccion*this
 * \return in
 *
 */
void selec_delete(Seleccion* this)
{
	if(this != NULL)
		{
			free(this);
		}
}
/** \brief obtiene  idSeleccion
	 *\param this
	 * \param ,int* id
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int selec_getId(Seleccion* this,int* id)
{
	int retorno = -1;
	if(this != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene  pais
	 *\param this
	 *\param ,char* pais
	 *\return int 0 si pudo -1 si no pudo
	 *
 */
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = -1;
	if(this != NULL && pais != NULL)
	{
		strcpy(pais,this->pais);
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene  confederacion
	 *\param this
	 *\param ,char* confederacion
	 *\return int 0 si pudo -1 si no pudo
	 *
 */
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;
	if(this != NULL && confederacion != NULL)
	{
		strcpy(confederacion,this->confederacion);
		retorno = 0;
	}
	return retorno;
}
// SET Y GET DE CONVOCADOS
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;
	if(this != NULL )
	{
		this->convocados = convocados;
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene  convocados
	 *\param this
	 * \param ,int* convocados
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = -1;
	if(this != NULL)
	{
		*convocados = this->convocados;
		retorno = 0;
	}
	return retorno;
}
/** \brief encabezado de selecciones
 */
void encabezadoSelecciones()
{
	int anchoColumnaId = -10 ;
	int anchoColumnaPais = -20;
	int anchoColumnaConfederacion = -15 ;
	int anchoColumnaConvocado = -10 ;

	printf("<<<<<<<<<<<<<<<<<<<<LISTA DE CONVOCADOS>>>>>>>>>>>>>>>>>>>>");
	printf("\n**********+********************+***************+**********\n");
	printf("|%*s|%*s|%*s|%*s|\n",anchoColumnaId,"ID",anchoColumnaPais,"PAIS",anchoColumnaConfederacion, "CONFEDERACION",anchoColumnaConvocado,"CONVOCADOS");
	printf("\n**********+********************+***************+**********\n");

}
/** \brief imprime una seleccion
	 *\param this
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int selec_imprimirUnaSeleccion(Seleccion* this)
{
	int retorno = -1;
	int auxId;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;
	int anchoColumnaId = -10 ;
	int anchoColumnaPais = -20;
	int anchoColumnaConfederacion = -15 ;
	int anchoColumnaConvocado = -10 ;


	if(this != NULL )
	{
		selec_getId(this,&auxId);
		selec_getPais(this,auxPais);
		selec_getConfederacion(this,auxConfederacion);
		selec_getConvocados(this,&auxConvocados);

		printf("|%*d|%*s|%*s|%*d|\n",anchoColumnaId, auxId , anchoColumnaPais, auxPais , anchoColumnaConfederacion, auxConfederacion, anchoColumnaConvocado,auxConvocados);
		retorno = 0;
	}
	return retorno;
}
/** \brief ordena seleccion x confederacion
 *\param void* p1
 *\param void* p2
 * \return int
 *
*/
int selec_ordenarPorConfederacion(void* p1,void*p2)
{
	char confederacion1[30];
	char confederacion2[30];
	int retorno;
	Seleccion* seleccion1 = (Seleccion*)p1;
	Seleccion* seleccion2 = (Seleccion*)p2;
	if(seleccion1 != NULL && seleccion2 != NULL)
	{
       selec_getConfederacion(seleccion1, confederacion1);
       selec_getConfederacion(seleccion2, confederacion2);
       retorno =stricmp(confederacion1,confederacion2);
	}
	return retorno;
}


/// \fn int selec_AsignarDescripcionPais(LinkedList*, LinkedList*, int, char*)
/// \brief Al recibir el indice de un jugador, teniendo en cuenta el campo idSeleccion, busco pasar por referencia
/// el nombre de la seleccion a la que esta convocado.
///
/// \param pArrayListSeleccion
/// \param pArrayListJugador
/// \param indice
/// \param descripcionPais paso por referencia la descripcion del pais.
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_AsignarDescripcionPais(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, int indice, char *descripcionPais)
{
	int retorno=-1;
	Jugador* pJugador;
	int tam;
	Seleccion* pSeleccion;
	int selecId;
	char selecPais[30];
	int jugIdSeleccion;


	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		//printf("ENTRE AL IF en selec_AsignarDescripcionPais >0\n");
		//PUNTERO A LA ESTRUCTURA TENIENDO EL INDICE
		pJugador=ll_get(pArrayListJugador, indice);
		//BUSCO EL TAMANIO DE LA LISTA DE SELECCIONES
		tam=ll_len(pArrayListSeleccion);
		for(int i=0;i<tam;i++)
		{
			//printf("ENTRE AL FOR en selec_AsignarDescripcionPais >0\n");
			pSeleccion=ll_get(pArrayListSeleccion, i);
		//	printf("PASE EL ll_get\n");
			if(selec_getId(pSeleccion, &selecId)==0 && jug_getSIdSeleccion(pJugador, &jugIdSeleccion)==0)
			{
				//printf("OBTUVE LOS GETTERS\n");
				if(selecId==jugIdSeleccion)
				{
				//	printf("COINCIDENCIA ENTRE EL ID DE SELECCION DEL JUG Y EL DE LA SELEC \n");
					if(selec_getPais(pSeleccion, selecPais)==0)
					{
						retorno=0;
						//PASO EL NOMBRE DEL PAIS
						//printf("HAGO STRCPY selec_AsignarDescripcionPais >0\n");
						strcpy(descripcionPais, selecPais);
						break;
					}
				}
			}
		}
	}
	return retorno;
}


/// \fn int selec_Solicitar_Id(LinkedList*, int*)
/// \brief Ya listadas las selecciones, en esta funcion paso a solicitar el id de la seleccion (valido), verifico que aun
/// se mantenga por debajo de los 22 convocados y retorno segun ello.
///
/// \param pArrayListSeleccion
/// \param indice
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_Solicitar_Id(LinkedList* pArrayListSeleccion, int* indice)
{
	int retorno=-1;
	int idPais;
	Seleccion* pSeleccion;
	int selecConvocados;
	if(pArrayListSeleccion!=NULL)
	{
		//SOLICITO ID.
		utn_pedirNumeroEntero(&idPais, "\nIngrese un pais para convocar jugadores : ", "\nError", 32, 1);
//		ingresarIntConRango(&idPais, "Ingrese pais para el que desea convocar jugadores.\n", "ERROR, Ingerse ID valido,\n", 1, 32);
		//CON EL ID, PASO A BUSCAR EL INDICE.

		if(selec_buscarPorId(pArrayListSeleccion, idPais, &(*(indice)))==0)
		{
			// BUSCO EL PUNTERO AL ELEMENTO TENIENDO EN CUENTA EL INDICE.
			pSeleccion=ll_get(pArrayListSeleccion, *(indice));
			if(selec_getConvocados(pSeleccion, &selecConvocados)==0)
			{
				//if((*(pSeleccion)).convocados<22)
				if(selecConvocados<22)
				{
					retorno=0;
				}
				else
				{
					printf("ERROR, La seleccion llego a su maximo de 22 convocados.\n");
				}
			}

		}

	}
	return retorno;
}

/// \fn int selec_buscarPorId(LinkedList*, int, int*)
/// \brief Recibe un id de seleccion y pasa por referencia el indice en el que se encuentra el mismo.
///
/// \param pArrayListSeleccion
/// \param idBuscado
/// \param indice
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_buscarPorId(LinkedList* pArrayListSeleccion, int idBuscado, int *indice)
{
	int retorno=-1;
	int tam;
	Seleccion* pSeleccion=NULL;
	int selecId;
	tam=ll_len(pArrayListSeleccion);

	if(pArrayListSeleccion!=NULL)
	{
		//printf("ENTRO 0\n");
		for(int i=0;i<tam;i++)
		{
			//printf("ENTRO 1\n");
			pSeleccion=ll_get(pArrayListSeleccion, i);
			//printf("ENTRO 2\n");
			if(selec_getId(pSeleccion, &selecId)==0)
			{
				//printf("ENTRO 3\n");
				//if((*(pSeleccion)).id==idBuscado)
				if(selecId==idBuscado)
				{
					//printf("ENTRO 4\n");
					*indice=i;
					retorno=0;
					break;
				}
			}
			else
			{
				printf("ERROR al obtener el id de la seleccion.\n");
			}
		}
	}
	return retorno;
}


/** \brief ordena jugador por edad
 *\param void* p1
 *\param void* p2
 * \return int
 *
*/
//0 descendente 1 ascendente
int selec_ordenarPorId(void* p1,void*p2)//void puntero al elemento lo casteo
{
	int idUno=0;

	int idDos=0;

	int retorno;
	Seleccion* seleccion1 = (Seleccion*)p1;
	Seleccion* seleccion2 = (Seleccion*)p2;
	if(seleccion1 != NULL && seleccion2 != NULL)
	{
		selec_getId(seleccion1, &idUno);
		selec_getId(seleccion2, &idDos);
		if(idUno > idDos)
		{
			retorno = 1;
		}else if(idUno < idDos)
		{
			retorno = -1;
		}else{
			retorno = 0;
		}
	}
	return retorno;
}


