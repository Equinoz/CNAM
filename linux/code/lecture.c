#include <stdio.h>

int main() {
  float buffer[10];
  size_t ret = 1;

  FILE *file = fopen("./donnees", "r");
  
  while (ret == 1) {
    ret = fread(buffer, 34, 5, file);
    printf("Résultat: %f\n, %d", buffer[0], ret);
  }
}