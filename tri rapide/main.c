#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "triRapide.h"

int main(){
	int *T;
	clock_t t1, t2;
	double delta;
	srand(time(0)); //random number generator seeding
	int n = 10;
	printf("----------------------------------------------------------------------\n");
	printf("pour N = %d\n", n);
	printf("-----------------------------------------------------------------------\n");
	// Le meilleur des cas consiste en un tableau deja triéé
	printf("remplissage du tableau..\n");
	remplir(&T, n);
	printf("tri rapide en cours... \n");
	t1 = clock();
	triRapide(T, 0, n-1);
	t2 = clock();
	delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("le tableau, dans  le cas de la taille %d, a ete trié en %f secondes :\n", n, delta);
	printf("appuyez sur entree pr continuer\n");
	fflush(stdin);
	getchar();


}
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
void triRapide(int *array, int p, int r){
	int q;
	if(p<r){
		q = partitionner(array, p, r);
		triRapide(array, p, q);
		triRapide(array, q+1, r);
	}
}
int partitionner(int *array, int d, int f){
	
	int pivot = array[d];
	int i = d-1, j = f+1;
	while(1){
		do{
			i++;
		}while(array[i] < pivot);
		do{
			j--;
		}while(array[j] > pivot);
		if(i>=j){
			return j;
		}
		permutter(&array[i], &array[j]);
	}
}