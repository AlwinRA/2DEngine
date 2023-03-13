CXX		:= g++
CXX_FLAGS       := -g -std=c++17 #-Wextra -Wall

SRC		:= src
LIB		:= ./lib

LIBRARIES	:= -lglad -lglfw3dll -lgdi32 -lglew32 -lopengl32 -lglu32
EXECUTABLE	:= bin/main

all:./$(EXECUTABLE)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE):$(SRC)/*.cpp  $(SRC)/**/*.cpp $(SRC)/**/**/*.cpp
	$(CXX) $(CXX_FLAGS) -L$(LIB) $^ -o $@ $(LIBRARIES)
