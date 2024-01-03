#include "TADString.h"
#include <stdio.h>
#include <stdlib.h>

int _i;

string crearString(){
  string s = (string)malloc(sizeof(_string));
  s->node = NULL;
  s->pos = 0;
  return s;
}

int estaVaciaString(string s){
  if(s->node == NULL)
    return 1;
  else return 0;
}

_nodo crearNodo(){
  _nodo nodo = (_nodo)malloc(sizeof(_nodeChar));
  if(nodo == NULL){
    //no hay memoria suficiente para guardar el Nodo
    manejaError(0);
  }
  nodo->next = NULL;
  nodo->prev = NULL;
  return nodo;
}

int StringLength(string s){
  if(estaVaciaString(s)) return 0;
  int count = 0;
  _nodo aux = s->node;
  while(aux != NULL){
    count++;
    aux = aux->next;
  }
  return count;
}

int moverIndice(string s){
  if(estaVaciaString(s)){ s->pos = 0; return 1; }
  if(StringLength(s) > s->pos ){
    s->pos+=1;
  } 
  else{
    //no pudo mover el indice
    return 0;
  }
  return 1;
}

int obtenerIndice(string s){
  return s->pos;
}

void insertarCaracter(string s, char c){
  _nodo nodeTmp = crearNodo(),
        aux1,aux2;
  nodeTmp->c = c;
  if(estaVaciaString(s)){
    s->node = nodeTmp;
    return;
  }
  aux1 = s->node;
  while(aux1 != NULL){
    aux2 = aux1;
    aux1 = aux1->next;
  }
  aux2->next = nodeTmp;
  nodeTmp->prev = aux2;
  nodeTmp->next = aux1;
}

void insertarCaracterPorIndice(string s, char c, int index){
  _nodo nuevoNodo = crearNodo();
  nuevoNodo->c = c;
  if(estaVaciaString(s)){
    if(index) fprintf(stderr,"Arreglo vacio, insertando al inicio despreciando index.\n");
    s->node = nuevoNodo;
    return;
  }
  if(index == 0){
    s->node->prev = nuevoNodo;
    nuevoNodo->next = s->node;
    s->node = nuevoNodo;
    return;
  }
  _nodo aux1,aux2;
  aux1 = s->node;
  while(aux1 != NULL && index--){
    aux2 = aux1;
    aux1 = aux1->next;
  }
  //si no llego al final
  if(index >= 1) fprintf(stderr, "No existe ese indice, añadiendo al ultimo.\n");
  aux2->next = nuevoNodo;
  nuevoNodo->prev = aux2;
  nuevoNodo->next = aux1;
}
/* FAILED
void insertarNCaracteres(string s, char *caracteres, int no_elementos){
  if(no_elementos == 1) {
    printf("Bruh, this is just one element\n");
    insertarCaracter(s,caracteres[0]);
    return;
  }
  _nodo nodeTmp = crearNodo(), aux1, aux2;
  if(estaVaciaString(s)){
    s->node = nodeTmp;
    return;
  }
  aux1 = s->node;
  while(aux1 != NULL){
    aux2 = aux1;
    aux1 = aux1->next;
  }
  //añadimos el primer nodo a añadir
  aux2->next = nodeTmp;
  nodeTmp->prev = aux2;
  nodeTmp->c = caracteres[0];
  
  //inicializamos todo para empezar a añadir lo demas
  aux2 = nodeTmp;

  for(_i = 1; no_elementos; _i++){
    aux1 = crearNodo();
    aux1->c = caracteres[_i];
    aux1->prev = aux2;
    aux2->next = aux1;
    aux2 = aux1;
  }
}
*/


 void insertarNCaracteres(string s, char *caracteres, int no_elementos){
  if(no_elementos == 1) {
    printf("Bruh, this is just one element\n");
    insertarCaracter(s,caracteres[0]);
    return;
  }
  _nodo nodoInicial, aux1, aux2, nodoFinal;
  
  //conectamos el nodo inicial con aux1
  nodoInicial = crearNodo(); aux1 = crearNodo();
  nodoInicial->c = caracteres[0];
  nodoInicial->next = aux1;
  aux1->prev = nodoInicial;
  
  //Y aux2 apunta al anterior a aux1
  aux2 = nodoInicial;

  for(_i = 1; _i < no_elementos-1; _i++){
    aux2 = aux1;
    aux1 = crearNodo();
    aux2->c = caracteres[_i];

    aux1->prev = aux2;
    aux2->next = aux1;
  }
  nodoFinal = aux1;
  nodoFinal->c = caracteres[no_elementos-1];

  if(estaVaciaString(s)){
    s->node = nodoInicial;
    return;
  }

  aux1 = s->node;
  while(aux1 != NULL){
    aux2 = aux1;
    aux1 = aux1->next;
  }
  aux2->next = nodoInicial;
  nodoInicial->prev = aux2;
  nodoFinal->next = aux1; 

}

void imprimirString(string s){
  int count = s->pos;
  if(estaVaciaString(s)){
    manejaError(1);
    return;
  }
  _nodo aux = s->node;
  while(aux != NULL){
    if(count-- == 0)
    printf("{%c}",aux->c);
    else printf("[%c]",aux->c);
    aux = aux->next;
  }
}

/*
void imprimirString(string s){
  if(estaVaciaString(s)){
    manejaError(1);
    return;
  }
  _nodo aux = s->node;
  while(aux != NULL){
    printf("[%c]",aux->c);
    aux = aux->next;
  }
  printf("\n");
}
*/

void insertarNCaracteresPorIndice(string s, char *caracteres, int no_elementos, int index){
  if(no_elementos == 1) {
    printf("Bruh, this is just one element\n");
    insertarCaracter(s,caracteres[0]);
    return;
  }
  _nodo nodoInicial, aux1, aux2, nodoFinal;
  
  //conectamos el nodo inicial con aux1
  nodoInicial = crearNodo(); aux1 = crearNodo();
  nodoInicial->c = caracteres[0];
  nodoInicial->next = aux1;
  aux1->prev = nodoInicial;
  
  //Y aux2 apunta al anterior a aux1
  aux2 = nodoInicial;

  for(_i = 1; _i < no_elementos-1; _i++){
    aux2 = aux1;
    aux1 = crearNodo();
    aux2->c = caracteres[_i];

    aux1->prev = aux2;
    aux2->next = aux1;
  }
  nodoFinal = aux1;
  nodoFinal->c = caracteres[no_elementos-1];

  if(estaVaciaString(s)){
    if(index) fprintf(stderr,"Arreglo vacio, insertando al inicio despreciando index.\n");
    s->node = nodoInicial;
    return;
  }
  if(index == 0){
    s->node->prev = nodoFinal;
    nodoFinal->next = s->node;
    s->node = nodoInicial;
    return;
  }

  aux1 = s->node;
  while(aux1 != NULL && index--){
    aux2 = aux1;
    aux1 = aux1->next;
  }
  //si no llego al final
  if(index >= 1) fprintf(stderr, "No existe ese indice, añadiendo al ultimo.\n");

  aux2->next = nodoInicial;
  nodoInicial->prev = aux2;
  nodoFinal->next = aux1; 
}

char mostrarElementoActual(string s){
  return mostrarElementoIndex(s, s->pos);
}

char mostrarElementoIndex(string s, int index){
  if(estaVaciaString(s)){
    manejaError(2);
    return '\0';
  }
  _nodo aux1, aux2;
  char c;
  aux1 = s->node;
  aux2 = aux1;
  while(aux1!= NULL && index--){
    aux2 = aux1;
    aux1 = aux1->next;
  }
  if(aux1 == NULL) return '\0';
  return aux1->c;
}

void insertarNCaracteresActual(string s, char *caracteres, int no_elementos){
  insertarNCaracteresPorIndice(s, caracteres, no_elementos,s->pos);
}

void insertarCaracterActual(string s, char c){
  insertarCaracterPorIndice(s, c,s->pos);
}

void eliminarEnIndice(string s, int index){
  if(estaVaciaString(s)){
    manejaError(3);
    return;
  }
  _nodo aux1;
  if(index == 0){
    aux1 = s->node;
    s->node = aux1->next;
    if(s->node != NULL)
      s->node->prev = NULL;
    return;
  }

  _nodo aux2;
  aux1 = s->node;
  aux2 = aux1;
  while(aux1!= NULL && index--){
    aux2 = aux1;
    aux1 = aux1->next;
  }
  //si el index apunta a un elemento vacio, no tenemos nada que hacer ahi
  if(aux1 == NULL) return;
  //de otra forma, remplazamos el nodo por el siguiente
  aux2->next = aux1->next;
  //si es que no estamos en el ultimo nodo, que es NULL
  if(aux1->next != NULL)
    aux1->next->prev = aux2;
  else if(StringLength(s)-1 == s->pos) s->pos--;
}

void eliminarActual(string s){
  eliminarEnIndice(s,s->pos);
}

void liberarString(string s){
  _nodo aux1 = s->node, aux2;
  while(aux1 != NULL){
    aux2 = aux1;
    aux1 = aux1->next;
    free(aux2);
  }
  free(s);
}

void liberarNodo(_nodo n){
  free(n);
}

void manejaError(int error_code){
  char *errors[] = {
    "no hay memoria suficiente para guardar el Nodo",
    "La estructura esta vacia, no puede ser impresa...",
    "The structure is empty, cannot return a value",
    "The structure is empty, cannot delete a value",
    "Undefined character in main..."
  };
  fprintf(stderr,"%s\n",errors[error_code]);
}
