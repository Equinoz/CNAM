/*******************************************************************
Role de ce module
 Boucle d'attendre et de reception d'un message UDP
 -> En argument d'entree :
 - numero de Port d'écoute,
 -> Sur reception de message :
 - affichage du message et de l'émetteur,
 - sortie.
CE PROGRAMME NE SE REMET PAS EN ATTENTE DU MESSAGE SUIVANT
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#define MAXMESS 100

int main(int argc, char** argv) {
  int sock;
  char message[MAXMESS+1];
  struct sockaddr_in local, distant;
  unsigned short port;
  unsigned short distant_port;
  char distant_adresse[50];
  char* ptn_adresse = distant_adresse;
  int len, n;
  errno = 0;

  /* Contrôle des arguments */
  if (argc != 2) goto usage;
  port = (unsigned short) atol (argv[1]);

  /* Création socket */
  if ((sock = socket(AF_INET,SOCK_DGRAM, 0)) < 0) goto faute1;
  /* Bind */
  memset(&local, 0, sizeof(&local)); //precaution
  local.sin_family = AF_INET;
  local.sin_addr.s_addr = INADDR_ANY; // une des adresses IP locales
  local.sin_port = htons(port); // numéro de port
  if (bind(sock, (const struct sockaddr *)&local, sizeof(local)) < 0)
    goto faute2;

  /* Attente et Réception */
  printf("SERVEUR UDP A L'ECOUTE SUR PORT %d\n",port);
  n = recvfrom (sock, (char *)message, MAXMESS, 0, (struct sockaddr *)&distant, &len);
  message[n] = '\0';
  ptn_adresse = inet_ntoa(distant.sin_addr);
  distant_port = ntohs(distant.sin_port);
  printf("Reçu de %s/%d : %s\n", ptn_adresse,distant_port,message);

  /* Retour OK */
  close(sock);
  exit(0);

  /* USAGE */
  usage:
    printf ("Usage : serveur <Port>\n>");
    exit (-1);

  /* CAS DE FAUTES */
  faute1:
    perror("faute socket : ");
    exit(-2);

  faute2:
    perror("faute bind : ");
    exit(-3);
}