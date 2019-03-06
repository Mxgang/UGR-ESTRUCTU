#include "diccionario.h"
#include "bolsaletras.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
	if (argc!=5){
      cout<<"Dime el nombre del fichero con el diccionario, el fichero con las letras, el número de letras a generar y el modo de juego"<<endl;
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

   int num_letras = atoi(argv[3]);
   if(num_letras <= 0 || num_letras >= 50){
      cout << "No se ha introducido un número válido de letras";
   }

   if( (strcmp(argv[4], "L") != 0) && (strcmp(argv[4], "P") != 0) )
   {
      cout << "No se ha introducido un modo de juego válido";
      return 0;
   }

   Diccionario mi_diccionario;

   f1 >> mi_diccionario;

   bool salir;
   
   BolsaLetras bolsa_letras;
   f2 >> bolsa_letras;

   do
   {
      
      if(strcmp(argv[4], "P") == 0)
      {
         cout << "\n\n" << bolsa_letras;
      }

      cout << "\nLas letras son:\n";
      vector<pair<char,int> > salida_letras = bolsa_letras.sacarLetras(num_letras, argv[4]);
      for(int i = 0; i < salida_letras.size(); ++i)
         cout  << (char) toupper(salida_letras[i].first) << "\t"; 

      vector<string> palabras_posibles = mi_diccionario.algoritmoLongitud(salida_letras);

      Diccionario mi_diccionario_reducido(palabras_posibles);
      
      string solucion;
      cout << "\n\nIntroduzca su solución: ";
      cin >> solucion;

      while(!mi_diccionario_reducido.Esta(solucion))
      {
         cout << "\nLa palabra introducida no es válida, introduzca otra: ";
         cin >> solucion;
      }

      cout << "\n" << solucion << "\tPuntuación: " << solucion.size();

      cout << "\n\nPalabras posibles:\n";
      cout << "\n" << mi_diccionario_reducido;
      
      int maxima_puntuacion = 0;
      
      if( (strcmp(argv[4], "P") == 0))
      {
         for(int i = 0; i < palabras_posibles.size(); ++i)
         {
            if(bolsa_letras.getPuntuacionPalabra(palabras_posibles[i]) > maxima_puntuacion)   
               maxima_puntuacion = bolsa_letras.getPuntuacionPalabra(palabras_posibles[i]);
         }
         cout << "\n\nMejores soluciones:\n";
         vector<string> mejores_palabras = mi_diccionario_reducido.PalabrasPuntuacion(maxima_puntuacion, bolsa_letras);

         for(int i = 0 ; i < mejores_palabras.size(); ++i)
         {
            cout << "\n" << mejores_palabras[i] << "\tPuntuación: " << bolsa_letras.getPuntuacionPalabra(mejores_palabras[i]);
         }
      }
      else
      {
         for(int i = 0; i < palabras_posibles.size(); ++i)
         {
            if(palabras_posibles[i].length() > maxima_puntuacion)   
               maxima_puntuacion = palabras_posibles[i].size();
         }
         cout << "\n\nMejores soluciones:\n";
         vector<string> mejores_palabras = mi_diccionario_reducido.PalabrasLongitud(maxima_puntuacion);

         for(int i = 0 ; i < mejores_palabras.size(); ++i)
         {
            cout << "\n" << mejores_palabras[i] << "\tPuntuación: " << mejores_palabras[i].size();
         }
      }

      char opcion;
      do
      {
         cout << "\n\n¿Desea seguir jugando? [S/N]?\n";
         cin >> opcion;
      } while(toupper(opcion) != 'S' && toupper(opcion) != 'N');

      if(toupper(opcion) == 'S')
         salir = false;
      else
         salir = true;

   } while(!salir);
   
}