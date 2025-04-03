#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main() {
	int pere;
	int fils;

	pere = getpid();
	printf("Processus : je suis le père, mon PID est %d\n", pere);

	fils = fork();

	if (fils != 0) {
		printf("Processus : je viens de créer le fils : %d\n", fils);
		while (1) {};
	} else {
		printf("Processus : je suis le fils : %d\n", getpid());
		execlp("./mini", NULL);
	}
}

