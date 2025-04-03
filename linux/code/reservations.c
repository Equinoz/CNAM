#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static pthread_mutex_t my_mutex;
static int compteur;

// Mutex
// Ressource a protéger
void *reservation (void * arg) {
  // Thread de réservation
  pthread_t pthr = pthread_self();

  while (1) {
    pthread_mutex_lock (&my_mutex); // Prise du mutex, si pris attente
    if (compteur > 0) {
      compteur--;
      // décrémenter compteur
      pthread_mutex_unlock (&my_mutex); // libération du mutex
      printf("Place réservée thread %u\n",(unsigned int)pthr);
    }
    else {
      pthread_mutex_unlock (&my_mutex); // libération du mutex
      printf("Plus de places thread %u\n",(unsigned int)pthr);
      break;
    }
  }
}

int main (int ac, char **av) {
  pthread_t th1, th2;
  void *ret;
  compteur = 10;

  // 10 places à réserver
  pthread_mutex_init (&my_mutex, NULL);
  /* Threads de réservation */
  if (pthread_create (&th1, NULL, reservation, NULL) < 0) {
    printf("Faute création thread 1\n");
    exit(-1);
  }

  if (pthread_create (&th2, NULL, reservation, NULL) < 0) {
    printf("Faute création thread 2\n");
    exit(-1);
  }

  /* Retour */
  (void)pthread_join (th1, &ret); //attente terminaison thread th1
  (void)pthread_join (th2, &ret); //attente terminaison thread th2
  exit (0);
}