# TAD String (Version Personalizada)
El siguiente TAD de String esta elaborado para el lenguaje C, con el objetivo de brindar abstracción y hacer facil al implementación del programa de gramática no ambigua.

TAD String por Nodos (Un string expresado a base de nodos para poder añadir en cualquier momento, n carácteres en el indice especificado, y un indice que indica la posición de lectura de caracter actual)

Diseño de estructura:
```c
typedef struct _nodeChar{
  char c;
  struct _nodeChar *next;
  struct _nodeChar *prev;
}_nodeChar;

typedef _nodeChar *_node;

typedef struct String{
    _node node;
    int pos;
}String;
```


## Especificación Informal

**Operaciones visibles:**
Crear,Añadir,Mostrar,Eliminar,MoverIndice,Liberar

1.  **CrearString ()**
    Se crea la estructura para su uso.

2.  **LiberarString (String)**
    Se libera dinamicamente todos los nodos, previo a terminar el programa.

3.  **InsertarCaracter (String, Char)**
    Se añade un caracter en el indice actual.

4.  **InsertarCaracterPorIndice (String, Char, index)**
    Se añade un caracter en el indice especificado.

5.  **InsertarNCaracteres (String, Char\*, no_elementos)**
    Se itera sobre un arreglo de caracteres añadiendolos.

6.  **InsertarNCaracteresPorIndice (String, Char\*, no_elementos, index)**
    Se añade n caracteres en el indice indicado, si es que existe, si no, se regresa un código de error.

7.  **MostrarElementoActual (String)**
    Regresa el carácter al cuál se apunta actualmente el indice.

8. **InsertarCaracterActual (String, char)**
    Se inserta un caracter en el indice en el que se encuentre apuntando actualmente.

9. **InsertarNCaracteresActual (String, Char\*, no_elementos, index)**
    Se inserta N carácteres en el puesto actual donde se encuentre apuntando el índice.

10. **EliminarActual (String)**
    Elimina el carácter al que se encuentre apuntando actualmente el índice.
    Tiene que manejar el caso de que sea el primer o el último elemento, así como manejar comprobación de que el índice se encuentre en el correcto lugar.

11. **ImprimirString (String)**
    Imprime el arreglo String de forma completa.

12.  **MostrarElementoIndex (String,index)**
    Muestra el carácter en el índice especificado. Si este apunta a un lugar más alla de lo que tiene el String, devuelve el último del String.

13. **EliminarEnIndice (String, index)**
    Elimina el carácter del índice especificado.


14. **MoverIndice (String)**
    incrementa el valor del indice, si es que puede llegar a esa posición, si no, lanza error.

15. **ObtenerIndice (String)**
    Devuelve el índice de la estructura String.

## Especificación Formal

**Operaciones:**

1.  CrearString() -> String;
2.  LiberarString(String string);
3.  InsertarCaracter(String string, char caracter);
4.  InsertarCaracterPorIndice(String string, char caracter, int index);
5.  InsertarNCaracteres(String string, char\* caracteres, int no_elementos);
6.  InsertarNCaracteresPorIndice(String string, char\* caracteres, int no_elementos, int index);
7.  MostrarElementoActual(String string) -> char caracter;
8.  InsertarCaracterActual(String string, char caracter);
9.  InsertarNCaracteresActual(String string, char\* caracteres);
10. EliminarActual(String string);
11. ImprimirString(String string);
12. MostrarElementoIndex(String string, int index) -> char caracter;
13. EliminarEnIndice(String string, int index);
14. MoverIndice(String string);
15. ObtenerIndice(String string) -> int index;
