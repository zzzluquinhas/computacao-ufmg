#include "headers.h"
#include "linkOut.h"

int main(int argc, char const* argv[]) {
	int u, j, e;

	cin >> u >> j >> e;
	LinkOut rede(u, j);

	string usuario, vaga;
	for (int i = 0; i < e; i++) {
        cin >> usuario >> vaga;
		rede.addQualificacao(usuario, vaga);
    }

	cout << "Guloso: " << rede.resultadoGuloso() << endl;
	cout << "Exato: " << rede.resultadoOtimo() << endl;

	return 0;
}
