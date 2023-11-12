#include "headers.h"

/// @brief Calcula o número mínimo de ligas necessárias para uma encomenda
/// @param l Vetor com os tamanhos das ligas
/// @param w Tamanho da encomenda
/// @return Número mínimo de ligas necessárias para uma encomenda
int ligas(vector<int>& l, int w);

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, w;
		cin >> n >> w;

		// 1 <= n <= 1000
		if(1 > n || n > 1000) {
			cout << "n = " << n << " fora do intervalo [1, 1000]" << endl;
			n = (1 > n) ? 1 : 1000;
		}

		// 1 <= w <= 1000000
		if(1 > w || w > 1000000) {
			cout << "w = " << w << " fora do intervalo [1, 1000000]" << endl;
			w = (1 > w) ? 1 : 1000000;
		}

		vector<int> l(n);

		for (int j = 0; j < n; j++) {
			cin >> l[j];
			
			// 1 <= l[j] <= 1000
			if(1 > l[j] || l[j] > 1000) {
				cout << "l[" << j << "] = " << l[j] << " fora do intervalo [1, 1000]" << endl;
				l[j] = (1 > l[j]) ? 1 : 1000;
			}
		}

		cout << ligas(l, w) << endl;
	}

	return 0;
}

int ligas(vector<int>& l, int w) {
	// Inicializa o vetor de soluções com o valor máximo
	vector<int> solucoes(w + 1, INF);

	// A solução para o caso base é 0
	solucoes[0] = 0;

	// Para cada tamanho de liga
	for (int i = 0; i < int(l.size()); i++) {
		// Para cada tamanho de encomenda
		for (int j = 1; j <= w; j++) {
			// Se o tamanho da liga for menor ou igual ao tamanho da encomenda
			if(l[i] <= j) {
				// A solução para o tamanho da encomenda é o mínimo entre a solução anterior
				// e a solução para o tamanho da encomenda menos o tamanho da liga atual
				solucoes[j] = min(solucoes[j], solucoes[j - l[i]] + 1);
			}
		}
	}

	// Retorna a solução para o tamanho da encomenda
	return solucoes[w];
}