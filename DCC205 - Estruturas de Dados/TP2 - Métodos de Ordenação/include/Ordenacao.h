#include <getopt.h>
#include <sys/resource.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

#include "Globais.h"
#include "Pilha.h"
#include "Registro.h"
#include "memlog.h"
#include "msgassert.h"

/// @brief Troca dois elementos do tipo Item
void Troca(Item *a, Item *b, int id);

/// @brief Divide o vetor ao meio e coloca valores menores à esquerda e maiores à direita
/// @param vetor vetor a ser particionado
/// @param inicio posição inicial do vetor
/// @param fim posição final do vetor
/// @param i ponteiro onde será guardado o valor à esquerda do pivô
/// @param j ponteiro onde será guardado o valor à direita do pivô
/// @param pivo pivô utilizado na partição (se não indicado, será definido à metade do vetor)
void Particao(Item *vetor, int inicio, int fim, int *i, int *j, int pivo);

/// @brief Função auxiliar de @ref QuickSortRecursivo()
/// @param vetor vetor que será ordenado
/// @param inicio posição inicial do vetor
/// @param fim posição final do vetor
void OrdenaQuickSortRecursivo(Item *vetor, int inicio, int fim);

/// @brief Ordenação do tipo quicksort utilizando recursividade
/// @param vetor vetor que será ordenado
/// @param tam tamanho do vetor
void QuickSortRecursivo(Item *vetor, int tam);

/// @brief Ordenação do tipo selection sort
/// @param vetor vetor que será ordenado
/// @param inicio posição inicial do vetor
/// @param fim posição final do vetor
void SelectionSort(Item *vetor, int inicio, int fim);

/// @brief Função auxiliar de @ref QuickSortSelecao()
/// @param vetor vetor que será ordenado
/// @param inicio posição inicial do vetor
/// @param fim posição final do vetor
void OrdenaQuickSortSelecao(Item *vetor, int inicio, int fim);

/// @brief Ordenação do tipo quicksort, porém se o vetor tiver tamanho menor que k, utiliza a selection sort
/// @param vetor vetor que será ordenado
/// @param tam tamanho do vetor
void QuickSortSelecao(Item *vetor, int tam);

/// @brief Cria um vetor do tamanho do limiar, preenche com números aleatórios do vetor recebido e calcula a mediana desses valores
/// @param vetor vetor de elementos do tipo Item
/// @param inicio posição inicial do vetor
/// @param fim posição final do vetor
/// @return chave do Item que representa a mediana calculada
int Mediana(Item *vetor, int inicio, int fim);

/// @brief Função auxiliar de @ref QuickSortMediana()
/// @param vetor vetor que será ordenado
/// @param inicio posição inicial do vetor
/// @param fim posição final do vetor
void OrdenaQuickSortMediana(Item *vetor, int inicio, int fim);

/// @brief Ordenação do tipo quicksort que particiona o vetor em uma mediana calculada com n elementos aleatórios do vetor
/// @param vetor vetor que será ordenado
/// @param tam tamanho do vetor
void QuickSortMediana(Item *vetor, int tam);

/// @brief Ordenação do tipo quicksort sem utilizar recursividade, utilizando pilha
/// @param vetor vetor que será ordenado
/// @param tam tamanho do vetor
void QuickSortNaoRecursivo(Item *vetor, int tam);

/// @brief Ordenação quicksort não recursiva que processa primeiro a menor partição
/// @param vetor vetor que será ordenado
/// @param tam tamanho do vetor
void QuickSortInteligente(Item *vetor, int tam);

/// @brief Refaz o vetor durante a execução da ordenação do tipo heapsort
/// @param inicio posição inicial do vetor
/// @param fim posição final do vetor
/// @param vetor vetor que será reconstruído
void Refaz(Item *vetor, int inicio, int fim);

/// @brief Ordenação do tipo heapsort
/// @param vetor vetor que será ordenado
/// @param tam tamanho do vetor
void HeapSort(Item *vetor, int tam);

/// @brief Junta duas metades do vetor ordenando-as
/// @param vetor vetor que será juntado
/// @param inicio início do vetor
/// @param meio meio do vetor
/// @param fim fim do vetor
void Junta(Item *vetor, int inicio, int meio, int fim);

/// @brief Função auxiliar de @ref MergeSort()
/// @param inicio posição inicial do vetor
/// @param fim posição final do vetor
/// @param vetor vetor que será ordenado
void OrdenaMergeSort(Item *vetor, int inicio, int fim);

/// @brief Ordenação do tipo mergesort
/// @param vetor vetor que será ordenado
/// @param tam tamanho do vetor
void MergeSort(Item *vetor, int tam);