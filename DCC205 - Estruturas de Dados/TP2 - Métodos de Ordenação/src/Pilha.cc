#include "Pilha.h"

void Pilha::Empilha(ItemPilha item) {
	Node *nova = new Node(item, this->topo);
	topo = nova;
	tamanho++;
}

ItemPilha Pilha::Desempilha() {
	ItemPilha aux;
	Node *p;

	if(tamanho == 0) throw "Pilha vazia!";

	aux = topo->item;
	p = topo;
	topo = topo->prox;

	delete p;
	tamanho--;
	return aux;
}

void Pilha::Limpa() {
	while(!Vazia()) Desempilha();
}