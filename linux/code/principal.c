#include<stdio.h>
#include "interet.h"

int main() {
	float somme;
	float taux;
	int annees;
	printf("Somme:");
	scanf("%f", &somme);
	printf("Taux:");
	scanf("%f", &taux);
	printf("Années:");
	scanf("%d", &annees);
	calc(somme, taux, annees);
}