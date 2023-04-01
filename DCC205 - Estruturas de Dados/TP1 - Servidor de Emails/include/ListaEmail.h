#include "Email.h"

class ListaEmail{
private:
	int tamanho;
public:
	Email *inicio = nullptr, *fim = nullptr;

	ListaEmail() : tamanho(0), inicio(nullptr), fim(nullptr) {}
	int getTamanho();
	void limpa();
	void insereOrdenado(Email* e);
	bool removePrimeiro(Email& e);
};