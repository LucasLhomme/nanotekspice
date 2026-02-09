##
## EPITECH PROJECT, 2025
## G-OOP-400-LIL-3-1-NANOTEKSPICE
## File description:
## Makefile
##

PROJECT     =   ./src
INCLUDE		=	./include
COMPONENTS	=	./src/components

SRC         =   $(PROJECT)/main.cpp \
				$(PROJECT)/Parser.cpp \
				$(PROJECT)/Factory.cpp \
				$(PROJECT)/Circuit.cpp \
				$(COMPONENTS)/Clock.cpp \
				$(COMPONENTS)/Input.cpp \
				$(COMPONENTS)/Output.cpp \

OBJ			=	$(SRC:.cpp=.o)
EXEC        =   nanotekspice
CXX			= 	clang++
CXXFLAGS    +=  -std=c++20 -W -Wall -Wextra -g -Iinclude/

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
