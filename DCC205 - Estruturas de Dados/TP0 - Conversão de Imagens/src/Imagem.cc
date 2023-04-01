#include "Imagem.h"

#define IMAGEM_ORIGINAL 0
#define IMAGEM_NOVA 1

/** @brief Construtor de Imagem
 * @param versao Versão do arquivo
 * @param largura Largura da imagem em pixels
 * @param altura Altura da imagem em pixels
 * @param range Alcance de cor da imagem
 * @param matriz Matriz de pixels que constitui a imagem
**/
Imagem::Imagem(string versao, int largura, int altura, int range, Pixel **matriz) : versao(versao), largura(largura), altura(altura), range(range), matriz(matriz) {
}

/// @brief Construtor de Imagem
/// @param nomeArquivo Nome do arquivo de imagem do qual serão extraídos os dados
Imagem::Imagem(string nomeArquivo){
    fstream arquivo;

    arquivo.open(nomeArquivo);
    erroAssert(arquivo.is_open(), "PPMtoPGM - Arquivo não encontrado");
    
    arquivo >> this->versao >> this->largura >> this->altura >> this->range;
    
    this->matriz = new Pixel*[this->altura];
    for(int i=0; i<this->altura; i++){
    
        this->matriz[i] = new Pixel[this->largura];
        for(int j=0; j<this->largura; j++){

            int r,g,b;
            arquivo >> r >> g >> b;
            erroAssert(((r<=this->range)&&(g<=this->range)&&(b<=this->range)),"PPMtoPGM - Pixel do arquivo ultrapassa limite estabelecido");
            
            this->matriz[i][j] = Pixel(r,g,b);
            ESCREVEMEMLOG((long int)(&this->matriz[i][j]),sizeof(Pixel),IMAGEM_ORIGINAL);
            
        }
    }
    arquivo.close();
}

Imagem::~Imagem(){
    //for(int i=0; i<this->largura; i++) delete[] this->matriz[i];
    //delete[] this->matriz;
}

/// @brief  Converte a imagem de PPM (colorida) para PGM (escala de cinza)
/// @return variável tipo Imagem em escala de cinza
Imagem Imagem::PPMtoPGM(){
    Pixel** img2 = new Pixel*[this->altura];
    for (int i = 0; i < this->altura; i++){

        img2[i] = new Pixel[this->largura];
        for (int j = 0; j < this->largura; j++){

            int gray = this->matriz[i][j].getGrayscale();
            LEMEMLOG((long int)(&this->matriz[i][j]),sizeof(int),IMAGEM_ORIGINAL);
            img2[i][j] = Pixel(gray);
            ESCREVEMEMLOG((long int)(&this->matriz[i][j]),sizeof(Pixel),IMAGEM_NOVA);

        }

    }

    return Imagem("P2", this->largura, this->altura, 49, img2);
}