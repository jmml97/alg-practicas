# ***** Variables *****
H_FILES = $(wildcard $(INCLUDE)/*.h)

# ****** Directorios ********
INCLUDE   = include
OBJ       = obj
SRC       = src
BIN       = bin
TEST      = $(SRC)/test

# ****** Opciones de compilación ********
AR        = ar
CXX       = g++
CXXFLAGS  = -Wall -O2 -g -std=c++11 -c -I./$(INCLUDE) -DNDEBUG
RM	  		= rm -f

# ****** Fuentes y cabeceras *************

SOURCES = $(addprefix $(SRC)/, TableroAjedrez.cpp Algoritmo.cpp main.cpp)
OBJECTS = $(addprefix $(OBJ)/, TableroAjedrez.o Algoritmo.o main.o)

# ****** Compilación de módulos **********

.PHONY: all test docs clean mrproper

all: $(BIN)/main

# --- Ejecutables ---

$(BIN)/main: $(OBJECTS)
	$(CXX) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/Algoritmo.o: $(INCLUDE)/TableroAjedrez.h $(INCLUDE)/Algoritmo.h

$(OBJ)/main.o: $(SRC)/*.cpp $(INCLUDE)/TableroAjedrez.h $(INCLUDE)/Algoritmo.h

$(OBJ)/TableroAjedrez.o: $(INCLUDE)/TableroAjedrez.h

# ************ Limpieza ************

clean:
	-@rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~
	@echo "Limpiando..."

mrproper: clean
	-@rm -f $(BIN)/*
	@echo "Limpieza completada."
