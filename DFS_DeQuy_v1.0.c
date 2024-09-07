#include <stdio.h>
#define M 100

typedef struct{
    int A[M][M];
    int n;
}Graph;

void initGraph(Graph *G, int n){
    int i, j;
    G->n = n;
    for(i=1; i<=G->n; i++){
        for(j=1; j<=G->n; j++){
            G->A[i][j]=0;
        }
    }
}

void addEdge(Graph *G, int x, int y){
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

int adjacent(Graph *G, int x, int y){
    return G->A[x][y] != 0;
}

int degree(Graph *G, int x){
    int i;
    int deg = 0;
    for(i=1; i<=G->n; i++){
        if(adjacent(G, i, x)){
            deg++;
        }
    }
    return deg;
}

//khoi tao danh sach
typedef struct{
    int data[M];
    int size;
}List;

void makeNullList(List *L){
    L->size = 0;
}

void pushBack(List *L, int x){
    L->data[L->size] = x;
    L->size++;
}

int elementAt(List *L, int x){
    return L->data[x-1];
}

List neighbors(Graph *G, int x){
    List L;
    makeNullList(&L);
    int i;
    for(i=1; i<=G->n; i++){
        if(G->A[x][i] == 1){
            pushBack(&L, i);
        }
    }
    return L;
}
//khai bao mang ben ngoai tranh su dung trong de quy
int mark[M];
void DFS_DeQuy(Graph *G, int u){
    if(mark[u] == 1){
        return;
    }
    printf("Duyet: %d\n", u);
    mark[u]=1;
    //lay danh sach cac dinh ke
    List L = neighbors(G, u);
    int i;
    for(i=1; i<=L.size; i++){
        //lay dinh v tai vi tri i
        int v = elementAt(&L, i);
        //goi de quy dinh v
        DFS_DeQuy(G, v);
    }
}

int main(){
    Graph G;
    freopen("DFS_DeQuy.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    initGraph(&G, n);
    int u, v, i;
    for(i=1; i<=G.n; i++){
        scanf("%d%d", &u, &v);
        addEdge(&G, u, v);
    }
    for(i=1; i<=n; i++){
        //tao dinh chua duoc duyet
        mark[i]=0;
    }
    DFS_DeQuy(&G, 1);
    
    return 0;
}