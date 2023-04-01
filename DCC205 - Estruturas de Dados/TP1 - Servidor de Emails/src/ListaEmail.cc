#include "ListaEmail.h"

int ListaEmail::getTamanho(){
	return this->tamanho;
}

void ListaEmail::limpa(){
	for(Email *i=inicio; inicio; inicio = i){
		i = i->prox;
		delete inicio;
	}
	tamanho=0;
}

/// @brief Insere um email na lista seguindo a ordem de prioridade
/// @param e email a ser inserido
void ListaEmail::insereOrdenado(Email* e){
	if(!inicio){
		inicio = e;
		fim = e;
	}
	else{
		Email *atual = inicio;
		Email *anterior = nullptr;

		// se o email a ser inserido tiver prioridade maior que o primeiro, insere no início
		if(e->getPrioridade() > atual->getPrioridade()){
			e->prox = inicio;
			inicio = e;
		}
		else{
			// percorre a lista até o final ou até encontrar um email com prioridade menor
			while(atual && (e->getPrioridade() <= atual->getPrioridade())){
				anterior = atual;
				atual = atual->prox;
			}
			if(!atual) fim = e; // percorreu até o final da lista
			anterior->prox = e;
			e->prox = atual;
		}
	}
	tamanho++;
}

/// @brief Remove e retorna o primeiro email da lista
/// @param e endereço onde será armazenado o email removido
/// @return true se o email foi removido com sucesso, false se a lista estiver vazia 
bool ListaEmail::removePrimeiro(Email& e){
	if(!inicio) return false;
	Email *aux = inicio;
	e = *inicio;
	inicio = inicio->prox;
	delete aux;
	tamanho--;
	return true;
}
