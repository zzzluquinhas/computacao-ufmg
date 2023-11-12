#include "grafo.h"

using namespace std;

int main(int argc, char const* argv[]) {
	int n, a, x1, x2, d;

	cin >> n >> a;

	Grafo grafo(n);

	for (int i = 0; i < a; i++) {
		if (!(cin >> x1 >> x2 >> d)) break;

		// adiciona apenas as arestas de peso par
		if (d % 2 == 0) grafo.addAresta(x1 - 1, x2 - 1, d);  // -1 para converter para 0-indexado
	}

	int dist = grafo.Jodds();

	cout << dist << endl;

	return 0;
}