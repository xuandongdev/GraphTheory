#include<stdio.h>
#include<math.h>
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

void add_edges ( Graph * pG, int e, int u ,int v){
		pG->A[u][e] += 1;
		pG->A[v][e] += 1;
}

void neighbors( Graph * pG, int u){
	printf ("neighbor(%d) = [ ",u);
	for ( int e = 1; e <= pG->m ;e ++){	
		if ( pG->A[u][e] == 2) printf ("%d ",u);
		else {
			if ( pG->A[u][e] == 1 ){
				for ( int v = 1; v<= pG->n ;v++){
					if ( v != u && pG->A[v][e] == 1) printf("%d ",v);
				}
			}
		} 
	}
	printf ("]\n");
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
	
	for ( int u = 1; u <= G.n ;u++){
		neighbors(&G,u);
	}
	
	return 0;
}
