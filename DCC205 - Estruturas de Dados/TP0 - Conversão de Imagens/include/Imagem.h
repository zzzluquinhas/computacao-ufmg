#ifndef IMAGEM_H
#define IMAGEM_H

#include "Pixel.h"
#include <fstream>

class Imagem{
public:
    int largura, altura, range;
    Pixel **matriz;
    string versao;
    Imagem(string versao, int largura, int altura, int range, Pixel **matriz);
    Imagem(string nomeArquivo);
    ~Imagem();
    Imagem PPMtoPGM();
};

#endif