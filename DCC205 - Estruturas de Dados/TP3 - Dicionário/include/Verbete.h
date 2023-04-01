#include "Globais.h"
#include "Significado.h"

/// @brief Classe que representa um verbete
class Verbete {
   public:
	char tipo = ' ';                                            // Tipo do verbete ((a)djective, (n)oun ou (v)erb)
	std::string palavra = " ";                                  // Palavra do verbete
	ListaSignificados *significados = new ListaSignificados();  // Lista de significados do verbete
	Verbete *prox = nullptr;                                    // Próximo verbete da lista

	Verbete() : tipo(' '), palavra(" "){};
	Verbete(char t, std::string p) : tipo(t), palavra(p){};
	~Verbete();

	/// @brief Insere um significado ao verbete
	/// @param s Texto do significado que será inserido
	void InsereSignificado(std::string s);

	/// @brief Insere uma lista de significados ao verbete
	/// @param s Lista de significados que será inserida
	void InsereSignificado(ListaSignificados *s);

	/// @brief Imprime o verbete no terminal
	void Imprime();

	/// @brief Produz uma string com o verbete no formato desejado
	/// @return String com o verbete
	std::string Saida();

	/// @brief Verifica se o verbete está vazio
	/// @return True se o verbete estiver vazio, false caso contrário
	bool Vazio();

	friend class ListaVerbete;
};

/// @brief Lista de verbetes
class ListaVerbete {
   private:
	/// @brief Limpa a lista de verbetes
	void Limpa();

   public:
	Verbete *inicio = nullptr, *fim = nullptr;
	int tamanho = 0;

	ListaVerbete(){};
	~ListaVerbete();

	/// @brief Insere um verbete na lista em ordem alfabética
	/// @param v Verbete que será inserido
	void InsereOrdenado(Verbete *v);

	/// @brief Imprime a lista de verbetes no terminal
	void Imprime();

	/// @brief Produz uma string com todos os verbetes da lista no formato desejado
	/// @return String com o conteúdo da lista
	std::string Saida();

	/// @brief Imprime a lista de verbetes no arquivo de saída
	void ImprimeSaida();

	/// @brief Remove verbetes que possuem pelo menos um significado
	void RemoveVerbeteComSignificado();

	/// @brief Busca um verbete na lista
	/// @param v Verbete que será buscado
	/// @return Ponteiro para o verbete buscado, ou nullptr caso não seja encontrado
	Verbete *Pesquisa(Verbete *v);

	/// @brief Verifica se a lista está vazia
	/// @return True se a lista estiver vazia, false caso contrário
	bool Vazio() { return tamanho == 0; }
};

/// @brief Classe abstrata que define a interface de um dicionário
class Dicionario {
   public:
	/// @brief Insere um verbete no dicionário
	/// @param v Verbete que será inserido
	virtual void Insere(Verbete *v) = 0;

	/// @brief Imprime o dicionário no arquivo de saída
	virtual void ImprimeSaida() = 0;

	/// @brief Remove verbetes que possuem pelo menos um significado
	virtual void RemoveVerbeteComSignificado() = 0;

	virtual ~Dicionario(){};
};