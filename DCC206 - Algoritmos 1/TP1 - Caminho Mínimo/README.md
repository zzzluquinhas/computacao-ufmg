# Trabalho prático 1 - Aritmofobia
Esse trabalho explora noções de caminho mínimo em grafos, através do seguinte problema proposto:

Uma certa pessoa sofre de um transtorno peculiar: ela tem fobia a números ímpares. Felizmente, esse problema não a impediu de viajar pelo país inteiro. Queremos criar um algoritmo para ajudar essa pessoa a planejar melhor suas viagens. Queremos criar um algoritmo que determine o menor caminho entre duas cidades, dado um grafo que representa a rede de cidades e estradas que interconectam a região. No entanto, o algoritmo deve levar em consideração as seguintes restrições:
1. As viagens entre duas cidades adjacentes só ocorrem se a estrada que conecta as duas cidades tiver comprimento par;
2. O caminho traçaado pelo algoritmo deve passar por um número par de estradas.

## Funcionamento do programa
A primeira linha de uma entrada de teste contém o número de cidades ($2\leq C\leq 10000$) e estradas ($1\leq E\leq 100000$) conectando os pares de cidades, separados por espaço.
As próximas $E$ linhas contém as conexões entre cidades no formato $C_O C_D D$, onde os valores são números inteiros que representam uma cidade de origem, uma cidade de destino e a distância, respectivamente. Essas variáveis tem as seguintes restrições: $1\leq C_O$, $C_D\leq C$, $C_O\neq C_D$ e $0<D\leq 10000$. Além disso, todas as estradas são de mão dupla, a cidade de origem inicial sempre tem valor 1 e a cidade de destino final sempre tem valor $C$.

A saída do programa consiste de um número inteiro representando o tamanho do caminho mínimo. Se o caminho mínimo não existir, ele imprime -1.

Mais detalhes do programa podem ser vistos no [relatório](relatorio.pdf).