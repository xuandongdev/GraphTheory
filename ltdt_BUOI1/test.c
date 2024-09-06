#include <stdio.h>
#define M 100

typedef struct{
    int n, m;
    int A[M][M];
}Graph;

void initGraph(Graph *G, int n){
    G->n = n;
    int i, j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            G->A[i][j]=0;
            G->A[j][i]=0;
        }
    }
    G->m=0;
}

int main(){
    Graph G;
    int n;
    int i, j, k;
    scanf("%d", &n);
    initGraph(&G, n);
    for(i=1; i<=n; i++){
        for(j = 1; j<=n; j++){
            scanf("%d", &G.A[i][j]);
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i>j) continue;
            for(k=1; k<=n; k++){
                printf("%d %d\n", i, j);
            }
        }
    }
}
