#ifndef LINKOUT_HPP
#define LINKOUT_HPP

#include "headers.h"

class LinkOut {
private:
	int numUsuarios = 0, numEmpresas = 0;
	unordered_map<string, int> indices; // mapeia o nome do usuário ou da empresa para um índice no grafo
	vector<vector<bool>> qualificacoes; // matriz de adjacência que indica se um usuário i é qualificado para uma vaga j

public:
	LinkOut(int u, int j);
	void addQualificacao(string usuario, string empresa);
	int FordFulkerson(vector<list<int>> grafo, int s, int t);
	int resultadoGuloso();
	int resultadoOtimo();
};
#endif  // LINKOUT_HPP