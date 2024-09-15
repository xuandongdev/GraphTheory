#include <stdio.h>
#define M 100

typedef struct{
    int A[M][M];
    int n;
}Graph;

void initGraph(Graph *g, int n){
    int i, j;
    g->n = n;
    for(i=1; i<=g->n; i++){
        for(j=1; j<=g->n; j++){
            g->A[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v){
    g->A[u][v] = 1;
    g->A[v][u] = 1;
}

int adjacent(Graph *g, int u, int v){
    return g->A[u][v] != 0;
}

typedef struct
{
    int front, rear;
    int data[M];
}Queue;

void makeNull(Queue *q){
    q->front = 0;
    q->rear = -1;
}

void push(Queue *q, int u){
    q->rear++;
    q->data[q->rear] = u;
}

int emptyQueue(Queue *q){
    return (q->front > q->rear);
}

int top(Queue *q){
    return q->data[q->front];
}

void pop(Queue *q){
    q->front++;
}

void bfs(Graph *g, int x){
    int i;
    Queue q;
    makeNull(&q);
    int mark[M];
    for(i=1; i<=g->n; i++){
        mark[i] = 0;
    }
    push(&q, x);
    while (!emptyQueue(&q))
    {
        int u = top(&q);
        pop(&q);
        if(mark[u] != 0){
            continue;
        }
        printf("%d ", u);
        mark[u] = 1;
        for(i=1; i<=g->n; i++){
            if(adjacent(g, u, i)){
                push(&q, i);
            }
        }
    }
}

int main(){
    Graph G;
    int i,n,m,u,v,s;
    scanf("%d%d", &n,&m);
    initGraph(&G, n);
    for(i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        addEdge(&G, u, v);
    }
    scanf("%d", &s);
    bfs(&G, s);
    return 0;
}