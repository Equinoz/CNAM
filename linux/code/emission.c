/*******************************************************************
 Role de ce module
 Emettre un message UDP
 En entree :
 -> adresse IP destinataire,
 -> numero de Port destinataire,
 -> Texte du message
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
  char message[MAXMESS];
  struct sockaddr_in local, distant;
  unsigned int adresse;
  unsigned short port;
  int len, n;
  errno = 0;

  /* Contrôle des arguments */
  if (argc != 4) goto usage;
  if (inet_aton (argv[1],(struct in_addr *)&adresse) == 0) goto usage;
  port = (unsigned short) atol (argv[2]);
  strncpy (message, argv[3],MAXMESS+1);

  /* Création socket */
  if ((sock = socket(AF_INET,SOCK_DGRAM, 0)) < 0) goto faute1;

  /* Bind */
  memset(&local, 0, sizeof(&local)); //precaution
  local.sin_family = AF_INET;
  local.sin_addr.s_addr = INADDR_ANY; // une des adresses IP locales
  local.sin_port = 0; // numero de port affecté par le système
  if (bind(sock, (const struct sockaddr *)&local, sizeof(local)) < 0)
    goto faute2;

  /* Envoi message */
  memset(&distant, 0, sizeof(&distant)); //precaution
  distant.sin_family = AF_INET;
  distant.sin_addr.s_addr = adresse; // adresse IP serveur
  distant.sin_port = htons(port); // numéro de port serveur
  sendto(sock, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *) &distant, sizeof(distant));

  /* Retour OK */
  close(sock);
  exit(0);

  /* USAGE */
  usage:
    printf ("Usage : client <IP> <Port> <message>\n>");
    exit (-1);

  /* CAS DE FAUTES */
  faute1:
    perror("faute socket : ");
    exit(-2);

  faute2:
    perror("faute bind : ");
    exit(-3);
}