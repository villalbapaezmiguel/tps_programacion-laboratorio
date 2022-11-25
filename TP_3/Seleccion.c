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
	if(this != NULL && convocados > 0)
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
	printf("_________________________________________________________________\n");
	printf("                       LISTA DE SELECCIONES                       \n");
    printf("_________________________________________________________________\n");
	printf("ID          PAIS               CONFEDERACION       CONVOCADOS\n");
	printf("_________________________________________________________________\n");
}
/** \brief imprime una seleccion
	 *\param this
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int selec_imprimirUnaSeleccion(Seleccion* this)
{
	int retorno = -1;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;


	if(this != NULL )
	{
		selec_getId(this,&id);
		selec_getPais(this,pais);
		selec_getConfederacion(this,confederacion);
		selec_getConvocados(this,&convocados);

		printf("%3d      %15s %20s  %10d\n",
				id,pais,confederacion,convocados);
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
