#include<stdio.h>
#define MAX 20

typedef struct {
	int data[MAX];
	int size ;
}List;

typedef struct {
	int n,m;
	List adj[MAX];
}Graph;

void make_null ( List *pL){
	pL->size = 0;
}

void push_back ( List *pL, int u){
	pL->data[pL->size++] = u;
}

int element_at ( List * pL , int i){
	return pL->data[i-1];
}

int size_list ( List *pL ){
	return pL->size;
}

void init_graph ( Graph *pG , int n){
	pG->n = n;
	for ( int i=1;i<=n ;i++){
		make_null ( &pG->adj[i] );
	}
}

int adjacent ( Graph * pG, int u, int v){
	for ( int i = 1;i<= size_list ( &pG->adj[u] );i++){
		if ( v == element_at(&pG->adj[u],i) ) return 1;
	}
	return 0;
}

// vo huong
void add_edges ( Graph *pG, int u, int v){
	if ( !adjacent(pG,u,v) ){
		if ( u == v ) push_back(&pG->adj[u],v);
		else{
			push_back(&pG->adj[u],v);
			push_back(&pG->adj[v],u);
		}
	}	
}


void neighbors (Graph * pG){
	for ( int u=1;u<=pG->n;u++){
		printf ("neighbors(%d) = [ ",u);
		for ( int v=1;v<=size_list (&pG->adj[u]);v++){
			printf ("%d ",element_at(&pG->adj[u],v));
		}
		printf ("]\n");
	} 
}

int main (){
	
	Graph G;
	
	int n,m;
	freopen( "12.txt","r",stdin);
	scanf("%d %d",&n,&m);
	init_graph(&G,n);
	for ( int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		add_edges(&G,u,v);
	}
	
	neighbors(&G);
	
	
	return 0;
}
