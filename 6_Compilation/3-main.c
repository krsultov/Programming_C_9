#include <stdio.h>
#include "3-transformation.h"

int main(void) {
  transformation t = transform("123");
  printf("Result: %ld\n", t.result);
  printf("Error: %s\n", t.error);

  return 0;
}