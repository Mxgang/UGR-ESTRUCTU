#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;
  
  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";
  
  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

int main(){
  
  set<int> A, B, C; //conjuntos A, B y C
  set<int> parte1, parte2;
  set<int>::iterator it1;
  set<int>::iterator aux1, aux2;
  
  //Conjunto A, todos los elementos del 1 al 9 salvo los pares (1,2,5,7,9)
  for(int i = 0; i < 10; i++) A.insert(i);
  for(int i = 0; i < 10; i+=2) A.erase(i);

  //Conjunto B, todos los elementos del 1 al 9 salvo el 3,6,9 (1,2,4,5,7,8)
  for(int i = 0; i < 10; i++) B.insert(i);
  for(int i = 0; i < 10; i+=3) B.erase(i);

  //Conjunto C, todos los elementos del 1 al 9 salvo el 4,8 (1,2,3,5,6,7,9)
  for(int i = 0; i < 10; i++) C.insert(i);
  for(int i = 0; i < 10; i+=4) C.erase(i);

//----------------------------------------------------------------------------//

  //elementos de A que no están ni en B ni en C (no hay)
  for(it1 = A.begin(); it1 != A.end(); ++it1){ //itero sobre el conjunto A
    aux1 = B.find(*it1); //si el elemento de *it1 está en el conjunto B, ese valor lo tomará aux1, si no, el valor es null
    aux2 = C.find(*it1); //si el elemento de *it1 está en el conjunto de C, ese valor lo tomará aux2, si no, el valor es null
    if(*it1 != *aux1 && *it1 != *aux2) //comprueba si el valor de *it1 es distinto al de aux1 y aux2
      parte1.insert(*it1); //si se cumple la condición, inserto dicho valor en parte1
  }

  //elementos de B que no están ni en A ni en C (4 y 8)
  for(it1 = B.begin(); it1 != B.end(); ++it1){
    aux1 = A.find(*it1);
    aux2 = C.find(*it1);
    if(*it1 != *aux1 && *it1 != *aux2)
      parte1.insert(*it1);
  }

  //elementos de C que no están ni en A ni en B (no hay)
  for(it1 = C.begin(); it1 != C.end(); ++it1){
    aux1 = A.find(*it1);
    aux2 = B.find(*it1);
    if(*it1 != *aux1 && *it1 != *aux2)
      parte1.insert(*it1);
  }

//-------------------------------------------------------------------------------------------//


  //elementos de A y B que no están en C (no hay)

  for(it1 = A.begin(); it1!= A.end(); ++it1){
    aux1 = B.find(*it1);
    aux2 = C.find(*it1);
    if(*it1 == *aux1 && *it1 != *aux2)
      parte2.insert(*it1);
  }

  //elementos de B y C que no están en A (2)

  for(it1 = B.begin(); it1!= B.end(); ++it1){
    aux1 = A.find(*it1);
    aux2 = C.find(*it1);
    if(*it1 == *aux2 && *it1 != *aux1)
      parte2.insert(*it1);
  }

  //elementos de A y C que no están en B (3 y 9)

  for(it1 = A.begin(); it1!= A.end(); ++it1){
    aux1 = B.find(*it1);
    aux2 = C.find(*it1);
    if(*it1 == *aux2 && *it1 != *aux1)
      parte2.insert(*it1);
  }

  cout << "El resultado de la primera parte es: " << parte1 << endl;

  cout << "El resultado de la segunda parte es: " << parte2 << endl;
}  