// #include <stdio.h>

// int main() {
//   float num;

//   FILE *file = fopen("./donnees", "a");

//   float buffer[1];

//   while (1) {
//     printf("Saisie: ");
//     scanf("%f", &num);
//     if (num < 0) {
//       break;
//     } else {
//       buffer[0] = num;
//       fwrite(buffer, sizeof num, sizeof num, file);
//     }
//   }
//   fclose(file);
// }

#include <stdio.h>
/* Programme principal */
void main() {
float data;
FILE *flot;
int taille;
int nbr;
/* Ouverture du fichier "donnees" */
flot = fopen ("donnees", "a"); // ouverture du fichier
if (flot == NULL) {
perror("Faute ouverture : \n");
return;
}
taille = sizeof (data);
/* Boucle de traitement */
while (1) {
/* Saisie de la donnée */
printf("Veuillez saisir votre donnee : ");
scanf ("%f",&data);
printf("donnee = %f\n",data);
if (data < 0) return;
// sortie du programme
/* Enregistrement de la donnee */
nbr = fwrite(&data, taille, 1, flot); // ecriture dans le fichier
if (nbr != 1) {
perror("Faute ecriture : \n");
return;
}
}
/* Fermeture du fichier */
fclose(flot);
}