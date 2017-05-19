# ***** Variables *****
LIBNAME   = cronologia
H_FILES = $(wildcard $(INCLUDE)/*.h)

# ****** Directorios ********
INCLUDE   = include
LIB       = lib
OBJ       = obj
SRC       = src
BIN       = bin
DOC       = doc
TEST      = $(SRC)/test

# ****** Opciones de compilación ********
AR        = ar
CXX       = g++
CXXFLAGS  = -Wall -g -std=c++11 -c -I./$(INCLUDE) -DNDEBUG
LDFLAGS   = -L./$(LIB)
LDLIBS    = -l$(LIBNAME)
RM				= rm -f

# ****** Fuentes y cabeceras *************

SOURCES = $(addprefix $(SRC)/, Algoritmo.cpp Solucion.cpp Problema.cpp)
OBJECTS = $(addprefix $(OBJ)/, main.o Algoritmo.o Solucion.o Problema.o)

# ****** Compilación de módulos **********

.PHONY: all test docs clean mrproper

all: $(BIN)/main

# --- Ejecutables ---

$(BIN)/main : $(OBJECTS)
	$(CXX) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# ************ Generación de documentación **************
docs:
	@doxygen $(DOC)/doxys/Doxyfile
	@echo "Documentación disponible en $(DOC)/html"

# ************ Limpieza ************

clean:
	-@rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~
	@echo "Limpiando..."

mrproper: clean
	-@rm -f $(BIN)/* $(LIB)/* $(DOC)/html/*
	@echo "Limpieza completada."
