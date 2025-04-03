#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

int pere;

static void *code_thread(void* arg) {
	pid_t tid;
	pthread_t pthr;
	tid = syscall(SYS_gettid);
	pthr = pthread_self();
	printf("Je suis le thread %u (ID Posix %u) créé par le processus %d \n", (unsigned int) tid, (unsigned int) pthr, pere);
	while (1) {}
}

int main() {
	int i;
	pthread_t p;
	pere = getpid();

	for (i=0; i<3; i++) {
		if (pthread_create(&p, NULL, &code_thread, NULL) != 0)
			printf("Je suis le processus %d, faute lancement thread\n", pere);
		else
			printf("Je suis le processus %d, j'ai lancé le thread Posix %u\n", pere, (unsigned int) p);
	}
	while(1) {}
}

