#include <stdio.h>
#include <unistd.h>

void main() {
  for(;;) {
    printf("Hello Everybody\n");
    sleep(60);
  }

  return;
}
