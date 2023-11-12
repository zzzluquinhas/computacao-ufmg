# Trabalho Prático 2 - Sistema de Controle de Estoque
Esse trabalho tem como objetivo praticar a manipulação de arquivos em C e modularização de funções. Ele consiste na implementação de um sistema de controle de estoque, que receberá como entrada a lista de produtos em um arquivo de extensão TXT. O programa inicialmente lê as entradas contendo informações sobre os produtos, armazena essas entradas em uma estrutura interna (em memória) e realiza as operações solicitadas.

# Funcionamento do programa
A entrada possui várias linhas, onde cada linha tem detalhes sobre determinado produto.

- A primeira linha possui a quantidade (Q) de produtos que constam na lista ($1 \leq Q \leq 1000$);
- As próximas 5*Q linhas representam os dados de cada produto, na seguinte ordem (Um dado por linha):
	- Código
	- Nome
	- Quantidade
	- Preço
	- Estado

O programa deve ser executado a partir da linha de comando com os seguintes parâmetros:
.\tp2 \[param1] \[param2] \[param3]

**\[param1] (Obrigatório):** Nome do arquivo de entrada.
Ex.: input.txt

**\[param2] (Obrigatório):** Número correspondente a função a ser executada, a saber:
1. Gerar relatório de estoque
2. Pesquisar por produto pelo código
3. Listar dados do produto com menor quantidade em estoque
4. Listar produtos por estado
5. Encontrar produto com menor quantidade em estoque do estado
6. Calcular a quantidade total de itens no estoque

**\[param3] (Opcional):** Nome do arquivo de saída (se função 1), código do produto desejado
(se função 2), ou sigla do estado desejado (funções 4 e 5).

A saída esperada para cada uma das opções é:
1. Gerar relatório de estoque:
O programa deve gerar um arquivo TXT, com o nome passado pelo param3, salvo no mesmo diretório de execução. Deve-se salvar a lista de todos os produtos COM OS NOMES EM ORDEM ALFABÉTICA, com os mesmos dados da entrada, um dado por linha (Código, Nome, Quantidade, Preço e Estado).
2. Pesquisar por produto pelo código:
O programa deverá imprimir na saída padrão (tela) todos os dados do produto que tenha o código igual ao informado no param3, um dado por linha (Código, Nome, Quantidade, Preço e Estado).
3. Listar dados do produto com menor quantidade em estoque:
O programa deverá imprimir na saída padrão (tela) todos os dados do produto que possui a menor quantidade em estoque, um dado por linha (Código, Nome, Quantidade, Preço e Estado).
4. Pesquisar por produto pelo estado:
O programa deverá imprimir na saída padrão (tela) a lista de produtos do estado informado no param3, EM ORDEM ALFABÉTICA, com todos os dados de cada produto, um dado por linha (Código, Nome, Quantidade, Preço e Estado).
5. Encontrar produto com menor quantidade em estoque do estado:
O programa deverá imprimir na saída padrão (tela) o produto do estado informado no param3 que possui a menor quantidade em estoque, um dado por linha (Código, Nome, Quantidade, Preço e Estado).
6. Calcular a quantidade total de itens no estoque:
O programa deverá imprimir na saída padrão (tela) a quantidade total de itens. Para o cálculo da quantidade total de itens do estoque deve-se somar a quantidade de cada produto, recebida no arquivo de entrada. 
