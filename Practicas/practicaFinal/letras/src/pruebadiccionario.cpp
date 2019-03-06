#include "diccionario.h"
#include "bolsaletras.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
	if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Diccionario mi_diccionario;

   cout << "\nCargando diccionario..." << endl;

   f >> mi_diccionario; 

   cout << "\nLeido el diccionario..." << endl;

   cout << mi_diccionario;

   int longitud;
   cout << "\nDime la longitud de las palabras que quieres ver: ";
   cin >> longitud;
   

   cout << "\nPalabras de longitud " << longitud << ":\n";
   vector<string> palabras_longitud = mi_diccionario.PalabrasLongitud(longitud);
   for(int i = 0; i < palabras_longitud.size(); ++i)
      cout << palabras_longitud[i] << endl;

   string palabra;
   cout << "\nDime una palabra para comprobar si está en el diccionario: ";
   cin >> palabra;
   if(mi_diccionario.Esta(palabra))
      cout << "\nLa palabra \"" << palabra << "\" está en el diccionario" << endl;
   else
      cout << "\nLa palabra \"" << palabra << " no está en el diccionario" << endl;
}