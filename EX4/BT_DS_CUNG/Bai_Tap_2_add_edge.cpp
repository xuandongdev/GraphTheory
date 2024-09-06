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

void add_edges( Graph *pG, int u, int v){
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int main (){
	Graph G;
	init_graph(&G,6);
	printf ("Do Thi Co %d dinh va %d Cung\n",G.n, G.m);
	
	add_edges(&G, 1, 4);
	add_edges(&G, 1, 3);
	
	for ( int i=0;i<G.m;i++){
		printf ("%d - %d\n",G.edges[i].u,G.edges[i].v);
	}
	return 0;
}
