#include "diccionario.h"
#include "bolsaletras.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
	if (argc!=4){
      cout<<"Dime el nombre del fichero con el diccionario, el fichero con las letras y el fichero en el que quieres escribir"<<endl;
      return 0;
   }

   ifstream f1 (argv[1]);
   if (!f1){
      cout << "No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
   }

   ifstream f2 (argv[2]);
   if(!f2){
      cout << "No puedo abrir el fichero "<<argv[2]<<endl;
      return 0;
   }

   ofstream f3 (argv[3]);
   if (!f3)
   {
      cout << "No puedo abrir el fichero "<<argv[3] << " para escribir en él" << endl;
   }

   Diccionario mi_diccionario;

   f1 >> mi_diccionario;
   
   BolsaLetras bolsa_letras;

   f2 >> bolsa_letras;


   f3 << "#Letra\tFAbs.\tFrel." << endl;
   int letras_totales = mi_diccionario.getLetrasTotales();
   for (int i=0; i<bolsa_letras.size(); i++)
   {
        Letra l = bolsa_letras[i];

        char caracter = l.getChar();
        int fabs = mi_diccionario.getApariciones(caracter);
        double frel =  (double) fabs / letras_totales;

        f3 << caracter << '\t' << fabs << '\t' << frel << endl;
    }
    f3.close();
}