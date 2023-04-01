#include "ListaEmail.h"

class Usuario{
private:
	int id;
public:
	ListaEmail *caixaDeEntrada;
	Usuario *prox;
	Usuario(int i);
	~Usuario();
	void recebeEmail(Email* e);
	bool lerEmail(string& mensagem);
	int getId();
};