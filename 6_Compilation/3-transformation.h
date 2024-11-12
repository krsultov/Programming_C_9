#ifndef INC_3_TRANSFORMATION_H
#define INC_3_TRANSFORMATION_H

typedef struct transformation {
  long result;
  char error[100];
} transformation;

transformation transform(char str[]);

#endif
