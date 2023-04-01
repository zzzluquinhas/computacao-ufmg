#
# Copyright 2021 Alysson Ribeiro da Silva - Federal University of Minas Gerais
#
# Permission is hereby granted, free of charge, to any person obtaining a copy 
# of this software and associated documentation files (the "Software"), to deal 
# in the Software without restriction, including without limitation the rights 
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
# of the Software, and to permit persons to whom the Software is furnished to do 
# so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all 
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
# PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
# HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

# cc and flags
CC = g++
CXXFLAGS = -std=c++17 -g -Wall -pg
#CXXFLAGS = -std=c++11 -O3 -Wall

# folders
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/
# TMP_FOLDER = ./tmp/
# ANALISAMEM = ./analisamem/#-pg
# MEMLOG = ./memlog/

# all sources, objs, and header files
MAIN = Main
TARGET = run.out
SRC = $(wildcard $(SRC_FOLDER)*.cc) 
OBJ = $(patsubst $(SRC_FOLDER)%.cc, $(OBJ_FOLDER)%.o, $(SRC))

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cc
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

clean:
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)*

run:
	./bin/run.out

val:
	valgrind --leak-check=full --track-origins=yes ./bin/run.out -v 1 -s 10 -i testes/entrada/entradavalgrind.txt -o testes/saida/temp.out
	valgrind --leak-check=full --track-origins=yes ./bin/run.out -v 2 -k 3 -s 10 -i testes/entrada/entradavalgrind.txt -o testes/saida/temp.out
	valgrind --leak-check=full --track-origins=yes ./bin/run.out -v 3 -m 10 -s 10 -i testes/entrada/entradavalgrind.txt -o testes/saida/temp.out
	valgrind --leak-check=full --track-origins=yes ./bin/run.out -v 4 -s 10 -i testes/entrada/entradavalgrind.txt -o testes/saida/temp.out
	valgrind --leak-check=full --track-origins=yes ./bin/run.out -v 5 -s 10 -i testes/entrada/entradavalgrind.txt -o testes/saida/temp.out
	valgrind --leak-check=full --track-origins=yes ./bin/run.out -v 6 -s 10 -i testes/entrada/entradavalgrind.txt -o testes/saida/temp.out
	valgrind --leak-check=full --track-origins=yes ./bin/run.out -v 7 -s 10 -i testes/entrada/entradavalgrind.txt -o testes/saida/temp.out