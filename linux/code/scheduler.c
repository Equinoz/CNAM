#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main() {
	int i = 0;
	int fils = 0;
	int pere;
	int politique;
	struct sched_param param;

	pere = getpid();
	printf("Je suis le père mon numéro est : %d\n", pere);
	politique = sched_getscheduler(pere);
	if (politique == SCHED_FIFO)
		printf("Politique père FIFO\n");
	else if (politique == SCHED_RR)
		printf("Politique père Tourniquet\n");
	else if (politique == SCHED_OTHER)
		printf("Politique père Temps partagé\n");
	else
		printf("Politique père inconnue %d\n", politique);
	
	if ((fils = fork()) == 0) {
		fils = getpid();
		printf("Je suis le fils %d. Mon père est : %d\n", fils, pere);
		param.sched_priority = 10;

		if (sched_setscheduler(fils, SCHED_FIFO, &param) == -1)
			printf("Faute setscheduler\n");
		else {
			politique = sched_getscheduler(fils);
			if (politique == SCHED_FIFO)
				printf("Nouvelle politique fils FIFO\n");
			else if (politique == SCHED_RR)
				printf("Nouvelle politique fils Tourniquet\n");
			else if (politique == SCHED_OTHER)
				printf("Nouvelle politique fils Temps partagé\n");
		}
	}
}

