//TP3
//#include "Jugador.h"
//1. CARGA DE ARCHIVOS: Se deben leer los archivos .csv de jugadores y selecciones
///HECHO
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
//8. GENERAR ARCHIVO BINARIO: Generar y guardar en binario una nueva lista que contenga los jugadores convocados de una confederaci�n ingresada por el usuario
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

int encontrarElIdU(char* id);
int encontrarUltimoId(char* path, char* id);
int actualizarId(char* path, char* id);

//int jug_obtenerElmaxId(Jugador* this,int* id);
int obtenerID(int* id);
int actualizarIdok(int id);
int controller_guardarComoTextoMaxID(FILE* pFile,char* path, LinkedList* pArrayListJugador);
int controller_guardarComoTexto_maximoId(FILE* pFile, LinkedList* pArrayListJugador,int* maxID);
int buscarJugadorId(int* idABuscar, LinkedList* pArrayListJugador);
//2 ALTA HECHO PERO PONER OPCION DE NACION Y POS
int controller_agregarJugador(LinkedList* pArrayListJugador);
//.5 LISTADOS: A) TODOS LOS JUGADORES.
//HECHO
int controller_listarJugadores(LinkedList* pArrayListJugador);
//3  MODIFICAR HECHO PERO PONER OPCION DE NACION Y POS
int controller_editarJugador(LinkedList* pArrayListJugador);
//  4 BAJA
int controller_removerJugador(LinkedList* pArrayListJugador);
//.5 LISTADOS: A) TODOS LOS JUGADORES.


int controller_listarJugYSelec(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_ordenarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
//7. ORDENAR Y LISTAR
int controller_ordenarJugadores2(LinkedList* pArrayListJugador);
//10. GUARDAR ARCHIVOS .CSV: Se deber� guardar en sus respectivos archivos todos los cambios realizados en jugadores
//HECHO
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
//hecho probar bien
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

//SELECIOOOON
//HECHO
//1. CARGA DE ARCHIVOS: Se deben leer los archivos .csv de jugadores y selecciones
//HACHO
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

//int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
//5 LISTADOS B) TODAS LAS SELECCIONES. [hacer pensar]C) JUGADORES CONVOCADOS (�nicamente).
//HECHO
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_imprimirJugadoresConvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, int referenciaDeUso);

int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
//10. GUARDAR ARCHIVOS .CSV: Se deber� guardar en sus respectivos archivos todos los cambios realizados en  selecciones
//HECHO OK
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

//============
int controller_agregarJugador3(LinkedList* pArrayListJugador);

