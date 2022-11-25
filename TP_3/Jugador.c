#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"
#include "utn.h"
//this es la lista,
/** \brief asigna un lugar de la memoria dinamica para un elemento de tipo jugador y deja todos sus campos inicializados
 *
 * \return Jugador* retorna un puntero al lugar de la memoria asignado o devuelve NULL si no lo logro
 *
 */
Jugador* jug_new()
{
	Jugador* nuevoJugador = NULL;

	nuevoJugador = (Jugador*)malloc(sizeof(Jugador));

	if(nuevoJugador != NULL)
	{
		jug_setId(nuevoJugador, 0);
		jug_setNombreCompleto(nuevoJugador," ");
		jug_setEdad(nuevoJugador,0);
		jug_setPosicion(nuevoJugador," ");
		jug_setNacionalidad(nuevoJugador," ");
		jug_setIdSeleccion(nuevoJugador,0);
	}
	return nuevoJugador;
}
//texto

/** \brief reserva espacio de memoria dinamica para un elemento de tipo Jugador cargando en todos sus campos los datos pasados como parametros en formato de cadena de caracteres
 *
 * \param idStr char*
 * \param nombreCompletoStr char*
 * \param edadStr char*
 * \param posicoinstr char*
 * \param nacionalidadstr char*
 * \param  idSeleccionStr char*
 * \return Jugador* retorna un puntero al lugar de la memoria asignado o devuelve NULL si no lo logro
 *
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
	Jugador* nuevoJugador = NULL;
	//nuevoJugador = jug_new();

	if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL)
	{
		nuevoJugador = jug_new();

		if(nuevoJugador != NULL)
		{
			jug_setId(nuevoJugador, atoi(idStr));
			jug_setNombreCompleto(nuevoJugador,nombreCompletoStr);
			jug_setEdad(nuevoJugador,atoi(edadStr));
			jug_setPosicion(nuevoJugador,posicionStr);
			jug_setNacionalidad(nuevoJugador,nacionalidadStr);
			jug_setIdSeleccion(nuevoJugador,atoi(idSeleccionStr));

			//jug_delete(nuevoJugador);//free
			//nuevoJugador = NULL;
		}
	/*	else
		{
			jug_delete(nuevoJugador);//free
		nuevoJugador = NULL;
		}*/

		//}
	}
	return nuevoJugador;
}
/** \brief Libera el espacio en memoria apuntado por "this"
 *
 * \param Jugsdor*this
 * \return int retorna 0 si pudo y 1 si no lo logro
 *
 */
void jug_delete(Jugador* this)
{
	//int retorno = -1;
	if(this != NULL)
	{
		free(this);
	//	retorno = 0;
	}
	//return retorno;
}
/** \brief  setea id del jugadores
	 *
	 * \param int id
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_setId(Jugador* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene id del jugados

	 *
	 * \param int id
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_getId(Jugador* this,int* id)
{
	int retorno = -1;
	if(this != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
/** \brief  setea id del jugador
	 *\param this
	 * \param int *id
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_setID(Jugador *this, int *id) {
	int sucess = 0;

	if (this != NULL) {
		if (id >= 0) {
			this->id = *id;
			sucess = 1;
		}
	}
	return sucess;
}
/** \brief obtiene id del jugados

	 *
	 * \param int id
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_getID(Jugador *this, int *id) {
	int sucess = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		sucess = 1;
	}
	return sucess;
}
//****************************************
/** \brief  setea nombre del jugador
	 *\param this
	 * \param char* nombreCompleto
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;
	if(this != NULL && nombreCompleto != NULL && strlen(nombreCompleto) > 1 && strlen(nombreCompleto) < 30)
	{
		strcpy(this->nombreCompleto,nombreCompleto);
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene NombreCompleto del jugados

	 *
	 * \param char* nombreCompleto
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;
	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno = 0;
	}
	return retorno;
}
//****************************************
/** \brief  setea posicon del jugador
	 *\param this
	 * \param char* posicion
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;
	if(this != NULL && posicion != NULL && strlen(posicion) > 1 && strlen(posicion) < 30)
	{
		strcpy(this->posicion,posicion);
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene  posicion del jugados

	 *
	 * \param char*  posicion
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;
	if(this != NULL && posicion != NULL)
	{
		strcpy(posicion,this->posicion);
		retorno = 0;
	}
	return retorno;
}
//****************************************
/** \brief  setea nacionalidad del jugador
	 *\param this
	 *\param  char* nacionalidad
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;
	if(this != NULL && nacionalidad != NULL && strlen(nacionalidad) > 1 && strlen(nacionalidad) < 30)
	{
		strcpy(this->nacionalidad,nacionalidad);
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene  nacionalidad del jugados
	 *
	 * \param char*  nacionalidad
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;
	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad,this->nacionalidad);
		retorno = 0;
	}
	return retorno;
}
//****************************************
/** \brief  setea edad del jugador
	 *\param this
	 *\param int edad
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;
	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene  edad del jugados
	 *\param this
	 * \param ,int* edad
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;
	if(this != NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}
	return retorno;
}
//****************************************
/** \brief  setea isdeleccion del jugador
	 *\param this
	 *\param int idSeleccion
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;
	if(this != NULL && idSeleccion >= 0)//
	{
		this->idSeleccion = idSeleccion;
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene  idSeleccion del jugador
	 *\param this
	 * \param ,int* idSeleccion
	 * \return int 0 si pudo -1 si no pudo
	 *
 */
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;
	if(this != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}
	return retorno;
}//=======================
int jugador_obtenerElmaximoId(Jugador* this,int* id)
{
    int retorno = -1;

    if(this != NULL){

        jug_getID(this,id);
        retorno = 0;
    }
    return retorno;
}
void encabezado()
{
	int anchoColumnaId = -7;
	int anchoColumnaNombre = -20;
	int anchoColumnaEdad = -10;
	int anchoColumnaPosicion = -15;
	int anchoColumnaNacionalidad = -20;
	int anchoColumnaIdSeleccion = -7;

	printf("\n*******+********************+**********+***************+********************+*******+\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnaId, "ID", anchoColumnaNombre, "NOMBRE", anchoColumnaEdad, "EDAD",anchoColumnaPosicion, "POSICION",
			anchoColumnaNacionalidad, "NACIONALIDAD", anchoColumnaIdSeleccion, "ID SELECCION");
	printf("*******+********************+**********+***************+********************+*******+\n");

//	printf("_____________________________________________________________________________________________________\n");
//	printf("                       LISTA DE JUGADORES                               \n");
//	printf("_____________________________________________________________________________________________________\n");
//	printf("ID                    NOMBRE               EDAD         POSICION     NACIONALIDAD    idSELECCION\n");
//	printf("_____________________________________________________________________________________________________\n");
}
/**
 * Convierte un id en texto dependiendo a la posicon que le corresponda.
 * \param id recibe id a convertir en texto.
 * \param descripcionCorrespondiente devuelve por referenciaposicion correspondite al id.
 * \return retorna -1 si no se pudo hacer la conversion y 0 si se pudo.
 */
int convertirIdEnPosicion(int id, char* nombreDeLaPosicion)
{
	int retorno = -1;

	if(id > 0 && nombreDeLaPosicion != NULL)
	{
		switch(id)
		{
		case 1:
			strcpy(nombreDeLaPosicion, "Portero");
			retorno = 0;
			break;
		case 2:
			strcpy(nombreDeLaPosicion, "Defensa central");

			retorno = 0;
			break;
		case 3:
			strcpy(nombreDeLaPosicion, "Lateral izquierdo");

			retorno = 0;
			break;
		case 4:
			strcpy(nombreDeLaPosicion, "Lateral derecho");
			retorno = 0;
			break;
		case 5:
			strcpy(nombreDeLaPosicion, "Pivote");
			retorno = 0;
			break;
		case 6:
			strcpy(nombreDeLaPosicion, "Mediocentro");
			retorno = 0;
			break;
		case 7:
			strcpy(nombreDeLaPosicion, "Mediocentro ofensivo");
			retorno = 0;
			break;
		case 8:
			strcpy(nombreDeLaPosicion, "Extremo izquierdo");
			retorno = 0;
			break;
		case 9:
			strcpy(nombreDeLaPosicion, "Extremo derecho");
			retorno = 0;
			break;
		case 10:
			strcpy(nombreDeLaPosicion, "Mediapunta");
			retorno = 0;
			break;
		case 11:
			strcpy(nombreDeLaPosicion, "Delantero centro");
			retorno = 0;
			break;
		case 12:
			strcpy(nombreDeLaPosicion, "Interior derecho");
			retorno = 0;
			break;
		}
	}
	return retorno;
}
/** \brief imprime un  jugador
 *\param Jugador* this
 * \return int 0 si pudo -1 si no pudo
 *
*/
int jug_imprimirUnJugador(Jugador* this)
{
	int retorno = -1;
	int id;
	char nombreC[30];
	int edad;
	int posicionInt=0;
	char posicion[30];
	int nacionalidadInt=0;
	char nacionalidad[30];
	int idSeleccion;
	if(this != NULL)
	{

		jug_getId(this,&id);
		//jug_getId(this,&id);
		jug_getNombreCompleto(this,nombreC);
		jug_getEdad(this,&edad);
		jug_getPosicion(this,posicion);
		jug_getNacionalidad(this,nacionalidad);
		jug_getSIdSeleccion(this,&idSeleccion);

		convertirIdEnPosicion(posicionInt,posicion);
		convertirIdEnPosicion(nacionalidadInt,nacionalidad);

		printf("%3d      %22s    %10d   %20s    %5s    %5d \n",
				id,nombreC,edad,posicion,nacionalidad,idSeleccion);
		retorno = 0;
	}
	printf("_____________________________________________________________________________________________________\n");
	return retorno;
}
//===============

/** \brief reserva espacio de memoria dinamica para un elemento de tipo jugador cargando en todos sus campos los datos pasados como parametros en los formatos correspondientes
 *
 * \param id int
 * \param nombreC char*
 * \param int edad
 * \param  char* posicion
 * \param  char* nacionalidad
 *\param int idSeleccion
 * \return jugador* retorna un puntero al lugar de la memoria asignado o devuelve NULL si no lo logro
 *
 */
Jugador* jug_newParametrosReales(int id,char* nombreC,int edad,char* posicion, char*nacionalidad, int idSeleccion)

{//ya no con * los parametros
	Jugador* nuevoJugador = NULL;

	if(id > 0 && nombreC != NULL && edad > 0 && posicion != NULL && nacionalidad != NULL  && idSeleccion >0){
		nuevoJugador = jug_new();
		if(nuevoJugador != NULL){
			jug_setId(nuevoJugador,id);
					jug_setNombreCompleto(nuevoJugador,nombreC);
					jug_setEdad(nuevoJugador,edad);
					jug_setPosicion(nuevoJugador,posicion);
					jug_setNacionalidad(nuevoJugador,nacionalidad);
					jug_setIdSeleccion(nuevoJugador,idSeleccion);
		}
	}
	return nuevoJugador;
}
Jugador* jug_newParametrosReales2(int* id,char* nombreC,int* edad,char* posicion, char*nacionalidad, int* idSeleccion)
{
	Jugador* nuevoJugador = NULL;

	if(id != NULL && nombreC != NULL && edad != NULL && posicion != NULL && nacionalidad != NULL  && idSeleccion != NULL){
		nuevoJugador = jug_new();
		if(nuevoJugador != NULL){
			jug_setId(nuevoJugador,(*id));
					jug_setNombreCompleto(nuevoJugador,nombreC);
					jug_setEdad(nuevoJugador,*edad);
					jug_setPosicion(nuevoJugador,posicion);
					jug_setNacionalidad(nuevoJugador,nacionalidad);
					jug_setIdSeleccion(nuevoJugador,*idSeleccion);

				//employee_delete(nuevoJugador);
				//nuevoJugador = NULL;
		}
	}
	return nuevoJugador;
}
///


/**
 * Lista los posiciones disponibles con sus ids.

 */
//2 formas
void subMenuListadoPosiciones()//se muestra corrido pro los \t estan bien!
{
	int anchoColumnaOpcion = -7;
	int anchoColumnaPosicion = -20;

	printf("\n********+********************+\n");
	printf("|%*s|%*s|\n", anchoColumnaOpcion, "Opcion", anchoColumnaPosicion , "Posicion");
	printf("********+********************+\n");

	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 1, anchoColumnaPosicion, "Portero");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 2, anchoColumnaPosicion, "Defensa central");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 3, anchoColumnaPosicion, "Lateral izquierdo");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 4, anchoColumnaPosicion, "Lateral derecho");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 5, anchoColumnaPosicion, "Pivote");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 6, anchoColumnaPosicion, "Mediocentro");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 7, anchoColumnaPosicion, "Mediocentro ofensivo");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 8, anchoColumnaPosicion, "Extremo izquierdo");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1, 9, anchoColumnaPosicion, "Extremo derecho");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 10, anchoColumnaPosicion, "Mediapunta");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 11, anchoColumnaPosicion, "Delantero centro");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 12, anchoColumnaPosicion, "Interior derecho");
	printf("--------+-------------------+");

}
/**
 * Lista los nacionalidades disponIbLes con sus ids.

 */
void subMenuListadoNacionalidades()
{
	int anchoColumnaOpcion = -7;
	int anchoColumnaNacionalidades = -20;
	printf("\n********+********************+\n");
	printf("|%*s|%*s|\n", anchoColumnaOpcion, "Opcion", anchoColumnaNacionalidades , "Nacionalidades");
	printf("********+********************+\n");


	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 1, anchoColumnaNacionalidades, "Aleman");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 2, anchoColumnaNacionalidades, "Saudi");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 3, anchoColumnaNacionalidades, "Argentino");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 4, anchoColumnaNacionalidades, "Australiano");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 5, anchoColumnaNacionalidades, "Belga");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 6, anchoColumnaNacionalidades, "Brasilero");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 7, anchoColumnaNacionalidades, "Camerun");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 8, anchoColumnaNacionalidades, "Canadiense");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 9, anchoColumnaNacionalidades, "Surcoreano");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 10, anchoColumnaNacionalidades, "Costarricense");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 11, anchoColumnaNacionalidades, "Croata");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 12, anchoColumnaNacionalidades, "Danes");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 13, anchoColumnaNacionalidades, "Ecuatoriano");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 14, anchoColumnaNacionalidades, "Espanol");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 15, anchoColumnaNacionalidades, "Estado Unidense");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 16, anchoColumnaNacionalidades, "Frances");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 17, anchoColumnaNacionalidades, "Gales");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 18, anchoColumnaNacionalidades, "Ghanes");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 19, anchoColumnaNacionalidades, "Holandes");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 20, anchoColumnaNacionalidades, "Ingles");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 21, anchoColumnaNacionalidades, "Irani");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 22, anchoColumnaNacionalidades, "Japones");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 23, anchoColumnaNacionalidades, "Marroqui");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 24, anchoColumnaNacionalidades, "Mexicano");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 25, anchoColumnaNacionalidades, "Polaco");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 26, anchoColumnaNacionalidades, "Portugues");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 27, anchoColumnaNacionalidades, "Qatari");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 28, anchoColumnaNacionalidades, "Senegales");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 29, anchoColumnaNacionalidades, "Serbio");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 30, anchoColumnaNacionalidades, "Suizo");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 31, anchoColumnaNacionalidades, "Tunecino");
	printf("%*d|%*s|\n",anchoColumnaOpcion-1 , 32, anchoColumnaNacionalidades, "Uruguayo");
	printf("--------+-------------------+");

}

/** \brief ordena jugador por Nacionalidad
 *\param void* p1
 *\param void* p2
 * \return int
*/
int jug_ordenarPorNacionalidad(void* p1,void*p2)
{
	char nacionalidad1[50];

	char nnacionalidad2[50];
	int retorno;
	Jugador* jugador1 = (Jugador*)p1;
	Jugador* jugador2 = (Jugador*)p2;
	if(jugador1 != NULL && jugador2 != NULL)
	{
       jug_getNacionalidad(jugador1, nacionalidad1);
       jug_getNacionalidad(jugador2, nnacionalidad2);
//usar un strcmp y no con i
       retorno =stricmp(nacionalidad1,nnacionalidad2);
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
int jug_ordenarPorEdad(void* p1,void*p2)//void puntero al elemento lo casteo
{
	int edad1=0;

	int edad2=0;

	int retorno;
	Jugador* jugador1 = (Jugador*)p1;
	Jugador* jugador2 = (Jugador*)p2;
	if(jugador1 != NULL && jugador2 != NULL)
	{
		jug_getEdad(jugador1, &edad1);
		jug_getEdad(jugador2, &edad2);
		if(edad1 > edad2)
		{
			retorno = 1;
		}
		else if(edad1 < edad2)
		{
			retorno = -1;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}
/** \brief ordena jugador por Nombre
 *\param void* p1
 *\param void* p2
 * \return int
*/
int jug_ordenarPorNombre(void* p1,void*p2)
{
	char nombre1[50];
	char nombre2[50];
	int retorno;
	Jugador* jugador1 = (Jugador*)p1;
	Jugador* jugador2 = (Jugador*)p2;
	if(jugador1 != NULL && jugador2 != NULL)
	{
       jug_getNombreCompleto(jugador1, nombre1);
       jug_getNombreCompleto(jugador2, nombre2);

       retorno =stricmp(nombre1,nombre2);
	}
	return retorno;
}
