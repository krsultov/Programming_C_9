#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"
#include "utils.h"

DynamicArray init(uint capacity) {
  if (capacity < 0) {
    printf("Invalid capacity \n");
    exit(1);
  }

  DynamicArray newDynamicArray = {
    .size = 0,
    .capacity = capacity,
    .buffer = NULL
  };

  if (newDynamicArray.capacity > 0) {
    newDynamicArray.buffer = calloc(newDynamicArray.capacity, sizeof(DynArrType));
    ASSERT_ALLOC(newDynamicArray.buffer);
  }

  return newDynamicArray;
}

static void resize(DynamicArray * dynArr, uint newSize) {
  if (newSize > dynArr->capacity) {
    if (dynArr->capacity == 0) {
      dynArr->capacity = 1;
    }

    while (dynArr->capacity <= newSize) {
      dynArr->capacity *= 2;
    }
  } else if (newSize <= dynArr->capacity / 2) {
    dynArr->capacity = newSize;
  }

  if (dynArr->capacity == 0) {
    free(dynArr->buffer);
  } else {
    DynArrType * temp = realloc(dynArr->buffer, dynArr->capacity * sizeof(DynArrType));
    ASSERT_ALLOC(temp);
    dynArr->buffer = temp;
  }

  dynArr->size = newSize;
}

void pushBack(DynamicArray * dynArr, DynArrType value) {
  uint newSize = dynArr->size + 1;
  resize(dynArr, newSize);
  dynArr->buffer[newSize - 1] = value;
}

void push(DynamicArray * dynArr, uint index, DynArrType value) {
  if (index > dynArr->size - 1) {
    printf("Index out of bounds");
    exit(1);
  }
  uint newSize = dynArr->size + 1;
  resize(dynArr, newSize);
  for (int i = newSize - 1; i > index; i--) {
    dynArr->buffer[i] = dynArr->buffer[i-1];
  }
  dynArr->buffer[index] = value;
}

void pushFront(DynamicArray * dynArr, DynArrType value) {
  push(dynArr, 0, value);
}

DynArrType popBack(DynamicArray * dynArr) {
  uint newSize = dynArr->size - 1;
  DynArrType result = dynArr->buffer[newSize];
  resize(dynArr, newSize);
  return result;
}

DynArrType popFront(DynamicArray * dynArr) {
  return 0;
}

DynArrType pop(DynamicArray * dynArr, uint index) {
  uint newSize = dynArr->size - 1;
  DynArrType result = dynArr->buffer[index];
  for (int i = index; i < newSize; i++) {
    dynArr->buffer[i] = dynArr->buffer[i+1];
  }
  resize(dynArr, newSize);
  return result;
}

DynArrType get(DynamicArray * dynArr, uint index) {
  return dynArr->buffer[index];
}

void set(DynamicArray * dynArr, uint index, DynArrType value) {
  dynArr->buffer[index] = value;
}

void release(DynamicArray * dynArr) {
  free(dynArr->buffer);
  dynArr->buffer = NULL;

  dynArr->capacity = 0;
  dynArr->size = 0;
}

DynArrType searchIndex(DynamicArray *dynArr, DynArrType value) {
    for (int i = 0; i < dynArr->size; i++) {
        if (dynArr->buffer[i] == value) {
            return i;
        }
    }

    return -1;
}