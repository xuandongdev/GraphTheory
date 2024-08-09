/*
	Name:
	Author: Bui Xuan Dong
	Date: 06/08/24 22:03
	Description: Do thi vo huong Dinh-Dinh CTU
*/

#include <stdio.h>
#define MAX_Vertices 20 // cap phat o nho so luong dinh toi da 20 dinh

typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n; //so luong dinh
}Graph;

//khoi tao do thi
void initGraph(Graph *G, int n){	//dung bien con tro thi xai ->
	int i, j;
	G->n = n;	//so luong dinh nguoi dung tu nhap
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->n; j++){
			G->A[i][j] = 0;
		}
	}
}

//them cung vao do thi
void addEdge(Graph *G, int x, int y){	//them cung tu dinh x den dinh y
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

//kiem tra dinh x va y co phai la lang gieng hay khong
int isAdjacent(Graph *G, int x, int y){
	return (G->A[x][y] != 0);	//kiem tra neu x va y co cung (la lang gieng) thi return 1
}

//tinh bac cua dinh x trong do thi
int degree(Graph *G, int x){
	int deg = 0, i;
	for(i=1; i<=G->n; i++){
		if(G->A[i][x] == 1){
			deg++;
		}
	}
	return deg;
}

int main(){
	Graph G;
	//khai bao doc file
	FILE* file = fopen("dothi.txt", "r");
	int n, m;	//so luong dinh n; so luong cung m
	fscanf(file, "%d%d", &n, &m);
	//khoi tao do thi
	initGraph(&G, n);
	int u, v, e;	//2 dau mut cua cung
	//doc du lieu cung tu tap tin
	for(e=1; e<=m; e++){
		fscanf(file, "%d%d", &u, &v);
		addEdge(&G, u, v);
	}
	//dong tap tin
	fclose(file);
	int i;
	for(i=1; i<=G.n; i++){
		printf("\ndegree(%d) = %d\n", i, degree(&G, i));
	}
	return 0;
}
