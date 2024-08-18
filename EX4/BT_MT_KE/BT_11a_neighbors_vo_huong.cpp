#include<stdio.h>
#define MAX 20

typedef struct {
	int n,m;
	int A[MAX][MAX];
}Graph;

void init_graph(Graph * pG, int n){
	for ( int i=1;i<=n;i++){
		for ( int j=1;j<=n;j++){
			pG->A[i][j] = 0 ;
		}
	}
}

//vo huong
void neighbors ( Graph *pG, int u ){
	printf ("neighbors(%d) : ",u);
	for ( int i=1;i<=pG->n;i++){
		if ( pG->A[u][i] != 0 ) 
			printf ("%d ",i);
	}
	printf ("\n");
}

int adjacent ( Graph * pG, int u, int v){
	return pG->A[u][v];
}

void add_edge ( Graph * pG , int u, int v){
	if ( u != v){
		pG->A[u][v] += 1;
		pG->A[v][u] += 1;
	}	 
	else { 
		pG->A[u][v] += 1;
	}
}

void print_graph(Graph * pG){
	for ( int i=1;i<=pG->n;i++){
		for ( int j=1;j<=pG->n;j++){
			printf ("%d ",pG->A[i][j]);
		}
		printf ("\n");
	}
}


int main (){
	Graph G;
	int n,m,u,v ;
	freopen ("6a.txt","r",stdin);
	scanf("%d %d",&n,&m);
	G.n = n;
	G.m = m;
	init_graph(&G,n);
	
	for ( int i = 1;i<=m ;i++){
		scanf("%d %d ",&u,&v);
		add_edge(&G,u,v);
	}
	
	print_graph(&G);
	
	for ( int i=1;i<=G.n;i++){
		neighbors(&G,i);
	}
	
	return 0;
}
