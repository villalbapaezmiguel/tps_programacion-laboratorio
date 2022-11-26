#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "utn.h"
//****tp3 q si
int main()
{

	 //solo limpio p subir a gitd aca p arriba volver a traer al parcial
	setbuf(stdout,NULL);
    int opcion = 0;
    char seguir = 'n';
    int flag=0;
    int flagGuardar=0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();


    do{
//    	printf("<<<<<<<<<<<<<<<_MENU_>>>>>>>>>>>>>>>\n");
//    	printf("\n1)CARGA DE ARCHIVOS\n2)ALTA DE JUGADOR\n3)MODIFICACION DE JUGADOR\n4)BAJA DE JUGADOR\n5)LISTADOS\n6)\n7)\n8)\n9)\n10)\n11)");

    	if(utn_pedirNumeroEntero(&opcion,
    			"||=�=�=�= __________  M E N U  __________ =�=�=�  ||\n"
				"||________________________________________________||\n"
				"||\t1.CARGA DE ARCHIVOS                       ||\n"
				"||\t2.ALTA DE JUGADOR                         ||\n"
				"||\t3.MODIFICACION DE JUGADOR                 ||\n"
				"||\t4.BAJA DE JUGADOR                         ||\n"
				"||\t5.LISTADOS                                ||\n"
				"||\t6.CONVOCAR JUGADORES                      ||\n"
				"||\t7.ORDENAR Y LISTAR                        ||\n"
				"||\t8.GENERAR ARCHIVO BINARIO                 ||\n"
				"||\t9.CARGAR ARCHIVO BINARIO                  ||\n"
				"||\t10.GUARDAR ARCHIVOS .CSV                  ||\n"
				"||\t11.SALIR                                  ||\n"
				"||________________________________________________||\n", "\nerror", 11, 1) == 0){
        switch(opcion)
        {
        case 1:
            	if(flag == 0)
            	{
					if(!controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) &&
					!controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones))
					{
						printf("Archivo Jugadores cargado exitosamente\n");
						printf("Archivo selecciones cargado exitosamente\n");
						flag =1;
	//            		controller_editarSeleccion(listaSelecciones);
					}else{
						printf("No se pudo cargar los archivos \n");
					}

            	}else if(flag == 1)
            		{
            			printf("Los archivo ya fueron cargados\n");
            		}
                break;
            case 2:
            	if(flag == 1)
            	{
            		if(!controller_agregarJugador(listaJugadores))
					   {
						printf("Alta de Jugador correcto \n");
					   }
            		             	else
            		             	{
            		             		printf("Error con Alta de Jugador \n");
            		             	}
            		                   }
            		             	else
            		             	{
            		             		printf("Debe cargar los archivos para poder dar de alta \n");
            		             	}


             	/*if(!ll_isEmpty(listaJugadores))
             	{
                   if(!controller_agregarJugador(listaJugadores))
                   {
             		printf("Alta de Jugador correcto \n");
                   }
             	else
             	{
             		printf("Error con Alta de Jugador \n");
             	}
                   }
             	else
             	{
             		printf("Debe cargar los archivos para poder dar de alta \n");
             	}*/
            	break;
            case 3:
            	if(!ll_isEmpty(listaJugadores))
            	{
            		controller_editarJugador(listaJugadores);
            	}
            	else
            	{
            		printf("Debe tener jugadores cargados\n");
            	}
            	break;
            case 4:
            	if(!ll_isEmpty(listaJugadores))
            	{
            		controller_removerJugador(listaJugadores);
            	}
            	else
            	{
            		printf("Debe tener jugadores cargados\n");
            	}
            	break;
            case 5:/*
            5. LISTADOS: A) TODOS LOS JUGADORES. B) TODAS LAS SELECCIONES. C) JUGADORES CONVOCADOS
            (�nicamente). Este proceso debe contar con men� propio permitiendo elegir qu� listado
             se desea ver.
            */
            	if(!ll_isEmpty(listaJugadores))
            	{
            		controller_listarJugYSelec(listaJugadores,listaSelecciones);//controller_listarJugadores(listaJugadores);
            	}
            	else
            	{
            		printf("Debe tener jugadores cargados\n");
            	}
            	break;
            case 6://convocados
            	break;
            case 7:
            	if(!ll_isEmpty(listaJugadores))
            	{
            		controller_ordenarJugadores(listaJugadores,listaSelecciones);
            	}
            	else
            	{
            		printf("Debe tener jugadores cargados\n");
            	}
            	break;
            case 8://guardar  GENERAR ARCHIVO BINARIO: Generar y guardar en binario una nueva lista
            	//que contenga los jugadores convocados de una confederaci�n ingresada por el usuario.

            	if(!ll_isEmpty(listaJugadores))
            	{
            		controller_guardarJugadoresModoBinario("jugadores.bin",listaJugadores);
            		printf("Guardado modo binario con exito jugadores \n");
            	}
            	else
            	{
            		printf("Debe cargar jugadores para poder guardarlos\n");
            	}
            	break;
            case 9://cargar  9. CARGAR ARCHIVO BINARIO: Se deber� leer e imprimir los datos del archivo generado en el punto 8.
            	if(!ll_isEmpty(listaJugadores)){
            		ll_clear(listaJugadores);
            	}
            	if(!controller_cargarJugadoresDesdeBinario("jugadores.bin",listaJugadores))
            	{
            		printf("Archivo binario Jugadores cargado exitosamente\n");
               	}
            	else
            	{
            		printf("No se pudo cargar el Archivo  binario Jugadores \n");
            	}
            	break;
            case 10:
            	//if(!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones))
            	if(flagGuardar == 0)
            	{
            		if(!controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores) &&
            		!controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones))
            		{
            			printf("Guardado Archivos Jugadores y selecciones  exitosamente\n");
            			flagGuardar =1;
            		}
            	}
            	else
            	{
            		printf("Debe tener Jugadores y selecciones cargados \n");
            	}

            	break;
            case 11:if(flagGuardar == 1)
            {
            	printf("Va a salir del programa sin guardar los cambios  realizados. Para guardar vuelva a la opcion 10 del menu \n");
            }
            else
            {
            	utn_pedirLetra(&seguir, "\nSeguro desea cerrar el programa?\n s-n : ", "\nError");
//            	utn_getCaracter(&seguir,"\n| �Desea cerrar del programa? (minuscula)\n  s = si\n  n = no \n","Error, ingrese s o n minuscula\n",'n','s',5);
            	break;
            }
        }
    	}
    }while(seguir == 'n');
    printf("\n. . . Acaba de Salir del Programa");
    return 0;
}

