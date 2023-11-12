#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int media(int a, int b){
	int res = (a+b)/2;
	return res;
}

void copiaTabuleiro(int t,char t1[t][t],char t2[t][t]){
	for(int i=0;i<t;i++){
		for(int j=0;j<t; j++){
			t1[i][j] = t2[i][j];
		}
	}
}

void imprime(int n, char t[n][n], int m){
	printf("==============\n");
	printf("--\n%i\n--\n",m);
	for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(t[i][j]=='p') printf("\033[1;32m%x%x\e[0;37m ",j,i);
            else if(t[i][j]=='b') printf("\033[1;31m%x%x\e[0;37m ",j,i);
            else if(t[i][j]=='o') printf("\033[1;37m%x%x\e[0;37m ",j,i);
            else if(t[i][j]=='P') printf("\033[1;34m%x%x\e[0;37m ",j,i);
            else if(t[i][j]=='B') printf("\033[1;35m%x%x\e[0;37m ",j,i);
            else printf("\033[1;37m%c\e[0;37m ",t[i][j]);
        }
        printf("\n");
	}
	printf("==============\n");
	// sleep(2);
}

int contaMovs(int tam, char tb[tam][tam], int x, int y){
	char temp[tam][tam];
	copiaTabuleiro(tam, temp, tb);
	char inimiga = tb[x][y] == 'b' ? 'p' : 'b';
	int xf,yf,contagem=0,maior=0;


	xf=x-2;
	yf=y-2;
	if(!(xf<0 || yf<0) && (xf<tam && yf<tam)){
		if(tb[xf][yf]=='o' && tb[media(xf,x)][media(yf,y)]==inimiga){
			temp[xf][yf]=temp[x][y];
			temp[media(xf,x)][media(yf,y)]='o';
			temp[x][y]='o';
			// imprime(tam,temp,maior);
			contagem = contaMovs(tam,temp,xf,yf)+1;
			copiaTabuleiro(tam, temp, tb);
			// imprime(tam,temp,maior);
		}
	}
	if(maior<contagem) maior = contagem;

	contagem=0;

	xf=x-2;
	yf=y+2;
	if(!(xf<0 || yf<0) && (xf<tam && yf<tam)){
		if(tb[xf][yf]=='o' && tb[media(xf,x)][media(yf,y)]==inimiga){
			temp[xf][yf]=temp[x][y];
			temp[media(xf,x)][media(yf,y)]='o';
			temp[x][y]='o';
			// imprime(tam,temp,maior);
			contagem = contaMovs(tam,temp,xf,yf)+1;
			copiaTabuleiro(tam, temp, tb);
			// imprime(tam,temp,maior);
		}
	}
	if(maior<contagem) maior = contagem;

	contagem=0;

	xf=x+2;
	yf=y+2;
	if(!(xf<0 || yf<0) && (xf<tam && yf<tam)){
		if(tb[xf][yf]=='o' && tb[media(xf,x)][media(yf,y)]==inimiga){
			temp[xf][yf]=temp[x][y];
			temp[media(xf,x)][media(yf,y)]='o';
			temp[x][y]='o';
			// imprime(tam,temp,maior);
			contagem = contaMovs(tam,temp,xf,yf)+1;
			copiaTabuleiro(tam, temp, tb);
			// imprime(tam,temp,maior);
		}
	}
	if(maior<contagem) maior = contagem;

	contagem=0;

	xf=x+2;
	yf=y-2;
	if(!(xf<0 || yf<0) && (xf<tam && yf<tam)){
		if(tb[xf][yf]=='o' && tb[media(xf,x)][media(yf,y)]==inimiga){
			temp[xf][yf]=temp[x][y];
			temp[media(xf,x)][media(yf,y)]='o';
			temp[x][y]='o';
			// imprime(tam,temp,maior);
			contagem = contaMovs(tam,temp,xf,yf)+1;
			copiaTabuleiro(tam, temp, tb);
			// imprime(tam,temp,maior);
		}
	}
	if(maior<contagem) maior = contagem;

	contagem=0;

	return maior;
}

int main(int argc, char const *argv[]){
	// leitura
	int tam;
	scanf("%i",&tam);

	char tab[tam][tam];
	for(int i=0;i<tam;i++){
		getchar();
		for(int j=0;j<tam;j++){
			tab[i][j]=getchar();
		}
	}
	// int tam = 12;
	// char tab[12][12] = {
	// 	'o',' ','o',' ','o',' ','o',' ','o',' ','o',' ',
	// 	' ','o',' ','p',' ','p',' ','p',' ','o',' ','p',
	// 	'o',' ','o',' ','o',' ','o',' ','b',' ','o',' ',
	// 	' ','o',' ','p',' ','p',' ','o',' ','p',' ','p',
	// 	'o',' ','o',' ','o',' ','o',' ','b',' ','o',' ',
	// 	' ','o',' ','p',' ','p',' ','p',' ','o',' ','p',
	// 	'o',' ','o',' ','o',' ','o',' ','p',' ','o',' ',
	// 	' ','o',' ','p',' ','p',' ','p',' ','b',' ','o',
	// 	'o',' ','o',' ','o',' ','b',' ','p',' ','p',' ',
	// 	' ','o',' ','p',' ','p',' ','b',' ','o',' ','b',
	// 	'o',' ','b',' ','o',' ','o',' ','o',' ','b',' ',
	// 	' ','b',' ','b',' ','b',' ','b',' ','b',' ','b'
	// };

    int x, y, n=0, tVet=0;
	int *vet = (int *) calloc(tVet, sizeof(int));

    for(int i=0; i<tam; i++){
		if(i%2==0){
			for(int j=0; j<tam; j++){
				if(tab[i][j]=='b'){
					int a = contaMovs(tam,tab,i,j);
					if(a>0){
						tVet+=3;
						vet = realloc(vet,tVet*sizeof(int));
						vet[tVet-1] = a;
						vet[tVet-2] = i;
						vet[tVet-3] = j;
					}
					if(n<a){
						n = a;
						x = j;
						y = i;
					}
				}
			}
		}
		else{
			for(int j=tam-1; j>=0; j--){
				if(tab[i][j]=='b'){
					int a = contaMovs(tam,tab,i,j);
					if(a>0){
						tVet+=3;
						vet = realloc(vet,tVet*sizeof(int));
						vet[tVet-1] = a;
						vet[tVet-2] = i;
						vet[tVet-3] = j;
					}
					if(n<a){
						n = a;
						x = j;
						y = i;
					}
				}
			}
		}
	}

	//impressão 
    // imprime(tam, tab,0);

	printf("%i %i %i\n",y,x,n);

	for(int i=0; i<tVet; i+=3){
		printf("%i %i %i\n",vet[i+1],vet[i],vet[i+2]);
	}

	free(vet);
	return 0;
}