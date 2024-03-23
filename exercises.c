#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
  List* L = create_list();
  for(int i = 1; i <= 10; i++){
    int* dato = (int*)malloc(sizeof(int)); //resarvando memoria de cada elemento en un puntero
    *dato = i;
    pushCurrent(L, dato);  
  }
  return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
  int suma = 0;
  int* dato = (int*)first(L);
  while(dato != NULL){
    suma += *dato;
    dato = (int*)next(L);
  }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
  int* dato = (int*)first(L);
  while(dato != NULL){
    if(*dato == elem) popCurrent(L); 
    dato = next(L);
  }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
  char stack[1000]; // Usaremos un arreglo para simular una pila para almacenar los paréntesis abiertos
  int top = -1; // Índice que representa el tope de la pila

  // Iteramos sobre cada carácter de la cadena
  for (int i = 0; cadena[i] != '\0'; i++) {
      // Si encontramos un paréntesis abierto, lo agregamos a la pila
      if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') {
          stack[++top] = cadena[i];
      }
      // Si encontramos un paréntesis cerrado
      else if (cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}') {
          // Si la pila está vacía, significa que no hay un paréntesis abierto correspondiente
          if (top == -1) {
              return 0; // Paréntesis desbalanceados
          }
          // Si el paréntesis cerrado no coincide con el último paréntesis abierto en la pila, están desbalanceados
          else if ((cadena[i] == ')' && stack[top] != '(') ||
                   (cadena[i] == ']' && stack[top] != '[') ||
                   (cadena[i] == '}' && stack[top] != '{')) {
              return 0; // Paréntesis desbalanceados
          }
          // Si coincide, eliminamos el paréntesis abierto de la pila
          else {
              top--;
          }
      }
  }
  // Al finalizar, si la pila está vacía, significa que todos los paréntesis tienen sus cierres correspondientes
  return (top == -1) ? 1 : 0;
  }
