#include "Significado.h"
ListaSignificados::~ListaSignificados() {
	Limpa();
}

void ListaSignificados::Insere(std::string info) {
	Significado *novo = new Significado(info);
	if(!inicio) {
		inicio = fim = novo;
	} else {
		fim->prox = novo;
		fim = novo;
	}
	tamanho++;
}

void ListaSignificados::Imprime() {
	Significado *aux = inicio;
	for(int i = 1; aux; i++) {
		std::cout << i << ". " << aux->getItem() << "\n";
		aux = aux->prox;
	}
}

std::string ListaSignificados::Saida() {
	std::string saida = "";
	Significado *aux = inicio;
	for(int i = 1; aux; i++) {
		saida += std::to_string(i) + ". " + aux->getItem() + "\n";
		aux = aux->prox;
	}
	return saida;
}

void ListaSignificados::Limpa() {
	for(Significado *i = inicio; i; inicio = i) {
		i = i->prox;
		delete inicio;
		tamanho--;
	}
	fim = nullptr;
	erroAssert(tamanho == 0 && !inicio, "Dicionario - Erro na limpeza do dicionario");
}

bool ListaSignificados::Vazia() {
	return inicio == nullptr;
}