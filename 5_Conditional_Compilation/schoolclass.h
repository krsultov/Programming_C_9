#ifndef SCHOOLCLASS_H_
#define SCHOOLCLASS_H_

#include "person.h"

typedef struct {
    Person students[26];
    char class_letter;
    int class_id;
    Person head_teacher;
} SchoolClass;

#endif