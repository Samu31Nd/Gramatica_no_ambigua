#include "TADString.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N;
char *createRandomParentheses(int n);
int checkLL(char *parentheses, string s);

int main(int argc, char *argv[]){
  srand(time(NULL));
  string s = crearString(); int decision;
  printf("Ingresa el tamaño de n: ");
  scanf("%d",&N);
  char *parentheses = createRandomParentheses(N);
  printf("Cadena creada: [%s]\n",parentheses);
  int c = getchar();
  decision = checkLL(parentheses,s);
  printf("\n\tLa cadena %s a la gramatica.\n",decision?"pertenece":"no pertenece");
  return EXIT_SUCCESS;
}

char *createRandomParentheses(int charLength){
  char *string = (char*)malloc(sizeof(char)*(charLength+1));

  for(int i = 0; i < charLength; i++)
    string[i] = (rand()%2)?'(':')';
  string[charLength] = '\0';
  return string;
}

int checkLL(char *parentheses, string s){
  insertarCaracter(s, 'B');
  while (*parentheses != '\0'){
    printf("Input: %c.\t",*parentheses);
    if(estaVaciaString(s)) return 0;
    printf("Steps: "); imprimirString(s); printf(" -> ");
    switch (*parentheses) {
      case '(':
        if(mostrarElementoActual(s) == 'B'){
          eliminarActual(s);
          insertarNCaracteresActual(s, "(RB", 3);
        } else if(mostrarElementoActual(s) == 'R'){
          eliminarActual(s);
          insertarNCaracteresActual(s, "(RR", 3);
        } else return 0;
        break;
      case ')':
        if(mostrarElementoActual(s) == 'R'){
          eliminarActual(s);
          insertarCaracterActual(s, ')');
        } else if(mostrarElementoActual(s) == 'B'){
          eliminarActual(s);
        } else return 0;
        break;

      default:
        fprintf(stderr, "Unexpected token in switch: [%c]\n",*parentheses);
        return 0;
    }
    if(!moverIndice(s)){
      imprimirString(s);
      return 0;
    }
    parentheses++;
    if(estaVaciaString(s)) printf("[e]");
    else imprimirString(s);  
    printf("\n");
  }
  printf("Input: e.\t");

  if(estaVaciaString(s)) return 0;
  printf("Steps: "); imprimirString(s); printf(" -> ");
  if(mostrarElementoActual(s) == 'B') eliminarActual(s);
  else return 0;

  imprimirString(s); printf("\n");
  if(mostrarElementoActual(s) != '\0')
    return 0;
  return 1;
}
