#include <iostream>
#include <string>
#include "Cronologia.h"
#include "Fecha_Historica.h"

using namespace std;

//Resize
  void Cronologia::resize(int r){
     if(r>reservados){
	     Fecha_Historica *aux = new Fecha_Historica[r];   
	     for (int i=0; i<neventos; i++)
	        aux[i]=event[i]; 
	     delete[] event;
	     event = aux;
	     reservados=r;
     }
  }
  
//Ordena
  void Cronologia::ordenar(){
     for (int i=neventos-1; i>0; --i) 
      for (int j=0; j<i; ++j)
         if (event[j].getAnio() > event[j+1].getAnio()) {
            Fecha_Historica aux;
            aux = event[j];
            event[j] = event[j+1];
            event[j+1]= aux;
         }
}

//Constructor vacío
  Cronologia::Cronologia():reservados(0),neventos(0){delete[] event;}
     

//Constructor con parámetro cadena de Fecha_Historica y número de objetos
  Cronologia::Cronologia(Fecha_Historica *eh, int n):reservados(n),neventos(n){
     Fecha_Historica *event = new Fecha_Historica[n];   
     for (int i=0; i<n; i++)
        event[i]=eh[i];
  }

//Constructor de copias
   Cronologia::Cronologia(const Cronologia& c){
      event = new Fecha_Historica[c.reservados];
      neventos = c.neventos;
      reservados = c.neventos;
      for(int i=0; i<neventos; ++i)
      {
         event[i] = c.event[i];
         cout << "Copiando evento " << event[i];
      }
   }

//Añade objeto de Fecha_Historica
  void Cronologia::aniadirEvento(Fecha_Historica& eh){
     if (neventos == reservados){
        if (neventos==0)
           resize(1);
        else
           resize(2*reservados);
     }
     event[neventos]=eh;
     neventos++;
     ordenar();
  }

  //Borra un evento
   void Cronologia::borrarEvento(string& evento){
    /*for(int i = 0; i < neventos; ++i){
      if(event[i].find(evento) != -1)
        event->erase(i);
    }
    neventos--;
    ordenar();*/
   }


//Busca un evento en la Cronología y devuelve su posición en el vector
  int Cronologia::buscarAnio(int f){
     int i=0;
     bool valido=false;
     while(i<neventos && !valido){
        if(event[i].getAnio()==f)
           valido = true;
        else
           ++i;
     }
     if(!valido)
        i=-1;
     return i;
  }


//Busca un evento en la Cronología y devuelve su posición en el vector
  Cronologia Cronologia::buscarEventos(string s){
     Cronologia nuevo;
     for (int i=0; i < neventos; ++i){
        Fecha_Historica aux;
        if(event[i].buscarEventos(s,aux)){
           nuevo.aniadirEvento(aux);
        }
     }
     nuevo.ordenar();
     return nuevo;
   }

//Devuelve los eventos de un año especifico
  Fecha_Historica Cronologia::getEventosAnio(int anio){

    bool anio_encontrado = false;
    Fecha_Historica fecha;
    for(int i = 0; i < neventos && !anio_encontrado; ++i)
    {
      if(event[i].getAnio() == anio)
      {
        fecha = event[i];
        anio_encontrado = true;
      }
    }    
    cout << fecha << endl;
    return fecha;
  }

//Operador <<
  ostream& operator<< (ostream& os, const Cronologia& c){
     for(int i=0; i<c.neventos; i++)
        os << c.event[i] << "\n";
     return os;     
  }

//Operador >>
  istream& operator>> (istream& is, Cronologia& c){
    Fecha_Historica b, fecha_nula;
    while(is >> b){
		c.aniadirEvento(b);
		cout << "\nSe ha añadido el evento: " << b;
		cout << "\nNúmero de eventos: " << c.neventos << " | " << "Reservados: " << c.reservados;
		b = fecha_nula;
    }
    
    return is;
  } 
