/*
	Name:
	Author: Bui Xuan Dong
	Date: 06/08/24 22:03
	Description: Do thi vo huong Dinh-Dinh CTU
*/

#include <stdio.h>
#define MAX_Vertices 20 // cap phat o nho so luong dinh toi da 20 dinh
#define MAX_Length 20	//so luong phan tu danh sach toi da la 20

typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n; //so luong dinh
}Graph;

typedef struct{
	int data[MAX_Length];
	int size;
}List;

//tao danh sach rong
void makeNull(List *list){
	list->size = 0;		//gan size =0 => trong list ko co phan tu nao => rong
}

//them phan tu (dinh) vao cuoi danh sach
void pushBack(List *list, int x){
	list->data[list->size] = x;		//them phan tu vao vi tri thu size
	list->size++;	//tang size de them phan tu tiep theo
}

//lay 1 dinh trong danh sach tai vi tri i
int elementAt(List *list, int i){
	return list->data[i-1];		//tra ve gia tri tai vi tri thu i
}
//tim lang gieng cua dinh x | tra ve danh sach vi cac dinh deu luu vao list
List neighbours(Graph *G, int x){
	int i;
	List L;
	makeNull(&L);
	for(i=1; i<=G->n; i++){
		if(G->A[i][x] == 1){
			pushBack(&L, i);
		}
	}
	return L;
}

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
	freopen("dothi.txt", "r", stdin);
	int n, m;	//so luong dinh n; so luong cung m
	scanf("%d%d", &n, &m);
	//khoi tao do thi
	initGraph(&G, n);
	int u, v, e;	//2 dau mut cua cung
	//doc du lieu cung tu tap tin
	for(e=1; e<=m; e++){
		scanf("%d%d", &u, &v);
		addEdge(&G, u, v);
	}
	//tinh bac
	int i, j;
	for(i=1; i<=G.n; i++){
		printf("\ndegree(%d) = %d\n", i, degree(&G, i));
	}
	//in danh sach lang gieng
	printf("\nIn danh sach lang gieng\n");
	for(i=1; i<=G.n; i++){
		List list = neighbours(&G, i);
		printf("Neighbours(%d) = [", i);
		for(j=1; j<=list.size; j++){
			printf("%d ", elementAt(&list, j));
		}
		printf("]\n");
	}
	
	
	return 0;
}
