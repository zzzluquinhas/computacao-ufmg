#include <string>

#define MAX_CHAVE 10000
#define NUM_REG 4

enum versoes {
	RECURSIVO = 1,
	MEDIANA,
	SELECAO,
	NAO_RECURSIVO,
	INTELIGENTE,
	MERGE,
	HEAP
};

/// @brief Variáveis de controle da análise de desempenho
namespace reg {
	inline int tamanho = 0;         // Tamanho do vetor ordenado
	inline double tempo = 0;        // Tempo de execução do programa
	inline double comparacoes = 0;  // Número de comparações de chaves
	inline double copias = 0;       // Número de cópias de variáveis
}  // namespace reg

/// @brief Argumentos recebidos pela linha de comando
namespace args {
	inline int versao = 0;               // Tipo de ordenação escolhido
	inline int seed = 0;                 // Semente utilizada pela função rand()
	inline int medianas = 0;             // Número de elementos utilizados pelo QuickSort Mediana
	inline int limiar = 0;               // Limiar que o QuickSort Seleção utilizará para escolher a ordenação da partição
	inline std::string nomeEntrada = "";      // Nome do arquivo de onde serão lidos os dados
	inline std::string nomeSaida = "";        // Nome do arquivo onde será escrito o resultado
	inline std::string nomeMemLog = "";  // Nome do arquivo onde será escrito o resultado
}  // namespace args
