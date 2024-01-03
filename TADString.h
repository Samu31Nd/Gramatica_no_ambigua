#ifndef _TADString_
#define _TADString_

typedef struct _nodeChar{
  struct _nodeChar *prev;
  struct _nodeChar *next;
  char c;
}_nodeChar;

typedef _nodeChar* _nodo;

typedef struct _string{
  _nodo node;
  int pos;
} _string;

typedef _string* string;

//Inicio de definición de operaciones

string crearString(); //implemented
void liberarString(string s); //implemented
void insertarCaracter(string s, char c); //implemented
void insertarCaracterPorIndice(string s, char c, int index); //implemented
void insertarNCaracteres(string s, char *caracteres, int no_elementos); //implemented
void insertarNCaracteresPorIndice(string s, char *caracteres, int no_elementos, int index); //implemented

char mostrarElementoActual(string s); //implemented
void insertarCaracterActual(string s, char c); //implemented
void insertarNCaracteresActual(string s, char *caracteres, int no_elementos); //implemented
void eliminarActual(string s); //implemented

void imprimirString(string s); //implemented
char mostrarElementoIndex(string s, int index); //implemented
char *mostrarNElementos(string s, int no_elementos);
char *mostrarNElementosIndex(string s, int no_elementos, int index);
void eliminarEnIndice(string s, int index); //implemented
int moverIndice(string s); //implemented
int obtenerIndice(string s); // implemented

//operaciones invicibles
int estaVaciaString(string s); //implemented
int StringLength(string s); //implemented
_nodo crearNodo(); //implemented
void manejaError(int codeError); //implemented
void liberarNodo(_nodo n); //implemented

#endif // !_TADString_
