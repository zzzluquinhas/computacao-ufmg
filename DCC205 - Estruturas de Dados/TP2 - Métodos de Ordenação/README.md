# Trabalho Prático 2 - Métodos de Ordenação

Esse trabalho tem como objetivo analisar o desempenho de diferentes métodos de ordenação, observando fatores como tempo de execução, uso e localidade de memória e número de cópias de registros realizadas.

Os métodos de ordenação analisados foram:

* **Quicksort Recursivo:** Versão mais conhecida do quicksort, que utiliza recursividade para dividir e ordenar o vetor

* **Quicksort Mediana:** Essa versão do quicksort contém uma alteração na escolha do pivô do particionamento. Em vez de selecionar o pivô como sendo o elemento do meio do vetor, o programa escolhe aleatoriamente *k* elementos do vetor (sendo *k* um parâmetro passado pelo usuário), calcula a mediana desses *k* elementos e essa mediana é escolhida como o pivô da partição. Depois disso, o programa segue similar ao Quicksort Recursivo. Ele tem como objetivo reduzir a probabilidade do pivô escolhido ser o maior ou menor elemento do vetor (pior caso).

* **Quicksort Seleção:** Essa versão do quicksort recebe, além do vetor e do tamanho, uma constante *m*, que corresponde a um limiar. Enquanto o tamanho do vetor for maior que o limiar, a função utilizará a mesma lógica do Quicksort Recursivo para ordená-lo. Quando o tamanho do vetor for
menor que esse limiar, ela utilizará o Selection Sort para ordenar aquela partição.

* **Quicksort Não-Recursivo:** Essa é uma versão do Quicksort que não utiliza recursividade, mas sim uma estrutura de Pilha Encadeada para ordenar as partições do vetor.

* **Quicksort Empilha Inteligente:** A última versão do Quicksort implementada é bastante similar ao Quicksort não Recursivo, porém ao invés de inserir a partição esquerda e depois a direita, o programa insere a menor das duas partições na pilha em cada iteração.

Mais detalhes sobre as implementações e análises dos algoritmos podem ser vistos no [relatório](relatorio.pdf).