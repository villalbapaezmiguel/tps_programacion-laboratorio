#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Seleccion.h"
#include "Jugador.h"
#include "utn.h"
//****tp3 q si
int main()
{

	 //solo limpio p subir a gitd aca p arriba volver a traer al parcial
	setbuf(stdout,NULL);
    int opcion = 0;
    int banderaCargaArchivo=0;
    int banderaGuardarArchivo=-1;
	int respuestaSalir = -1;
	int auxSalir =  2 ;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    printf("BIENVENIDOS\n\n");
    do{

    	printf("\n<<<<<<<<<<<<<<<<<<<<_MENU_>>>>>>>>>>>>>>>>>>>>\n");
    	printf("\n1).CARGA DE ARCHIVOS\n2)ALTA DE JUGADOR\n3)MODIFICACION DE JUGADOR\n4)BAJA DE JUGADOR\n5)LISTADOS\n6)CONVOCAR JUGADORES\n7)ORDENAR Y LISTAR\n8)GENERAR ARCHIVO BINARIO\n9)CARGAR ARCHIVO BINARIO\n10)GUARDAR ARCHIVOS .CSV\n11)SALIR");
    	if(utn_pedirNumeroEntero(&opcion,"\nIngrese Opcion : ", "\nerror", 11, 1) == 0){
        switch(opcion)
        {
        case 1:
            	if(banderaCargaArchivo == 0)
            	{
					if(!controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) &&
					!controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones))
					{
						printf("Archivo Jugadores cargado exitosamente\n");
						printf("Archivo selecciones cargado exitosamente\n");
						banderaCargaArchivo =1;
	//            		controller_editarSeleccion(listaSelecciones);
					}else{
						printf("No se pudo cargar los archivos \n");
					}

            	}else if(banderaCargaArchivo == 1)
            		{
            			printf("Los archivo ya fueron cargados\n");
            		}
                break;
            case 2:
            	if(banderaCargaArchivo == 1)
            	{
            		if(controller_agregarJugador(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0)
					   {
						printf("Alta de Jugador exitosa !!\n");
					   }else{
							printf("Error con Alta de Jugador \n");
						}
            	}else{
						printf("Tiene que cargar los archivos para poder dar de alta \n");
					}

            	break;
            case 3:
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0)
            	{
            		controller_editarJugador(listaJugadores);
            	}else{
            		printf("Tiene que tener jugadores cargados\n");
            	}
            	break;
            case 4:
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0 )
            	{
            		controller_removerJugador(listaJugadores);
            	}else{
            		printf("Tiene que tener jugadores cargados\n");
            	}
            	break;
            case 5:
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0)
            	{
            		if(controller_listarJugYSelec(listaJugadores,listaSelecciones) == -1)
            		{
            			printf("\nError al Listar");
            			printf("\nRecuerde que para acceder a JUGADORES CONVOCADOS primero tiene que tener por lo menos un convocado ");
            			printf("\nTiene que ir en : 6) CONVOCAR JUGADORES , luego ingresa 1)CONVOCAR JUGADOR");
            		}
            	}else{
            		printf("Tiene que tener jugadores  y selecciones cargados \n");
            	}
            	break;
            case 6://convocados
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0)
            	{
            		if( controller_editarSeleccion(listaJugadores, listaSelecciones) != 0)
            		{
            			printf("\nError al convocar jugador ");
            		}

            	}else{
            		printf("Tiene que tener jugadores  y selecciones cargados \n");
            	}
            	break;
            case 7:
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0)
            	{
            		controller_ordenarJugadores(listaJugadores,listaSelecciones);
            	}
            	else
            	{
            		printf("Tiene que tener jugadores y selecciones cargados \n");
            	}
            	break;
            case 8://guardar  GENERAR ARCHIVO BINARIO: Generar y guardar en binario una nueva lista
            	//que contenga los jugadores convocados de una confederaci�n ingresada por el usuario.

            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0)
            	{
            		controller_guardarJugadoresModoBinario("jugadores.bin",listaJugadores);
            		printf("Guardado modo binario con exito jugadores \n");
            	}else{
            		printf("Tiene que tener jugadores y selecciones cargados , para poder guardarlos \n");
            	}
            	break;
            case 9://cargar  9. CARGAR ARCHIVO BINARIO: Se deber� leer e imprimir los datos del archivo generado en el punto 8.
            	if(ll_isEmpty(listaJugadores ) == 0 && ll_isEmpty(listaSelecciones) == 0)
            	{
                	if(controller_cargarJugadoresDesdeBinario("jugadores.bin",listaJugadores) == 0)
                	{
                		printf("Archivo binario Jugadores cargado exitosamente\n");
                   	}else{
                		printf("No se pudo cargar el Archivo  binario Jugadores \n");
                	}
            	}else{
            		printf("Tiene que tener jugadores y selecciones cargados \n");
            	}
            	break;
            case 10:
            	//if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones))
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0)
            	{
            		if(controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores) == 0 ||
            		controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones) == 0)
            		{
            			printf("Guardado Archivos Jugadores y selecciones  exitosamente\n");
            			banderaGuardarArchivo = 0;
            		}

            	}else{
            		printf("Debe tener Jugadores y selecciones cargados \n");
            	}

            	break;
            case 11:
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0)
				{
            		if(banderaGuardarArchivo == -1)
            		{
						printf("Va a salir del programa sin guardar los cambios  realizados. Para guardar vuelva a la opcion 10 del menu \n");

            		}else{

            			do {
            				respuestaSalir = utn_pedirNumeroEntero(&auxSalir, "\nSeguro/a que quiere salir (1 : SI | 2 : NO) :", "\nError", 2, 1);

						} while (respuestaSalir == -1);

            		}
				}
            	break;
        }
    	}
    }while(auxSalir == 2);
    printf("\nSalio del programa exitosamente....\nMuchas gracias por usarlo <3");
    return 0;
}

