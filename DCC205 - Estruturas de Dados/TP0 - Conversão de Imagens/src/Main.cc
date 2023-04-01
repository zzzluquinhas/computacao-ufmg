#include "Imagem.h"

#include <string.h>
#include <getopt.h>

#define IMAGEM_ORIGINAL 0
#define IMAGEM_NOVA 1


/// @brief Avalia se a string termina com determinada extensão
/// @param nome String que será avaliada
/// @param extensao Final que será usado como parâmetro para conferir
/// @return True se a string termina com a extensão, false caso contrário
static bool terminaCom(string& nome, string extensao){
	//crédito https://stackoverflow.com/questions/874134/find-out-if-string-ends-with-another-string-in-c
    return nome.size() >= extensao.size() && 0 == nome.compare(nome.size()-extensao.size(), extensao.size(), extensao);
}

/// @brief Escreve os dados de uma Imagem em um arquivo
/// @param nomeArquivo Nome do arquivo no qual a imagem será escrita 
/// @param pgm Ponteiro para uma variável do tipo Imagem
void escreverArquivo(string nomeArquivo, Imagem *pgm){
	ofstream arquivo;
	arquivo.open(nomeArquivo);
    erroAssert(arquivo.is_open(), "PPMtoPGM - Arquivo não existe e não foi possível criar");

	arquivo << pgm->versao << "\n" << pgm->largura << " " << pgm->altura << "\n" << pgm->range << endl;
	
	for(int i=0; i<pgm->altura; i++){
	
		for(int j=0; j<pgm->largura; j++){
	
			arquivo << pgm->matriz[i][j].getGray();
            LEMEMLOG((long int)(&pgm->matriz[i][j]),sizeof(int),IMAGEM_NOVA);
			if(j < pgm->largura-1) arquivo << " ";
	
		}
		arquivo << "\n";
	
	}
	arquivo.close();
}

int main(int argc, char* argv[]) {

	int opt;
	bool registraAcessos = false; // Indica se o usuário deseja registrar os acessos à memória
	string nomeRegistro; // Nome do arquivo onde serão registrados os acessos à memória
	string nomeEntrada; // Nome do arquivo de onde será lida a imagem
	string nomeSaida; // Nome do arquivo onde a imagem resultante será escrita
	char *nomeRegistroChar; // Variável usada para enviar o nome do arquivo de registro para a função iniciaMemLog()

	while ((opt = getopt(argc, argv, "i:o:p:l"))!=-1){
		switch (opt){
			case 'i':
				nomeEntrada = optarg;
    			erroAssert((nomeEntrada.size() > 0), "PPMtoPGM - Não foi registrado um nome para o arquivo de entrada");
				erroAssert(terminaCom(nomeEntrada,".ppm"), "PPMtoPGM - Arquivo de entrada não é do tipo ppm");
				break;

			case 'o':
				nomeSaida = optarg;
    			erroAssert((nomeSaida.size() > 0), "PPMtoPGM - Não foi registrado um nome para o arquivo de saída");
				avisoAssert(terminaCom(nomeSaida, ".pgm"), "PPMtoPGM - O arquivo não tem extensão .pgm"); 
				if(!terminaCom(nomeSaida, ".pgm")) nomeSaida += ".pgm";
				break;

			case 'p':
				nomeRegistro = optarg;
    			erroAssert((nomeRegistro.size() > 0), "PPMtoPGM - Não foi registrado um nome para o arquivo de registro");
				break;

			case 'l':
				registraAcessos = true;
				break;
				
		}
	}

	nomeRegistroChar = new char[nomeRegistro.size() + 1];
	strcpy(nomeRegistroChar, nomeRegistro.c_str());

	iniciaMemLog(nomeRegistroChar);

	registraAcessos ? ativaMemLog() : desativaMemLog();

    defineFaseMemLog(0);
	Imagem entrada = Imagem(nomeEntrada);

    defineFaseMemLog(1);
	Imagem saida = entrada.PPMtoPGM();

	escreverArquivo(nomeSaida, &saida);

	finalizaMemLog();

	return 0;
}