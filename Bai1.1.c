/*
	Name: Do thi vo huong Dinh Dinh
	Author: Bui Xuan Dong
	Date: 06/08/24 12:42
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

int main(){
	Graph G;
	//khoi tao do thi
	int i, j;
	int edge1, edge2;
	int option;
//	G.n = 6;	// so luong dinh = 6
//	//duyet cac phan tu 
//	for(i=1; i<=G.n; i++){ //hang ma tran
//		for(j=1; j<=G.n; j++){ //dong ma tran
//			G.A[i][j]=0;
//		}
//	}
	int n;
	printf("Nhap vao so luong dinh (tu 1 den 20): \n");
	scanf("%d", &n);
	initGraph(&G, n);	//khai bao init la con tro nen xai &
	printf("So luong dinh: %d\n\n", G.n);
	for(i=1; i<=G.n; i++){
		for(j=1; j<=G.n; j++){
			printf("%d ", G.A[i][j]);
		}
		//duyet het 1 hang thi xuong dong
		printf("\n");
	}
	printf("Nhap vao cac dinh tao cung (nhap 0 de ket thuc va in ma tran): \n\n");
	for(i=0; i<=G.n*G.n; i++){
		printf("Nhap vao dinh thu nhat: \n");
		scanf("%d", &edge1);
		printf("Nhap vao dinh thu hai: \n");
		scanf("%d", &edge2);
		addEdge(&G, edge1, edge2);
		if(edge1 > n || edge2 > n){
			printf("Loi so dinh vuot qua cho phep!!!");
			return 0;
		}
		else if(edge1 == 0 || edge2 == 0){
			break;
		}
	}
	printf("\n");
	for(i=1; i<=G.n; i++){
		for(j=1; j<=G.n; j++){
			printf("%d ", G.A[i][j]);
		}
		//duyet het 1 hang thi xuong dong
		printf("\n");
	}
	printf("Ban co muon kiem tra lang gieng giua cac dinh hay khong(1: co; 2: khong)?\n");
	scanf("%d", &option);
	if(option == 0){
		return 0;
	}
	else if(option == 1){
		printf("Nhap vao cap dinh can kiem tra:\n\n");
		printf("Nhap vao dinh thu nhat: \n");
		scanf("%d", &edge1);
		printf("Nhap vao dinh thu hai: \n");
		scanf("%d", &edge2);
		if(isAdjacent){
			printf("Hai dinh %d va %d la lang gieng!!", edge1, edge2);
			return 0;
		}
		else{
			printf("Hai dinh %d va %d la lang gieng!!", edge1, edge2);
			return 0;
		}
	}
//	for(i=1; i<=G.n; i++){
//		for(j=1; j<=G.n; j++){
//			printf("%d ", G.A[i][j]);
//		}
//		//duyet het 1 hang thi xuong dong
//		printf("\n");
//	}
	
	return 0;
}
