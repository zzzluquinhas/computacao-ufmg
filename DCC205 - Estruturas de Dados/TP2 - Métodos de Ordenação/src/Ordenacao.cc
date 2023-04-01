#include "Ordenacao.h"

void Troca(Item *a, Item *b) {
	Item aux = *a;
	LEMEMLOG((long int)(a), sizeof(Item), 0);

	*a = *b;
	LEMEMLOG((long int)(b), sizeof(Item), 0);
	ESCREVEMEMLOG((long int)(a), sizeof(Item), 0);

	*b = aux;
	ESCREVEMEMLOG((long int)(b), sizeof(Item), 0);

	reg::copias += 3;
}

void Particao(Item *vetor, int inicio, int fim, int *i, int *j, int pivo = -1) {
	int a;
	*i = inicio;
	*j = fim;
	if(pivo == -1) {
		a = vetor[(*i + *j) / 2].chave;
		LEMEMLOG((long int)(&vetor[(*i + *j) / 2].chave), sizeof(int), 0);

	} else {
		a = pivo;
	}
	do {
		while(a > vetor[*i].chave) {
			reg::comparacoes++;
			(*i)++;
		}
		reg::comparacoes++;

		while(a < vetor[*j].chave) {
			reg::comparacoes++;
			(*j)--;
		}
		reg::comparacoes++;

		if(*i <= *j) {
			Troca(&vetor[*i], &vetor[*j]);
			(*i)++;
			(*j)--;
		}
	} while(*i <= *j);
}

void OrdenaQuickSortRecursivo(Item *vetor, int inicio, int fim) {
	int i, j;
	Particao(vetor, inicio, fim, &i, &j);
	if(inicio < j) OrdenaQuickSortRecursivo(vetor, inicio, j);
	if(i < fim) OrdenaQuickSortRecursivo(vetor, i, fim);
}

void QuickSortRecursivo(Item *vet, int tam) {
	OrdenaQuickSortRecursivo(vet, 0, tam - 1);
}

void SelectionSort(Item *vet, int inicio, int fim) {
	int min;
	Item a;

	for(int i = inicio; i < fim+1; i++) {
		min = i;
		for(int j = i + 1; j < fim+1; j++) {
			if(vet[j].chave < vet[min].chave) {
				min = j;
			}
			reg::comparacoes++;
		}
		Troca(&vet[i], &vet[min]);
	}
}

void OrdenaQuickSortSelecao(Item *vetor, int inicio, int fim) {
	int i, j, tam;
	tam = fim - inicio + 1;
	if(tam > args::limiar) {
		Particao(vetor, inicio, fim, &i, &j);
		if(inicio < j) OrdenaQuickSortSelecao(vetor, inicio, j);
		if(i < fim) OrdenaQuickSortSelecao(vetor, i, fim);
	} else {
		SelectionSort(vetor, inicio, fim);
	}
}

void QuickSortSelecao(Item *vet, int tam) {
	OrdenaQuickSortSelecao(vet, 0, tam - 1);
}

int Mediana(Item *vetor, int inicio, int fim) {
	int tam = fim - inicio + 1;

	Item elementos[args::medianas];
	int mediana, posicao;

	for(int i = 0; i < args::medianas; i++) {
		posicao = lrand48();
		posicao = (posicao % tam) + inicio;

		reg::copias++;
		elementos[i] = vetor[posicao];
		LEMEMLOG((long int)(&vetor[posicao]), sizeof(Item), 0);
		ESCREVEMEMLOG((long int)(&elementos[i]), sizeof(Item), 1);
	}

	SelectionSort(elementos, 0, args::medianas-1);

	mediana = elementos[(args::medianas - 1) / 2].chave;
	LEMEMLOG((long int)(&elementos[(args::medianas - 1) / 2].chave), sizeof(int), 1);

	return mediana;
}

void OrdenaQuickSortMediana(Item *vetor, int inicio, int fim) {
	int mediana = Mediana(vetor, inicio, fim);

	int i, j;
	Particao(vetor, inicio, fim, &i, &j, mediana);

	if(inicio < j) OrdenaQuickSortMediana(vetor, inicio, j);
	if(i < fim) OrdenaQuickSortMediana(vetor, i, fim);
}

void QuickSortMediana(Item *vet, int tam) {
	OrdenaQuickSortMediana(vet, 0, tam - 1);
}

void QuickSortNaoRecursivo(Item *vetor, int tam) {
	Pilha pilha = Pilha();
	ItemPilha item;
	int esq, dir, i, j;

	esq = 0;
	dir = tam - 1;
	item.inicio = esq;
	item.fim = dir;
	pilha.Empilha(item);

	do {
		if(dir > esq) {
			Particao(vetor, esq, dir, &i, &j);
			item.fim = j;
			item.inicio = esq;
			pilha.Empilha(item);
			esq = i;
		} else {
			item = pilha.Desempilha();
			dir = item.fim;
			esq = item.inicio;
		}
	} while(!pilha.Vazia());
}

void QuickSortInteligente(Item *vetor, int tam) {
	Pilha pilha = Pilha();
	ItemPilha item;
	int inicio, fim, i, j;

	inicio = 0;
	fim = tam - 1;
	item.inicio = inicio;
	item.fim = fim;
	pilha.Empilha(item);

	do {
		if(fim > inicio) {
			Particao(vetor, inicio, fim, &i, &j);
			if((j - inicio) > (fim - i)) {
				item.fim = j;
				item.inicio = inicio;
				pilha.Empilha(item);
				inicio = i;
			} else {
				item.inicio = i;
				item.fim = fim;
				pilha.Empilha(item);
				fim = j;
			}
		} else {
			item = pilha.Desempilha();
			fim = item.fim;
			inicio = item.inicio;
		}
	} while(!pilha.Vazia());
}

void Refaz(int tam, int raiz, Item *vetor) {
	int maior = raiz,
	    esq = 2 * raiz + 1,
	    dir = 2 * raiz + 2;

	if(esq < tam && vetor[esq].chave > vetor[maior].chave) maior = esq;
	reg::comparacoes++;

	if(dir < tam && vetor[dir].chave > vetor[maior].chave) maior = dir;
	reg::comparacoes++;

	if(maior != raiz) {
		Troca(&vetor[raiz], &vetor[maior]);
		Refaz(tam, maior, vetor);
	}
}

void HeapSort(Item *vetor, int tam) {
	for(int i = (tam / 2) - 1; i >= 0; i--) Refaz(tam, i, vetor);

	for(int i = tam - 1; i >= 0; i--) {
		Troca(&vetor[0], &vetor[i]);
		Refaz(i, 0, vetor);
	}
}

void Junta(Item *vet, int inicio, int meio, int fim) {
	int tamanhoEsq = meio - inicio + 1,
	    tamanhoDir = fim - meio;

	Item *vetEsq = new Item[tamanhoEsq],
	     *vetDir = new Item[tamanhoDir];

	for(int i = 0; i < tamanhoEsq; i++) {
		reg::copias++;
		vetEsq[i] = vet[inicio + i];
		LEMEMLOG((long int)(&vet[inicio + i]), sizeof(Item), 0);
		ESCREVEMEMLOG((long int)(&vetEsq[i]), sizeof(Item), 0);
	}

	for(int i = 0; i < tamanhoDir; i++) {
		reg::copias++;
		vetDir[i] = vet[meio + 1 + i];
		LEMEMLOG((long int)(&vet[meio + 1 + i]), sizeof(Item), 0);
		ESCREVEMEMLOG((long int)(&vetDir[i]), sizeof(Item), 0);
	}

	int indEsq = 0, indDir = 0, indGeral = inicio;

	while(indEsq < tamanhoEsq && indDir < tamanhoDir) {
		if(vetEsq[indEsq].chave <= vetDir[indDir].chave) {
			vet[indGeral] = vetEsq[indEsq];
			LEMEMLOG((long int)(&vetEsq[indEsq]), sizeof(Item), 0);
			ESCREVEMEMLOG((long int)(&vet[indGeral]), sizeof(Item), 0);
			indEsq++;
		} else {
			vet[indGeral] = vetDir[indDir];
			LEMEMLOG((long int)(&vetDir[indDir]), sizeof(Item), 0);
			ESCREVEMEMLOG((long int)(&vet[indGeral]), sizeof(Item), 0);
			indDir++;
		}
		reg::comparacoes++;
		reg::copias++;
		indGeral++;
	}

	while(indEsq < tamanhoEsq) {
		reg::copias++;
		vet[indGeral] = vetEsq[indEsq];
		LEMEMLOG((long int)(&vetEsq[indEsq]), sizeof(Item), 0);
		ESCREVEMEMLOG((long int)(&vet[indGeral]), sizeof(Item), 0);
		indEsq++;
		indGeral++;
	}

	while(indDir < tamanhoDir) {
		reg::copias++;
		vet[indGeral] = vetDir[indDir];
		LEMEMLOG((long int)(&vetDir[indDir]), sizeof(Item), 0);
		ESCREVEMEMLOG((long int)(&vet[indGeral]), sizeof(Item), 0);
		indDir++;
		indGeral++;
	}

	delete[] vetEsq;
	delete[] vetDir;
}

void OrdenaMergeSort(Item *vetor, int inicio, int fim) {
	if(inicio >= fim) return;

	int meio = inicio + (fim - inicio) / 2;
	OrdenaMergeSort(vetor, inicio, meio);
	OrdenaMergeSort(vetor, meio + 1, fim);
	Junta(vetor, inicio, meio, fim);
}

void MergeSort(Item *vet, int tam) {
	OrdenaMergeSort(vet, 0, tam - 1);
}