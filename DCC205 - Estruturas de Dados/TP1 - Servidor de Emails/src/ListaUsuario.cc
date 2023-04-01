#include "ListaUsuario.h"

int ListaUsuario::getTamanho(){
	return tamanho;
}

void ListaUsuario::limpa(){
	for(Usuario *i = inicio; inicio; inicio = i){
		i = i->prox;
		delete inicio;
	}
	tamanho=0;
}

/// @brief Insere um novo usuário ao final da lista
/// @param usr usuário a ser inserido
/// @return true se for inserido com sucesso, false se já houver um usuário existente com o mesmo id
bool ListaUsuario::insere(Usuario* usr){
	if(!inicio){
		inicio = usr;
		fim = usr;
	}
	else{
		Usuario *atual = inicio;
		while(atual){
			if(atual->getId() == usr->getId()) return false;
			atual = atual->prox;
		}
		fim->prox = usr;
		fim = usr;
	}
	tamanho++;
	return true;
}

/// @brief Remove um usuário da lista
/// @param id id do usuário a ser removido
/// @return true se for removido com sucesso, false se o usuário não existir
bool ListaUsuario::remove(int id){
	Usuario *atual = inicio, *anterior = nullptr;
	while(atual && atual->getId() != id){
		anterior = atual;
		atual = atual->prox;
	}
	if(!atual) return false;
	if(atual == inicio) inicio = inicio->prox;
	if(atual == fim) fim = anterior;
	if(anterior) anterior->prox = atual->prox;
	delete atual;
	tamanho--;
	return true;
}