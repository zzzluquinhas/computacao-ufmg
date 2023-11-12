#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "headers.h"

/// @brief Classe Grafo
class Grafo {
private:
	int n;
	vector<vector<pair<int, int>>> vertices;

public:
	Grafo(int n);
	void addAresta(int x1, int x2, int d);
	bool Vazio();
	int Jodds();
	int JoddsMelhorado();
};

#endif  // GRAPH_HPP