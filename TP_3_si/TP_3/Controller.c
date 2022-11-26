#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "parser.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "utn.h"

int guardarComoTexto_maxID(FILE* pFile, LinkedList* pArrayListJugador,int* maxID){
	Jugador* jugador;
	int id;
	int retorno = -1;
	int maxId;
	int bandera = 0;

	if(pFile != NULL && pArrayListJugador != NULL && maxID != NULL){	//si el archivo y el array no son null..

		for(int i=0; i< ll_len(pArrayListJugador); i++)
		{
			jugador = ll_get(pArrayListJugador,i);	// copio la estructura del jugador del indice.
			jugador_obtenerElmaximoId(jugador,&id);	//obtengo toda la info del jug
			if(bandera == 0 || id > maxId)
			{
				maxId = id;
				bandera=1;
			}
			retorno = 0;
		}
	}
	*maxID = maxId;
	return retorno;
}
/** \brief obtiene el id ultimo desde el archivo  y lo guarda en el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int controller_guardarComoTextoMaxID(FILE* pFile,char* path, LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int maxID;

	if(pFile !=NULL && guardarComoTexto_maxID(pFile,pArrayListJugador,&maxID))
	{ //si el archivo no es null y pude escribir, retorno 0
		retorno = 0;
		fprintf(pFile,"%d\n",maxID+1);	//escribo los datos de cada jug en el archivo.
	}
	return retorno;
}
/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 *
 * \return int
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 1;
	int flag=0;
	FILE *pArchivo; //= fopen(path,"r");
	FILE *pArchivoId; //= fopen("elUltimoId.txt","w");
	pArchivo=fopen(path,"r");
	pArchivoId=fopen("elUltimoId.txt","w");
	if(pArchivo != NULL && pArchivoId != NULL)
	{
		flag = ll_isEmpty(pArrayListJugador);
		if(flag == 1)
		{
			retorno = parser_JugadorFromText(pArchivo,pArrayListJugador);
			fclose(pArchivo);
			retorno = 0;
		}else{
			retorno= 2;
		}
	}
	if(controller_guardarComoTextoMaxID(pArchivoId,"maxid.txt",pArrayListJugador))
	{
		fclose(pArchivoId);
	}
	return retorno;

	/*parser_JugadorFromText(pArchivo,pArrayListJugador);
		fclose(pArchivo);
		retorno = 0;
	}
	if(controller_guardarComoTextoMaxID(pArchivoId,"maxid.txt",pArrayListJugador))
	{
		fclose(pArchivoId);
	}
	return retorno;*/
}
/** \brief Carga los datos de los jugadores desde el archivo generado en MODO BINARIO
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	///return 1;
	int retorno = -1;
	FILE *pArchivo = fopen(path,"rb");
	FILE *pArchivoId = fopen("elUltimoId.txt","w");


	if(path != NULL && pArrayListJugador != NULL)
	{
		if(pArchivo != NULL && parser_JugadorFromBinary(pArchivo,pArrayListJugador)==0)
		{
			printf("Archivo binario cargado exitosamente\n");
			retorno = 0;
		}
		if(controller_guardarComoTextoMaxID(pArchivoId,"maxid.txt",pArrayListJugador))
		{
			fclose(pArchivoId);
		}
		else
		{
			printf("El archivo no pudo abrirse\n");
		}
	}
	fclose(pArchivo);
	return retorno;
}
/** \brief busca a un jugador mediante su id y retorna su posicion en la lista LinkedList
 *
 * \param idABuscar int* id a buscar
 * \param pArrayListJugador LinkedList* lista a donde buscar al jugador
 * \return int retorna el indice si pudo encontrarlo y -1 si no lo logro
 *
 */
int buscarJugadorId(int* idABuscar, LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int i;
	int id;//id del jugador
	Jugador* jugador;

	if(idABuscar != NULL && pArrayListJugador != NULL)
	{
		for(i = 0; i < ll_len(pArrayListJugador); i++)
		{
			jugador = (Jugador*) ll_get(pArrayListJugador, i); //tomo un jug
			jug_getID(jugador,&id); //tomo su id
			if(*idABuscar == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/** \brief obtener el id  y leerlo
 * en el archivo de texto
 *
 * \param int id*
 * \return int 0 si pudo -1 si no pudo
 *
 */
int obtenerID(int* id){
	int retorno = -1;
	int proxId=371;

	FILE* pFile;
	pFile = fopen("elUltimoId.txt","r");
	if(pFile!=NULL)
	{
		fscanf(pFile,"%d\n", &proxId);
		*id = proxId;
		fclose(pFile);
		retorno = 0;
	}
	return retorno;
}
/** \brief  escribe
 * en el archivo de texto
 *
 * \param int id
 * \return int 0 si pudo -1 si no pudo
 *
 */
int actualizarIdok(int id){
	int proxId =++id;//
	int retorno = -1;
	FILE* pFile;
	pFile = fopen("elUltimoId.txt","w");
	if(pFile!=NULL)
	{
		fprintf(pFile,"%d\n",proxId);
		fclose(pFile); // lo cierro si lo pude abrir.
		retorno = 0;
	}
	return retorno;
}
//================================save
/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)//SI
{
	int retorno = -1;
	int id;
	char nombreC[30];
	int edad;
	char posicion[30];
	char posicionH[12][150]={"Portero","Defensa central","Lateral izquierdo","ateral derecho","Pivote","Mediocentro",
			"Mediocentro ofensivo","Extremo izquierdo",
			"Extremo derecho","Mediapunta","Delantero centro","Interior derecho"};
	char nacionalidad[30];
	char nacionalidadH[32][200]={"Aleman","Saudi","Argentino","Belga","Australiano","Brasilero","Camerun","Canadiense","Surcoreano","Costarricense",
			"Croata","Danes","Ecuatoriano","Espanol","Estado Unidense","Frances","Gales","Ghanes","Holandes","Ingles",
			"Irani","Japones","Marroqui","Mexicano","Polaco","Portugues","Qatari","Senegales","Serbio","Suizo","Tunecino","Uruguayo"};

	int opcion;
	int opcionN;
	int idSeleccion;
	Jugador* nuevoJugador=jug_new();

	if(pArrayListJugador != NULL && nuevoJugador != NULL)
	{

		obtenerID(&id);
		printf("| El alta se asignara con el id: %d\n",id);
		utn_pedirNombreConEspacio(nombreC, 30, "\nIngrese nombre de jugador: ", "\nError");
		utn_pedirNumeroEntero(&edad, "\nIngrese edad de jugador (entre 1 y 30): ", "\nError", 30, 1);
		subMenuListadoPosiciones();//modificar
		utn_pedirNumeroEntero(&opcion, "\nIngrese una posicion : ", "\nError", 12, 1);
		strcpy(posicion,posicionH[opcion-1]);
		subMenuListadoNacionalidades();
		utn_pedirNumeroEntero(&opcionN, "\nIngrese una opcion de nacionalidad : ", "\nError", 32, 1);
		strcpy(nacionalidad,nacionalidadH[opcionN-1]);

		//	utn_getNumero(&idSeleccion,"Ingrese 0 como  id seleccion de jugador: ","ERROR!!!\n",0,32,10);
		//	utn_pedirNumeroEntero(idSeleccion, "", "\nerror", 32, 10);
		idSeleccion = 0;

		if(jug_setID(nuevoJugador,&id)== -1||
				jug_setNombreCompleto(nuevoJugador,nombreC)==-1 ||
				jug_setEdad(nuevoJugador,edad) ==-1||
				jug_setPosicion(nuevoJugador,posicion)==-1||
				jug_setNacionalidad(nuevoJugador,nacionalidad) ==-1||
				jug_setIdSeleccion(nuevoJugador,idSeleccion))
		{
			jug_delete(nuevoJugador);
		}else{
			retorno =0;
			ll_add(pArrayListJugador, nuevoJugador);
			actualizarIdok(id);
		}
		encabezado();
		jug_imprimirUnJugador(nuevoJugador);
	}
	return retorno;
}
/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */

int controller_listarJugadores(LinkedList* pArrayListJugador)//cambio de ubicacion xq tira warning
{
	Jugador* jugador;
	int retorno = -1;
	int i;

	if(pArrayListJugador != NULL)
	{
		encabezado();
		retorno = 0;
		for(i = 0; i < ll_len(pArrayListJugador); i++)
		{
			jugador = (Jugador*)ll_get(pArrayListJugador,i);
			jug_imprimirUnJugador(jugador);
		}
	}
	printf("----------------------------------------------------------------------\n");
	return retorno;
}
/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{//AGREGAR MAS NACIONALIDADEEEES!SON32
	// return 1;
	int retorno = -1;
	int opcion;
	int opcionNacionalidad;
	int idABuscar;
	int indice;
	int idMax;
	int obtenerId;
	char auxNombre[30];
	int auxEdad;
	char auxPosicion[30];
	char auxPosicionH[12][200]={"Portero","Defensa central","Lateral izquierdo","Lateral derecho",
			"Pivote","Mediocentro","Mediocentro ofensivo","Extremo izquierdo",
			"Extremo derecho","Mediapunta","Delantero centro","Interior derecho"};

	char auxNacionalidad[30];
	char auxNacionalidadH[32][200]={"Aleman","Saudi","Argentino","Belga","Australiano","Brasilero","Camerun","Canadiense","Surcoreano","Costarricense",
			"Croata","Danes","Ecuatoriano","Espanol","Estado Unidense","Frances","Gales","Ghanes","Holandes","Ingles",
			"Irani","Japones","Marroqui","Mexicano","Polaco","Portugues","Qatari","Senegales","Serbio","Suizo","Tunecino","Uruguayo"};

	Jugador* jugadorAmodificar;

	if(pArrayListJugador != NULL)
	{
		retorno =0;
		obtenerID(&idMax);
		controller_listarJugadores(pArrayListJugador);
		utn_pedirNumeroEntero(&idABuscar, "\nIngrese el ID del jugador que quiere modificar: \n", "\nError", (idMax-1), 0);
		//		utn_getNumero(&idABuscar,"\nIngrese el id del jugador que quiere modificar: \n","ERROR!!!\n",0,(idMax-1),10);
		indice = buscarJugadorId(&idABuscar, pArrayListJugador);

		jugadorAmodificar = (Jugador*)ll_get(pArrayListJugador,indice);
		jug_getID(jugadorAmodificar,&obtenerId);//agruegue desp q dio 0

		encabezado();
		jug_imprimirUnJugador(jugadorAmodificar);
		if(indice == -1)
		{
			printf("ERROR. El id ingresado no existe\n");
		}
		do{
			printf("\n*****************************************************\n");
			printf("Campos que se pueden modificar\n");
			printf("\n1) Nombre\n2)Edad\n3)Posicion\n4)Nacionalidad\n5)Salir\n");
			printf("\n*****************************************************\n");

			if(utn_pedirNumeroEntero(&opcion, "\nIngrese opcion : " , "\nError", 5, 1) == 0)
			{
				switch(opcion)
				{
					case 1:

						if(utn_pedirNombre(auxNombre, 30, "\nIngrese el Nuevo nombre del jugador : ", "\nError") == 0)
						{
							jug_setNombreCompleto(jugadorAmodificar,auxNombre);
							encabezado();
							jug_imprimirUnJugador(jugadorAmodificar);
							printf("\nSe ha modificado el nombre con exito\n");
						}
						break;
					case 2:

						if(utn_pedirNumeroEntero(&auxEdad, "\nIngrese la Nueva edad (entre 18 y 32)", "\nError", 32, 18) == 0)
						{
							jug_setEdad(jugadorAmodificar,auxEdad);
							encabezado();
							jug_imprimirUnJugador(jugadorAmodificar);
							printf("\nSe han modificado edad con exito\n");
						}
						break;
					case 3:
						subMenuListadoPosiciones();
						utn_pedirNumeroEntero(&opcion, "\nIngrese Nueva posicion del Jugador :", "\nError", 12, 1);
						//					get_Int("\nIngrese Opcion de posicion: ",&opcion,1,12);
						strcpy(auxPosicion,auxPosicionH[opcion-1]);
						jug_setPosicion(jugadorAmodificar,auxPosicion);
						encabezado();
						jug_imprimirUnJugador(jugadorAmodificar);
						printf("\nSe ha modificado posicon con exito\n");
						break;
					case 4:
						subMenuListadoNacionalidades();
						utn_pedirNumeroEntero(&opcionNacionalidad, "\nIngrese Nueva opcion de nacionalidad : ", "\nError", 32, 1);
						//					get_Int("Ingrese Opcion de nacionalidad: ",&opcionN,1,32);
						strcpy(auxNacionalidad,auxNacionalidadH[opcionNacionalidad-1]);
						jug_setNacionalidad(jugadorAmodificar,auxNacionalidad);
						encabezado();
						jug_imprimirUnJugador(jugadorAmodificar);
						printf("\nSe ha modificado nacionalidad con exito\n");
						break;
					default : printf("\nOpcion Incorrecta ");
				}
			}
		}while(opcion != 5);}
	return retorno;
}
/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;

	int idABuscar;
	int indice;
	char rta;
	char seguir='s';
	int obtenerId;
	int maxId;

	Jugador* jugadorDarDeBaja;
	obtenerID(&maxId);
	if(pArrayListJugador != NULL){
		retorno =0;
		do{
			if(!controller_listarJugadores(pArrayListJugador))
			{
				//	utn_getNumero(&idABuscar,"\nIngrese el id del jugador que quiere dar de baja: \n","ERROR!!!\n",0,ll_len(pArrayListJugador),10);
				utn_pedirNumeroEntero(&idABuscar, "Ingrese ID del jugador que quiere dar de baja : ", "\nError",(maxId-1) , 0);
				//					utn_getNumero(&idABuscar,"\nIngrese el id del jugador que quiere dar de baja: \n","ERROR!!!\n",0,(maxId-1),10);
				indice = buscarJugadorId(&idABuscar, pArrayListJugador);
				jugadorDarDeBaja = (Jugador*)ll_get(pArrayListJugador,indice);

				jug_getID(jugadorDarDeBaja,&obtenerId);
				encabezado();
				jug_imprimirUnJugador(jugadorDarDeBaja);
			}
			if(indice == -1)
			{
				printf("ERROR. El id ingresado no existe\n");
			}

			else if(utn_pedirLetra(&rta, "\nEsta seguro/a que quiera dar de baja este ID ?\n s-n (minusculas) : ", "\nError") == 0 && rta == 's')
			{
				retorno = 0;
				ll_remove(pArrayListJugador,indice);
				jug_delete(jugadorDarDeBaja);
				printf(" Jugador eliminado correctamente\n");
			}
			utn_pedirLetra(&seguir, "\nQuiere dar de Baja otro jugador ?\n s-n (minuscula) : ", "\nError");
			//				utn_getCaracter(&seguir,"\n�Desea dar de baja otro jugador? s-n (minuscula)\n","Error, ingrese s o n minuscula\n",'n','s',2);
		}	while(seguir == 's');
	}
	return retorno;
}
/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)//cambio de ubicacion xq tira warning
{
	int retorno = -1;
	int i;
	int tam;//=0;
	Seleccion* seleccion;

	if(pArrayListSeleccion != NULL)
	{
		tam= ll_len(pArrayListSeleccion);
		encabezadoSelecciones();
		for(i = 0; i < tam; i++)
		{
			retorno = 0;
			seleccion = (Seleccion*)ll_get(pArrayListSeleccion,i);
			selec_imprimirUnaSeleccion(seleccion);
		}
		printf("_________________________________________________________________\n");
	}
	return retorno;
}
/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int orden;
	int retorno =-1;
	printf("\n0) Descendente Z-A\n1)Ascendente A-Z");
	utn_pedirNumeroEntero(&orden, "\nIngrese opcion de como quiere ordenar : ", "\nError", 1, 0);
	//	utn_getNumero(&orden, "\n\nIngrese opcion como desea ordenar:\n0.Descendente Z-A \n1.Ascendente. A-Z \nOpcion: ", "Error.", 0, 1,5);
	ll_sort(pArrayListSeleccion,selec_ordenarPorConfederacion,orden);
	retorno =0;

	return retorno;}
int controller_listarJugYSelec(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	char opcion;
	int retorno =-1;
	do{

		if(utn_pedirLetra(&opcion,
				"\n\n_____________________________________________\n"
				"||	_________  LISTADOS ________        ||\n"
				"||__________________________________________||\n"
				"||\tA.TODOS LOS JUGADORES               ||\n"
				"||\tB.TODAS LAS SELECCIONES             ||\n"
				"||\tC.JUGADORES CONVOCADOS              ||\n"
				"||\tD.SALIR                             ||\n"
				"||__________________________________________||\n"
				"Ingrese opcion en mayuscula: \n", "\nError debe ingresar en mayuscula A- D"
		)== 0)
		{
			switch(opcion)
			{
			case 'A':
				controller_listarJugadores(pArrayListJugador);
				break;
			case 'B':
				controller_listarSelecciones(pArrayListSeleccion);
				break;
			case 'C'://	hacer lista de convocados
				//  controller_listarJugadores(pArrayListJugador);
				break;
			}
		}
	}while(opcion < 'D');
	return retorno;
}
/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{

	char rta;
	int orden;
	int retorno =-1;

	do{
		if(utn_pedirLetra(&rta,
				"\n\n_______________________________________________\n"
				"||	___  ORDENAR Y LISTAR _____           ||\n"
				"||____________________________________________||\n"
				"||\tA.JUGADORES POR NACIONALIDAD          ||\n"
				"||\tB.SELECCIONES POR CONFEDERACION       ||\n"
				"||\tC.JUGADORES POR EDAD                  ||\n"
				"||\tD.JUGADORES POR NOMBRE                ||\n"
				"||\tE.SALIR                               ||\n"
				"||____________________________________________||\n",
				"| Opci�n inv�lida, debe ingresar mayusculas de A-E\n") == 0){
		}
		printf("Ingrese opcion en mayuscula\n");

		switch(rta)
		{
		case 'A':
			printf("\n0)Descendente Z-A\n1)Ascendente A-Z");
			utn_pedirNumeroEntero(&orden, "\nIngrese como quiere ordenar las nacionladidades : ", "\nError", 1, 0);
			//	    	  utn_getNumero(&orden, "\n\nIngrese opcion como desea ordenar las nacionalidades:\n 0.Descendente Z-A \n 1.Ascendente. A -Z \nOpcion: ", "Error.", 0, 1,5);
			ll_sort(pArrayListJugador, jug_ordenarPorNacionalidad, orden);
			controller_listarJugadores(pArrayListJugador);
			//  printf("Ordenamiento ok\n");
			break;
		case 'B':
			controller_ordenarSelecciones(pArrayListSeleccion);
			controller_listarSelecciones(pArrayListSeleccion);
			break;
		case 'C':
			printf("\n0)Descendente\n1)Ascendente");
			utn_pedirNumeroEntero(&orden, "\nIngrese como quiere ordenar las edades : ", "\nError", 1, 0);
			//	    	  utn_getNumero(&orden, "\nIngrese opcion como desea ordenar las edades:\n0.Descendente \n1.Ascendente. \nOpcion: ", "Error.", 0, 1,5);
			ll_sort(pArrayListJugador, jug_ordenarPorEdad, orden);
			controller_listarJugadores(pArrayListJugador);
			//  printf("Ordenamiento ok\n");
			break;
		case 'D':
			printf("\n0)Descendente Z_A\n1)Ascendente A_Z");
			utn_pedirNumeroEntero(&orden, "\nIngrese como quiere ordenar los nombres : ", "\nError", 1, 0);
			//	    	  utn_getNumero(&orden, "\n\nIngrese opcion como desea ordenar los nombres:\n0.Descendente Z-A \n1.Ascendente A -Z. \nOpcion: ", "Error.", 0, 1,5);
			ll_sort(pArrayListJugador, jug_ordenarPorNombre, orden);
			controller_listarJugadores(pArrayListJugador);
			// printf("Ordenamiento ok\n");
			break;
		default : printf("\nError, Opcion invalida, tiene que ingresar mayusculas de A-E");
		}
	}while(rta < 'E');
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	// return 1;
	int retorno = -1;
	int i;
	FILE* fpArchivo;
	int auxId;
	char auxNombreC[30];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;
	Jugador* auxJugador;

	if(pArrayListJugador != NULL && path != NULL)
	{
		fpArchivo = fopen(path,"w");
		if(fpArchivo != NULL)
		{
			retorno = 0;
			for(i = 0; i < ll_len(pArrayListJugador); i++)
			{
				auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
				if(auxJugador != NULL)
				{
					if(!jug_getId(auxJugador,&auxId) &&
							!jug_getNombreCompleto(auxJugador,auxNombreC) &&
							!jug_getEdad(auxJugador,&auxEdad) &&
							!jug_getPosicion(auxJugador,auxPosicion) &&
							!jug_getNacionalidad(auxJugador,auxNacionalidad) &&
							!jug_getSIdSeleccion(auxJugador,&auxIdSeleccion))
					{
						fprintf(fpArchivo,"%d,%s,%d,%s,%s%d\n",
								auxId,
								auxNombreC,
								auxEdad,
								auxPosicion,
								auxNacionalidad,
								auxIdSeleccion);
					}
				}
			}
			fclose(fpArchivo);
			printf("El Archivo de jugadores fue guardado correctamente\n");
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el ARCHIVO BINARIO
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	// return 1;
	int retorno = -1;
	FILE* auxP;
	Jugador* auxJugador;

	if(pArrayListJugador != NULL)
	{
		auxP = fopen(path,"wb");//guardar
		if(auxP != NULL)
		{
			for(int i = 0;i<ll_len(pArrayListJugador);i++)
			{
				auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
				if(auxJugador != NULL)
				{
					if(fwrite(auxJugador,sizeof(Jugador),1, auxP) != 1)
					{
						retorno = 0;
						printf(" Archivo cargado exitosamente\n");
						break;
					}
					retorno = 1;
				}
			}
		}
		else
		{
			printf("No se pudo escribir en el archivo");
		}
		fclose(auxP);
	}

	return retorno;
}
//==============______{{{{����������----------------------------
/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 1;
	int flag=0;
	FILE *pArchivo= fopen(path, "r");
	if(pArchivo != NULL )
	{
		//	if(pArchivo != NULL && parser_SeleccionFromText(pArchivo,pArrayListSeleccion)==0)
		flag=ll_isEmpty(pArrayListSeleccion);
		if(flag == 1)
		{
			retorno = parser_SeleccionFromText(pArchivo,pArrayListSeleccion);
			fclose(pArchivo);
		}
		//printf("Archivo de selecciones cargado Exitosamente\n");
		else{
			printf("El archivo no puede abrirse\n");
		}
	}
	/*	else{
						printf("El archivo no puede abrirse\n");
					}*/

	//fclose(pArchivo);
	return retorno;
}

/*int controller_convocadosAlta(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
   // return 1;
	int retorno = -1;
	int opcion;
	int opcionN;
	int idJugador;
	int indice;
	int indiceS;
	int idMax;
	int seleccionElegida;
	int idSeleccion;
	int obtenerId;
	int idJugador;
int seleccionAElegir;
//int indiceS;
int obtenerIdS;

	Jugador* jugadorParaConvocar;*/

/*
	 Yo lo que hice fue crear una funci�n nueva para Convocar, le pide el id
	 del jugador luego el id de la selecci�n, v�lida que sean del mismo pa�s
	 (o tambi�n pod�s no validarlo), llamas a controller editar selecci�n y
	 dentro aumentas la cant de convocados de la selecci�n que escogi� antes
	 (y adem�s ver qu� la cant no sea mayor a 22 sino no puede convocar)
	Lo que si tuve que cambiar el prototipo porque otra manera no encontr�
	Y si todas las validaciones pasan al jugador le asignas el id de selecci�n
 */
/*if(pArrayListJugador != NULL){
		retorno =0;
		obtenerID(&idMax);
		controller_listarJugadores(pArrayListJugador);
	//	utn_getNumero(&idABuscar,"\nIngrese el id del jugador que quiere modificar: \n","ERROR!!!\n",0,ll_len(pArrayListJugador),10);
		utn_getNumero(&idJugador,"\nIngrese el id del jugador que quiere convocar: \n","ERROR!!!\n",0,(idMax-1),10);
		indice = buscarJugadorId(&idJugador, pArrayListJugador);

		jugadorParaConvocar = (Jugador*)ll_get(pArrayListJugador,indice);
		jug_getID(jugadorParaConvocar,&obtenerId);//agruegue desp q dio 0
if(jug_getId())
		encabezado();
		jug_imprimirUnJugador(jugadorParaConvocar);
		utn_getNumero(&idJugador,"\nIngrese el id se seleccion: \n","ERROR!!!\n",0,(idMax-1),10);
		if(indice == -1)
		{
			printf("ERROR. El id ingresado no existe\n");
		}
		do{
			if(!utn_getNumero(&opcion,
					"\nEn que seleccion quiere convocarlo? \n"

					,"Opcion incorrecta debe ingresar opcion 1 - 4\n"
					, 1, 32, 10))
			{
				indice = buscarJugadorId(&idJugador,pArrayListSeleccion);

				seleccionElegida = (Seleccion*)ll_get(pArrayListSeleccion,indiceS);
						selec_getId(seleccionElegida,&obtenerIdS);//agruegue desp q dio 0
						//selec_getID(jugadorAmodificar,&obtenerId);//agruegue desp q dio 0
						encabezadoSelecciones();
						imprimirUnaSeleccion(seleccionElegida);
						encabezado();
						jug_imprimirUnJugador(jugadorParaConvocar);
						idSeleccion=jug_getSIdSeleccion(seleccionAElegir,&obtenerIdS);

						if(jugadorParaConvocar == 0 &&  idSeleccion >0)
						{

						}



			}
		}while(opcion != 5);}
	return retorno;
}*/

int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;

	int idABuscar;
	int indice;
	int cantidadConvocados=0;
	//int auxConvocados;
	Seleccion* seleccionAmodificar;
	int aux;

	if(pArrayListSeleccion != NULL){
		retorno =0;
		controller_listarSelecciones(pArrayListSeleccion);
		utn_pedirNumeroEntero(&idABuscar, "\nIngrese el ID de la seccion que quiere asignar : ", "\nError", ll_len(pArrayListSeleccion), 0);
		//			utn_getNumero(&idABuscar,"Ingrese el id de seleccion que quiere asignar: \n","ERROR!!!\n",0,ll_len(pArrayListSeleccion),10);
		indice = buscarJugadorId(&idABuscar, pArrayListSeleccion);
		seleccionAmodificar = (Seleccion*)ll_get(pArrayListSeleccion,indice);
		encabezadoSelecciones();
		selec_imprimirUnaSeleccion(seleccionAmodificar);
		utn_pedirNumeroEntero(&aux, "\nIngrese el ID de la confederacion que quiera modificar : ", "\nError", ll_len(pArrayListSeleccion), 0);
		//			utn_getNumero(&aux,"Ingrese el id de confederacion que quiere modificar: \n","ERROR!!!\n",0,ll_len(pArrayListSeleccion),10);
		selec_setConvocados(seleccionAmodificar,aux);

		if(indice == -1)
		{
			printf("ERROR. El id ingresado no existe\n");
		}
		else if(cantidadConvocados <= 22)
		{
			cantidadConvocados++;
			printf("cant convoc %d",cantidadConvocados);
		}
		else
		{
			cantidadConvocados--;
		}
	}

	return retorno;
}
/*int retorno = -1;
	int opcion;
	int idABuscar;
	int indice;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;
	Seleccion* seleccionAmodificar;

	if(pArrayListSeleccion != NULL){
		retorno =0;
		controller_listarSelecciones(pArrayListSeleccion);
		utn_getNumero(&idABuscar,"Ingrese el id de confederacion que quiere modificar: \n","ERROR!!!\n",0,ll_len(pArrayListSeleccion),10);
		indice = buscarJugadorId(&idABuscar, pArrayListSeleccion);
		seleccionAmodificar = (Seleccion*)ll_get(pArrayListSeleccion,indice);
		encabezadoSelecciones();
		selec_imprimirUnaSeleccion(seleccionAmodificar);
		if(indice == -1)
		{
			printf("ERROR. El id ingresado no existe\n");
		}
		do{
			if(!utn_getNumero(&opcion,*/
/*"\n_____________________________________________________\n"
					"| De los 3 DATOS cual desea modificar:               |\n"
					"|____________________________________________________|\n"
					"| 1.Pais                                             |\n"
					"|____________________________________________________|\n"
					"| 2.Confederacion                                    |\n"*/
/*	"|____________________________________________________|\n"
					"| 3.Convocados                                       |\n"
					"|____________________________________________________|\n"
					"| 4.Salir                                            |\n"
					"|____________________________________________________|\n"
					,"Opcion incorrecta debe ingresar opcion 1 - 4\n"
					, 1, 4, 5))
			{
				switch(opcion){
				case 1:
					if(!utn_descripcion(auxPais,30,"Ingrese pais","ERROR!\n",10))
					{
						strcpy(seleccionAmodificar->pais,auxPais);
						encabezado();
						selec_imprimirUnaSeleccion(seleccionAmodificar);
						printf("Se ha modificado el pais con exito\n");
					}
					break;
				case 2:
					if(!utn_descripcion(auxConfederacion,30,"Ingrese confederacion","ERROR\n",10))
					{
						strcpy(seleccionAmodificar->confederacion,auxConfederacion);
						encabezado();
						selec_imprimirUnaSeleccion(seleccionAmodificar);
						printf("Se ha modificado confederacion con exito\n");
					}
					break;
				case 3:
					if(!utn_getNumero(&auxConvocados,"Ingrese edad 19-33","ERROR\n",0,33,10)){
						selec_setConvocados(seleccionAmodificar,auxConvocados);
						encabezado();
						selec_imprimirUnaSeleccion(seleccionAmodificar);
						printf("Se han modificado convocado con exito\n");
					}
					break;
				}
			}
		}while(opcion != 4);}*/

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	//return 1;
	int retorno = -1;
	int i;
	FILE* fpArchivo;
	int auxId;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;
	Seleccion* auxSelecion;

	if(pArrayListSeleccion != NULL && path != NULL)
	{
		fpArchivo = fopen(path,"w");
		if(fpArchivo != NULL)
		{
			retorno = 0;
			for(i = 0; i < ll_len(pArrayListSeleccion); i++)
			{
				auxSelecion = (Seleccion*)ll_get(pArrayListSeleccion,i);
				if(auxSelecion != NULL)
				{
					if(!selec_getId(auxSelecion,&auxId) &&
							!selec_getPais(auxSelecion,auxPais) &&
							!selec_getConfederacion(auxSelecion,auxConfederacion) &&
							!selec_getConvocados(auxSelecion,&auxConvocados))
					{
						fprintf(fpArchivo,"%d,%s,%s,%d\n",
								auxId,
								auxPais,
								auxConfederacion,
								auxConvocados);
					}
				}
			}
			fclose(fpArchivo);
			printf("El Archivo de Seleccion fue guardado correctamente\n");
		}
	}
	return retorno;
}

