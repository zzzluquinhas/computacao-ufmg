#include "Email.h"

/// @brief Construtor de Email vazio
Email::Email(){
	this->prox = nullptr;
}

/// @brief Destrutor de Email
Email::~Email(){

}

/// @brief Construtor de Email
/// @param msg mensagem do email
/// @param pri prioridade do email
Email::Email(string msg, int pri) : mensagem(msg), prox(nullptr) {
	avisoAssert((pri>=0)&&(pri<=9),"EMAIL_SERVER: Prioridade do email inválida. A prioridade deve ser um número entre 0 e 9. A prioridade foi reajustada para o limite mais próximo");
	if(pri<0) pri = 0;
	else if(pri>9) pri = 9;
	this->prioridade = pri;
}

string Email::getMensagem(){
	return this->mensagem;
}

int Email::getPrioridade(){
	return this->prioridade;
}