#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "../triABulles.h"

int main(){
	int *T;
	int n[13];
	int i;
	double delta;
	clock_t t1, t2;
	srand(time(0)); //random number generator seeding
	n[0] = 50000;
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

	for(i =0; i<13; i++){
		printf("----------------------------------------------------------------------\n");
		printf("pour N = %d\n", n[i]);
		printf("-----------------------------------------------------------------------\n");
		// Le meilleur des cas consiste en un tableau deja triéé
		printf("remplissage du tableau au meilleur des cas...\n");
		remplirTableauMeilleurDesCas(&T, n[i]);
		printf("tri a bulles en cours...\n");
		t1 = clock();
		triABulles(T, n[i]);
		t2 = clock();
		delta = (double)(t2-t1)/CLOCKS_PER_SEC;
		printf("le tableau, dans le meilleure des cas de la taille %d, a ete rempli en %f secondes :\n", n[i], delta);

		printf("******************************************\n");
		// Le pire des cas consiste en un tableau triée par ordre decroissant
		printf("remplissage du tableau au pire des cas... \n");
		remplirTableauPireDesCas(&T, n[i]);
		printf("tri a bulles en cours...\n");
		t1 = clock();
		triABulles(T, n[i]);
		t2 = clock();
		delta = (double)(t2-t1)/CLOCKS_PER_SEC;
		printf("le tableau, dans le pire des cas de la taille %d, a ete rempli en %f secondes :\n", n[i], delta);

		printf("appuyez sur entree pr continuer\n");
		fflush(stdin);
		getchar();
	}
}
void remplirTableauPireDesCas(int **T, int n){
	*T = malloc(sizeof(int) * n);
	int i;
	//* (*T)[0] = rand();
	for(i=0; i<n; i++){
		//*ci-contre, une facon de le remplir en utilisant rand, cette methode est extremement lente...
		// do{
		// 	(*T)[i] = rand();
		// }while((*T)[i] > (*T)[i-1] );
		(*T)[i] = n-i;
	}
}
void remplirTableauMeilleurDesCas(int **T, int n){
	*T = malloc(sizeof(int) * n);
	int i;
	//* (*T)[0] = rand();
	for(i=0; i<n; i++){
		//*ci-contre, une facon de le remplir en utilisant rand, cette methode est extremement lente...
		// do{
		// 	(*T)[i] = rand();
		// }while((*T)[i] < (*T)[i-1] );
		(*T)[i] = i;
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
void triABulles(int *array, int n){
	bool changement = true;
	int i;
	while(changement == true){
		changement = false;
		for(i = 0; i<n-1; i++){
			if(array[i] > array[i+1]){
				permutter(&array[i], &array[i+1]);
				changement = true;
			}
		}
	}
}