#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"
#include "Seleccion.h"
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
	int sucess = -1;

	if (this != NULL) {
		if (id >= 0) {
			this->id = *id;
			sucess = 0;
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
void jugador_encabezado()
{
	int anchoColumnaId = -6;
	int anchoColumnaNombre = -25;
	int anchoColumnaEdad = -10;
	int anchoColumnaPosicion = -25;
	int anchoColumnaNacionalidad = -20;
	int anchoColumnaIdSeleccion = -15;
	int anchoColumnaConvocado = -25;

	printf("\n*******+*************************+**********+*************************+********************+***************+*************************\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnaId, "ID", anchoColumnaNombre, "NOMBRE", anchoColumnaEdad, "EDAD",anchoColumnaPosicion, "POSICION",
			anchoColumnaNacionalidad, "NACIONALIDAD", anchoColumnaIdSeleccion, "ID SELECCION" , anchoColumnaConvocado, "PAIS QUE TE CONVOCADO");
	printf("*******+*************************+**********+*************************+********************+***************+*************************\n");

}
/**
 * Convierte un id en texto dependiendo a la posicon que le corresponda.
 * \param id recibe id a convertir en texto.
 * \param descripcionCorrespondiente devuelve por referenciaposicion correspondite al id.
 * \return retorna -1 si no se pudo hacer la conversion y 0 si se pudo.
 */
int jugador_convertirIdEnPosicion(int id, char* nombrePosicion)
{
	int retorno = -1;

	if(id > 0 && nombrePosicion != NULL)
	{
		switch(id)
		{
		case 1:
			strcpy(nombrePosicion, "Portero");
			retorno = 0;
			break;
		case 2:
			strcpy(nombrePosicion, "Defensa central");

			retorno = 0;
			break;
		case 3:
			strcpy(nombrePosicion, "Lateral izquierdo");

			retorno = 0;
			break;
		case 4:
			strcpy(nombrePosicion, "Lateral derecho");
			retorno = 0;
			break;
		case 5:
			strcpy(nombrePosicion, "Pivote");
			retorno = 0;
			break;
		case 6:
			strcpy(nombrePosicion, "Mediocentro");
			retorno = 0;
			break;
		case 7:
			strcpy(nombrePosicion, "Mediocentro ofensivo");
			retorno = 0;
			break;
		case 8:
			strcpy(nombrePosicion, "Extremo izquierdo");
			retorno = 0;
			break;
		case 9:
			strcpy(nombrePosicion, "Extremo derecho");
			retorno = 0;
			break;
		case 10:
			strcpy(nombrePosicion, "Mediapunta");
			retorno = 0;
			break;
		case 11:
			strcpy(nombrePosicion, "Delantero centro");
			retorno = 0;
			break;
		case 12:
			strcpy(nombrePosicion, "Interior derecho");
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
int jugador_imprimirUnJugador(Jugador* this )
{
	int retorno = -1;
	int id;
	char nombreCompleto[30];
	int edad;
	int posicionInt=0;
	char posicion[30];
	int nacionalidadInt=0;
	char nacionalidad[30];
	int idSeleccion;
	int anchoColumnaId = -6;
	int anchoColumnaNombre = -25;
	int anchoColumnaEdad = -10;
	int anchoColumnaPosicion = -25;
	int anchoColumnaNacionalidad = -20;
	int anchoColumnaIdSeleccion = -15;

	if(this != NULL)
	{

		jug_getId(this,&id);
		//jug_getId(this,&id);
		jug_getNombreCompleto(this,nombreCompleto);
		jug_getEdad(this,&edad);
		jug_getPosicion(this,posicion);
		jug_getNacionalidad(this,nacionalidad);
		jug_getSIdSeleccion(this,&idSeleccion);

		jugador_convertirIdEnPosicion(posicionInt,posicion);
		jugador_convertirIdEnPosicion(nacionalidadInt,nacionalidad);

		if(idSeleccion != 0)
		{
			printf("|%*d|%*s|%*d|%*s|%*s|%*d|%*d|\n",anchoColumnaId,id,anchoColumnaNombre,nombreCompleto,anchoColumnaEdad,edad,
					anchoColumnaPosicion,posicion,anchoColumnaNacionalidad,nacionalidad,anchoColumnaIdSeleccion,idSeleccion,20, idSeleccion);
		}else{
			printf("|%*d|%*s|%*d|%*s|%*s|%*d|%*s|\n",anchoColumnaId,id,anchoColumnaNombre,nombreCompleto,anchoColumnaEdad,edad,
					anchoColumnaPosicion,posicion,anchoColumnaNacionalidad,nacionalidad,anchoColumnaIdSeleccion,idSeleccion,20, "NO CONVOCADO");
		}


		retorno = 0;
	}
	printf("-------+-------------------------+----------+-------------------------+--------------------+---------------+--------------------+\n");
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
Jugador* jugador_newConParametros(int id,char* nombreC,int edad,char* posicion, char*nacionalidad, int idSeleccion)

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
Jugador* jugador_newConParametros_tomaDatoArchivo(int* id,char* nombreC,int* edad,char* posicion, char*nacionalidad, int* idSeleccion)
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
void jugador_subMenuListadoPosiciones()//se muestra corrido pro los \t estan bien!
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
void jugador_subMenuListadoNacionalidades()
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
int jugador_ordenarPorNacionalidad(void* p1,void*p2)
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
int jugador_ordenarPorEdad(void* p1,void*p2)//void puntero al elemento lo casteo
{
	int auxEdadUno=0;
	int auxEdadDos=0;
	int retorno;
	Jugador* jugador1 = (Jugador*)p1;
	Jugador* jugador2 = (Jugador*)p2;


	if(jugador1 != NULL && jugador2 != NULL)
	{
		jug_getEdad(jugador1, &auxEdadUno);
		jug_getEdad(jugador2, &auxEdadDos);
		if(auxEdadUno > auxEdadDos)
		{
			retorno = 1;
		}else if(auxEdadUno < auxEdadDos)
		{
			retorno = -1;
		}else{
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
int jugador_ordenarPorNombre(void* p1,void*p2)
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


/// \fn int jug_convocar(LinkedList*, LinkedList*)
/// \brief Se listan selecciones, se da a elegir 1 (validacion - selec_Solicitar_Id), en caso que el jugador pueda ser convocado se
/// le setea el id de seleccion y se suma 1 convocado al campo convocados de la estructura de tipo Seleccion del pais.
///Imprimo el nombre del jugador convocado y el del pais convocante.
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jugador_paraConvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int idSeleccion;
	int jugIdSeleccion;
	int indiceSeleccion;
	int indiceJugador;
	int convocados;
	Seleccion* pSeleccion;
	Jugador* pJugador;
	char nombreCompleto[100];
	char pais[30];
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{

		ll_sort(pArrayListSeleccion, selec_ordenarPorId, 1);
		controller_listarSelecciones(pArrayListSeleccion);
		if(selec_Solicitar_Id(pArrayListSeleccion, &indiceSeleccion)==0)
		{
			jugador_imprimirListaJugadores(pArrayListJugador, pArrayListSeleccion, 3);
			jugador_pedirId(pArrayListJugador, &indiceJugador, "\nIngrese ID del jugador que quiere convocar :");
			pJugador = ll_get(pArrayListJugador, indiceJugador);
			pSeleccion=ll_get(pArrayListSeleccion, indiceSeleccion);

			if(jug_getSIdSeleccion(pJugador, &jugIdSeleccion)==0 && selec_getConvocados(pSeleccion, &convocados)==0 && selec_getId(pSeleccion, &idSeleccion)==0)
			{
				if(jugIdSeleccion == 0)
				{
					convocados=convocados+1;
					if(selec_setConvocados(pSeleccion, convocados)==0 && jug_setIdSeleccion(pJugador, idSeleccion)==0 &&
							jug_getNombreCompleto(pJugador, nombreCompleto)==0 && selec_getPais(pSeleccion, pais)==0)
					{
						printf("<<<<<<<<<<El jugador CONVOCADO por : %s fue : %s >>>>>>>>>>\n\n",pais , nombreCompleto);
						retorno=0;
					}
				}else{
					printf("\n****************************************");
					printf("\nERROR, el jugador fue esta convocado...");
					printf("\n****************************************");
				}
			}
		}
	}

	return retorno;
}



/// \fn int jug_imprimirJugadores(LinkedList*, LinkedList*, int)
/// \brief Imprime/lista en forma ordenada los datos de los jugadores, incluyendo si estan o no seleccionados. Se
/// tiene en cuenta una referencia recibida por parametro a la hora de listar.
///
/// \param pArrayListJugador lista de jugadores
/// \param pArrayListSeleccion lista de selecciones
/// \param referenciaDeUso 	 * referenciaDeUso==1 / SE MUESTRAN TODOS LOS JUGADORES.
///	referenciaDeUso==2 / SE MUESTRAN LOS JUGADORES CONVOCADOS.
///	 referenciaDeUso==3 / SE MUESTRAN LOS JUGADORES NO CONVOCADOS.
/// \return
int jugador_imprimirListaJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, int referenciaDeUso)
{
	int retorno=-1;
	int id;
	char nombreCompleto[200];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int idSeleccion;
	char descripcionSeleccion[30];
	int tam;
	//*referenciaDeUso=flagRefUno;
	/*
	 * referenciaDeUso==1 / SE MUESTRAN TODOS LOS JUGADORES.
	 * referenciaDeUso==2 / SE MUESTRAN LOS JUGADORES CONVODADOS.
	 * referenciaDeUso==3 / SE MUESTRAN LOS JUGADORES NO CONVOCADOS.
	 */
	Jugador* pJugAux;

	//index>-1 para mostrar el indice 0
	if(pArrayListJugador!=NULL)
	{
		tam=ll_len(pArrayListJugador);

		printf("+================================================================================================================================+\n");
				printf("|%*s|\n",-128,"                                                    JUGADORES ");
				printf("+================================================================================================================================+\n");
				printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n%s\n",-6,"  ID",-40,"         NOMBRE COMPLETO",-4,"EDAD",-25,"      POSICION",
						-18,"    NACIONALIDAD",-8,"ID SELEC.",-20,"PAIS QUE CONVOCA",
						"+================================================================================================================================+");

		for(int i=0;i<tam;i++)
		{
			pJugAux=ll_get(pArrayListJugador, i);
			if(jug_getId(pJugAux, &id)==0 &&
					jug_getNombreCompleto(pJugAux, nombreCompleto)==0 &&
					jug_getPosicion(pJugAux, posicion) == 0 &&
					jug_getNacionalidad(pJugAux, nacionalidad)== 0 &&
					jug_getEdad(pJugAux,&edad)== 0 &&
					jug_getSIdSeleccion(pJugAux, &idSeleccion)==0)
			{
				if(idSeleccion>0 && (referenciaDeUso==2 || referenciaDeUso==1))
				{
					retorno=0;
					selec_AsignarDescripcionPais(pArrayListSeleccion, pArrayListJugador, i, descripcionSeleccion);
					printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|%*s|\n",
							-4,id,-40,nombreCompleto,-3,edad,-25,posicion,-18,nacionalidad,-5,idSeleccion,-20,descripcionSeleccion);
				}
				else
				{
					if(idSeleccion==0 && (referenciaDeUso==3 || referenciaDeUso==1))
					{
						retorno=0;
						printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|%*s|\n",
									-4,id,-40,nombreCompleto,-3,edad,-25,posicion,-18,nacionalidad,-5,idSeleccion,-20,"NO CONVOCADO");
					}
				}
			}
		}
		printf("+================================================================================================================================+\n");
	}
	return retorno;
}


/// \fn int jug_Solicitar_Id(LinkedList*, int*, char*)
/// \brief Solicito id, valido que exista y retorno el indice en el que se encuentra (funcion jug_BuscarPorId).
///
/// \param pArrayListJugador
/// \param indice posicion del id
/// \param mensaje descripcion para solicitar el id
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jugador_pedirId(LinkedList* pArrayListJugador, int * indice ,char * mensaje)
{
	int retorno=-1;
	int idBuscado;

	//BUSCO EL ULTIMO ID PARA DARLE UN MAXIMO AL INGRESAR EL ID.

	if(pArrayListJugador!=NULL)
	{
		do
		{
			utn_pedirNumeroEnteroComoMinimo(&idBuscado, mensaje, "\nError", 1);
//			ingresarIntConMinimo(&idBuscado, mensaje, "ERROR, Ingrese ID existente\n", 1);
			//ESTE PRINT ES POR SI EL USUARIO CARGA UN ID QUE ESTA POR DEBAJO DEL MAXIMO PERO QUE YA FUE BORRADO.
			if(jugador_buscarPorId(pArrayListJugador, idBuscado, &(*(indice)))==-1)
			{
				printf("ERROR, Ingrese ID existente.\n");
			}
			//printf("POSICION %d\n",posicion);
		}while(jugador_buscarPorId(pArrayListJugador, idBuscado, &(*(indice)))==-1);
		retorno=0;
	}
	return retorno;
}

/// \fn int jug_BuscarPorId(LinkedList*, int, int*)
/// \brief Recibo un id y busco el indice en donde se encuentra la estructura.
///
/// \param pArrayListJugador
/// \param idBuscado
/// \param indice posicion retornada por referencia
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jugador_buscarPorId(LinkedList* pArrayListJugador, int idBuscado, int* indice)
{
	int retorno=-1;
	Jugador* AuxJugador;
	int idAux;
	if(pArrayListJugador!=NULL)
	{
		int tam= ll_len(pArrayListJugador);
		//printf("tam %d",tam);
		for(int i=0;i<tam;i++)
		{
			//printf("ENTRE AL FOR DE BUSCAR POR ID\n");
			AuxJugador=ll_get(pArrayListJugador, i);
			//NO DEBO HACER (*(AuxJugador+i).id PORQUE YA ll_get me retorna puntero a indice especificado, ademas el tema de trabajar con posiciones consecutivas o no.
			//if((*(AuxJugador)).id==idBuscado)
			if(jug_getId(AuxJugador, &idAux)==0)
			{
				if(idAux==idBuscado)
				{
					*indice=i;
					//printf("POSICION %d\n",*posicion);
					retorno=0;
					break;
				}
			}

		}
	}
	return retorno;
}
