#include <iostream>
#include "diccionario.h"
#include <algorithm>

//constructor vacio
Diccionario::Diccionario(){
	numpalabras = 0;
	reservados = 0;
}

Diccionario::Diccionario(vector<string> palabras)
{
	numpalabras = palabras.size();
	reservados = numpalabras;
	for(int i = 0; i < palabras.size(); ++i)
		aniadirPalabra(palabras[i]);
}

Nodo* Diccionario::inicializarNodo()
{
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->es_hoja = false;
	nuevoNodo->palabra_mas_larga = 0;
	for(int i = 0; i < SIZE; ++i)
		nuevoNodo->hijo[i] = NULL;
	return nuevoNodo;
}

//Resize simple
void Diccionario::resize(int r){
 /*set<string> *aux;   
 for(int i=0; i<numpalabras; ++i){
    aux[i]=datos[i]; 
 }
 delete[] datos;
 datos = aux;
 reservados = r;*/
}

int Diccionario::size() const{
	return datos.size();
}

int Diccionario::getApariciones(char c) {
	int apariciones = 0;
	set<string>::iterator it;
	string aux;
	for(it = datos.begin(); it != datos.end(); ++it)
	{
		aux = *it;
		for(int i = 0; i < aux.length(); ++i)
		{
			if(aux[i] == c)
				apariciones++;
		}
	}
	return apariciones;
}

vector<string> Diccionario::PalabrasLongitud(int longitud){
	vector<string> a;
	set<string>::iterator it;
	string aux;
	for(it = datos.begin(); it != datos.end(); ++it){
		aux = *it;
		if(aux.length() == longitud){
			a.push_back(aux);
		}
	}
	return a;
}

vector<string> Diccionario::PalabrasPuntuacion(int puntuacion, BolsaLetras bl)
{
	vector<string> a;
	set<string>::iterator it;
	string aux;
	for(it = datos.begin(); it != datos.end(); ++it){
		aux = *it;
		if(bl.getPuntuacionPalabra(aux) == puntuacion)
		{
			a.push_back(aux);
		}
	}
	return a;
}

void Diccionario::buscarPalabra(Nodo* raiz, int pueden_usarse[], string cadena_actual, vector<string>& palabras_encontradas){//, int mejor_puntuacion_encontrada){
	if(raiz->es_hoja == true)
	{
		//cout << "\nSe ha encontrado la palabra -> " + cadena_actual;
		for(int i = 0; i < SIZE; ++i)
		{
			//cout << "\n\t\tQuedan " << pueden_usarse[i] << " unidades de la letra " << CaracterAbecedario(i);
		}	
		palabras_encontradas.push_back(cadena_actual);
	}

	for (int i = 0; i < SIZE; ++i) 
    { 
    	//cout << "\n\t(buscarpalabra) Comprobando nodo '" << CaracterAbecedario(i) << "'...";
    	Nodo* nodo_hijo = raiz->hijo[i];
        if (pueden_usarse[i] > 0 && nodo_hijo != NULL) //&& nodo_hijo->palabra_mas_larga >= mejor_puntuacion_encontrada) 
        { 
        	//mejor_puntuacion_encontrada = nodo_hijo->palabra_mas_larga;
        	//cout << "\n\t(buscarpalabra) Profundizando en nodo '" << CaracterAbecedario(i) << "'(" << nodo_hijo->palabra_mas_larga << ")...";
        	pueden_usarse[i]--;
            char c = CaracterAbecedario(i);
            buscarPalabra(nodo_hijo, pueden_usarse, cadena_actual + c, palabras_encontradas);//, mejor_puntuacion_encontrada);
            pueden_usarse[i]++;
        } 
    }
}

//aqui estara el algoritmo que dado las letras te las va ordenando para obtener la palabra mas larga, poner el parametro que se necesite
vector<string> Diccionario::algoritmoLongitud(vector<pair<char,int> > desorden){

	// AÑADIR LAS PALABRAS AL ARBOL
	Nodo* raiz = inicializarNodo(); 
	Nodo* nodo_hijo;
	set<string>::iterator it;
	int maxima_longitud = 0;
	for(it = datos.begin(); it != datos.end(); ++it)
	{
		nodo_hijo = raiz;
		string palabra = *it;
		const char* palabra_separada = palabra.c_str();
		int tam = strlen(palabra_separada);
		//cout << "\nRAIZ";
	    for (int j=0; j<tam; ++j) 
	    { 
	        int indice = IndiceAbecedario(palabra_separada[j]); 
	  	
	        if (nodo_hijo->hijo[indice] == NULL) 
	        {
	        	//cout << "\nEl nodo hijo '" << CaracterAbecedario(indice) << "' ha sido inicializado al recibir la palabra " << palabra;
	            nodo_hijo->hijo[indice] = inicializarNodo(); 
	        }

	        nodo_hijo = nodo_hijo->hijo[indice]; 
	       	
	       	//cout << "\n\nPalabra más larga del nodo hijo: " << nodo_hijo->palabra_mas_larga << "\n"; 
	        if(nodo_hijo->palabra_mas_larga < tam)
	        {
	        	nodo_hijo->palabra_mas_larga = tam;
	        	//cout << "\nEl nodo '" << CaracterAbecedario(indice) << "' ha actualizado su longitud máxima a " << tam << " al recibir la palabra " << palabra; 
	        }
	        if(maxima_longitud < tam)
	        	maxima_longitud = tam;
	    } 
	    nodo_hijo->es_hoja = true; 
	    //cout << "\nSe ha introducido la palabra -> " << palabra;	
	}

    // ENCONTRAR LAS PALABRAS MÁS LARGAS

    vector<string> palabras_posibles;
	int pueden_usarse[SIZE] = {0};
    for (int i = 0 ; i < desorden.size(); i++) 
    {
    	//cout << "\nPuede usarse la letra -> " << desorden[i] << " con índice " << IndiceAbecedario(desorden[i]); 
        pueden_usarse[IndiceAbecedario(desorden[i].first)]++; 
    }

	string str = "";
	//int mejor_puntuacion_encontrada = 0;
	for (int i = 0 ; i < SIZE ; i++) 
    {
    	//cout << "\n(algoritmo) Comprobando nodo '" << CaracterAbecedario(i) << "'...";
    	nodo_hijo = raiz->hijo[i];
        if (pueden_usarse[i] > 0 && nodo_hijo != NULL) //&& nodo_hijo->palabra_mas_larga > mejor_puntuacion_encontrada) 	// EVITAMOS VISITAR NODOS QUE NO PUEDAN MEJORAR LA MEJOR PALABRA
        { 
        	//mejor_puntuacion_encontrada = nodo_hijo->palabra_mas_larga;
        	//cout << "\nMaxima longitud encontrada pasa a valer " << mejor_puntuacion_encontrada;
        	pueden_usarse[i]--;
            str = str+CaracterAbecedario(i); 
            buscarPalabra(nodo_hijo, pueden_usarse, str, palabras_posibles);//, mejor_puntuacion_encontrada); 
            str = ""; 
            pueden_usarse[i]++;
        } 
	}
	// En este punto tenemos todas las palabras que se pueden formar con las letras introducidas
	return palabras_posibles;
}

bool Diccionario::Esta(string palabra){
	bool esta = false;
	set<string>::iterator it;
	string aux;
	for(it = datos.begin(); it != datos.end(); ++it){
		if(*it == palabra)
			esta = true;
	}

	return esta;

}

void Diccionario::aniadirPalabra(string& palabra){
		datos.insert(palabra);
		numpalabras++;
		letrastotales+=palabra.length();
	}

istream & operator>>(istream & is,Diccionario &D){
	
    //is >> D.word;
    bool salir = false;

    while(!salir)
    {
      string aux;
      getline(is,aux);
      D.aniadirPalabra(aux);
      if(is.peek() == '\n' || is.eof())
      {
        salir = true;
      }
    }

    return is;
}

ostream & operator<<(ostream & os, const Diccionario &D){

	set<string>::iterator it;
    for(it = D.datos.begin(); it != D.datos.end(); ++it){
      os << *it << "\n";
    }
    return os;

}