# Trabalho Prático 3 - Centro de Distribuição
Esse trabalho aplica conceitos de programação dinâmica através do seguinte problema:

Um certo centro de distribuição tem conexão com várias fábricas de ligas metálicas e seus clientes e deseja otimizar sua logística. Cada fábrica produz ligas metálicas de tamanhos diferentes, e cada cliente possui uma demanda específica de ligas, medida em metros. O objetivo é minimizar o número de ligas necessárias para atender à demanda, levando em
consideração os tamanhos disponíveis nas fábricas.

# Funcionamento do programa
A entrada do programa consiste em um arquivo de texto com o seguinte formato:
- A primeira linha contém um inteiro T que representa o número de testes que será feito;
- A segunda linha contém dois inteiros separados por espaço:
	- O primeiro, $1 \leq N \leq 1000$, representa a quantidade de tamanhos de ligas metálicas disponíveis (ou o número de fábricas);
	- O segundo, $1 \leq W \leq 1000000$, representa a demanda do cliente em metros.
- A terceira linha contém uma sequência de inteiros $1 \leq li \leq 1000$ separados por espaço, que representam os tamanhos de ligas disponíveis, em metros.

A saída do programa consiste em um arquivo de texto com T linhas, cada uma contendo um inteiro que representa o número mínimo de ligas necessárias para atender à demanda de cada teste.

Mais detalhes do programa podem ser vistos no [relatório](relatorio.pdf).