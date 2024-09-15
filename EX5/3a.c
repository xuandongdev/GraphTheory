#include <stdio.h>
#define M 100

typedef struct
{
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
    return (g->A[u][v] != 0);
}

typedef struct{
    int data[M];
    int size;
}Stack;

void makeNull(Stack *s){
    s->size = -1;
}

void push(Stack *s, int x){
    s->size++;
    s->data[s->size] = x;
}

int top(Stack *s){
    return s->data[s->size];
}

void pop(Stack *s){
    s->size--;
}

int empty(Stack *s){
    return (s->size<0);
}

int mark[M];
void dfs(Graph *g, int x){
    int i;
    Stack s;
    makeNull(&s);
    push(&s, x);
    while(!empty(&s)){
        int u = top(&s);
        pop(&s);
        if(mark[u] != 0){
            continue;
        }
        printf("%d ", u);
        mark[u] = 1;
        for(i=1; i<=g->n; i++){
            if(adjacent(g, i, u)){
                push(&s, i);
            }
        }
    }
}

int main(){
    Graph g;
    int i, n, m, u, v;
    scanf("%d%d", &n, &m);
    initGraph(&g, n);
    for(i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        addEdge(&g, u, v);
    }
    for(i=1; i<=n; i++){
        mark[i]=0;
    }
    dfs(&g, 1);
    return 0;
}