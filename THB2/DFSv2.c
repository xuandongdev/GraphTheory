#include <stdio.h>
#define M 100

typedef struct{
	int A[M][M];
	int n;
}Graph;

void init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->n; j++){
			G->A[i][j] = 0;
		}
	}
}

void add_edge(Graph *G, int u, int v){
	G->A[u][v] = 1;
}

int adjacent(Graph *G, int u, int v){
	return (G->A[u][v] != 0);
}

int degree(Graph *G, int x){
	int i, deg = 0;
	for(i=1; i<=G->n; i++){
		if(adjacent(G, x, i)){
			deg++;
		}
	}
	return deg;
}

typedef struct{
	int data[M];
	int size;
}Stack;

void makeNullStack(Stack *S){
	S->size = 0;
}

void push(Stack *S, int x){
	S->data[S->size] = x;
	S->size++;
}

int top(Stack *S){
	return S->data[S->size];
}

void pop(Stack *S){
	S->size--;
}

int empty(Stack *S){
	return S->size < 0;
}

void DFS(Graph *G, int x){
	int i, j, mark[M];
	Stack S;
	makeNullStack(&S);
	push(&S, x);
	for(i=1; i<=G->n; i++){
		mark[i] = 0;
	}
	while(!empty(&S)){
		int u = top(&S);
		pop(&S);
		if(mark[u] != 0){
			continue;
		}
		printf("%d\n", u);
		mark[u] = 1;
		for(j=G->n; j>=1; j--){
			if(adjacent(G, j, u)){
				push(&S, u);
			}
		}
	}
}
int main(){
	int i, n, m, u, v;
	Graph G;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i=1; i<=m; i++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	DFS(&G, 1);
}
