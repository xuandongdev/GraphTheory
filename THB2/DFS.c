#include <stdio.h>
#define M 100

typedef struct{
    int A[M][M];
    int n;
}Graph;

void initGraph(Graph *G, int n){
    int i, j;
    G->n = n;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            G->A[i][j] = 0;
        }
    }
}

void addEdge(Graph *G, int x, int y){
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

int adjacent(Graph *G, int x, int y){
    return (G->A[x][y] != 0);
}

int degree(Graph *G, int x){
    int deg = 0;
    int i;
    for(i = 1; i <= G->n; i++){
        if(adjacent(G, x, i)){
            deg++;
        }
    }
    return deg;
}

//khai bao list
typedef struct{
    int data[M];
    int size;
}List;

void makeNull(List *L){
    L->size = 0;
}

void pushBack(List *L, int x){
    L->data[L->size] = x;
    L->size++;
}

int elementAt(List *L, int i){
    return L->data[i-1];
}

List neighbors(Graph *G, int x){
    List L;
    makeNull(&L);
    int i;
    for(i = 1; i<=G->n; i++){
        if(G->A[i][x]==1){
            pushBack(&L, i);
        }
    }
    return L;
}
//khoi tao ngan xep
typedef struct{
    int data[M];
    int size;
}Stack;

void makeNullStack(Stack *S){
    S->size = 0;
}

int isEmpty(Stack *S){
    return S->size == 0;
}

//them phan tu vao stack
void pushStack(Stack *S, int x){
    S->data[S->size] = x;
    S->size++;
}

//lay phan tu trong stack
int top(Stack *S){
    return (S->data[S->size-1]);
}

//xoa phan tu trong stack
void pop(Stack *S){
    S->size--;
}

List DFS(Graph *G, int x){
    Stack S;
    makeNullStack(&S);
    //dua dinh x vao stack
    pushStack(&S, x);
    List L_DFS;
    makeNull(&L_DFS);
    //lay dinh trong stack
    int mark[M];
    int i;
    //khoi tao cac dinh chua duyet
    for(i=1; i<=G->n; i++){
        mark[i]=0;
    }
    while(!isEmpty(&S)){
        int u = top(&S);  //dinh u
        pop(&S);
        if (mark[u] == 1){
            continue;
        }
        //dua u vao list (duyet u)
        pushBack(&L_DFS, u);
        mark[u] = 1;
        //khai bao danh sach dinh ke
        List L = neighbors(G, u);
        for(i=1; i<=L.size; i++){
            int v = elementAt(&L, i);   //lay dinh v tai vi tri i
            if(mark[v] == 0){
                //neu v chua duoc duyet => dua v vao ngan xep
                pushStack(&S, v);
            }
        }
    }
    return L_DFS;
}

int main(){
    Graph G;
    int n, m;
    scanf("%d%d", &n, &m);
    initGraph(&G, n);
    int e;  //so luong cung
    int u, v;
    int i,j;
    for(e = 1; e <= m; e++){
        scanf("%d%d", &u, &v);
        addEdge(&G, u, v);
    }
    //mark ca do thi
    int markDFS[M];
    for(i=1; i<=G.n; i++){
        markDFS[i] = 0;
    }
    //neu dinh chua duyet thi tiep tuc duyet
    for(i=1; i<=G.n; i++){
        //neu chua duyet thi bat dau duyet
        if(markDFS[i] == 0){
            List dfs = DFS(&G, i);
            //in danh sach
            for(i=j; j<=dfs.size; j++){
                printf("Duyet: %d\n", elementAt(&dfs, j));
                markDFS[elementAt(&dfs, j)] = 1;    //danh dau markDFS cua dinh tai vi tri j
            }
        }
    }
    return 0;
}
