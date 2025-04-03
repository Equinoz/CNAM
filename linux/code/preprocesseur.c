#include <stdio.h>
#include <stdlib.h>

float lire_float(void);
// prototype lire_float()

/*
* Programme princial
*/
int main () {
  float poids,taille,masse;
  // Saisie des informations
  printf ("Saisissez votre poids en kilos\n");
  poids = lire_float();
  printf ("Saisissez votre taille en mètres\n");
  taille = lire_float();
  // Calcul de la masse ponderale
  masse=poids/(taille*taille);
  // Affichage du resultat
  if (masse < 18.4) printf ("Vous êtes trop maigre\n");
  else if (masse > 25) printf ("Vous êtes trop gros\n");
  else printf ("Vous êtes équilibré\n");
  // Retour
  return (0);
}
/*
* Lecture d'un nombre flottant
*/
#ifndef MEILLEURE_SAISIE
  float lire_float() {
    printf("pas meilleure saisie\n");
    float f;
    scanf("%f",&f);
    return(f);
  }
#endif

#ifdef MEILLEURE_SAISIE
  float lire_float() {
    printf("meilleure saisie\n");
    char texte[11];
    int c,i;
    int virgule = 0;
    float f;

    // Lecture caractère par caractère
    // limitée à 10 caractères
    for (i = 0; i < 10 ; i++) {
      // lecture d'un caractère
      c=getchar();
      if (c == '\n') break;
      // fin de saisie (fin de ligne)
      // cas particulier de la virgule
      if (c == ',') {
        c = '.';
        // la virgule est transformée en point
        if (virgule++ != 0) {
          // une seule virgule autorisée
          printf("Faute de saisie\n");
          exit (1);
          // on quitte le programme
        }
      }
      // controle de la valeur numérique
      else if ((c < '0')||(c > '9')) {
        printf("Faute de saisie\n");
        exit (1);
        // on quitte le programme
      }
      // Le caractère est accepté
      texte[i] = c;
    }
    texte[i] = 0;
    // on ferme la chaine de caractères
    // Conversion en flottant et retour
    sscanf(texte,"%f",&f);
    return(f);
  }
#endif