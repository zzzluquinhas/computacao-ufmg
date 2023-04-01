#include "Ordenacao.h"

#define LARGURA 20

using namespace std;

/// @brief Chama a função de ordenação escolhida
/// @param vet vetor que será ordenado
/// @param tam tamanho do vetor
void chamaOrdenacao(Item *vet, int tam) {
	reg::copias = 0;
	reg::comparacoes = 0;

	avisoAssert(args::versao >= RECURSIVO && args::versao <= HEAP, "Ordenacao - Versão da ordenação não informada ou informada incorretamente. O valor deve estar entre 1 e 7. Selecionado por padrão a ordenação Quicksort Recursivo");
	if(args::versao < RECURSIVO || args::versao > HEAP) args::versao = RECURSIVO;

	avisoAssert(args::seed > 0, "Seed não informada ou informada incorretamente. O valor foi automaticamente ajustado para 10");
	if(args::seed <= 0) args::seed = 10;

	switch(args::versao) {
		case RECURSIVO:
			QuickSortRecursivo(vet, tam);
			break;

		case MEDIANA:
			avisoAssert(args::medianas > 0, "Ordenação - Parâmetro k da função Quicksort Mediana não foi informado corretamente. O valor foi automaticamente ajustado para 3");
			if(args::medianas <= 0) args::medianas = 3;
			QuickSortMediana(vet, tam);
			break;

		case SELECAO:
			avisoAssert(args::limiar > 0, "Ordenação - Parâmetro m da função Quicksort Seleção não foi informado corretamente. O valor foi automaticamente ajustado para 10");
			if(args::limiar <= 0) args::limiar = 10;
			QuickSortSelecao(vet, tam);
			break;

		case NAO_RECURSIVO:
			QuickSortNaoRecursivo(vet, tam);
			break;

		case INTELIGENTE:
			QuickSortInteligente(vet, tam);
			break;

		case MERGE:
			MergeSort(vet, tam);
			break;

		case HEAP:
			HeapSort(vet, tam);
			break;
	}
}

/// @brief Registra o tempo de sistema e de usuário
/// @return Tempo total do programa no momento da chamada
double contagem() {
	struct rusage resources;
	int rc;
	double utime, stime, total_time;

	if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
		perror("getrusage failed");
	utime = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
	stime = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;
	total_time = utime + stime;

	return total_time;
}

/// @brief Preenche um vetor de itens com chaves aleatórias de 0 a MAX_CHAVE
/// @param vetor Vetor que será preenchido
/// @param tam Tamanho do vetor
void preencheVetor(Item *vetor, int tam) {
	int chave;
	for(int i = 0; i < tam; i++) {
		chave = lrand48();
		vetor[i].chave = chave % MAX_CHAVE;
	}
}

/// @brief Recebe os argumentos da linha de execução do programa
void parseArgs(int argc, char *argv[]) {
	int opcao;
	while((opcao = getopt(argc, argv, "v:s:k:m:i:o:l:")) != -1) {
		switch(opcao) {
			case 'i':
				args::nomeEntrada = optarg;
				break;

			case 'o':
				args::nomeSaida = optarg;
				break;

			case 'v':
				args::versao = atoi(optarg);
				break;

			case 's':
				args::seed = atoi(optarg);
				break;

			case 'k':
				args::medianas = atoi(optarg);
				break;

			case 'm':
				args::limiar = atoi(optarg);
				break;

			case 'l':
				args::nomeMemLog = optarg;

				break;
		}
	}
}

/// @brief Busca o nome da ordenação inserida pelo usuário
/// @return String contendo o nome da ordenação
string nomeOrdenacao() {
	switch(args::versao) {
		case RECURSIVO:
			return "Quicksort Recursivo";
			break;

		case MEDIANA:
			return "Quicksort Mediana";
			break;

		case SELECAO:
			return "Quicksort Seleção";
			break;

		case NAO_RECURSIVO:
			return "Quicksort não Recursivo";
			break;

		case INTELIGENTE:
			return "Quicksort Empilha Inteligente";
			break;

		case MERGE:
			return "Merge Sort";
			break;

		case HEAP:
			return "Heap Sort";
			break;
		
		default:
			return "Quicksort Recursivo";
			break;
	}
	return "Não reconhecida";
}

/// @brief Insere a header no arquivo de saída
void inicializaSaida(int n) {
	ofstream saida;
	int var;

	saida.open(args::nomeSaida);
	erroAssert(saida.is_open(), "Ordenacao - Não foi possível abrir o arquivo de saída. Verifique se o caminho indicado existe");

	saida << right << setfill('-') << setw(LARGURA * 4) << "\n";
	
	if(args::seed <= 0) var = 10;
	saida << left << setfill(' ') << setw(LARGURA) << "Seed: " + to_string(var) << right << setw(LARGURA * 3) << "Número de entradas: " + to_string(n) << "\n";

	saida << left << setw(LARGURA * 2) << "Ordenação: " + nomeOrdenacao();

	if(args::versao == 2) {
		if(args::medianas <= 0)
			var = 3;
		else
			var = args::medianas;
		saida << right << setw(LARGURA * 2) << "k = " + to_string(var);
	} else if(args::versao == 3) {
		if(args::limiar <= 0)
			var = 10;
		else
			var = args::limiar;
		saida << right << setw(LARGURA * 2) << "m = " + to_string(var);
	}

	saida << "\n";

	saida << right << setfill('-') << setw(LARGURA * 4) << "\n";
	saida << left << setfill(' ') << setw(LARGURA) << "Tamanho" << setw(LARGURA) << "Tempo" << setw(LARGURA) << "Comparações"
	      << "Cópias" << endl;
	saida << right << setfill('-') << setw(LARGURA * 4) << "\n";
	saida.close();
}

/// @brief Insere os valores de registro ao final do arquivo de saída no momento da chamada da função
void registraNoArquivo() {
	ofstream arq;
	arq.open(args::nomeSaida, ios::out | ios::app);
	arq << left << setw(LARGURA) << reg::tamanho << setw(LARGURA) << reg::tempo << setw(LARGURA) << reg::comparacoes << reg::copias << endl;
	arq.close();
}

int main(int argc, char *argv[]) {
	parseArgs(argc, argv);

	int n;
	Item *vetor;

	erroAssert((args::nomeEntrada.size() > 0), "Ordenação - Não foi registrado um nome para o arquivo de entrada");
	ifstream entrada;
	entrada.open(args::nomeEntrada);
	erroAssert(entrada.is_open(), "Ordenacao - Não foi possível abrir o arquivo de entrada. Verifique se ele existe ou está no caminho indicado");
	entrada >> n;

	avisoAssert((args::nomeSaida.size() > 0), "Ordenação - Não foi lido um nome para o arquivo de saída. arquivo padrão definido em ./bin/saida.out");
	args::nomeSaida = "bin/saida.out";

	inicializaSaida(n);

	srand48(args::seed);

	(args::nomeMemLog.size() > 0) ? iniciaMemLog(args::nomeMemLog.c_str()) : iniciaMemLog("bin/memlog.out");
	ativaMemLog();

	for(int i = 0; i < n; i++) {
		defineFaseMemLog(i);

		entrada >> reg::tamanho;
		vetor = new Item[reg::tamanho];
		preencheVetor(vetor, reg::tamanho);

		double inicio = contagem();
		chamaOrdenacao(vetor, reg::tamanho);
		double fim = contagem();

		delete[] vetor;

		reg::tempo = fim - inicio;

		registraNoArquivo();
	}

	finalizaMemLog();

	entrada.close();

	return 0;
}