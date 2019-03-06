/**
  * @file letra.h
  * @brief Fichero cabecera del TDA Letra
  *
  */

#ifndef __Letra_h__
#define __Letra_h__

#include <iostream>

using namespace std;

class Letra
{
    private:

    	char c;	// El caracter
    	int n; 	// Las apariciones
    	int p; 	// La puntuacion

    public:

        /**
         * @brief Constructor sin parametros
         */
    	Letra() : c('\0'), n(0), p(0) {}

        /**
         * @brief Constructor con parametros
         * @param c Carácter asociado a la letra
         * @param n Número de apariciones de la letra
         * @param p Puntuación de la letra
         */
        Letra(char c, int n, int p) : c(c), n(n), p(p) {}

        /**
         * @brief Devuelve el carácter asociado a la letra
         * @return Carácter asociado a la letra
         */
        char getChar() const
        {
            return c;
        }
       
        /**
         * @brief Devuelve el número de apariciones de la letra
         * @return Número de apariciones de la letra
         */ 
        int getApariciones() const
        {
            return n;
        }

        /**
         * @brief Decrementa el número de apariciones de la letra que llama a la función
         */
        void decrementarApariciones()
        {
            if(n!=0)
                n--;
        }

        /**
         * @brief Devuelve la puntuación de la letra
         * @return Puntuación de la letra
         */
        int getPuntos() const
        {
        	return p;
        }

        /**
         * @brief Pinta una letra en un ostream
         *
         * @param os La referencia al ostream donde escribir
         * @param l Letra que se lee
         */
    	friend ostream & operator<<(ostream & os, const Letra &l)
    	{
    		os << l.c << "\t" << l.n << "\t" << l.p;
    		return os;
    	}

        /**
         * @brief Lee una letra desde un istream
         *
         * @param is La referencia al istream desde el que leer
         * @param l Letra en la que se escribe
         */
        friend istream & operator>>(istream & is, Letra &l)
        {
            is >> l.c >> l.n >> l.p;
            return is;
        }
};


#endif