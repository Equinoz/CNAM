#include <stdio.h>
#include <string.h>

int main() {
  char h[] = "Hello";
  char w[] = "World";
  printf("1: %s\n", h);
  printf("2: %s\n", w);

  char hw[50];
  strcpy(hw, h);
  strcat(hw, " ");
  strcat(hw, w);
  printf("a) %s\n", hw);

  char *pstring = strstr(hw, w);
  *pstring = '\0';
  printf("b) %s\n", hw);

  char *pblank = strstr(hw, " ");
  *pblank = '\0';
  printf("c) %s\n", hw);

  int res = strcmp(hw, h);
  if (res == 0) {
    printf("d) Chaînes identiques\n");
  } else {
    printf("d) Chaînes différentes\n");
  }
}