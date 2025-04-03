#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct dino {
  int id;
  char nom[50];
  int longueur;
  bool carnivore;
  int os;
  int decouverte;
} dino;

int main() {
  dino dino1;
  dino1.id = 44;
  strcpy(dino1.nom, "Stégosaure");
  dino1.longueur = 500;
  dino1.carnivore = 0;
  dino1.os = 340;
  dino1.decouverte = 1657;

  printf("%s\n\n\n", dino1.nom);

  char text[500];
  sprintf(text, "Exemplaire n° : %d\n", dino1.id);
  char name[50];
  sprintf(name, "Nom : %s\n", dino1.nom);
  char length[50];
  sprintf(length, "Longueur : %d mètres\n", dino1.longueur);
  char isCarnivore[50];
  strcpy(isCarnivore, (dino1.carnivore) ? "Carnivore : Oui\n" : "Carnivore : Non\n");
  char os[50];
  sprintf(os, "Os : %d\n", dino1.os);
  char discovered[50];
  sprintf(discovered, "Découvert en : %d\n", dino1.decouverte);
  strcat(text, name);
  strcat(text, length);
  strcat(text, isCarnivore);
  strcat(text, os);
  strcat(text, discovered);
  printf("%s", text);
}