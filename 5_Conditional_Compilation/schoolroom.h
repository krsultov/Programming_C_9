#ifndef SCHOOLROOM_H_
#define SCHOOLROOM_H_

#include "person.h"

typedef struct {
    int room_number;
    Person people[50];
} SchoolRoom;

#endif