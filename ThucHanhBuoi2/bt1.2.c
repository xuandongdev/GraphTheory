#include <stdio.h>
#define M 100

typedef struct {
    int A[M][M];
    int n;
}Graph;

void initGraph(Graph *G, int n){
    int i, j;
    G->n = n;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            G->A[i][j]=0;
        }
    }
}

void addEdge(Graph *G, int u, int v){
    G->A[u][v] = 1;
    G->A[v][u] = 1;
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

typedef struct
{
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

int elemantAt(List *L, int x){
    return L->data[x-1];
}

List neighbors(Graph *G, int x){
    List L;
    makeNull(&L);
    int i;
    for(i=1; i<=G->n; i++){
        if(G->A[i][x] == 1){
            pushBack(&L, i);
        }
    }
    return L;
}

typedef struct{
    int dataQ[M];
    int front;  //quan ly dau hang doi
    int rear;   //chi so cuoi hang doi
}Queue;

void makeNullQ(Queue *Q){
    Q->front = 0;
    Q->rear = -1;
}
//them phan tu vao hang
void pushQueue(Queue *Q, int x){
    Q->rear++;  //them vao duoi
    Q->dataQ[Q->rear] = x;
}

int emptyQueue(Queue *Q){
    return (Q->front > Q->rear);
}
//lay phan tu trong hang
int top(Queue *Q){
    return Q->dataQ[Q->front];
}
//tang front de cap nhat hang doi
void pop(Queue *Q){
    Q->front++;
}

void BFS(Graph *G){
    Queue Q;
    makeNullQ(&Q);
    int mark[M];
    int i;
    for(i=1; i<=G->n; i++){
        //danh dau cac dinh chua duoc duyet
        mark[i] = 0;
    }
    pushQueue(&Q, 1);
    while(!emptyQueue(&Q)){
        //lay phan tu dau tien trong hang doi
        int u = top(&Q);
        pop(&Q);
        //xem dinh u da duyet chua
        if(mark[u] == 1){
            continue;
        }
        printf("%d\n", u);
        mark[u] = 1;
        //tao danh sach lang gieng
        List L;
        //for cac lang gieng cua u
        makeNull(&L);
        L = neighbors(G, u);
        int v;
        for(i=1; i<=L.size; i++){
            //lay phan tu v tai vi tri i
            v = elemantAt(&L, i);
            if(mark[v]==0){
                pushQueue(&Q, v);
            }
        }
    }
}

int main(){
    Graph G;
    int n, m;
    scanf("%d%d", &n, &m);
    int i, j;
    initGraph(&G, n);
    int u, v;
    for(i=1; i<=m; i++){
        scanf("%d%d", &u, &v);
        addEdge(&G, u, v);
    }
    BFS(&G  );
    // for(i=1; i<=L.size; i++){
    //     printf("%d\n", elemantAt(&L, i));
    // }
    return 0;
}