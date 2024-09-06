#include<stdio.h>
#define MAX 20
typedef struct {
	int A[MAX][MAX];
	int n,m;
}Graph_MT;

typedef struct{
	int data[MAX];
	int size;
}List;

typedef struct {
	List adj[MAX];
	int n,m;
}Graph_DSK;


void init_MT ( Graph_MT *pG, int n){
	pG->n=n;
	for ( int i=1;i<=n;i++){
		for ( int j=1;j<=n;j++){
			pG->A[i][j] = 0;
		}
	}
}

void make_null(List * pL){
	pL->size  = 0;
}

int element_at( List * pL, int i){
	return pL->data[i-1];
}

int count_list (List *pL ){
	return pL->size;
}

void push_back ( List * pL, int v){
	pL->data[pL->size] = v;
	pL->size++;
}

void  init_DSK ( Graph_DSK * pG, int n ){
	pG->n = n;
	for ( int i=1;i<=n;i++){
		make_null(&pG->adj[i]);
	}
}


void add_edges_MT( Graph_MT * pG, int u, int v){
	pG->A[u][v] += 1;
}

void add_edges_DSK ( Graph_DSK *pG , int u , int v){
	if ( u == v ) push_back(&pG->adj[u],v);
	else{
		push_back(&pG->adj[u],v);
		push_back(&pG->adj[v],u);
	}
}

void print_MT ( Graph_MT *pG ){
	for (int i=1;i<=pG->n;i++){
		for ( int j=1;j<=pG->n;j++){
			printf("%d ",pG->A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_DSK ( Graph_DSK * pG){
	for ( int u=1;u<=pG->n;u++){
		printf("adj(%d) = [ ",u);
		for ( int v = 1; v <= count_list (&pG->adj[u]) ;v++){
			printf("%d ",element_at(&pG->adj[u],v));
		}
		printf("]\n");
	}
}


int main (){
	int n,m;
	freopen ( "13.txt", "r", stdin);
	scanf("%d %d",&n, &m);
	
	Graph_DSK DSK;
	init_DSK(&DSK,n);
	
	for ( int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		add_edges_DSK(&DSK,u,v);
	}
	
	print_DSK(&DSK);
	
	Graph_MT MT;
	init_MT(&MT,n);
	
	for ( int u=1;u<=n ;u++){
		for ( int v =1;v<=count_list ( &DSK.adj[u]);v++){
			add_edges_MT(&MT,u,element_at(&DSK.adj[u],v));
		}
	} 
	
	print_MT(&MT);
	
		
	return 1;
}

