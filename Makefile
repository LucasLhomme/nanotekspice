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
COMPONENTS_GATES	=	./src/components/gates_components
ADVANCED_COMP	=	./src/components/advanced_components

SRC         =   $(PROJECT)/main.cpp \
				$(PROJECT)/components/AComponent.cpp \
				$(PROJECT)/Parser.cpp \
				$(PROJECT)/Factory.cpp \
				$(PROJECT)/Circuit.cpp \
				$(COMPONENTS_SPECIAL)/Clock.cpp \
				$(COMPONENTS_SPECIAL)/Input.cpp \
				$(COMPONENTS_SPECIAL)/Output.cpp \
				$(COMPONENTS_SPECIAL)/True.cpp \
				$(COMPONENTS_SPECIAL)/False.cpp \
				$(COMPONENTS_SPECIAL)/Logger.cpp \
				$(COMPONENTS_ELEMENTARY)/or.cpp \
				$(COMPONENTS_ELEMENTARY)/and.cpp \
				$(COMPONENTS_ELEMENTARY)/xor.cpp \
				$(COMPONENTS_ELEMENTARY)/not.cpp \
				$(COMPONENTS_GATES)/comp_4069.cpp \
				$(COMPONENTS_GATES)/comp_4071.cpp \
				$(COMPONENTS_GATES)/comp_4030.cpp \
				$(COMPONENTS_GATES)/comp_4001.cpp \
				$(COMPONENTS_GATES)/comp_4081.cpp \
				$(COMPONENTS_GATES)/comp_4011.cpp \
				$(ADVANCED_COMP)/comp_4512.cpp \
				$(ADVANCED_COMP)/comp_4514.cpp \
				$(ADVANCED_COMP)/comp_4008.cpp \

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
