#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
char grid[MAX][MAX];

typedef struct posicao{
    int linha;
    int coluna;
}posicao;

int visitado[MAX][MAX];
posicao veio_de[MAX][MAX];
posicao fila[MAX*MAX];

int main(){
    //Preenche o grid
    int M, N;
    posicao inicio, destino;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %c", &grid[i][j]);
            if(grid[i][j] != '@' && grid[i][j] != 'A' && grid[i][j] != 'R' && grid[i][j] != '.'){
                printf("Caractere invalido.\n");
                return 0;
            }
            if(grid[i][j] == 'A'){
                inicio.linha = i;
                inicio.coluna = j;
            }
            if(grid[i][j] == 'R'){
                destino.linha = i;
                destino.coluna = j;
            }
        }
    }
    //Procura caminho
    int ini = 0, fim = 0;
    posicao atual;
    int mud_linha[4] = {-1, 1, 0, 0};
    int mud_col[4] = {0, 0, -1, 1};
    int nova_linha;
    int nova_coluna;
    int achou = 0;
    fila[fim] = inicio;
    fim++;
    visitado[inicio.linha][inicio.coluna] = 1;
    while(ini < fim){
        atual = fila[ini];
        ini++;
        if(atual.coluna == destino.coluna && atual.linha == destino.linha){
            achou = 1;
            break;
        }

        for(int i = 0; i <= 3; i++){
            nova_linha = atual.linha + mud_linha[i];
            nova_coluna = atual.coluna + mud_col[i];

            if(nova_linha >= 0 && nova_linha < N && nova_coluna >= 0 && nova_coluna < M){
                if(grid[nova_linha][nova_coluna] != '@'){
                    if(!visitado[nova_linha][nova_coluna]){
                        visitado[nova_linha][nova_coluna] = 1;
                        veio_de[nova_linha][nova_coluna] = atual;
                        posicao temp;
                        temp.linha = nova_linha;
                        temp.coluna = nova_coluna;
                        fila[fim] = temp;
                        fim++;
                     }
                }
            }
        }
    }
    if(!achou){
        printf("VOU MORRER DE FOME\n");
    }else{
        //Refaz o caminho
        char caminho[MAX*MAX];
        int tamanho = 0;
        posicao atual_r = destino;
        while(!(atual_r.linha == inicio.linha && atual_r.coluna == inicio.coluna)){
            posicao anterior = veio_de[atual_r.linha][atual_r.coluna];
            if(anterior.linha > atual_r.linha){
                caminho[tamanho] = 'C';
                tamanho++;
            }else if(anterior.linha < atual_r.linha){
                caminho[tamanho] = 'B';
                tamanho++;
            }else{
                if(anterior.coluna < atual_r.coluna){
                    caminho[tamanho] = 'D';
                    tamanho++;
                }else if(anterior.coluna > atual_r.coluna){
                    caminho[tamanho] = 'E';
                    tamanho++;
                }
            }
            atual_r = anterior;
        }
        printf("AMEM\n");
        for(int i = tamanho-1; i >= 0; i--){
            printf("%c", caminho[i]);
        }
        printf("\n");
        printf("%d\n", tamanho);
    }
    return 0;
}
