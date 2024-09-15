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
    return g->A[u][v] = 1;
}

typedef struct{
    int data[M];
    int size;
}List;

void makeNullList(List *l){
    l->size = 0;
}

void pushBack(List *l, int x){
    l->data[l->size] = x;
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
    int size
}Stack;

void makeNullStack(Stack *s){
    s->size = 0;
}

void pushStack(Stack *s, int x){
    s->data[s->size] = x;
    s->size++;
}

int top(Stack *s, int x){
    return s->data[x-1];
}

void pop(Stack *s){
    s->size--;
}

int empty(Stack *s){
    return s->size = 0;
}

List dfs(Graph *g, int x){
    Stack s;
    makeNullStack(&s);
    int i, j;
    pushStack(&s, x);
    List markDFS;
    makeNullList(&markDFS);
    int mark[M];
    for(i=1; i<=g->n; i++){
        mark[i] = 0;
    } 
    while (!empty(&s))
    {
        int u = top(&s, x);
        pop(&s);
        if(mark[u] == 1){
            continue;
        }
        pushBack(&markDFS, u);
        mark[u] = 1;
        List l = neighbors(g, u);
        for(i=1; i<=l.size; i++){
            int v = element(&l, i);
            if(mark[i] == 0){
                pushStack(&s, i);
            }
        }
    }
    return markDFS;
}

int main(){
    Graph g;
    int i, j, n, m, u, v;
    scanf("%d%d", &n, &m);
    initGraph(&g, n);
    for(i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        addEdge(&g, u, v);
    }
    int mark_dfs[M];
    for(i=1; i<=g.n; i++){
        if(mark_dfs[i] == 0){
            List DFS = dfs(&g, i);
            for(j=1; j<=DFS.size; j++){
                printf("%d ", element(&DFS, j));
                mark_dfs[element(&DFS, j)] = 1;
            }
        }        
    }
    return 0;
}