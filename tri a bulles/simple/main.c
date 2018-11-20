#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "triABulles.h"

int main(){
	int T[20];
	int n = 10;
	int i;
	printf("les valeurs du tableau sont : \n");
	for(i=0; i<10; i++){
		T[i] = rand();
	}
	afficher(T, n);
	printf("tri a bulles en cours...\n");
	triABulles(T, n);

	printf("le tableau trié :\n");
	afficher(T, n);

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