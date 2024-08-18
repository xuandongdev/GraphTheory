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

int main (){
	Graph G;
	init_graph(&G,5);
	printf ("Do Thi Co %d dinh va %d Cung\n",G.n, G.m);
	return 0;
}
