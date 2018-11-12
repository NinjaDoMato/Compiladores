cmake_minimum_required(VERSION 3.12)
project(Compiladores)

set(CMAKE_CXX_STANDARD 17)

add_executable(Compiladores main.cpp Model/Arquivo.h Model/AnalisadorLexico.h Model/Token.h Model/Arquivo.cpp Model/AnalisadorLexico.cpp Controller/CompiladorController.cpp Controller/CompiladorController.h Enuns/EstadoEnum.cpp Enuns/EstadoEnum.h)