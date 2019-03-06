/**
  * @file bolsaletras.h
  * @brief Fichero cabecera del TDA BolsaLetras
  *
  */

#ifndef __BolsaLetras_h__
#define __BolsaLetras_h__

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "letra.h"

using namespace std;


class BolsaLetras
{

private:
 	vector<Letra> bolsa;

public:
	/**
	@brief Construye una bolsa de letras vacía
	**/
	BolsaLetras()
	{}

	/**
	 * @brief Construye una bolsa de letras partiendo de un vector de letras
	 *
	 * @param letras El vector de letras que forma la bolsa	
	 */
	BolsaLetras(vector<Letra> letras)
	{
		for(int i=0; i < letras.size(); ++i)
		{
			bolsa.push_back(letras[i]);
		}
	}

	/**
	 * @brief Devuelve Tamaño del conjunto de letras (abecedario)
	 *
	 * @return Tamaño del conjunto de letras
	 */
	int size()
	{
		return bolsa.size();
	}

	/**
	 * @brief Saca un número prefijado de letras de la bolsa con su valor asociado
	 *
	 * @param n El numero de letras que se sacan
	 * @param s La opción elegida para calcular la puntuación
	 * @return Vector de pares compuestos por las letras y sus valores asociados (puntuación)
	 */
	vector<pair<char,int> > sacarLetras(int n, const char* s)
	{
		vector<Letra> aux = bolsa;
		vector<pair<char,int> > letras;

		for(int i = 0; i < bolsa.size(); )
		{
			aux[i].decrementarApariciones();
			if(strcmp(s, "P") == 0)
				letras.push_back(make_pair(bolsa[i].getChar(), bolsa[i].getPuntos() ) );
			else
				letras.push_back(make_pair(bolsa[i].getChar(), 1) );

			if(aux[i].getApariciones() == 0)
				i++;
		}

		vector<pair<char,int> > letras_aleatorias;
		srand(time(0));

		for(int i = 0; i < n; ++i)
		{
			int rnd = rand() % letras.size();
			letras_aleatorias.push_back(letras.at(rnd));
		}	
		return letras_aleatorias;
	}

	/**
	 * @brief Mete una letra en la bolsa
	 *
	 * @param l Letra que se desea introducir en la bolsa
	 */
	void meteLetra(Letra l)
	{
		bolsa.push_back(l);
	}

	/**
	 * @brief Obtiene la puntuación total de una palabra
	 *
	 * @param p La palabra cuya puntuación se desea calcular
	 * @return Puntuación de la palabra
	 */
	int getPuntuacionPalabra(string p)
	{
		int puntos = 0;
		const char* c = p.c_str();

		for(int i = 0; i < p.length(); ++i)
		{
			for(int j = 0; j < bolsa.size(); ++j)
			{
				if(bolsa[j].getChar() == c[i])
				{
					puntos += bolsa[j].getPuntos();
				}
			}
		}
		return puntos;
	}

	/**
	 * @brief Sobrecarga del operador [] para acceder a una posición concreta de la bolsa
	 *
	 * @param n El índice al que se accede
	 * @return La letra situada en el índice dado
	 */
	const Letra & operator[](int n) const
    {
		return bolsa[n];
    };

	/**
	 * @brief Pinta una bolsa de letras en un ostream
	 *
	 * @param os La referencia al ostream donde escribir
	 * @param bl Bolsa de Letras desde la que leer
	 */
	friend ostream & operator<<(ostream & os, const BolsaLetras &bl)
	{
		vector<Letra>::const_iterator it = bl.bolsa.begin();
		
		os << "#Letra\tCantidad\tPuntos\n";
		while(it!=bl.bolsa.end())
		{
			os << *it << endl;
			++it;
		}
		return os;
	}

	/**
	 * @brief Llena una bolsa de letras desde un istream
	 *
	 * @param is La referencia al istream desde el que leer
	 * @param bl Bolsa de Letras en la que escribir
	 */
	friend istream & operator>>(istream & is, BolsaLetras &bl)
	{
		vector<Letra> letras;
		Letra l;
		string line;
		
		getline(is, line);
		if(line.at(0) == '#')
		{
			
			while(is >> l)
			{
				bl.meteLetra(l);
			}
		}
		
		return is;
	}

};

#endif