cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "clang++")

project(nanotekspice VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(CLANG_WARNINGS
        -Wall
        -Wextra
        -Werror
)

set(CLANG_DEBUG "-g")

set(SOURCES
        src/main.cpp
        src/Core.cpp
        src/Parsing/Parser.cpp
        src/Parsing/ParsingException.cpp
        src/Factory/ComponentFactory.cpp
        src/Factory/FactoryException.cpp
        src/Special-Components/InputComponent.cpp
        src/Special-Components/ClockComponent.cpp
        src/Special-Components/FalseComponent.cpp
        src/Special-Components/TrueComponent.cpp
        src/Special-Components/OutputComponent.cpp
        src/AComponent.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})