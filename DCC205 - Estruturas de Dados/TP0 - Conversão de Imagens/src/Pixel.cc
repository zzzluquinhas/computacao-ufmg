#include "Pixel.h"

/// @brief Calcula o valor da escala de cinza a partir do RGB de um pixel
/// @return Inteiro com o valor na escala de cinza
int Pixel::getGrayscale(){
	float gray = (0.30 * this->red + 0.59 * this->green + 0.11 * this->blue)*49/255;
	return (int)gray;
}

/// @return Inteiro com o valor na escala de cinza
int Pixel::getGray(){
	return this->red;
}