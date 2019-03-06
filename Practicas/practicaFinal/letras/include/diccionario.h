/**
  * @file diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef __Diccionario_h__
#define __Diccionario_h__
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <iterator>
#include <map>
#include "letra.h"
#include "bolsaletras.h"

using namespace std;

const int SIZE = 26;

struct Nodo 
{ 
    Nodo* hijo[SIZE]; 
    bool es_hoja;
    int palabra_mas_larga;
};


class Diccionario{

	private:


		set<string> datos;
		int numpalabras;
		int letrastotales;
		int reservados;
		void resize(int r); /**< Funcion privada para mantener el vector dinámico de set<string> */
		
		/**
		 * @brief Devuelve el índice en el abecedario del carácter dado
		 * @param c Carácter del que se quiere obtener el índice
		 * @return Índice en el abecedario del carácter dado
		**/
		int IndiceAbecedario(char c)
		{
			return (int) c - (int) 'a';
		}

		/**
		 * @brief Devuelve el carácter dado un índice del abecedario
		 * @param indice Índice del que se quiere obtener el carácter
		 * @return Carácter situado en el índice dado en el abecedario
		**/
		char CaracterAbecedario(int indice)
		{
			return (char) indice + (char) 'a';
		}

		/**
		 * @brief Busca las palabras que se pueden formar dado un nodo raiz
		 * @param raiz Nodo raiz del árbol
		 * @param pueden_usarse Vector de enteros que indica cuantas unidades de cada letra pueden usarse
		 * @param cadena_actual Cadena formada hasta el momento
		 * @param palabras_encontradas Vector de las cadenas encontradas hasta el momento
		 * @return Carácter situado en el índice dado en el abecedario
		**/
		void buscarPalabra(Nodo* raiz, int pueden_usarse[], string cadena_actual, vector<string>& palabras_encontradas);//, int mejor_puntuacion_encontrada);

		/**
		 * @brief Inicializa un nodo del árbol
		 * @return Nodo inicializado
		**/
		Nodo* inicializarNodo();

	public:
		/**
		@brief Construye un diccionario vacío.
		**/
		Diccionario();

		/**
		 * @brief Construye un diccionario partiendo de un vector de string
		 *
		 * @param palabras El vector de string que contiene las palabras
		 */
		Diccionario(vector<string> palabras);

		/**
		 * @brief Obtiene el número de letras totales del diccionario
		 * @return Número de letras totales del diccionario
		**/
		int getLetrasTotales()
		{
			return letrastotales;
		}

		/**
		 * @brief Obtiene el número de apariciones de un caracter concreto en el diccionario
		 * @param c El carácter a buscar
		 * @return Número de apariciones del carácter en el diccionario
		**/
		int getApariciones(char c);

		/**
		 * @brief Obtiene el tamaño del diccionario
		 * @return Tamaño del diccionario
		**/
		int size() const ;

		/**
		 * @brief Obtiene todas las palabras en el diccionario de una longitud dada
		 * @param longitud La longitud de las palabras de salida
		 * @return Un vector con las palabras de longitud especifica en el parametro de entrada
		**/
		vector<string> PalabrasLongitud(int longitud);

		/**
		 * @brief Obtiene todas las palabras en el diccionario de una puntuación dadda
		 * @param puntuacion La puntuación de las palabras de salida
		 * @param bl Bolsa de letras de la que se obtienen los valores de las letras
		 * Un vector con las palabras de puntuación especifica en el parametro de entrada
		**/
		vector<string> PalabrasPuntuacion(int puntuacion, BolsaLetras bl);

		/**
		 * @brief Indica si una palabra está en el diccionario o no
		 * @param palabra: la palabra que se quiere buscar
		 * @return true si la palabra esta en el diccionario. False en caso contrario
		**/
		bool Esta(string palabra);

		/**
		 * @brief Añade una palabra al diccionario
		 * @param palabra la palabra que se desea insertar en el diccionario
		**/
		void aniadirPalabra(string& palabra);

		/**
		 * @brief Devuelve las palabras que se pueden crear dados unos caracteres desordenados
		 * @param desorden Vector que contiene los caracteres desordenados y sus puntuaciones asociadas
		 * @return Un vector que consta de todas las palabras que el diccionario puede formar con los caracteres dados
		**/
		vector<string> algoritmoLongitud(vector<pair<char,int> > desorden);

		/**
		@brief Lee de un flujo de entrada un diccionario
		@param is:flujo de entrada
		@param D: el objeto donde se realiza la lectura.
		@return el flujo de entrada
		**/
		friend istream & operator>>(istream & is,Diccionario &D);

		/**
		@brief Escribe en un flujo de salida un diccionario
		@param os:flujo de salida
		@param D: el objeto diccionario que se escribe
		@return el flujo de salida
		**/
		friend ostream & operator<<(ostream & os, const Diccionario &D);

	class iterator{
	private:
		set<string>::iterator it;
	public:
		iterator & operator++(){
			++it;
		}
		iterator & operator--(){
			--it;
		}
		const string operator *(){
			return *it;
		}
		bool operator ==(const iterator &i){
			return i.it==it;
		}	  
		bool operator !=(const iterator &i){
			return i.it!=it;
		}
		friend class Diccionario;
    };
    
    /**
     * @brief Inicializa un iterator al comienzo de la guia
     * */
    iterator begin(){
	iterator i;
	i.it=datos.begin();
	return i;
    }
    /**
     * @brief Inicializa un iterator al final de la guia
     * */
    iterator end(){
	iterator i;
	i.it=datos.end();
	return i;
    } 
};

#endif