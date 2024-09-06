#include<stdio.h>
#define  MAX 50
typedef struct{
	int n,m;
	int A[MAX][MAX];
}Graph;

void  init_graph ( Graph *pG, int n, int m ){
	pG->n = n;
	pG->m = m;
	for ( int u=1;u<=n;u++){
		for ( int e  =1; e<= m ;e++){
			pG->A[u][e] = 0;
		}
	}
}

int adjacent( Graph * pG, int u ,int v ){
	for ( int e = 1;e<= pG->m ;e++){
		if ( pG->A[u][e] == 1 && pG->A[v][e] == 1 ) return 1;
	}
	return 0;
}

void add_edges ( Graph * pG, int e, int u ,int v){
	if ( u == v ) 		pG->A[u][e] = 2;
	else {
		pG->A[u][e] = 1;
		pG->A[v][e] = -1;
	}
}

void print_graph (Graph * pG){
	printf ("  ");
	for  ( int i=1;i<=pG->m ;i++) printf ("%2d ",i);
	printf ("\n");
	for ( int u = 1; u<= pG->n ; u++){
		printf ("%d ",u);
		for ( int e =1 ;e <= pG->m ;e++){
			printf ("%2d ",pG->A[u][e]);
		}
		printf ("\n");
	}
}

int main (){
	freopen( "13.txt","r",stdin);
	int n,m;
	scanf ("%d %d",&n,&m);
	Graph  G;
	init_graph(&G,n,m);
	for ( int e = 1;e<=m ;e++){
		int u,v ;
		scanf("%d %d",&u,&v);
		add_edges(&G,e,u,v);
	}
	
	print_graph(&G);
	
	return 0;
}
