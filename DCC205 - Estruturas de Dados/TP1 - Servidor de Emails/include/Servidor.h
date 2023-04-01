#include "ListaUsuario.h"

class Servidor{
private:
	ListaUsuario *usuarios;
	int quantidade;
public:
	Servidor();
	~Servidor();
	void adicionaUsuario(int id);
	void removeUsuario(int id);
	bool consultaUsuario(int id);
	bool enviaMensagem(int id, int prioridade, string mensagem);
};
