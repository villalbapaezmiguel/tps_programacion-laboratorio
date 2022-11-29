
#ifndef PARSER_H_
#define PARSER_H_


//JUGADORES
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);//hecho
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);//hecho
//SELECCIONES
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_JugadorFromText2(FILE* pFile , LinkedList* pArrayListJugador);


#endif /* PARSER_H_ */
