Componentes del grupo:
	Enrique Moreno Carmona
	Javier Martín Gómez

Modo de uso:
	Desde el directorio letras hacer make all

	Para ejecutar los 3 programas (ejemplos):
		./bin/cantidad_letras ./datos/diccionario1000.txt ./datos/letras.txt
		./bin/letras ./datos/diccionario1000.txt ./datos/letras.txt 20 L
		./bin/letras ./datos/diccionario1000.txt ./datos/letras.txt 20 P

Algoritmo empleado para obtener las palabras más largas:
	Inicialmente pensabamos implementar todo el diccionario mediante un árbol de prefijos,
	sin embargo, al ver que en la práctica se indicaba que se usase en el diccionario el
	tipo set, optamos por generar un árbol de forma local en el método "algoritmoLongitud",
	que consta de una estructura de Nodos, cada uno de los cuales contiene:
		- Un booleano indicando si es una palabra válida
		- Un puntero que apunta a los 26 nodos que cuelgan de este (cada uno de los
		cuales representa una letra del abecedario)
		- Un entero que indica la palabra de mayor longitud que se puede generar con ese
		prefijo (lo cual nos podría ahorrar, por ejemplo, visitar nodos que no son tan
		prometedores como la palabra de mayor longitud encontrada)
	Con esa estructura y con ayuda del método de llamada recursiva "buscarPalabra", hemos
	podido generar el árbol deseado, llamando a las funciones IndiceAbecedario y
	CaracterAbecedario para traducir la información de los punteros

Nota: Se podría implementar, en caso de no querer comprobar todas las palabras posibles
dadas unas letras, un algoritmo que solo comprobase los nodos que permiten crear una palabra,
como mínimo, tan larga como la mayor encontrada hasta el momento.
Para poner ese algoritmo en práctica, habría que descomentar las líneas (que no contienen cout)
de las funciones "buscarPalabra" y "algoritmoLongitud"

Para más información acerca de los métodos, ver la documentación en doxygen (generada con make documentacion)