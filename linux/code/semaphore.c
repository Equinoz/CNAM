#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_PROD 10 // Max produits à produire au total
#define MAX_BUF 3 // Taille max buffer tampon

typedef struct semaphore { // structure 2 sémaphores vide et plain
  sem_t sem_vide;
  sem_t sem_plein;
} sema;

static int buf[MAX_BUF]; // buffer produits

/* Thread Producteur */
void *producteur(void *arg) {
  int ip = 0; // index circulaire dans buffer
  int nbprod = 0; // nombre de produits produits
  int produit = 1001; // identifiant produit produit
  sema *args = (sema *) arg;

  while(nbprod < MAX_PROD) {
    sem_wait(&args->sem_vide); // Fonction "P" sémaphore vide
    buf[ip] = produit;
    sem_post(&args->sem_plein); // Fonction "V" sémaphore plein
    printf("produteur: buf[%d]=%d\n", ip, produit);
    produit++;
    nbprod++;
    ip = (ip + 1) % MAX_BUF; // maj index circulaire
  }
  return NULL;
}
/* Thread Consommateur */
void *consommateur(void *arg) {
  int ic = 0; // index circulaire dans buffer
  int nbcons = 0; // nombre de produits consommés
  int produit; // identifiant produit consommé
  sema *args = (sema *) arg;

  while(nbcons < MAX_PROD) {
    sleep(1);
    sem_wait(&args->sem_plein); // Fonction "P" sémaphore plein
    produit = buf[ic];
    sem_post(&args->sem_vide); // Fonction "V" sémaphore vide
    printf("consommateur: buf[%d]=%d\n", ic, produit);
    nbcons++;
    ic = (ic + 1) % MAX_BUF; // maj index circulaire
  }

  return NULL;
}

 /* Programme principal */
int main( ) {
  int p, i;
  pthread_t th1, th2;
  sema args;

  if (sem_init(&args.sem_vide, 0, MAX_BUF) == -1) perror ("1");
  if (sem_init(&args.sem_plein, 0, 0) == -1) perror("2");
  if (pthread_create(&th1,NULL,producteur,&args) != 0) perror("3");
  if (pthread_create(&th2,NULL,consommateur,&args) != 0) perror("4");

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);
}