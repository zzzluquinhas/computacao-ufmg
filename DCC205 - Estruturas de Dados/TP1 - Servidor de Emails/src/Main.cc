#include "Servidor.h"

int main(){

	iniciaMemLog("testes/funcaoEntrega/logs/teste50k.out");

	Servidor server = Servidor();

	string opcao, mensagem="", temp;
	int id, prioridade;

	while(cin >> opcao){
		if(opcao == "CADASTRA"){
			cin >> id;
			server.adicionaUsuario(id);
		}
		else if(opcao == "REMOVE"){
			cin >> id;
			server.removeUsuario(id);
		}
		else if(opcao == "ENTREGA"){
			cin >> id >> prioridade;
			mensagem.clear();
			while(true){
				cin >> temp;
				if(temp == "FIM") break;
				mensagem += temp + " ";
			}
			server.enviaMensagem(id, prioridade, mensagem);
		}
		else if(opcao == "CONSULTA"){
			cin >> id;
			server.consultaUsuario(id);
		}
	}
	
	finalizaMemLog();

	return 0;
}
