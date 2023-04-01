#include "ArvAVL.h"

#define LARGURA 20
#define MAX_ALFABETO 26 * 26 * 26

using namespace std;

/// @brief Recebe os argumentos da linha de execução do programa
void parseArgs(int argc, char *argv[]) {
	int opcao;
	while((opcao = getopt(argc, argv, "i:o:t:l:")) != -1) {
		switch(opcao) {
			case 'i':
				args::nomeEntrada = optarg;
				break;

			case 'o':
				args::nomeSaida = optarg;
				break;

			case 't':
				args::hashOuArv = optarg;
				break;

			case 'l':
				args::nomeMemLog = optarg;

				break;
		}
	}
}

int main(int argc, char *argv[]) {
	parseArgs(argc, argv);

	ifstream entrada;
	entrada.open(args::nomeEntrada);
	erroAssert(entrada.is_open(), "Dicionario - Não foi possível abrir o arquivo de entrada. Verifique se ele existe ou está no caminho indicado");

	avisoAssert((args::nomeSaida.size() > 0), "Dicionario - Não foi lido um nome para o arquivo de saída. arquivo padrão definido em ./bin/saida.out");
	if(args::nomeSaida.size() <= 0) args::nomeSaida = "bin/saida.out";

	string linhas;

	// 1. Criar o dicionário, indicando o número máximo de verbetes a ser inseridos
	// (que pode ser o número de linhas do arquivo de entrada).
	Dicionario *dicionario = nullptr;

	if(args::hashOuArv == "hash") {
		dicionario = new Hash(MAX_ALFABETO);
	} else if(args::hashOuArv == "arv") {
		dicionario = new ArvAVL();
	} else {
		erroAssert(false, "Dicionario - Não foi lido um tipo de estrutura válido para o dicionário. Verifique se o parâmetro -t foi passado corretamente, com valores hash ou arv");
	}

	// 2. Inserir no dicionário criado todos os verbetes e seus significados a partir do arquivo de entrada.
	// Note que um verbete pode ter mais de um significado e a estrutura de dados deve permitir o armazenamento
	// dos potencialmente vários significados de um verbete.
	while(getline(entrada, linhas)) {
		char tipo;
		string palavra, definicao = "";
		istringstream iss(linhas);
		iss >> tipo >> palavra;

		if(tipo != 'v' && tipo != 'n' && tipo != 'a') {
			string erro = "Dicionario - Tipo do verbete " + palavra + " inválido. Verifique se o arquivo de entrada está no formato correto";
			avisoAssert(tipo == 'v' || tipo == 'n' || tipo == 'a', erro.c_str());
		} else if(palavra.length() == 0) {
			avisoAssert(palavra.length() > 0, "Dicionario - Palavra vazia inserida. Verifique se o arquivo de entrada está no formato correto");
		} else {
			getline(iss, definicao);
			definicao.erase(0, 1);
			palavra.pop_back();  // remove [] da palavra
			palavra.erase(palavra.begin());

			Verbete *verbete = new Verbete(tipo, palavra);
			if(definicao != "") verbete->InsereSignificado(definicao);
			dicionario->Insere(verbete);
		}
	}
	entrada.close();

	// 3. Imprimir o dicionário resultante em ordem alfabética dos verbetes e ordem de
	// inserção dos significados dos verbetes.
	ofstream saida(args::nomeSaida, ios::out | ios::trunc);
	saida.close();
	dicionario->ImprimeSaida();

	// 	4. Remover todos os verbetes que tem pelo menos um significado, pois a empresa que
	// está construindo o dicionário quer saber quais verbetes ainda tem que ser complementados
	// com os seus significados.
	dicionario->RemoveVerbeteComSignificado();

	// 5. Imprimir novamente o dicionário, que deve conter apenas os verbetes que não tem
	// significado registrado ainda.
	dicionario->ImprimeSaida();

	// 6. Destruir o dicionário.
	delete dicionario;

	return 0;
}