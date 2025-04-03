#include<stdio.h>

int calc(float somme, float taux, int annees) {
	float interet = 0;
	// Calcul des intérêts
	for (int i=1; i<=annees; i++) {
		interet += somme*taux;
		somme += interet;
		// Afficher le résultat
		printf ("%d : intérêt = %f\n",i,interet);
	}
}
