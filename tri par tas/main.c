#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "triParTas.h"

void remplirParZero(int *T, int n){
	int i;
	for(i = 0; i<n; i++){
		T[i] = 0;
	}
}
int main(){
	int liste[20];
	liste[0] = 16;
	liste[1] = 10;
	liste[2] = 8;
	liste[3] = 11;
	liste[4] = 5;
	liste[5] = 6;
	liste[6] = 9;
	liste[7] = 1;
	int tas[20];
	int tasFinale[20];
	remplirParZero(tasFinale, 20);
	printf("remplissage du tas a partir de la liste [16-10-8-11-5-6-9-1]\n");
	remplir(tas, liste);
	//affichage du tas initial
	afficher(tas, 9);
	printf("tri par tas en cours...\n");
	triParTas(tas, tasFinale, 9);
	printf("Affichage finale : \n");
	afficher(tasFinale, 9);
} 

void remplir(int *tas, int *liste){
	int i;
	int j = 1; tas[0] = 0;//pour eviter tout type de probleme, je commence a partir de 1
	int pere, k;
	for(i = 0; i<8; i++){
		tas[j] = liste[i];
		k = j;
		pere = j/2;
		while(pere > 0 && tas[pere] > tas[k]){
			permutter(&tas[pere], &tas[k]);
			k = pere;
			pere = k/2;
		}
		j++;
	}
	for(i = 9; i<20; i++){
		tas[i] = 0;		
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
void triParTas(int *tas, int *resultat, int n){
	int i = 1;
	int j;
	while(n > 0){
		resultat[i] = tas[1];
		supprimerMin(tas, n);
		tas[n-1] = 0;
		n--;
		// chaque iteration affiche une representation du tableau qui coincide avec
		// une des dernieres representations en arbre que la serie nous presente 
		printf("affichage apres suppression du min num %d\n", i);
		afficher(tas, n);
		i++;
	}
}
void supprimerMin(int *tas, int n){
	int i = 1;
	tas[i] = tas[n-1];
	int g = i*2, d = (i*2)+1;
	int suivant;
	while((tas[g] != 0 && tas[i] > tas[g]) || (tas[d] != 0 && tas[i] > tas[d])){
		int *min;
		if(tas[g] > tas[d]){
			 min = &tas[d];
			 suivant = d;
		}else{
			 min = &tas[g];
			 suivant = g;
		}
		printf("min = %d\n", *min);
		permutter(&tas[i], min);
		i = suivant;
		g = i*2; d = (i*2)+1;
	}
}