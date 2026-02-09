##
## EPITECH PROJECT, 2025
## G-OOP-400-LIL-3-1-NANOTEKSPICE
## File description:
## Makefile
##

PROJECT     =   ./src
INCLUDE		=	./include
COMPONENTS_SPECIAL	=	./src/components/Special
COMPONENTS_ELEMENTARY	=	./src/components/elementary_components

SRC         =   $(PROJECT)/main.cpp \
				$(PROJECT)/Parser.cpp \
				$(PROJECT)/Factory.cpp \
				$(PROJECT)/Circuit.cpp \
				$(COMPONENTS_SPECIAL)/Clock.cpp \
				$(COMPONENTS_SPECIAL)/Input.cpp \
				$(COMPONENTS_SPECIAL)/Output.cpp \
				$(COMPONENTS_SPECIAL)/True.cpp \
				$(COMPONENTS_SPECIAL)/False.cpp \
				$(COMPONENTS_ELEMENTARY)/or.cpp \
				$(COMPONENTS_ELEMENTARY)/and.cpp \
				$(COMPONENTS_ELEMENTARY)/xor.cpp \
				$(COMPONENTS_ELEMENTARY)/not.cpp \


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
