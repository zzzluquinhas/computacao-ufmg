#include <iostream>
#include <string>

#include "msgassert.h"
#include "memlog.h"

/// @brief Significado de um verbete
class Significado {
   private:
	std::string info = "";  // Texto do significado

   public:
	Significado *prox = nullptr;  // Próximo significado da lista

	Significado() : info(""), prox(nullptr){};
	Significado(std::string i) : info(i), prox(nullptr){};
	std::string getItem() { return info; };
	void setItem(std::string i) { info = i; };

	friend class ListaSignificados;
};

/// @brief Lista de significados
class ListaSignificados {
   private:
	/// @brief Limpa a lista de significados
	void Limpa();

   public:
	Significado *inicio = nullptr, *fim = nullptr;
	int tamanho = 0;

	ListaSignificados(){};
	~ListaSignificados();

	/// @brief Insere um significado no final da lista
	/// @param info Texto do significado
	void Insere(std::string info);

	/// @brief Imprime a lista de significados no terminal
	void Imprime();

	/// @brief Produz uma string com todos os significados da lista
	/// @return String com o conteúdo da lista
	std::string Saida();

	/// @brief Verifica se a lista está vazia
	/// @return True se a lista estiver vazia, false caso contrário
	bool Vazia();
};
