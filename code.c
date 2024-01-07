#include "TADString.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_LIMIT 200

int N;
int askNumber();
char *generateString();
char *createRandomParentheses(int n);
int checkLL(char *parentheses, string s);

int main(int argc, char *argv[]){
  srand(time(NULL));
  string s = crearString(); int decision;
  char *parentheses = generateString();
  printf("Cadena creada: [%s]\n",parentheses);
  int c = getchar();
  decision = checkLL(parentheses,s);
  printf("\n\tLa cadena %s a la gramatica.\n",decision?"pertenece":"no pertenece");
  free(parentheses);
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

char *generateString(){
  int N;
  char *parentheses;
  //queremos crear la cadena
  if((N = askNumber()) == 0){
    parentheses = (char*)malloc(sizeof(char)*SIZE_LIMIT);
    printf("\nIngresa la cadena: ");
    scanf("%s",parentheses);

  }else parentheses = createRandomParentheses(N);
  return parentheses;
}

int askNumber(){
  int option, number = -1;
  do{ 
    printf("Ingresa una opcion: \n");
    printf("\t1. Numero aleatorio.\n");
    printf("\t2. Ingresar numero n.\n");
    printf("\t3. Ingresar cadena personalizada.\n");
    printf("Tu opcion: "); scanf("%d",&option);
    if(option == 1)number = rand()%1000;
    else if(option == 2){
      printf("Ingresa n: ");
      scanf("%d", &number);
    } else if (option == 3) number = 0;
    else printf("Has ingresado una opcion invalida, reintenta.\n");
  }while(number == -1);
  return number;
}
