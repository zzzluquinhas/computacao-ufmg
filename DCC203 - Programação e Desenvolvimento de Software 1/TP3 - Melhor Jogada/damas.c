#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    //leitura
    int n;
    scanf("%i",&n);
    
    char tab[n][n];
    for(int i=0;i<n;i++){
        getchar();
        for(int j=0;j<n;j++){
            tab[i][j]=getchar();
            if(tab[i][j]=='b' && i==0){
                tab[i][j] = 'B';
            }
            else if(tab[i][j]=='p' && i==n-1){
                tab[i][j] = 'P';
            }
        }
    }

    //execução
    int xi=0,yi=0,xf=0,yf=0,fim=0, ptPreta=0, ptBranca=0;
    
    do{

        scanf("%i%i%i%i",&xi,&yi,&xf,&yf); //lê o movimento
        if(xi==yi && xi==xf && xi==yf) break; //se forem 4 inteiros iguais, termina o jogo

        if(tab[xi][yi]=='b' || tab[xi][yi]=='p'){ //se a peça inicial for branca ou preta...
            int ctrl = tab[xi][yi]=='b'? 1 : 2; //variável de controle: peça branca=1, peça preta=2
            int pot1 = (1 * pow(-1,ctrl)); //variável de controle: -1 pras brancas e +1 pras pretas
            char inimiga = tab[xi][yi]=='b'? 'p' : 'b'; //variável de controle: pega a peça da cor oposta
            char damaInimiga = tab[xi][yi]=='b'? 'P' : 'B'; //variável de controle: pega a dama da cor oposta
            if(xf==xi+pot1){ //se o jogador movimentou 1 casa pra frente...
                if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                    if(xf==n-1 || xf==0){ //se a peça chegou na borda de cima ou de baixo do tabuleiro...
                        tab[xf][yf] = tab[xi][yi]=='b' ? 'B' : 'P'; //a peça vira uma dama da cor dela
                        tab[xi][yi]=='b' ? ptBranca++ : ptPreta++; //+1 ponto
                    }
                    else tab[xf][yf] = tab[xi][yi]; //ocupa a casa destino
                    tab[xi][yi] = 'o'; //esvazia a casa inicial
                }
            }
            else if(xf==xi+(2*pot1)){ //se o jogador movimentou 2 casas pra frente...
                if(yf==yi+(2*pot1) || yf==yi-(2*pot1)){ //se o jogador movimentou 2 casas pra direita ou esquerda...
                    int ctrl2 = yf==yi+(2*pot1) ? 2 : 1; //variável de controle que alterna entre 2 e 1 dependendo da direção que movimentou
                    int pot2 = (pot1 * pow(-1,ctrl2)); //variável de controle que alterna entre 1 e -1 dependendo da direção que movimentou
                    if(tab[xi+pot1][yi+pot2]==inimiga || tab[xi+pot1][yi+pot2]==damaInimiga){ //se a casa entre a inicial e a destino for uma peça inimiga...
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                            tab[xi+pot1][yi+pot2]='o'; //exclui a peça inimiga
                            if(xf==n-1 || xf==0){
                                tab[xf][yf] = tab[xi][yi]=='b' ? 'B' : 'P'; //se a peça chegou na borda de cima ou de baixo do tabuleiro, a peça vira uma dama da cor dela
                                tab[xi][yi]=='b' ? ptBranca++ : ptPreta++; //+1 ponto
                            }
                            else tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            inimiga=='p' || damaInimiga=='P' ? ptBranca++ : ptPreta++; //+1 ponto
                        }
                    }
                }
            }
        }
        else if(tab[xi][yi]=='B' || tab[xi][yi]=='P'){ //se a peça inicial for uma dama branca ou preta...
            char inimiga = tab[xi][yi]=='B'? 'p' : 'b'; //variável de controle: pega a peça da cor oposta
            char damaInimiga = tab[xi][yi]=='B'? 'P' : 'B'; //variável de controle: pega a dama da cor oposta
            if(xf==xi+1 || xf==xi-1){ //se o jogador movimentou 1 casa pra frente ou pra trás...
                if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...
                    tab[xf][yf] = tab[xi][yi]; //ocupa a casa destino
                    tab[xi][yi] = 'o'; //esvazia a casa inicial
                }
            }
            else if(xf==xi+2 || xf==xi-2){ //se o jogador movimentou 2 casas pra frente ou pra trás...
                if(yf==yi+2 || yf==yi-2){ //se o jogador movimentou 2 casas pra direita ou esquerda...
                    int ctrl = xf==xi+2? 2 : 1; //variável de controle que alterna entre 2 e 1 dependendo se foi pra direita ou esquerda
                    int pot1 = (1 * pow(-1,ctrl)); //variável de controle que alterna entre +1 e -1 dependendo se foi pra direita ou esquerda
                    int ctrl2 = yf==yi+2 ? 2 : 1; //variável de controle que alterna entre 2 e 1 dependendo se foi pra frente ou trás
                    int pot2 = (1 * pow(-1,ctrl2)); //variável de controle que alterna entre +1 e -1 dependendo se foi pra frente ou trás
                    if(tab[xi+pot1][yi+pot2]==inimiga || tab[xi+pot1][yi+pot2]==damaInimiga){ //se a casa entre a inicial e a destino for uma peça inimiga...
                        if(tab[xf][yf] == 'o'){ //se a casa destino estiver vazia...                
                            tab[xi+pot1][yi+pot2]='o'; //exclui a peça inimiga
                            tab[xf][yf]=tab[xi][yi]; //ocupa a casa destino
                            tab[xi][yi]='o'; //esvazia a casa inicial
                            inimiga=='p' || inimiga=='P' ? ptBranca++ : ptPreta++; //+1 ponto
                        }
                    }
                }
            }
        }
    }while(1);
    
    printf("PRETAS %i\nBRANCAS %i\n",ptPreta,ptBranca);
    ptBranca>ptPreta ? printf("BRANCAS VENCERAM\n") : ptBranca<ptPreta ? printf("PRETAS VENCERAM\n") : printf("EMPATE\n");

    return 0;
}