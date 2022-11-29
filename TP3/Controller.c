#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "parser.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "utn.h"
/**int guardarComoTexto_maxID(FILE* pFile, LinkedList* pArrayListJugador,int* maxID)
 *
 *objetivo : guarda en modo texto el maximo ID
 *
 *parametro path char*
 *parametro pArrayListJugador LinkedList*
 *
 *return : retorna 0
 */
int controller_guardarComoTexto_maximoId(FILE* pFile, LinkedList* pArrayListJugador,int* maxID)
{
	Jugador* jugador;
	int id;
	int retorno = -1;
	int maxId;
	int bandera = 0;

	if(pFile != NULL && pArrayListJugador != NULL && maxID != NULL)
	{

		for(int i=0; i< ll_len(pArrayListJugador); i++)
		{
			jugador = ll_get(pArrayListJugador,i);
			if(jugador_obtenerElmaximoId(jugador,&id) == 0)
			{
				if(bandera == 0 || id > maxId)
				{
					maxId = id;
					bandera=1;
					retorno = 0;
				}
			}
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

	if(pFile !=NULL && controller_guardarComoTexto_maximoId(pFile,pArrayListJugador,&maxID))
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
	int retornaParser = -1;
	int flag=0;
	FILE *pArchivo; //= fopen(path,"r");
	FILE *pArchivoId; //= fopen("elUltimoId.txt","w");
	pArchivo=fopen(path,"r");
	pArchivoId=fopen("idAutoIncremental.txt","w");
	if(pArchivo != NULL && pArchivoId != NULL)
	{
		flag = ll_isEmpty(pArrayListJugador);
		if(flag == 1)
		{
			retornaParser = parser_JugadorFromText(pArchivo,pArrayListJugador);
			if(retornaParser == 0)
			{
				fclose(pArchivo);
				retorno = 0;
			}
		}else{
			retorno= 2;
		}
	}
	if(controller_guardarComoTextoMaxID(pArchivoId,"maximoId.txt",pArrayListJugador))
	{
		fclose(pArchivoId);
	}
	return retorno;

}
/**
 * \brief Carga los datos de los jugadores desde el archivo generado en MODO BINARIO
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
	FILE *punteroArchivoRB = fopen(path,"rb");
	FILE *punteroArchivoId = fopen("archivoId.bin","w");


	if(path != NULL && pArrayListJugador != NULL)
	{
		if(punteroArchivoRB != NULL && parser_JugadorFromBinary(punteroArchivoRB,pArrayListJugador)==0)
		{
			printf("\n***************************************");
			printf("\nArchivo binario cargado exitosamente");
			printf("\n***************************************");
			retorno = 0;
		}
		if(controller_guardarComoTextoMaxID(punteroArchivoId,"maxid.txt",pArrayListJugador))
		{
			fclose(punteroArchivoId);
		}else{
			printf("\n***************************************");
			printf("\nError , El archivo no se pudo abrir...");
			printf("\n***************************************");
		}
	}
	fclose(punteroArchivoRB);
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
	pFile = fopen("idAutoincremental.txt","r");
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
	int proximoId =++id;
	int retorno = -1;
	FILE* pFile;
	pFile = fopen("idAutoIncremental.txt","w");
	if(pFile!=NULL)
	{
		fprintf(pFile,"%d\n",proximoId);
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
int controller_agregarJugador(LinkedList* pArrayListJugador , Seleccion* listaSeleccion)//SI
{
	int retorno = -1;
	int auxId;
	char auxNombreCompleto[NOMBRE_LEN];
	int auxEdad;
	int auxOpcionPosicion;
	int auxOpcionNacionalidad;
	int idSeleccion;
	char auxPosicion[POSICION_LEN];
	char posicionHarcodeo[12][POSICION_LEN]={"Portero","Defensa central","Lateral izquierdo","ateral derecho","Pivote","Mediocentro",
			"Mediocentro ofensivo","Extremo izquierdo",
			"Extremo derecho","Mediapunta","Delantero centro","Interior derecho"};
	char nacionalidad[NACIONALIDAD_LEN];
	char nacionalidadHarcodeo[32][NACIONALIDAD_LEN]={"Aleman","Saudi","Argentino","Belga","Australiano","Brasilero","Camerun","Canadiense","Surcoreano","Costarricense",
			"Croata","Danes","Ecuatoriano","Espanol","Estado Unidense","Frances","Gales","Ghanes","Holandes","Ingles",
			"Irani","Japones","Marroqui","Mexicano","Polaco","Portugues","Qatari","Senegales","Serbio","Suizo","Tunecino","Uruguayo"};
	int banderaNombreCompleto = -1;
	int banderaEdad = -1;
	int banderaPosicion = -1;
	int banderaNacionalidad = -1;
	int opcionAgregarOtroJugador = -1;
	int bandera_opcionAgregarOtroJugador = -1;


	Jugador* nuevoJugador = jug_new();

	if(pArrayListJugador != NULL && nuevoJugador != NULL && listaSeleccion != NULL)
	{

		do {
			obtenerID(&auxId);
			printf("\n****************************************");
			printf("\nEl ID comenzara con el numero : %d\n",auxId);
			printf("\n****************************************");
			do {

				banderaNombreCompleto = utn_pedirNombreConEspacio(auxNombreCompleto, NOMBRE_LEN, "\nIngrese nombre de jugador: ", "\nError");
			} while (banderaNombreCompleto == -1);

			do {
				banderaEdad = utn_pedirNumeroEntero(&auxEdad, "\nIngrese edad de jugador (entre 19 y 30): ", "\nError", 30, 19);
			} while (banderaEdad == -1);

			do {
				jugador_subMenuListadoPosiciones();
				banderaPosicion = utn_pedirNumeroEntero(&auxOpcionPosicion, "\nIngrese una posicion : ", "\nError", 12, 1);
			} while (banderaPosicion == -1);

			strcpy(auxPosicion,posicionHarcodeo[auxOpcionPosicion-1]);

			do {

				jugador_subMenuListadoNacionalidades();
				banderaNacionalidad = utn_pedirNumeroEntero(&auxOpcionNacionalidad, "\nIngrese una opcion de nacionalidad : ", "\nError", 32, 1);
			} while (banderaNacionalidad == -1);
			strcpy(nacionalidad,nacionalidadHarcodeo[auxOpcionNacionalidad-1]);

			//	utn_getNumero(&idSeleccion,"Ingrese 0 como  id seleccion de jugador: ","ERROR!!!\n",0,32,10);
			//	utn_pedirNumeroEntero(idSeleccion, "", "\nerror", 32, 10);
			idSeleccion = 0;

			if(jug_setID(nuevoJugador,&auxId)== -1||
				jug_setNombreCompleto(nuevoJugador,auxNombreCompleto)==-1 ||
				jug_setEdad(nuevoJugador,auxEdad) ==-1||
				jug_setPosicion(nuevoJugador,auxPosicion)==-1||
				jug_setNacionalidad(nuevoJugador,nacionalidad) ==-1||
				jug_setIdSeleccion(nuevoJugador,idSeleccion))
			{
				jug_delete(nuevoJugador);
			}else{
				retorno =0;
				ll_add(pArrayListJugador, nuevoJugador);
				actualizarIdok(auxId);
				jugador_encabezado();
				jugador_imprimirUnJugador(nuevoJugador);
			}

			do {
				bandera_opcionAgregarOtroJugador = utn_pedirNumeroEntero(&opcionAgregarOtroJugador, "\nQuiere agregar otro jugador (1 : SI | 2 : NO) ??:", "\nError", 2, 1);

			} while (bandera_opcionAgregarOtroJugador == -1);

		} while (opcionAgregarOtroJugador == 1);
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
		jugador_encabezado();
		retorno = 0;
		for(i = 0; i < ll_len(pArrayListJugador); i++)
		{
			jugador = (Jugador*)ll_get(pArrayListJugador,i);
			jugador_imprimirUnJugador(jugador);
		}
	}
	printf("__________________________________________________________________________________\n");
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
	char auxNombre[NOMBRE_LEN];
	int auxEdad;
	char auxPosicion[POSICION_LEN];
	char auxPosicionHarcodeo[12][POSICION_LEN]={"Portero","Defensa central","Lateral izquierdo","Lateral derecho",
			"Pivote","Mediocentro","Mediocentro ofensivo","Extremo izquierdo",
			"Extremo derecho","Mediapunta","Delantero centro","Interior derecho"};

	char auxNacionalidad[NACIONALIDAD_LEN];
	char auxNacionalidadH[32][NACIONALIDAD_LEN]={"Aleman","Saudi","Argentino","Belga","Australiano","Brasilero","Camerun","Canadiense","Surcoreano","Costarricense",
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

		jugador_encabezado();
		jugador_imprimirUnJugador(jugadorAmodificar);
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

						if(utn_pedirNombreConEspacio(auxNombre, NOMBRE_LEN, "\nIngrese el Nuevo nombre del jugador : ", "\nError") == 0)
						{
							jug_setNombreCompleto(jugadorAmodificar,auxNombre);
							jugador_encabezado();
							jugador_imprimirUnJugador(jugadorAmodificar);
							printf("\nSe ha modificado el nombre con exito\n");
						}
						break;
					case 2:

						if(utn_pedirNumeroEntero(&auxEdad, "\nIngrese la Nueva edad (entre 18 y 32)", "\nError", 32, 18) == 0)
						{
							jug_setEdad(jugadorAmodificar,auxEdad);
							jugador_encabezado();
							jugador_imprimirUnJugador(jugadorAmodificar);
							printf("\nSe han modificado edad con exito\n");
						}
						break;
					case 3:
						jugador_subMenuListadoPosiciones();
						utn_pedirNumeroEntero(&opcion, "\nIngrese Nueva posicion del Jugador :", "\nError", 12, 1);
						//					get_Int("\nIngrese Opcion de posicion: ",&opcion,1,12);
						strcpy(auxPosicion,auxPosicionHarcodeo[opcion-1]);
						jug_setPosicion(jugadorAmodificar,auxPosicion);
						jugador_encabezado();
						jugador_imprimirUnJugador(jugadorAmodificar);
						printf("\nSe ha modificado posicon con exito\n");
						break;
					case 4:
						jugador_subMenuListadoNacionalidades();
						utn_pedirNumeroEntero(&opcionNacionalidad, "\nIngrese Nueva opcion de nacionalidad : ", "\nError", 32, 1);
						//					get_Int("Ingrese Opcion de nacionalidad: ",&opcionN,1,32);
						strcpy(auxNacionalidad,auxNacionalidadH[opcionNacionalidad-1]);
						jug_setNacionalidad(jugadorAmodificar,auxNacionalidad);
						jugador_encabezado();
						jugador_imprimirUnJugador(jugadorAmodificar);
						printf("\nSe ha modificado nacionalidad con exito\n");
						break;
					default : printf("\nOpcion Incorrecta ");
				}
			}
		}while(opcion != 5);
	}
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
				jugador_encabezado();
				jugador_imprimirUnJugador(jugadorDarDeBaja);
			}
			if(indice == -1)//hcaer do
			{
				printf("ERROR. El id ingresado no existe\n");
			}else if(utn_pedirLetra(&rta, "\nEsta seguro/a que quiera dar de baja este ID ?\n s-n (minusculas) : ", "\nError") == 0 && rta == 's')
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
//	int orden = 1;
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
		printf("__________________________________________________________________________________\n");
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
int controller_imprimirJugadoresConvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, int referenciaDeUso)
{
	int retorno=-1;
	int auxId;
	char auxNombreCompleto[200];
	char auxPosicion[100];
	char nacionalidad[100];
	int auxEdad;
	int auxIdSeleccion;
	char auxDescripcionSeleccion[30];
	//*referenciaDeUso=flagRefUno;
	/*
	 * referenciaDeUso==1 / SE MUESTRAN TODOS LOS JUGADORES.
	 * referenciaDeUso==2 / SE MUESTRAN LOS JUGADORES CONVODADOS.
	 * referenciaDeUso==3 / SE MUESTRAN LOS JUGADORES NO CONVOCADOS.
	 */
	Jugador* pJugAux;

	int anchoColumnaId = -6;
	int anchoColumnaNombre = -25;
	int anchoColumnaEdad = -10;
	int anchoColumnaPosicion = -25;
	int anchoColumnaNacionalidad = -20;
	int anchoColumnaIdSeleccion = -15;
	int anchoColumnaNoConvocado = -20;
	//index>-1 para mostrar el indice 0
	if(pArrayListJugador!=NULL && pArrayListSeleccion != NULL)
	{
//		encabezadoSelecciones();
		jugador_encabezado();

		for(int i=0;i<ll_len(pArrayListJugador);i++)
		{
			pJugAux = ll_get(pArrayListJugador, i);
			if(jug_getId(pJugAux, &auxId)==0 &&
				jug_getNombreCompleto(pJugAux, auxNombreCompleto)==0 &&
				jug_getPosicion(pJugAux, auxPosicion) == 0 &&
				jug_getNacionalidad(pJugAux, nacionalidad)== 0 &&
				jug_getEdad(pJugAux,&auxEdad)== 0 &&
				jug_getSIdSeleccion(pJugAux, &auxIdSeleccion)==0)
			{
				if(auxIdSeleccion > 0 && (referenciaDeUso==2 || referenciaDeUso==1))
				{
					retorno=0;
					//printf("ENTRE AL IF isSeleccion>0\n");
					selec_AsignarDescripcionPais(pArrayListSeleccion, pArrayListJugador, i, auxDescripcionSeleccion);
					printf("|%*d|%*s|%*d|%*s|%*s|%*d|%*s|\n",
							anchoColumnaId,auxId,anchoColumnaNombre,auxNombreCompleto,anchoColumnaEdad,auxEdad,
							anchoColumnaPosicion,auxPosicion,anchoColumnaNacionalidad,nacionalidad,
							anchoColumnaIdSeleccion,auxIdSeleccion,anchoColumnaNoConvocado,auxDescripcionSeleccion);
//					printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|%*s|\n",
//												-4,auxId,-40,auxnombreCompleto,-3,auxEdad,-25,auxPosicion,-18,nacionalidad,-5,auxIdSeleccion,-20,auxDescripcionSeleccion);
				}else{
					if(auxIdSeleccion == 0 && (referenciaDeUso == 3 || referenciaDeUso == 1))
					{
						retorno=0;
//						printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|%*s|\n",
//							-4,auxId,-40,auxnombreCompleto,-3,auxEdad,-25,auxPosicion,-18,nacionalidad,-5,auxIdSeleccion,-20,"NO CONVOCADO");

						printf("|%*d|%*s|%*d|%*s|%*s|%*d|%*s|\n",
									anchoColumnaId,auxId,anchoColumnaNombre,auxNombreCompleto,anchoColumnaEdad,auxEdad,
									anchoColumnaPosicion,auxPosicion,anchoColumnaNacionalidad,nacionalidad,anchoColumnaIdSeleccion,
									auxIdSeleccion,anchoColumnaNoConvocado,"NO CONVOCADO");
					}
				}
			}
		}
		printf("+================================================================================================================================+\n");
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
	int respuestaB = -1;

	do {
		printf("\n<<<<<<<<<<<<<<<<<<<<_SELECCIONES POR CONFEDERACION_>>>>>>>>>>>>>>>>>>>>\n");
		printf("\n0) Descendente Z-A\n1)Ascendente A-Z");
		respuestaB = utn_pedirNumeroEntero(&orden, "\nIngrese opcion de como quiere ordenar : ", "\nError", 1, 0);
	} while (respuestaB == -1);
	//	utn_getNumero(&orden, "\n\nIngrese opcion como desea ordenar:\n0.Descendente Z-A \n1.Ascendente. A-Z \nOpcion: ", "Error.", 0, 1,5);
	ll_sort(pArrayListSeleccion,selec_ordenarPorConfederacion,orden);
	retorno =0;

	return retorno;
}

int controller_listarJugYSelec(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int opcion;
	int retorno =-1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL )
	{
		printf("\n<<<<<<<<<<<<<<<<<<<<_LISTADO_>>>>>>>>>>>>>>>>>>>>\n");
		printf("\n1)TODOS LOS JUGADORES\n2)TODAS LAS SELECCIONES\n3)JUGADORES CONVOCADOS\n4)SALIR");
		printf("\n_________________________________________________\n");
		if(utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion : ", "\nError", 4, 1)== 0)
		{
			switch(opcion)
			{
			case 1:
				if(controller_listarJugadores(pArrayListJugador) == 0)
				{
					retorno = 0;
				}
					break;
			case 2:
				ll_sort(pArrayListSeleccion, selec_ordenarPorId, 1);
				if(controller_listarSelecciones(pArrayListSeleccion) == 0)
				{
					retorno = 0;
				}
				break;
			case 3://	hacer lista de convocados
				if(controller_imprimirJugadoresConvocados(pArrayListJugador, pArrayListSeleccion, 2) == 0)
				{
					retorno = 0;
				}
				//  controller_listarJugadores(pArrayListJugador);
				break;
			default : printf("\nOpcion incorrectar");
			}
		}
	}
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
	int respuestaA = -1;
	int respuestaC = -1;
	int respuestaD = -1;

	do{
		printf("\n<<<<<<<<<<<<<<<<<<<<_ORDENAR Y LISTAR_>>>>>>>>>>>>>>>>>>>>\n");
		printf("\nA)JUGADORES POR NACIONALIDAD\nB)SELECCIONES POR CONFEDERACION\nC)JUGADORES POR EDAD\nD)JUGADORES POR NOMBRE\nE)SALIR");
		printf("\nADVERTANCIA , tiene que ingresar con MAYUSCULAS ");
		utn_pedirLetra(&rta, "\nIngrese Letra : ", "\nError");

		switch(rta)
		{
		case 'A':

			do {
				printf("\n<<<<<<<<<<<<<<_JUGADORES POR NACIONALIDAD_>>>>>>>>>>>>>>>>\n");
				printf("\n0)Descendente Z-A\n1)Ascendente A-Z");
				respuestaA = utn_pedirNumeroEntero(&orden, "\nIngrese como quiere ordenar las nacionladidades : ", "\nError", 1, 0);
			} while (respuestaA == -1);
			ll_sort(pArrayListJugador, jugador_ordenarPorNacionalidad, orden);
			controller_listarJugadores(pArrayListJugador);
			break;
		case 'B':
			controller_ordenarSelecciones(pArrayListSeleccion);
			controller_listarSelecciones(pArrayListSeleccion);
			break;
		case 'C':
			do {
				printf("\n<<<<<<<<<<<<<<<_JUGADORES POR EDAD_>>>>>>>>>>>>>>>>>\n");
				printf("\n0)Descendente\n1)Ascendente");
				respuestaC = utn_pedirNumeroEntero(&orden, "\nIngrese como quiere ordenar las edades : ", "\nError", 1, 0);
			} while (respuestaC == -1);
			ll_sort(pArrayListJugador, jugador_ordenarPorEdad, orden);
			controller_listarJugadores(pArrayListJugador);
			break;
		case 'D':
			do {
				printf("\n<<<<<<<<<<<<<<<_JUGADORES POR NOMBRE_>>>>>>>>>>>>>>>>>>\n");
				printf("\n0)Descendente Z_A\n1)Ascendente A_Z");
				respuestaD = utn_pedirNumeroEntero(&orden, "\nIngrese como quiere ordenar los nombres : ", "\nError", 1, 0);
			} while (respuestaD == -1);
			ll_sort(pArrayListJugador, jugador_ordenarPorNombre, orden);
			controller_listarJugadores(pArrayListJugador);
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



/// \fn int controller_editarSeleccion(LinkedList*, LinkedList*)
/// \brief Se muestra menu, el usuario elige segun desee operar (validacion), se llama a jug_convocar o a jug_Quitar_Convocado segun corresponda.
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_editarSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int opcion;
	Seleccion* pSeleccion;
	int selecConvocados;
	int bandera=0;
	int respuestaOpcion = -1;
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		do {
			printf("\n<<<<<<<<<<<<<<<<<<<<_CONVOCAR JUGADORES_>>>>>>>>>>>>>>>>>>>>\n");
			printf("\n1)CONVOCAR JUGADOR\n2)QUITAR DE LA SELECCION");
			respuestaOpcion = utn_pedirNumeroEntero(&opcion, "\nIngrese una opcion : ", "\nError", 2, 1);
		} while (respuestaOpcion == -1);
		switch(opcion)
		{
		case 1:
			if(jugador_paraConvocar(pArrayListJugador, pArrayListSeleccion)==0)
			{
				retorno=0;
			}
		break;
		case 2:
			for(int i=0;i<ll_len(pArrayListSeleccion);i++)
			{
				pSeleccion=ll_get(pArrayListSeleccion, i);

				if(selec_getConvocados(pSeleccion, &selecConvocados)==0)
				{
					if(selecConvocados!=0)
					{
						if(jugador_sacarConvocado(pArrayListJugador, pArrayListSeleccion)==0)
						{
							retorno=0;
							bandera=1;
							break;
						}
					}
				}
			}
			if(bandera==0)
			{
				printf("ERROR, No se pueden quitar convocados si aun no hay ninguno.\n");
			}
		break;
		}
	}
	return retorno;
}

/// \fn int jug_Quitar_Convocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
/// \brief Previa verificacion de la existencia de al menos 1 convocado, se listan jugadores convocados (jug_imprimirJugadores) , se
/// solicita id (jug_Solicitar_Id), en caso que el jugador se encuentre convocado se pondra en 0 al campo de idSeleccion y se
/// restara a la seleccion que convocante un convocado.
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jugador_sacarConvocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int indice;
	int indiceSeleccion;
	Jugador* pJugador;
	int jugIdSeleccion;
	char nombreCompleto[100];
	int selecConvocados;
	Seleccion* pSeleccion;
	int bandera=0;
	char jug_NombreCompleto[100];
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		//jug_Listar_Convocados(pArrayListJugador, pArrayListSeleccion, 2);
		jugador_imprimirListaJugadores(pArrayListJugador, pArrayListSeleccion, 2);
		do
		{
			jugador_pedirId(pArrayListJugador, &indice, "Ingrese ID del jugador que desar quitar de la convocatoria.\n");

			pJugador=ll_get(pArrayListJugador, indice);
			if(jug_getSIdSeleccion(pJugador, &jugIdSeleccion)==0 && jug_getNombreCompleto(pJugador, nombreCompleto)==0)
			{
				if(jugIdSeleccion!=0)
				{
					if(selec_buscarPorId(pArrayListSeleccion, jugIdSeleccion, &indiceSeleccion)==0)
					{
						pSeleccion=ll_get(pArrayListSeleccion, indiceSeleccion);
						if(selec_getConvocados(pSeleccion, &selecConvocados)==0)
						{
							//printf("CANTIDAD DE CONVOCADOS ANTES DE BAJAR %d\n",selecConvocados);
							//1 CONVOCADO MENOS - LUEGO SETEO ESTE CAMBIO
							selecConvocados=selecConvocados-1;
							//(*(seleccion)).convocados=(*(seleccion)).convocados-1

							//PONGO EN 0 AL ID DE SELECCION DEL JUGADOR
							//(*(pJugador)).idSeleccion=0;
							jugIdSeleccion=0;
							//SETEO NUEVOS VALORES PARA EL JUGADOR (idSeleccion) y para la seleccion 1 convocado menos
							if(jug_setIdSeleccion(pJugador, jugIdSeleccion)==0 && selec_setConvocados(pSeleccion, selecConvocados)==0)
							{
								if(jug_getNombreCompleto(pJugador, jug_NombreCompleto)==0)
								{
									retorno=0;
									bandera=1;
									printf("<<<<<<<<<< El jugador : %s fue bajado de la convocatoria. >>>>>>>>>>\n",jug_NombreCompleto);
								}
							}else{
								printf("ERROR al setear el id de seleccion del jugador en 0 / al setear la cantidad de convocados nueva de la seleccion.\n");
							}
						}else{
							printf("ERROR al buscar el indice por desde el ID.\n");
						}

					}else{
						printf("\nNO se pudo encontrar ese ID ");
					}

				}else{
					printf("ERROR, El id ingresado pertenece a un jugador que NO esta convocado por ninguna seleccion.\n");
				}

			}else{
				printf("ERROR al intentar acceder al id de la seleccion o al nombre del jugador.\n");
			}

		}while(bandera==0);
	}
	return retorno;
}
