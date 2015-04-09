#include "Algorithme.h"
#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int *fs,*aps,**cout1,s,*pred,*d;
	int n = 7;
	int m = 12;
	fs = new int[n+m+1];fs[0]=n+m;
	aps = new int[n+1];aps[0]=n;
	cout1 = new int*[n+1];
	for(int i=0;i<=n;i++){
		cout1[i] = new int[n+1];
	}
	fs[1] = 2;
	fs[2] = 5;
	fs[3] = 0; //1
	fs[4] = 5;
	fs[5] = 6;
	fs[6] = 0; //2
	fs[7] = 1;
	fs[8] = 4;
	fs[9] = 0; //3
	fs[10] = 7;
	fs[11] = 0; //4
	fs[12] = 3;
	fs[13] = 4;
	fs[14] = 7;
	fs[15] = 0; //5
	fs[16] = 5;
	fs[17] = 0; //6
	fs[18] = 6;
	fs[19] = 0; //7
	
	aps[1] = 1;
	aps[2] = 4;
	aps[3] = 7;
	aps[4] = 10;
	aps[5] = 12;
	aps[6] = 16;
	aps[7] = 18;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout1[i][j] = INT_MAX;
		}
	}
	
	cout1[1][2] = 1;
	cout1[1][5] = 3;
	cout1[2][5] = 1;
	cout1[2][6] = 4;
	cout1[3][1] = 0;
	cout1[3][4] = 2;
	cout1[4][7] = 4;
	cout1[5][3] = 1;
	cout1[5][4] = 6;
	cout1[5][7] = 0;
	cout1[6][5] = 1;
	cout1[7][6] = 1;
	
	s = 1;
	
	Algorithme algo;
	
	algo.dijkstra(fs,aps,cout1,s,pred,d);
	cout<<"****Test Djikstra****"<<endl;
	cout<<"pred : ["<<pred[1];
	for(int i=2;i<=n;i++){
		cout<<","<<pred[i];
	}
	cout<<"]"<<endl;
	
	cout<<"d : ["<<d[1];
	for(int i=2;i<=n;i++){
		cout<<","<<d[i];
	}
	cout<<"]"<<endl;
	
	
	delete(fs);
	delete(aps);
	for(int i=0;i<=n;i++){
		delete(cout1[i]);
	}
	delete(cout1);
	delete(pred);
	delete(d);
	
	n=8;
	m=13;
	arete *g,*t,a;
	g = new arete[m];
	//1
	a.s = 1;
	a.t = 2;
	a.cout = 1;
	g[0] = a;
	//2
	a.s = 1;
	a.t = 3;
	a.cout = 2;
	g[1] = a;
	//3
	a.s = 1;
	a.t = 4;
	a.cout = 3;
	g[2] = a;
	//4
	a.s = 2;
	a.t = 3;
	a.cout = 1;
	g[3] = a;
	//5
	a.s = 2;
	a.t = 5;
	a.cout = 2;
	g[4] = a;
	//6
	a.s = 2;
	a.t = 6;
	a.cout = 3;
	g[5] = a;
	//7
	a.s = 2;
	a.t = 7;
	a.cout = 3;
	g[6] = a;
	//8
	a.s = 3;
	a.t = 4;
	a.cout = 1;
	g[7] = a;
	//9
	a.s = 3;
	a.t = 7;
	a.cout = 4;
	g[8] = a;
	//10
	a.s = 4;
	a.t = 6;
	a.cout = 2;
	g[9] = a;
	//11
	a.s = 4;
	a.t = 7;
	a.cout = 2;
	g[10] = a;
	//12
	a.s = 4;
	a.t = 8;
	a.cout = 2;
	g[11] = a;
	//13
	a.s = 5;
	a.t = 6;
	a.cout = 2;
	g[12] = a;
	
	algo.trierAretes(g,m);
	algo.kruskal(g,n,m,t);
	cout<<"****Test Kruskal****"<<endl;
	for(int i=0;i<(n-1);i++){
		cout<<"["<<t[i].s<<","<<t[i].t<<","<<t[i].cout<<"]"<<endl;
	}
	
	delete(g);
	delete(t);
	
	g = new arete[8];
	//1
	a.s = 1;
	a.t = 6;
	g[0] = a;
	//2
	a.s = 1;
	a.t = 7;
	g[1] = a;
	//3
	a.s = 1;
	a.t = 2;
	g[2] = a;
	//4
	a.s = 2;
	a.t = 3;
	g[3] = a;
	//5
	a.s = 2;
	a.t = 4;
	g[4] = a;
	//6
	a.s = 2;
	a.t = 5;
	g[5] = a;
	//7
	a.s = 5;
	a.t = 8;
	g[6] = a;
	//8
	a.s = 5;
	a.t = 9;
	g[7] = a;
	int *h;
	algo.prufer(g,9,h);
	cout<<"****Test Prufer****"<<endl;
	cout<<"h: ["<<h[0];
	for(int i=1;i<7;i++){
		cout<<","<<h[i];
	}
	cout<<"]"<<endl;
	delete(g);
	delete(h);
	
	int *poids,**matrix; //*aps,*fs,n,m
	n = 5;m = 7;
	matrix = new int*[n+1];
	matrix[0] = new int[2]; matrix[0][0] = n; matrix[0][1] = m;
	for(int i=1;i<=n;i++){
		matrix[i] = new int[n+1];
		for(int j=1;j<=n;j++) matrix[i][j] = INT_MAX;
	}
	matrix[1][2] = 1;
	matrix[1][5] = 3;
	matrix[2][5] = 1;
	matrix[3][1] = 0;
	matrix[3][4] = 2;
	matrix[5][3] = 1;
	matrix[5][4] = 6;
	algo.matrix2all(matrix,fs,aps,poids);
	cout<<"****Test matrix2all****"<<endl;
	cout<<"aps: ["<<aps[0];
	for(int i=1;i<=n;i++){
		cout<<","<<aps[i];
	}
	cout<<"]"<<endl;
	cout<<"fs: ["<<fs[0];
	for(int i=1;i<=(n+m);i++){
		cout<<","<<fs[i];
	}
	cout<<"]"<<endl;
	cout<<"poids: ["<<poids[0];
	for(int i=1;i<=(n+m);i++){
		cout<<","<<poids[i];
	}
	cout<<"]"<<endl;
	
	algo.all2matrix(fs,aps,poids,matrix);
	cout<<"****Test all2matrix****"<<endl;
	cout<<"Matrix:"<<endl;
	for(int i=1;i<=n;i++){
		cout<<"| ";
		for(int j=1;j<=n;j++){
			switch(matrix[i][j]){
				case INT_MAX:
					cout<<"m ";
					break;
				default:
					cout<<matrix[i][j]<<" ";
					break;	
			}
		}
		cout<<"|"<<endl;
	}
	
	for(int i=0;i<=n;i++){
		delete(matrix[i]);
	}			
	delete(matrix);
	//delete(fs);
	//delete(aps);
	//delete(poids);
	
	n=4;m=4;
	g = new arete[4];
	//1
	a.s = 1;
	a.t = 2;
	a.cout = 1;
	g[0] = a;
	//2
	a.s = 1;
	a.t = 3;
	a.cout = 2;
	g[1] = a;
	//3
	a.s = 1;
	a.t = 4;
	a.cout = 3;
	g[2] = a;
	//4
	a.s = 2;
	a.t = 3;
	a.cout = 1;
	g[3] = a;
	
	algo.aretes2matrix(g,matrix,n,m);
	cout<<"****Test aretes2matrix****"<<endl;
	cout<<"Matrix:"<<endl;
	for(int i=1;i<=n;i++){
		cout<<"| ";
		for(int j=1;j<=n;j++){
			switch(matrix[i][j]){
				case INT_MAX:
					cout<<"m ";
					break;
				default:
					cout<<matrix[i][j]<<" ";
					break;	
			}
		}
		cout<<"|"<<endl;
	}
	
	algo.matrix2aretes(matrix,g,n,m);
	cout<<"****Test matrix2arete****"<<endl;
	for(int i=0;i<m;i++){
		cout<<"["<<g[i].s<<","<<g[i].t<<","<<g[i].cout<<"]"<<endl;
	}
	delete(g);
	
	return 0;
}
