#include "3-transformation.h"
#include <string.h>

transformation transform(char str[]) {
  transformation t;
  t.result = 0;
  t.error[0] = '\0';

  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= '0' && str[i] <= '9') {
      t.result = t.result * 10 + (str[i] - '0');
    } else {
      if (str[i] != '-' && str[i + 1] != '\0') {
        t.result *= -1;
        return t;
      } else if (str[i] == '+' && str[i + 1] == '\0') {
        return t;
      }
      t.result = 0;
      strcpy(t.error, "Invalid input string");
      return t;
    }
    i++;
  }
  return t;
}