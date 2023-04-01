#include "Usuario.h"

/// @brief Construtor de Usuario
/// @param i id do usuário
Usuario::Usuario(int i) : id(i), caixaDeEntrada(new ListaEmail()), prox(nullptr){
	avisoAssert((0<=id)&&(id<=1000000), "EMAIL_SERVER: ID inválido. O ID deve ser um número entre 0 e 10⁶.");
}

/// @brief Destrutor de Usuario
Usuario::~Usuario(){
	caixaDeEntrada->limpa();
	delete caixaDeEntrada;
}

/// @brief Insere um email na caixa de entrada do usuário
/// @param e email a ser inserido
void Usuario::recebeEmail(Email* e){
	this->caixaDeEntrada->insereOrdenado(e);
}

/// @brief Remove o primeiro email da lista
/// @param mensagem variável onde a mensagem do email será armazenada
/// @return true se a mensagem foi removida com sucesso, false se não
bool Usuario::lerEmail(string& mensagem){
	Email e;
	if(this->caixaDeEntrada->removePrimeiro(e)){
		mensagem = e.getMensagem();
		return true;
	}
	return false;
}

int Usuario::getId(){
	return this->id;
}