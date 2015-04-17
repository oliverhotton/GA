#ifndef ALGORITHME_H 
#define ALGORITHME_H

typedef struct {
	int s,t;
	long cout;
} arete;

typedef struct somp {
	int num;
	struct somp *suiv;
	struct soma *succ;
} principale;

typedef struct soma {
	struct somp *som;
	struct soma *suiv;
	long cout;
} secondaire;

class Algorithme {
	public:
		void dijkstra(int* fs, int* aps,int **cout,int s,int* &pred,int* &d);
		void det_fpapp(int* fs, int* aps,int *&fp,int *&app);
		void bellman(int* fs, int* aps,int* poids,int s,int* &pred,int* &d); //sans circuit
		void kruskal(arete *g,int n,int m,arete *&t);
		void prim(arete *g,int n,int m,int s,arete *&t);
		void trierAretes(arete *&g,int m);
		void prufer(arete *g,int n,int *&t);
		void matrix2all(int **a,int *&fs,int *&aps,int *&poids);
		void all2matrix(int *fs,int *aps,int *poids,int **&a); //fs aps poids ne sont pas supprimés
		void matrix2aretes(int **a,arete *&g,int &n,int &m);
		void aretes2matrix(arete *g,int **&a,int n,int m);
		principale* adresse(principale* pri,int sommet);
		void all2lists(int *fs,int *aps,int *poids,principale *&pri);
		void lists2all(principale *pri,int *&fs,int *&aps,int *&poids);
		void affiche_lists(principale *pri);
		void del_lists(principale *&pri);
		void det_ddi(int *fs,int *aps,int *&ddi);
		int det_rang(int *fs,int *aps,int *&rang);
		void det_dist(int *fs,int *aps,int s,int *&marque);
	
	private:
		void joindre(int i,int j,int *prem, int *cc,int *pilch);
};

#endif
