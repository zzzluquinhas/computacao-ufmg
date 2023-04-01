#include "Hash.h"

/// @brief No da Árvore AVL
class No {
   public:
	Verbete *chave;  // Verbete do node
	No *esq;         // No da esquerda
	No *dir;         // No da direita
	int altura;      // Altura do node

	No() : chave(nullptr), esq(nullptr), dir(nullptr), altura(1){};
	No(Verbete *c) : chave(c), esq(nullptr), dir(nullptr), altura(1){};
	~No() { delete chave; }

	/// @brief Calcula o fator de balanceamento de um nó
	/// @return O fator de balanceamento em int
	int FatorBalanceamento() {
		int altEsq = -1,
		    altDir = -1;
		if(esq) altEsq = esq->altura;
		if(dir) altDir = dir->altura;
		return altDir - altEsq;
	}

	/// @brief Recalcula a altura de um nó e armazena no seu atributo altura
	void RecalculaAltura() {
		this->altura = Altura();
	}

   private:
	/// @brief Calcula a altura de um nó da árvore
	/// @return Altura em int
	int Altura() {
		int altEsq = -1,
		    altDir = -1;

		if(esq) altEsq = esq->Altura();
		if(dir) altDir = dir->Altura();

		return std::max(altEsq, altDir) + 1;
	}
};

/// @brief Árvore AVL que armazena verbetes
class ArvAVL : public Dicionario {
   public:
	ArvAVL() : raiz(nullptr){};
	~ArvAVL() { Limpa(); }

	/// @brief Insere um verbete na árvore
	/// @param chave Verbete que será inserido
	void Insere(Verbete *chave) {
		InsereRecursivo(raiz, chave);
		Balanceamento();
	}

	/// @brief Remove um verbete da árvore
	/// @param chave Verbete que será removido
	void Remove(Verbete *chave) {
		RemoveRecursivo(raiz, chave);
		Balanceamento();
	}

	/// @brief Remove todos os verbetes que possuem pelo menos um significado
	void RemoveVerbeteComSignificado() {
		RemoveVerbeteComSignificadoRecursivo(raiz);
		Balanceamento();
	}

	/// @brief Imprime todos os verbetes da árvore no terminal
	void Imprime() {
		ImprimeRecursivo(raiz);
	}

	/// @brief Imprime todos os verbetes da árvore em um arquivo de saída
	void ImprimeSaida() {
		std::ofstream saida;
		saida.open(args::nomeSaida, std::ios::out | std::ios::app);
		avisoAssert(saida.is_open(), "Dicionario - Não foi possível abrir o arquivo de saída indicado. Saída salva em bin/saida.out");
		if(!saida.is_open()) {
			args::nomeSaida = "bin/saida.out";
			saida.open(args::nomeSaida, std::ios::out | std::ios::app);
		}
		ImprimeSaidaRecursivo(raiz, saida);
		saida.close();
	}

	/// @brief Limpa a árvore
	void Limpa() {
		LimpaRecursivo(raiz);
		raiz = nullptr;
	}

   private:
	/// @brief Rotaciona a subárvore para a direita
	/// @param p Nó raiz da subárvore que será rotacionada
	void RotacaoDireita(No *&p);

	/// @brief Rotaciona a subárvore para a esquerda
	/// @param p Nó raiz da subárvore que será rotacionada
	void RotacaoEsquerda(No *&p);

	/// @brief Realiza uma rotação RL na subárvore
	/// @param p Nó raiz da subárvore que será rotacionada
	void RotacaoDuplaDireita(No *&p);

	/// @brief Realiza uma rotação LR na subárvore
	/// @param p Nó raiz da subárvore que será rotacionada
	void RotacaoDuplaEsquerda(No *&p);

	/// @brief Balanceia a árvore
	void Balanceamento();

	/// @brief Balanceia uma subárvore recursivamente
	/// @param p Nó raiz da subárvore que será balanceada
	void BalanceamentoRecursivo(No *&p);

	/// @brief Função recursiva para inserir um item na árvore
	/// @param p Nó raiz da árvore onde será inserido o item
	/// @param item Item que será inserido
	void InsereRecursivo(No *&p, Verbete *item);

	/// @brief Função recursiva para remover um item da árvore
	/// @param p Nó raiz da árvore onde será removido o item
	/// @param item Item que será removido
	void RemoveRecursivo(No *&p, Verbete *item);

	/// @brief Função recursiva para remover todos os verbetes que possuem pelo menos um significado
	/// @param p Nó raiz da árvore onde serão removidos os verbetes
	void RemoveVerbeteComSignificadoRecursivo(No *&p);

	/// @brief Função recursiva para limpar a árvore
	/// @param p Nó raiz da árvore que será limpa
	void LimpaRecursivo(No *p);

	/// @brief Função recursiva para imprimir a árvore no terminal
	/// @param p Nó raiz da árvore que será impressa
	void ImprimeRecursivo(No *p);

	/// @brief Função recursiva para imprimir a árvore em um arquivo de saída
	/// @param p Nó raiz da árvore que será impressa
	/// @param saida Arquivo de saída onde será impressa a árvore
	void ImprimeSaidaRecursivo(No *p, std::ofstream &saida);

	No *raiz;  // Nó raiz da árvore
};