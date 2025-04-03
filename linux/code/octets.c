#include <stdio.h>
#include <stdlib.h>

void main () {
  int i;
  unsigned *ptn;
  ptn = (unsigned *) malloc (sizeof(unsigned));
  printf("taille unsigned = %d\n",sizeof(unsigned));
  *ptn = 0x12345678;
  void *ptn2 = ptn;
  printf("mot mémoire = %x\n",*ptn);
  for (i = 1; i <= 4; i++) {
    printf("octet %d = %x\n",i+1, *((char*)ptn2++));
  }
}
