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
}

int adjacent(Graph *g, int u, int v){
    return (g->A[u][v] != 0);
}

typedef struct{
    int data[M];
    int size;
}List;

void makeNullList(List *l){
    l->size = 0;
}
void pushBack(List *l, int i){
    l->data[l->size] = i;
    l->size++;
}

int element(List *l, int x){
    return l->data[x-1];
}

List neighbors(Graph *g, int x){
    List l;
    makeNullList(&l);
    int i;
    for(i=1; i<=g->n; i++){
        if(adjacent(g, x, i)){
            pushBack(&l, i);
        }
    }
    return l;
}

typedef struct{
    int data[M];
    int size;
}Stack;

void makeNull(Stack *s){
    s->size = 0;
}

void push(Stack *s, int x){
    s->data[s->size] = x;
    s->size++;
}

int top(Stack *s){
    return s->data[s->size-1];
}

void pop(Stack *s){
    s->size--;
}

int empty(Stack *s){
    return (s->size==0);
}

void dfs(Graph *g, int x){
    int i, j;
    Stack s;
    makeNull(&s);
    push(&s, x);
    int mark[M];
    for(j=1; j<=g->n; j++){
        mark[j]=0;
    }
    while(!empty(&s)){
        int u = top(&s);
        pop(&s);
        if(mark[u] == 1){
            continue;
        }
        printf("%d ", u);
        mark[u] = 1;
        List l = neighbors(g, u);
        for(i=1; i<=l.size; i++){
            //lay dinh v tai vi tri i
            int v = element(&l, i);
            if (mark[v] == 0)
            {
                push(&s, v);
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
    dfs(&g, 1);
    return 0;
}