
#include<stdio.h>
#define MAX 50
typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph( Graph * pG , int n){
	pG->n = n;
	pG->m = 0;
}

int adjacent(Graph *pG , int u, int v){
	for ( int i=0;i<pG->m;i++){
		if ( pG->edges[i].u == u && pG->edges[i].v == v ||
			 pG->edges[i].u == v && pG->edges[i].v == u) return 1;
	}
	return 0;
}

void add_edges( Graph *pG, int u, int v){
	if ( !adjacent( pG, u, v) ){
		pG->edges[pG->m].u = u;
		pG->edges[pG->m].v = v;
		pG->m++;
	}
}

int main (){
	freopen( "13.txt","r",stdin);
	int n,m;
	scanf ("%d %d",&n,&m);
	Graph  G;
	init_graph(&G,n);
	for ( int e = 1;e<=m ;e++){
		int u,v ;
		scanf("%d %d",&u,&v);
		add_edges(&G,u,v);
	}
	
	for ( int i=0;i<G.m;i++){
		printf ("%d - %d\n",G.edges[i].u,G.edges[i].v);
	}
	printf ("Do Thi Co %d dinh va %d Cung\n",G.n, G.m);
	printf ("%d co ke voi %d : %d\n",1,2 ,adjacent(&G,1 ,2));
	printf ("%d co ke voi %d : %d\n",1,4 ,adjacent(&G,1 ,4));
	
	return 0;
}
