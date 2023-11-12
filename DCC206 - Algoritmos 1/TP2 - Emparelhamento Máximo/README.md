# Trabalho Prático 2 - Desemprego
Esse trabalho busca aplicar o algoritmo de Emparelhamento Máximo através do seguinte problema:

Uma grande empresa, dona de uma rede social para buscar empregos, está passando por problemas pois a alocação de vagas não está acontecendo de modo satisfatório. A empresa já tem um algoritmo que determina se um certo candidato está apto para a vaga, na forma de um grafo bipartido onde uma aresta candidato-vaga existe se o candidato atende aos requisitos da vaga. O objetivo é desenvolver primeiro uma solução gulosa, de baixa complexidade, que encontra uma solução rapidamente e, depois, desenvolver uma solução exata. Após a implementação, devem ser feitos comentários sobre as vantagens e desvantagens de cada abordagem.

# Funcionamento do programa
A primeira linha da entrada do programa é composta de três inteiros separados por espaço, $U E Q$, representando o número de usuários ($2\leq U \leq 10000$), o número de ofertas de emprego ($1\leq E \leq 10000$) e o número de qualificações usuário emprego ($1\leq Q \leq (U\times E)$). As próximas $Q$ linhas descrevem as qualificações, representadas pelo nome do usuário seguido pelo nome da vaga, como strings separadas por espaço.

A saída do programa imprime a quantidade de pares feitos, da seguinte forma: na primeira linha, "Guloso: " seguido da solução gulosa e, na segunda linha, "Exato: " seguido da solução exata.

Mais detalhes do programa podem ser vistos no [relatório](relatorio.pdf).