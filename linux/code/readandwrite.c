#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

char text[51];
int lock = 0;

static void *code_thread(void *arg) {
  pid_t tid = syscall(SYS_gettid);
  while(1) {
    if (lock) {
      printf("Le thread n°%u produit la valeur: %s\n", (unsigned int) tid, text);
      lock = 0;
    }
  }
}

int main() {
  int idParent = getpid();
  pthread_t p;

  if (pthread_create(&p, NULL,&code_thread, NULL) != 0)
    printf( "Processus %d en échec\n", idParent);
  else {
    while(1) {
      if (!lock) {
        printf("Mot à saisir: ");
        int result = scanf("%50s", text);
        lock = 1;
        printf("Le thread n°%d à récupéré la valeur: %s\n", idParent, text);
      }
    }
  }
}
