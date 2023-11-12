#include "grafo.h"

/// @brief Construtor da classe Grafo
/// @param n Número de vértices
Grafo::Grafo(int n) {
	this->n = n;
	this->vertices.resize(n);
}

/// @brief Adiciona uma aresta de um vértice a outro, com peso
/// @param x1 Uma aresta do vértice
/// @param x2 Outra aresta do vértice, diferente de x1
/// @param d O peso da aresta, ou distância entre os vértices
void Grafo::addAresta(int x1, int x2, int d) {
	// não adiciona a aresta de um vértice para ele mesmo
	if (x1 == x2) return;

	// adiciona a adjacência (d, x2) no vérice x1
	this->vertices[x1].push_back(make_pair(x2, d));

	// adiciona a adjacência (d, x1) no vérice x2
	this->vertices[x2].push_back(make_pair(x1, d));
}

/// @brief verifica se o grafo está vazio
/// @return boleano indicando true caso o grafo esteja vazio
bool Grafo::Vazio() {
	return this->n == 0;
}

/// @brief calcula o menor caminho entre o par e ímpar
/// @param a pair com o menor caminho par e o menor caminho ímpar, respectivamente
/// @return o menor caminho entre o par e ímpar
int menorCaminho(pair<int, int> a) {
	if (a.first < a.second) return a.first;
	return a.second;
}

/// @brief Busca o menor caminho par entre o vértice 1 e o vértice n, passando por um número par de arestas
/// @return A distância do menor caminho par entre o vértice 1 e o vértice n, ou -1 se não houver caminho
int Grafo::Jodds() {
	if (this->Vazio()) return -1;

	// como especificado, o caminho deve partir do vértice 1 e chegar no vértice n
	int origem = 0, final = this->n - 1;

	// o vetor "caminhos" tem tamanho n e em cada posição contém um pair com a distância do menor
	// caminho par e o menor caminho impar, respectivamente.
	vector<pair<int, int>> caminhos(this->n, make_pair(INF, INF));

	// vetor de visitados pelo caminho par e ímpar, respectivamente
	vector<pair<bool, bool>> visitados(this->n, make_pair(false, false));

	// o menor caminho par até a origem é 0, e não há caminho par menor
	caminhos[origem].first = 0;
	visitados[origem].first = true;

	// uma fila de inteiros que será usada para percorrer o grafo
	filaPrioridade fila;
	fila.push(make_pair(menorCaminho(caminhos[origem]), origem));

	while (!fila.empty()) {
		int v = fila.top().second;  // pega o vértice com menor distância
		fila.pop();

		if (visitados[v].first && visitados[v].second) {
			if(v == final) break ; // se v já foi visitado pelo caminho par e ímpar, e é o final, encerra o loop
			continue; // se v já foi visitado pelo caminho par e ímpar, não analisa os vizinhos
		}

		// para cada vizinho w de v
		for (auto &it : this->vertices[v]) {
			int w = it.first;
			int peso = it.second;

			bool atualizado = false;

			// se (o menor caminho par até v + o peso da aresta vw) for menor que o atual
			// menor caminho impar até w, atualiza esse caminho de w
			if ((caminhos[v].first + peso) < caminhos[w].second) {
				caminhos[w].second = caminhos[v].first + peso;
				atualizado = true;
				visitados[v].first = true; // marca que v está em seu menor caminho par até agora
				visitados[v].second = false; // como ele atualizou algum vizinho, ele pode ter seu caminho ímpar atualizado novamente
			}

			// se (o menor caminho impar até v + o peso da aresta vw) for menor que o atual
			// menor caminho par até w, atualiza esse caminho de w
			if ((caminhos[v].second + peso) < caminhos[w].first) {
				caminhos[w].first = caminhos[v].second + peso;
				atualizado = true;
				visitados[v].second = true; // marca que v está em seu menor caminho ímpar até agora
				visitados[v].first = false; // como ele atualizou algum vizinho, ele pode ter seu caminho par atualizado novamente
			}

			// se w foi atualizado, adiciona w na fila com a menor distância até ele
			if (atualizado) fila.push(make_pair(menorCaminho(caminhos[w]), w));
		}
	}

	// retorna o menor caminho par até o final
	int menor = caminhos[final].first;
	return menor != INF ? menor : -1;
}