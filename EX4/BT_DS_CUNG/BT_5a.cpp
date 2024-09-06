
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
	
		pG->edges[pG->m].u = u;
		pG->edges[pG->m].v = v;
		pG->m++;
	
}

int degree( Graph * pG, int u){
	int deg = 0;
	for ( int i=0;i<pG->m;i++){
		if ( pG->edges[i].u == u ) deg++;
		if ( pG->edges[i].v == u ) deg++;
	}
	return deg;
}

int main (){
	Graph G;
	init_graph(&G,4);
	printf ("Do Thi Co %d dinh va %d Cung\n",G.n, G.m);
	
	add_edges(&G, 1, 2);
	add_edges(&G, 1, 3);
	add_edges(&G, 1, 3);
	add_edges(&G, 3, 4);
	add_edges(&G, 1, 4);
	
	for ( int i=0;i<G.m;i++){
		printf ("%d - %d\n",G.edges[i].u,G.edges[i].v);
	}
	printf ("Do Thi Co %d dinh va %d Cung\n",G.n, G.m);
	
	for ( int i=1;i<=G.n;i++){
		printf("deg(%d) = %d\n",i,degree(&G,i));
	}
	
	return 0;
}
