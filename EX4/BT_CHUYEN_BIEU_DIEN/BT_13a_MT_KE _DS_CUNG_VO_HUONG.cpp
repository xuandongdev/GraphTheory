#include<stdio.h>
#define MAX 20
typedef struct {
	int A[MAX][MAX];
	int n,m;
}Graph_MT;

typedef struct {
	int u,v;
	int size ;
}Edge;

typedef struct {
	Edge edges[MAX];
	int n,m;	
}Graph_DSC;

void init_MT ( Graph_MT *pG, int n){
	pG->n=n;
	for ( int i=1;i<=n;i++){
		for ( int j=1;j<=n;j++){
			pG->A[i][j] = 0;
		}
	}
}

void init_DSC( Graph_DSC *pG, int n){
	pG->n = n;
	pG->m = 0;
}

void add_edges_MT( Graph_MT * pG, int u, int v){
	if( u ==v ) pG->A[u][v] += 1;
	else {
		pG->A[u][v] += 1;
		pG->A[v][u] += 1;
	}
}

void add_edges_DSC ( Graph_DSC *pG, int u, int v){
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

void print_MT ( Graph_MT *pG ){
	for (int i=1;i<=pG->n;i++){
		for ( int j=1;j<=pG->n;j++){
			printf("%d ",pG->A[i][j]);
		}
		printf("\n");
	}
}

void print_DSC ( Graph_DSC * pG ){
	for ( int i=1;i<=pG->m;i++){
		printf ("%d - %d\n",pG->edges[i-1].u,pG->edges[i-1].v);
	}
}

int main (){
	Graph_MT MT;
	
	int n,m;
	freopen ( "13.txt", "r", stdin);
	scanf("%d %d",&n, &m);
	init_MT(&MT,n);
	
	for ( int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		add_edges_MT(&MT,u,v);
	}
	
	print_MT(&MT);
	
	Graph_DSC DSC ;
	init_DSC ( &DSC,n);
	for ( int i=1;i<=n;i++){
		for ( int j=1;j<=i;j++){

			if ( MT.A[i][j] >= 1 ){
				for ( int u = 1 ; u <=  MT.A[i][j] ;u++){
					add_edges_DSC(&DSC,i,j); 
				}
			}
		} 
	}
	
	print_DSC(&DSC);
		
	return 1;
}

