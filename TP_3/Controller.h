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

int controller_agregarJugador(LinkedList* pArrayListJugador);

int controller_listarJugadores(LinkedList* pArrayListJugador);

int controller_editarJugador(LinkedList* pArrayListJugador);

int controller_removeJugador(LinkedList* pArrayListJugador);



int controller_mostrarJug_selec(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_ordenarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

int controller_ordenarJugadores2(LinkedList* pArrayListJugador);

int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

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

