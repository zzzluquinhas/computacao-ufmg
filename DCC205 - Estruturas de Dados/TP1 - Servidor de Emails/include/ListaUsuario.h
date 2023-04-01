#include "Usuario.h"

class ListaUsuario{
private:
	int tamanho;
public:
	Usuario *inicio = nullptr, *fim = nullptr;

	ListaUsuario() : tamanho(0), inicio(nullptr), fim(nullptr) {};
	void limpa();
	bool insere(Usuario* cx);
	bool remove(int id);
	int getTamanho();
};