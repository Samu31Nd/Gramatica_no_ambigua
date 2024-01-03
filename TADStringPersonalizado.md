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

1.  **CrearString ():** 
    Se crea la estructura para su uso.

2.  **LiberarString (String):**
    Se libera dinamicamente todos los nodos, previo a terminar el programa.

3.  **InsertarCaracter (String, Char)**
    Se añade un caracter en el indice actual.

4.  **InsertarCaracterPorIndice (String, Char, index)**
    Se añade un caracter en el indice especificado.

5.  **InsertarNCaracteres (String, Char\*, no_elementos)**
    Se itera sobre un arreglo de caracteres añadiendolos.

6.  **InsertarNCaracteresPorIndice (String, Char\*, no_elementos, index)**
    Se añade n caracteres en el indice indicado, si es que existe, si no, se regresa un código de error.

7. **imprimirString(String):**
    Imprime el arreglo String de forma completa.

7.  **MostrarElementoActual (String)**
    

8.  **MostrarElementoIndex (String,index)**
    

9.  **MostrarNElementos (String, no_elementos)**


10. **MostrarNElementosIndex (String, no_elementos, index)**


11. **EliminarActual (String)**


12. **EliminarEnIndice (String, index)**


13. **MoverIndice (String)**
    incrementa el valor del indice, si es que puede llegar a esa posición

## Especificación Formal

**Operaciones:**

1. 
