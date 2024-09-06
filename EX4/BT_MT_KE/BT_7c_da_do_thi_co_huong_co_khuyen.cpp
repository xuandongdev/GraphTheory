#include<stdio.h>
#define MAX 20

typedef struct {
	int n,m;
	int A[MAX][MAX];
}Graph;

void init_graph(Graph *pG, int n){
	for ( int i=1;i<=n;i++){
		for ( int j=1;j<=n;j++){
			pG->A[i][j] = 0;
		}
	}
}

int hop_le ( Graph * pG , int u, int v){
	return ( u>=1 && u<= pG->n && v>= 1 && u <= pG->n);
}

int adjacent ( Graph * pG, int u, int v){
	return pG->A[u][v];
}

void add_edge ( Graph *pG, int u, int v ){
	if ( u == v )  pG->A[u][v] += 1;
	else{
		pG->A[u][v] += 1;
	}	
}

void print_graph( Graph *pG){
	for ( int i=1;i<=pG->n;i++){
		for (int j=1;j<=pG->n;j++){
			printf ("%d ",pG->A[i][j]);
		}
		printf("\n");
	}
}

int main (){
	Graph G;
	
	int u,v, n ,m;
	freopen ("6a.txt","r",stdin);
	scanf("%d %d",&n,&m);
	G.n = n;
	G.m = m;
	init_graph(&G,n);
	
	for ( int i=1;i<=m;i++){
		scanf("%d %d ",&u,&v);
		printf ("%d - %d\n",u,v);
		add_edge( &G, u, v);
	}
	
	print_graph(&G);
	
	
	
	return 0;
}
