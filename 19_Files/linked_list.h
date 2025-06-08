#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef unsigned int uint;

#define MAX_NAME_LEN 128

typedef struct {
    char name[MAX_NAME_LEN];
    char author[MAX_NAME_LEN];
    char genre[MAX_NAME_LEN];
    int year_of_publication;
    char isbn[MAX_NAME_LEN];
} Book;

typedef Book ListType;

typedef struct Node {
    ListType value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    uint size;
} LinkedList;

LinkedList init();

void pushFront(LinkedList *list, ListType value);

void pushBack(LinkedList *list, ListType value);

void push(LinkedList *list, uint index, ListType value);

ListType popFront(LinkedList *list);

ListType popBack(LinkedList *list);

ListType pop(LinkedList *list, uint index);

ListType get(LinkedList *list, uint index);

void set(LinkedList *list, uint index, ListType value);

void release(LinkedList *list);

#endif /* LINKED_LIST_H */
