#include "Hash.h"

Hash::Hash(int tam) {
	tamanho = tam;
	tabela = new ListaVerbete[tamanho];
}

Hash::~Hash() {
	delete[] tabela;
}

Verbete* Hash::Pesquisa(Verbete* v) {
	int pos = Hashing(v->palavra);
	return tabela[pos].Pesquisa(v);
}

void Hash::Insere(Verbete* v) {
	int pos = Hashing(v->palavra);
	tabela[pos].InsereOrdenado(v);
}

void Hash::Imprime() {
	for(int i = 0; i < tamanho; i++) {
		if(!tabela[i].Vazio()) {
			std::cout << "Tabela " << i << ":\n";
			tabela[i].Imprime();
		}
	}
}

void Hash::ImprimeSaida() {
	std::ofstream saida;
	saida.open(args::nomeSaida, std::ios::app | std::ios::out);
	avisoAssert(saida.is_open(), "Dicionario - Não foi possível abrir o arquivo de saída indicado. Saída salva em bin/saida.out");
	if(!saida.is_open()) {
		args::nomeSaida = "bin/saida.out";
		saida.open(args::nomeSaida, std::ios::app | std::ios::out);
	}
	saida.close();
	for(int i = 0; i < tamanho; i++) {
		if(!tabela[i].Vazio()) {
			tabela[i].ImprimeSaida();
		}
	}
}

void Hash::RemoveVerbeteComSignificado() {
	for(int i = 0; i < tamanho; i++) {
		tabela[i].RemoveVerbeteComSignificado();
	}
}

int Hash::Hashing(std::string chave) {
	int pos;
	pos = (tolower(chave[0]) - 'a') * 26 * 26;
	if(chave.length() > 1) pos += (tolower(chave[1]) - 'a') * 26;
	if(chave.length() > 2) pos += (tolower(chave[2]) - 'a');
	return pos % tamanho;
}