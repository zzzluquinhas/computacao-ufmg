#include "linkOut.h"

/// @brief Construtor da classe LinkOut
/// @param u Número total de usuários
/// @param j Número total de vagas
LinkOut::LinkOut(int u, int j) {
	qualificacoes.resize(u, vector<bool>(j, false));
}

/// @brief Adiciona uma qualificação de um usuário para uma vaga
/// @param usuario
/// @param vaga 
void LinkOut::addQualificacao(string usuario, string vaga) {
	if (!indices.count(usuario)) {
		indices[usuario] = numUsuarios++;
	}
	if (!indices.count(vaga)) {
		indices[vaga] = numEmpresas++;
	}
	qualificacoes[indices[usuario]][indices[vaga]] = true;
}

/// @brief Algoritmo Guloso para encontrar o número máximo de usuários que podem ser alocados
/// @return Número máximo de usuários que podem ser alocados
int LinkOut::resultadoGuloso(){
	int resultado = 0;
	vector<bool> vagas(numEmpresas, false); // indica se uma vaga já foi preenchida

	for (int i = 0; i < numUsuarios; i++) {
		int empresa = -1;
		for (int j = 0; j < numEmpresas; j++) {
			if (qualificacoes[i][j] && !vagas[j]) {
				empresa = j;
				break;
			}
		}
		if (empresa != -1) {
			vagas[empresa] = true;
			resultado++;
		}
	}
	return resultado;
}

/// @brief Algoritmo de Ford-Fulkerson para encontrar o número máximo de usuários que podem ser alocados
/// @param grafo Lista de adjacência que representa o grafo
/// @param s Vértice fonte que aponta para todos os usuários
/// @param t Vértice sumidouro que é apontado por todas as vagas
/// @return Número máximo de usuários que podem ser alocados
int LinkOut::FordFulkerson(vector<list<int>> grafo, int s, int t){
	int u, v;
	vector<list<int>> grafoResidual = grafo;
	vector<int> pai(grafo.size(), -1);
	int resultado = 0;

	// Enquanto existir um caminho de s para t no grafo residual
	while (true) {
		vector<bool> visitado(grafo.size(), false);
		queue<int> fila;
		fila.push(s);
		visitado[s] = true;

		// BFS para encontrar um caminho de s para t
		while (!fila.empty()) {
			u = fila.front();
			fila.pop();

			// Para cada vizinho v de u no grafo residual
			for (auto it = grafoResidual[u].begin(); it != grafoResidual[u].end(); it++) {
				v = *it;
				if (!visitado[v]) {
					fila.push(v);
					visitado[v] = true;
					pai[v] = u;
				}
			}
		}

		// Se não existe um caminho de s para t no grafo residual, termina
		if (!visitado[t]) {
			break;
		}

		// Se existe um caminho de s para t no grafo residual, aumenta o fluxo
		for (v = t; v != s; v = pai[v]) {
			u = pai[v];
			grafoResidual[u].remove(v);
			grafoResidual[v].push_back(u);
		}

		resultado++;
	}
	return resultado;
}

int LinkOut::resultadoOtimo(){
	vector<list<int>> grafo(numUsuarios+numEmpresas+2); // grafo com vértice fonte e sumidouro

	for (int i = 0; i < numUsuarios; i++) {
		grafo[0].push_back(i+1); // vértice fonte aponta para todos os usuários
	}

	for (int i = 0; i < numEmpresas; i++) {
		grafo[i+numUsuarios+1].push_back(numUsuarios+numEmpresas+1); // todas as vagas apontam para o vértice sumidouro
	}

	for (int i = 0; i < numUsuarios; i++) {
		for (int j = 0; j < numEmpresas; j++) {
			// se o usuário i é qualificado para a vaga j, cria uma aresta de i para j
			if (qualificacoes[i][j]) {
				grafo[i+1].push_back(j+numUsuarios+1);
			}
		}
	}

	return FordFulkerson(grafo, 0, numUsuarios+numEmpresas+1);
}