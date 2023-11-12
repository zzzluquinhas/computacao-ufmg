# Trabalho Prático 1 - Damas

O trabalho consiste em uma versão simplificada do jogo de Damas. Nessa versão, as damas ganham apenas o poder de se moverem em todas as direções, mas continuam limitadas a uma casa por jogada. Além disso, peças comuns não podem se mover para trás, nem se isso for realizado em um movimento de captura.

# Funcionamento do programa
A primeira linha da entrada do programa contém um inteiro, podendo ser 8, 10 ou 12, que indica o tamanho do tabuleiro. As próximas N linhas contêm informação sobre a disposição das peças sobre o tabuleiro, sendo cada caractere representando uma casa. Os possíveis valores obtidos são:
- 'o' - Casa preta vazia;
- 'p' - Casa preta com peça preta;
- 'b' - Casa preta com peça branca;
- ' ' - Casa branca vazia.
Vale lembrar que as peças serão dispostas apenas em casas pretas, por causa das jogadas em um jogo de damas serem na diagonal.
As próximas linhas da entrada são quatro inteiros $x_o\ y_o\ x_f\ y_f$, que indicam coordenadas de início e fim de uma jogada.
Por fim, uma linha contendo 0 0 0 0 indica o fim da sequência de ações.

A saída do programa diz o placar com as peças capturadas de cada time, além de anunciar o vencedor.