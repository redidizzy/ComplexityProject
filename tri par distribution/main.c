#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "triParDistribution.h"

int main(){
	int *T;
	int i;
	int k = 0;
	int n[100];
	double delta;
	clock_t t1, t2;
	srand(time(0)); //random number generator seeding
	// L'algorithme ne marche pas pour les valeurs qu'elle nous a donnes, c'est a dire : 
	n[0] = 5000;
	n[1] = 100000;
	n[2] = 200000;
	n[3] = 400000;
	n[4] = 800000;
	n[5] = 1600000;
	n[6] = 3200000;
	n[7] = 6400000;
	n[8] = 12800000;
	n[9] = 25600000;
	n[10] = 51200000;
	n[11] = 102400000;
	n[12] = 204800000;
	//j'ai donc utilisé une seule valeur pour cette question*/
	//int n = 100;
	for(i = 0; i<13; i++){
		printf("----------------------------------------------------------------------\n");
		printf("pour N = %d\n", n[i]);
		printf("-----------------------------------------------------------------------\n");
		// Le meilleur des cas consiste en un tableau deja triéé
		printf("remplissage du tableau..\n");
		remplir(&T, n[i]);
		k = plusGrandNbChiffre(T, n[i]);
		printf("tri par distribution en cours...\n");
		t1 = clock();
		triBase(T, n[i], k);
		t2 = clock();
		delta = (double)(t2-t1)/CLOCKS_PER_SEC;
		printf("le tableau, dans le cas de la taille %d, a ete trié en %f secondes :\n", n[i], delta);
		printf("appuyez sur entree pr continuer\n");
		fflush(stdin);
		getchar();
	}
}

// J'ai crée cette fonction pour tester le cas ou les valeurs sont aleatoires(pas demandé)
void remplir(int **T, int n){
	*T = malloc(sizeof(int) * n);
	int i;
	for(i=0; i<n; i++){
		(*T)[i] = rand();
	}
}
void afficher(int *array, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("T[%d] = %d\n", i, array[i]);
	}
	
}
void permutter(int *val1, int *val2){
	int x;
	x = *val1;
	*val1 = *val2;
	*val2 = x;
}
int cle(int x, int i){
	return x % (int)pow(10, i+1) / pow(10, i);
}
void triAux(int *T, int n, int i){
	int j = 0;
	int l = 0;
	int t;
	int tab[10];
	for(j = 0; j<10; j++){
		tab[j] = 0;
	}

	int *tabaux = malloc(n*sizeof(int));

	for(j=0;j<n;j++){
		tab[cle(T[j], i)]++;
	}
	for(j=1; j<10;j++){
		tab[j] = tab[j] + tab[j-1];
	}
	for(j=n-1; j>=0; j--){
		t = cle(T[j], i);
		tabaux[tab[t] - 1] = T[j];
		tab[t] = tab[t] - 1;
	}

	for(j= 0; j<n; j++){
		T[j] = tabaux[j];
	}

	free(tabaux);
}
void triBase(int *T, int n, int k){
	// La question n'est pas claire sur le role du k, je vais donc supposer qu'il s'agit du nombre de chiffre de l'element le plus grand
	//voir fonction plus grand nombre chiffre
	int i = 0;
	for (i = 0; i<k; i++){
		triAux(T, n, i);
	}
}
int plusGrandNbChiffre(int *T, int n){
	int resultat = 0;
	int nbChiffre = 0;
	int i;
	int nb;
	for(i = 0; i<n; i++){
		nbChiffre = 0;
		nb = T[i];
		while(nb != 0){
			nb = nb/10;
			nbChiffre++;
		}
		if(nbChiffre > resultat){
			resultat = nbChiffre;
		}
	}
	return resultat;
}