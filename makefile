CXX		:= g++
CXX_FLAGS       := -g -std=c++17 #-Wextra -Wall

SRC		:= src
INCLUDE         := ./src/Utils
LIB		:= ./lib

LIBRARIES	:= -lglad -lglfw3dll -lgdi32 -lglew32 -lopengl32
EXECUTABLE	:= build/main

all:./$(EXECUTABLE)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE):$(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)
