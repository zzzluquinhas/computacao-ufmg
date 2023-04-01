#include "Verbete.h"

/// @brief Hash que armazena verbetes
class Hash : public Dicionario {
   public:
	Hash(int tam);
	~Hash();

	/// @brief Pesquisa um verbete no hash
	/// @param v Verbete que será buscado
	/// @return Verbete encontrado ou nullptr
	Verbete* Pesquisa(Verbete* v);

	/// @brief Insere um verbete no hash
	/// @param v Verbete que será inserido
	void Insere(Verbete* v);

	/// @brief Imprime o hash no terminal
	void Imprime();

	/// @brief Imprime o hash no arquivo de saída
	void ImprimeSaida();

	/// @brief Remove do hash todos os verbetes com pelo menos um significado
	void RemoveVerbeteComSignificado();

   private:
	int tamanho;                     // Tamanho do hash
	ListaVerbete* tabela;            // Tabela do hash
	int Hashing(std::string chave);  // Função de hashing
};
