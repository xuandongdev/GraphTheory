#include <stdio.h>
#define M 100
typedef int ElementTpye;

typedef struct {
    int A[M][M];
    int n;
}Graph;

void init_graph(Graph *G, int n){
    int i, j;
    G->n = n;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            G->A[i][j]=0;
        }
    }
}

void add_edge(Graph *G, int u, int v){
    G->A[u][v] = 1;
}

int adjacent(Graph *G, int x, int y){
    return (G->A[x][y] !=0);
}

int degree(Graph *G, int x){
    int i, deg = 0;
    for(i=1; i<=G->n; i++){
        if(adjacent(G, i, x)){
            deg++;
        }
    }
    return deg;
}

typedef struct{
	ElementType data[M];
	int front, rear;
}Queue;

void makeNull(Queue *Q){
	Q->front = 0;
	Q->rear = -1;
}

void enQueue(Queue *Q, int x){
	Q->rear++;
	Q->data[Q->rear] = x;
}

ElementTpye front(Queue *Q){
	return Q->data[Q->front];
}

void deQueue(Queue *Q){
	Q->front++;
}

int empty(Queue *Q){
	return Q->front > Q->rear;
}

int mark[M];
void BFS(Graph *G, int x){
	int i;
	Queue Q;
	makeNull(&Q);
	enQueue(&Q, x);
	while(!empty(&Q)){
		int u = front(&Q);
		deQueue(&Q);
		if(mark[u]!=0){
			continue;
		}
		printf("%d\n", u);
		mark[u] = 1;
		for( i = 1; i<=G->n; i++){
			if(adjacent(G, x, i)){
				enQueue(&Q, i);
			}
		}
	}
}

int main(){
	
	int i, n, m, u, v, x;
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for(i=1; i<=m; i++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
//	scanf("%d", &x);
	for(i=1; i<=G.n; i++){
		mark[i] = 0;
	}
	BFS(&G, 1);
	return 0;
}
