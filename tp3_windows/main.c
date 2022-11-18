#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();

    puts("funciona ok");

    do{
    	printf("\n1)CARGA DE ARCHIVOS\n2)ALTA DE JUGADOR\n3)MODIFICACIÓN DE JUGADOR\n4)BAJA DE JUGADOR\n5)LISTADOS\n6)\n7)\n8)\n9)\n10)");
    	printf("\nIngrese opcion :");
    	scanf("%d",&option);
        switch(option)
        {
            case 1:
            	printf("\nCARGA DE ARCHIVOS");
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
                break;
            case 2:
            	printf("\n2)ALTA DE JUGADOR");

            	break;
            case 3:
            	break;
            case 4:
            	break;
            case 5:
            	break;
        }
    }while(option != 10);

    return 0;
}

