#include<stdio.h>
#define MAX 20

typedef struct {
	int data[MAX][MAX];
	int size;	
}Graph;

typedef struct {
	int data[MAX];
	int size;
}List;

typedef struct {
	int data[MAX];
	int size, front, rear;
}Que;

void init_graph( Graph * G){
	int i, j;
	for (i=1;i<=G->size;i++){
		for (j=1;j<=G->size;j++){
			G->data[i][j] = 0 ; 
		}	
	}	
}

void add_graph ( Graph * G , int x , int y ){
	G->data[x][y] = 1;
	G->data[y][x] = 1;
}

void in_graph ( Graph * G ){
	int i, j;
	for (i=1;i<=G->size;i++){
		for (j=1;j<=G->size;j++){
			printf ( "%d ",G->data[i][j]);
		}	
		printf("\n");
	}
}

int acjacent ( Graph * G , int x , int y ){
	return G->data[x][y];
}

int degree ( Graph * G ,int  u){
	int i;
	int count = 0;
	for (i=1;i<=G->size;i++){
		if ( G->data[u][i]==1) count ++;
	}
	return count ;
}

void make_null_list ( List * L ){
	L->size =0;
}

void add_list ( List * L , int x){
	L->data[L->size++] = x;
}

int element_at ( List * L, int i ){
	return L-> data[i-1];
}

List neighbors ( Graph * G , int u){
	List L ;
	make_null_list(&L) ;
	int i;
	for (i=1;i<=G->size ;i++){
		if ( G->data[u][i] == 1){
			add_list(&L, i);
		}
	}
	return L ;
}

void make_null_que( Que * Q ){
	Q->front = 0; 
	Q->rear = -1;
}

int empty_que ( Que * Q){
	return Q->front > Q->rear ;
}

void push_que ( Que * Q , int x){
	Q->data[++Q->rear] = x;
}

int  top_que ( Que * Q ){
	return Q->data[Q->front++];	
}
void init_mark ( int n, int mark[]){
	int i;
	for (i=1;i<=n;i++){
		mark[i] = 0;
	}
}
int parent[MAX];

List BFS ( Graph * G , int x ){
	int i;
	Que Q ;
	make_null_que(&Q);	

	int mark[MAX] ;	
	init_mark(G->size,mark);
	
	List L_BFS ;
	make_null_list (&L_BFS);
	
	push_que (&Q,x );
	while ( !empty_que (&Q) ){
		int u = top_que(&Q);
		if ( mark[u]==1) continue;
		
		mark[u] = 1;
		add_list(&L_BFS,u);
		
		List L ;
		make_null_list(&L);
		L = neighbors(G,u);
		for (i=1;i<=L.size;i++){
			int v = element_at(&L,i);
			if ( mark[v] == 0 ){
				push_que(&Q,v);
				if ( parent[v] == 0 ) parent[v] = u;
			}
		}
	}
	return L_BFS;
}




//void De_quy ( Graph * G , int u, int p){		
//	if ( mark[u] == 1 ) return ;
//	parent[u]=  p;
//	mark[u] =1;
//	printf ("Duyet %d \n",u);
//	List L = neighbors (G,u);
//	for ( int i = 1;i<=L.size;i++){
//		int v = element_at(&L,i);
//		
//		De_quy(G,v,u);
//	}
//}
	
int main (){
	Graph G ;
	
	int i, j;
	freopen( "BFS.txt","r", stdin);
	int n,m;
	scanf("%d %d ", &n, &m);
	G.size = n;
	init_graph(&G);
	for (i=1;i<=m;i++){
		int u,v ;
		scanf("%d  %d ",&u,&v);
		add_graph(&G,u,v);
	}
	
	in_graph(&G);
	
	for (i=1;i<=G.size;i++){
		printf ("Degrree (%d) : %d\n",i,degree(&G,i));	
	}
	
	printf ("In lang gieng cua cac dinh\n");
	for (i=1;i<=G.size;i++){
		List L = neighbors(&G,i);
		printf ("neighbors(%d) =[ ",i);
		for (j=0;j<L.size;j++){
			printf ("%d ",L.data[j]);
		}
		printf("]\n");
	}
	
	int mark_BFS[G.size];
	init_mark(G.size,mark_BFS);
	init_mark(G.size,parent);
	
	for (i=1;i<=G.size ;i++){
		if ( mark_BFS[i] == 0){
			List L = BFS( &G, i);
			for (j=1;j<=L.size;j++){
				int v = element_at(&L,j);
				printf("Duyet : %d \n",v);
				mark_BFS[v] = 1;
			}
		}
	}
	
	for ( i=1;i<=G.size;i++){
		printf ("%d   %d\n",i,parent[i]);
	}
	return 0;
}
