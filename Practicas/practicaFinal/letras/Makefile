INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g


all: $(BIN)/testdiccionario $(BIN)/letras $(BIN)/cantidad_letras

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/testdiccionario : $(OBJ)/pruebadiccionario.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/pruebadiccionario.o $(OBJ)/diccionario.o
$(BIN)/letras : $(OBJ)/letras.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/diccionario.o
$(BIN)/cantidad_letras : $(OBJ)/cantidad_letras.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o $(OBJ)/diccionario.o

$(OBJ)/pruebadiccionario.o : $(INC)/diccionario.h $(SRC)/pruebadiccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp

$(OBJ)/letras.o : $(INC)/diccionario.h $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/letras.o $(SRC)/letras.cpp

$(OBJ)/cantidad_letras.o : $(INC)/diccionario.h $(SRC)/cantidad_letras.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp

$(OBJ)/diccionario.o : $(INC)/diccionario.h $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -rf $(BIN)/* doc/html/* doc/latex/*
