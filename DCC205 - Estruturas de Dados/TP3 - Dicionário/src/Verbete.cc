#include "Verbete.h"

Verbete::~Verbete() {
	delete significados;
}

void Verbete::InsereSignificado(std::string s) {
	significados->Insere(s);
}

void Verbete::InsereSignificado(ListaSignificados *s) {
	Significado *aux = s->inicio;
	while(aux) {
		significados->Insere(aux->getItem());
		aux = aux->prox;
	}
}

void Verbete::Imprime() {
	std::cout << palavra << " (" << tipo << ")"
	          << "\n";
	significados->Imprime();
}

std::string Verbete::Saida() {
	std::string saida = palavra + " (" + tipo + ")\n";
	saida += significados->Saida();
	return saida;
}

bool Verbete::Vazio() {
	return palavra == " ";
}

//--------------------------------------------------------------

ListaVerbete::~ListaVerbete() {
	Limpa();
}

void ListaVerbete::InsereOrdenado(Verbete *v) {
	Verbete *novo = Pesquisa(v);
	if(!novo) {
		// Se o verbete ainda não exitse, insere
		novo = v;
		if(!inicio) {
			inicio = fim = novo;
		} else {
			Verbete *aux = inicio;
			Verbete *ant = nullptr;
			while(aux && aux->palavra < novo->palavra) {
				ant = aux;
				aux = aux->prox;
			}
			if(!ant) {
				novo->prox = inicio;
				inicio = novo;
			} else {
				novo->prox = aux;
				ant->prox = novo;

				if(ant == fim) {
					fim = novo;
				}
			}
		}
	} else {
		// Se já existe, adiciona o(s) novo(s) significado(s) a ele
		novo->InsereSignificado(v->significados);
		delete v;
	}
	tamanho++;
}

void ListaVerbete::Imprime() {
	Verbete *aux = inicio;
	while(aux) {
		aux->Imprime();
		aux = aux->prox;
	}
}

std::string ListaVerbete::Saida() {
	std::string saida = "";
	Verbete *aux = inicio;
	while(aux) {
		saida += aux->Saida();
		aux = aux->prox;
	}
	return saida;
}

void ListaVerbete::ImprimeSaida() {
	std::ofstream saida;
	saida.open(args::nomeSaida, std::ios::out | std::ios::app);

	Verbete *aux = inicio;
	while(aux) {
		saida << aux->Saida();
		aux = aux->prox;
	}
	saida.close();
}

void ListaVerbete::RemoveVerbeteComSignificado() {
	Verbete *aux = inicio, *ant = nullptr, *next;
	while(aux) {
		next = aux->prox;
		if(!aux->significados->Vazia()) {
			if(ant) {
				ant->prox = next;
			} else {
				inicio = next;
			}
			if(aux == fim) {
				fim = ant;
			}
			delete aux;
			aux = next;
		} else {
			ant = aux;
			aux = next;
		}
	}
}

Verbete *ListaVerbete::Pesquisa(Verbete *v) {
	Verbete *aux = inicio;
	while(aux) {
		if(aux->palavra == v->palavra && aux->tipo == v->tipo) {
			return aux;
		}
		aux = aux->prox;
	}
	return nullptr;
}

void ListaVerbete::Limpa() {
	for(Verbete *i = inicio; inicio; inicio = i) {
		i = i->prox;
		delete inicio;
	}
	tamanho = 0;
}