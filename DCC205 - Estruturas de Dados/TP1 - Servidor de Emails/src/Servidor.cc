#include "Servidor.h"

/// @brief Construtor de Servidor
Servidor::Servidor(){
	usuarios = new ListaUsuario();
	quantidade = 0;
}

/// @brief Destrutor de Servidor
Servidor::~Servidor(){
	usuarios->limpa();
	delete usuarios;
}

/// @brief Adiciona uma nova Caixa de Entrada na lista
/// @param id id do usuário
void Servidor::adicionaUsuario(int id){
	if(usuarios->insere(new Usuario(id))){
		quantidade++;
		cout << "OK: CONTA " << id << " CADASTRADA" << endl;
	}
	else cout << "ERRO: CONTA " << id << " JA EXISTENTE" << endl;
}

/// @brief Remove um usuário da lista
/// @param id id do usuário
void Servidor::removeUsuario(int id){
	if(usuarios->remove(id)){
		cout << "OK: CONTA " << id << " REMOVIDA" << endl;
		quantidade--;
	}
	else cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
}

/// @brief Busca por um usuário
/// @param id id do usuário
/// @return true se encontrou a conta e leu a mensagem, false se não encontrou ou se a caixa de entrada está vazia
bool Servidor::consultaUsuario(int id){
	for(Usuario *i = usuarios->inicio; i; i=i->prox){
		if(i->getId() == id){
			string msg;
			if(i->lerEmail(msg)){
				cout << "CONSULTA " << i->getId() << ": " << msg << endl;
				return true;
			}
			else{
				cout << "CONSULTA " << id << ": CAIXA DE ENTRADA VAZIA" << endl;
				return false;
			}
		}
	}
	cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
	return false;
}

/// @brief insere um email na caixa de entrada do usuário, seguindo a ordem de prioridade
/// @param id id do usuário
/// @param prioridade prioridade da mensagem
/// @param mensagem texto da mensagem
/// @return true se a mensagem for entregue com sucesso, false se a conta não existir
bool Servidor::enviaMensagem(int id, int prioridade, string mensagem){
	for(Usuario *i = usuarios->inicio; i; i=i->prox){
		if(i->getId() == id){
			Email *e = new Email(mensagem, prioridade);
			i->recebeEmail(e);
			cout << "OK: MENSAGEM PARA " << id << " ENTREGUE" << endl;
			return true;
		}
	}
	cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
	return false;
}
