#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

typedef struct {
	double codigo;
	char nome[50];
	int qtd;
	float preco;
	char estado[2];
}produto_t;

int converte(char const *arr, char op){
	char *p;
	int a;
	double b;

    errno = 0;
    long conv = strtol(arr, &p, 10);

    if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {
        printf("erroo\n");
    } else {
        a = conv;
        b = conv;
    }
    if(op == 'i') return a;
    else if(op == 'd') return b;
    else return -1;

}

void ordena(produto_t *lista, int tam) {
	produto_t temp;
	for (int i = 0; i < tam; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (strcmp(lista[j].nome, lista[i].nome) < 0) {
				temp = lista[i];
				lista[i] = lista[j];
				lista[j] = temp;
			}
		}
	}
}
              
void opcao1(produto_t *lista, int tam, const char *nomeArq){
	ordena(lista, tam);

	FILE *saida;
	saida = fopen(nomeArq,"w");

	for(int i=0;i<tam;i++){
		fprintf(saida, "%.0lf\n", lista[i].codigo);
		fprintf(saida, "%s\n", lista[i].nome);
		fprintf(saida, "%i\n", lista[i].qtd);
		fprintf(saida, "%.2f\n", lista[i].preco);
		fprintf(saida, "%s\n", lista[i].estado);
	}

	fclose(saida);
}

void opcao2(produto_t *lista, int tam, const char *c){
	double cod = converte(c,'d');
	for(int i=0;i<tam;i++){
		if(lista[i].codigo == cod){
			printf("%.0lf\n%s\n%i\n%.2f\n%s\n",lista[i].codigo,lista[i].nome,lista[i].qtd,lista[i].preco,lista[i].estado);
		}
	}
}

void opcao3(produto_t *lista, int tam){
	int indiceMenor=0;
	for(int i=0;i<tam;i++){
		if(lista[indiceMenor].qtd > lista[i].qtd){
			indiceMenor = i;
		}
	}
	printf("%.0lf\n%s\n%i\n%.2f\n%s\n",lista[indiceMenor].codigo,lista[indiceMenor].nome,lista[indiceMenor].qtd,lista[indiceMenor].preco,lista[indiceMenor].estado);
}

void opcao4(produto_t *lista, int tam, const char *estado){
	produto_t filtraEstado[tam];
    	
	int j=0;
	for(int i=0;i<tam;i++){
		if(strcmp(lista[i].estado,estado)==0){
			filtraEstado[j] = lista[i];
			j++;
		}
	}
	ordena(filtraEstado, j);

	for(int i=0;i<j;i++){
		printf("%.0lf\n", filtraEstado[i].codigo);
		printf("%s\n", filtraEstado[i].nome);
		printf("%i\n", filtraEstado[i].qtd);
		printf("%.2f\n", filtraEstado[i].preco);
		printf("%s\n", filtraEstado[i].estado);
	}
}

void opcao5(produto_t *lista, int tam, const char *estado){
	produto_t filtraEstado[tam];
    	
	int j=0;
	for(int i=0;i<tam;i++){
		if(strcmp(lista[i].estado,estado)==0){
			filtraEstado[j] = lista[i];
			j++;
		}
	}
	opcao3(filtraEstado, j);
}

void opcao6(produto_t *lista, int tam){
	double somaQtds=0;
	for(int i=0;i<tam;i++){
		somaQtds += lista[i].qtd;
	}
	printf("%.0lf\n",somaQtds);
}

int main(int argc, char const *argv[]){
	FILE *arq;
	arq = fopen(argv[1], "r");
	if(arq==NULL){
		printf("erro na abertura do aquivo\n");
		system("pause");
		exit(1);
	}
	int qtdProd;

	rewind(arq);
	fscanf(arq,"%i",&qtdProd);
	produto_t prod[qtdProd];
	produto_t prTemp[qtdProd];

	for(int i=0;i<qtdProd;i++){
		fscanf(arq,"%lf %[^\n]",&prod[i].codigo,prod[i].nome);
		fscanf(arq,"%i %f %[^\n]",&prod[i].qtd,&prod[i].preco,prod[i].estado);

		prTemp[i].codigo = prod[i].codigo;
		strcpy(prTemp[i].nome,prod[i].nome);
		prTemp[i].preco = prod[i].preco;
		prTemp[i].qtd = prod[i].qtd;
		strcpy(prTemp[i].estado,prod[i].estado);

		if(feof(arq)) break;
	}	
	fclose(arq);

    int num = converte(argv[2],'i');

	switch(num){
		case 1:
			opcao1(prTemp, qtdProd, argv[3]);
			break;
		case 2:
    		opcao2(prod, qtdProd, argv[3]);
			break;
		case 3:
			opcao3(prod, qtdProd);
			break;
		case 4:
	    	opcao4(prod, qtdProd, argv[3]);
			break;
		case 5:
	    	opcao5(prod, qtdProd, argv[3]);
			break;
		case 6:
	    	opcao6(prod, qtdProd);
			break;
		default:
			printf("erro na escolha da opção\n");
			break;
	}

	return 0;
}