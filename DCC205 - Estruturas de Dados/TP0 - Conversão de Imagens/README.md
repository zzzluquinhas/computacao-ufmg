# Trabalho Prático 0

Esse trabalho tem o objetivo de revisar conceitos de programação visto em matérias anteriores e apresentar as bibliotecas de análise de memória.

O objetivo do trabalho consiste na conversão de uma imagem colorida para tons de cinza. Essas imagens são um resultado geral de um cálculo da intensidade da luz em cada pixel da imagem por cada faixa do espectro de luz visível.

A fórmula utilizada para calcular o tom de cinza Y de cada pixel, utilizando os valores RGB (vermelho, verde e azul) da imagem original é apresentada abaixo:

$$
	Y = \frac{49}{255}(0.3 \cdot R + 0.59 \cdot G + 0.11 \cdot B)
$$

O programa processa uma imagem de entrada no formato ``.ppm`` (ASCII, P3) com representação de 8 bits por componente de cor (R, G, e B) de cada pixel (valores podem ir de 0 a 255). A imagem de saída em tons de cinza é gerada no formato ``.pgm`` (ASCII, P2) com no máximo 50 tons de cinza (valores podem ir de 0 a 49). A página [Netpbm - Wikipédia](http://en.wikipedia.org/wiki/Netpbm_format) contém mais informações sobre esses formatos de imagem.

Mais detalhes sobre o projeto podem ser vistos no [relatório](relatorio.pdf).

