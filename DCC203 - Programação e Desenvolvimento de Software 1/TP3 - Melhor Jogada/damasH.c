#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    // leitura
     int n;
     scanf("%i",&n);
    
     char tab[n][n];
     for(int i=0;i<n;i++){
         getchar();
         for(int j=0;j<n;j++){
             tab[i][j]=getchar();
             if(tab[i][j]=='b'){// && i==0){
                 tab[i][j] = 'B';
             }
             else if(tab[i][j]=='p'){// && i==n-1){
                 tab[i][j] = 'P';    
             }
         }
     }

    //execução
    int xi=0,yi=0,xf=0,yf=0,fim=0, ptPreta=0, ptBranca=0;
    // int n=8;
    // char tab[8][8] = {' ','p',' ','p',' ','p',' ','p','p',' ','p',' ','p',' ','p',' ',' ','p',' ','p',' ','p',' ','p','o',' ','o',' ','o',' ','o',' ',' ','o',' ','o',' ','o',' ','o','b',' ','b',' ','b',' ','b',' ',' ','b',' ','b',' ','b',' ','b','b',' ','b',' ','b',' ','b',' '};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tab[i][j]=='b' && i==0){
                tab[i][j] = 'B';
            }
            else if(tab[i][j]=='p' && i==n-1){
                tab[i][j] = 'P';
            }
        }
    }

    do{
        system("clear");
        printf("%i,%i para %i,%i\n",xi,yi,xf,yf);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(tab[i][j]=='p') printf("\033[1;32m%i%i\e[0;37m ",i,j);
                else if(tab[i][j]=='b') printf("\033[1;31m%i%i\e[0;37m ",i,j);
                else if(tab[i][j]=='o') printf("\033[1;37m%i%i\e[0;37m ",i,j);
                else if(tab[i][j]=='P') printf("\033[1;34m%i%i\e[0;37m ",i,j);
                else if(tab[i][j]=='B') printf("\033[1;35m%i%i\e[0;37m ",i,j);
                else printf("\033[1;37m%c\e[0;37m ",tab[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");

        scanf("%i%i%i%i",&xi,&yi,&xf,&yf); //lê o movimento
        if(xi==yi && xi==xf && xi==yf) break; //se forem 4 inteiros iguais, termina o jogo

        if(tab[xi][yi]=='b'){
            if(xf==xi-1){ //se o jogador das brancas movimentou 1 casa...
                if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                    if(xf==0){
                        tab[xf][yf] = 'B';
                        ptBranca++; //+1 ponto
                    }
                    else tab[xf][yf] = tab[xi][yi]; //ocupa a casa destino
                    tab[xi][yi] = 'o'; //esvazia a casa inicial
                }
                else printf("movimento inválido\n"); //se a casa destino não estiver vazia, erro
            }
            else if(xf==xi-2){ //se o jogador das brancas movimentou 2 casas...
                if(yf==yi-2){ //se o jogador movimentou 2 casas pra esquerda...
                    if(tab[xi-1][yi-1]=='p'||tab[xi-1][yi-1]=='P'){ //se a casa entre a inicial e a destino for uma peça inimiga...
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi-1][yi-1]='o'; //exclui a peça inimiga
                            if(xf==0){
                                tab[xf][yf] = 'B';
                                ptBranca++; //+1 ponto
                            }
                            else tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            ptBranca++; //+1 ponto
                        }
                    }
                    else printf("movimento inválido\n"); //se a casa e entre a inicial e a destino não for uma peça inimiga, erro
                }
                else if(yf==yi+2){ //se o jogador movimentou 2 casas pra direita...
                    if(tab[xi-1][yi+1]=='p'||tab[xi-1][yi+1]=='P'){ //se a casa entre a inicial e a destino for uma peça inimiga...
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi-1][yi+1]='o'; //exclui a peça inimiga
                            if(xf==0){
                                tab[xf][yf] = 'B';
                                ptBranca++; //+1 ponto
                            }
                            else tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            ptBranca++; //+1 ponto
                        }
                    }
                    else printf("movimento inválido\n"); //se a casa e entre a inicial e a destino não for uma peça inimiga, erro
                }
                else printf("movimento inválido\n");
            }
            else printf("movimento inválido\n");
        }

        else if(tab[xi][yi]=='p'){
            if(xf==xi+1){ //se o jogador das pretas movimentou 1 casa...
                if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                    if(xf==0){
                        tab[xf][yf] = 'P';
                        ptPreta++; //+1 ponto
                    }
                    else tab[xf][yf] = tab[xi][yi]; //ocupa a casa destino
                    tab[xi][yi] = 'o'; //esvazia a casa inicial
                }
                else printf("movimento inválido\n"); //se a casa destino não estiver vazia, erro
            }
            else if(xf==xi+2){ //se o jogador das pretas movimentou 2 casas...
                if(yf==yi-2){ //se o jogador movimentou 2 casas pra esquerda...
                    if(tab[xi+1][yi-1]=='b'||tab[xi+1][yi-1]=='B'){ //se a casa entre a inicial e a destino for uma peça inimiga...
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi+1][yi-1]='o'; //exclui a peça inimiga
                            if(xf==n-1){
                                tab[xf][yf] = 'P';
                                ptPreta++; //+1 ponto
                            }
                            else tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            ptPreta++; //+1 ponto
                        }
                    }
                    else printf("movimento inválido\n"); //se a casa e entre a inicial e a destino não for uma peça inimiga, erro
                }
                else if(yf==yi+2){ //se o jogador movimentou 2 casas pra direita...
                    if(tab[xi+1][yi+1]=='b'||tab[xi+1][yi+1]=='B'){ //se a casa entre a inicial e a destino for uma peça inimiga...
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi+1][yi+1]='o'; //exclui a peça inimiga
                            if(xf==n-1){
                                tab[xf][yf] = 'P';
                                ptPreta++; //+1 ponto
                            }
                            else tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            ptPreta++; //+1 ponto
                        }
                    }
                    else printf("movimento inválido\n"); //se a casa e entre a inicial e a destino não for uma peça inimiga, erro
                }
                else printf("movimento inválido\n");
            }
            else printf("movimento inválido\n");
        }

        else if(tab[xi][yi]=='B'){
            if(xf==xi-1){ //se o jogador das brancas movimentou 1 casa...
                if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                    tab[xf][yf] = tab[xi][yi]; //ocupa a casa destino
                    tab[xi][yi] = 'o'; //esvazia a casa inicial
                }
                else printf("movimento inválido\n"); //se a casa destino não estiver vazia, erro
            }
            else if(xf==xi-2){ //se o jogador das brancas movimentou 2 casas...
                if(yf==yi+2){ //se o jogador movimentou 2 casas pra direita...
                    if(tab[xi-1][yi+1]=='p'||tab[xi-1][yi+1]=='P'){
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi-1][yi+1]='o'; //exclui a peça inimiga
                            tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            ptBranca++; //+1 ponto
                        }
                        else printf("movimento inválido\n");
                    }
                    else printf("movimento inválido\n");
                }
                else if(yf==yi-2){ //se o jogador movimentou 2 casas pra esquerda...
                    if(tab[xi-1][yi-1]=='p'||tab[xi-1][yi-1]=='P'){
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi-1][yi-1]='o'; //exclui a peça inimiga
                            tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            ptBranca++; //+1 ponto
                        }
                        else printf("movimento inválido\n");
                    }
                    else printf("movimento inválido\n");
                }
                else printf("movimento inválido\n");
            }
            else if(xf==xi+2){ //se o jogador das brancas movimentou 2 casas...
                if(yf==yi+2){ //se o jogador movimentou 2 casas pra direita...
                    if(tab[xi+1][yi+1]=='p'||tab[xi+1][yi+1]=='P'){
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi+1][yi+1]='o'; //exclui a peça inimiga
                            tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            ptBranca++; //+1 ponto
                        }
                        else printf("movimento inválido\n");
                    }
                    else printf("movimento inválido\n");
                }
                else if(yf==yi-2){ //se o jogador movimentou 2 casas pra esquerda...
                    if(tab[xi+1][yi-1]=='p'||tab[xi+1][yi-1]=='P'){
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi+1][yi-1]='o'; //exclui a peça inimiga
                            tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            ptBranca++; //+1 ponto
                        }
                        else printf("movimento inválido\n");
                    }
                    else printf("movimento inválido\n");
                }
                else printf("movimento inválido\n");
            }
            else printf("movimento inválido\n");
        }

        else if(tab[xi][yi]=='P'){
            if(xf==xi+1){ //se o jogador das pretas movimentou 1 casa...
                if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                    tab[xf][yf] = tab[xi][yi]; //ocupa a casa destino
                    tab[xi][yi] = 'o'; //esvazia a casa inicial
                }
                else printf("movimento inválido\n"); //se a casa destino não estiver vazia, erro
            }
            else if(xf==xi+2){ //se o jogador das pretas movimentou 2 casas...
                if(yf==yi+2){ //se o jogador movimentou 2 casas pra direita...
                    if(tab[xi+1][yi+1]=='b'||tab[xi+1][yi+1]=='B'){
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi+1][yi+1]='o'; //exclui a peça inimiga
                            tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            ptPreta++; //+1 ponto
                        }
                        else printf("movimento inválido\n");
                    }
                    else printf("movimento inválido\n");
                }
                else if(yf==yi-2){ //se o jogador movimentou 2 casas pra esquerda...
                    if(tab[xi+1][yi-1]=='b'||tab[xi+1][yi-1]=='B'){
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi+1][yi-1]='o'; //exclui a peça inimiga
                            tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            ptPreta++; //+1 ponto
                        }
                        else printf("movimento inválido\n");
                    }
                    else printf("movimento inválido\n");
                }
                else printf("movimento inválido\n");
            }
            else printf("movimento inválido\n");
        }
        else printf("movimento inválido\n");
    }while(1);

    //impressão 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(tab[i][j]=='p') printf("\033[1;32m%i%i\e[0;37m ",i,j);
            else if(tab[i][j]=='b') printf("\033[1;31m%i%i\e[0;37m ",i,j);
            else if(tab[i][j]=='o') printf("\033[1;37m%i%i\e[0;37m ",i,j);
            else if(tab[i][j]=='P') printf("\033[1;34m%i%i\e[0;37m ",i,j);
            else if(tab[i][j]=='B') printf("\033[1;35m%i%i\e[0;37m ",i,j);
            else printf("\033[1;37m%c\e[0;37m ",tab[i][j]);
        }
        printf("\n");
    }
    printf("PRETAS: %i\nBRANCAS: %i\n",ptPreta,ptBranca);
    ptBranca>ptPreta ? printf("BRANCAS VENCERAM\n") : ptBranca<ptPreta ? printf("PRETAS VENCERAM\n") : printf("EMPATE\n");

    return 0;
}